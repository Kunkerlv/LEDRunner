#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>

#pragma config FPLLIDIV = DIV_2 // 8/4 = 2
#pragma config FPLLMUL = MUL_20 //2*16 = 32
#pragma config FPLLODIV = DIV_8// 32/8 = 4

#pragma config FWDTEN = OFF // Watchdog off
#pragma config POSCMOD = HS // HS Mode

#pragma config FNOSC = PRIPLL
#pragma config FPBDIV = DIV_8

#define SYS_FREQ (4000000L) // 4MHz

uint8_t TickTock = 0;
int8_t LEDnum = 0;
uint8_t btn = 0;

void InitTimer2(){
    __builtin_disable_interrupts();
    PR2		 = 1000; // Interrupt after 1000 cycles
    TMR2		 = 0;
    T2CONbits.TCKPS0 = 1;   // set prescaler to 256
    T2CONbits.TCKPS1 = 1;
    T2CONbits.TCKPS2 = 1; 
    T2CONbits.TGATE = 0;    // not gated input (the default)
    T2CONbits.TSIDL = 0;    // stop in idle mode off
    T2CONbits.TCS = 0;      // PCBLK input (the default)
    T2CONbits.ON = 1;       // Timer2 ON
    
    IPC2bits.T2IP = 1;               // Timer2 interrupt priority
    IPC2bits.T2IS = 0;               // Timer2 sub-priority
    IFS0bits.T2IF = 0;               // Interrupt clear
    IEC0bits.T2IE = 1;               // Interrupt EN
    INTCONbits.MVEC = 1;             //  Enable the multi vector interrupts
    __builtin_enable_interrupts();
}

void __ISR (_TIMER_2_VECTOR, IPL7SRS) Timer2Handler (void){ //Called every 0.512s
    TickTock = !TickTock;
    if(LEDnum>8){LEDnum=0;}
    if(LEDnum<-1){LEDnum=8;}
    
    if (TickTock){ // 1
        PORTD |= 1 << LEDnum;
    }
    
    
    if (!TickTock){// 2
        PORTD &= 0 << LEDnum;
        if(btn == 1){
        LEDnum++;  
        } else if (btn == 0){
        LEDnum--;
        if(LEDnum<0){LEDnum=8;}
        }
    }

    IFS0bits.T2IF = 0;// Reset Interrupt Flag
}

void LEDforward(void){
    
}

int main (int argc, char *argv[]) {
    

    TRISD = 0x200; //RD0 - RD8 = OUTPUT, RD9 = INPUT
    PORTD = 0b000000000; //RD0-RD8 OFF
    InitTimer2();
    while(1){
        if(PORTDbits.RD9 == 1){
        btn = !btn;
        }      
    }
    
}