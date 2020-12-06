from crawler.utils.csv_utils import news_to_csv
from crawler.sites import g1, globo, uol, estadao

g1_noticias = g1.get_noticias()
uol_noticias = uol.get_noticias()
globo_noticias = globo.get_noticias()
estadao_noticias = estadao.get_noticias()

news_to_csv(g1_noticias)
news_to_csv(uol_noticias)
news_to_csv(globo_noticias)
news_to_csv(estadao_noticias)

