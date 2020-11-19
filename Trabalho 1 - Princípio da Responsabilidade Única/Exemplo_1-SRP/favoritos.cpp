#include "favoritos.h"
#include <iostream>

Favoritos::Favoritos(){
    numFilmes = 0;
    numSeries = 0;
    numJogos = 0;
}
//Métodos dos Filmes
bool Favoritos::adicionaFilme(std::string t, std::string d, std::string g, int a){
    Filme f;
    f.titulo = t;
    f.diretor = d;
    f.genero = g;
    f.ano = a;

    for(int i = 0; i < filmes.size(); i++){
        if (f == filmes[i]){
            std::cout << "Filme já incluido na lista";
            return false;
        }
    }
    filmes.push_back(f);
    numFilmes++;
    return true;
}

bool Favoritos::removeFilme(Filme& f){
    for(int i = 0; i < filmes.size(); i++){
        if (f == filmes[i]){
            filmes.erase(filmes.begin()+i);
            numFilmes--;
            return true;
        }
    }
    std::cout << "Filme não encontrado";
    return false;
}

bool Favoritos::trocaFilme(int pos1, int pos2){
    if(pos1 < numFilmes && pos2 < numFilmes && pos1 != pos2){
        Filme f = filmes[pos1];
        filmes[pos1] = filmes[pos2];
        filmes[pos2] = f;
        std::cout << "\"" << filmes[pos1].titulo << "\" trocou de posição com \"" 
        << filmes[pos2].titulo << "\" \n";
        return true;
    }
    return false;
}

bool Favoritos::leFilme(Filme& f, int pos) const{
    if (pos > numFilmes)
        return false;
    f = filmes[pos];
    return true;
}

int Favoritos::getNumFilmes() const{
    return numFilmes;
}

bool Favoritos::imprimeFilme(int pos) const{
    if (pos <= numFilmes){
        std::cout << "Título: \"" << filmes[pos].titulo << "\"" << std::endl;
        std::cout << "Diretor: " << filmes[pos].diretor << std::endl;
        std::cout << "Gênero: " << filmes[pos].genero << std::endl;
        std::cout << "Ano: " << filmes[pos].ano << std::endl;
        std::cout << std::endl;
        return true;
    }
    std::cout << "Série não encontrada." << std::endl;
    return false;
}

void Favoritos::imprimeFilmes() const{
    for(int i = 0; i < numFilmes; i++){
        std::cout << "Filme " << i+1 << std::endl;
        std::cout << "Título: \"" << filmes[i].titulo << "\"" << std::endl;
        std::cout << "Diretor: " << filmes[i].diretor << std::endl;
        std::cout << "Gênero: " << filmes[i].genero << std::endl;
        std::cout << "Ano: " << filmes[i].ano << std::endl;
        std::cout << std::endl;
    }
}

//Métodos das séries
bool Favoritos::adicionaSerie(std::string t, std::string d, std::string g, int n, int a){
    Serie f;
    f.titulo = t;
    f.diretor = d;
    f.genero = g;
    f.num_temporada = n;
    f.ano = a;

    for(int i = 0; i < series.size(); i++){
        if (f == series[i]){
            std::cout << "Serie já incluido na lista";
            return false;
        }
    }
    series.push_back(f);
    numSeries++;
    return true;
}

bool Favoritos::removeSerie(Serie& f){
    for(int i = 0; i < series.size(); i++){
        if (f == series[i]){
            series.erase(series.begin()+i);
            return true;
        }
    }
    std::cout << "Serie não encontrado";
    numSeries--;
    return false;
}

bool Favoritos::trocaSerie(int pos1, int pos2){
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

bool Favoritos::leSerie(Serie& f, int pos) const{
    if (pos > numSeries)
        return false;
    f = series[pos];
    return true;
}

int Favoritos::getNumSeries() const{
    return numSeries;
}

bool Favoritos::imprimeSerie(int pos) const{
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

void Favoritos::imprimeSeries() const{
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

//Métodos dos jogos
bool Favoritos::adicionaJogo(std::string t, std::string d, std::string g, std::vector<std::string> p, int a){
    Jogo f;
    f.titulo = t;
    f.desenvolvedora = d;
    f.genero = g;
    f.plataformas = p;
    f.ano = a;

    for(int i = 0; i < jogos.size(); i++){
        if (f == jogos[i]){
            std::cout << "Jogo já incluido na lista";
            return false;
        }
    }
    jogos.push_back(f);
    numJogos++;
    return true;
}

bool Favoritos::removeJogo(Jogo& f){
    for(int i = 0; i < jogos.size(); i++){
        if (f == jogos[i]){
            jogos.erase(jogos.begin()+i);
            return true;
        }
    }
    std::cout << "Jogo não encontrado";
    numJogos--;
    return false;
}

bool Favoritos::trocaJogo(int pos1, int pos2){
    if(pos1 < numJogos && pos2 < numJogos && pos1 != pos2){
        Jogo j = jogos[pos1];
        jogos[pos1] = jogos[pos2];
        jogos[pos2] = j;
                std::cout << "\"" << jogos[pos1].titulo << "\" trocou de posição com \"" 
                << jogos[pos2].titulo << "\" \n";
        return true;
    }
    return false;    
}

bool Favoritos::leJogo(Jogo& f, int pos) const{
    if (pos > numJogos)
        return false;
    f = jogos[pos];
    return true;
}

int Favoritos::getNumJogos() const{
    return numJogos;
}

bool Favoritos::imprimeJogo(int pos) const{
    if (pos <= numJogos){
        std::cout << "Título: \"" << jogos[pos].titulo << "\"" << std::endl;
        std::cout << "Diretor: " << jogos[pos].desenvolvedora << std::endl;
        std::cout << "Gênero: " << jogos[pos].genero << std::endl;
        std::cout << "N° de temporadas: " << jogos[pos].plataformas << std::endl;
        std::cout << "Lançamento: " << jogos[pos].ano << std::endl;
        std::cout << std::endl;
        return true;
    }
    std::cout << "Série não encontrada." << std::endl;
    return false;
}

void Favoritos::imprimeJogos() const{
    for(int i = 0; i < numJogos; i++){
        std::cout << "Jogo " << i+1 << std::endl;
        std::cout << "Título: \"" << jogos[i].titulo << "\"" << std::endl;
        std::cout << "Desenvolvedora: " << jogos[i].desenvolvedora << std::endl;
        std::cout << "Gênero: " << jogos[i].genero << std::endl;
        std::cout << "Plataformas: " << jogos[i].plataformas << std::endl;
        std::cout << "Lançamento: " << jogos[i].ano << std::endl;
        std::cout << std::endl;
    }
}

