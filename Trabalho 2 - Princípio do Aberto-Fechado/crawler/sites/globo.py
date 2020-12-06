import requests
from bs4 import BeautifulSoup

def get_noticias():
    src = requests.get("https://www.globo.com/").content

    soup = BeautifulSoup(src, 'lxml')
    noticias = list()
    identifiers= ["hui-premium__title","hui-premium__related","hui-highlight-title"]

    links = soup.find_all(class_= identifiers)
    for link in links:
        parent = link.find_parents("a")
        if parent:
            titulo = link.text.strip()
            url = parent[0].get('href')
            noticias.append([titulo, url])
    return "Globo", noticias


