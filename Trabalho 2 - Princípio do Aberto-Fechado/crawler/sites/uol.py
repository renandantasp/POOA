import requests
from bs4 import BeautifulSoup

def get_noticias():
    src = requests.get("https://www.uol.com.br/").content

    identifiers = ["manchete|3-colunas", 
                   "chamada-destaque-submanchete|coluna-1", 
                   "chamada-coluna-do-meio|coluna-3", 
                   "chamada-destaque-submanchete|coluna-2"]

    soup = BeautifulSoup(src, 'lxml')
    noticias = list()

    links = soup.find_all("a")
    for link in links:
        if "name" in link.attrs:
            if [i for i in identifiers if i in link.attrs["name"]]:
                noticia = [get_title(link), link.attrs["href"]]
                noticias.append(noticia)
    return "UOL", noticias


#função que só retorna o titulo da noticia em questão
def get_title(link):
    for child in link.descendants:
        if type(child) == type(link) and "class" in child.attrs:
            if "titulo" in child.attrs["class"]:
                return child.text.strip()