# Trabalho Programação Orientada a Objetos
 * 2017089014 - Alex Souza
 * 2017001320 - Rafael Ribeiro


## Sumário

- [Introdução](#Introducao)
- [Documentação](#Documentação)
    - [Visão Geral](#VisaoGeral)
    - [Requisitos](#Requisitos)
- [Código Fonte](#CodigoFonte)
    - [main.cpp](#maincpp)
    - [Edge.h](#Edge.h)
    - [Edge.cpp](#Edge.cpp)
    - [Graph.h](#Graph.h)
    - [Graph.cpp](#Graph.cpp)

- [I/O](#i/o)
    - [vertex.txt](#vertex.txt)
    - [Saĩda do Console](#SaidaDoConsole)
- [Referências](#Referências)


<a name="Introducao"></a>
## Introdução

<a name="VisaoGeral"></a>
### Visão Geral
 
Trabalho final da disciplina Programação Orientada a Objetos ministrado pela professora Raquel Mini no primeiro semestre de 2019. O software desenvolvido tem como objetivo, implementar técnicas comuns de manipulação e busca em grafos. Criado com base na pesquisa feita pelos alunos envolvidos, o software possui um script principal que efetua a demonstração das diversas funcionalidades solicitadas pelo enunciado, conforme descrito em cada ponto onde os requisitos foram atendidos. Cada um dos requisitos é listado a segir, no tópico [Requistos](#Requisitos):

<a name="Requisitos"></a>
## Requisitos

> a) Um construtor, que receberá como parâmetro um inteiro indicando o número de
> vértices do grafo;

- [Resolução (a)](#ResolucaoA)

> b) Um destrutor, que se incumbirá de fazer a desalocação de memória eventualmente
> utilizada na representação do grafo;

- [Resolução (b)](#ResolucaoB)


> c) Função para inserir uma aresta no grafo: bool Graph::insert(const Edge&). A função
> retornará true se a inserção ocorrer com sucesso e false caso a aresta que se está
> tentando inserir já exista no grafo.

- [Resolução (c)](#ResolucaoC)

> d) Função para retirar uma aresta do grafo: bool Graph::remove(const Edge&). A função
> retornará true se a remoção ocorrer com sucesso e false caso a aresta que se está
> tentando remover não exista no grafo.

- [Resolução (d)](#ResolucaoD)

> e) Funções para buscar o número de vértices e o número de arestas do grafo. Para que a
> função que retorna o número de arestas seja eficiente, é interessante que a classe
> mantenha um atributo interno que faça esta contagem. O atributo deve ser atualizado
> em todas as inserções e remoções de aresta que ocorrerem com sucesso;



> f) Função para verificar a existência de uma aresta do grafo: bool Graph::edge(const
> Edge&) const . A função retornará true se a aresta estiver presente no grafo e false em
> caso contrário.

> g) Função booleana para verificar se o grafo desenhado é completo.

> h) Função para completar o grafo desenhado.

> i) Função para realizar a busca em largura (Breadth First Search - BFS). Essa função deve
> receber o índice de um vértice e apresentar os índices dos vértices na ordem do
> caminhamento em largura a partir do vértice recebido como parâmetro. Este
> caminhamento deve ser feito apenas no componente do vértice inicial.

> j) Função para realizar a busca em profundidade (Depth First Search – DFS). Essa função
> deve receber o índice de um vértice e apresentar os índices dos vértices na ordem do
> caminhamento em profundidade a partir do vértice recebido como parâmetro. Este
> caminhamento deve ser feito em todos os componentes do grafo.

> k) Função para retornar o número de componentes conectados do grafo. A
> determinação do número de componentes conectados pode ser feita usando busca
> em profundidade no grafo.

> l) Função para encontrar o menor caminho através do Algoritmo de Dijkstra. Essa função
> deverá receber o índice do vértice inicial e final e retornar os vértices contidos no
> menor caminho bem como o comprimento desse menor caminho.

> m) Função para resolver o Problema do Caixeiro Viajante. Essa função deverá completar o
> grafo caso o mesmo não seja completo.

> n) Função para encontrar uma árvore geradora mínima de um grafo com peso nas
> arestas.


> Crie um programa que, utilizando a classe acima, leia em um arquivo o número de vértices
> de um grafo, construa o grafo, e em seguida leia do mesmo arquivo pares de inteiros que
> definem as arestas do grafo. As arestas lidas devem ser adicionadas ao grafo. Teste as
> demais funções da interface da classe.


<a name="CodigoFonte"></a>
##Código Fonte

<a name="main.cpp"></a>
### main.cpp

```c++


```
<a name="Edge.h"></a>
### Edge.h

```c++


```
<a name="Edge.cpp"></a>
### Edge.cpp

```c++


```
<a name="Graph.h"></a>
### Graph.h

```c++


```
<a name="Graph.cpp"></a>
### Graph.cpp

```c++

```

<a name="i/o"></a>
## I/O

<a name="vertex.txt"></a>
### vertex.txt

```c++

```


<a name="SaidaDoConsole"></a>
### Saída do Console

```c++

```




| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| Github | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |


