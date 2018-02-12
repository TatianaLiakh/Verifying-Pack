
#define VKL /* C_0 - ВКЛ */ 1
#define VYKL /* C_1 - ВЫКЛ */ 0
#define OzhidaniyeOtvyetaOtAlgoritma /* C_2 - ОжиданиеОтветаОтАлгоритма */ 10
#define ZadyerzhkaOb_yekta /* C_3 - ЗадержкаОбъекта */ 10

enum EN0 {
	AU2GUI_V_RUCHNOYE_UPRAVLYENIYE /* АУ2ГУИ_В_РУЧНОЕ_УПРАВЛЕНИЕ */,
	AU2GUI_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE /* АУ2ГУИ_ОТКЛЮЧИТЬ_РУЧНОЕ_УПРАВЛЕНИЕ */,
	AU2GUI_VKLYUCHIT__SUSHILKU /* АУ2ГУИ_ВКЛЮЧИТЬ_СУШИЛКУ */,
	AU2GUI_VYKLYUCHIT__SUSHILKU /* АУ2ГУИ_ВЫКЛЮЧИТЬ_СУШИЛКУ */

};

enum EN1 {
	KOM2AU_YEST__SUSHILKA_V_RUCHNOYE_UPRAVLYENIYE /* КОМ2АУ_ЕСТЬ_СУШИЛКА_В_РУЧНОЕ_УПРАВЛЕНИЕ */,
	KOM2AU_YEST__OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE /* КОМ2АУ_ЕСТЬ_ОТКЛЮЧИТЬ_РУЧНОЕ_УПРАВЛЕНИЕ */,
	KOM2AU_SUSHILKA_VYKLYUCHYENA /* КОМ2АУ_СУШИЛКА_ВЫКЛЮЧЕНА */,
	KOM2AU_SUSHILKA_VKLYUCHYENA /* КОМ2АУ_СУШИЛКА_ВКЛЮЧЕНА */

};

 
 enum EN2 {
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE /* БУС2БВ_РУЧНОЕ_УПРАВЛЕНИЕ_ВКЛЮЧЕНИЕ */,
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE /* БУС2БВ_РУЧНОЕ_УПРАВЛЕНИЕ_ВЫКЛЮЧЕНИЕ */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY /* БУС2БВ_АВТОМАТИЧЕСКОЕ_УПРАВЛЕНИЕ_РУКИ_ПОМЕЩЕНЫ */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY /* БУС2БВ_АВТОМАТИЧЕСКОЕ_УПРАВЛЕНИЕ_РУКИ_УБРАНЫ */,
	BUS2BV_KONYETS_SHTANOGO_RYEZHIMA /* БУС2БВ_КОНЕЦ_ШТАНОГО_РЕЖИМА */	
	
};

enum EN3 {
	BV2BUS_SLYEDUYUSCHIJ_STSYENARIJ /* БВ2БУС_СЛЕДУЮЩИЙ_СЦЕНАРИЙ */,
	BV2BUS_OSHIBKA_OSTANOV /* БВ2БУС_ОШИБКА_ОСТАНОВ */

};

enum EN4 {
	BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno /* БВ2ГОО_ВключениеРучногоУправленияУспешно */,
	BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno /* БВ2ГОО_ВыключениеРучногоУправленияУспешно */,
	BV2GOO_VklyuchyeniyeAvtomatichyeskoyeUspyeshno /* БВ2ГОО_ВключениеАвтоматическоеУспешно */,
	BV2GOO_VyklyuchyeniyeAvtomatichyeskoyeUspyeshno /* БВ2ГОО_ВыключениеАвтоматическоеУспешно */,
	BV2GOO_ /* БВ2ГОО_ */

};

enum EN5 {
	BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno /* БВ2ГОО_ВключениеРучногоУправленияНЕУспешно */ = BV2GOO_ + 1,
	BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno /* БВ2ГОО_ВыключениеРучногоУправленияНЕУспешно */,
	BV2GOO_Samoproizvol_noyeOtklyuchyeniyeRyezhimaRuchnogoUpravlyeniya /* БВ2ГОО_СамопроизвольноеОтключениеРежимаРучногоУправления */,
	BV2GOO_Samoproizvol_noyeVklyuchyeniyeRyezhimaRuchnogoUpravlyeniya /* БВ2ГОО_СамопроизвольноеВключениеРежимаРучногоУправления */,
	BV2GOO_OSHIBKA_Samoproizvol_noyeVyklyuchyeniyeVavtomatRyezhimye /* БВ2ГОО_ОШИБКА_СамопроизвольноеВыключениеВавтоматРежиме */,
	BV2GOO_OSHIBKA_Samoproizvol_noyeVklyuchyeniyeVavtomatRyezhimye /* БВ2ГОО_ОШИБКА_СамопроизвольноеВключениеВавтоматРежиме */

};