# Projeto Semáforo com Raspberry Pi Pico W

## Descrição
Este projeto consiste na criação de um semáforo utilizando o microcontrolador Raspberry Pi Pico W, três LEDs (vermelho, amarelo e verde) e resistores de 330 Ω. O semáforo altera seus sinais a cada 3 segundos, começando com o LED vermelho aceso.

## Componentes
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω

## Requisitos
1. O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde.
2. O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms).
3. A mudança de estado dos LEDs deve ser implementada na função de call-back do temporizador.
4. A rotina principal, presente no interior da estrutura de repetição while, deve imprimir alguma tipo de informação a cada segundo (1.000 ms).
5. Utilizar a Ferramenta Educacional BitDogLab para experimentar o código, utilizando o LED RGB – GPIOs 11, 12 e 13.

## Funcionalidades Implementadas
- Foi adicionado ao main as funções para inicialização dos 3 leds, sendo o led vermelho já inicializado ligado.
- O main tambem contem função repeating_timer_callback que é responsável pela mudança dos leds a cada 3 segundos. 
- No loop principal (while (true)), uma mensagem é impressa a cada segundo para indicar que o semáforo está funcionando.
