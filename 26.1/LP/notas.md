**horário monitoria**
Terça-feira, 10:00-11:00h presencial, sala de monitoria do prédio CIC/EST
Sexta-feira, 11:00-12:00h, online, Teams - Erick Rodrigues Fraga


os trabalhos serão exercícios. nos últimos semestres as notas das provas eram mais baixas e dos trabalhos sempre acima de 9, então a partir desse semestre o Vander não vai mais avaliá-los



# Módulo 1

## INTRODUÇÃO

IA simbólica simulando processos profissionais - diagnósticos, análise de contabilidade

IA conexionista - aproximação dos valores desejados

computação neuro-simbólica - integração entre modelos probabilístico e lógico


### Paradigma Lógico
- ligação bidirecional entre E/S, não apenas unidirecional em sentido de analisar entradas e produzir saídas. analisa também as saídas em relação às entradas

vantagens
- permite alto nível de abstração
problemas
- usualmente não possuem tipos, nem são de alta ordem
- podem ser menos eficientes que programas compilados


### Outros paradigmas
Desenvolvimento por agentes...
- agentes de IA não são exatamente uma novidade hoje, a inovação é o caráter conexionista
- programação bem mais alto nível, se declara os requisitos e detalhes do programa e seu código é gerado

tendência: integração de paradigmas
- combinas facilidades e expandindo o domínio de aplicações
- linguagens multi-paradigma: Python, JavaScript, etc.
- se codificado erroneamente, pode gerar contradições e sistemas 
- linguagens se tornam mais complexas, podendo aumentar custo computacional, custo de treinamento de pessoal, dificuldade de transição de sistemas legados para linguagens mais complexas

### outras classificações
- linguagens de 1a., 2a., 3a. 4a. e 5a. gerações
- programação sequencial versus concorrente
- programação linear versus programação visual



> DÚVIDA: toda função com mais de um parâmetro é necessariamente uma composição de funções? essa implementação é eficiente? como otimizar o armazenamento?

> aula 02 - 25/03/26

### Programação Funcional
- alto nível de abstração
- computam resultados apenas sobre as entradas (analogamente a funções matemáticas)
- forte fundamentação teórica (facilita provas)
- traz conceitos fundamentais da computação moderna: abstração (em funções), abstração de dados (tipos), genericidade, polimorfismo, overloading

### Haskell

conceitos importantes:
- Sistema de tipos fortes
- Uso extensivo de recursão
- Polimorfismo e funções de alta ordem
- Tipos de dados algébricos

características
- programação baseada em definições
- não tem variáveis, todos os dados armazenados são constantes
- a declaração de constantes pode ser antes ou depois do seu uso, é irrelevante para o sucesso da compilação


definições
< answer::Int // answer = 42
< greater::Bool // grater = (answer > 71)
< square::Int -> Int // square x = x * x	/// o escopo de x é apenas essa linha, representando uma entrada qualquer; se ocorrer em outro lugar, será uma constante
< allEqual :: Int -> Int -> Int -> Int -> Bool // allEqual n m p = (n == m) && (m == p)
< maxi :: Int -> Int -> Int
< maxi n m	| n >= m	= n	/// | são guardas, a primeira que for válida define o retorno
		| otherwise	= m	/// otherwise é uma constante True, como um default num switch; se nenhuma guarda for avaliada como verdadeira, haverá erro por tempo de execução
< f y = y	/// função polimórfica; se checarmos o tipo no interpretador com :t f, teremos f :: a -> a, sendo a qualquer tipo

tecnicamente, todas funções têm apenas um parâmetro e retornam uma função ou valor com uma saída. Int -> Int -> Bool recebe um inteiro e retorna uma função Int -> Bool, que por sua vez retorna um Bool - aplicação parcial de funções, courificação? de funções


> aula 03


Haskell é fortemente tipada e tem tipagem estática. a linguagem infere tipos a partir da definição da função quando não é tipada explicitamente


parâmetro: definição da entrada de uma declaração de função, é o domínio da função
argumento: valor de entrada da função


Num - TypeClass (Int, Fractional, ...)
type class Eq: classe de todos os tipos que podem ser comparados pela expressão de igualdade ==

allEqual n m p = (n == m) && (m == p)
:t allEqual :: Eq a => a -> a -> a -> Bool

processo de compilação até a chamada de uma função válida:

- compilação	
-> validação da declaração da função
-> checagem de tipos
-> alocação da função
- execução
-> chamada da função
-> checa existência da função
-> checa enumeração de argumentos e seus valores
-> se houver guardas, avalia as condições e obtém a expressão adequada
-> substitui os parâmetros pelos argumentos na expressão da função
-> calcula a expressão
-> chega no resultado, obtém um valor e checa sua validade
-> chega-se no estágio terminal, um valor de retorno numa forma normal. fim da execução

lazy evaluation; pilha de expressões, não apenas valores
a linguagem avalia primeiramente os argumentos mais internos da função. numa chamada recursiva, ele armazena as expressões numa pilha

fat 2   // 2 * fat 1   // 2 * 1 * fat 0   // 2 * 1 * 1   // 2

Maybe : uma forma de definir de funções parciais, possibilitanto uma restrição de domínio para valores não aceitos



> aula 04 25/03


maxSales :: Int -> Int
maxSales n
	| n == 0 	= sales 0
	| otherwise 	= maxi 	(maxSales (n-1))
				(sales n)

maxSales 2   // maxi (maxSales 1) sales 2   // maxi (maxi (maxSales 0) sales 1) sales 2  // (supondo sales n = n)  maxi (maxi 0 1) 2   // maxi 1 2   // 2

no meio da execução acima, o maxi exige saber os valores das chamadas de sales

### padrões na definição de funções
bastante comum em linguagens funcionais

```hs
maxSales :: Int -> Int
maxSales 0 = sales 0		-- assim como nas guardas, ele avalia sequencialmente qual definição casa com o argumento
maxSales n = maxi (maxSales (n-1))(sales n)

myAnd :: Bool -> Bool
myAnd False x = False	  -- myAnd False _ = False
myAnd True  x = x
```
obs. uma linguagem que surgiu prometendo simplicidade OOP foi Java, mas com o tempo foi crescendo e inclusive adotou funções lambda, permitindo um paradigma híbrido com elementos funcionais e casamento de padrões

obs. como Haskell avalia os argumentos da esquerda da direita, em certos cassos pode ser mais eficiente usar os valores fixos em padrões à esquerda e as indeterminadas à direita. não é o caso da função seguinte, por conta da avaliação preguiçosa (lazy evaluation) do Haskell, ela é apenas pra ilustrar

```hs
myAnd :: Bool -> Bool
myAnd _ False = False
myAnd x True  = x
```

#### case
permite casamento de padrões no corpo de uma função

```hs
firstDigit :: String -> Char
firstDigit st = case (digits st) of
                  []      -> '\0'
                  (a:as)  -> a
```


### EXERCÍCIO - funções, recursividade e guardas condicionais

Defina uma função que dado um valor inteiro s e um número de semanas n retorna quantas semanas de 0 a n tiveram venda igual a s.

```hs
sales :: Int -> Int
sales n | n > 3 = 20
        | otherwise = 5

countSales :: Int -> Int -> Int
countSales s n  | n == 0 && (s == sales 0) = 1
                | n == 0 && (s /= sales n) = 0
                | n >  0 && (s == sales n) = 1 + countSales s (n-1)
                | n >  0 && (s /= sales n) = countSales 2 (n-1)
```

obs. as checagens de se s é igual a sales n podem ser omitidas nessa ordem de declaração, mas por alguns motivos podem ser mantidas: legibilidade, se quisermos reordenar as guardas (otimização, caso comum em primeiro), se for um sistema que for mantido por anos ou desenvolvido em colaboração
muitas vezes é interessante ser mais explícito, pra ter mais flexibilidade. apenas em casos específicos é mais benéfico fazer omissões


'' e "" usadas da mesma forma que em C. ' ' é um caractere de espaço, " " é uma string com apenas um espaço

### EXERCÍCIO - strings
Defina a função makeSpaces :: Int -> String que produz um string com uma quantidade n de espaços
Defina pushRight :: Int -> String -> String, utilizando a definição de makeSpaces, para adicionar uma quantidade n de espaços a um dado string.

```hs
makeSpaces :: Int -> String
makeSpaces n  | n == 1 = " "
              | n  > 1 = " " ++ makeSpaces (n-1)  -- os parênteses são necessários para
                                                  -- impedir que a precedência dos operadores
                                                  -- afete a execução e dê erros

pushRight :: Int -> String -> String
pushRight n str = (makeSpaces n) ++ str           -- parênteses não necessários
```


> aula 30/03/26

### Ponto Flutuante

> [ ] DEVER: prof pediu pra testar precisão float (provavelmente na conversão int/float) e trazer observações na próxima aula, mas não sei bem o que ele quis dizer ou estava falando (cheguei dps)

### EXERCÍCIO - float e média
```hs
sales :: Int -> Int
sales n = 4 + 2 * mod n 5

sumSales :: Int -> Int
sumSales n  | n == 0    = sales 0
            | otherwise = sales n + sumSales(n-1)

averageSales :: Int -> Float
averageSales n = (sumSales n) / n
```


### Estruturas de dados

#### Tuplas

```hs
intP :: (Int, Int)
intP = (33,43)

addPair :: (Int, Int) -> Int    -- 1 parâmetro do tipo tupla de inteiros
addPair (x,y) = x+y             -- padrão que se refere a valores internos do argumento tupla
-- mais natural algo assim addPair tup = tup[0]+tup[1]

shift :: ((Int,Int),Int) -> (Int,(Int,Int))
shift ((x,y),z) = (x,(y,z))
```


```hs
addPair intP  />/ addPair (33,43)  />/ x + y [(x,y) / (33,43)]  />/ 33 + 43  />/ 76
```

### Sinônimos de Tipos

```hs
type Name = String
type Age = Int
type Phone = Int
type Person = (Name, Age, Phone)

name :: Person -> Name
name (n,a,p) = n
```

### Definições Locais

questão de estilo de escrita, mas 

```hs
sumSquares :: Int -> Int -> Int

--# definição top-down: define a expressão que usa os nomes locais depois os define
sumSquares x y = sqX + sqY
    where sqX = x * x           -- definição de nomes, mas que representam
          sqY = y * y           -- uma mesma operação

sumSquares x y = sq x + sq y
    where sq z = z * z          -- a função sq captura a abstração idealizada na
                                -- definição anterior, 

--# definição bottom-up: define os nomes locais depois a expressão que os usa
sumSquares x y =  let sqX = x * x
                      sqY = y * y
                  in sqX + sqY
```

### Notação da Linguagem
- case sensitive
- maiúsculas: tipos e construtores
- minúsculas: funções e argumentos
- -- comentário de uma linha / {- comentário de várias linhas... -}

```hs
f  n + 1
f (n + 1)   -- Haskell: aplicação de função precede a operação aritmética

2 + 3       -- forma infixada
(+) 3 2     -- forma prefixada

maxi 2 4
2 `maxi` 4  -- forma infixada de qualquer função binária entre sinais de crase
```

### Erros comuns na Linguagem

obs uso da formação de layouts pra não precisar de muitos parênteses nem ';' para 

```hs
square x =    x   -- expressões devem ocupar exatamente 1 linha
  *x
funny x = x +
  1
answer = 42; newline = '\n'
```

#### Exemplo
programa que analisa raízes de uma função quadrática com base nos seus coeficientes

`The quadratic equation 1.0*X^2 + 5.0*X + 6.0 = 0.0 has two roots: -2.0 -3.0`

```hs
oneRoot :: Float -> Float -> Float -> Float
oneRoot a b c = -b/(2.0*a)

twoRoots :: Float -> Float -> Float -> (Float, Float)
twoRoots a b c = (d-e, d+e)
  where
    d = -b/(2.0*a)
    e = sqrt(b^2-4.0*a*c)/(2.0*a)

roots :: Float -> Float -> Float -> String
roots a b c
  | b^2 == 4.0*a*c = show (oneRoot a b c)
  | b^2 > 4.0*a*c = show f ++ " " ++ show s
  | otherwise = "no roots"
    where (f,s) = twoRoots a b c

-- OU 
--where
--  f = fst(twoRoots a b c)
--  s = snd(twoRoots a b c)
```

### Listas
- sequência de valores de mesmo tipo
- ordem é significativa (diferentemente de conjuntos)
- o número de elementos também importa (dif. de conjuntos)

```hs
[1,2,3,4] :: [Ínt]
[True] :: [Bool]
[(5,True), (7,True)] :: [(Int,Bool)]
[[4,2], [3,7,7,1], [], [9]] :: [[Int]]
['b', 'o', 'm'] :: [Char]
"bom" :: [Char]

type String = [Char]  -- sinônimo de tipo

[]                    -- lista de qualquer tipo
```

### Construtor de listas
construtor/operador ':'
- infixo, associativo *à direita* (com inteiro na esq, lista na direita)
- polimórfico

```hs
5:[]        />/ [5]
4:(5:[])    />/ [4, 5]
2:3:4:5:[]  />/ [2, 3, 4, 5, 6]

(:) :: Int -> [Int] -> [Int]
...
(:) :: t -> [t] -> [t]
```

```hs
[2..7]          = [2, 3, 4, 5, 6, 7]
[-1...3]        = [-1, 0, 1, 2, 3]
[2.8..5.0]      = [2.8, 3.8, 4.8]   -- pa com elementos <= ao último valor
[7,5..0]        = [7, 5, 3, 1]
[2.8, 3.3..5.0] = [2.8, 3.3, 3.8, 4.3, 4.8]
```

> [X] EXERCÍCIO - listas
```hs
[2,3]         -- tem 2 elementos
[[2,3]]       -- tem 1 elemento
[[2,3]]       -- é de tipo [[Int]]
[2,4..9]      -- [2, 4, 6, 8]
[2..2]        -- [2]
[2,7..4]      -- [] X                               -> [2]
[10,9..1]     -- [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]  
[10..1]       -- [10, 9, 8, 7, 6, 5, 4, 3, 2, 1] X  -> []
```

`[prim, seg .. limite]`
prim  : início da pa
seg   : seg - prim é a razão da pa
lim   : todos os elementos da lista serão <= lim

se seg for omitido (`[prim..lim]`) a linguagem considera que é uma pa de razão 1

### Funções sobre listas

```hs
sumList :: [Int] -> Int
sumList []      = 0               -- padrão de lista vazia
sumList (a:as)  = a + sumList as  -- padrão para lista não vazia, onde a é o primeiro
                                  -- item, as é lista com os demais elementos (recursivo)
```

> aula 01/04/26

> **avaliação** : transformação de uma expressão sua forma normal. no caso de uma função, a substituição de uma chamada em uma expressão e obtendo seu valor de retorno
> 
> na avaliação de uma função, a substituição dos parâmetros pelo argumentos é o processo de **biding/ligação** das 
> 
> ```hs
> sumList [2,3,4,5]   --> a + sumList as [(a:as) / (2:[3,4,5])]
> ```


```hs
f :: [Int] -> Int
f [] = 0
f [x] = x
f [x,y] = x*y         -- caso tenha exatos 2 elementos, vai retornar um produto
f (x:y:xys)= x+y      -- se tiver exatos 2 elementos, não vai retornar uma soma

double :: [Int] -> Int
double [] = []
double (y:ys) = (2*y) : (double ys)

member :: [Int] -> Int -> Bool
member [] _ = False
member (x:xs) y | x == y    = True
                | otherwise = member xs y

member1 (x:xs) y = (x == y) || (member xs y)

digits :: String -> String
digits [] = ''
digits (a:as)
  | ord a >= ord '0' && ord a <= ord '9' = a : digits as

sumPairs :: [(Int, Int)] -> [Int]
sumPairs [] = []
sumPairs ((x,y):as) = (x+y) : sumPairs as

alternativa
sumPairs (a:as) = (fst a + snd a) : summPair as
```

> **obs**: o caractere `_` não é um nome ligado de fato a uma variável, podemos utilizá-lo quando é importante marcar um parâmetro ou algo do tipo mas a informação que o representa é desconsiderável

> obs: pattern matching traz a vantagem de esclarecer a ligação entrada-saída das funções, porém é extremamente dependente da tipagem dos dados. se a evolução do código altera minimamente alguma implementação ou tipagem, os padrões podem precisar serem reescritos

### expressão `case`

```hs
firstDigit :: String -> Char
firstDigit st = case (digits st) of
                  []      -> '\0'
                  (a:as)  -> a
```

### polimorfismo
- função tem tipo genérico, atendendo a vários tipos
- reuso de código
- uso de variáveis de tipo

```hs
-- comprimento
length :: [t] -> Int
length [] = 0                   -- lista vazia de qualquer tipo
length (a:as) = 1 + length as

-- concatenação
(++) :: [a] -> [a] -> [a]
[] ++ y = y
(x:xs) ++ y = x : (xs ++ y)

zip :: [t] -> [u] -> [(t,u)]
zip (a:as) (b:bs) = (a,b) : zip as bs
zip [] [] = []
```

> [ ] EXERCÍCIO: testar a função zip para listas de comprimentos diferentes, propor uma solução e ver como Haskell trata isso 
> [ ] EXERCÍCIO: reescrever funções ?? e shuffle de pares usando fst snd ()

Se a ideia da função é fazer a correspondência entre elementos das duas listas par-a-par, não faz muito sentido fazer a correspondência de um elemento de uma das listas com um valor irrelevante, que não faz parte da outra lista. Ainda mais, para alguns tipos seria especialmente difícil estabelecer uma convenção de valor "nulo", por exemplo se fosse zipar uma lista de inteiros com outra de bools, não é plausível estabelecer "True" nem "False" como valores desconsideráveis.

Possíveis soluções:
```hs
zip :: [t] -> [u] -> [(t, u)]
zip (a:as) (b:bs) = (a, b) : zip as bs
zip _ _ = []

-- ou
-- zip (a:as) [] = []
-- zip [] (b:bs) = []
```

```hs
head :: [t] -> t
head (a:as) = a     -- funções parciais, não definidas para listas vazias

tail :: [t] -> [t]
tail (a:as) = as
```

### Banco de dados
exemplo: biblioteca, onde pessoas pegam livros emprestados

```hs
type Person = String
type Book = String
type Database = [(Person, Book)]

exampleBase =
  [("Alice","Postman Pat"),
   ("Anna","All Alone"),
   ("Alice","Spot"),
   ("Rory","Postman Pat")]

books :: Database -> Person -> [Book]
boos [] _ = []
books ((p,b):pbs) person
  | p == person = [] : books as p
  | otherwise   = snd a : books as p

borrowers :: Database -> Book -> [Person]
borrowers ((p,b):pbs) book
  | b == book =
  | otherwise = borrowers

borrowed :: Database -> Book -> Bool
-- opção 1, reutilizando borrowers para tal livro


numBorrowed :: Database -> Person -> Int
-- opção 1, reutilizando books para tal pessoa


```

> obs. a definição de Database traz uma simetria sintática (Person e Book são strings) mas também tem uma simetria semântica, é uma associação 1:1 de pessoa a livro. essa definição da estrutura de dados 

#### Funções de atualizações
em Haskell, temos apenas constantes, 

```hs
makeLoan :: Database -> Person -> Book -> Database
makeLoan db p b = (p,b) : db      -- ou [(p,b)] : db

returnLoan :: Database -> Person -> Book -> Database
returnLoan [] _ _ = []

-- opção 2 - retira todos os empréstimos idêntico
returnLoan (pb:pbs) person book
  | pb == (person, book)  = returnLoan pbs person book
  | otherwise             = pb : returnLoan pbs person book

-- opção 1 - retira apenas o primeiro empréstimo
returnLoan ((p,b):pbs) person book
  | p == person && b == book  = pbs         -- exclui apenas esse (p,b) coincidente
  | otherwise                 = (p,b) : returnLoan pbs person book
```

### compreensões de listas
[elemento | gerador, filtro]
elemento a ser incluído na lista, gerador que fornece a lista de elementos, expressão booleana a ser satisfeita para incluir o elemento na lista

```hs
doubleList xs = [2*a|a <- xs]     -- definição declarativa
-- retorna lista de elementos 2*a tais que a pertence a xs (considerando ordem e quantidade)

doubleIfEven xs = [2*a|a <- xs, isEven a]
-- "2*a" é o elemento a ser incluído na lista, "a <- xs" é o gerador (elementos de xs), e "isEven a" é o filtro (*expressão booleana*) a ser satisfeito pelo elemento a 

sumPairs :: [(Int,Int)] -> [Int]
sumPairs lp = [a+b|(a,b) <- lp]   -- casamento de padrão no gerador
```


> [ ] EXERCÍCIO: identificar quais das funções books, borrowers, borrowed, numBorrowed podem ser reescritas com compreensão de listas e reescrevê-las


### Funções de alta ordem
- funções como argumentos ou resultados de outras funções
- permite definições polimórficas
  - funções aplicadas sobre uma coleção de tipos
  - padrões de recursão usados por várias funções

exemplo: pra não precisar definir a recursão e casos bases para cada função recursiva como em
```hs
double :: [Int] -> [Int]
double [] = []
double (a:x) = (2*a) : double x

sqrList :: [Int] -> [Int]
sqrList [] = []
sqrList (a:x)= (a*a) : sqrList x
```

podemos usar do mapping dessa forma

```hs
times2 :: Int -> Int
times2 n = 2 * n

sqr :: Int -> Int
sqr n = n * n

-- def map
map :: (t -> u) -> [t] -> [u]     -- notação de função/transformação (t -> u)
map f [] = []
map f (a:as) = f a : map f as     -- aplica f recursivamente sobre os elementos

doubleList xs = map times2 xs
sqrList xs = map sqr xs

snds :: [(t,u)] -> [u]
snds xs = map snd xs
```

função map
  - auxilia na modularidade
  - facilita manutenção e incremento do código

  - argumentos
    - a função a ser aplicada acada elemento
    - a lista de entrada

```hs
-- definição alternativa de map
map f l = [f a | a <- l]
```

> [ ] EXERCÍCIO: implementar quick sort, aplicando a listas com elementos repetidos, invertendo a ordem de ordenação

```hs
qs :: [Int] -> [Int]
qs [] = []
qs (a:as) = qs [l | - <- as. l <= a] ++ [a] ++ [l | - <- as. l >= a]
```


> [ ] EXERCÍCIO: implementar maxSales de 0 a n usando maxFun; implementar uma função isCrescent verificando se uma função é crescente de 0 a n 
> [ ] EXERCÍCIO: é possível implementar um map usando um fold? e vice-versa? implementar o foldr. não é possível implementar map usando filter nem vice-versa, pois enquanto o map mantém todas as posições de uma lista e mapeia cada elemento para outro (possivelmente outro tipo), o filter não transforma os elementos de forma alguma e pode diminuir as posições da lista, a depender do predicado aplicado
> [ ] EXERCÍCIO: pensar em que casos fold se diferencia de foldr, ou seja, que operadores (não-associativos) não trazem essa propriedade e dê exemplos


> [ ] exercícios: 
```hs
sqrList :: [Int] -> [Int]
sqrList il = map sqr il
              where sqr a = a * a

sumSqr :: [Int] -> Int
sumSqr il = fold sum il

sumSqr l = foldr (+) 0 (f l)
```

### Funções como valores

#### composição de funções

```hs
-- função de composição (associativa)
(.) :: (u -> v) -> (t -> u) -> (t -> v)
(.) f g x = f (g x)

(f . g) x = f (g x)

-- função de composição pra frente
(>.>) :: (t -> u) -> (u -> v) -> (t -> v)
g >.> f = f . g

-- (g >.> f) x = (f . g) x = f (g x)
```

#### funções como valores e resultados
```hs
twice :: (t -> t) -> (t -> t)
twice f = f . f

{- (twice succ) 12   />/   (succ . succ) 12   />/   succ (succ 12)   />/   14 -}

iter :: Int -> (t -> t) -> (t -> t)
iter 0 f = id
iter n f = f >.> iter (n-1) f
```


### Expressões lambda
top = \a -> "top"

### Aplicações parciais
suponha que tenhamos uma função que recebe dois inteiros. seu funcionamento é: se o primeiro argumento for um número primo, imprime o segundo; caso contrário, imprime o oposto do segundo inteiro

essa função é usada num programa duas vezes, sendo que nas duas vezes o primeiro argumento é igual, apenas o segundo muda. sendo assim, vale a pena computar primeiro a checagem do primeiro argumento, armazenar seu resultado e então esperar o segundo argumento para imprimir o resultado esperado. isso é uma aplicação parcial da função

```hs
multiply :: Int -> Int -> Int
multiply a b = a*b

doubleList :: [Int] -> [Int]
doubleList = map (multiply 2)   -- temos a aplicação parcial inicialmente computada com 2* argumento que falta, passada para um map que espera uma [Int]

(multiply 2) :: Int -> Int
map (multiply 2) :: [Int] -> [Int]
```

na verdade, todas as funções em Haskell são aplicadas parcialmente, pois efetivamente não há funções com mais de 1 parâmetro. o Haskell trata toda função de mais de um parâmetro primeiro como uma composição de funções com apenas um parâmetro cada. quando passamos multiply 2 3, primeiro a linguagem computa multiply 2 e espera o argumento 3 para computar o resultado final

dessa forma, é como se a linguagem criasse várias funções em tempo de execução. e, utilizando a ideia de aplicação parcial no nosso programa, podemos 

```hs
multiply :: Int -> Int -> Int
multiply :: Int -> (Int -> Int)
multiply 4
(multiply 4) 5

-- f a b = (f a) b
-- f a b /= f (a b)
```

point free notation

#### Seções
aplicação de operadores e funções binários

```hs
(+2)                      -- \a -> a + 2
(2+)                      -- \a -> 2 + a
(>2)                      -- \a -> a > 2
(3:)                      -- \l -> 3 : l
(++ "\n")                 -- \s -> s ++ "\n"
map (+1) >.> filter (>0)  -- \l -> filter (>0) (map (+1) l)
double = map (*2)         -- \l -> map (*2) l
```

### typeClass

```hs
class Eq t where
  (==) :: t -> t -> Bool
```
- a classe Eq suporta todos os tipos t que cumpram um contrato de ter implementada a operação binária (==) que retorne um booleano
- para a formalização em linguages de programação, há linguagens em que é possível definir axiomas que definem as restrições e comportamentos necessários para  (Galina do Rock?)
- a typeClass Eq tem, virtualmente, infinitas instâncias: tipos primitivos e listas e tuplas de instâncias de Eq. Int, Float, Char, Bool, [Int], (Int, Bool) .... e demais tipos que cumprirem seu contrato (inclusive tipos além da linguagem padrão). sendo assim, seguindo essa regra, pode-se gerar definições para cumprir o contrato de tipos não primitivos automaticamente


- não podemos ter funções como instância de Eq. para comparar funções, teríamos que comparar suas respectivas saídas para todas as entradas possíveis. Vander: porém, se nem é possível verificar computacionalmente se toda função uma hora para dada uma saída qualquer (Halting Problem), como vamos verificar se os valores retornados são iguais

#### Funções que usam typeClasses

```hs
allEqual :: Eq t => t -> t -> t -> Bool
allEqual n m p = (n == m) && (m == p)
```

- type context: definido pela parte antes de "=>"
- type constraint: exigências de tipo das entradas e saída da função

#### Assinaturas de classe

Podemos definir funções (nome e tipo) que devem ser definidas para cada instância da classe

```hs
class Visible t where       -- tipos representáveis visualmente
  toString :: t -> String   -- deve poder ser escrito em uma string
  size :: t -> Int          -- deve poder declarar seu tamanho
```

#### Criar instâncias de classe

```hs
-- typeClass Eq
instance Eq Bool where
  True == True = True
  False == False = True
  _ == _ = False

-- typeClass Visible
instance Visible Char where
  toString ch = [ch]
  size _ = 1
instance Visible Bool where
  toString True = "True"
  toString False = "False"
  size _ = 1
```

para o type checking do Haskell, basta essas definições para estabelecer que esses tipos `Char` e `Bool` cumprem o contrato definido por `Visible`. porém, linguagens que permitem a definição de axiomas para estabelecer o contrato de uma classe de tipos exigem a computação de uma prova da satisfatibilidade dos axiomas para os tipos elegíveis para a classe


supondo que definimos que `Int` é `Visible`, podemos definir a linguagem de forma que verifique, automaticamente, se `[Int]` é `Visible` com base do tipo dos seus elementos. se todos os elementos de uma lista são `Visible`, então é possível representá-lo numa string concatenando as representações em string de seus elementos e obter seu tamanho somando os tamanhos de seus elementos

```hs
instance Visible t => Visible [t] where
  toString = map toString >.> concat
  size = map size >.> foldr (+) 0
```


#### Definições default
```hs
class Eq t where
  (==), (/=) :: t -> t -> Bool
  a /= b = not (a==b)
```

#### Classes derivadas
```hs
class Eq t => Ord t where               -- Ord é um subconjunto da typeClass Eq
  (<),(<=),(>),(>=) :: t -> t -> Bool
  max, min :: t -> t -> t
  a <= b = (a < b || a == b)
  a > b = b < a
  a < b = b > a
  a >= b = (a > b || a == b)

iSort :: Ord t => [t] ->[t]
```

#### Restrições múltiplas
```hs
vSort = iSort >.> toString
vSort :: (Ord t, Visible t) => [t] -> String  -- o contexto de tipo pode ser uma tupla

instance (Eq t, Eq u) => Eq (t,u) where       -- permissão para infinitas definições de instância
  (a,b) == (c,d) = (a == c && b == d)

class (Ord t, Visible t) => OrdVis t          -- interseção de typeClasses
```

se assemelha ao conceito de Herança Múltipla


## Dúvidas

- oq acontece se aplicar `snd` a uma tupla de 3 elementos ou mais?
- typeClasses trazem a ideia de conjuntos de tipos, mas tecnicamente não são uma lista de tipos que cumprem o contrato, mas são o padrão pra checar em tempo de execução se tais tipos cumprem o contrato ou não, né? é possível ter erro de compilação 

## Tipos algébricos

Com tipos algébricos
- cada objeto do tipo tem um label explícito
- não se pode confundir um tipo com outro, devido ao
construtor (definições bem tipadas)
- o tipo aparecerá nas mensagens de erro

Com tipos sinônimos
- elementos mais compactos, definições mais curtas
- possibilidade de reusar funções polimórficas

todo tipo algébrico **deve** ter construtores de tipo na sua definição, como denotados a seguir

### Tipos Enumerados
```hs
data Bool = True | False
data Estacao = Inverno | Verao |
               Outono | Primavera
data Temp = Frio | Quente

clima :: Estacao -> Temp
clima Inverno = Frio
clima _       = Quente
```

### Produtos
```hs
type Name = String
type Age = Int
data People = Person Name Age
Person ”José” 22
Person ”Maria” 23
showPerson :: People -> String
showPerson (Person n a) = n ++ " -- " ++ show a
Person :: Name -> Aqe -> People
```

### Construtores com argumentos
```hs
data Shape = Circle Float
 | Rectangle Float Float
Circle 4.9 :: Shape
Rectangle 4.2 2.0 :: Shape
isRound :: Shape -> Bool
isRound (Circle _) = True
isRound (Rectangle _ _) = False
```

### Forma geral

```hs
data Nome_do_Tipo
  = Construtor1 t11 ... t1k1
  | Construtor2 t21 ... t2k2
--....
  | Construtorn tn1
```

### Tipos Recursivos

dado: `Cons` recebe dois parâmetros, um literal inteiro 

```hs
showExpr :: Expr -> String
showExpr (Lit n) = show
showExpr (Add e1 e2) = "(" ++ (showExpr e1) ++ " + " ++ (showExpr e2) ++ ")"
showExpr (Sub e1 e2) = "(" ++ (showExpr e1) ++ " - " ++ (showExpr e2) ++ ")"
```

### Tipos polimórficos

```hs
data List t = Nil | Cons t (List t)

toList :: List t -> [t]
toList Nil = []
toList (Cons e l) = e : (toList l)

fromList :: [t] -> List t
fromList [] = Nil
fromList (a:as) = Cons a (fromList as)
```

`toList` e `fromList` definem um isomorfismo entre os tipos `[t]` e `List t`

```hs
depth :: Tree t -> Int
depth NilT = 0
depth (Node _ l r) = 1 + maxi (depth l) (depth r)
```

>[ ] EXERCÍCIO implementar collapse, mapTree

> 06/05

## Funções parciais - Maybe

até agora, deixamos funções parciais indefinidas para os casos fora do domínio, mas sem explicitar que não são entradas válidas. assim, chamando uma função para um valor que não encaixa em nenhum padrão da função, teríamos um erro em tempo de execução indicando que, testando exaustivamente, não há padrão que case com o valor de input

tomando como exeplo a função `fat :: Int -> Int`, para não precisarmos delimitar outro domínio na definição de `fat` com outro tipo, podemos definir a saída da função como um tipo que pode ter valor definido ou não, `Maybe`. teríamos `fat :: Int -> Maybe Int`

o tipo algébrico `Maybe` encapsula um valor com `Just v`, validando-o, ou contém `Nothing`, um valor representando algo indefinido

definição de tipo `Maybe`
```hs
Maybe t = Just t | Nothing
          deriving (Eq, Ord, Show)
```

`Nothing` e `Just` são construtores de tipo diferentes, então não há chance de confundir um valor válido de outro indefinido

```hs
saldo :: String -> [(String,Float)] -> Maybe Float
saldo _ [] = Nothing
saldo person ((p,s):pss)
              | person == p = Just s
              | otherwise   = saldo person pss

{-
saldo "Maria" [("Jose",10), ("Maria",20)]   />/   Just 20.0
saldo "Pedro" [("Jose",10), ("Maria",20)]   />/   Nothing
-}
```

```hs
{-...-}
  case <chamada de func> of     -- casamento de padrão com Just
          Just v -> v +10
```

`fromJust` recebe um `Just` com valor e retorna apenas o valor encapsulado

```hs
import Data.Maybe     -- fromJust
fat :: Int -> Maybe Int
fat 0 = Just 1
fat n
    | n < 0 = Nothing
    | n > 0 = Just (n * (fromJust (fat (n-1))))

f :: Float -> Float -> Maybe Float
f x y
    | y == 0    = Nothing
    | otherwise = Just (x / y)
```


# Módulo 2

a história dos compiladores acompanha a história da abstração nas linguagens de programação. começa nas linguagens de máquina (baixo nível) e, para aumentar produtividade, usabilidade, simplicidade do código fonte e portabilidade, passa a abstrair os conceitos e aproximar das linguagem naturais (alto nível)

é também parte da tendência geral e histórica de automatização de tarefas mecânicas e repetitivas

décadas \
1940: começa-se a representar dados em base binária \
1950: surgem as primeiras linguagens de programação, Fortran, COBOL, Lips - primeira funcional, o resto, imperativa \
1960: ALGOL, BCPL (-> B, -> C), SIMULA - primeira OOP \
1970: Smalltalk, Prolog, ML \
1980: C++, Perl, Python \
1990: Haskell, Java \


## Compilação vs Interpretação

a compilação é a tradução de um código fonte para outro código
a interpretação é a execução do programa sem tradução (o interpretador é executável e interpreta um programa)

- C, em geral, é compilado em código de máquina pelo GCC
- Java é compilado para o bytecode JVM pelo Javac, daí esse bytecode é interpretado (alta portabilidade); mas também é possível compilar Java para código de máquina pello JIT (just in time compilation)
- JavaScript é interpretado nos browsers web
- Unix shell é interpretado pelo shell
- Haskell pode ser compilado pelo GHC ou interpretado em Hugs ou GHCI

Vantagens da interpretação:
- mais prático e desenvolvimento mais rápido
- mais fácil de implementar
- portável

Vantagens da compilação:
- a execução é mais rápida (em geral, mas necessariamente para linguagem de máquina)
- para uma linguagem não dependente de máquina, o código resultantes é mais fácil de interpretar que o fonte

## Fases de compilação

pipeline de compilação:
```
character string
    | lexer         - reconhece os símbolos e quebra em palavras
token string (erros de símbolos e nomes)
    | parser        - interpreta as operações e estrutura a expressão em uma árvore sintática (erros de sintaxe)
syntax tree
    | type checker  - analisa ou atribui os tipos dos operadores, operandos e funções (erro de tipos)
annotated syntax tree
    | code generator - gera as instruções necessárias para representar a expressão
instrucion sequence   (obtida apenas na compilação)
```
> obs. fases de código fonte **Java** para **linguagem de máquina JVM**

partes do programa de compilação \
**Front-end**: **análise** inspeção do programa - lexer, parser, type checker \
**Back-end**: **síntese**, gera algo novo - code generator

### Normalização/Desugaring

remoção do "açúcar síntático", formas ou elementos desnecessários do código fonte que podem ser substituídos por códigos mais simples ou diretos

### Otimização

- source code optimization: pré-avaliar e pré-computar valores conhecidos em tempo de compilação
- target code optimization: escolher instruções mais baratas que as do programa não otimizado

> EXERCÍCIO: !tarefa de expressões! descompactar LE1.rar e estudar execução do processo com base no README.txt + modificar o pattern matching para que os erros sejam enunciados na execução, sem interrupção do programa por erro

## Linguagem Imperativa 1 - LI1

```c
// ex 1
x = x;

// ex 2
x = y;

// ex 1
int x, y;
x = y;
```

> EXERCÍCIO: Obtenha o valor do tipo algébrico representando cada programa apresentado como exemplo da LI1 nos slides anteriores // Você pode checar o resultado usando o programa TestLI, que faz parte do arquivo LI1.rar

para o programa `ex1.li1`
```c
x = 1;
```
```hs
Prog (SAss (Ident "x") (EInt 1))
```

para `ex2.li1`
```c
{
  x = 1;
  y = 2;
  z = x + y;
}
```

como o interpretador vai representar o programa em LI1

```hs
Prog (SBlock [SAss (Ident "x") (EInt 1), SAss (Ident "y") (EInt 2), SAss (Ident "y") (EInt 2), SAss (Ident "z") (EAdd (Ident "x") (Ident "y"))])
```

> EXERCÍCIO: Estenda a definição de tipos algébricos e do interpretador para implementar os comandos for e if. (tentar fazer o for como um bloco único ou como um caso específico do while)

LI1:
- contexto dinâmico com variáveis
- comandos e blocos de comando

motivação da LI2: a LI1 não oferece nenhum tipo de modularização
- todo comando que quisermos repetir ao longo do programa exige que ele seja copiado e que essa cópia seja executada
- a concepção e compreensão de um único bloco enorme de código como programa é bem mais trabalhosa (assim como a manutenção)


## Linguagem Imperativa 2 - LI2

novidades: chamadas de função e retorno, literais e operadores booleanos e de string

agora, um programa é uma lista de funções e, por padrão, executa apenas a que for identificada como "main". no seu corpo, ela pode executar comandos de atribuição, bloco de comandos, condicional, ou chamar outra função 

todo contexto local de uma função deve conter também todas as funções existentes, pois podemos chamar qualquer função em seu corpo de execução (exceto a main, preferencialmente, para evitar ciclos)

returno: a função chamada mapeia seu resultado no seu contexto de execução para então busca esse valor para comunicar ao contexto antecessor. o escopo antecessor então incrementa seu contexto adicionando o resultado da função

ao chamar uma função, o programa checa a existência dela no contexto de execução (lista). como **ainda** não temos checagem de tipos na LI2, teremos um **erro de execução** ao tentarmos chamar uma função que não existe


motivação para a tipagem dos valores: evitar operar valores que não correspondem ao uso correto dos operadores ou que contradigam a avaliação das expressões
- podemos mudar a gramática das expressões da linguagem LI1 (não evita todos os casos não desejados)
- ou fazer de outra forma, evitando expressões mal formadas e mais


## Linguagem Imperativa 2 Tipada - LI2T

### Inicialização

as variáveis são declaradas informando seu tipo apenas (**sem valores**). nas etapas de back-end da linguagem LI2T, vamos inicializar as variáveis com valores padrão de acordo com seus tipos

```c
int x;      // x = 0
bool z;     // z = false ?
String y;   // y = ""
```

### Checagem estática de tipos

#### Variáveis

além de impedir que alguns casos de códigos inconsistentes e potencialmente errôneos sejam tratados como programas bem-formados, a tipagem fornece uma integração maior entre etapas de desenvolvimento, exigindo que o programador tenha maior consciência do uso de funções e variáveis

no processo de checagem (estática) de tipos, vamos manter um **contexto de tipos**. em um dado escopo, todas as variáveis devem ser mapeadas para um tipo no contexto de tipos

a inicialização de uma variável, nessa checagem de tipos (front-end), consiste na declaração de seu nome e tipo simultaneamente. a execução do comando de inicialização atualiza o contexto de tipos, adicionando o mapeamento da variável para um tipo

caso uma variável já esteja presente num mesmo contexto e a declaremos novamente, teremos um erro de declaração repetida

#### Funções

além disso, as funções devem retornar exatamente 1 valor, cujo tipo devemos declarar na assinatura da função. para a execução do programa, esse tipo declarado é uma promessa, nem sempre temos certeza que será retornado um valor (funções que não param, erros de execução, etc.). porém, podemos pelo menos checar se o programa define o retorno de uma expressão/valor de mesmo tipo da assinatura

e claro que os parâmetros devem ter tipo definido. a assinatura da função passa a incluir também o tipo de cada parâmetro

por enquanto, vamos simplificar o retorno de funções. o último comando de toda função deve ser da forma `return`, e apenas deve ser usado como último comando de uma função (isso pra facilitar a checagem de tipo e **promessa de retorno** da função)

tanto a inferência de tipos quando a checagem de tipos são recursivas e chamam uma a outra

#### Escopo

para cada escopo do programa (uma função, um bloco de um while, etc.), tanto para a checagem de tipos quanto para a execução, é necessário que todas as variáveis utilizadas tenham sido inicializadas

duas funções diferentes sempre terão escopos e contextos completamente separados, apenas se "comunicam" pela passagem de argumentos, tanto na compilação quanto na execução

no caso de criar um bloco aninhado em um escopo maior, empilhamos um contexto de tipos do bloco aninhado sobre o contexto que o engloba. temos então uma **pilha de contextos** de execução e de tipos

quando utilizarmos as funções de *lookup*, a busca será feita do topo da pilha para a base, dando prioridade para o escopo mais aninhado


#### Exemplos

```c
int main () {
  int f;
  f = fat(5);
  return f;
}

int fat (int n) {
  int r;
  if (n)
    then r = n * fat(n-1);
    else r = 1
  return r;
}
```

para avaliar o programa acima, precisamos checar se:

`main`
- o tipo de `f` é definido
- a função `fat` é chamada corretamente, ela existe e os argumentos casam com os parâmetros
- a atribuição de `f` é realizada com uma expressão de mesmo tipo da variável atribuída
- a função retorna uma expressão de mesmo tipo que a promessa de sua assinatura

`fat`
- o tipo de `r` é definido
- o comando `if` tem uma expressão numérica `n` e dois comandos para `then` e `else`
- os comandos aninhados em `if` são bem tipados

  `then`
  - `fat` existe, o argumento `n-1` é do tipo da assinatura da função
  - a multiplicação é feita entre um inteiro `n` e uma função de tipo inferido de retorno `int`
  - é atribuído um inteiro a `r`

  `else`
  - é atribuído um inteiro 1 a `r`

- a função retorna uma expressão do mesmo tipo que o declarado na sua assinatura


o seguinte programa é válido, pois o bloco aninhado implica a formação de um novo contexto aninhado no escopo de `main`, de forma que não há dupla declaração de `i`
```c
int main () {
  int i;
  i = 2;

  {
    int i;
    i = 3;
  }

  return i;
}
```

já esse programa não é válido/bem-tipado, pois tenta acessar uma variável `i` não definida no escopo geral de `main`
```c
int main () {
  int j;
  j = 2;

  {
    int i;
    i = 3;
  }

  j = i;
  return j;
}
```

o próximo programa também é válido
```c
int main () {
  int j;
  j = 2;
  
  {
    int i;
    i = 3;
    j = i;
  }
  
  return j;
}
```