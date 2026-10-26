# Tradução

Análise:
- erro léxico: token indevido. nomeação de variável indevida, palavras reservadas
- erro sintático: erro estrutural na gramática em um comando. expressão
- erro semântico: erro de lógica, incoerência entre comandos (linhas do programa).
- árvore de derivação: árvore sintática de um comando


scanner separa os tokens do programa (identificando tokens inválidos), parser monta a árvore de derivação (indentificando estruturas erradas, nós faltando)

<br>

Síntese:
- código de 3 endereços (código intermediário, com operação e até 2 operadores) \
  vai cobrar conversão de um código simples em C pra código de 3 endereços

- otimização simples
  1. garantir que duas operações não fazem a mesma coisa (mesmos valores de operandos e operação)
  2. garantir que não há operações independente de loop dentro de um loop


# Montador

a tabela das instruções do assembly inventado vai ser projetada no quadro durante a prova

a questão de programação em assembly pode ser algo como
- receba dois números e indique qual dos dois é maior
- receba base e altura de um triângulo, calcule a área, etc.

montagem da tabela de símbolos: listar todos os rótulos e seu endereço de declaração \
lista de pendências: lista de endereços que referenciam um **rótulo ainda não declarado**

> [!note] obs:
> todas as novas referências a um rótulo depois que ele já foi definido **não devem adicionar endereços na lista de pendências**

<br>

```
0  | FRONT:  INPUT   N1
2  |         INPUT   N2
4  |         LOAD    N1
6  |         ADD     N2
8  |         STORE   N3
10 |         OUTPUT  N3
12 |         STOP
13 | N1:     SPACE
14 | N2:     SPACE
15 | N3:     SPACE
```

| rótulo | endereço | lista de pendências   |
| ------ | -------- | --------------------- |
| FRONT  | 0        | -1 (lista vazia)      |
| N1     | 13       | 5 &rarr; 1 &rarr; -1  |
| N2     | 14       | 7 &rarr; 3 &rarr; -1  |
| N3     | 15       | 11 &rarr; 9 &rarr; -1 |

pode ser que ele cobre a lista de pendências inserida no código (indexada)

primeiro, indica rótulos ainda não definidos com -1, quando é definido, substitui com o endereço correto

quando encontrar a declaração do rótulo, 

diferenças dos algoritmos de passagem única e duas passagens (vantagens e desvantagens)

<br>

---

MACROs
- associa um trecho de código a um nome
- no pré-processamento, todo nome de macro é substituído pelo trecho (expansão de macro)
- não deve ter macro recursiva

```
SWAP: MACRO     &A, &B, &T    ; argumentos da macro
      COPY      &A, &T
      COPY      &B, &A
      COPY      &T, &B
      ENDMACRO
      ...
```

<br>

---

o montador deve gerar:
- código objeto do programa
- tabela de símbolos (PUBLIC, rótulos e seus endereços)
- tabela de uso (EXTERN, rótulos externos)

# Ligador

1. alinhar módulos
2. calcular fatores de correção
3. montar a Tabela Global de Definições (combina as tabelas dos módulos)
4. corrigir as referências cruzadas
5. corrigir os endereços relativos do programa com o fator de correção correto


# Carregador

carregador estático: sempre carrega num endereço fixo da memória. simples, mas só permite a execução de 1 programa por vez \
carregador dinâmico: carrega código relocável em qualquer endereço (precisa corrigir endereços). complexo, mas permite vários programas em execução

# Bibliotecas

ligador estático \
ligador dinâmico \
carregador estático \
carregador dinâmico


# 3 mandamentos
1. se virar professor, nunca dê uma prova fácil
2. nunca use gravata
3. nunca mande ou ouça áudio no whatsapp
