/* MAIN FILE OF THE PROJECT */
#include "canonext.h" /* Common files for all generated c-files */
#include "canonproc.h"  /* Process-functions desription */
#include "canongvar.h"  /* Project variables images */
#include "canonio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* Управляющий алгоритм */
{
	Input();
	P0();  /* Process Инициализация */
	P1();  /* Process Режим_ИНИЦИАЛИЗАЦИЯ */
	P2();  /* Process КонтрольРежимов */
	P3();  /* Process Режим_РР */
	P4();  /* Process ОбработкаКомандОтГИО */
	P5();  /* Process КонтрольИзмененияЗаданий_ЗД_R_КАРЕТКИ */
	P6();  /* Process КонтрольИзмененияЗаданий_ЗД_W_ПРЕДМЕТНОГО_СТОЛИКА */
	P7();  /* Process КонтрольИзменения_ФП_R_КАРЕТКИ */
	P8();  /* Process КонтрольИзменения_ФП_W_ПРЕДМЕТНОГО_СТОЛИКА */
	P9();  /* Process ВКЛ_ВОЗД_ПОДУШКУ */
	P10();  /* Process ПроверкаИсправностиВоздушнойПодушки */
	P11();  /* Process ВКЛ_НАСОС */
	P12();  /* Process ЗАЖАТЬ_ДИСК */
	P13();  /* Process РАЗЖАТЬ_ДИСК */
	P14();  /* Process ИНИЦИАЛИЗАЦИЯ_ЛАЗЕРА */
	P15();  /* Process ВКЛ_ЛАЗЕРА */
	P16();  /* Process ВЫКЛ_ЛАЗЕРА */
	P17();  /* Process КонтрольОсвещенияДиска */
	P18();  /* Process ВКЛ_ПОДСВЕТКУ_ДИСКА */
	P19();  /* Process ВЫКЛ_ПОДСВЕТКУ_ДИСКА */
	P20();  /* Process ИНИЦИАЛИЗАЦИЯ_ПРИВОДОВ */
	P21();  /* Process КонтрольДавления */
	P22();  /* Process КонтрольАварииДавления */
	P23();  /* Process КонтрольВакуума */
	P24();  /* Process КонтрольАварииВакуума */
	P25();  /* Process КонтрольСвязи_сМОХА1212 */
	P26();  /* Process КонтрольСвязи_сМОХА1214 */
	P27();  /* Process КонтрольДистанционного1212 */
	P28();  /* Process КонтрольДистанционного1214 */
	P29();  /* Process РАЗБЛОКИРОВКА_КОМАНД_ПЕРЕМЕЩЕНИЯ */
	P30();  /* Process БЛОКИРОВКА_КОМАНД_ПЕРЕМЕЩЕНИЯ */
	P31();  /* Process ОТМЕНА */
	P32();  /* Process КОНЕЦ_РАБОТЫ */
	P33();  /* Process КАРЕТКУ_В_ЦЕНТР_ВРАЩЕНИЯ */
	P34();  /* Process КАРЕТКУ_В_ЗАДАННЫЙ_РАДИУС */
	P35();  /* Process СТОП_КАРЕТКИ */
	P36();  /* Process КАРЕТКУ_В_ПОЛОЖЕНИЕ_УСТАНОВКИ_ДИСКА */
	P37();  /* Process ВКЛ_АКТИВНОЕ_ПОЗИЦИОНИРОВАНИЕ_ПО_ВРАЩЕНИЮ */
	P38();  /* Process ВЫКЛ_АКТИВНОЕ_ПОЗИЦИОНИРОВАНИЕ_ПО_ВРАЩЕНИЮ */
	P39();  /* Process ВКЛ_ВРАЩЕНИЕ_ПРЕД_СТОЛИКА_В_ЗД_W */
	P40();  /* Process СТОП_ВРАЩЕНИЯ_ПРЕДМЕТНОГО_СТОЛИКА */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}