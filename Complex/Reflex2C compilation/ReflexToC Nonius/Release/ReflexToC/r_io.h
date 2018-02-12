#ifndef _R_IO_H
#define _R_IO_H 1
#include "R_CNST.H"
/**********************************************
 * Структура для безопасной
 * передачи слова для 8-ми
 * разрядной системной магистрали 
 **********************************************/

struct Word {
    INT8U  Channel; /* номер действительного канала */
    INT16U Value0;  /* канал N 0 */
    INT16U Value1;  /* канал N 1 */
};

/*********************************************
 * Структура для безопасной
 * передачи двойного слова для 8-ми
 * и 16-ти разрядной системной магистрали 
 *********************************************/

struct DWord{
    INT8U  Channel; /* номер действительного канала */
    INT32U Value0;  /* канал N 0 */
    INT32U Value1;  /* канал N 1 */
};

char * aInput;
char * aOutput;

int input_counter;
int output_counter;

unsigned char INBYTE(unsigned int, unsigned int);         /* считывание байта из UNIO */
unsigned int  OUTBYTE(unsigned int, unsigned int, unsigned char); /* запись байта в UNIO */

/* signed int  INWORD(INT16U, void far *);
 signed long INDWORD(INT16U, void far *);
*/

#endif
