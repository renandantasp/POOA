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
}


info = infoG1
class Scrapper:
    def getContent(info):
        if(info["has_parent"] == True):
            all_news = []
            container = soup.find_all(info["tag"])
            for news in container:
                parents = news.find_parents(info["parent_tag"], attrs={info["parent_identifyer_type"]:info["parent_identifyer"]})#aqui daria pra colocar mais identificadores
                for parent in parents:
                    all_news.append(parent.find(info["tag"]))
            all_news = list(dict.fromkeys(all_news))
        else:
            all_news = soup.find_all(info["tag"])
        return all_news
    
    def scrapeNews(all_news, info):
        noticias = []
        for news in all_news:
            if(info["has_identifyer"]):
                if info["identifyer_type"] in news.attrs:
                    if [i for i in info["identifyer"] if i in news.attrs[info["identifyer_type"]]]:
                        noticias.append(news.attrs["href"])
            else:
                noticias.append(news.attrs["href"])
        

