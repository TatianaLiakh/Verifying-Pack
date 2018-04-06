#include <stdio.h>
#include "voc_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("voc_constants.cfg","w");
	i = VKL; /* C_0 - бйк */
	fputs( "бйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - бшйк */
	fputs( "бшйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MINIMAL_NOYE_ZADANIYE_R_KARYETKI; /* C_2 - лхмхлюкэмне_гюдюмхе_R_йюперйх */
	fputs( "лхмхлюкэмне_гюдюмхе_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI; /* C_3 - люйяхлюкэмне_гюдюмхе_R_йюперйх */
	fputs( "люйяхлюкэмне_гюдюмхе_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MINIMAL_NOYE_ZADANIYE_W_UglovojSkorosti; /* C_4 - лхмхлюкэмне_гюдюмхе_W_сЦКНБНИяЙНПНЯРХ */
	fputs( "лхмхлюкэмне_гюдюмхе_W_сЦКНБНИяЙНПНЯРХ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NOYE_ZADANIYE_W_UglovojSkorosti; /* C_5 - люйяхлюкэмне_гюдюмхе_W_сЦКНБНИяЙНПНЯРХ */
	fputs( "люйяхлюкэмне_гюдюмхе_W_сЦКНБНИяЙНПНЯРХ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = R_PO_UMOLCHANIYU; /* C_6 - R_он_слнквюмхч */
	fputs( "R_он_слнквюмхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = W_PO_UMOLCHANIYU; /* C_7 - W_он_слнквюмхч */
	fputs( "W_он_слнквюмхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = R_FP_PO_UMOLCHANIYU; /* C_8 - R_то_он_слнквюмхч */
	fputs( "R_то_он_слнквюмхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FP_W_PO_UMOLCHANIYU; /* C_9 - то_W_он_слнквюмхч */
	fputs( "то_W_он_слнквюмхч = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_VOZD_PODUSHKI; /* C_10 - рюилюср_бнгд_ондсьйх */
	fputs( "рюилюср_бнгд_ондсьйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_KLAPANOV; /* C_11 - рюилюср_йкюоюмнб */
	fputs( "рюилюср_йкюоюмнб = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_NORMU; /* йнл_бундмюъ_реяр_дюбкемхе_б_мнплс */
	fputs( "йнл_бундмюъ_реяр_дюбкемхе_б_мнплс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_NIZKOYE; /* йнл_бундмюъ_реяр_дюбкемхе_б_мхгйне */
	fputs( "йнл_бундмюъ_реяр_дюбкемхе_б_мхгйне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_AVARINOYE; /* йнл_бундмюъ_реяр_дюбкемхе_б_юбюпхмне */
	fputs( "йнл_бундмюъ_реяр_дюбкемхе_б_юбюпхмне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_OPORA_ISPRAVNA; /* йнл_бундмюъ_реяр_нонпю_хяопюбмю */
	fputs( "йнл_бундмюъ_реяр_нонпю_хяопюбмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_OPORA_OTKAZ_VKLYUCHYENIYA; /* йнл_бундмюъ_реяр_нонпю_нрйюг_бйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_нонпю_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_OPORA_OTKAZ_VYKLYUCHYENIYA; /* йнл_бундмюъ_реяр_нонпю_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_нонпю_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KARYETKA_ISPRAVNA; /* йнл_бундмюъ_реяр_йюперйю_хяопюбмю */
	fputs( "йнл_бундмюъ_реяр_йюперйю_хяопюбмю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KARYETKA_OTKAZ_VKLYUCHYENIYA; /* йнл_бундмюъ_реяр_йюперйю_нрйюг_бйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_йюперйю_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KARYETKA_OTKAZ_VYKLYUCHYENIYA; /* йнл_бундмюъ_реяр_йюперйю_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_йюперйю_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_SHPINDYEL__ISPRAVYEN; /* йнл_бундмюъ_реяр_ьохмдекэ_хяопюбем */
	fputs( "йнл_бундмюъ_реяр_ьохмдекэ_хяопюбем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_SHPINDYEL__OTKAZ_VKLYUCHYENIYA; /* йнл_бундмюъ_реяр_ьохмдекэ_нрйюг_бйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_ьохмдекэ_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_SHPINDYEL__OTKAZ_VYKLYUCHYENIYA; /* йнл_бундмюъ_реяр_ьохмдекэ_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_ьохмдекэ_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_SVYETODIOD_ISPRAVYEN; /* йнл_бундмюъ_реяр_яберндхнд_хяопюбем */
	fputs( "йнл_бундмюъ_реяр_яберндхнд_хяопюбем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VKLYUCHYENIYA; /* йнл_бундмюъ_реяр_яберндхнд_нрйюг_бйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_яберндхнд_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VYKLYUCHYENIYA; /* йнл_бундмюъ_реяр_яберндхнд_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_яберндхнд_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_ISPRAVYEN; /* йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_хяопюбем */
	fputs( "йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_хяопюбем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKAZ_VKLYUCHYENIYA; /* йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_нрйюг_бйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKAZ_VYKLYUCHYENIYA; /* йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_ISPRAVYEN; /* йнл_бундмюъ_реяр_йкюоюм_бюйсслю_хяопюбем */
	fputs( "йнл_бундмюъ_реяр_йкюоюм_бюйсслю_хяопюбем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKAZ_VKLYUCHYENIYA; /* йнл_бундмюъ_реяр_йкюоюм_бюйсслю_нрйюг_бйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_йкюоюм_бюйсслю_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKAZ_VYKLYUCHYENIYA; /* йнл_бундмюъ_реяр_йкюоюм_бюйсслю_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бундмюъ_реяр_йкюоюм_бюйсслю_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE; /* йнл_бундмюъ_реяр_йнмрпнкэмне_яннаыемхе */
	fputs( "йнл_бундмюъ_реяр_йнмрпнкэмне_яннаыемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_IZMN_R_KARYETKI; /* йнл_бшундмюъ_реяр_хглм_R_йюперйх */
	fputs( "йнл_бшундмюъ_реяр_хглм_R_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_IZMN_W_KARYETKI; /* йнл_бшундмюъ_реяр_хглм_W_йюперйх */
	fputs( "йнл_бшундмюъ_реяр_хглм_W_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_IZMN_R_FP_KARYETKI; /* йнл_бшундмюъ_реяр_хглм_R_то_йюперйх */
	fputs( "йнл_бшундмюъ_реяр_хглм_R_то_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_IZMN_W_FP_KARYETKI; /* йнл_бшундмюъ_реяр_хглм_W_то_йюперйх */
	fputs( "йнл_бшундмюъ_реяр_хглм_W_то_йюперйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_DAVLYENIYE_V_NORMYE; /* йнл_бшундмюъ_реяр_дюбкемхе_б_мнпле */
	fputs( "йнл_бшундмюъ_реяр_дюбкемхе_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_DAVLYENIYE_NIZKOYE; /* йнл_бшундмюъ_реяр_дюбкемхе_мхгйне */
	fputs( "йнл_бшундмюъ_реяр_дюбкемхе_мхгйне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_DAVYELYENIYE_AVARIJNOYE; /* йнл_бшундмюъ_реяр_дюбекемхе_юбюпхимне */
	fputs( "йнл_бшундмюъ_реяр_дюбекемхе_юбюпхимне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_OSHIBKA_KODA_KOMANDY_OT_GUI; /* йнл_бшундмюъ_ньхайю_йндю_йнлюмдш_нр_цсх */
	fputs( "йнл_бшундмюъ_ньхайю_йндю_йнлюмдш_нр_цсх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_OPORU; /* йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_нонпс */
	fputs( "йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_нонпс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_NA_OPORYE_STOLA_AVARIJNOYE_DAVLYENIYE; /* йнл_бшундмюъ_реяр_мю_нонпе_ярнкю_юбюпхимне_дюбкемхе */
	fputs( "йнл_бшундмюъ_реяр_мю_нонпе_ярнкю_юбюпхимне_дюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_OPORU; /* йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_нонпс */
	fputs( "йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_нонпс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_KARYETKU; /* йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_йюперйс */
	fputs( "йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_йюперйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_NA_KARYETKYE_AVARIJNOYE_DAVLYENIYE; /* йнл_бшундмюъ_реяр_мю_йюперйе_юбюпхимне_дюбкемхе */
	fputs( "йнл_бшундмюъ_реяр_мю_йюперйе_юбюпхимне_дюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_KARYETKU; /* йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_йюперйс */
	fputs( "йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_йюперйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_SHPINDYEL_; /* йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_ьохмдекэ */
	fputs( "йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_ьохмдекэ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_PRYEDUPRYEZHDYENIYE_VOZDUKH_PODAN_NA_SHPINDYEL__NA_KA; /* йнл_бшундмюъ_реяр_опедсопефдемхе_бнгдсу_ондюм_мю_ьохмдекэ_мю_йю */
	fputs( "йнл_бшундмюъ_реяр_опедсопефдемхе_бнгдсу_ондюм_мю_ьохмдекэ_мю_йю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_PRYEDUPRYEZHDYENIYE_VOZDUKH_PODAN_NA_SHPINDYEL__NA_OP; /* йнл_бшундмюъ_реяр_опедсопефдемхе_бнгдсу_ондюм_мю_ьохмдекэ_мю_но */
	fputs( "йнл_бшундмюъ_реяр_опедсопефдемхе_бнгдсу_ондюм_мю_ьохмдекэ_мю_но = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_NA_SHPINDYELYE_AVARIJNOYE_DAVLYENIYE; /* йнл_бшундмюъ_реяр_мю_ьохмдеке_юбюпхимне_дюбкемхе */
	fputs( "йнл_бшундмюъ_реяр_мю_ьохмдеке_юбюпхимне_дюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_SHPINDYEL_; /* йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_ьохмдекэ */
	fputs( "йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_ьохмдекэ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_PITANIYE_PODANO_NA_LAZYER; /* йнл_бшундмюъ_реяр_охрюмхе_ондюмн_мю_кюгеп */
	fputs( "йнл_бшундмюъ_реяр_охрюмхе_ондюмн_мю_кюгеп = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_PITANIYE_NA_LAZYERYE_NYET; /* йнл_бшундмюъ_реяр_охрюмхе_мю_кюгепе_мер */
	fputs( "йнл_бшундмюъ_реяр_охрюмхе_мю_кюгепе_мер = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_SVYETODIOD_VKLYUCHYEN; /* йнл_бшундмюъ_реяр_яберндхнд_бйкчвем */
	fputs( "йнл_бшундмюъ_реяр_яберндхнд_бйкчвем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_SVYETODIOD_VYKLYUCHYEN; /* йнл_бшундмюъ_реяр_яберндхнд_бшйкчвем */
	fputs( "йнл_бшундмюъ_реяр_яберндхнд_бшйкчвем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VKLYUCHYENIYA; /* йнл_бшундмюъ_реяр_яберндхнд_нрйюг_бйкчвемхъ */
	fputs( "йнл_бшундмюъ_реяр_яберндхнд_нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VYKLYUCHYENIYA; /* йнл_бшундмюъ_реяр_яберндхнд_нрйюг_бшйкчвемхъ */
	fputs( "йнл_бшундмюъ_реяр_яберндхнд_нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_NASOS_VYKLYUCHYEN; /* йнл_бшундмюъ_реяр_мюяня_бшйкчвем */
	fputs( "йнл_бшундмюъ_реяр_мюяня_бшйкчвем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_KLAPAN_NASOS_VKLYUCHYEN; /* йнл_бшундмюъ_реяр_йкюоюм_мюяня_бйкчвем */
	fputs( "йнл_бшундмюъ_реяр_йкюоюм_мюяня_бйкчвем = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKRYT; /* йнл_бшундмюъ_реяр_йкюоюм_юрлнятепш_нрйпшр */
	fputs( "йнл_бшундмюъ_реяр_йкюоюм_юрлнятепш_нрйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_ZAKRYT; /* йнл_бшундмюъ_реяр_йкюоюм_юрлнятепш_гюйпшр */
	fputs( "йнл_бшундмюъ_реяр_йкюоюм_юрлнятепш_гюйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKRYT; /* йнл_бшундмюъ_реяр_йкюоюм_бюйсслю_нрйпшр */
	fputs( "йнл_бшундмюъ_реяр_йкюоюм_бюйсслю_нрйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_KLAPAN_VAKUUMA_ZAKRYT; /* йнл_бшундмюъ_реяр_йкюоюм_бюйсслю_гюйпшр */
	fputs( "йнл_бшундмюъ_реяр_йкюоюм_бюйсслю_гюйпшр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_OBA_KLAPANA_OTKRYTY_DISK_RAZAZHAT; /* йнл_бшундмюъ_реяр_наю_йкюоюмю_нрйпшрш_дхяй_пюгюфюр */
	fputs( "йнл_бшундмюъ_реяр_наю_йкюоюмю_нрйпшрш_дхяй_пюгюфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VAKUUM_OTKRYT_ATMOSFYERA_ZAKRYT_DISK_ZAZHAT; /* йнл_бшундмюъ_реяр_бюйссл_нрйпшр_юрлнятепю_гюйпшр_дхяй_гюфюр */
	fputs( "йнл_бшундмюъ_реяр_бюйссл_нрйпшр_юрлнятепю_гюйпшр_дхяй_гюфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VAKUUM_OTKRYT_ATMOSFYERA_ZAKRYT_DISK_RAZZHAT; /* йнл_бшундмюъ_реяр_бюйссл_нрйпшр_юрлнятепю_гюйпшр_дхяй_пюгфюр */
	fputs( "йнл_бшундмюъ_реяр_бюйссл_нрйпшр_юрлнятепю_гюйпшр_дхяй_пюгфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_OTKRYT_DISK_RAZAZHAT; /* йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_нрйпшр_дхяй_пюгюфюр */
	fputs( "йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_нрйпшр_дхяй_пюгюфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_ZAKRYT_DISK_ZAZHAT; /* йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_гюйпшр_дхяй_гюфюр */
	fputs( "йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_гюйпшр_дхяй_гюфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_ZAKRYT_DISK_RAZZHAT; /* йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_гюйпшр_дхяй_пюгфюр */
	fputs( "йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_гюйпшр_дхяй_пюгфюр = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM_VYKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE; /* йнл_бшундмюъ_реяр_йнмрпнкэмне_яннаыемхе */
	fputs( "йнл_бшундмюъ_реяр_йнмрпнкэмне_яннаыемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DAVLYENIYE_AVARIJNOYE; /* дюбкемхе_юбюпхимне */
	fputs( "дюбкемхе_юбюпхимне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DAVLYENIYE_NIZKOYE; /* дюбкемхе_мхгйне */
	fputs( "дюбкемхе_мхгйне = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DAVLYENIYE_V_NORMYE; /* дюбкемхе_б_мнпле */
	fputs( "дюбкемхе_б_мнпле = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ISPRAVNOST_; /* хяопюбмнярэ */
	fputs( "хяопюбмнярэ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OTKAZ_VKLYUCHYENIYA; /* нрйюг_бйкчвемхъ */
	fputs( "нрйюг_бйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OTKAZ_VYKLYUCHYENIYA; /* нрйюг_бшйкчвемхъ */
	fputs( "нрйюг_бшйкчвемхъ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
