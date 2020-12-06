from scrapper.csv_utils import news_to_csv
from scrapper.sites import g1, globo, uol#, estadao

uol_noticias = uol.get_noticias()
g1_noticias = g1.get_noticias()
globo_noticias = globo.get_noticias()
#estadao_noticias = estadao.get_noitcias()

news_to_csv(uol_noticias)
news_to_csv(g1_noticias)
news_to_csv(globo_noticias)
news_to_csv(estadao_noticias)

