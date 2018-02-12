#include <stdio.h>
#include "bsvt_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 1024];
	file = fopen("bsvt_cnfg.cnfg","w");
	i = T0_1; /* C_0 - р0_1 */
	fputs( "р0_1 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ODNA_SYEKUNDA; /* C_1 - ндмю_яейсмдю */
	fputs( "ндмю_яейсмдю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVYE_SYEKUNDY; /* C_2 - дбе_яейсмдш */
	fputs( "дбе_яейсмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRI_SYEKUNDY; /* C_3 - рпх_яейсмдш */
	fputs( "рпх_яейсмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_DOSTOVYERNOST_; /* C_4 - рюилюср_мю_днярнбепмнярэ */
	fputs( "рюилюср_мю_днярнбепмнярэ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYAT__SYEKUND; /* C_5 - оърэ_яейсмд */
	fputs( "оърэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NAYA_DLITYEL_NOST__OTSUTSTVIYA_DOSTOVYERNOSTI; /* C_6 - люйяхлюкэмюъ_дкхрекэмнярэ_нрясрярбхъ_днярнбепмнярх */
	fputs( "люйяхлюкэмюъ_дкхрекэмнярэ_нрясрярбхъ_днярнбепмнярх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DYESYAT__SYEKUND; /* C_7 - деяърэ_яейсмд */
	fputs( "деяърэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVADTSAT__SYEKUND; /* C_8 - дбюджюрэ_яейсмд */
	fputs( "дбюджюрэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_ZAT_VAK; /* C_9 - рюилюср_мю_япюаюршбюмхе_гюр_бюй */
	fputs( "рюилюср_мю_япюаюршбюмхе_гюр_бюй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_SAPUNA; /* C_10 - рюилюср_мю_япюаюршбюмхе_яюосмю */
	fputs( "рюилюср_мю_япюаюршбюмхе_яюосмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_USTR_PLAV_PUSKA; /* C_11 - рюилюср_мю_япюаюршбюмхе_сярп_окюб_осяйю */
	fputs( "рюилюср_мю_япюаюршбюмхе_сярп_окюб_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_VAK_NASOSA; /* C_12 - рюилюср_мю_япюаюршбюмхе_бюй_мюяняю */
	fputs( "рюилюср_мю_япюаюршбюмхе_бюй_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_VYENTILYATORA; /* C_13 - рюилюср_мю_япюаюршбюмхе_бемрхкърнпю */
	fputs( "рюилюср_мю_япюаюршбюмхе_бемрхкърнпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_RYEG_T; /* C_14 - рюилюср_мю_япюаюршбюмхе_пец_р */
	fputs( "рюилюср_мю_япюаюршбюмхе_пец_р = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_RYEG_UR; /* C_15 - рюилюср_мю_япюаюршбюмхе_пец_сп */
	fputs( "рюилюср_мю_япюаюршбюмхе_пец_сп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_NASOS_OKHL; /* C_16 - рюилюср_мю_япюаюршбюмхе_мюяня_нук */
	fputs( "рюилюср_мю_япюаюршбюмхе_мюяня_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SVYAZ__S_GUI; /* C_17 - рюилюср_мю_ябъгэ_я_цсх */
	fputs( "рюилюср_мю_ябъгэ_я_цсх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ODNA_MINUTA; /* C_18 - ндмю_лхмсрю */
	fputs( "ндмю_лхмсрю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVYE_MINUTY; /* C_19 - дбе_лхмсрш */
	fputs( "дбе_лхмсрш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYAT__MINUT; /* C_20 - оърэ_лхмср */
	fputs( "оърэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DYESYAT__MINUT; /* C_21 - деяърэ_лхмср */
	fputs( "деяърэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRIDTSAT__MINUT; /* C_22 - рпхджюрэ_лхмср */
	fputs( "рпхджюрэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYATNADTSAT__MINUT; /* C_23 - оърмюджюрэ_лхмср */
	fputs( "оърмюджюрэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_ZADYERZHKA_NA_OTKACHKU; /* C_24 - рюилюср_гюдепфйю_мю_нрйювйс */
	fputs( "рюилюср_гюдепфйю_мю_нрйювйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VKL; /* C_25 - бйк */
	fputs( "бйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYK; /* C_26 - бшй */
	fputs( "бшй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OTKR; /* C_27 - нрйп */
	fputs( "нрйп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZAKR; /* C_28 - гюйп */
	fputs( "гюйп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = YEST_; /* C_29 - еярэ */
	fputs( "еярэ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NYET; /* C_30 - мер */
	fputs( "мер = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NIZHYE_NORMY; /* C_31 - мхфе_мнплш */
	fputs( "мхфе_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NORMA; /* C_32 - мнплю */
	fputs( "мнплю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYSHYE_NORMY; /* C_33 - бшье_мнплш */
	fputs( "бшье_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VNYE_NORMY; /* C_34 - бме_мнплш */
	fputs( "бме_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DOSTOVYERNO; /* C_35 - днярнбепмн */
	fputs( "днярнбепмн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NYEDOSTOVYERNO; /* C_36 - меднярнбепмн */
	fputs( "меднярнбепмн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = Nye_provyeryayutsya; /* C_37 - мЕ_ОПНБЕПЪЧРЯЪ */
	fputs( "мЕ_ОПНБЕПЪЧРЯЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = Provyeryayutsya; /* C_38 - оПНБЕПЪЧРЯЪ */
	fputs( "оПНБЕПЪЧРЯЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_DIAGNOSTIKU_RAZRYVA_SVYAZI; /* C_39 - рюилюср_мю_дхюцмнярхйс_пюгпшбю_ябъгх */
	fputs( "рюилюср_мю_дхюцмнярхйс_пюгпшбю_ябъгх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = T_Pryedyel_nayaVrubashkyeOkhlazhdyeniya; /* C_40 - р_оПЕДЕКЭМЮЪбПСАЮЬЙЕнУКЮФДЕМХЪ */
	fputs( "р_оПЕДЕКЭМЮЪбПСАЮЬЙЕнУКЮФДЕМХЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = T_Pryedyel_nayaVbakyeOkhlazhdyeniya; /* C_41 - р_оПЕДЕКЭМЮЪбАЮЙЕнУКЮФДЕМХЪ */
	fputs( "р_оПЕДЕКЭМЮЪбАЮЙЕнУКЮФДЕМХЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKIJ; /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_мхгйхи */
	fputs( "ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_мхгйхи = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKIJ; /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_бшянйхи */
	fputs( "ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_бшянйхи = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE; /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_б_мнпле */
	fputs( "ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_DATCHIKOV_UROVNYA; /* ой_цсх_нрйюг_дюрвхйнб_спнбмъ */
	fputs( "ой_цсх_нрйюг_дюрвхйнб_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKAYA; /* ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_мхгйюъ */
	fputs( "ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_мхгйюъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKAYA; /* ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_бшянйюъ */
	fputs( "ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_бшянйюъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE; /* ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_б_мнпле */
	fputs( "ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_NIZKAYA; /* ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_мхгйюъ */
	fputs( "ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_мхгйюъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_VYSOKAYA; /* ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_бшянйюъ */
	fputs( "ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_бшянйюъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_V_NORMYE; /* ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_б_мнпле */
	fputs( "ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_V_NORMYE; /* ой_цсх_дюбкемхе_б_бюйсслмни_рпсае_б_мнпле */
	fputs( "ой_цсх_дюбкемхе_б_бюйсслмни_рпсае_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_VNYE_NORMY; /* ой_цсх_дюбкемхе_б_бюйсслмни_рпсае_бме_мнплш */
	fputs( "ой_цсх_дюбкемхе_б_бюйсслмни_рпсае_бме_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SKOROST__OTKACHKI_V_NORMYE; /* ой_цсх_яйнпнярэ_нрйювйх_б_мнпле */
	fputs( "ой_цсх_яйнпнярэ_нрйювйх_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SKOROST__OTKACHKI_NIZHYE_NORMY; /* ой_цсх_яйнпнярэ_нрйювйх_мхфе_мнплш */
	fputs( "ой_цсх_яйнпнярэ_нрйювйх_мхфе_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_V_NORMYE; /* ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_б_мнпле */
	fputs( "ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_VYSHYE_NORMY; /* ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_бшье_мнплш */
	fputs( "ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_бшье_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY; /* ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_мхфе_мнплш */
	fputs( "ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_мхфе_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VAKUUMIROVANIYA_OTKAZ_OBORUDOVANIYA; /* ой_цсх_нрйюг_бюйсслхпнбюмхъ_нрйюг_нанпсднбюмхъ */
	fputs( "ой_цсх_нрйюг_бюйсслхпнбюмхъ_нрйюг_нанпсднбюмхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_START_VYKLYUCHYENIYA_VAKUUMIROVANIYA_TRUBY; /* ой_цсх_ярюпр_бшйкчвемхъ_бюйсслхпнбюмхъ_рпсаш */
	fputs( "ой_цсх_ярюпр_бшйкчвемхъ_бюйсслхпнбюмхъ_рпсаш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_START_VYKLYUCHYENIYA_VAKUUMNOGO_NASOSA; /* ой_цсх_ярюпр_бшйкчвемхъ_бюйсслмнцн_мюяняю */
	fputs( "ой_цсх_ярюпр_бшйкчвемхъ_бюйсслмнцн_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_OTKR_ZATVOR_VAK; /* йнл_цсх_нрйп_гюрбнп_бюй */
	fputs( "йнл_цсх_нрйп_гюрбнп_бюй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_ZAKR_ZATVOR_VAK; /* йнл_цсх_гюйп_гюрбнп_бюй */
	fputs( "йнл_цсх_гюйп_гюрбнп_бюй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_OTKR_SAPUN; /* йнл_цсх_нрйп_яюосм */
	fputs( "йнл_цсх_нрйп_яюосм = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_ZAKR_SAPUN; /* йнл_цсх_гюйп_яюосм */
	fputs( "йнл_цсх_гюйп_яюосм = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_USTR_PLAV_PUSKA; /* йнл_цсх_бйк_сярп_окюб_осяйю */
	fputs( "йнл_цсх_бйк_сярп_окюб_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_USTR_PLAV_PUSKA; /* йнл_цсх_бшй_сярп_окюб_осяйю */
	fputs( "йнл_цсх_бшй_сярп_окюб_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_PIT_UPP_VAK_NASOSA; /* йнл_цсх_бйк_охр_соо_бюй_мюяняю */
	fputs( "йнл_цсх_бйк_охр_соо_бюй_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_PIT_UPP_VAK_NASOSA; /* йнл_цсх_бшй_охр_соо_бюй_мюяняю */
	fputs( "йнл_цсх_бшй_охр_соо_бюй_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_PIT_VYENTILYATOR; /* йнл_цсх_бйк_охр_бемрхкърнп */
	fputs( "йнл_цсх_бйк_охр_бемрхкърнп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_PIT_VYENTILYATOR; /* йнл_цсх_бшй_охр_бемрхкърнп */
	fputs( "йнл_цсх_бшй_охр_бемрхкърнп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_PIT_RYEG_T; /* йнл_цсх_бйк_охр_пец_р */
	fputs( "йнл_цсх_бйк_охр_пец_р = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_PIT_RYEG_T; /* йнл_цсх_бшй_охр_пец_р */
	fputs( "йнл_цсх_бшй_охр_пец_р = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_PIT_RYEG_UR; /* йнл_цсх_бйк_охр_пец_сп */
	fputs( "йнл_цсх_бйк_охр_пец_сп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_PIT_RYEG_UR; /* йнл_цсх_бшй_охр_пец_сп */
	fputs( "йнл_цсх_бшй_охр_пец_сп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_PIT_NAS_OKHL; /* йнл_цсх_бйк_охр_мюя_нук */
	fputs( "йнл_цсх_бйк_охр_мюя_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_PIT_NAS_OKHL; /* йнл_цсх_бшй_охр_мюя_нук */
	fputs( "йнл_цсх_бшй_охр_мюя_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_VAKUUMIROVANIYE_TRUBY; /* йнл_цсх_бйк_бюйсслхпнбюмхе_рпсаш */
	fputs( "йнл_цсх_бйк_бюйсслхпнбюмхе_рпсаш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VYK_VAKUUMIROVANIYE_TRUBY; /* йнл_цсх_бшй_бюйсслхпнбюмхе_рпсаш */
	fputs( "йнл_цсх_бшй_бюйсслхпнбюмхе_рпсаш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_GUI_VKL_VAKUUMNYJ_NASOS; /* йнл_цсх_бйк_бюйсслмши_мюяня */
	fputs( "йнл_цсх_бйк_бюйсслмши_мюяня = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOMANDY_OT_GUI; /* йнлюмдш_нр_цсх */
	fputs( "йнлюмдш_нр_цсх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_FP_P_VbakyeKompryessora; /* хглм_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ */
	fputs( "хглм_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_FP_P_Vpatrubkye; /* хглм_то_P_бОЮРПСАЙЕ */
	fputs( "хглм_то_P_бОЮРПСАЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_FP_T_Vrubashkye; /* хглм_то_T_бПСАЮЬЙЕ */
	fputs( "хглм_то_T_бПСАЮЬЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_FP_T_Vbakye; /* хглм_то_T_бАЮЙЕ */
	fputs( "хглм_то_T_бАЮЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_FP_P_VtrubyeSidyer; /* хглм_то_P_бРПСАЕяХДЕП */
	fputs( "хглм_то_P_бРПСАЕяХДЕП = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOMANDY_IZM_FP; /* йнлюмдш_хгл_то */
	fputs( "йнлюмдш_хгл_то = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_OTKRYTIYA_ZATVORA_VAKUUMNOGO; /* ой_цсх_нрйюг_нрйпшрхъ_гюрбнпю_бюйсслмнцн */
	fputs( "ой_цсх_нрйюг_нрйпшрхъ_гюрбнпю_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_ZAKRYTIYA_ZATVORA_VAKUUMNOGO; /* ой_цсх_нрйюг_гюйпшрхъ_гюрбнпю_бюйсслмнцн */
	fputs( "ой_цсх_нрйюг_гюйпшрхъ_гюрбнпю_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_OTKRYTIYA_SAPUNA; /* ой_цсх_нрйюг_нрйпшрхъ_яюосмю */
	fputs( "ой_цсх_нрйюг_нрйпшрхъ_яюосмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_ZAKRYTIYA_SAPUNA; /* ой_цсх_нрйюг_гюйпшрхъ_яюосмю */
	fputs( "ой_цсх_нрйюг_гюйпшрхъ_яюосмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_VYENTILYATORA; /* ой_цсх_нрйюг_бйкчвемхъ_бемрхкърнпю */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_бемрхкърнпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_VYENTILYATORA; /* ой_цсх_нрйюг_бшйкчвемхъ_бемрхкърнпю */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_бемрхкърнпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_USTR_PLAV_PUSKA; /* ой_цсх_нрйюг_бйкчвемхъ_сярп_окюб_осяйю */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_сярп_окюб_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_USTR_PLAV_PUSKA; /* ой_цсх_нрйюг_бшйкчвемхъ_сярп_окюб_осяйю */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_сярп_окюб_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_RYEGULYATORA_TYEMPYERATURY; /* ой_цсх_нрйюг_бйкчвемхъ_пецскърнпю_релоепюрспш */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_пецскърнпю_релоепюрспш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_RYEGULYATORA_TYEMPYERATURY; /* ой_цсх_нрйюг_бшйкчвемхъ_пецскърнпю_релоепюрспш */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_пецскърнпю_релоепюрспш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_RYEGULYATORA_UROVNYA; /* ой_цсх_нрйюг_бйкчвемхъ_пецскърнпю_спнбмъ */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_пецскърнпю_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_RYEGULYATORA_UROVNYA; /* ой_цсх_нрйюг_бшйкчвемхъ_пецскърнпю_спнбмъ */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_пецскърнпю_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_NASOSA_OKHLAZHDYENIYA; /* ой_цсх_нрйюг_бйкчвемхъ_мюяняю_нукюфдемхъ */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_мюяняю_нукюфдемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_NASOSA_OKHLAZHDYENIYA; /* ой_цсх_нрйюг_бшйкчвемхъ_мюяняю_нукюфдемхъ */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_мюяняю_нукюфдемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_IDYET_VAKUUMIROVANIYE_OTKAZ_VYPOLNYENIYA_KOMANDY; /* ой_цсх_хдер_бюйсслхпнбюмхе_нрйюг_бшонкмемхъ_йнлюмдш */
	fputs( "ой_цсх_хдер_бюйсслхпнбюмхе_нрйюг_бшонкмемхъ_йнлюмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_USLOVIJ_DLYA_VYPOLNYENIYA_KOMANDY; /* ой_цсх_мер_сякнбхи_дкъ_бшонкмемхъ_йнлюмдш */
	fputs( "ой_цсх_мер_сякнбхи_дкъ_бшонкмемхъ_йнлюмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VNYE_NORMY_OTKAZ_VYPOLNYENI; /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_бме_мнплш_нрйюг_бшонкмемх */
	fputs( "ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_бме_мнплш_нрйюг_бшонкмемх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTRITSATYEL_NAYA_TYEMPYERATURA_VODY_OTKAZ_VYPOLNYENIYA_KOMANDY; /* ой_цсх_нрпхжюрекэмюъ_релоепюрспю_бндш_нрйюг_бшонкмемхъ_йнлюмдш */
	fputs( "ой_цсх_нрпхжюрекэмюъ_релоепюрспю_бндш_нрйюг_бшонкмемхъ_йнлюмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_PATRUBKYE_NYE_UMYEN_SHAYETSYA; /* ой_цсх_дюбкемхе_б_оюрпсайе_ме_слемэьюеряъ */
	fputs( "ой_цсх_дюбкемхе_б_оюрпсайе_ме_слемэьюеряъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_DAVLYENIYE_V_VAK_TRUBYE_NYE_UMYEN_SHAYETSYA; /* ой_цсх_дюбкемхе_б_бюй_рпсае_ме_слемэьюеряъ */
	fputs( "ой_цсх_дюбкемхе_б_бюй_рпсае_ме_слемэьюеряъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_VAKUUMIROVANIYE_USPYESHNO_ZAVYERSHYENO; /* ой_цсх_бюйсслхпнбюмхе_сяоеьмн_гюбепьемн */
	fputs( "ой_цсх_бюйсслхпнбюмхе_сяоеьмн_гюбепьемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_PITANIYA_UPP_VAKUUMNOGO_NASOSA; /* ой_цсх_нрйюг_бйкчвемхъ_охрюмхъ_соо_бюйсслмнцн_мюяняю */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_охрюмхъ_соо_бюйсслмнцн_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_UPP_VAKUUMNOGO_NASOSA; /* ой_цсх_нрйюг_бшйкчвемхъ_охрюмхъ_соо_бюйсслмнцн_мюяняю */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_охрюмхъ_соо_бюйсслмнцн_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYEDOSTOVYERNYYE_DANNYYE_OBORUDOVANIYA_VAK_SISTYEMY; /* ой_цсх_меднярнбепмше_дюммше_нанпсднбюмхъ_бюй_яхярелш */
	fputs( "ой_цсх_меднярнбепмше_дюммше_нанпсднбюмхъ_бюй_яхярелш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_AVARIYA_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_MYEN_SHYE_2kh_ATMOSFYER; /* ой_цсх_юбюпхъ_дюбкемхе_б_аюйе_йнлопеяянпю_лемэье_2У_юрлнятеп */
	fputs( "ой_цсх_юбюпхъ_дюбкемхе_б_аюйе_йнлопеяянпю_лемэье_2У_юрлнятеп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_AVARIYA__SROCHNO_VYKLYUCHIT__VAK_SISTYEMU_V_RUCHNOM_RYEZHIMYE; /* ой_цсх_юбюпхъ__япнвмн_бшйкчвхрэ_бюй_яхярелс_б_псвмнл_пефхле */
	fputs( "ой_цсх_юбюпхъ__япнвмн_бшйкчвхрэ_бюй_яхярелс_б_псвмнл_пефхле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_AVARIYA_PYERYEGRYEV_RUBASHKI_OKHLAZHDYENIYA; /* ой_цсх_юбюпхъ_оепецпеб_псаюьйх_нукюфдемхъ */
	fputs( "ой_цсх_юбюпхъ_оепецпеб_псаюьйх_нукюфдемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_AVARIYA_PYERYEGRYEV_BAKA_OKHLAZHDYENIYA_NASOSA; /* ой_цсх_юбюпхъ_оепецпеб_аюйю_нукюфдемхъ_мюяняю */
	fputs( "ой_цсх_юбюпхъ_оепецпеб_аюйю_нукюфдемхъ_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_RYESTART_NYEDOSTOVYERNYYE_DANNYYE_OBORUDOVANIYA_VAK_SISTYEMY; /* ой_цсх_пеярюпр_меднярнбепмше_дюммше_нанпсднбюмхъ_бюй_яхярелш */
	fputs( "ой_цсх_пеярюпр_меднярнбепмше_дюммше_нанпсднбюмхъ_бюй_яхярелш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__PITANIYE_SHKAFA_VS_380; /* ой_цсх_еярэ_охрюмхе_ьйютю_бя_380 */
	fputs( "ой_цсх_еярэ_охрюмхе_ьйютю_бя_380 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_PITANIYE_SHKAFA_VS_380; /* ой_цсх_мер_охрюмхе_ьйютю_бя_380 */
	fputs( "ой_цсх_мер_охрюмхе_ьйютю_бя_380 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_VYENTILYATOR_VKLYUCHYEN; /* ой_цсх_бемрхкърнп_бйкчвем */
	fputs( "ой_цсх_бемрхкърнп_бйкчвем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_VYENTILYATOR_VYKLYUCHYEN; /* ой_цсх_бемрхкърнп_бшйкчвем */
	fputs( "ой_цсх_бемрхкърнп_бшйкчвем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_VYENTILYATORA; /* ой_цсх_яонмрюммне_бшйкчвемхе_бемрхкърнпю */
	fputs( "ой_цсх_яонмрюммне_бшйкчвемхе_бемрхкърнпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_VYENTILYATORA; /* ой_цсх_яонмрюммне_бйкчвемхе_бемрхкърнпю */
	fputs( "ой_цсх_яонмрюммне_бйкчвемхе_бемрхкърнпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_ZATVOR_VAKUUMNYJ_OTKRYT; /* ой_цсх_гюрбнп_бюйсслмши_нрйпшр */
	fputs( "ой_цсх_гюрбнп_бюйсслмши_нрйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_ZATVOR_VAKUUMNYJ_ZAKRYT; /* ой_цсх_гюрбнп_бюйсслмши_гюйпшр */
	fputs( "ой_цсх_гюрбнп_бюйсслмши_гюйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SRYEDNYEYE_SOSTOYANIYE_ZATVORA_VAKUUMNOGO; /* ой_цсх_япедмее_янярнъмхе_гюрбнпю_бюйсслмнцн */
	fputs( "ой_цсх_япедмее_янярнъмхе_гюрбнпю_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SOSTOYANIYE_OSHIBKI_ZATVORA_VAKUUMNOGO; /* ой_цсх_янярнъмхе_ньхайх_гюрбнпю_бюйсслмнцн */
	fputs( "ой_цсх_янярнъмхе_ньхайх_гюрбнпю_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_OTKRYTIYE_ZAT_VAKUUMNOGO; /* ой_цсх_яонмрюммне_нрйпшрхе_гюр_бюйсслмнцн */
	fputs( "ой_цсх_яонмрюммне_нрйпшрхе_гюр_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_ZAKRYTIYE_ZAT_VAKUUMNOGO; /* ой_цсх_яонмрюммне_гюйпшрхе_гюр_бюйсслмнцн */
	fputs( "ой_цсх_яонмрюммне_гюйпшрхе_гюр_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SAPUN_OTKRYT; /* ой_цсх_яюосм_нрйпшр */
	fputs( "ой_цсх_яюосм_нрйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SAPUN_ZAKRYT; /* ой_цсх_яюосм_гюйпшр */
	fputs( "ой_цсх_яюосм_гюйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_OTKRYTIYE_SAPUNA; /* ой_цсх_яонмрюммне_нрйпшрхе_яюосмю */
	fputs( "ой_цсх_яонмрюммне_нрйпшрхе_яюосмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_ZAKRYTIYE_SAPUNA; /* ой_цсх_яонмрюммне_гюйпшрхе_яюосмю */
	fputs( "ой_цсх_яонмрюммне_гюйпшрхе_яюосмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_UPP_VAKUUMNOGO_NASOSA_VKLYUCHYENO; /* ой_цсх_охрюмхе_соо_бюйсслмнцн_мюяняю_бйкчвемн */
	fputs( "ой_цсх_охрюмхе_соо_бюйсслмнцн_мюяняю_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_UPP_VAKUUMNOGO_NASOSA_VYKLYUCHYENO; /* ой_цсх_охрюмхе_соо_бюйсслмнцн_мюяняю_бшйкчвемн */
	fputs( "ой_цсх_охрюмхе_соо_бюйсслмнцн_мюяняю_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_UPP_VAKUUMNOGO_NASOSA; /* ой_цсх_яонмрюммне_бйкчвемхе_соо_бюйсслмнцн_мюяняю */
	fputs( "ой_цсх_яонмрюммне_бйкчвемхе_соо_бюйсслмнцн_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_UPP_VAKUUMNOGO_NASOSA; /* ой_цсх_яонмрюммне_бшйкчвемхе_соо_бюйсслмнцн_мюяняю */
	fputs( "ой_цсх_яонмрюммне_бшйкчвемхе_соо_бюйсслмнцн_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_RYEGULYATORA_TYEMPYERATURY_VKLYUCHYENO; /* ой_цсх_охрюмхе_пецскърнпю_релоепюрспш_бйкчвемн */
	fputs( "ой_цсх_охрюмхе_пецскърнпю_релоепюрспш_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_RYEGULYATORA_TYEMPYERATURY_VYKLYUCHYENO; /* ой_цсх_охрюмхе_пецскърнпю_релоепюрспш_бшйкчвемн */
	fputs( "ой_цсх_охрюмхе_пецскърнпю_релоепюрспш_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_RYEGULYATORA_TYEMPYERATURY; /* ой_цсх_яонмрюммне_бйкчвемхе_пецскърнпю_релоепюрспш */
	fputs( "ой_цсх_яонмрюммне_бйкчвемхе_пецскърнпю_релоепюрспш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_RYEGULYATORA_TYEMPYERATURY; /* ой_цсх_яонмрюммне_бшйкчвемхе_пецскърнпю_релоепюрспш */
	fputs( "ой_цсх_яонмрюммне_бшйкчвемхе_пецскърнпю_релоепюрспш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_RYEGULYATORA_UROVNYA_VKLYUCHYENO; /* ой_цсх_охрюмхе_пецскърнпю_спнбмъ_бйкчвемн */
	fputs( "ой_цсх_охрюмхе_пецскърнпю_спнбмъ_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_RYEGULYATORA_UROVNYA_VYKLYUCHYENO; /* ой_цсх_охрюмхе_пецскърнпю_спнбмъ_бшйкчвемн */
	fputs( "ой_цсх_охрюмхе_пецскърнпю_спнбмъ_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_RYEGULYATORA_UROVNYA; /* ой_цсх_яонмрюммне_бйкчвемхе_пецскърнпю_спнбмъ */
	fputs( "ой_цсх_яонмрюммне_бйкчвемхе_пецскърнпю_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_RYEGULYATORA_UROVNYA; /* ой_цсх_яонмрюммне_бшйкчвемхе_пецскърнпю_спнбмъ */
	fputs( "ой_цсх_яонмрюммне_бшйкчвемхе_пецскърнпю_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_NASOSA_OKHLAZHDYENIYA_VKLYUCHYENO; /* ой_цсх_охрюмхе_мюяняю_нукюфдемхъ_бйкчвемн */
	fputs( "ой_цсх_охрюмхе_мюяняю_нукюфдемхъ_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_PITANIYE_NASOSA_OKHLAZHDYENIYA_VYKLYUCHYENO; /* ой_цсх_охрюмхе_мюяняю_нукюфдемхъ_бшйкчвемн */
	fputs( "ой_цсх_охрюмхе_мюяняю_нукюфдемхъ_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_NASOSA_OKHLAZHDYENIYA; /* ой_цсх_яонмрюммне_бйкчвемхе_мюяняю_нукюфдемхъ */
	fputs( "ой_цсх_яонмрюммне_бйкчвемхе_мюяняю_нукюфдемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_NASOSA_OKHLAZHDYENIYA; /* ой_цсх_яонмрюммне_бшйкчвемхе_мюяняю_нукюфдемхъ */
	fputs( "ой_цсх_яонмрюммне_бшйкчвемхе_мюяняю_нукюфдемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_USTROJSTVO_PLAVNOGO_PUSKA_VKLYUCHYENO; /* ой_цсх_сярпниярбн_окюбмнцн_осяйю_бйкчвемн */
	fputs( "ой_цсх_сярпниярбн_окюбмнцн_осяйю_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_USTROJSTVO_PLAVNOGO_PUSKA_VYKLYUCHYENO; /* ой_цсх_сярпниярбн_окюбмнцн_осяйю_бшйкчвемн */
	fputs( "ой_цсх_сярпниярбн_окюбмнцн_осяйю_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_USTROJSTVA_PLAVNOGO_PUSKA; /* ой_цсх_яонмрюммне_бйкчвемхе_сярпниярбю_окюбмнцн_осяйю */
	fputs( "ой_цсх_яонмрюммне_бйкчвемхе_сярпниярбю_окюбмнцн_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_USTROJSTVA_PLAVNOGO_PUSKA; /* ой_цсх_яонмрюммне_бшйкчвемхе_сярпниярбю_окюбмнцн_осяйю */
	fputs( "ой_цсх_яонмрюммне_бшйкчвемхе_сярпниярбю_окюбмнцн_осяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VAKUUMIROVANIYA; /* ой_цсх_нрйюг_бюйсслхпнбюмхъ */
	fputs( "ой_цсх_нрйюг_бюйсслхпнбюмхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VKLYUCHYENIYA_VAKUUMNOJ_PODSISTYEMY; /* ой_цсх_нрйюг_бйкчвемхъ_бюйсслмни_ондяхярелш */
	fputs( "ой_цсх_нрйюг_бйкчвемхъ_бюйсслмни_ондяхярелш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OTKAZ_VYKLYUCHYENIYA_VAKUUMNOJ_PODSISTYEMY; /* ой_цсх_нрйюг_бшйкчвемхъ_бюйсслмни_ондяхярелш */
	fputs( "ой_цсх_нрйюг_бшйкчвемхъ_бюйсслмни_ондяхярелш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_KONTS_OTKRYTIYA_ZATV_VAKUUMNOGO; /* ой_цсх_еярэ_ябъгэ_я_йнмж_нрйпшрхъ_гюрб_бюйсслмнцн */
	fputs( "ой_цсх_еярэ_ябъгэ_я_йнмж_нрйпшрхъ_гюрб_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_KONTS_OTKRYTIYA_ZATV_VAKUUMNOGO; /* ой_цсх_мер_ябъгх_я_йнмж_нрйпшрхъ_гюрб_бюйсслмнцн */
	fputs( "ой_цсх_мер_ябъгх_я_йнмж_нрйпшрхъ_гюрб_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_KONTS_ZAKRYTIYA_ZATV_VAKUUMNOGO; /* ой_цсх_еярэ_ябъгэ_я_йнмж_гюйпшрхъ_гюрб_бюйсслмнцн */
	fputs( "ой_цсх_еярэ_ябъгэ_я_йнмж_гюйпшрхъ_гюрб_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_KONTS_ZAKRYTIYA_ZATV_VAKUUMNOGO; /* ой_цсх_мер_ябъгх_я_йнмж_гюйпшрхъ_гюрб_бюйсслмнцн */
	fputs( "ой_цсх_мер_ябъгх_я_йнмж_гюйпшрхъ_гюрб_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_SAPUNOM; /* ой_цсх_еярэ_ябъгэ_я_яюосмнл */
	fputs( "ой_цсх_еярэ_ябъгэ_я_яюосмнл = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_SAPUNOM; /* ой_цсх_мер_ябъгх_я_яюосмнл */
	fputs( "ой_цсх_мер_ябъгх_я_яюосмнл = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_PLAVNYM_PUSKOM; /* ой_цсх_еярэ_ябъгэ_я_окюбмшл_осяйнл */
	fputs( "ой_цсх_еярэ_ябъгэ_я_окюбмшл_осяйнл = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_PLAVNYM_PUSKOM; /* ой_цсх_мер_ябъгх_я_окюбмшл_осяйнл */
	fputs( "ой_цсх_мер_ябъгх_я_окюбмшл_осяйнл = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_PITANIYEM_VAK_NASOSA; /* ой_цсх_еярэ_ябъгэ_я_охрюмхел_бюй_мюяняю */
	fputs( "ой_цсх_еярэ_ябъгэ_я_охрюмхел_бюй_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_PITANIYEM_VAK_NASOSA; /* ой_цсх_мер_ябъгх_я_охрюмхел_бюй_мюяняю */
	fputs( "ой_цсх_мер_ябъгх_я_охрюмхел_бюй_мюяняю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_VYENTILYATOROM; /* ой_цсх_еярэ_ябъгэ_я_бемрхкърнпнл */
	fputs( "ой_цсх_еярэ_ябъгэ_я_бемрхкърнпнл = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_VYENTILYATOROM; /* ой_цсх_мер_ябъгх_я_бемрхкърнпнл */
	fputs( "ой_цсх_мер_ябъгх_я_бемрхкърнпнл = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_RYEG_TYEMPYERATURY; /* ой_цсх_еярэ_ябъгэ_я_пец_релоепюрспш */
	fputs( "ой_цсх_еярэ_ябъгэ_я_пец_релоепюрспш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_RYEG_TYEMPYERATURY; /* ой_цсх_мер_ябъгх_я_пец_релоепюрспш */
	fputs( "ой_цсх_мер_ябъгх_я_пец_релоепюрспш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_RYEG_UROVNYA; /* ой_цсх_еярэ_ябъгэ_я_пец_спнбмъ */
	fputs( "ой_цсх_еярэ_ябъгэ_я_пец_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_RYEG_UROVNYA; /* ой_цсх_мер_ябъгх_я_пец_спнбмъ */
	fputs( "ой_цсх_мер_ябъгх_я_пец_спнбмъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_NIZHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL; /* ой_цсх_еярэ_ябъгэ_я_мхфмхл_йнмжебхйнл_сп_бндш_аюйю_нук */
	fputs( "ой_цсх_еярэ_ябъгэ_я_мхфмхл_йнмжебхйнл_сп_бндш_аюйю_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_NIZHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL; /* ой_цсх_мер_ябъгх_я_мхфмхл_йнмжебхйнл_сп_бндш_аюйю_нук */
	fputs( "ой_цсх_мер_ябъгх_я_мхфмхл_йнмжебхйнл_сп_бндш_аюйю_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_VYERKHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL; /* ой_цсх_еярэ_ябъгэ_я_бепумхл_йнмжебхйнл_сп_бндш_аюйю_нук */
	fputs( "ой_цсх_еярэ_ябъгэ_я_бепумхл_йнмжебхйнл_сп_бндш_аюйю_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_VYERKHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL; /* ой_цсх_мер_ябъгх_я_бепумхл_йнмжебхйнл_сп_бндш_аюйю_нук */
	fputs( "ой_цсх_мер_ябъгх_я_бепумхл_йнмжебхйнл_сп_бндш_аюйю_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_NASOSOSOM_OKHL; /* ой_цсх_еярэ_ябъгэ_я_мюянянянл_нук */
	fputs( "ой_цсх_еярэ_ябъгэ_я_мюянянянл_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_NASOSOSOM_OKHL; /* ой_цсх_мер_ябъгх_я_мюянянянл_нук */
	fputs( "ой_цсх_мер_ябъгх_я_мюянянянл_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_PITANIYEM_SHKAFA_380; /* ой_цсх_еярэ_ябъгэ_я_охрюмхел_ьйютю_380 */
	fputs( "ой_цсх_еярэ_ябъгэ_я_охрюмхел_ьйютю_380 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_PITANIYEM_SHKAFA_380; /* ой_цсх_мер_ябъгх_я_охрюмхел_ьйютю_380 */
	fputs( "ой_цсх_мер_ябъгх_я_охрюмхел_ьйютю_380 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_BAKYE_KOMPRYESSORA; /* ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_аюйе_йнлопеяянпю */
	fputs( "ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_аюйе_йнлопеяянпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_BAKYE_KOMPRYESSORA; /* ой_цсх_мер_ябъгх_я_дюбкемхел_б_аюйе_йнлопеяянпю */
	fputs( "ой_цсх_мер_ябъгх_я_дюбкемхел_б_аюйе_йнлопеяянпю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_PATRUBKYE; /* ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_оюрпсайе */
	fputs( "ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_оюрпсайе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_PATRUBKYE; /* ой_цсх_мер_ябъгх_я_дюбкемхел_б_оюрпсайе */
	fputs( "ой_цсх_мер_ябъгх_я_дюбкемхел_б_оюрпсайе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_TYEMPYERATUROJ_V_RUBASHKYE_OKHL; /* ой_цсх_еярэ_ябъгэ_я_релоепюрспни_б_псаюьйе_нук */
	fputs( "ой_цсх_еярэ_ябъгэ_я_релоепюрспни_б_псаюьйе_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_TYEMPYERATUROJ_V_RUBASHKYE_OKHL; /* ой_цсх_мер_ябъгх_я_релоепюрспни_б_псаюьйе_нук */
	fputs( "ой_цсх_мер_ябъгх_я_релоепюрспни_б_псаюьйе_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_TYEMPYERATUROJ_V_BAKYE_OKHL; /* ой_цсх_еярэ_ябъгэ_я_релоепюрспни_б_аюйе_нук */
	fputs( "ой_цсх_еярэ_ябъгэ_я_релоепюрспни_б_аюйе_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_TYEMPYERATUROJ_V_BAKYE_OKHL; /* ой_цсх_мер_ябъгх_я_релоепюрспни_б_аюйе_нук */
	fputs( "ой_цсх_мер_ябъгх_я_релоепюрспни_б_аюйе_нук = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_TRUBYE_SID; /* ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_рпсае_яхд */
	fputs( "ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_рпсае_яхд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_TRUBYE_SID; /* ой_цсх_мер_ябъгх_я_дюбкемхел_б_рпсае_яхд */
	fputs( "ой_цсх_мер_ябъгх_я_дюбкемхел_б_рпсае_яхд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_VAKUUMIROVANIYE_TRUBY_VKLYUCHYENO; /* ой_цсх_бюйсслхпнбюмхе_рпсаш_бйкчвемн */
	fputs( "ой_цсх_бюйсслхпнбюмхе_рпсаш_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_VAKUUMIROVANIYE_TRUBY_VYKLYUCHYENO; /* ой_цсх_бюйсслхпнбюмхе_рпсаш_бшйкчвемн */
	fputs( "ой_цсх_бюйсслхпнбюмхе_рпсаш_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_FP_P_VbakyeKompryessora; /* ой_цсх_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ */
	fputs( "ой_цсх_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_FP_P_Vpatrubkye; /* ой_цсх_то_P_бОЮРПСАЙЕ */
	fputs( "ой_цсх_то_P_бОЮРПСАЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_FP_T_Vrubashkye; /* ой_цсх_то_T_бПСАЮЬЙЕ */
	fputs( "ой_цсх_то_T_бПСАЮЬЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_FP_T_Vbakye; /* ой_цсх_то_T_бАЮЙЕ */
	fputs( "ой_цсх_то_T_бАЮЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_FP_P_VtrubyeSidyer; /* ой_цсх_то_P_бРПСАЕяХДЕП */
	fputs( "ой_цсх_то_P_бРПСАЕяХДЕП = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_1; /* хглм_мо_1 */
	fputs( "хглм_мо_1 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_P_VbakyeKompryessora; /* хглм_мо_гд_P_бАЮЙЕйНЛОПЕЯЯНПЮ */
	fputs( "хглм_мо_гд_P_бАЮЙЕйНЛОПЕЯЯНПЮ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_Patmosf; /* хглм_мо_гд_PЮРЛНЯТ */
	fputs( "хглм_мо_гд_PЮРЛНЯТ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_P_VtrubyeSidyer; /* хглм_мо_гд_P_бРПСАЕяХДЕП */
	fputs( "хглм_мо_гд_P_бРПСАЕяХДЕП = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_T_VrubashkyeNizhnyaya; /* хглм_мо_гд_T_бПСАЮЬЙЕмХФМЪЪ */
	fputs( "хглм_мо_гд_T_бПСАЮЬЙЕмХФМЪЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_T_VrubashkyeVyerkhnyaya; /* хглм_мо_гд_T_бПСАЮЬЙЕбЕПУМЪЪ */
	fputs( "хглм_мо_гд_T_бПСАЮЬЙЕбЕПУМЪЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_T_VbakyeNizhnyaya; /* хглм_мо_гд_T_бАЮЙЕмХФМЪЪ */
	fputs( "хглм_мо_гд_T_бАЮЙЕмХФМЪЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_T_VbakyeVyerkhnyaya; /* хглм_мо_гд_T_бАЮЙЕбЕПУМЪЪ */
	fputs( "хглм_мо_гд_T_бАЮЙЕбЕПУМЪЪ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_PyeriodaKontrP_PriOtkachkye; /* хглм_мо_гд_оЕПХНДЮйНМРПP_оПХнРЙЮВЙЕ */
	fputs( "хглм_мо_гд_оЕПХНДЮйНМРПP_оПХнРЙЮВЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_PyeriodaKontrP_PriNatyekanii; /* хглм_мо_гд_оЕПХНДЮйНМРПP_оПХмЮРЕЙЮМХХ */
	fputs( "хглм_мо_гд_оЕПХНДЮйНМРПP_оПХмЮРЕЙЮМХХ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_Gist_T_Vbakye; /* хглм_мо_гд_цХЯР_T_бАЮЙЕ */
	fputs( "хглм_мо_гд_цХЯР_T_бАЮЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_Gist_T_Vrubashkye; /* хглм_мо_гд_цХЯР_T_бПСАЮЬЙЕ */
	fputs( "хглм_мо_гд_цХЯР_T_бПСАЮЬЙЕ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_Gist_P_VbakyeKompryessora; /* хглм_мо_гд_цХЯР_P_бАЮЙЕйНЛОПЕЯЯНПЮ */
	fputs( "хглм_мо_гд_цХЯР_P_бАЮЙЕйНЛОПЕЯЯНПЮ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_Gist_P_VtrubyeSidyerVyerkh; /* хглм_мо_гд_цХЯР_P_бРПСАЕяХДЕПбЕПУ */
	fputs( "хглм_мо_гд_цХЯР_P_бРПСАЕяХДЕПбЕПУ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_ZD_Gist_P_VtrubyeSidyerNizh; /* хглм_мо_гд_цХЯР_P_бРПСАЕяХДЕПмХФ */
	fputs( "хглм_мо_гд_цХЯР_P_бРПСАЕяХДЕПмХФ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_N; /* хглм_мо_N */
	fputs( "хглм_мо_N = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PK_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI; /* ой_цсх_ньхайю_йндю_йнлюмдш_нр_цсх */
	fputs( "ой_цсх_ньхайю_йндю_йнлюмдш_нр_цсх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
