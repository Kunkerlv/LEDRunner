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

void __ISR (_TIMER_2_VECTOR, IPL7SRS) Timer2Handler (void){ //Periods 0.512s


    IFS0bits.T2IF = 0;// Reset Interrupt Flag
}

int main (int argc, char *argv[]) {
    InitTimer2();

    TRISD = 0x0000; //D All Outputs
    PORTD = 0x0000; //D All OFF

    while(1){
        
    }
}