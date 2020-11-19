#include "filmes.h"


Filmes::Filmes(){
    numFilmes = 0;
}

bool Filmes::adicionaFilme(std::string t, std::string d, std::string g, int a){
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

bool Filmes::removeFilme(Filme& f){
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

bool Filmes::trocaFilme(int pos1, int pos2){
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

bool Filmes::leFilme(Filme& f, int pos) const{
    if (pos > numFilmes)
        return false;
    f = filmes[pos];
    return true;
}

int Filmes::getNumFilmes() const{
    return numFilmes;
}

bool Filmes::imprimeFilme(int pos) const{
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

void Filmes::imprimeFilmes() const{
    for(int i = 0; i < numFilmes; i++){
        std::cout << "Filme " << i+1 << std::endl;
        std::cout << "Título: \"" << filmes[i].titulo << "\"" << std::endl;
        std::cout << "Diretor: " << filmes[i].diretor << std::endl;
        std::cout << "Gênero: " << filmes[i].genero << std::endl;
        std::cout << "Ano: " << filmes[i].ano << std::endl;
        std::cout << std::endl;
    }
}

