import requests
from bs4 import BeautifulSoup

def get_noticias():
    src = requests.get("https://www.globo.com/").content

    identifiers = ["hui-premium-foto__highlight-link", 
                   "hui_premium__link", 
                   "hui-premium__related-link", 
                   "hui-highlight__link"]

    soup = BeautifulSoup(src, 'lxml')
    noticias = list()

    links = soup.find_all("a")
    for link in links:
        if "class" in link.attrs:
            if [i for i in identifiers if i in link.attrs["class"]]:
                noticia = [link.text.strip(),link.attrs["href"]]
                noticias.append(noticia)
    return "Globo", noticias


