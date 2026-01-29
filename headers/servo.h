#ifndef SERVO_H_   /* Include guard */
#define SERVO_H_

typedef struct servomotorConf
{
    uint32_t actual_angle;
    uint slice_num;
    uint channel;
    uint gpio_number;
}svmConf;

typedef struct servoarm
{
     svmConf scv[4];
     
}svarm;

void init_servo(svmConf * svc);
void turn_degree_with_velocity(svmConf *svc, uint to_degree, int sleep_time);

#endif 
