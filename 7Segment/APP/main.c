#include "../HAL/7_segment.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

int main() {
    HSSD_voidInit(0);
    HSSD_voidInit(1);
    HSSD_voidInit(2);
    HSSD_voidInit(3);

    u8 LA_hours = 0;
    u8 LA_hours2 = 0;
    u8 LA_minutes = 0;

    while(1) {
        HSSD_VoidDisplayNumber(PORTA, LA_hours);
        HSSD_VoidDisplayNumber(PORTB, LA_hours2);
        HSSD_VoidDisplayNumber(PORTC, LA_minutes / 10);
        HSSD_VoidDisplayNumber(PORTD, LA_minutes % 10);


        _delay_ms(1000);  // Delay for 1 second

        LA_minutes++;
        if (LA_minutes == 60) {
            LA_minutes = 0;
            LA_hours++;
            if (LA_hours == 10) {
                LA_hours = 0;
                LA_hours2++;
                if(LA_hours2==3){
                		LA_hours=0;
                	}

                }
            }
        if (LA_hours2 == 2 && LA_hours == 4 && LA_minutes == 0) {
                    LA_hours2 = 0;
                    LA_hours = 0;
                    LA_minutes = 0;
                }
        }


    return 0;
}
