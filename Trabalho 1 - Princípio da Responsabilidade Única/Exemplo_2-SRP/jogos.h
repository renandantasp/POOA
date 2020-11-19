#include <string>
#include <vector>
#include <iostream>


typedef struct Jogo{
        std::string titulo;
        std::string desenvolvedora;
        std::string genero;
        std::vector<std::string> plataformas;
        int ano;
} Jogo;

bool operator==(const Jogo& j1, const Jogo& j2)
{
    return ( 
        j1.titulo == j2.titulo && 
        j1.desenvolvedora == j2.desenvolvedora &&
        j1.genero == j2.genero &&
        j1.plataformas == j2.plataformas &&
        j1.ano == j2.ano);
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& j1)
{
    for(int i = 0; i < j1.size()-1; i++){
    os << j1[i] << ", ";
    }
    os << j1[j1.size()-1];
    return os;
}

class Jogos{
    private:
        std::vector<Jogo> jogos;
        int numJogos;
    public:
        Jogos();
        bool adicionaJogo(std::string t, std::string d, std::string g, std::vector<std::string> p, int a);
        bool removeJogo(Jogo& j);
        bool trocaJogo(int pos1, int pos2);
        bool leJogo(Jogo& f, int pos) const;
        int getNumJogos() const;
        bool imprimeJogo(int pos = 0) const;
        void imprimeJogos() const;
};
