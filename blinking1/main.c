#include "stm32f1xx.h"
#include "FreeRTOS.h"
#include "task.h"

static const int delay_1 = 2137;

static void led_task(void* args);

int main(void) {

    /* enable clock for ports: A */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    /* TODO: clock setup, tick setup */
 
    // mind its in output mode
    GPIOC->CRH &= ~GPIO_CRH_MODE13_Msk; // clear mode bits
    GPIOC->CRH |= GPIO_CRH_MODE13_0;  // Set MODE13[0]-bit -> now is 01, in output mode
    GPIOC->CRH &= ~GPIO_CRH_CNF13_Msk; // clear both CNF13[1:0] bits -> make it 00 push-pull
    
    /* create tasks */
    /* TODO: understanging what these words mean */
    xTaskCreate(led_task, "blinking", 128, (void*)(&delay_1), configMAX_PRIORITIES - 1, NULL);

    vTaskStartScheduler();
}

/* task definition */

static void led_task(void* args) {
    int delay_ms = *((int*)args);
    
    while (1) {
        /* toggle */
        GPIOC->ODR ^= GPIO_ODR_ODR13;

        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}
