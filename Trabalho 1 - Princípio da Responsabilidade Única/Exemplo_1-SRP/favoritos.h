#include <string>
#include <vector>
#include <iostream>

typedef struct Filme{
        std::string titulo;
        std::string diretor;
        std::string genero;
        int ano;
} Filme;

bool operator==(const Filme& f1, const Filme& f2)
{
    return ( f1.titulo == f2.titulo && 
        f1.diretor == f2.diretor &&
        f1.genero == f2.genero &&
        f1.ano == f2.ano);
}

typedef struct Serie{
        std::string titulo;
        std::string diretor;
        std::string genero;
        int num_temporada;
        int ano;
} Serie;

bool operator==(const Serie& f1, const Serie& f2)
{
    return ( 
        f1.titulo == f2.titulo && 
        f1.diretor == f2.diretor &&
        f1.genero == f2.genero &&
        f1.num_temporada == f2.num_temporada &&
        f1.ano == f2.ano);
}

typedef struct Jogo{
        std::string titulo;
        std::string desenvolvedora;
        std::string genero;
        std::vector<std::string> plataformas;
        int ano;
} Jogo;

bool operator==(const Jogo& f1, const Jogo& f2)
{
    return ( 
        f1.titulo == f2.titulo && 
        f1.desenvolvedora == f2.desenvolvedora &&
        f1.genero == f2.genero &&
        f1.plataformas == f2.plataformas &&
        f1.ano == f2.ano);
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& j1)
{
    for(int i = 0; i < j1.size()-1; i++){
    os << j1[i] << ", ";
    }
    os << j1[j1.size()-1];
    return os;
}


class Favoritos{
    private:
        std::vector<Filme> filmes;
        std::vector<Serie> series;
        std::vector<Jogo> jogos;        
        int numFilmes;    
        int numSeries;
        int numJogos;
    public:
        Favoritos();
        bool adicionaFilme(std::string t, std::string d, std::string g, int a);
        bool removeFilme(Filme& f);
		bool trocaFilme(int pos1, int pos2);
        bool leFilme(Filme& f, int pos) const;
        int  getNumFilmes() const;
        bool imprimeFilme(int pos = 0) const;
        void imprimeFilmes() const;

        bool adicionaSerie(std::string t,std::string d,std::string g,int n,int a);
        bool removeSerie(Serie& s);
		bool trocaSerie(int pos1, int pos2);
        bool leSerie(Serie& s, int pos) const;
        int  getNumSeries() const;
        bool imprimeSerie(int pos = 0) const;
        void imprimeSeries() const;        

        bool adicionaJogo(std::string t, std::string d, std::string g,
									std::vector<std::string> n, int a);
        bool removeJogo(Jogo& j);
		bool trocaJogo(int pos1, int pos2);
        bool leJogo(Jogo& j, int pos) const;
        int  getNumJogos() const;
        bool imprimeJogo(int pos = 0) const;
        void imprimeJogos() const;
};
