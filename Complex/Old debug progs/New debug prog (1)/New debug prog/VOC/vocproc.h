/* Process-Images functions prototypes */
#ifndef _vocproc_h
#define _vocproc_h 1

void P0(void);  /* Process Инициализация */
void P1(void);  /* Process ЧтениеКольцевогоБуфера */
void P2(void);  /* Process КОНТРОЛЬ_ДАВЛЕНИЯ_ВОЗД_ПОДУШКИ */
void P3(void);  /* Process КонтрольПодачиВоздухаНаОпору */
void P4(void);  /* Process ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ОПОРУ */
void P5(void);  /* Process ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ОПОРУ */
void P6(void);  /* Process КонтрольПодачиВоздухаНаКаретку */
void P7(void);  /* Process ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_КАРЕТКУ */
void P8(void);  /* Process ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_КАРЕТКУ */
void P9(void);  /* Process КонтрольПодачиВоздухаНаШпиндель */
void P10(void);  /* Process ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ШПИНДЕЛЬ */
void P11(void);  /* Process ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ШПИНДЕЛЬ */
void P12(void);  /* Process УправлениеПитаниемЛазера */
void P13(void);  /* Process УПРАВЛЕНИЕ_СВЕТОДИОДОМ */
void P14(void);  /* Process УПРАВЛЕНИЕ_НАСОСОМ */
void P15(void);  /* Process КонтрольКлапанаАтмосферы */
void P16(void);  /* Process ОТКРЫТИЕ_КЛАПАНА_АТМОСФЕРЫ */
void P17(void);  /* Process ЗАКРЫТИЕ_КЛАПАНА_АТМОСФЕРЫ */
void P18(void);  /* Process КонтрольРазжатияЗажатияДиска */
void P19(void);  /* Process КонтрольКлапанаВакуума */
void P20(void);  /* Process ОТКРЫТИЕ_КЛАПАНА_ВАКУУМА */
void P21(void);  /* Process ЗАКРЫТИЕ_КЛАПАНА_ВАКУУМА */

#define PROCESS_N1 0
#define PROCESS_Nn 21 /* Number Of Proc */

#endif