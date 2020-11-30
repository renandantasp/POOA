import requests
from bs4 import BeautifulSoup

## GLOBO PARAMS
site    = "https://www.globo.com"
tag     = "a"
classes = ["hui_premium__link", "hui-premium__related-link", "hui-highlight__link", ]

result = requests.get(site)
src = result.content
soup = BeautifulSoup(src, 'lxml')


all_news = soup.find_all(tag)
for news in all_news:
    if 'class' in news.attrs:
        if [i for i in classes if i in news.attrs['class']]:
            print("## Notícia: " + news.attrs["title"]+ "\n##### Link: " + news.attrs['href'])
            print("--------------------------------------------")


