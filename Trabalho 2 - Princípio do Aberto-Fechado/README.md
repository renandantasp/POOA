Nomes: Guilherme Locca Salomão, Nathaelly Boni, Renan Dantas Pasquantonio

# 1 - Trabalho 2 - Princípio do Aberto-Fechado
O segundo trabalho da disciplina de Programação Orientada a Objetos teve como seu objetivo construir uma ferramenta que encontre e baixe os títulos das notícias diárias nos principais sites de notícia (G1, Estadão, UOL, etc), além de respeitar os seguintes príncipios SOLID:

- Princípio aberto-fechado 
- Princípio da responsabilidade única

Isto é, essa ferramenta deve ser aberta para extensão e fechada para modificação. Para evitar possíveis dificuldades, ela também deve permitir a inclusão de novos sites de notícias e novos algoritmos.

# 2 - O que foi feito
Para a construção desse projeto, utilizamos a linguagem [Python](https://www.python.org/) e a biblioteca [Beautiful Soup 4](https://pypi.org/project/beautifulsoup4/).
Criamos o pacote `Crawler` que contém os diretórios: 

- `sites`: contém os scripts de *crawling* para cada website; 
- `utils`: contém as funcionalidades referentes aos arquivos da extensão csv, mas também pode armazenar qualquer tipo de novas funcionalidades (mais detalhes na seção 4).

O pacote está disposto da seguinte forma:
```
crawler:
    + __init__.py
    + sites:
        + __init__.py
        + g1.py
        + estadao.py
        + uol.py

    + utils:
        + __init__.py
        + csv_utils.py
```
Todos os scripts de *crawling* seguem o mesmo padrão de *output*, que é uma lista com dois elementos, uma `string` contendo o nome do site, e a lista das notícias e seus respectivos links (ex: `["G1", noticias]`).

Isso é feito para que haja uma padronização de entrada e saída entre todos os scripts, consequentemente facilitando a extensão do pacote.

# 3 - Configuração e utilização

## 3.1 Configuração
Para a utilização do pacote são necessários a instalação da linguagem [Python](https://www.python.org/) e do gerenciador de pacotes [pip](https://pypi.org/project/pip/):

- [Como instalar o Python](https://www.python.org/downloads/)
- [Como instalar o pip](https://pip.pypa.io/en/stable/installing/)

Por fim, é necessário o download da biblioteca [Beautiful Soup 4](https://pypi.org/project/beautifulsoup4/):

```
$ pip install bs4
```

## 3.2 Utilização
Após o download, é possível ver no arquivo `main.py` como é feita a utilização das funcionalidades do pacote.

# 4 - Como ampliar
Por fim, listamos aqui três exemplos de como aplicar novas funcionalidades. Além dos passos citados, deve-se manter a estrutura do código e também respeitar as normas de entrada e saída:

## 4.1 Novo site
Para a inclusão de um novo site de notícias, um arquivo deve ser criado na pasta `sites` com o nome do site desejado. Tomamos aqui, como exemplo, o site de notícias "xyz". Depois da criação do arquivo `xyz.py`, precisamos importá-lo para o código principal. Assim, em `main.py` a chamada deve ser feita da seguinte forma:
```
from crawler.sites import xyz
```
E depois, para chamar a função que busca os títulos das matérias:
```
xyz.get_noticias()
```
## 4.2 Novo algoritmo
Para um novo algoritmo, tomamos como exemplo a funcionalidade de ordenar as notícias por ordem alfabética. Assim, dentro da pasta `utils`, criamos um arquivo `sort.py` contendo a função *sort_news* que faz a ordenação, e, na função main, fazemos a chamada:
```
from crawler.utils.sort import sort_news
```
E para implementar  depois:
```
noticias = xyz.get_noticias()
noticias_ordenadas = sort_news(noticias)
filename = news_to_csv(noticias_ordenadas)
```
## 4.3 Novo pacote
Para a implementação de um novo pacote, o processo é bem semelhante com o anterior, apenas com algumas alterações. Tomamos como exemplo o pacote *machine learning*. Dentro da pasta `crawler`, criamos uma nova pasta chamada `machine_learning`, e ela ficaria assim:
```
crawler:
    + __init__.py
    + sites:
	    + __init__.py
	    + g1.py
	    + estadao.py
	    + uol.py
    + utils:
	    + __init__.py
	    + csv_utils.py
    + machine_learning:
	    + __init__.py
	    + bag_of_words.py
	    + sentiment_analysis.py
	    + topic_classification.py
```
É possível importar os pacotes da seguinte forma:
```
from crawler.machine_learning import bag_of_words, sentiment_analysis, topic_classification
```
