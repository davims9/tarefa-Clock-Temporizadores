#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

int estado_led = 0;

//função para definifir que led será ligado
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (estado_led) {
        case 0:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            estado_led = 1;
            break;
        case 1:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            estado_led = 2;
            break;
        case 2:
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            estado_led = 0;
            break;
    }
    return true;
}

int main() {
    // Inicializa a saída padrão e a UART para comunicação serial
    stdio_init_all();
    
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 1); // Inicia com o LED vermelho aceso

    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    //loop para mensagem do terminal
    while (true) {
        printf("Semáforo está funcionando...\n");
        sleep_ms(1000);
    }

    return 0;
}
