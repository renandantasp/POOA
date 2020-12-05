import requests
from bs4 import BeautifulSoup
import datetime


#função que acessa o site, e busca todas as tags "a" que possuem um link para uma noticia
def getSources(info):
    result = requests.get(info["site"])
    src = result.content
    soup = BeautifulSoup(src, 'lxml')

    if(info["has_parent"] == True):#verifica se precisa "subir" na arvore do html para filtrar as tags "a"
        all_news = []#lista com todas as tags uteis
        container = soup.find_all(info["tag"])
        for news in container:
            #verifica se os "pais" dessa tag atual possuem o atributo que identifica ela como util
            parents = news.find_parents(info["parent_tag"], attrs={info["parent_identifier_type"]:info["parent_identifier"]})
            for parent in parents:#com todos os "pais" uteis selecionados
                all_news.append(parent.find(info["tag"]))#procura dentro deles os tag "a" que vão ser usados
        all_news = list(dict.fromkeys(all_news))
    else:#caso não tenha que subir, retorna todas as tags "a" encontradas
        all_news = soup.find_all(info["tag"])
    
    return all_news#retorna a lista com todos os tags que vão ser usados

#função que resgata todos as noticias seguindo o formato do dict abaixo
# dict{tipo, titulo, link}
#  
def getNews(all_news, info):
    lista_news = []#lista onde os dicionarios vão ser armazenados
    for news in all_news:#para todas as tags "a" que forem passadas
        if(info["has_identifier"]):#caso na tag "a", ainda haja coisas para serem separadas
            if info["identifier_type"] in news.attrs:#encontra esses diferenciadores
                #é a função do Renan, mas removi as variaveis dela e coloquei no dict
                attrs = [info["identifier"][i] for i in info["identifier"] if i in news.attrs[info["identifier_type"]]]
                if attrs:
                    destaque = "Secundária"
                    if ("Principal" in attrs) and ("Not Principal" not in attrs):
                        destaque = "Principal"
                    noticia = {#cria o dict para armazenar as informações
                        "tipo": destaque,
                        "titulo": getTitle(news,info).rstrip().lstrip(),
                        "link": news.attrs["href"]
                    }
                    lista_news.append(noticia)#adiciona o dict a lista
        else:
            #Ainda pra fazer a seleção de destaque pra sites sem identificador
            destaque = "#####"

            noticia = {
                        "tipo": destaque,
                        "titulo": getTitle(news,info).rstrip().lstrip(),
                        "link": news.attrs["href"]
                    }
            lista_news.append(noticia)
    return lista_news

#função que só retorna o titulo da noticia em questão
def getTitle(news, info):
    if(info["is_title_separate"]):#caso a noticia não esteja na mesma tag do link
            
        if(info["title_identifier_type"] != "text"):#caso ela esteja escondida em outra tag
            for child in news.descendants:
                if(type(child) == type(news)):
                        
                    if info["title_identifier_type"] in child.attrs:
                        if info["title_identifier"] in child.attrs[info["title_identifier_type"]] :
                            return child.text
        else:#caso ela seja encontrada como texto apenas
            return news.text
    else:
        return news.attrs["title"]
        
def news_csv(info):
    all_news = getSources(info)
    noticias = getNews(all_news, info)

    date = datetime.datetime.now()
    now = str(date.day) + '-' + str(date.month) + '-'
    now += str(date.year) + '_' + str(date.hour) + '-' + str(date.minute)
    filename = info['nome'] + "_" + now + ".csv"
    
    f = open(filename, "w")
    f.write('tipo\ttitulo\tlink\n')
    
    for noticia in noticias:
        f.write(noticia['tipo'] + '\t' + noticia['titulo'] + '\t' + noticia['link'] + '\n')
    f.close()

def print_news(info):
    all_news = getSources(info)
    noticias = getNews(all_news, info)
    
    for noticia in noticias:
        print(noticia['tipo'], '\n', noticia['titulo'], '\n', noticia['link'],'\n\n')
