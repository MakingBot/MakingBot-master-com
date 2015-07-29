#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED
#define TAKEJETONPWM \
while (jetonPwm);\
jetonPwm = 1;
//uint jetonPwm; //jeton pwm est remis à 0 lors d'un nouveau cycle pwm permet de bloquer une execution
typedef struct
 {
 uchar R;
 uchar G;
 uchar B;
 uchar A;
 }led_power;
void pwm_init();
uint set_color(uint R,uint G,uint B,uint Alpha);
void set_color_s(led_power lp);

#endif // PWM_H_INCLUDED
