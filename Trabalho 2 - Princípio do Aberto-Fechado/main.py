from scrapper.news_to_csv import news_to_csv
from scrapper import g1, globo, uol

uol_noticias = uol.get_noticias()
g1_noticias = g1.get_noticias()
globo_noticias = globo.get_noticias()

news_to_csv(uol_noticias)
news_to_csv(g1_noticias)
news_to_csv(globo_noticias)

