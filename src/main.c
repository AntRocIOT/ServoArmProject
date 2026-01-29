#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "headers/values.h"
#include "headers/servo.h"


int led_value = 0;
int direction_flag = 0;

void init_pico_led(){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void init_libraries(){
     stdio_init_all();
}

int main()
{
    init_libraries();
    init_pico_led();
    absolute_time_t test_led_timer = get_absolute_time();

    svmConf svc1 = {.actual_angle=0,.slice_num=0,.channel=0,.gpio_number=SERVO_ONEF};
    svmConf svc2 = {.actual_angle=0,.slice_num=0,.channel=0,.gpio_number=SERVO_TWOF};
    svmConf svc3 = {.actual_angle=0,.slice_num=0,.channel=0,.gpio_number=SERVO_THREEF};
    svmConf svc4 = {.actual_angle=0,.slice_num=0,.channel=0,.gpio_number=SERVO_FOURF};

    svarm sa = {
        .scv = {
                svc1,
                svc2, 
                svc3,
                svc4
        }
    };
    svarm *psa = &sa;

    init_servo(&(psa->scv[0]));
    init_servo(&(psa->scv[1]));
    init_servo(&(psa->scv[2]));
    init_servo(&(psa->scv[3]));
    
    while (true) {
        printf("Servo 1 configuration:: ANGLE = %d, CHANNEL = %d,SLICE = %d, GPIO = %d \n",psa->scv[0].actual_angle,psa->scv[0].channel,psa->scv[0].slice_num ,psa->scv[0].gpio_number);
        printf("Servo 2 configuration:: ANGLE = %d, CHANNEL = %d,SLICE = %d, GPIO = %d \n",psa->scv[1].actual_angle,psa->scv[1].channel,psa->scv[1].slice_num ,psa->scv[1].gpio_number);
        printf("Servo 3 configuration:: ANGLE = %d, CHANNEL = %d,SLICE = %d, GPIO = %d \n",psa->scv[2].actual_angle,psa->scv[2].channel,psa->scv[2].slice_num ,psa->scv[2].gpio_number);
        printf("Servo 4 configuration:: ANGLE = %d, CHANNEL = %d,SLICE = %d, GPIO = %d \n",psa->scv[3].actual_angle,psa->scv[3].channel,psa->scv[3].slice_num ,psa->scv[3].gpio_number);
        printf("Welcome to blink \n");
        
        if(us_to_ms(absolute_time_diff_us(test_led_timer,get_absolute_time())) >= 250 )
        {
            led_value = 1 -led_value;
            gpio_put(LED_PIN,led_value);
            test_led_timer = get_absolute_time();
        }
        turn_degree_with_velocity(&(psa->scv[0]),0,10);
        turn_degree_with_velocity(&(psa->scv[1]),45,10);
        turn_degree_with_velocity(&(psa->scv[2]),135,10);
        turn_degree_with_velocity(&(psa->scv[3]),10,10);
       
        
        turn_degree_with_velocity(&(psa->scv[0]),90,10);
        turn_degree_with_velocity(&(psa->scv[3]),130,10);
        printf("SERVO ARM: TOPOS2! GO TO OBJ \n");

        turn_degree_with_velocity(&(psa->scv[1]),15,10);
       
        printf("SERVO ARM: TOPOS3! \n");

        turn_degree_with_velocity(&(psa->scv[3]),10,10);
        printf("SERVO ARM: TOPOS4! CLOSE ARM\n");
        
        turn_degree_with_velocity(&(psa->scv[1]),45,10);
        printf("SERVO ARM: TOPOS5! \n");
        turn_degree_with_velocity(&(psa->scv[0]),180,10);
        printf("SERVO ARM: TOPOS6! \n");
        turn_degree_with_velocity(&(psa->scv[2]),180,10);
        turn_degree_with_velocity(&(psa->scv[1]),0,10);
        printf("SERVO ARM: TOPOS7! \n");
        turn_degree_with_velocity(&(psa->scv[3]),140,10);
        turn_degree_with_velocity(&(psa->scv[1]),90,10);
       
     }
}

