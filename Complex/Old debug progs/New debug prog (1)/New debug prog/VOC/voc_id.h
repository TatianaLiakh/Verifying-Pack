    

#define VKL /* C_0 - бйк */                1
#define VYKL /* C_1 - бшйк */               0
#define MINIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_2 - лхмхлюкэмне_гюдюмхе_R_йюперйх */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_3 - люйяхлюкэмне_гюдюмхе_R_йюперйх */        200.0    

#define MINIMAL_NOYE_ZADANIYE_W_UglovojSkorosti /* C_4 - лхмхлюкэмне_гюдюмхе_W_сЦКНБНИяЙНПНЯРХ */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_W_UglovojSkorosti /* C_5 - люйяхлюкэмне_гюдюмхе_W_сЦКНБНИяЙНПНЯРХ */        200.0     


#define R_PO_UMOLCHANIYU /* C_6 - R_он_слнквюмхч */ 0.0
#define W_PO_UMOLCHANIYU /* C_7 - W_он_слнквюмхч */ 0.0
#define R_FP_PO_UMOLCHANIYU /* C_8 - R_то_он_слнквюмхч */ 0.0
#define FP_W_PO_UMOLCHANIYU /* C_9 - то_W_он_слнквюмхч */ 0.0

#define TAJMAUT_VOZD_PODUSHKI /* C_10 - рюилюср_бнгд_ондсьйх */ 10
#define TAJMAUT_KLAPANOV /* C_11 - рюилюср_йкюоюмнб */ 10


enum EN0 {
KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_NORMU /* йнл_бундмюъ_реяр_дюбкемхе_б_мнплс */,
KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_NIZKOYE /* йнл_бундмюъ_реяр_дюбкемхе_б_мхгйне */,
KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_AVARINOYE /* йнл_бундмюъ_реяр_дюбкемхе_б_юбюпхмне */,
KOM_VKHODNAYA_TYEST_OPORA_ISPRAVNA /* йнл_бундмюъ_реяр_нонпю_хяопюбмю */,
KOM_VKHODNAYA_TYEST_OPORA_OTKAZ_VKLYUCHYENIYA /* йнл_бундмюъ_реяр_нонпю_нрйюг_бйкчвемхъ */,
KOM_VKHODNAYA_TYEST_OPORA_OTKAZ_VYKLYUCHYENIYA /* йнл_бундмюъ_реяр_нонпю_нрйюг_бшйкчвемхъ */,
KOM_VKHODNAYA_TYEST_KARYETKA_ISPRAVNA /* йнл_бундмюъ_реяр_йюперйю_хяопюбмю */,
KOM_VKHODNAYA_TYEST_KARYETKA_OTKAZ_VKLYUCHYENIYA /* йнл_бундмюъ_реяр_йюперйю_нрйюг_бйкчвемхъ */,
KOM_VKHODNAYA_TYEST_KARYETKA_OTKAZ_VYKLYUCHYENIYA /* йнл_бундмюъ_реяр_йюперйю_нрйюг_бшйкчвемхъ */,
KOM_VKHODNAYA_TYEST_SHPINDYEL__ISPRAVYEN /* йнл_бундмюъ_реяр_ьохмдекэ_хяопюбем */,
KOM_VKHODNAYA_TYEST_SHPINDYEL__OTKAZ_VKLYUCHYENIYA /* йнл_бундмюъ_реяр_ьохмдекэ_нрйюг_бйкчвемхъ */,
KOM_VKHODNAYA_TYEST_SHPINDYEL__OTKAZ_VYKLYUCHYENIYA /* йнл_бундмюъ_реяр_ьохмдекэ_нрйюг_бшйкчвемхъ */,
KOM_VKHODNAYA_TYEST_SVYETODIOD_ISPRAVYEN /* йнл_бундмюъ_реяр_яберндхнд_хяопюбем */,
KOM_VKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VKLYUCHYENIYA /* йнл_бундмюъ_реяр_яберндхнд_нрйюг_бйкчвемхъ */,
KOM_VKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VYKLYUCHYENIYA /* йнл_бундмюъ_реяр_яберндхнд_нрйюг_бшйкчвемхъ */,
KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_ISPRAVYEN /* йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_хяопюбем */,
KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKAZ_VKLYUCHYENIYA /* йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_нрйюг_бйкчвемхъ */,
KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKAZ_VYKLYUCHYENIYA /* йнл_бундмюъ_реяр_йкюоюм_юрлнятепш_нрйюг_бшйкчвемхъ */,
KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_ISPRAVYEN /* йнл_бундмюъ_реяр_йкюоюм_бюйсслю_хяопюбем */,
KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKAZ_VKLYUCHYENIYA /* йнл_бундмюъ_реяр_йкюоюм_бюйсслю_нрйюг_бйкчвемхъ */,
KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKAZ_VYKLYUCHYENIYA /* йнл_бундмюъ_реяр_йкюоюм_бюйсслю_нрйюг_бшйкчвемхъ */,

KOM_VKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE /* йнл_бундмюъ_реяр_йнмрпнкэмне_яннаыемхе */

};

enum EN1 {
	KOM_VYKHODNAYA_TYEST_IZMN_R_KARYETKI /* йнл_бшундмюъ_реяр_хглм_R_йюперйх */ = KOM_VKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE + 1, 
	KOM_VYKHODNAYA_TYEST_IZMN_W_KARYETKI /* йнл_бшундмюъ_реяр_хглм_W_йюперйх */,  		
	KOM_VYKHODNAYA_TYEST_IZMN_R_FP_KARYETKI /* йнл_бшундмюъ_реяр_хглм_R_то_йюперйх */,
	KOM_VYKHODNAYA_TYEST_IZMN_W_FP_KARYETKI /* йнл_бшундмюъ_реяр_хглм_W_то_йюперйх */,
	KOM_VYKHODNAYA_TYEST_DAVLYENIYE_V_NORMYE /* йнл_бшундмюъ_реяр_дюбкемхе_б_мнпле */,
	KOM_VYKHODNAYA_TYEST_DAVLYENIYE_NIZKOYE /* йнл_бшундмюъ_реяр_дюбкемхе_мхгйне */,
	KOM_VYKHODNAYA_TYEST_DAVYELYENIYE_AVARIJNOYE /* йнл_бшундмюъ_реяр_дюбекемхе_юбюпхимне */,
	KOM_VYKHODNAYA_OSHIBKA_KODA_KOMANDY_OT_GUI /* йнл_бшундмюъ_ньхайю_йндю_йнлюмдш_нр_цсх */,
	KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_OPORU /* йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_нонпс */,
	KOM_VYKHODNAYA_TYEST_NA_OPORYE_STOLA_AVARIJNOYE_DAVLYENIYE /* йнл_бшундмюъ_реяр_мю_нонпе_ярнкю_юбюпхимне_дюбкемхе */,
	KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_OPORU /* йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_нонпс */,
	KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_KARYETKU /* йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_йюперйс */,
	KOM_VYKHODNAYA_TYEST_NA_KARYETKYE_AVARIJNOYE_DAVLYENIYE /* йнл_бшундмюъ_реяр_мю_йюперйе_юбюпхимне_дюбкемхе */,
	KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_KARYETKU /* йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_йюперйс */,
	KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_SHPINDYEL_ /* йнл_бшундмюъ_реяр_бнгдсу_ондюм_мю_ьохмдекэ */,
	KOM_VYKHODNAYA_TYEST_PRYEDUPRYEZHDYENIYE_VOZDUKH_PODAN_NA_SHPINDYEL__NA_KA /* йнл_бшундмюъ_реяр_опедсопефдемхе_бнгдсу_ондюм_мю_ьохмдекэ_мю_йю */,
	KOM_VYKHODNAYA_TYEST_PRYEDUPRYEZHDYENIYE_VOZDUKH_PODAN_NA_SHPINDYEL__NA_OP /* йнл_бшундмюъ_реяр_опедсопефдемхе_бнгдсу_ондюм_мю_ьохмдекэ_мю_но */,
	KOM_VYKHODNAYA_TYEST_NA_SHPINDYELYE_AVARIJNOYE_DAVLYENIYE /* йнл_бшундмюъ_реяр_мю_ьохмдеке_юбюпхимне_дюбкемхе */,
	KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_SHPINDYEL_ /* йнл_бшундмюъ_реяр_бшйкчвемю_ондювю_бнгдсую_мю_ьохмдекэ */,
	KOM_VYKHODNAYA_TYEST_PITANIYE_PODANO_NA_LAZYER /* йнл_бшундмюъ_реяр_охрюмхе_ондюмн_мю_кюгеп */,
	KOM_VYKHODNAYA_TYEST_PITANIYE_NA_LAZYERYE_NYET /* йнл_бшундмюъ_реяр_охрюмхе_мю_кюгепе_мер */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_VKLYUCHYEN /* йнл_бшундмюъ_реяр_яберндхнд_бйкчвем */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_VYKLYUCHYEN /* йнл_бшундмюъ_реяр_яберндхнд_бшйкчвем */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VKLYUCHYENIYA /* йнл_бшундмюъ_реяр_яберндхнд_нрйюг_бйкчвемхъ */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VYKLYUCHYENIYA /* йнл_бшундмюъ_реяр_яберндхнд_нрйюг_бшйкчвемхъ */,
	KOM_VYKHODNAYA_TYEST_NASOS_VYKLYUCHYEN /* йнл_бшундмюъ_реяр_мюяня_бшйкчвем */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_NASOS_VKLYUCHYEN /* йнл_бшундмюъ_реяр_йкюоюм_мюяня_бйкчвем */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKRYT /* йнл_бшундмюъ_реяр_йкюоюм_юрлнятепш_нрйпшр */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_ZAKRYT /* йнл_бшундмюъ_реяр_йкюоюм_юрлнятепш_гюйпшр */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKRYT /* йнл_бшундмюъ_реяр_йкюоюм_бюйсслю_нрйпшр */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_VAKUUMA_ZAKRYT /* йнл_бшундмюъ_реяр_йкюоюм_бюйсслю_гюйпшр */,
	KOM_VYKHODNAYA_TYEST_OBA_KLAPANA_OTKRYTY_DISK_RAZAZHAT /* йнл_бшундмюъ_реяр_наю_йкюоюмю_нрйпшрш_дхяй_пюгюфюр */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_OTKRYT_ATMOSFYERA_ZAKRYT_DISK_ZAZHAT /* йнл_бшундмюъ_реяр_бюйссл_нрйпшр_юрлнятепю_гюйпшр_дхяй_гюфюр */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_OTKRYT_ATMOSFYERA_ZAKRYT_DISK_RAZZHAT /* йнл_бшундмюъ_реяр_бюйссл_нрйпшр_юрлнятепю_гюйпшр_дхяй_пюгфюр */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_OTKRYT_DISK_RAZAZHAT /* йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_нрйпшр_дхяй_пюгюфюр */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_ZAKRYT_DISK_ZAZHAT /* йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_гюйпшр_дхяй_гюфюр */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_ZAKRYT_DISK_RAZZHAT /* йнл_бшундмюъ_реяр_бюйссл_гюйпшр_юрлнятепю_гюйпшр_дхяй_пюгфюр */,
	KOM_VYKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE /* йнл_бшундмюъ_реяр_йнмрпнкэмне_яннаыемхе */ 
  
 };
 
 
 
 enum EN2 {
	DAVLYENIYE_AVARIJNOYE /* дюбкемхе_юбюпхимне */,
	DAVLYENIYE_NIZKOYE /* дюбкемхе_мхгйне */,
	DAVLYENIYE_V_NORMYE /* дюбкемхе_б_мнпле */
 
 };
 
 enum EN3 {
	ISPRAVNOST_ /* хяопюбмнярэ */,
	OTKAZ_VKLYUCHYENIYA /* нрйюг_бйкчвемхъ */,
	OTKAZ_VYKLYUCHYENIYA /* нрйюг_бшйкчвемхъ */

};