#include "jogos.h"

Jogos::Jogos(){
    numJogos = 0;
}

bool Jogos::adicionaJogo(std::string t, std::string d, std::string g, std::vector<std::string> p, int a){
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

bool Jogos::removeJogo(Jogo& f){
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

bool Jogos::trocaJogo(int pos1, int pos2){
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

bool Jogos::leJogo(Jogo& f, int pos) const{
    if (pos > numJogos)
        return false;
    f = jogos[pos];
    return true;
}

int Jogos::getNumJogos() const{
    return numJogos;
}

bool Jogos::imprimeJogo(int pos) const{
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

void Jogos::imprimeJogos() const{
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