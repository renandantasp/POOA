import requests
from bs4 import BeautifulSoup

def get_noticias():
    src = requests.get("https://g1.globo.com/").content
    identifiers = ["ui-color-primary", "bstn-hl-link", "feed-post-link"]
    
    soup = BeautifulSoup(src, 'lxml')
    noticias = list()
    
    links = soup.find_all("a")
    for link in links:
        if "class" in link.attrs:
            if [i for i in identifiers if i in link.attrs["class"]]:
                noticia = [link.text.strip(),link.attrs["href"]]
                noticias.append(noticia)
    
    return "G1", noticias


