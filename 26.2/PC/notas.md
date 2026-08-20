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

![media/proc_multiprogramacao](media/proc_multiprogramacao.png)

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

estado de processo (atividade atual)
- segundo Tanenbaum, podem ser
    - em execução: sendo atentido pela CPU
    - pronto: aguardando execução
    - bloqueado (em lock): ocioso, esperando ocorrência de evento externo

        ![proc_estado](media/proc_estado.png)


## Implementação e gerenciamento

o gerenciamento de processos é implementado por uma **tabela de processos**, com campos para:
- gerência de processos
- gerência de memória
- gerência de arquivos

![proc_tabela](media/proc_tabela.png)


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

escalonamento de 
