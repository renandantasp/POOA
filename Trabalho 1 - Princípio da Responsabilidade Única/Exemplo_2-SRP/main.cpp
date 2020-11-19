#include <stdlib.h>
#include "filmes.cpp"
#include "series.cpp"
#include "jogos.cpp"
#include <iostream>

int main(){
    Filmes filmes;
    Series series;
    Jogos jogos;

    filmes.adicionaFilme("Scott Pilgrim vs. The World", "Edgar Wright", "Comédia", 2010);
    filmes.adicionaFilme("Chunking Express", "Wong Kar-wai", "Drama", 1994);
    filmes.adicionaFilme("Taxi Driver", "Martin Scorcese", "Crime", 1976);

    series.adicionaSerie("Game of Thrones", "David Benioff, D.B. Weiss", "Ação", 8, 2011);
    series.adicionaSerie("Twin Peaks", "David Lynch, Mark Frost", "Suspense", 3, 1990);
    series.adicionaSerie("Breaking Bad", "Vince Gilligan", "Drama", 5, 2008);

    std::vector<std::string> p;
    p.push_back("PS3");
    p.push_back("X360");
    p.push_back("PC");

    jogos.adicionaJogo("Dark Souls", "From Software", "RPG", p, 2011);
    jogos.adicionaJogo("The Elder Scrolls IV: Oblivion", "Bethesda Game Studios", "RPG", p, 2006);
    jogos.adicionaJogo("Portal 2", "Valve", "Puzzle", p, 2011);

    filmes.trocaFilme(0, 1);
    series.trocaSerie(0, 1);
    jogos.trocaJogo(1, 2);
    
    filmes.imprimeFilmes();
    series.imprimeSeries();
    jogos.imprimeJogos();

}