import requests
from bs4 import BeautifulSoup

infoEstadao = {
    "site":'https://www.estadao.com.br/',##link para o site
    "has_parent": True,#caso no o tag "a" não seja o suficiente para poder diferenciar os links uteis e inuteis, usar True, caso contrário False e manter proximos campos vazios
    "parent_tag": "div",#encontrar uma tag "pai" da tag "a" útil
    "parent_identifyer_type": "class",#encontrar um atributo que diferencie ela das outras tags
    "parent_identifyer": "intro",#qual o valor desse atributo
    "has_identifyer": False,#caso na tag "a" tenha as informaçoes necessárias para diferenciar os links uteis e inuteis, usar True, caso contrário false e manter proximos campos vazios
    "tag":"a",#tag onde se encontra os links, normalmente n vai mudar
    "identifyer_type": "",#qual campo identificaria a tag "a" certa
    "identifyer":[],#quais valores serviriam pra isso
    "is_title_separate":False,#caso o titulo da noticia não esteja no atributo "title" da tag "a", marcar como verdadeiro
    "title_identifyer": "title",#o valor do atributo que identifica a tag
    "title_identifyer_type": "class",#colocar o atributo da tag que possui o titulo
}

infoGlobo = {
    "site":'https://www.globo.com',
    "has_parent": False,
    "parent_tag": "",
    "parent_identifyer_type": "",
    "parent_identifyer": "",
    "has_identifyer": True,
    "tag":"a",
    "identifyer_type": "class",
    "identifyer":["hui_premium__link", "hui-premium__related-link", "hui-highlight__link", ],
    "is_title_separate":False,
    "title_identifyer": "",
    "title_identifyer_type": "",
 
}

infoUol = {
    "site":'https://www.uol.com.br/',
    "has_parent": False,
    "parent_tag": "",
    "parent_identifyer_type": "",
    "parent_identifyer": "",
    "has_identifyer": True,
    "tag":"a",
    "identifyer_type": "name",
    "identifyer":["manchete|3-colunas","chamada-destaque-submanchete|coluna-1","chamada-coluna-do-meio|coluna-3","chamada-destaque-submanchete|coluna-2" ],
    "is_title_separate":True,
    "title_identifyer": "titulo",
    "title_identifyer_type": "class",
    
}

infoG1 = {
    "site":'https://g1.globo.com/',
    "has_parent": False,
    "parent_tag": "",
    "parent_identifyer_type": "",
    "parent_identifyer": "",
    "has_identifyer": True,
    "tag":"a",
    "identifyer_type": "class",
    "identifyer":["gui-color-primary","bstn-hl-link","feed-post-link"],
    "is_title_separate":True,
    "title_identifyer": "",
    "title_identifyer_type": "text",
 
}


info = infoG1
class Scrapper:
    #função que acessa o site, e busca todas as tags "a" que possuem um link para uma noticia
    def getSources(info):
        result = requests.get(info["site"])
        src = result.content
        soup = BeautifulSoup(src, 'lxml')

        if(info["has_parent"] == True):#verifica se precisa "subir" na arvore do html para filtrar as tags "a"
            all_news = []#lista com todas as tags uteis
            container = soup.find_all(info["tag"])
            for news in container:
                parents = news.find_parents(info["parent_tag"], attrs={info["parent_identifyer_type"]:info["parent_identifyer"]})#verifica se nos "pais" dessa tag atual, possuem o atributo que identifica ela como util
                for parent in parents:#com todos os "pais" uteis selecionados
                    all_news.append(parent.find(info["tag"]))#procura dentro deles os tag "a" que vão ser usados
            all_news = list(dict.fromkeys(all_news))
        else:#caso não tenha que subir, retorna todas as tags "a" encontradas
            all_news = soup.find_all(info["tag"])
        
        return all_news#retorna a lista com todos os tags que vão ser usados

    #função que resgata todos as noticias seguindo o formato do dict abaixo
    # dict{
    #   titulo
    #    link
    # }
    #  
    def getNews(all_news, info):
        lista_news = []#lista onde os dicionarios vão ser armazenados
        for news in all_news:#para todas as tags "a" que forem passadas
            if(info["has_identifyer"]):#caso na tag "a", ainda haja coisas para serem separadas
                if info["identifyer_type"] in news.attrs:#encontra esses diferenciadores
                    if [i for i in info["identifyer"] if i in news.attrs[info["identifyer_type"]]]:#é a função do Renan, mas removi as variaveis dela e coloquei no dict
                        noticia_dict = {#cria o dict para armazenar as informações
                            "titulo": getTitle(news,info),
                            "link": news.attrs["href"]
                        }
                        lista_news.append(noticia_dict)#adiciona o dict a lista
            else:
                noticia_dict = {
                            "titulo": getTitle(news,info),
                            "link": news.attrs["href"]
                        }
                lista_news.append(noticia_dict)
        return lista_news

    #função que só retorna o titulo da noticia em questão
    def getTitle(news, info):
        if(info["is_title_separate"]):#caso a noticia não esteja na mesma tag do link
                
            if(info["title_identifyer_type"] != "text"):#caso ela esteja escondida em outra tag
                for child in news.descendants:
                    if(type(child) == type(news)):
                            
                        if info["title_identifyer_type"] in child.attrs:
                            if info["title_identifyer"] in child.attrs[info["title_identifyer_type"]] :
                                return child.text
            else:#caso ela seja encontrada como texto apenas
                return news.text
        else:
            return news.attrs["title"]
            

