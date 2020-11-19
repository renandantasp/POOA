#include <string>
#include <vector>
#include <iostream>


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

class Series{
    private:
        std::vector<Serie> series;
        int numSeries;
    public:
        Series();
        bool adicionaSerie(std::string t, std::string d, std::string g, int n, int a);
        bool removeSerie(Serie& s);
        bool trocaSerie(int pos1, int pos2);
        bool leSerie(Serie& f, int pos) const;
        int getNumSeries() const;
        bool imprimeSerie(int pos = 0) const;
        void imprimeSeries() const;
};
