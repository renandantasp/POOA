import datetime

def news_to_csv(noticias):
    site = noticias[0]
    noticias = noticias[1]
    date = datetime.datetime.now()
    now = str(date.day) + '-' + str(date.month) + '-'
    now += str(date.year) + '_' + str(date.hour) + '-' + str(date.minute)
    filename = site + "_" + now + ".csv"
    
    f = open(filename, "w")
    f.write('titulo\tlink\n')
    
    for noticia in noticias:
        f.write(noticia[0] + '\t' + noticia[1] + '\n')
    f.close()
