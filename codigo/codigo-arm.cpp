#include "pico/stdlib.h"

int main() {

    const uint LED = 25;

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    while (true) {

        // Simula condição de alerta
        gpio_put(LED, 1);
        sleep_ms(1000);

        // Sistema seguro
        gpio_put(LED, 0);
        sleep_ms(1000);
    }
}
