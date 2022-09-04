#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#pragma config FPLLIDIV = DIV_2 // 8/4 = 2
#pragma config FPLLMUL = MUL_20 //2*16 = 32
#pragma config FPLLODIV = DIV_8// 32/8 = 4

#pragma config FWDTEN = OFF // Watchdog off
#pragma config POSCMOD = HS // HS Mode

#pragma config FNOSC = PRIPLL
#pragma config FPBDIV = DIV_8

#define SYS_FREQ (4000000L) // 4MHz

int main (int argc, char *argv[]) {
    while(1){
        
    }
}