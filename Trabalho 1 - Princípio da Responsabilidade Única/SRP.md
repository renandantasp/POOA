# SRP - Single-Responsibility Principle (Princípio da Responsabilidade Única)


O **Princípio da Responsabilidade Única** é um dos 5 princípios da orientação a objetos e design de código que foram definidos por **Robert C. Martin** e abordados no artigo *The Principles of OOD*. 

Esses 5 princípios foram chamados de **SOLID** por **Michael Feathers**, e nada mais é do que um acrônimo para a inicial de cada um desses princípios, eles servem pra ajudar desenvolvedores a escrever códigos mais limpos, bem estruturados e para manutenção simplificada.

 No meio de desenvolvimento *software* existe um grande debate sobre a "forma correta" de como desenvolver e de quais as melhores práticas a se seguir, o que é comum em áreas que envolvem habilidades técnicas, intelectuais e criativas. No entanto, as ideias apresentadas pelos princípios SOLID são muito presentes na comunidade de desenvolvimento de *software*, além de serem extremamente úteis para absorver boas práticas de desenvolvimento.

Nesse texto abordaremos o primeiro dos 5 princípios **SOLID**.

## O Princípio da Responsabilidade Única
Esse princípio afirma que toda classe ou módulo em um programa deve ter responsabilidade por apenas uma funcionalidade do programa. Além disso, os elementos envolvendo essa responsabilidade deveria ser encapsulado por uma classe responsável invés de estar espalhado em outras classes não relacionadas. O que pode ser simplificado em uma simples frase:

> "Uma classe deve ter uma, e apenas uma razão para ser modificada."
> -- *Robert Cecil Martin*

Na prática isso nos diz que elementos individuais de um programa devem ser distribuídos para as entidades que são capazes de lidar com esses elementos sem uma assistência externa.

O conceito de responsabilidade nesse contexto, segundo Martin, está atrelado à "atores". Se o *software* possui diferentes usuários, -- que pode ser interpretado como diferentes desenvolvedores e colaboradores, ou diferentes domínios de conhecimento -- então os interesses de cada um desses usuários definem as responsabilidades do *software*.


## A classe Deus ou *God class*

Quando não é seguido o conceito de uma classe ter apenas uma razão para ser modificada, o que encontramos é o caso de uma *God class*, que nada mais é do que uma classe responsável por diferentes recursos senão todos dentro de um projeto. O que a primeiro momento pode parecer eficiente, mas no exemplo abaixo será demonstrado o resultado real desse tipo de implementação.

## Sistema de listas de favoritos

### Exemplo 1

Iremos definir um sistema de criação de manutenção de listas de itens favoritos que consiste na adição, remoção, leitura e impressão de itens de três listas de obras favoritas referente a: filmes, series e jogos. Além disso, também é necessário editar a lista, como por exemplo, trocar a posição de um item de uma lista com outro da mesma lista. 

Uma possível solução para esse problema seria a criação de uma classe chamada `Favoritos` que contém as listas e dados referentes à elas como atributos e métodos implementando as funcionalidade previstas nos requisitos. Essa classe ficaria assim:

```cpp
class Favoritos{
	private:
		std::vector<Filme> filmes;
		int numFilmes;    

		std::vector<Serie> series;
		int numSeries;

		std::vector<Jogo> jogos;        
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
```

Nessa implementação (que pode ser visualizada com mais detalhes no arquivo `favoritos.h` e `favoritos.cpp` presente na pasta `Exemplo_1-SRP`) podemos identificar diversas responsabilidades dividindo a mesma classe, sendo elas:
- Tratamento da lista de filmes;
- Tratamento da lista de series;
- Tratamento da lista de jogos;
- Funcionalidades gerais para a lista;

Podemos notar que nossa classe é um exemplo claro de uma *God Class*, mesmo se assumirmos que somente um ator está envolvido com o código desse sistema, podemos notar a existência de diferentes responsabilidades para cada uma dessas áreas. 

Futuramente no projeto pode ser requisitado a criação do campo de "sinopse" para filmes, ou ser solicitado para a lista de séries o ano de cada temporada, ou então, o tempo médio para terminar um jogo. Poderia ser também requisitado um tratamento mais detalhado para o tratamento das listas, como subir um item um numero definido de posições, ou troca de posição de dois itens.

Esses e outros diversos novos requisitos poderiam ser definidos para o sistema, e independente do domínio do requisito, essa mudança seria feita na classe `Wishlists`, no entanto, o princípio da responsabilidade única preza que *uma classe deve ter um, e somente um, motivo para mudar*, o que não acontece nesse exemplo.

A violação do SRP pode gerar alguns problemas, como:
- Dificuldades de reaproveitamento e manutenção do código;
- Dificuldades na implementação de testes automatizados;
- **Falta de coesão** — uma classe não deve assumir responsabilidades que não são suas;
- **Alto acoplamento** — Mais responsabilidades geram um maior nível de dependências, deixando o sistema engessado e frágil para alterações;

Aplicando os conceitos de SRP na classe `Wishlists`, podemos refatorar o código da seguinte forma:

### Exemplo 2

```cpp
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
		int  getNumFilmes() const;
		bool imprimeFilme(int pos = 0) const;
		void imprimeFilmes() const;
};

class Series{
	private:
		std::vector<Serie> series;
		int numSeries;
	public:
	Series();
		bool adicionaSerie(std::string t,std::string d,std::string g,int n,int a);
		bool removeSerie(Serie& s);
		bool trocaSerie(int pos1, int pos2);
		bool leSerie(Serie& s, int pos) const;
		int  getNumSeries() const;
		bool imprimeSerie(int pos = 0) const;
		void imprimeSeries() const;        
};

class Jogos{
	private:
	    std::vector<Jogo> jogos;        
        int numJogos;
	public:
		bool adicionaJogo(std::string t, std::string d, std::string g,
					std::vector<std::string> n, int a);
		bool removeJogo(Jogo& j);
		bool trocaJogo(int pos1, int pos2);
		bool leJogo(Jogo& j, int pos) const;
		int  getNumJogos() const;
		bool imprimeJogo(int pos = 0) const;
		void imprimeJogos() const;
};
```
Essa implementação pode ser visualizada com mais detalhes nos arquivos `.h` e `.cpp` presentes na pasta `Exemplo_2-SRP`).

Agora temos cada classe cuidando de sua respectiva responsabilidade respeitando o Princípio da Responsabilidade Única, com isso temos agora uma boa quantidade de benefícios associados ao nosso sistema: 
- Facilidade de manutenção e evolução do código;
- Código limpo e de fácil entendimento;
- Facilidade para desenvolvimento de testes;
- Redução do acoplamento;
- Complexidade reduzida;
- Coesão das classes.

Analisando esta versão do código, é possível notar grandes diferenças com a primeira versão. Não apenas as funcionalidade são encapsuladas em suas próprias classes, mas são organizadas de uma maneira previsível e consistente. A ideia é agrupar essas funcionalidades semelhantes na tentativa de seguir o princípio de coesão e isolar os dados de forma que sejam acessíveis apenas aos atores relevantes.

No entanto, as responsabilidades que assumimos ser gerais da classe, como os métodos envolvendo edição das posições da lista ainda não está implementado numa classe única. Nesse ponto podemos abordar um outro aspecto da SRP, é importante ter uma noção do escopo do projeto, da complexidade atrelada às modificações pretendidas e os ganhos provenientes dela.

Nesse caso, a separação dessa classe poderia ser útil caso o projeto futuramente abrangesse um grande conjunto de modificações gerais dessas listas, mas caso ele não crie esses novos métodos, a separação dessa classe pode gerar um maior trabalho, podendo deixar o projeto desnecessariamente complexo e sem grandes retornos de qualidade. A complexidade também está ligada diretamente ao modo em que o *software* está desenvolvido, isto é, questões de linguagem, possíveis *frameworks* e bibliotecas utilizadas.

Por fim, foi possível analisar a utilidade e os diversos ganhos da aplicação dos conceitos expressos no *Princípio da Responsabilidade Única*, além de discutir possíveis casos onde a aplicação desse princípio sem um bom planejamento pode gerar resultados desnecessariamente complexos que não garantem os ganhos esperados.


## **Referências:**
- [**Writing Flexible Code with the Single Responsibility Principle**](https://medium.com/@severinperez/writing-flexible-code-with-the-single-responsibility-principle-b71c4f3f883f)

- [**Solid — S.R.P — Single Responsibility Principle**](https://medium.com/@tbaragao/solid-s-r-p-single-responsibility-principle-2760ff4a7edc)
- [**O que é SOLID: O guia completo para você entender os 5 princípios da POO**](https://medium.com/desenvolvendo-com-paixao/o-que-%C3%A9-solid-o-guia-completo-para-voc%C3%AA-entender-os-5-princ%C3%ADpios-da-poo-2b937b3fc530)
- [**Princípio da Responsabilidade Única**](https://medium.com/@angelomribeiro/princ%C3%ADpio-da-responsabilidade-%C3%BAnica-6d633087fa4e)
