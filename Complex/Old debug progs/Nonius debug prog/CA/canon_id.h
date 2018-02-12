    
#define ODNA_SYEKUNDA /* C_0 - ндмю_яейсмдю */               10  
#define DVYE_SYEKUNDY /* C_1 - дбе_яейсмдш */             2*ODNA_SYEKUNDA
#define TRI_SYEKUNDY /* C_2 - рпх_яейсмдш */             3*ODNA_SYEKUNDA
#define PYAT__SYEKUND /* C_3 - оърэ_яейсмд */             5*ODNA_SYEKUNDA
#define DYESYAT__SYEKUND /* C_4 - деяърэ_яейсмд */          10*ODNA_SYEKUNDA
#define DVADTSAT__SYEKUND /* C_5 - дбюджюрэ_яейсмд */        20*ODNA_SYEKUNDA
#define TRIDTSAT__SYEKUND /* C_6 - рпхджюрэ_яейсмд */        30*ODNA_SYEKUNDA
#define ODNA_MINUTA /* C_7 - ндмю_лхмсрю */            60*ODNA_SYEKUNDA
#define DVYE_MINUTY /* C_8 - дбе_лхмсрш */             2*ODNA_MINUTA
#define PYAT__MINUT /* C_9 - оърэ_лхмср */             5*60*ODNA_SYEKUNDA
#define DYESYAT__MINUT /* C_10 - деяърэ_лхмср */			 10*ODNA_MINUTA
#define PYATNADTSAT__MINUT /* C_11 - оърмюджюрэ_лхмср */       15*ODNA_MINUTA
#define TRIDTSAT__MINUT /* C_12 - рпхджюрэ_лхмср */         30*ODNA_MINUTA

#define TAJMAUT_VOZD_PODUSHKI /* C_13 - рюилюср_бнгд_ондсьйх */		TRI_SYEKUNDY
#define TAJMAUT_NASOSA_VAKUUMNOGO /* C_14 - рюилюср_мюяняю_бюйсслмнцн */	DVADTSAT__SYEKUND
#define TAJMAUT_ZAZHIMA_DISKA /* C_15 - рюилюср_гюфхлю_дхяйю */		DVADTSAT__SYEKUND
#define TAJMAUT_RAZZHIMA_DISKA /* C_16 - рюилюср_пюгфхлю_дхяйю */		DVADTSAT__SYEKUND

#define TAJMAUT_NA_SRABATYVANIYE_KLAPANA_KARYETKI /* C_17 - рюилюср_мю_япюаюршбюмхе_йкюоюмю_йюперйх */          	TRI_SYEKUNDY   
#define TAJMAUT_NA_SRABATYVANIYE_KLAPANA_SHPINDYELYA_D /* C_18 - рюилюср_мю_япюаюршбюмхе_йкюоюмю_ьохмдекъ_д */       	TRI_SYEKUNDY   

#define TAJMAUT_NA_SVYAZ__S_GIO /* C_19 - рюилюср_мю_ябъгэ_я_цхн */  DYESYAT__SYEKUND

#define VKL /* C_20 - бйк */                1
#define VYK /* C_21 - бшй */               0
#define VYKL /* C_22 - бшйк */               0
#define OTKR /* C_23 - нрйп */              1
#define ZAKR /* C_24 - гюйп */          	0
#define YEST_ /* C_25 - еярэ */               1
#define NYET /* C_26 - мер */                0
#define NI_DA_NI_NYET /* C_27 - мх_дю_мх_мер */       2


#define MINIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_28 - лхмхлюкэмне_гюдюмхе_R_йюперйх */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_29 - люйяхлюкэмне_гюдюмхе_R_йюперйх */        200.0    

#define MINIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA /* C_30 - лхмхлюкэмне_гюдюмхе_W_опедлермнцн_ярнкхйю */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA /* C_31 - люйяхлюкэмне_гюдюмхе_W_опедлермнцн_ярнкхйю */        200.0     

enum EN0 {
    RYEZHIM_INITSIALIZATSII /* пефхл_хмхжхюкхгюжхх */ = 1,
    RYEZHIM_RR /* пефхл_пп */,
    RYEZHIM_OTMYENA /* пефхл_нрлемю */        ,
    RYEZHIM_KONYETS_RABOTY /* пефхл_йнмеж_пюанрш */,  
	KONYETS_KODOV_RYEZHIMOV /* йнмеж_йнднб_пефхлнб */       
       
};

enum EN1 {
    GIO2SUAB_RYEZHIM_OTMYENA /* цхн2ясюа_пефхл_нрлемю */ = KONYETS_KODOV_RYEZHIMOV,
    GIO2SUAB_RYEZHIM_KONYETS_RABOTY /* цхн2ясюа_пефхл_йнмеж_пюанрш */,  
	GIO2SUAB_ZAZHAT__DISK /* цхн2ясюа_гюфюрэ_дхяй */ , 
	GIO2SUAB_RAZZHAT__DISK /* цхн2ясюа_пюгфюрэ_дхяй */,
	GIO2SUAB_KO_ISPRAVNOST__VOZDUSHNYKH_PODUSHYEK /* цхн2ясюа_йн_хяопюбмнярэ_бнгдсьмшу_ондсьей */,
	GIO2SUAB_OTKAZ_VOZDUSHNYKH_PODUSHYEK /* цхн2ясюа_нрйюг_бнгдсьмшу_ондсьей */,
	GIO2SUAB_KARYETKU_V_POLOZHYENIYE_USTANOVKI_DISKA /* цхн2ясюа_йюперйс_б_онкнфемхе_сярюмнбйх_дхяйю */,
   	GIO2SUAB_KARYETKU_V_TSYENTR_VRASCHYENIYA /* цхн2ясюа_йюперйс_б_жемрп_бпюыемхъ */,
	GIO2SUAB_KARYETKU_V_ZADANNYJ_RADIUS /* цхн2ясюа_йюперйс_б_гюдюммши_пюдхся */,
	GIO2SUAB_STOP_KARYETKI /* цхн2ясюа_ярно_йюперйх */,
	GIO2SUAB_VKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU /* цхн2ясюа_бйк_юйрхбмне_онгхжхнмхпнбюмхе_он_бпюыемхч */,
	GIO2SUAB_VYKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU /* цхн2ясюа_бшйк_юйрхбмне_онгхжхнмхпнбюмхе_он_бпюыемхч */,
	GIO2SUAB_VKL_VRASCHYENIYE_PRYED_STOLIKA_V_ZD_W /* цхн2ясюа_бйк_бпюыемхе_опед_ярнкхйю_б_гд_W */,  
	GIO2SUAB_STOP_VRASCHYENIYA_PRYEDMYETNOGO_STOLIKA /* цхн2ясюа_ярно_бпюыемхъ_опедлермнцн_ярнкхйю */,
	GIO2SUAB_VKL_PODSVYETKU_DISKA /* цхн2ясюа_бйк_ондяберйс_дхяйю */,  
	GIO2SUAB_VYKL_PODSVYETKU_DISKA /* цхн2ясюа_бшйк_ондяберйс_дхяйю */,
	
	FIK2SUAB_YEST__SVYAZ__S_MOKHA1212 /* тхй2ясюа_еярэ_ябъгэ_я_лную1212 */,
	FIK2SUAB_NYET_SVYAZI_S_MOKHA1212 /* тхй2ясюа_мер_ябъгх_я_лную1212 */,
	FIK2SUAB_YEST__SVYAZ__S_MOKHA1214 /* тхй2ясюа_еярэ_ябъгэ_я_лную1214 */,
	FIK2SUAB_NYET_SVYAZI_S_MOKHA1214 /* тхй2ясюа_мер_ябъгх_я_лную1214 */,


	GIO2SUAB_IZMN_ZD_R_KARYETKI /* цхн2ясюа_хглм_гд_R_йюперйх */,
    GIO2SUAB_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA /* цхн2ясюа_хглм_гд_W_опедлермнцн_ярнкхйю */,	
	GIO2SUAB_KONYETS_KODOV_FIK /* цхн2ясюа_йнмеж_йнднб_тхй */	
	
	
	
};

enum EN2 {
	
	SUAB2FIK_DAVLYENIYE_V_NORMYE /* ясюа2тхй_дюбкемхе_б_мнпле */ = 0,
	SUAB2FIK_DAVLYENIYE_NIZHYE_NORMY /* ясюа2тхй_дюбкемхе_мхфе_мнплш */,
	SUAB2FIK_DAVLYENIYE_AVARIJNOYE /* ясюа2тхй_дюбкемхе_юбюпхимне */,
	
	SUAB2FIK_PROVYER__VOZDUSHNUYU_PODUSHKU /* ясюа2тхй_опнбепэ_бнгдсьмсч_ондсьйс */,
	SUAB2FIK_BLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA /* ясюа2тхй_акнйхпнбйю_йнлюмд_оепелеыемхъ */,
	SUAB2FIK_RAZBLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA /* ясюа2тхй_пюгакнйхпнбйю_йнлюмд_оепелеыемхъ */,
	SUAB2FIK_IZMN_ZD_R_KARYETKI /* ясюа2тхй_хглм_гд_R_йюперйх */,
	SUAB2FIK_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA /* ясюа2тхй_хглм_гд_W_опедлермнцн_ярнкхйю */,

	
	SUAB2FIK_DISK_ZAZHAT /* ясюа2тхй_дхяй_гюфюр */,
	SUAB2FIK_DISK_RAZZHAT /* ясюа2тхй_дхяй_пюгфюр */,
	SUAB2FIK_AVARIJNOYE_RAZZHATIYE_DISKA /* ясюа2тхй_юбюпхимне_пюгфюрхе_дхяйю */,
	SUAB2FIK_OTKAZ_ZAZHIMA_DISKA /* ясюа2тхй_нрйюг_гюфхлю_дхяйю */,
	SUAB2FIK_OTKAZ_RAZZHIMA_DISKA /* ясюа2тхй_нрйюг_пюгфхлю_дхяйю */,
	SUAB2FIK_OSVYESCHYENIYE_DISKA_VKLYUCHYENO /* ясюа2тхй_нябеыемхе_дхяйю_бйкчвемн */,
	SUAB2FIK_OSVYESCHYENIYE_DISKA_VYKLYUCHYENO /* ясюа2тхй_нябеыемхе_дхяйю_бшйкчвемн */,
	
	
	SUAB2FIK_YEST__SVYAZ__S_MOKHA1212 /* ясюа2тхй_еярэ_ябъгэ_я_лную1212 */,
	SUAB2FIK_NYET_SVYAZI_S_MOKHA1212 /* ясюа2тхй_мер_ябъгх_я_лную1212 */,
	SUAB2FIK_YEST__SVYAZ__S_MOKHA1214 /* ясюа2тхй_еярэ_ябъгэ_я_лную1214 */,
	SUAB2FIK_NYET_SVYAZI_S_MOKHA1214 /* ясюа2тхй_мер_ябъгх_я_лную1214 */,
	
	SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1212 /* ясюа2тхй_еярэ_дхярюмжхнммне_сопюбкемхе_1212 */,
	SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1212 /* ясюа2тхй_мер_дхярюмжхнммнцн_сопюбкемхъ_1212 */,
	SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1214 /* ясюа2тхй_еярэ_дхярюмжхнммне_сопюбкемхе_1214 */,
	SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1214 /* ясюа2тхй_мер_дхярюмжхнммнцн_сопюбкемхъ_1214 */,
	SUAB2FIK_RYEZHIM_INITSIALIZATSIYA /* ясюа2тхй_пефхл_хмхжхюкхгюжхъ */,
	SUAB2FIK_RYEZHIM_RR /* ясюа2тхй_пефхл_пп */,
	SUAB2FIK_RYEZHIM_OTMYENA /* ясюа2тхй_пефхл_нрлемю */,
	SUAB2FIK_RYEZHIM_KONYETS_RABOTY /* ясюа2тхй_пефхл_йнмеж_пюанрш */,
	SUAB2FIK_USTANOVKA_GOTOVA_K_VYKLYUCHYENIYU /* ясюа2тхй_сярюмнбйю_цнрнбю_й_бшйкчвемхч */,
	SUAB2FIK_KONYETS_KODOV_SPK /* ясюа2тхй_йнмеж_йнднб_яой */ 
 
};	


enum EN3 {
	SUAB2FIK_IZMN_FP_R_KARYETKI /* ясюа2тхй_хглм_то_R_йюперйх */ = SUAB2FIK_KONYETS_KODOV_SPK + 1,
	SUAB2FIK_IZMN_FP_W_PRYEDMYETNOGO_STOLIKA /* ясюа2тхй_хглм_то_W_опедлермнцн_ярнкхйю */,
	KOMANDY_IZM_FP /* йнлюмдш_хгл_то */ = SUAB2FIK_IZMN_FP_W_PRYEDMYETNOGO_STOLIKA 	
 	
};

enum EN4 {
	SUAB2FIK_ZD_R_KARYETKI_VNYE_DIAPAZONA /* ясюа2тхй_гд_R_йюперйх_бме_дхюоюгнмю */ = KOMANDY_IZM_FP + 1,
	SUAB2FIK_ZD_W_PRYEDMYETNOGO_STOLIKA_VNYE_DIAPAZONA /* ясюа2тхй_гд_W_опедлермнцн_ярнкхйю_бме_дхюоюгнмю */

};

enum EN5 {                    
   
	
	SUAB2FIK_VKLYUCHITYE_KOMPRYESSOR /* ясюа2тхй_бйкчвхре_йнлопеяянп */ = SUAB2FIK_ZD_W_PRYEDMYETNOGO_STOLIKA_VNYE_DIAPAZONA +1



};	


enum EN6 { 
	IZMN_NP_1 /* хглм_мо_1 */ = SUAB2FIK_VKLYUCHITYE_KOMPRYESSOR + 1,
	IZMN_NP_N /* хглм_мо_N */

};
enum EN7 {
    SUAB2FIK_OSHIBKA_KODA_KOMANDY_OT_GIO /* ясюа2тхй_ньхайю_йндю_йнлюмдш_нр_цхн */ = IZMN_NP_N + 1,
	SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_RR /* ясюа2тхй_ньхайю_гюопеыеммюъ_йнлюмдю_пефхлю_пп */,
	SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_INITSIALIZATSII /* ясюа2тхй_ньхайю_гюопеыеммюъ_йнлюмдю_пефхлю_хмхжхюкхгюжхх */	 
	 
	 
	 
};