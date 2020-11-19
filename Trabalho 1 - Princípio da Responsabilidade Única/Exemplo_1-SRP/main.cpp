#include <stdlib.h>
#include "favoritos.cpp"
#include <iostream>

int main(){
    Favoritos lista;

    lista.adicionaFilme("Chunking Express", "Wong Kar-wai", "Drama", 1994);
    lista.adicionaFilme("Scott Pilgrim vs. The World", "Edgar Wright", "Comédia", 2010);
    lista.adicionaFilme("Taxi Driver", "Martin Scorcese", "Crime", 1976);

    lista.adicionaSerie("Twin Peaks", "David Lynch, Mark Frost", "Suspense", 3, 1990);
    lista.adicionaSerie("Game of Thrones", "David Benioff, D.B. Weiss", "Ação", 8, 2011);
    lista.adicionaSerie("Breaking Bad", "Vince Gilligan", "Drama", 5, 2008);

    std::vector<std::string> p;
    p.push_back("PS3");
    p.push_back("X360");
    p.push_back("PC");

    lista.adicionaJogo("Dark Souls", "From Software", "RPG", p, 2011);
    lista.adicionaJogo("The Elder Scrolls IV: Oblivion", "Bethesda Game Studios", "RPG", p, 2006);
    lista.adicionaJogo("Portal 2", "Valve", "Puzzle", p, 2011);
    
    lista.trocaFilme(0, 1);
    lista.trocaSerie(0, 1);
    lista.trocaJogo(1, 2);    
    
    lista.imprimeFilmes();
    lista.imprimeSeries();
    lista.imprimeJogos();


}