#include <stdio.h>
#include "VM_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("VM_constants.cfg","w");
	i = VKL; /* C_0 - ВКЛ */
	fputs( "ВКЛ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - ВЫКЛ */
	fputs( "ВЫКЛ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OzhidaniyeOtvyetaOtAlgoritma; /* C_2 - ОжиданиеОтветаОтАлгоритма */
	fputs( "ОжиданиеОтветаОтАлгоритма = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZadyerzhkaOb_yekta; /* C_3 - ЗадержкаОбъекта */
	fputs( "ЗадержкаОбъекта = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_V_RUCHNOYE_UPRAVLYENIYE; /* КОМ2АУ_В_РУЧНОЕ_УПРАВЛЕНИЕ */
	fputs( "КОМ2АУ_В_РУЧНОЕ_УПРАВЛЕНИЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* КОМ2АУ_ОТКЛЮЧИТЬ_РУЧНОЕ_УПРАВЛЕНИЕ */
	fputs( "КОМ2АУ_ОТКЛЮЧИТЬ_РУЧНОЕ_УПРАВЛЕНИЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VKLYUCHIT__SUSHILKU; /* КОМ2АУ_ВКЛЮЧИТЬ_СУШИЛКУ */
	fputs( "КОМ2АУ_ВКЛЮЧИТЬ_СУШИЛКУ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VYKLYUCHIT__SUSHILKU; /* КОМ2АУ_ВЫКЛЮЧИТЬ_СУШИЛКУ */
	fputs( "КОМ2АУ_ВЫКЛЮЧИТЬ_СУШИЛКУ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_YEST__SUSHILKA_V_RUCHNOYE_UPRAVLYENIYE; /* АУ2ГУИ_ЕСТЬ_СУШИЛКА_В_РУЧНОЕ_УПРАВЛЕНИЕ */
	fputs( "АУ2ГУИ_ЕСТЬ_СУШИЛКА_В_РУЧНОЕ_УПРАВЛЕНИЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_YEST__OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* АУ2ГУИ_ЕСТЬ_ОТКЛЮЧИТЬ_РУЧНОЕ_УПРАВЛЕНИЕ */
	fputs( "АУ2ГУИ_ЕСТЬ_ОТКЛЮЧИТЬ_РУЧНОЕ_УПРАВЛЕНИЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_SUSHILKA_VYKLYUCHYENA; /* АУ2ГУИ_СУШИЛКА_ВЫКЛЮЧЕНА */
	fputs( "АУ2ГУИ_СУШИЛКА_ВЫКЛЮЧЕНА = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_SUSHILKA_VKLYUCHYENA; /* АУ2ГУИ_СУШИЛКА_ВКЛЮЧЕНА */
	fputs( "АУ2ГУИ_СУШИЛКА_ВКЛЮЧЕНА = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE; /* БУС2БВ_РУЧНОЕ_УПРАВЛЕНИЕ_ВКЛЮЧЕНИЕ */
	fputs( "БУС2БВ_РУЧНОЕ_УПРАВЛЕНИЕ_ВКЛЮЧЕНИЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE; /* БУС2БВ_РУЧНОЕ_УПРАВЛЕНИЕ_ВЫКЛЮЧЕНИЕ */
	fputs( "БУС2БВ_РУЧНОЕ_УПРАВЛЕНИЕ_ВЫКЛЮЧЕНИЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY; /* БУС2БВ_АВТОМАТИЧЕСКОЕ_УПРАВЛЕНИЕ_РУКИ_ПОМЕЩЕНЫ */
	fputs( "БУС2БВ_АВТОМАТИЧЕСКОЕ_УПРАВЛЕНИЕ_РУКИ_ПОМЕЩЕНЫ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY; /* БУС2БВ_АВТОМАТИЧЕСКОЕ_УПРАВЛЕНИЕ_РУКИ_УБРАНЫ */
	fputs( "БУС2БВ_АВТОМАТИЧЕСКОЕ_УПРАВЛЕНИЕ_РУКИ_УБРАНЫ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_KONYETS_SHTANOGO_RYEZHIMA; /* БУС2БВ_КОНЕЦ_ШТАНОГО_РЕЖИМА */
	fputs( "БУС2БВ_КОНЕЦ_ШТАНОГО_РЕЖИМА = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2BUS_SLYEDUYUSCHIJ_STSYENARIJ; /* БВ2БУС_СЛЕДУЮЩИЙ_СЦЕНАРИЙ */
	fputs( "БВ2БУС_СЛЕДУЮЩИЙ_СЦЕНАРИЙ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2BUS_OSHIBKA_OSTANOV; /* БВ2БУС_ОШИБКА_ОСТАНОВ */
	fputs( "БВ2БУС_ОШИБКА_ОСТАНОВ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno; /* БВ2ГОО_ВключениеРучногоУправленияУспешно */
	fputs( "БВ2ГОО_ВключениеРучногоУправленияУспешно = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno; /* БВ2ГОО_ВыключениеРучногоУправленияУспешно */
	fputs( "БВ2ГОО_ВыключениеРучногоУправленияУспешно = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VklyuchyeniyeAvtomatichyeskoyeUspyeshno; /* БВ2ГОО_ВключениеАвтоматическоеУспешно */
	fputs( "БВ2ГОО_ВключениеАвтоматическоеУспешно = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VyklyuchyeniyeAvtomatichyeskoyeUspyeshno; /* БВ2ГОО_ВыключениеАвтоматическоеУспешно */
	fputs( "БВ2ГОО_ВыключениеАвтоматическоеУспешно = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_; /* БВ2ГОО_ */
	fputs( "БВ2ГОО_ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno; /* БВ2ГОО_ВключениеРучногоУправленияНЕУспешно */
	fputs( "БВ2ГОО_ВключениеРучногоУправленияНЕУспешно = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno; /* БВ2ГОО_ВыключениеРучногоУправленияНЕУспешно */
	fputs( "БВ2ГОО_ВыключениеРучногоУправленияНЕУспешно = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_Samoproizvol_noyeOtklyuchyeniyeRyezhimaRuchnogoUpravlyeniya; /* БВ2ГОО_СамопроизвольноеОтключениеРежимаРучногоУправления */
	fputs( "БВ2ГОО_СамопроизвольноеОтключениеРежимаРучногоУправления = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_Samoproizvol_noyeVklyuchyeniyeRyezhimaRuchnogoUpravlyeniya; /* БВ2ГОО_СамопроизвольноеВключениеРежимаРучногоУправления */
	fputs( "БВ2ГОО_СамопроизвольноеВключениеРежимаРучногоУправления = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_OSHIBKA_Samoproizvol_noyeVyklyuchyeniyeVavtomatRyezhimye; /* БВ2ГОО_ОШИБКА_СамопроизвольноеВыключениеВавтоматРежиме */
	fputs( "БВ2ГОО_ОШИБКА_СамопроизвольноеВыключениеВавтоматРежиме = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_OSHIBKA_Samoproizvol_noyeVklyuchyeniyeVavtomatRyezhimye; /* БВ2ГОО_ОШИБКА_СамопроизвольноеВключениеВавтоматРежиме */
	fputs( "БВ2ГОО_ОШИБКА_СамопроизвольноеВключениеВавтоматРежиме = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
