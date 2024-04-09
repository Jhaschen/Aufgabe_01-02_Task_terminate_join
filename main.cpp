/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdint>


// Blinking rate in milliseconds
#define BLINKING_RATE     200ms

Thread thread_led2(osPriorityNormal,OS_STACK_SIZE,NULL,"LED2_THREAD");
Thread thread_led3(osPriorityNormal,OS_STACK_SIZE,NULL,"LED3_THREAD");


void led2_thread()
{
    uint8_t cnt_1=0;
    DigitalOut led2(D2);
    while (cnt_1<=10) {
        led2 = !led2;
        cnt_1++;
        ThisThread::sleep_for(250ms);
    }
  thread_led2.terminate(); // Thread wird kontrolliert beendet( Auch der Stack wird friegegben)
  
  
  }
void led3_thread()
{
    uint8_t cnt_2=0;
    DigitalOut led3(D3);
    while (cnt_2<=10) {
        led3 = !led3;
        cnt_2++;
        ThisThread::sleep_for(1000ms);
    }
    thread_led3.terminate();
}



int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led1(LED1);

    
    thread_led2.start(led2_thread);
    thread_led3.start(led3_thread);




    while (true) {
        led1 = !led1;
        
        ThisThread::sleep_for(BLINKING_RATE);

        //oder 
        //thread_led3.join(); // Hier wird gewartet bis der Thread beendet wurde, aus der while-Schleife gesprungen ist.
       // thread_led2.join();

        
    }
}
