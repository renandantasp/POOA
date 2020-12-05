estadao = {
    "nome": "Estadão",
    "site":"https://www.estadao.com.br/",##link para o site
    "has_parent": True,#caso no o tag "a" não seja o suficiente para poder diferenciar os links uteis e inuteis, usar True, caso contrário False e manter proximos campos vazios
    "parent_tag": "div",#encontrar uma tag "pai" da tag "a" útil
    "parent_identifier_type": "class",#encontrar um atributo que diferencie ela das outras tags
    "parent_identifier": "intro",#qual o valor desse atributo
    "has_identifier": False,#caso na tag "a" tenha as informaçoes necessárias para diferenciar os links uteis e inuteis, usar True, caso contrário false e manter proximos campos vazios
    "tag":"a",#tag onde se encontra os links, normalmente n vai mudar
    "identifier_type": "",#qual campo identificaria a tag "a" certa
    "identifier":[],#quais valores serviriam pra isso
    "highlight_type": "class",
    "highlight": ["title"],
    "is_title_separate":False,#caso o titulo da noticia não esteja no atributo "title" da tag "a", marcar como verdadeiro
    "title_identifier": "title",#o valor do atributo que identifica a tag
    "title_identifier_type": "class"#colocar o atributo da tag que possui o titulo
}

globo = {
    "nome": "Globo",
    "site":"https://www.globo.com",
    "has_parent": False,
    "parent_tag": "",
    "parent_identifier_type": "",
    "parent_identifier": "",
    "has_identifier": True,
    "tag":"a",
    "identifier_type": "class",
    "identifier":{"hui-premium-foto__highlight-link":"Principal", 
                  "hui_premium__link":               "Secundária", 
                  "hui-premium__related-link":       "Secundária", 
                  "hui-highlight__link":             "Secundária"},
    "highlight_type": "class",
    "is_title_separate":False,
    "title_identifier": "",
    "title_identifier_type": ""
}

uol = {
    "nome": "UOL",
    "site":"https://www.uol.com.br/",
    "has_parent": False,
    "parent_tag": "",
    "parent_identifier_type": "",
    "parent_identifier": "",
    "has_identifier": True,
    "tag":"a",
    "identifier_type": "name",
    "identifier":{"manchete|3-colunas":                   "Principal",
                  "chamada-destaque-submanchete|coluna-1":"Secundária",
                  "chamada-coluna-do-meio|coluna-3":      "Secundária",
                  "chamada-destaque-submanchete|coluna-2":"Secundária" },
    "highlight_type": "class",
    "is_title_separate":True,
    "title_identifier": "titulo",
    "title_identifier_type": "class" 
}

G1 = {
    "nome": "G1",
    "site":"https://g1.globo.com/",
    "has_parent": False,
    "parent_tag": "",
    "parent_identifier_type": "",
    "parent_identifier": "",
    "has_identifier": True,
    "tag":"a",
    "identifier_type": "class",
    "identifier":{"gui-color-primary":"Principal",
                  "bstn-hl-link":     "Secundária",
                  "feed-post-link":   "Secundária"},
    "highlight_type": "class",
    "is_title_separate":True,
    "title_identifier": "",
    "title_identifier_type": "text"
}
