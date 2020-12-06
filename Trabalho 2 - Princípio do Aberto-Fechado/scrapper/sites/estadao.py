import requests
from bs4 import BeautifulSoup


def get_sources():
    result = requests.get('https://www.estadao.com.br/')
    src = result.content
    soup = BeautifulSoup(src, 'lxml')
    all_news = []
    container = soup.find_all("a")
    for news in container:
        parents = news.find_parents("div", attrs={"class":"intro"})
        for parent in parents:
            all_news.append(parent.find("a"))
    all_news = list(dict.fromkeys(all_news))
    
    
    return all_news


def get_noticias():
    sources = get_sources()
    all_news = list()
    for source in sources:
        titulo = source.attrs["title"]
        link = source.attrs["href"]
        noticia = [titulo,link]
        all_news.append(noticia)
    return "Estadao",all_news