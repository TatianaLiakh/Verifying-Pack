/* Process-Images functions prototypes */
#ifndef _canonproc_h
#define _canonproc_h 1

void P0(void);  /* Process Инициализация */
void P1(void);  /* Process Режим_ИНИЦИАЛИЗАЦИЯ */
void P2(void);  /* Process КонтрольРежимов */
void P3(void);  /* Process Режим_РР */
void P4(void);  /* Process ОбработкаКомандОтГИО */
void P5(void);  /* Process КонтрольИзмененияЗаданий_ЗД_R_КАРЕТКИ */
void P6(void);  /* Process КонтрольИзмененияЗаданий_ЗД_W_ПРЕДМЕТНОГО_СТОЛИКА */
void P7(void);  /* Process КонтрольИзменения_ФП_R_КАРЕТКИ */
void P8(void);  /* Process КонтрольИзменения_ФП_W_ПРЕДМЕТНОГО_СТОЛИКА */
void P9(void);  /* Process ВКЛ_ВОЗД_ПОДУШКУ */
void P10(void);  /* Process ПроверкаИсправностиВоздушнойПодушки */
void P11(void);  /* Process ВКЛ_НАСОС */
void P12(void);  /* Process ЗАЖАТЬ_ДИСК */
void P13(void);  /* Process РАЗЖАТЬ_ДИСК */
void P14(void);  /* Process ИНИЦИАЛИЗАЦИЯ_ЛАЗЕРА */
void P15(void);  /* Process ВКЛ_ЛАЗЕРА */
void P16(void);  /* Process ВЫКЛ_ЛАЗЕРА */
void P17(void);  /* Process КонтрольОсвещенияДиска */
void P18(void);  /* Process ВКЛ_ПОДСВЕТКУ_ДИСКА */
void P19(void);  /* Process ВЫКЛ_ПОДСВЕТКУ_ДИСКА */
void P20(void);  /* Process ИНИЦИАЛИЗАЦИЯ_ПРИВОДОВ */
void P21(void);  /* Process КонтрольДавления */
void P22(void);  /* Process КонтрольАварииДавления */
void P23(void);  /* Process КонтрольВакуума */
void P24(void);  /* Process КонтрольАварииВакуума */
void P25(void);  /* Process КонтрольСвязи_сМОХА1212 */
void P26(void);  /* Process КонтрольСвязи_сМОХА1214 */
void P27(void);  /* Process КонтрольДистанционного1212 */
void P28(void);  /* Process КонтрольДистанционного1214 */
void P29(void);  /* Process РАЗБЛОКИРОВКА_КОМАНД_ПЕРЕМЕЩЕНИЯ */
void P30(void);  /* Process БЛОКИРОВКА_КОМАНД_ПЕРЕМЕЩЕНИЯ */
void P31(void);  /* Process ОТМЕНА */
void P32(void);  /* Process КОНЕЦ_РАБОТЫ */
void P33(void);  /* Process КАРЕТКУ_В_ЦЕНТР_ВРАЩЕНИЯ */
void P34(void);  /* Process КАРЕТКУ_В_ЗАДАННЫЙ_РАДИУС */
void P35(void);  /* Process СТОП_КАРЕТКИ */
void P36(void);  /* Process КАРЕТКУ_В_ПОЛОЖЕНИЕ_УСТАНОВКИ_ДИСКА */
void P37(void);  /* Process ВКЛ_АКТИВНОЕ_ПОЗИЦИОНИРОВАНИЕ_ПО_ВРАЩЕНИЮ */
void P38(void);  /* Process ВЫКЛ_АКТИВНОЕ_ПОЗИЦИОНИРОВАНИЕ_ПО_ВРАЩЕНИЮ */
void P39(void);  /* Process ВКЛ_ВРАЩЕНИЕ_ПРЕД_СТОЛИКА_В_ЗД_W */
void P40(void);  /* Process СТОП_ВРАЩЕНИЯ_ПРЕДМЕТНОГО_СТОЛИКА */

#define PROCESS_N1 0
#define PROCESS_Nn 40 /* Number Of Proc */

#endif