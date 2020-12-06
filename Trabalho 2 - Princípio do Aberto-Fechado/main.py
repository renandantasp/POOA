from crawler.utils.csv_utils import news_to_csv, csv_to_news
from crawler.sites import g1, globo, uol, estadao

# <site>.get_noticias() faz o crawling específico para o site em questão
# <site>_noticias recebe uma lista da seguinte forma: ["<nome do site>, noticias"]
# noticias é uma lista onde cada elemento é: [<titulo da noticia>, <link da noticia>]

g1_noticias = g1.get_noticias()
uol_noticias = uol.get_noticias()
globo_noticias = globo.get_noticias()
estadao_noticias = estadao.get_noticias()

# news_to_csv recebe como entrada <site>_noticias, escreve as
# informações num arquivo e retorna <site>_filename,
# que é nome desse arquivo

g1_filename      = news_to_csv(g1_noticias)
uol_filename     = news_to_csv(uol_noticias)
globo_filename   = news_to_csv(globo_noticias)
estadao_filename = news_to_csv(estadao_noticias)

# csv_to_news lê o csv que idealmente foi gerado por
# news_to_csv e o retorna no mesmo formato de <site>_noticias

g1_noticias = csv_to_news(g1_filename)
uol_noticias = csv_to_news(uol_filename)
globo_noticias = csv_to_news(globo_filename)
estadao_noticias = csv_to_news(estadao_filename)

# Respeitando essas normas de entrada e saída, é possível
# extender o pacote crawler com novas funcionalidades