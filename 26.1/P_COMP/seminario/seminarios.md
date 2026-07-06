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