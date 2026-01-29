#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "headers/values.h"

#include "../headers/servo.h"



void init_servo(svmConf *svc)
{
    gpio_set_function(svc->gpio_number, GPIO_FUNC_PWM);
    svc->slice_num = pwm_gpio_to_slice_num(svc->gpio_number);
    pwm_set_clkdiv(svc->slice_num, CLOCK);
    pwm_set_wrap(svc->slice_num, WRAP);
    svc->channel = pwm_gpio_to_channel(svc->gpio_number);
    pwm_set_chan_level(svc->slice_num, svc->channel, 65465 / 2);
    pwm_set_enabled(svc->slice_num, true);
    
}

void turn_degrees(uint ServoPIO, int degree)
{
    if (degree < 0)
    {
        degree = 0;
    }
    else if (degree > 180)
    {
        degree = 180;
    }
    uint duty_ns = MAX_DUTY - degree * (MAX_DUTY - MIN_DUTY) / 180;
    pwm_set_gpio_level(ServoPIO, duty_ns);
}

void turn_degree_with_velocity(svmConf * svc, uint to_degree, int sleep_time)
{
    if (svc->actual_angle < to_degree)
    {
        for (int degre = 0; degre < to_degree; degre += 1)
        {
            turn_degrees(svc->gpio_number, degre);
            sleep_ms(sleep_time);
            svc->actual_angle = degre;
        }
    }
    if (svc->actual_angle > to_degree)
    {
        for (int degre = svc->actual_angle; degre > to_degree; degre -= 1)
        {
            turn_degrees(svc->gpio_number, degre);
            sleep_ms(sleep_time);
            svc->actual_angle = degre;
        }
    }
    if(svc->actual_angle == to_degree){
        turn_degrees(svc->gpio_number,to_degree);
    }
}
