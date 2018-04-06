#include <stdio.h>
#include "canon_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("canon_constants.cfg","w");
	i = ODNA_SYEKUNDA; /* C_0 - ндмю_яейсмдю */
	fputs( "ндмю_яейсмдю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVYE_SYEKUNDY; /* C_1 - дбе_яейсмдш */
	fputs( "дбе_яейсмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRI_SYEKUNDY; /* C_2 - рпх_яейсмдш */
	fputs( "рпх_яейсмдш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYAT__SYEKUND; /* C_3 - оърэ_яейсмд */
	fputs( "оърэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DYESYAT__SYEKUND; /* C_4 - деяърэ_яейсмд */
	fputs( "деяърэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVADTSAT__SYEKUND; /* C_5 - дбюджюрэ_яейсмд */
	fputs( "дбюджюрэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRIDTSAT__SYEKUND; /* C_6 - рпхджюрэ_яейсмд */
	fputs( "рпхджюрэ_яейсмд = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ODNA_MINUTA; /* C_7 - ндмю_лхмсрю */
	fputs( "ндмю_лхмсрю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVYE_MINUTY; /* C_8 - дбе_лхмсрш */
	fputs( "дбе_лхмсрш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYAT__MINUT; /* C_9 - оърэ_лхмср */
	fputs( "оърэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DYESYAT__MINUT; /* C_10 - деяърэ_лхмср */
	fputs( "деяърэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYATNADTSAT__MINUT; /* C_11 - оърмюджюрэ_лхмср */
	fputs( "оърмюджюрэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRIDTSAT__MINUT; /* C_12 - рпхджюрэ_лхмср */
	fputs( "рпхджюрэ_лхмср = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_VOZD_PODUSHKI; /* C_13 - рюилюср_бнгд_ондсьйх */
	fputs( "рюилюср_бнгд_ондсьйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NASOSA_VAKUUMNOGO; /* C_14 - рюилюср_мюяняю_бюйсслмнцн */
	fputs( "рюилюср_мюяняю_бюйсслмнцн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_ZAZHIMA_DISKA; /* C_15 - рюилюср_гюфхлю_дхяйю */
	fputs( "рюилюср_гюфхлю_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_RAZZHIMA_DISKA; /* C_16 - рюилюср_пюгфхлю_дхяйю */
	fputs( "рюилюср_пюгфхлю_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_KLAPANA_KARYETKI; /* C_17 - рюилюср_мю_япюаюршбюмхе_йкюоюмю_йюперйх */
	fputs( "рюилюср_мю_япюаюршбюмхе_йкюоюмю_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_KLAPANA_SHPINDYELYA_D; /* C_18 - рюилюср_мю_япюаюршбюмхе_йкюоюмю_ьохмдекъ_д */
	fputs( "рюилюср_мю_япюаюршбюмхе_йкюоюмю_ьохмдекъ_д = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SVYAZ__S_GIO; /* C_19 - рюилюср_мю_ябъгэ_я_цхн */
	fputs( "рюилюср_мю_ябъгэ_я_цхн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VKL; /* C_20 - бйк */
	fputs( "бйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYK; /* C_21 - бшй */
	fputs( "бшй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_22 - бшйк */
	fputs( "бшйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OTKR; /* C_23 - нрйп */
	fputs( "нрйп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZAKR; /* C_24 - гюйп */
	fputs( "гюйп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = YEST_; /* C_25 - еярэ */
	fputs( "еярэ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NYET; /* C_26 - мер */
	fputs( "мер = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NI_DA_NI_NYET; /* C_27 - мх_дю_мх_мер */
	fputs( "мх_дю_мх_мер = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MINIMAL_NOYE_ZADANIYE_R_KARYETKI; /* C_28 - лхмхлюкэмне_гюдюмхе_R_йюперйх */
	fputs( "лхмхлюкэмне_гюдюмхе_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI; /* C_29 - люйяхлюкэмне_гюдюмхе_R_йюперйх */
	fputs( "люйяхлюкэмне_гюдюмхе_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MINIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA; /* C_30 - лхмхлюкэмне_гюдюмхе_W_опедлермнцн_ярнкхйю */
	fputs( "лхмхлюкэмне_гюдюмхе_W_опедлермнцн_ярнкхйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA; /* C_31 - люйяхлюкэмне_гюдюмхе_W_опедлермнцн_ярнкхйю */
	fputs( "люйяхлюкэмне_гюдюмхе_W_опедлермнцн_ярнкхйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_INITSIALIZATSII; /* пефхл_хмхжхюкхгюжхх */
	fputs( "пефхл_хмхжхюкхгюжхх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_RR; /* пефхл_пп */
	fputs( "пефхл_пп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_OTMYENA; /* пефхл_нрлемю */
	fputs( "пефхл_нрлемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_KONYETS_RABOTY; /* пефхл_йнмеж_пюанрш */
	fputs( "пефхл_йнмеж_пюанрш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KONYETS_KODOV_RYEZHIMOV; /* йнмеж_йнднб_пефхлнб */
	fputs( "йнмеж_йнднб_пефхлнб = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_RYEZHIM_OTMYENA; /* цхн2ясюа_пефхл_нрлемю */
	fputs( "цхн2ясюа_пефхл_нрлемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_RYEZHIM_KONYETS_RABOTY; /* цхн2ясюа_пефхл_йнмеж_пюанрш */
	fputs( "цхн2ясюа_пефхл_йнмеж_пюанрш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_ZAZHAT__DISK; /* цхн2ясюа_гюфюрэ_дхяй */
	fputs( "цхн2ясюа_гюфюрэ_дхяй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_RAZZHAT__DISK; /* цхн2ясюа_пюгфюрэ_дхяй */
	fputs( "цхн2ясюа_пюгфюрэ_дхяй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KO_ISPRAVNOST__VOZDUSHNYKH_PODUSHYEK; /* цхн2ясюа_йн_хяопюбмнярэ_бнгдсьмшу_ондсьей */
	fputs( "цхн2ясюа_йн_хяопюбмнярэ_бнгдсьмшу_ондсьей = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_OTKAZ_VOZDUSHNYKH_PODUSHYEK; /* цхн2ясюа_нрйюг_бнгдсьмшу_ондсьей */
	fputs( "цхн2ясюа_нрйюг_бнгдсьмшу_ондсьей = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KARYETKU_V_POLOZHYENIYE_USTANOVKI_DISKA; /* цхн2ясюа_йюперйс_б_онкнфемхе_сярюмнбйх_дхяйю */
	fputs( "цхн2ясюа_йюперйс_б_онкнфемхе_сярюмнбйх_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KARYETKU_V_TSYENTR_VRASCHYENIYA; /* цхн2ясюа_йюперйс_б_жемрп_бпюыемхъ */
	fputs( "цхн2ясюа_йюперйс_б_жемрп_бпюыемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KARYETKU_V_ZADANNYJ_RADIUS; /* цхн2ясюа_йюперйс_б_гюдюммши_пюдхся */
	fputs( "цхн2ясюа_йюперйс_б_гюдюммши_пюдхся = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_STOP_KARYETKI; /* цхн2ясюа_ярно_йюперйх */
	fputs( "цхн2ясюа_ярно_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU; /* цхн2ясюа_бйк_юйрхбмне_онгхжхнмхпнбюмхе_он_бпюыемхч */
	fputs( "цхн2ясюа_бйк_юйрхбмне_онгхжхнмхпнбюмхе_он_бпюыемхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VYKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU; /* цхн2ясюа_бшйк_юйрхбмне_онгхжхнмхпнбюмхе_он_бпюыемхч */
	fputs( "цхн2ясюа_бшйк_юйрхбмне_онгхжхнмхпнбюмхе_он_бпюыемхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VKL_VRASCHYENIYE_PRYED_STOLIKA_V_ZD_W; /* цхн2ясюа_бйк_бпюыемхе_опед_ярнкхйю_б_гд_W */
	fputs( "цхн2ясюа_бйк_бпюыемхе_опед_ярнкхйю_б_гд_W = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_STOP_VRASCHYENIYA_PRYEDMYETNOGO_STOLIKA; /* цхн2ясюа_ярно_бпюыемхъ_опедлермнцн_ярнкхйю */
	fputs( "цхн2ясюа_ярно_бпюыемхъ_опедлермнцн_ярнкхйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VKL_PODSVYETKU_DISKA; /* цхн2ясюа_бйк_ондяберйс_дхяйю */
	fputs( "цхн2ясюа_бйк_ондяберйс_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VYKL_PODSVYETKU_DISKA; /* цхн2ясюа_бшйк_ондяберйс_дхяйю */
	fputs( "цхн2ясюа_бшйк_ондяберйс_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_YEST__SVYAZ__S_MOKHA1212; /* тхй2ясюа_еярэ_ябъгэ_я_лную1212 */
	fputs( "тхй2ясюа_еярэ_ябъгэ_я_лную1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_NYET_SVYAZI_S_MOKHA1212; /* тхй2ясюа_мер_ябъгх_я_лную1212 */
	fputs( "тхй2ясюа_мер_ябъгх_я_лную1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_YEST__SVYAZ__S_MOKHA1214; /* тхй2ясюа_еярэ_ябъгэ_я_лную1214 */
	fputs( "тхй2ясюа_еярэ_ябъгэ_я_лную1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_NYET_SVYAZI_S_MOKHA1214; /* тхй2ясюа_мер_ябъгх_я_лную1214 */
	fputs( "тхй2ясюа_мер_ябъгх_я_лную1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_IZMN_ZD_R_KARYETKI; /* цхн2ясюа_хглм_гд_R_йюперйх */
	fputs( "цхн2ясюа_хглм_гд_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA; /* цхн2ясюа_хглм_гд_W_опедлермнцн_ярнкхйю */
	fputs( "цхн2ясюа_хглм_гд_W_опедлермнцн_ярнкхйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KONYETS_KODOV_FIK; /* цхн2ясюа_йнмеж_йнднб_тхй */
	fputs( "цхн2ясюа_йнмеж_йнднб_тхй = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DAVLYENIYE_V_NORMYE; /* ясюа2тхй_дюбкемхе_б_мнпле */
	fputs( "ясюа2тхй_дюбкемхе_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DAVLYENIYE_NIZHYE_NORMY; /* ясюа2тхй_дюбкемхе_мхфе_мнплш */
	fputs( "ясюа2тхй_дюбкемхе_мхфе_мнплш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DAVLYENIYE_AVARIJNOYE; /* ясюа2тхй_дюбкемхе_юбюпхимне */
	fputs( "ясюа2тхй_дюбкемхе_юбюпхимне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_PROVYER__VOZDUSHNUYU_PODUSHKU; /* ясюа2тхй_опнбепэ_бнгдсьмсч_ондсьйс */
	fputs( "ясюа2тхй_опнбепэ_бнгдсьмсч_ондсьйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_BLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA; /* ясюа2тхй_акнйхпнбйю_йнлюмд_оепелеыемхъ */
	fputs( "ясюа2тхй_акнйхпнбйю_йнлюмд_оепелеыемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RAZBLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA; /* ясюа2тхй_пюгакнйхпнбйю_йнлюмд_оепелеыемхъ */
	fputs( "ясюа2тхй_пюгакнйхпнбйю_йнлюмд_оепелеыемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_ZD_R_KARYETKI; /* ясюа2тхй_хглм_гд_R_йюперйх */
	fputs( "ясюа2тхй_хглм_гд_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA; /* ясюа2тхй_хглм_гд_W_опедлермнцн_ярнкхйю */
	fputs( "ясюа2тхй_хглм_гд_W_опедлермнцн_ярнкхйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DISK_ZAZHAT; /* ясюа2тхй_дхяй_гюфюр */
	fputs( "ясюа2тхй_дхяй_гюфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DISK_RAZZHAT; /* ясюа2тхй_дхяй_пюгфюр */
	fputs( "ясюа2тхй_дхяй_пюгфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_AVARIJNOYE_RAZZHATIYE_DISKA; /* ясюа2тхй_юбюпхимне_пюгфюрхе_дхяйю */
	fputs( "ясюа2тхй_юбюпхимне_пюгфюрхе_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OTKAZ_ZAZHIMA_DISKA; /* ясюа2тхй_нрйюг_гюфхлю_дхяйю */
	fputs( "ясюа2тхй_нрйюг_гюфхлю_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OTKAZ_RAZZHIMA_DISKA; /* ясюа2тхй_нрйюг_пюгфхлю_дхяйю */
	fputs( "ясюа2тхй_нрйюг_пюгфхлю_дхяйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSVYESCHYENIYE_DISKA_VKLYUCHYENO; /* ясюа2тхй_нябеыемхе_дхяйю_бйкчвемн */
	fputs( "ясюа2тхй_нябеыемхе_дхяйю_бйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSVYESCHYENIYE_DISKA_VYKLYUCHYENO; /* ясюа2тхй_нябеыемхе_дхяйю_бшйкчвемн */
	fputs( "ясюа2тхй_нябеыемхе_дхяйю_бшйкчвемн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__SVYAZ__S_MOKHA1212; /* ясюа2тхй_еярэ_ябъгэ_я_лную1212 */
	fputs( "ясюа2тхй_еярэ_ябъгэ_я_лную1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_SVYAZI_S_MOKHA1212; /* ясюа2тхй_мер_ябъгх_я_лную1212 */
	fputs( "ясюа2тхй_мер_ябъгх_я_лную1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__SVYAZ__S_MOKHA1214; /* ясюа2тхй_еярэ_ябъгэ_я_лную1214 */
	fputs( "ясюа2тхй_еярэ_ябъгэ_я_лную1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_SVYAZI_S_MOKHA1214; /* ясюа2тхй_мер_ябъгх_я_лную1214 */
	fputs( "ясюа2тхй_мер_ябъгх_я_лную1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1212; /* ясюа2тхй_еярэ_дхярюмжхнммне_сопюбкемхе_1212 */
	fputs( "ясюа2тхй_еярэ_дхярюмжхнммне_сопюбкемхе_1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1212; /* ясюа2тхй_мер_дхярюмжхнммнцн_сопюбкемхъ_1212 */
	fputs( "ясюа2тхй_мер_дхярюмжхнммнцн_сопюбкемхъ_1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1214; /* ясюа2тхй_еярэ_дхярюмжхнммне_сопюбкемхе_1214 */
	fputs( "ясюа2тхй_еярэ_дхярюмжхнммне_сопюбкемхе_1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1214; /* ясюа2тхй_мер_дхярюмжхнммнцн_сопюбкемхъ_1214 */
	fputs( "ясюа2тхй_мер_дхярюмжхнммнцн_сопюбкемхъ_1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_INITSIALIZATSIYA; /* ясюа2тхй_пефхл_хмхжхюкхгюжхъ */
	fputs( "ясюа2тхй_пефхл_хмхжхюкхгюжхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_RR; /* ясюа2тхй_пефхл_пп */
	fputs( "ясюа2тхй_пефхл_пп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_OTMYENA; /* ясюа2тхй_пефхл_нрлемю */
	fputs( "ясюа2тхй_пефхл_нрлемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_KONYETS_RABOTY; /* ясюа2тхй_пефхл_йнмеж_пюанрш */
	fputs( "ясюа2тхй_пефхл_йнмеж_пюанрш = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_USTANOVKA_GOTOVA_K_VYKLYUCHYENIYU; /* ясюа2тхй_сярюмнбйю_цнрнбю_й_бшйкчвемхч */
	fputs( "ясюа2тхй_сярюмнбйю_цнрнбю_й_бшйкчвемхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_KONYETS_KODOV_SPK; /* ясюа2тхй_йнмеж_йнднб_яой */
	fputs( "ясюа2тхй_йнмеж_йнднб_яой = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_FP_R_KARYETKI; /* ясюа2тхй_хглм_то_R_йюперйх */
	fputs( "ясюа2тхй_хглм_то_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_FP_W_PRYEDMYETNOGO_STOLIKA; /* ясюа2тхй_хглм_то_W_опедлермнцн_ярнкхйю */
	fputs( "ясюа2тхй_хглм_то_W_опедлермнцн_ярнкхйю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOMANDY_IZM_FP; /* йнлюмдш_хгл_то */
	fputs( "йнлюмдш_хгл_то = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_ZD_R_KARYETKI_VNYE_DIAPAZONA; /* ясюа2тхй_гд_R_йюперйх_бме_дхюоюгнмю */
	fputs( "ясюа2тхй_гд_R_йюперйх_бме_дхюоюгнмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_ZD_W_PRYEDMYETNOGO_STOLIKA_VNYE_DIAPAZONA; /* ясюа2тхй_гд_W_опедлермнцн_ярнкхйю_бме_дхюоюгнмю */
	fputs( "ясюа2тхй_гд_W_опедлермнцн_ярнкхйю_бме_дхюоюгнмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_VKLYUCHITYE_KOMPRYESSOR; /* ясюа2тхй_бйкчвхре_йнлопеяянп */
	fputs( "ясюа2тхй_бйкчвхре_йнлопеяянп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_1; /* хглм_мо_1 */
	fputs( "хглм_мо_1 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_N; /* хглм_мо_N */
	fputs( "хглм_мо_N = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSHIBKA_KODA_KOMANDY_OT_GIO; /* ясюа2тхй_ньхайю_йндю_йнлюмдш_нр_цхн */
	fputs( "ясюа2тхй_ньхайю_йндю_йнлюмдш_нр_цхн = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_RR; /* ясюа2тхй_ньхайю_гюопеыеммюъ_йнлюмдю_пефхлю_пп */
	fputs( "ясюа2тхй_ньхайю_гюопеыеммюъ_йнлюмдю_пефхлю_пп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_INITSIALIZATSII; /* ясюа2тхй_ньхайю_гюопеыеммюъ_йнлюмдю_пефхлю_хмхжхюкхгюжхх */
	fputs( "ясюа2тхй_ньхайю_гюопеыеммюъ_йнлюмдю_пефхлю_хмхжхюкхгюжхх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
