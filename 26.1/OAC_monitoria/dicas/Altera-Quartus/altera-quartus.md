
Índice
1. [Setup Quartus + ModelSim](#setup-quartus--modelsim)
    1. [Setup Quartus + ModelSim](#setup-quartus--modelsim)
    1. [Setup Quartus + ModelSim](#setup-quartus--modelsim)
1. 


## Setup Quartus & ModelSim

Componentes (mínimo para OAC):
- Quartus Prime Lite Edition
- Questa*-Altera FPGA and Starter Editions
- Cyclone V device support
- MAX 10 FPGA device support


### Instalação Quartus ([Windows](https://www.altera.com/downloads/fpga-development-tools/quartus-prime-lite-edition-design-software-version-25-1-windows), [Linux](https://www.altera.com/downloads/fpga-development-tools/quartus-prime-lite-edition-design-software-version-25-1-linux))

- Instalador (recomendado)
    1. Baixar instalador personalizado
    
    1. Selecionar componentes listados acima
    
    1. Iniciar o download e instalação dos componentes

    ![instalador](instalador.png)

- Manual
    1. Baixar, **na mesma pasta**, os componentes listados [acima](#setup-quartus--modelsim)

    1. Com todos instaladores e suportes de dispositivos na mesma pasta
        - Instalar Quartus Prime
        - Instalar Questa*-Altera FPGA and Starter Editions

- Completo (download 6.5 GB, espaço necessário 31.37 GB)
    1. Baixar o instalador completo (Quartus e Questa-Altera FPGA + suportes para dispositivos)

    1. Instalar

Altera Download Center - Quartus Prime Lite: \
https://www.altera.com/downloads/fpga-development-tools/quartus-prime-pro-edition-design-software-version-26-1-windows


#### Possíveis erros na instalação

É possível que o instalador tenha problemas para estabelecer uma conexão com a internet. Se o problema persistir, pode ser melhor instalar os proramas individualmente (ou a versão completa). \
![erro_instalador](erro_instalador.png)

### Instalação ModelSim ([Windows/Linux](https://www.altera.com/downloads/simulation-tools/modelsim-fpgas-standard-edition-software-version-20-1-1))
Baixar e instalar ModelSim-FPGA Edition.

Altera Download Center - ModelSim
https://www.altera.com/downloads/simulation-tools/modelsim-fpgas-standard-edition-software-version-20-1-1


### Setup adicional

Garantir que as seguintes variáveis de ambiente da licensa Altera estão definidas. \
Por garantia, eu defino todos as seguintes apontando para a licensa no meu computador:
- `LM_LICENSE_FILE`
- `SALT_LICENSE_FILE`
- `SALT_LICENSE_SERVER`

![variaveis_de_ambiente](variaveis_de_ambiente.png)

Exemplo de erro na simulação por variável não definida: \
![erro_var_amb_salt_server](erro_var_amb_salt_server.png)

> [!note]
> Acredito que `LM_LICENSE_FILE` é essencial para o Quartus Prime 24.1 e `SALT_LICENSE_SERVER` pro 25.1. Como teve um rebranding de Intel &rarr; Altera, devem ter mudado alguns detalhes de licensa e do software.


## Desenvolvimento em HDL - Verilog

[a preencher]


## Compilação do design - Quartus

1. Selecionar o arquivo correto como Top-Level \
    Na seção Project Navigator, selecione a aba Files. Clique com o botão direito sobre o arquivo e selecione a opção "Set as Top-Level Entity".

    ![set_as_top-level_entity](set_as_top-level_entity.png)

1. Analisar recursos físicos \
    Anotar os valores mostrados no Flow Summary depois da compilação:
        - Total de ALMs 
        - Total de registradores
        - Número de bits usados
        - Número de blocos de DPS

    ![requisitos_fisicos](requisitos_fisicos.png)

1. Analisar recursos temporais
    Tools > Timing Analyzer

    ![tools_timing_analyzer](tools_timing_analyzer.png)

## Simulação - Quartus


## Simulação - FPGA DE1-SoC (Cyclone V)


### Carregar design na placa

Tools > Programmer
Selecionar placa (Programmer > Hardware Setup > Currently selected hardware)
Programmer > Auto Detect, selecionar 5CSEMA5
Selecionar o dispositivo 5CSEMA5, Programmer > Change file..., selecionar o design compilado `.sof`
No despositivo 5CSEMA5, selecionar a caixa Program/Configure
Programmer > Start


### Funções do processador (interface FPGA)

SW[5] \
    0 endereço \
    1 instrução

...

Frequência

caso SW[4:0] = 5'b00000
- freq = 50 MHz / 256

senão
- 50 MHz / (SW[4:0])
- varia de 50 MHz (5'b00001) até 50 / 31 = 1,61 MHz (5'b11111)


Display 7 segmentos
S[]

### Editar memória da placa

1. Tools > In-System Content Editor

1. `F5` mostra a memória da placa \
    Caso não apareçam as unidades de memória de dados   e programa, feche a janela e abra novamente (chance de crashar, independentemente).

1. Selecionar a unidade de memória (DATA, TEXT), clicar com o botão direito e Import Data From File

1. `F7` carrega a memória selecionada e sobrescreve na placa, reiniciando a execução


# Referências

M. V. LAMAR. *Tutorial de uso do Quartus-Prime v2.2*.