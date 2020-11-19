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

class Filmes{
    private:
        std::vector<Filme> filmes;
        int numFilmes;
    public:
        Filmes();
        bool adicionaFilme(std::string t, std::string d, std::string g, int a);
        bool removeFilme(Filme& f);
        bool trocaFilme(int pos1, int pos2);
        bool leFilme(Filme& f, int pos) const;
        int getNumFilmes() const;
        bool imprimeFilme(int pos = 0) const;
        void imprimeFilmes() const;
};
