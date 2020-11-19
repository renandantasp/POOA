#include "series.h"


Series::Series(){
    numSeries = 0;
}

bool Series::adicionaSerie(std::string t, std::string d, std::string g, int n, int a){
    Serie f;
    f.titulo = t;
    f.diretor = d;
    f.genero = g;
    f.num_temporada = n;
    f.ano = a;

    for(int i = 0; i < series.size(); i++){
        if (f == series[i]){
            std::cout << "Serie já incluida na lista";
            return false;
        }
    }
    series.push_back(f);
    numSeries++;
    return true;
}

bool Series::removeSerie(Serie& f){
    for(int i = 0; i < series.size(); i++){
        if (f == series[i]){
            series.erase(series.begin()+i);
            return true;
        }
    }
    std::cout << "Serie não encontrada";
    numSeries--;
    return false;
}

bool Series::trocaSerie(int pos1, int pos2){
    if(pos1 < numSeries && pos2 < numSeries && pos1 != pos2){
        Serie s = series[pos1];
        series[pos1] = series[pos2];
        series[pos2] = s;
        std::cout << "\"" << series[pos1].titulo << "\" trocou de posição com \"" 
        << series[pos2].titulo << "\" \n";
        return true;
    }
    return false;
}

bool Series::leSerie(Serie& f, int pos) const{
    if (pos > numSeries)
        return false;
    f = series[pos];
    return true;
}

int Series::getNumSeries() const{
    return numSeries;
}

bool Series::imprimeSerie(int pos) const{
    if (pos <= numSeries){
        std::cout << "Título: \"" << series[pos].titulo << "\"" << std::endl;
        std::cout << "Diretor: " << series[pos].diretor << std::endl;
        std::cout << "Gênero: " << series[pos].genero << std::endl;
        std::cout << "N° de temporadas: " << series[pos].num_temporada << std::endl;
        std::cout << "Estréia: " << series[pos].ano << std::endl;
        std::cout << std::endl;
        return true;
    }
    std::cout << "Série não encontrada." << std::endl;
    return false;
}

void Series::imprimeSeries() const{
    for(int i = 0; i < numSeries; i++){
        std::cout << "Série " << i+1 << std::endl;
        std::cout << "Título: \"" << series[i].titulo << "\"" << std::endl;
        std::cout << "Diretor: " << series[i].diretor << std::endl;
        std::cout << "Gênero: " << series[i].genero << std::endl;
        std::cout << "N° de temporadas: " << series[i].num_temporada << std::endl;
        std::cout << "Estréia: " << series[i].ano << std::endl;
        std::cout << std::endl;
    }
}

