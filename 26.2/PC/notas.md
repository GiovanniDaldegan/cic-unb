CIC0202 - Programação Concorrente

programas sequenciais são previsíveis. é sempre possível esperar um mesmo resultado a cada execução

programas concorrentes podem bem mais difíceis de prever a cada execução:
- threads podem ser criadas em qualquer ordem
- o escalonamento do SO é imprevisível, pois há outros programas sendo executados e preocupações em consideração
- a depender do compilador e processador, um programa pode ter diferentes tempos de execução e instruções (consequentemente, diferentes contagens de instrução)

assim, erros e execuções particulares podem ser bem difíceis de reproduzir

# Processos


Analogia de preparação de bolos

| factual           | analogia           |
| ----------------- | ------------------ |
| programa          | receita            |
| dados de entrada  | ingredientes       |
| processador       | cozinheiro         |
| processo          | preparação um bolo |
| pilha de execução | linha de produção  |

considerando um SO de core único que administra múltiplos processos concorrentes:
- o processador executa, de fato, um processo por vez
- cada processo tem uma seção da memória reservada, contendo uma pilha de execução com seus contextos de procedimentos (variáveis e argumentos, endereços de retorno )

CPU e threads virtuais: um mesmo processador pode executar apenas uma instrução (atender apenas um processo) por vez, mas ele pode chavear entre processos, alternando entre threads virtuais (pseudoparalelismo, multiprogramação)

![media/proc_multiprogramacao_0](media/proc_multiprogramacao_0.png)

obs: mesmo que seja uma organização pipeline, cada estágio do pipeline é dedicado a apenas 1 instrução

**espera ocupada**: uma thread travada por uma asserção, só avança caso ela seja satisfeita, **gastando recursos** de acesso à memória e avaliação de expressões enquanto **espera**

recursos de um processo
- memória: seção armazenando instruções e dados
- CPU: janela de disposição da CPU para o processo
- dispositivos: comunicação de I/O com periféricos ou memórias externas
- arquivos

um processo é formado por 3 elementos básicos:

- contexto de hardware    

    conteúdo de registradores (PC, SP, ...), alternados na **troca de contexto** entre processos

    ![proc_troca_contexto](media/proc_troca_contexto.png)

- contexto de software    
    - identificação \
        **PID** (Process Identification)
        
        **UID** (User Identification)

    - quota \
        limites de reserva de recursos

    - privilégios \  
        relativos a SO e a outros processos

- espaço de endereçamento
    
    espaço de memória onde o programa é armazenado e o o espaço para seus dados

    ![proc_espaco_enderecamento](media/proc_espaco_enderecamento.png)


<br>

criação de processo
- eventos de inicalização
    - inicialização de sistema

    - chamada de sistema (de um processo) para criação de um processo filho \
        ex: chamada `fork` em UNIX, copiando o contexto de execução do pai para o filho

    - requisição do usuário para criação de processo
    
    - início de tarefa em lote \
        em computadores de grande porte

saídas de processo
- voluntária
    - normal, sem erro
    - exceção, com erro
- involuntária
    - erro fatal
    - cancelamento por outro processo
        
        ex: chamada `kill` no UNIX

tipos de processo (de acordo com seu processamento):
- CPU-bound \
    passa maior parte do tempo utilizando o processador
- I/O-bound \
    passa maior parte do tempo realizando operações de I/O

    ![proc_cpu_io_bound](media/proc_cpu_io_bound.png)

estado de processo (atividade atual), segundo Tanenbaum, podem ser:
- em execução: sendo atentido pela CPU
- pronto: aguardando execução
- bloqueado (em lock): ocioso, esperando ocorrência de evento externo (não compete pela CPU)

![proc_estado](media/proc_estado.png)


## Implementação e gerenciamento

o gerenciamento de processos é implementado por uma **tabela de processos**, com campos para:
- gerência de processos
- gerência de memória
- gerência de arquivos

![proc_tabela](media/proc_tabela.png)


```c
fork();
```

Exemplo de uso de `fork` (um processo criando outros processos)
```
# execução x
proc 0
pid 478090
pai 477976          (terminal executando o programa)
valor 8

    proc 1
    pid 478093
    pai 478090
    valor 10

    proc 2
    pid 478091
    pai 478090
    valor 10

        proc 3
        pid 478092
        pai 478091
        valor 12

# execução y
proc 0
pid 478212
pai 477976          (terminal executando o programa)
valor 8


    proc 1
    pid 478214
    pai 478212
    valor 10

    proc 2
    pid 478213
    pai 2420        (proc 0 terminou antes de proc 2 executar, deixando-o órfão)  
    valor 10

        proc 3
        pid 478215
        pai 478213
        valor 12
```

## Multiprogramação

para otimizar a utilização do 

![proc_multiprogramacao_1](media/proc_multiprogramacao_1.png)

## Escalonamento de processos

a política de escalonamento varia de acordo com o propósito do SO, considerando
- prioridade

isso é implementado por uma heap de prioridade (à esquerda, os ids de processos de maior prioridade, à direita, os de menor). eventualmente, processos não prioritários aumentam de prioridade, pra que não sejam 

## Threads

threads são vantajosas pois compartilham memória de processo e agrupa recursos (espaço de endereçamento, arquivos abertos, etc.). porém, cada uma precisa do próprio PC, registradores, pilha, etc.

teoricamente, a sincronização de threads é semelhante à de processos: usamos locks, filas (heap de prioridade?), etc.

podemos ter processo 1:1 thread ou processo 1:n thread

por exemplo, em um servidor, podemos ter uma thread despachante que recebe dados pela rede e delega tarefas a outras threads operárias. caso uma thread operária precise acessar uma página na memória (não RAM), ela fica bloqueada esperando a transferênica da página pra RAM; nesse meio tempo, se chegar alguma nova requisição, a thread despachante pode alocar outra thread livre pra atendê-la

### Implementação

#### Threads no espaço de usuário

o núcleo (espaço de núcleo) tem apenas uma tabela de processos, os quais inicia e termina. cada processo pode ter uma tabela de threads (espaço de usuário)

problema: o SO não vê a nível de thread, então é possível ter o cenário em que um processo tem 3 threads e uma delas quer ler a memória; assim, o SO bloqueia o processo todo até que os dados requisitados estejam disponíveis, parando a execução

#### Threads no espaço de núcleo (kernel)

o núcleo controla tanto os processos quanto as threads diretamente, adicionando uma tabela de threads em espaço de núcleo, permitindo bloquear threads de um mesmo processo individualmente

desvantagem: o gerenciamento de threads é muito mais lento e custoso. processos precisam requisitar a criação de qualquer thread para o SO, que gasta muito mais tempo chaveando e sincronizando threads, manipulando uma tabela enorme de threads (o que também uma nova camada de complexidade para a tarefa do escalonador de garantir que todos os processos sejam atendidos)

#### Implementação híbrida

é possível um processo ter sua própria tabela de threads em espaço de usuário ou utilizar o sistema de threads do SO, fica a cargo da aplicação

### Escalonamento

Escalonamento em bando: threads mutuamente dependentes podem ser escalonadas juntas, pra que uma passe à seguinte um dado computado ou o acesso a um 

dúvidas
- pq pode ser necessário ter mais de uma thread de controle?
- qual a desvantagem de threads em espaço de núcleo? o processo pede a criação de uma thread pelo núcleo? isso e a tabela unificada de threads em espaço de núcleo atrasam o gerenciamento?
- é mais rápido criar threads do que atualizar a memória alocada pro processo? como o acesso à memória é escalonada e intermediada pelo SO, pode demorar mais?
- os slides no aprender3 tão desatualizados?

```c
void* pthread_func() {
    /* ... */
    pthread_self(); // referência à própria thread
    pthread_exit();
}

int main() {


    for (i = 0; i < N ; i++) {
        id = (int *) malloc(sizeof(int));
        *id = i;
        pthread_create(&a[i], NULL, pthread_func, (void *) (id));
    }
    // alocar mem pra id e passar (void*) (id) garante que cada thread terá um id alocado em memória corretamente alinhado com i
    // caso passemos i, várias threads terão o mesmo id registrado (antes de atualizar i, a thread salvou i como seu id? doidera)
    // talvez seja mais rápido registrar threads no processo do que atualizar a memória do processo (escalonada e intermediada pelo SO)
    // além disso, o escalonamento de processos pode interromper a execução da main, que ainda ia atualizar i, mas coloca as threads t0, t1 e t2 pra executar suas primeiras instruções, para depois a pthread main atualizar i

    pthread_join(id, NULL);
    // espera as threads criadas terminarem, pois senão a thread mãe termina e mata todas as filhas
}



```

fonte: [criar_threads.c](examples/criar_threads.c)

meus testes de 10 pthreads em WSL Ubuntu (com esse código acima do Adilio):

código original compilado: \
![thread_teste0](media/thread_teste0.png)

passando `i` como id das threads criadas, removendo `malloc()` para `int* id` e decrementando `c` em cada thread: \
![thread_teste1](media/thread_teste1.png)

passando `i` como id das threads criadas e decrementando c em cada thread (com `malloc()`, mas sem usar `int* id`): \
![thread_teste1](media/thread_teste2.png)

por algum motivo, as threads não repetem facilmente os ids passados incorretamente (passando a variável `int i` ao invés sem ser o `int* id` alocado). porém, `c` é sempre apresentado variando entre 7 e -1, ao invés de 9 a 0

talvez o WSL Ubuntu tenha alguma característica que acidentalmente sincroniza as threads. quando o prof testou, várias vezes havia 3 processos de id 0 e dois de id 2; quando outro colega testou, conseguiu todos as threads anunciando id 0
