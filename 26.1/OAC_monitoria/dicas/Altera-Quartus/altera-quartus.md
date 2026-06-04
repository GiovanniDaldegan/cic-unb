## Frequência
caso SW[4:0] = 5'b00000
- freq = 50 MHz / 256

senão
- 50 MHz / (SW[4:0])
- varia de 50 MHz (5'b00001) até 50 / 31 = 1,61 MHz (5'b11111)


Display 7 segmentos
S[]

Índice
1. [Setup Quartus + ModelSim](#setup-quartus--modelsim)
    1. [Setup Quartus + ModelSim](#setup-quartus--modelsim)
    1. [Setup Quartus + ModelSim](#setup-quartus--modelsim)
1. 

## Setup Quartus & ModelSim
componentes:
- Quartus Prime Lite Edition
- Questa*-Altera FPGA and Starter Editions
- Cyclone V device support
- MAX 10 FPGA device support


### Instalação Quartus ([Windows](https://www.altera.com/downloads/fpga-development-tools/quartus-prime-lite-edition-design-software-version-25-1-windows), [Linux](https://www.altera.com/downloads/fpga-development-tools/quartus-prime-lite-edition-design-software-version-25-1-linux))
- instalador
    seleciona componentes e instala (baixar e instalar)
- manual
    baixar
    - Quartus Prime
    - Questa*-Altera FPGA and Starter Editions
    - Cyclone V device support
    - MAX 10 FPGA device support
    com todos instaladores e suportes na mesma pasta
    - instalar Quartus Prime
    - Questa*-Altera FPGA and Starter Editions
- completo

Altera Download Center - Quartus Prime Lite: \
https://www.altera.com/downloads/fpga-development-tools/quartus-prime-pro-edition-design-software-version-26-1-windows

### Instalação ModelSim ([Windows/Linux](https://www.altera.com/downloads/simulation-tools/modelsim-fpgas-standard-edition-software-version-20-1-1))
- baixar e instalar ModelSim-FPGA Edition

Altera Download Center - ModelSim
https://www.altera.com/downloads/simulation-tools/modelsim-fpgas-standard-edition-software-version-20-1-1


setup
- variáveis de ambiente da licensa (LM_LICENSE_FILE, SALT_LICENSE_FILE, SALT_LICENSE_SERVER)


## Desenvolvimento em HDL - Verilog


## Compilação do design - Quartus


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

### Editar memória da placa

Tools > In-System Content Editor
F5 mostra a memória da placa
Selecionar a unidade de memória (DATA, TEXT), clicar com o botão direito e Import Data From File
F7 carrega a memória selecionada e sobrescreve na placa, reiniciando a execução


# Referências

M. V. LAMAR. *Tutorial de uso do Quartus-Prime v2.2*.