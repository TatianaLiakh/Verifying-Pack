
#define VKL /* C_0 - бйк */                1
#define VYKL /* C_1 - бшйк */               0
#define VryemyaNaOtklik /* C_2 - бПЕЛЪмЮнРЙКХЙ */		1000

 

 enum EN0 {
	BUS2VOU_POMYESTIT__RUKI /* ася2бнс_онлеярхрэ_псйх */,
	BUS2VOU_UBRAT__RUKI /* ася2бнс_сапюрэ_псйх */,
	BUS2VOU_SLOMAT__SUSHILKU /* ася2бнс_якнлюрэ_ясьхкйс */,
	BUS2VOU_SUSHILKA_RABOTAYET /* ася2бнс_ясьхкйю_пюанрюер */
 
 };
 
 
enum EN1 {
	KOM2AU_V_RUCHNOYE_UPRAVLYENIYE /* йнл2юс_б_псвмне_сопюбкемхе */,
	KOM2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE /* йнл2юс_нрйкчвхрэ_псвмне_сопюбкемхе */,
	KOM2AU_VKLYUCHIT__SUSHILKU /* йнл2юс_бйкчвхрэ_ясьхкйс */,
	KOM2AU_VYKLYUCHIT__SUSHILKU /* йнл2юс_бшйкчвхрэ_ясьхкйс */

};

 
  enum EN2 {
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE /* ася2аб_псвмне_сопюбкемхе_бйкчвемхе */,
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE /* ася2аб_псвмне_сопюбкемхе_бшйкчвемхе */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY /* ася2аб_юбрнлюрхвеяйне_сопюбкемхе_псйх_онлеыемш */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY /* ася2аб_юбрнлюрхвеяйне_сопюбкемхе_псйх_сапюмш */,
	BUS2BV_KONYETS_SHTANOGO_RYEZHIMA /* ася2аб_йнмеж_ьрюмнцн_пефхлю */,
	BUS2BV_Dlya_provyerki /* ася2аб_дКЪ_ОПНБЕПЙХ */

};

enum EN3 {
	BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE /* ася2аб_мехяопюбмнярэ_псвмне_сопюбкемхе_бйкчвемхе */ = BUS2BV_KONYETS_SHTANOGO_RYEZHIMA + 1,
	BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE /* ася2аб_мехяопюбмнярэ_псвмне_сопюбкемхе_бшйкчвемхе */,
	BUS2BV_NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY /* ася2аб_мехяопюбмнярэ_юбрнлюрхвеяйне_сопюбкемхе_псйх_онлеыемш */,
	BUS2BV_NYEISPRAVNOST__NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RU /* ася2аб_мехяопюбмнярэ_мехяопюбмнярэ_юбрнлюрхвеяйне_сопюбкемхе_пс */

};
enum EN4 {
	BV2BUS_SLYEDUYUSCHIJ_STSYENARIJ /* аб2ася_якедсчыхи_яжемюпхи */,
	BV2BUS_OSHIBKA_OSTANOV /* аб2ася_ньхайю_нярюмнб */

};