#include <stdio.h>
#include "SCM_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("SCM_constants.cfg","w");
	i = VKL; /* C_0 - бйк */
	fputs( "бйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - бшйк */
	fputs( "бшйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VryemyaNaOtklik; /* C_2 - бПЕЛЪмЮнРЙКХЙ */
	fputs( "бПЕЛЪмЮнРЙКХЙ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_POMYESTIT__RUKI; /* ася2бнс_онлеярхрэ_псйх */
	fputs( "ася2бнс_онлеярхрэ_псйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_UBRAT__RUKI; /* ася2бнс_сапюрэ_псйх */
	fputs( "ася2бнс_сапюрэ_псйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_SLOMAT__SUSHILKU; /* ася2бнс_якнлюрэ_ясьхкйс */
	fputs( "ася2бнс_якнлюрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_SUSHILKA_RABOTAYET; /* ася2бнс_ясьхкйю_пюанрюер */
	fputs( "ася2бнс_ясьхкйю_пюанрюер = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_V_RUCHNOYE_UPRAVLYENIYE; /* йнл2юс_б_псвмне_сопюбкемхе */
	fputs( "йнл2юс_б_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* йнл2юс_нрйкчвхрэ_псвмне_сопюбкемхе */
	fputs( "йнл2юс_нрйкчвхрэ_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VKLYUCHIT__SUSHILKU; /* йнл2юс_бйкчвхрэ_ясьхкйс */
	fputs( "йнл2юс_бйкчвхрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VYKLYUCHIT__SUSHILKU; /* йнл2юс_бшйкчвхрэ_ясьхкйс */
	fputs( "йнл2юс_бшйкчвхрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE; /* ася2аб_псвмне_сопюбкемхе_бйкчвемхе */
	fputs( "ася2аб_псвмне_сопюбкемхе_бйкчвемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE; /* ася2аб_псвмне_сопюбкемхе_бшйкчвемхе */
	fputs( "ася2аб_псвмне_сопюбкемхе_бшйкчвемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY; /* ася2аб_юбрнлюрхвеяйне_сопюбкемхе_псйх_онлеыемш */
	fputs( "ася2аб_юбрнлюрхвеяйне_сопюбкемхе_псйх_онлеыемш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY; /* ася2аб_юбрнлюрхвеяйне_сопюбкемхе_псйх_сапюмш */
	fputs( "ася2аб_юбрнлюрхвеяйне_сопюбкемхе_псйх_сапюмш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_KONYETS_SHTANOGO_RYEZHIMA; /* ася2аб_йнмеж_ьрюмнцн_пефхлю */
	fputs( "ася2аб_йнмеж_ьрюмнцн_пефхлю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_Dlya_provyerki; /* ася2аб_дКЪ_ОПНБЕПЙХ */
	fputs( "ася2аб_дКЪ_ОПНБЕПЙХ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE; /* ася2аб_мехяопюбмнярэ_псвмне_сопюбкемхе_бйкчвемхе */
	fputs( "ася2аб_мехяопюбмнярэ_псвмне_сопюбкемхе_бйкчвемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE; /* ася2аб_мехяопюбмнярэ_псвмне_сопюбкемхе_бшйкчвемхе */
	fputs( "ася2аб_мехяопюбмнярэ_псвмне_сопюбкемхе_бшйкчвемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY; /* ася2аб_мехяопюбмнярэ_юбрнлюрхвеяйне_сопюбкемхе_псйх_онлеыемш */
	fputs( "ася2аб_мехяопюбмнярэ_юбрнлюрхвеяйне_сопюбкемхе_псйх_онлеыемш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RU; /* ася2аб_мехяопюбмнярэ_мехяопюбмнярэ_юбрнлюрхвеяйне_сопюбкемхе_пс */
	fputs( "ася2аб_мехяопюбмнярэ_мехяопюбмнярэ_юбрнлюрхвеяйне_сопюбкемхе_пс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2BUS_SLYEDUYUSCHIJ_STSYENARIJ; /* аб2ася_якедсчыхи_яжемюпхи */
	fputs( "аб2ася_якедсчыхи_яжемюпхи = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2BUS_OSHIBKA_OSTANOV; /* аб2ася_ньхайю_нярюмнб */
	fputs( "аб2ася_ньхайю_нярюмнб = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
