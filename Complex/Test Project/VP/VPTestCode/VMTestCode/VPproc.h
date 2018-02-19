/* Process-Images functions prototypes */
#ifndef _VPproc_h
#define _VPproc_h 1

void P0(void);  /* Process Инициализация */
void P1(void);  /* Process ИсправнаяРабота */
void P2(void);  /* Process НеисправнаяРабота */
void P3(void);  /* Process ЧтениеСценариев */
void P4(void);  /* Process ВтыкайРуки */

#define PROCESS_N1 0
#define PROCESS_Nn 4 /* Number Of Proc */

#endif