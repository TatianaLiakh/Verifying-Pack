/* Process-Images functions prototypes */
#ifndef _bsvtproc_h
#define _bsvtproc_h 1

void P0(void);  /* Process Инициализация */
void P1(void);  /* Process КонтрольДостоверностиОткрытияЗатвораВакуумного */
void P2(void);  /* Process КонтрольДостоверностиОткрЗатВакуумного */
void P3(void);  /* Process КонтрольДостоверностиЗакрЗатВакуумного */
void P4(void);  /* Process КонтрольДостоверностиСостоянияСапуна */
void P5(void);  /* Process КонтрольДостоверностиСостоянияУстройстваПлавПуска */
void P6(void);  /* Process КонтрольДостоверностиСостоянияПитанияВакуумногоНасоса */
void P7(void);  /* Process КонтрольДостоверностиСостоянияПитанияВентилятора */
void P8(void);  /* Process ЧтениеФактПараметров_с_Датчиков */
void P9(void);  /* Process РЕГУЛЯТОР_ТРАФИКА */
void P10(void);  /* Process ЧтениеКольцевогоБуфера */
void P11(void);  /* Process ОбработкаКомандИзмененияНП_от_ГУИ */
void P12(void);  /* Process ОбработкаКомандУправления_от_ГУИ */
void P13(void);  /* Process КонтрольИзменения_ФП_P_ВбакеКомпрессора */
void P14(void);  /* Process КонтрольИзменения_ФП_P_Впатрубке */
void P15(void);  /* Process КонтрольИзменения_ФП_T_Врубашке */
void P16(void);  /* Process КонтрольИзменения_ФП_T_Вбаке */
void P17(void);  /* Process КонтрольИзменения_ФП_P_ВтрубеСидер */
void P18(void);  /* Process КонтрольОткачкиВауумнойТрубыСидеростата */
void P19(void);  /* Process КонтрольГотовностиВакуума_в_Вакуумной_Трубе */
void P20(void);  /* Process КонтрольУровняВодыБакаОхлаждения */
void P21(void);  /* Process КонтрольТемпературыВодыБакаОхлаждения */
void P22(void);  /* Process КонтрольТемпературыРубашкиОхлаждения */
void P23(void);  /* Process КонтрольДавленияВбакеКомпрессора */
void P24(void);  /* Process ВКЛ_ПИТ_ВЕНТИЛЯТОР */
void P25(void);  /* Process ВЫК_ПИТ_ВЕНТИЛЯТОР */
void P26(void);  /* Process КонтрольСпонтанногоВыключенияВентилятора */
void P27(void);  /* Process КонтрольСпонтанногоВключенияВентилятора */
void P28(void);  /* Process ОТКР_ЗАТВОР_ВАК */
void P29(void);  /* Process ЗАКР_ЗАТВОР_ВАК */
void P30(void);  /* Process КонтрольСпонтанногоЗакрытияЗатвораВакуумного */
void P31(void);  /* Process КонтрольСпонтанногоОткрытияЗатвораВакуумного */
void P32(void);  /* Process ОТКР_САПУН */
void P33(void);  /* Process ЗАКР_САПУН */
void P34(void);  /* Process КонтрольСпонтанногоЗакрытияСапуна */
void P35(void);  /* Process КонтрольСпонтанногоОткрытияСапуна */
void P36(void);  /* Process ВКЛ_ПИТ_ВАК_НАСОСА */
void P37(void);  /* Process ВЫК_ПИТ_ВАК_НАСОСА */
void P38(void);  /* Process КонтрольСпонтанногоВыключенияВакНасоса */
void P39(void);  /* Process КонтрольСпонтанногоВключенияВакНасоса */
void P40(void);  /* Process ВКЛ_ПИТ_РЕГ_Т */
void P41(void);  /* Process ВЫК_ПИТ_РЕГ_Т */
void P42(void);  /* Process КонтрольСпонтанногоВыключенияРЕГ_Т */
void P43(void);  /* Process КонтрольСпонтанногоВключенияРЕГ_Т */
void P44(void);  /* Process ВКЛ_ПИТ_РЕГ_УР */
void P45(void);  /* Process ВЫК_ПИТ_РЕГ_УР */
void P46(void);  /* Process КонтрольСпонтанногоВыключенияРЕГ_УР */
void P47(void);  /* Process КонтрольСпонтанногоВключенияРЕГ_УР */
void P48(void);  /* Process ВКЛ_ПИТ_НАС_ОХЛ */
void P49(void);  /* Process ВЫК_ПИТ_НАС_ОХЛ */
void P50(void);  /* Process КонтрольСпонтанногоВыключенияНасосаОхлаждения */
void P51(void);  /* Process КонтрольСпонтанногоВключенияНасосаОхлаждения */
void P52(void);  /* Process ВКЛ_УСТР_ПЛАВ_ПУСКА */
void P53(void);  /* Process ВЫК_УСТР_ПЛАВ_ПУСКА */
void P54(void);  /* Process КонтрольСпонтанногоВыключенияПлавнПуска */
void P55(void);  /* Process КонтрольСпонтанногоВключенияПлавнПуска */
void P56(void);  /* Process ВКЛ_ВАКУУМНУЮ_ПОДСИСТЕМУ */
void P57(void);  /* Process ВЫК_ВАКУУМНУЮ_ПОДСИСТЕМУ */
void P58(void);  /* Process ВКЛ_ВАКУУМИРОВАНИЕ_ТРУБЫ */
void P59(void);  /* Process ВЫК_ВАКУУМИРОВАНИЕ_ТРУБЫ */

#define PROCESS_N1 0
#define PROCESS_Nn 59 /* Number Of Proc */

#endif