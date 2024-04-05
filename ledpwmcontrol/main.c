#define  F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define LED_TIME 20

void turn_on_LED_in_PWM_manner(int dim)
{
    int i;
    
    PORTB = 0xFF; //LED 켜기
    
    for(i=0; i<256; i++){
        if(i>dim) PORTB = 0x00;
        _delay_us(LED_TIME);
        
    }
    
}

int main(void)
{
    /* Replace with your application code */
    DDRB = 0xFF; //PB5 핀(아두이노13핀)을 출력으로 설정
    
    int dim =0;  //현재 led 밝기
    int direction = 1; //밝기 증가(1) 또는 감소(-1)
    
    
    while (1) 
    {
        if(dim==0) direction =1;
        if(dim==255) direction=-1;
        
        dim += direction; //밝기 변화
        
        turn_on_LED_in_PWM_manner(dim);
        
    }
}
