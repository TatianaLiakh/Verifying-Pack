/* MAIN FILE OF THE PROJECT */
#include "bsvtext.inc" /* Common files for all generated c-files */
#include "bsvtproc.h"  /* Process-functions desription */
#include "bsvtgvar.h"  /* Project variables images */
#include "bsvtio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* Управляющий алгоритм */
{
	Input();
	P0();  /* Process Инициализация */
	P1();  /* Process ЧтениеФактПараметров_с_Датчиков */
	P2();  /* Process ЧтениеКольцевогоБуфера */
	P3();  /* Process ОбработкаКомандУправления_от_ГУИ */
	P4();  /* Process КонтрольИзменения_ФП_P_ВбакеКомпрессора */
	P5();  /* Process КонтрольИзменения_ФП_P_Впатрубке */
	P6();  /* Process КонтрольИзменения_ФП_T_Врубашке */
	P7();  /* Process КонтрольИзменения_ФП_T_Вбаке */
	P8();  /* Process КонтрольИзменения_ФП_P_ВтрубеСидер */
	P9();  /* Process КонтрольОткачкиВауумнойТрубыСидеростата */
	P10();  /* Process КонтрольГотовностиВакуума_в_Вакуумной_Трубе */
	P11();  /* Process КонтрольУровняВодыБакаОхлаждения */
	P12();  /* Process КонтрольТемпературыВодыБакаОхлаждения */
	P13();  /* Process КонтрольТемпературыРубашкиОхлаждения */
	P14();  /* Process КонтрольДавленияВбакеКомпрессора */
	P15();  /* Process ВКЛ_ПИТ_ВЕНТИЛЯТОР */
	P16();  /* Process ВЫК_ПИТ_ВЕНТИЛЯТОР */
	P17();  /* Process ОТКР_ЗАТВОР_ВАК */
	P18();  /* Process ЗАКР_ЗАТВОР_ВАК */
	P19();  /* Process ОТКР_САПУН */
	P20();  /* Process ЗАКР_САПУН */
	P21();  /* Process ВКЛ_ПИТ_ВАК_НАСОСА */
	P22();  /* Process ВЫК_ПИТ_ВАК_НАСОСА */
	P23();  /* Process ВКЛ_ПИТ_РЕГ_Т */
	P24();  /* Process ВЫК_ПИТ_РЕГ_Т */
	P25();  /* Process ВКЛ_ПИТ_РЕГ_УР */
	P26();  /* Process ВЫК_ПИТ_РЕГ_УР */
	P27();  /* Process ВКЛ_ПИТ_НАС_ОХЛ */
	P28();  /* Process ВЫК_ПИТ_НАС_ОХЛ */
	P29();  /* Process ВКЛ_УСТР_ПЛАВ_ПУСКА */
	P30();  /* Process ВЫК_УСТР_ПЛАВ_ПУСКА */
	P31();  /* Process ВКЛ_НАСОС_ВАКУУМНЫЙ */
	P32();  /* Process ВЫК_НАСОС_ВАКУУМНЫЙ */
	P33();  /* Process ВКЛ_ВАКУУМИРОВАНИЕ_ТРУБЫ */
	P34();  /* Process ВЫК_ВАКУУМИРОВАНИЕ_ТРУБЫ */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}