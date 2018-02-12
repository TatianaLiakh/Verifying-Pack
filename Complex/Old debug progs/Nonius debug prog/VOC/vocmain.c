/* MAIN FILE OF THE PROJECT */
#include "vocext.h" /* Common files for all generated c-files */
#include "vocproc.h"  /* Process-functions desription */
#include "vocgvar.h"  /* Project variables images */
#include "vocio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* Управляющий алгоритм */
{
	Input();
	P0();  /* Process Инициализация */
	P1();  /* Process ЧтениеКольцевогоБуфера */
	P2();  /* Process КОНТРОЛЬ_ДАВЛЕНИЯ_ВОЗД_ПОДУШКИ */
	P3();  /* Process КонтрольПодачиВоздухаНаОпору */
	P4();  /* Process ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ОПОРУ */
	P5();  /* Process ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ОПОРУ */
	P6();  /* Process КонтрольПодачиВоздухаНаКаретку */
	P7();  /* Process ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_КАРЕТКУ */
	P8();  /* Process ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_КАРЕТКУ */
	P9();  /* Process КонтрольПодачиВоздухаНаШпиндель */
	P10();  /* Process ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ШПИНДЕЛЬ */
	P11();  /* Process ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ШПИНДЕЛЬ */
	P12();  /* Process УправлениеПитаниемЛазера */
	P13();  /* Process УПРАВЛЕНИЕ_СВЕТОДИОДОМ */
	P14();  /* Process УПРАВЛЕНИЕ_НАСОСОМ */
	P15();  /* Process КонтрольКлапанаАтмосферы */
	P16();  /* Process ОТКРЫТИЕ_КЛАПАНА_АТМОСФЕРЫ */
	P17();  /* Process ЗАКРЫТИЕ_КЛАПАНА_АТМОСФЕРЫ */
	P18();  /* Process КонтрольРазжатияЗажатияДиска */
	P19();  /* Process КонтрольКлапанаВакуума */
	P20();  /* Process ОТКРЫТИЕ_КЛАПАНА_ВАКУУМА */
	P21();  /* Process ЗАКРЫТИЕ_КЛАПАНА_ВАКУУМА */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}