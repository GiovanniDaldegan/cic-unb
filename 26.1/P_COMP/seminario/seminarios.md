## DSU

- o que é o swap(a, b) na união?
  é a troca do representante (parent) de a e b (?), para garantir que sempre unimos o menor componente para o maior componente. essa otimização garante que a árvore gerada nas uniões sempre têm a menor profundidade possível e menor número de filhos adicionados nas folhas da ávore já existente


## Segtree 2D

- matriz com valores 0 ou 1
- árvore binária de "segmentos" da matriz, vetores de inteiros, em que cada posição tem o valor acumulado de 

String Matching: KMP (Knuth-Morris-Pratt)

percorremos uma string e buscamos quantas vezes uma segunda string ocorre nela

## LPS (Longest proper Prefix which is also Suffix)

ABABA
11100  - primeira ocorrência
00111  - segunda ocorrência

1. construímos o array de LPSs (para cada posição)
1. percorremos a string apenas avançando
  acumula um `len` do tamanho do prefixo

  para cada posição, se o caractere dela 

  se, ao final de um trecho analisado, o padrão não ocorre, voltamos para o último prefixo que casa com o padrão

## Psum 2D e "N"D

dado uma matriz com valores 0 ou 1, guardamos numa nova matriz com o PSUM 2D dela, de forma que cada posição [i][j] guarda a contagem de ávores no intervalo ([0][0], [i][j])

então, cada posição é calculada em função


```c++
soma = 0;
soma += m[i][j];
soma += m[i-1][j] + m[i][j-1];
soma -= m[i-1][i-j];
psum_m[i][j] = soma;
```

## Exponenciação de matrizes

problema: Fibonacci Numbers

- representar números da sequência de fib por matriz -> a matriz [[1, 1], [1, 0]] é multiplicada à esquerda n vzs
- implementar exponenciação de matrizes

```
[fn, fn-1] = [[1, 1], [1, 0]] x [fn-1, fn-2]
```

exponenciação binária

$$(13)_{10} = (1101)_{2}$$
$$5^{2^3} + 5^{2^2} + 5^{2^0}$$

$5^{13} = 5 * 5 * 5 * 5 * ...  * 5 * 5 * 5$ \
$5^{13} = 25 * 25 * ... * 25 * 5$ \
$5^{13} = 625 * ... * 625 * 25 * 5$


## Produto vetorial

problema: qual posicionamento de um ponto $p_3$ em relação a uma reta definida por outros dois ($p_1$, $p_2$)

collision boxes: como tudo 

montamos uma matriz com os vetores de p()

e calculamos seu determinante, que 
- det < 0 : o vetor 

O(1) temporal, O(1) de espaço

## menor polígono convexo

aplicamos um "filtro do quadrado mínimo" nos pontos, de forma que calculamos o $x$ e $y$ mínimos e máximos de todos os pontos e traçamos um quadrado que conecte esses pontos; todos os pontos dentro desse quadrado não são bons candidatos para serem vértices do polígono final

agora, sobre os vértices fora desse quadrado

usamos produtos vetoriais para encontrar qual 

procuramos os vértices candidatos a vértices


## XOR and favorite number

problema: dado um K, quantos subintervalos de um vetor tem XOR valendo K? \
para o intervalo $[i,j]$, queremos saber quantos subintervalos desse tem XOR cumulativo igual a K

computar o vetor pxor, acumulando o XOR consecutivo dos elementos


range query de frequência

dividir o vetor em $\approx \lfloor{\sqrt{n}}\rfloor$ intervalos, mantendo seus tamanhos próximos, equilibrando quantos blocos teremos e o deslocamento necessário para um ponteiro percorrer um bloco inteiro

&rarr; guardamos tabela de frequência de um bloco ? \
&rarr; agiliza quando consultamos em um bloco como inteiro, mas ainda temos que percorrer o vetor quando engloba apenas parte de um bloco

complexidade temporal: $\mathcal{O}(M * B + \frac{N^2}{B})$ \
com $B$ sendo o número de blocos

Algoritmo de Mo: ordenamos as queries de forma que uma  use um bloco próximo 

complexidade da movivmentação da janela de Mo $\mathcal{O}((N + M) * \sqrt{N})$

complexidade de memória: $\mathcal{O}(N + M + MAX\_VAL)$ \
com $MAX\_VAL$ sendo o tamanho do vetor de frequência


## String Hashing

problema: encontrar o maior palíndromo contido em uma string

primeiro, pré-processamos a string na ordem normal e invertida, passando cada substring por uma função *hash*

para garantir que não haja colisão, utilizamos uma *hash* polinomial dupla (repetida)

então, para cada valor *hash* de uma substring da string original buscamos um valor idêntico no vetor de *hash* das substrings da string inversa; se for igual, temos um palíndromo


## String matching (dnv?)

problema: calcular a frequência de um padrão em uma string

mapeamos o $i$-ésimo caractere da string para $b^i * str[i]$, tecnicamente passando por um *hash* monomial/polinomial de 1 entrada em um novo vetor, de forma que usemos o mesmo coeficiente **(maior que a quantidade total de caracteres possíveis)** para todos os monômios

para garantir que não haja colisão, no fim das contas fazemos um *hash* duplo (creio que isso é suficente pra garantir que o limite de tamanho `ll`)

fazemos um psum nesse vetor de *hashes*
