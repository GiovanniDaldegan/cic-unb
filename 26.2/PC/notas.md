# CIC0202 - Programação Concorrente

programas sequenciais são previsíveis. é sempre possível esperar um mesmo resultado a cada execução

programas concorrentes podem bem mais difíceis de prever a cada execução:
- threads podem ser criadas em qualquer ordem
- o escalonamento do SO é imprevisível, pois há outros programas sendo executados e preocupações em consideração
- a depender do compilador e processador, um programa pode ter diferentes tempos de execução e instruções (consequentemente, diferentes contagens de instrução)

assim, erros e execuções particulares podem ser bem difíceis de reproduzir