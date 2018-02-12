/* Process-Images functions prototypes */
#ifndef _bsvtproc_h
#define _bsvtproc_h 1

void P0(void);  /* Process Инициализация */
void P1(void);  /* Process ЧтениеФактПараметров_с_Датчиков */
void P2(void);  /* Process ЧтениеКольцевогоБуфера */
void P3(void);  /* Process ОбработкаКомандУправления_от_ГУИ */
void P4(void);  /* Process КонтрольИзменения_ФП_P_ВбакеКомпрессора */
void P5(void);  /* Process КонтрольИзменения_ФП_P_Впатрубке */
void P6(void);  /* Process КонтрольИзменения_ФП_T_Врубашке */
void P7(void);  /* Process КонтрольИзменения_ФП_T_Вбаке */
void P8(void);  /* Process КонтрольИзменения_ФП_P_ВтрубеСидер */
void P9(void);  /* Process КонтрольОткачкиВауумнойТрубыСидеростата */
void P10(void);  /* Process КонтрольГотовностиВакуума_в_Вакуумной_Трубе */
void P11(void);  /* Process КонтрольУровняВодыБакаОхлаждения */
void P12(void);  /* Process КонтрольТемпературыВодыБакаОхлаждения */
void P13(void);  /* Process КонтрольТемпературыРубашкиОхлаждения */
void P14(void);  /* Process КонтрольДавленияВбакеКомпрессора */
void P15(void);  /* Process ВКЛ_ПИТ_ВЕНТИЛЯТОР */
void P16(void);  /* Process ВЫК_ПИТ_ВЕНТИЛЯТОР */
void P17(void);  /* Process ОТКР_ЗАТВОР_ВАК */
void P18(void);  /* Process ЗАКР_ЗАТВОР_ВАК */
void P19(void);  /* Process ОТКР_САПУН */
void P20(void);  /* Process ЗАКР_САПУН */
void P21(void);  /* Process ВКЛ_ПИТ_ВАК_НАСОСА */
void P22(void);  /* Process ВЫК_ПИТ_ВАК_НАСОСА */
void P23(void);  /* Process ВКЛ_ПИТ_РЕГ_Т */
void P24(void);  /* Process ВЫК_ПИТ_РЕГ_Т */
void P25(void);  /* Process ВКЛ_ПИТ_РЕГ_УР */
void P26(void);  /* Process ВЫК_ПИТ_РЕГ_УР */
void P27(void);  /* Process ВКЛ_ПИТ_НАС_ОХЛ */
void P28(void);  /* Process ВЫК_ПИТ_НАС_ОХЛ */
void P29(void);  /* Process ВКЛ_УСТР_ПЛАВ_ПУСКА */
void P30(void);  /* Process ВЫК_УСТР_ПЛАВ_ПУСКА */
void P31(void);  /* Process ВКЛ_НАСОС_ВАКУУМНЫЙ */
void P32(void);  /* Process ВЫК_НАСОС_ВАКУУМНЫЙ */
void P33(void);  /* Process ВКЛ_ВАКУУМИРОВАНИЕ_ТРУБЫ */
void P34(void);  /* Process ВЫК_ВАКУУМИРОВАНИЕ_ТРУБЫ */

#define PROCESS_N1 0
#define PROCESS_Nn 34 /* Number Of Proc */

#endif