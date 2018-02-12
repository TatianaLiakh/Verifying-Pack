    
#define T0_1 /* C_0 - р0_1 */                       0  
#define ODNA_SYEKUNDA /* C_1 - ндмю_яейсмдю */               10  
#define DVYE_SYEKUNDY /* C_2 - дбе_яейсмдш */             2*ODNA_SYEKUNDA
#define TRI_SYEKUNDY /* C_3 - рпх_яейсмдш */             3*ODNA_SYEKUNDA
#define TAJMAUT_NA_DOSTOVYERNOST_ /* C_4 - рюилюср_мю_днярнбепмнярэ */ DVYE_SYEKUNDY
#define PYAT__SYEKUND /* C_5 - оърэ_яейсмд */             5*ODNA_SYEKUNDA
#define MAKSIMAL_NAYA_DLITYEL_NOST__OTSUTSTVIYA_DOSTOVYERNOSTI /* C_6 - люйяхлюкэмюъ_дкхрекэмнярэ_нрясрярбхъ_днярнбепмнярх */ PYAT__SYEKUND

#define DYESYAT__SYEKUND /* C_7 - деяърэ_яейсмд */          10*ODNA_SYEKUNDA
#define DVADTSAT__SYEKUND /* C_8 - дбюджюрэ_яейсмд */        20*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_ZAT_VAK /* C_9 - рюилюср_мю_япюаюршбюмхе_гюр_бюй */			PYAT__SYEKUND	
#define TAJMAUT_NA_SRABATYVANIYE_SAPUNA /* C_10 - рюилюср_мю_япюаюршбюмхе_яюосмю */           	TRI_SYEKUNDY   
#define TAJMAUT_NA_SRABATYVANIYE_USTR_PLAV_PUSKA /* C_11 - рюилюср_мю_япюаюршбюмхе_сярп_окюб_осяйю */   3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VAK_NASOSA /* C_12 - рюилюср_мю_япюаюршбюмхе_бюй_мюяняю */ 		3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VYENTILYATORA /* C_13 - рюилюср_мю_япюаюршбюмхе_бемрхкърнпю */		PYAT__SYEKUND
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_T /* C_14 - рюилюср_мю_япюаюршбюмхе_пец_р */				3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_UR /* C_15 - рюилюср_мю_япюаюршбюмхе_пец_сп */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_NASOS_OKHL /* C_16 - рюилюср_мю_япюаюршбюмхе_мюяня_нук */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SVYAZ__S_GUI /* C_17 - рюилюср_мю_ябъгэ_я_цсх */  DYESYAT__SYEKUND
#define ODNA_MINUTA /* C_18 - ндмю_лхмсрю */          60*ODNA_SYEKUNDA
#define DVYE_MINUTY /* C_19 - дбе_лхмсрш */          2*ODNA_MINUTA
#define PYAT__MINUT /* C_20 - оърэ_лхмср */          5*60*ODNA_SYEKUNDA
#define DYESYAT__MINUT /* C_21 - деяърэ_лхмср */			10*ODNA_MINUTA
#define TRIDTSAT__MINUT /* C_22 - рпхджюрэ_лхмср */          30*ODNA_MINUTA
#define PYATNADTSAT__MINUT /* C_23 - оърмюджюрэ_лхмср */          15*ODNA_MINUTA
#define TAJMAUT_ZADYERZHKA_NA_OTKACHKU /* C_24 - рюилюср_гюдепфйю_мю_нрйювйс */ DYESYAT__SYEKUND

#define VKL /* C_25 - бйк */                1
#define VYK /* C_26 - бшй */               0
#define OTKR /* C_27 - нрйп */              1
#define ZAKR /* C_28 - гюйп */          	0
#define YEST_ /* C_29 - еярэ */               1
#define NYET /* C_30 - мер */                0
#define NIZHYE_NORMY /* C_31 - мхфе_мнплш */		0
#define NORMA /* C_32 - мнплю */              1
#define VYSHYE_NORMY /* C_33 - бшье_мнплш */		2
#define VNYE_NORMY /* C_34 - бме_мнплш */			0
#define DOSTOVYERNO /* C_35 - днярнбепмн */                1
#define NYEDOSTOVYERNO /* C_36 - меднярнбепмн */               0
#define Nye_provyeryayutsya /* C_37 - мЕ_ОПНБЕПЪЧРЯЪ */       0  
#define Provyeryayutsya /* C_38 - оПНБЕПЪЧРЯЪ */      1

#define TAJMAUT_NA_DIAGNOSTIKU_RAZRYVA_SVYAZI /* C_39 - рюилюср_мю_дхюцмнярхйс_пюгпшбю_ябъгх */ 5*ODNA_SYEKUNDA

#define T_Pryedyel_nayaVrubashkyeOkhlazhdyeniya /* C_40 - р_оПЕДЕКЭМЮЪбПСАЮЬЙЕнУКЮФДЕМХЪ */          85.0 
#define T_Pryedyel_nayaVbakyeOkhlazhdyeniya /* C_41 - р_оПЕДЕКЭМЮЪбАЮЙЕнУКЮФДЕМХЪ */          65.0 

enum EN0 {
    PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKIJ /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_мхгйхи */,
    PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKIJ /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_бшянйхи */,
	PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_б_мнпле */,
	PK_GUI_OTKAZ_DATCHIKOV_UROVNYA /* ой_цсх_нрйюг_дюрвхйнб_спнбмъ */,  
	
	PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKAYA /* ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_мхгйюъ */,
	PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKAYA /* ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_бшянйюъ */,
	PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* ой_цсх_релоепюрспю_бндш_б_аюйе_нукюфдемхъ_б_мнпле */,

    PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_NIZKAYA /* ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_мхгйюъ */,
	PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_VYSOKAYA /* ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_бшянйюъ */,
	PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_V_NORMYE /* ой_цсх_релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_б_мнпле */,

	PK_GUI_DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_V_NORMYE /* ой_цсх_дюбкемхе_б_бюйсслмни_рпсае_б_мнпле */,
	PK_GUI_DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_VNYE_NORMY /* ой_цсх_дюбкемхе_б_бюйсслмни_рпсае_бме_мнплш */,
	
	PK_GUI_SKOROST__OTKACHKI_V_NORMYE /* ой_цсх_яйнпнярэ_нрйювйх_б_мнпле */,
	PK_GUI_SKOROST__OTKACHKI_NIZHYE_NORMY /* ой_цсх_яйнпнярэ_нрйювйх_мхфе_мнплш */, 

		
	PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_V_NORMYE /* ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_б_мнпле */,
	PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_VYSHYE_NORMY /* ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_бшье_мнплш */,  
    PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY /* ой_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_мхфе_мнплш */,
	
	
	PK_GUI_OTKAZ_VAKUUMIROVANIYA_OTKAZ_OBORUDOVANIYA /* ой_цсх_нрйюг_бюйсслхпнбюмхъ_нрйюг_нанпсднбюмхъ */,
	PK_GUI_START_VYKLYUCHYENIYA_VAKUUMIROVANIYA_TRUBY /* ой_цсх_ярюпр_бшйкчвемхъ_бюйсслхпнбюмхъ_рпсаш */,
	PK_GUI_START_VYKLYUCHYENIYA_VAKUUMNOGO_NASOSA /* ой_цсх_ярюпр_бшйкчвемхъ_бюйсслмнцн_мюяняю */
	

	
};
enum EN1 {
     KOM_GUI_OTKR_ZATVOR_VAK /* йнл_цсх_нрйп_гюрбнп_бюй */= PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY + 1,
     KOM_GUI_ZAKR_ZATVOR_VAK /* йнл_цсх_гюйп_гюрбнп_бюй */    	,
     KOM_GUI_OTKR_SAPUN /* йнл_цсх_нрйп_яюосм */			    ,
     KOM_GUI_ZAKR_SAPUN /* йнл_цсх_гюйп_яюосм */			    ,
     KOM_GUI_VKL_USTR_PLAV_PUSKA /* йнл_цсх_бйк_сярп_окюб_осяйю */    ,
     KOM_GUI_VYK_USTR_PLAV_PUSKA /* йнл_цсх_бшй_сярп_окюб_осяйю */    ,
 
 	 KOM_GUI_VKL_PIT_UPP_VAK_NASOSA /* йнл_цсх_бйк_охр_соо_бюй_мюяняю */     ,
	 KOM_GUI_VYK_PIT_UPP_VAK_NASOSA /* йнл_цсх_бшй_охр_соо_бюй_мюяняю */     ,
	 KOM_GUI_VKL_PIT_VYENTILYATOR /* йнл_цсх_бйк_охр_бемрхкърнп */    ,
	 KOM_GUI_VYK_PIT_VYENTILYATOR /* йнл_цсх_бшй_охр_бемрхкърнп */    ,
     KOM_GUI_VKL_PIT_RYEG_T /* йнл_цсх_бйк_охр_пец_р */    ,
	 KOM_GUI_VYK_PIT_RYEG_T /* йнл_цсх_бшй_охр_пец_р */    ,
     KOM_GUI_VKL_PIT_RYEG_UR /* йнл_цсх_бйк_охр_пец_сп */     ,
	 KOM_GUI_VYK_PIT_RYEG_UR /* йнл_цсх_бшй_охр_пец_сп */     , 
	 KOM_GUI_VKL_PIT_NAS_OKHL /* йнл_цсх_бйк_охр_мюя_нук */ ,
	 KOM_GUI_VYK_PIT_NAS_OKHL /* йнл_цсх_бшй_охр_мюя_нук */    , 
	 KOM_GUI_VKL_VAKUUMIROVANIYE_TRUBY /* йнл_цсх_бйк_бюйсслхпнбюмхе_рпсаш */,
	 KOM_GUI_VYK_VAKUUMIROVANIYE_TRUBY /* йнл_цсх_бшй_бюйсслхпнбюмхе_рпсаш */, 
	 KOM_GUI_VKL_VAKUUMNYJ_NASOS /* йнл_цсх_бйк_бюйсслмши_мюяня */ ,
   
     KOMANDY_OT_GUI /* йнлюмдш_нр_цсх */ = KOM_GUI_VKL_VAKUUMNYJ_NASOS 
	
 
	
};


enum EN2 {
	IZMN_FP_P_VbakyeKompryessora /* хглм_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ */ = KOMANDY_OT_GUI + 1,
	IZMN_FP_P_Vpatrubkye /* хглм_то_P_бОЮРПСАЙЕ */,
	IZMN_FP_T_Vrubashkye /* хглм_то_T_бПСАЮЬЙЕ */,	
	IZMN_FP_T_Vbakye /* хглм_то_T_бАЮЙЕ */,	
    IZMN_FP_P_VtrubyeSidyer /* хглм_то_P_бРПСАЕяХДЕП */,
    KOMANDY_IZM_FP /* йнлюмдш_хгл_то */ = IZMN_FP_P_VtrubyeSidyer  
  
};

enum EN3 {                    
      PK_GUI_OTKAZ_OTKRYTIYA_ZATVORA_VAKUUMNOGO /* ой_цсх_нрйюг_нрйпшрхъ_гюрбнпю_бюйсслмнцн */ = KOMANDY_IZM_FP + 1,
      PK_GUI_OTKAZ_ZAKRYTIYA_ZATVORA_VAKUUMNOGO /* ой_цсх_нрйюг_гюйпшрхъ_гюрбнпю_бюйсслмнцн */,
      PK_GUI_OTKAZ_OTKRYTIYA_SAPUNA /* ой_цсх_нрйюг_нрйпшрхъ_яюосмю */,
      PK_GUI_OTKAZ_ZAKRYTIYA_SAPUNA /* ой_цсх_нрйюг_гюйпшрхъ_яюосмю */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_VYENTILYATORA /* ой_цсх_нрйюг_бйкчвемхъ_бемрхкърнпю */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_VYENTILYATORA /* ой_цсх_нрйюг_бшйкчвемхъ_бемрхкърнпю */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_USTR_PLAV_PUSKA /* ой_цсх_нрйюг_бйкчвемхъ_сярп_окюб_осяйю */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_USTR_PLAV_PUSKA /* ой_цсх_нрйюг_бшйкчвемхъ_сярп_окюб_осяйю */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_RYEGULYATORA_TYEMPYERATURY /* ой_цсх_нрйюг_бйкчвемхъ_пецскърнпю_релоепюрспш */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_RYEGULYATORA_TYEMPYERATURY /* ой_цсх_нрйюг_бшйкчвемхъ_пецскърнпю_релоепюрспш */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_RYEGULYATORA_UROVNYA /* ой_цсх_нрйюг_бйкчвемхъ_пецскърнпю_спнбмъ */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_RYEGULYATORA_UROVNYA /* ой_цсх_нрйюг_бшйкчвемхъ_пецскърнпю_спнбмъ */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_NASOSA_OKHLAZHDYENIYA /* ой_цсх_нрйюг_бйкчвемхъ_мюяняю_нукюфдемхъ */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_NASOSA_OKHLAZHDYENIYA /* ой_цсх_нрйюг_бшйкчвемхъ_мюяняю_нукюфдемхъ */,
	  PK_GUI_IDYET_VAKUUMIROVANIYE_OTKAZ_VYPOLNYENIYA_KOMANDY /* ой_цсх_хдер_бюйсслхпнбюмхе_нрйюг_бшонкмемхъ_йнлюмдш */,
	  PK_GUI_NYET_USLOVIJ_DLYA_VYPOLNYENIYA_KOMANDY /* ой_цсх_мер_сякнбхи_дкъ_бшонкмемхъ_йнлюмдш */,
	  PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VNYE_NORMY_OTKAZ_VYPOLNYENI /* ой_цсх_спнбемэ_бндш_б_аюйе_нукюфдемхъ_бме_мнплш_нрйюг_бшонкмемх */, 				
	  PK_GUI_OTRITSATYEL_NAYA_TYEMPYERATURA_VODY_OTKAZ_VYPOLNYENIYA_KOMANDY /* ой_цсх_нрпхжюрекэмюъ_релоепюрспю_бндш_нрйюг_бшонкмемхъ_йнлюмдш */,
	  PK_GUI_DAVLYENIYE_V_PATRUBKYE_NYE_UMYEN_SHAYETSYA /* ой_цсх_дюбкемхе_б_оюрпсайе_ме_слемэьюеряъ */,
	  PK_GUI_DAVLYENIYE_V_VAK_TRUBYE_NYE_UMYEN_SHAYETSYA /* ой_цсх_дюбкемхе_б_бюй_рпсае_ме_слемэьюеряъ */,
	  PK_GUI_VAKUUMIROVANIYE_USPYESHNO_ZAVYERSHYENO /* ой_цсх_бюйсслхпнбюмхе_сяоеьмн_гюбепьемн */,	  
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_PITANIYA_UPP_VAKUUMNOGO_NASOSA /* ой_цсх_нрйюг_бйкчвемхъ_охрюмхъ_соо_бюйсслмнцн_мюяняю */,   
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_UPP_VAKUUMNOGO_NASOSA /* ой_цсх_нрйюг_бшйкчвемхъ_охрюмхъ_соо_бюйсслмнцн_мюяняю */,  
	  PK_GUI_NYEDOSTOVYERNYYE_DANNYYE_OBORUDOVANIYA_VAK_SISTYEMY /* ой_цсх_меднярнбепмше_дюммше_нанпсднбюмхъ_бюй_яхярелш */,
	  

		PK_GUI_AVARIYA_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_MYEN_SHYE_2kh_ATMOSFYER /* ой_цсх_юбюпхъ_дюбкемхе_б_аюйе_йнлопеяянпю_лемэье_2У_юрлнятеп */, 
		PK_GUI_AVARIYA__SROCHNO_VYKLYUCHIT__VAK_SISTYEMU_V_RUCHNOM_RYEZHIMYE /* ой_цсх_юбюпхъ__япнвмн_бшйкчвхрэ_бюй_яхярелс_б_псвмнл_пефхле */,	
		PK_GUI_AVARIYA_PYERYEGRYEV_RUBASHKI_OKHLAZHDYENIYA /* ой_цсх_юбюпхъ_оепецпеб_псаюьйх_нукюфдемхъ */,				
		PK_GUI_AVARIYA_PYERYEGRYEV_BAKA_OKHLAZHDYENIYA_NASOSA /* ой_цсх_юбюпхъ_оепецпеб_аюйю_нукюфдемхъ_мюяняю */,					
		

	  PK_GUI_RYESTART_NYEDOSTOVYERNYYE_DANNYYE_OBORUDOVANIYA_VAK_SISTYEMY /* ой_цсх_пеярюпр_меднярнбепмше_дюммше_нанпсднбюмхъ_бюй_яхярелш */, 
	  PK_GUI_YEST__PITANIYE_SHKAFA_VS_380 /* ой_цсх_еярэ_охрюмхе_ьйютю_бя_380 */,	
	  PK_GUI_NYET_PITANIYE_SHKAFA_VS_380 /* ой_цсх_мер_охрюмхе_ьйютю_бя_380 */,	
	  PK_GUI_VYENTILYATOR_VKLYUCHYEN /* ой_цсх_бемрхкърнп_бйкчвем */,
	  PK_GUI_VYENTILYATOR_VYKLYUCHYEN /* ой_цсх_бемрхкърнп_бшйкчвем */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_VYENTILYATORA /* ой_цсх_яонмрюммне_бшйкчвемхе_бемрхкърнпю */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_VYENTILYATORA /* ой_цсх_яонмрюммне_бйкчвемхе_бемрхкърнпю */,
	  PK_GUI_ZATVOR_VAKUUMNYJ_OTKRYT /* ой_цсх_гюрбнп_бюйсслмши_нрйпшр */,
	  PK_GUI_ZATVOR_VAKUUMNYJ_ZAKRYT /* ой_цсх_гюрбнп_бюйсслмши_гюйпшр */,
	  PK_GUI_SRYEDNYEYE_SOSTOYANIYE_ZATVORA_VAKUUMNOGO /* ой_цсх_япедмее_янярнъмхе_гюрбнпю_бюйсслмнцн */,
	  PK_GUI_SOSTOYANIYE_OSHIBKI_ZATVORA_VAKUUMNOGO /* ой_цсх_янярнъмхе_ньхайх_гюрбнпю_бюйсслмнцн */,
	  PK_GUI_SPONTANNOYE_OTKRYTIYE_ZAT_VAKUUMNOGO /* ой_цсх_яонмрюммне_нрйпшрхе_гюр_бюйсслмнцн */,
	  PK_GUI_SPONTANNOYE_ZAKRYTIYE_ZAT_VAKUUMNOGO /* ой_цсх_яонмрюммне_гюйпшрхе_гюр_бюйсслмнцн */,
	  PK_GUI_SAPUN_OTKRYT /* ой_цсх_яюосм_нрйпшр */,
	  PK_GUI_SAPUN_ZAKRYT /* ой_цсх_яюосм_гюйпшр */,
	  PK_GUI_SPONTANNOYE_OTKRYTIYE_SAPUNA /* ой_цсх_яонмрюммне_нрйпшрхе_яюосмю */,
	  PK_GUI_SPONTANNOYE_ZAKRYTIYE_SAPUNA /* ой_цсх_яонмрюммне_гюйпшрхе_яюосмю */,
	  PK_GUI_PITANIYE_UPP_VAKUUMNOGO_NASOSA_VKLYUCHYENO /* ой_цсх_охрюмхе_соо_бюйсслмнцн_мюяняю_бйкчвемн */,  
	  PK_GUI_PITANIYE_UPP_VAKUUMNOGO_NASOSA_VYKLYUCHYENO /* ой_цсх_охрюмхе_соо_бюйсслмнцн_мюяняю_бшйкчвемн */,  
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_UPP_VAKUUMNOGO_NASOSA /* ой_цсх_яонмрюммне_бйкчвемхе_соо_бюйсслмнцн_мюяняю */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_UPP_VAKUUMNOGO_NASOSA /* ой_цсх_яонмрюммне_бшйкчвемхе_соо_бюйсслмнцн_мюяняю */,
	  PK_GUI_PITANIYE_RYEGULYATORA_TYEMPYERATURY_VKLYUCHYENO /* ой_цсх_охрюмхе_пецскърнпю_релоепюрспш_бйкчвемн */,
	  PK_GUI_PITANIYE_RYEGULYATORA_TYEMPYERATURY_VYKLYUCHYENO /* ой_цсх_охрюмхе_пецскърнпю_релоепюрспш_бшйкчвемн */,
  	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_RYEGULYATORA_TYEMPYERATURY /* ой_цсх_яонмрюммне_бйкчвемхе_пецскърнпю_релоепюрспш */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_RYEGULYATORA_TYEMPYERATURY /* ой_цсх_яонмрюммне_бшйкчвемхе_пецскърнпю_релоепюрспш */,
	  PK_GUI_PITANIYE_RYEGULYATORA_UROVNYA_VKLYUCHYENO /* ой_цсх_охрюмхе_пецскърнпю_спнбмъ_бйкчвемн */,
	  PK_GUI_PITANIYE_RYEGULYATORA_UROVNYA_VYKLYUCHYENO /* ой_цсх_охрюмхе_пецскърнпю_спнбмъ_бшйкчвемн */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_RYEGULYATORA_UROVNYA /* ой_цсх_яонмрюммне_бйкчвемхе_пецскърнпю_спнбмъ */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_RYEGULYATORA_UROVNYA /* ой_цсх_яонмрюммне_бшйкчвемхе_пецскърнпю_спнбмъ */,
	  PK_GUI_PITANIYE_NASOSA_OKHLAZHDYENIYA_VKLYUCHYENO /* ой_цсх_охрюмхе_мюяняю_нукюфдемхъ_бйкчвемн */,
	  PK_GUI_PITANIYE_NASOSA_OKHLAZHDYENIYA_VYKLYUCHYENO /* ой_цсх_охрюмхе_мюяняю_нукюфдемхъ_бшйкчвемн */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_NASOSA_OKHLAZHDYENIYA /* ой_цсх_яонмрюммне_бйкчвемхе_мюяняю_нукюфдемхъ */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_NASOSA_OKHLAZHDYENIYA /* ой_цсх_яонмрюммне_бшйкчвемхе_мюяняю_нукюфдемхъ */,
	  PK_GUI_USTROJSTVO_PLAVNOGO_PUSKA_VKLYUCHYENO /* ой_цсх_сярпниярбн_окюбмнцн_осяйю_бйкчвемн */,
	  PK_GUI_USTROJSTVO_PLAVNOGO_PUSKA_VYKLYUCHYENO /* ой_цсх_сярпниярбн_окюбмнцн_осяйю_бшйкчвемн */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_USTROJSTVA_PLAVNOGO_PUSKA /* ой_цсх_яонмрюммне_бйкчвемхе_сярпниярбю_окюбмнцн_осяйю */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_USTROJSTVA_PLAVNOGO_PUSKA /* ой_цсх_яонмрюммне_бшйкчвемхе_сярпниярбю_окюбмнцн_осяйю */,
	  PK_GUI_OTKAZ_VAKUUMIROVANIYA /* ой_цсх_нрйюг_бюйсслхпнбюмхъ */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_VAKUUMNOJ_PODSISTYEMY /* ой_цсх_нрйюг_бйкчвемхъ_бюйсслмни_ондяхярелш */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_VAKUUMNOJ_PODSISTYEMY /* ой_цсх_нрйюг_бшйкчвемхъ_бюйсслмни_ондяхярелш */,
	  PK_GUI_YEST__SVYAZ__S_KONTS_OTKRYTIYA_ZATV_VAKUUMNOGO /* ой_цсх_еярэ_ябъгэ_я_йнмж_нрйпшрхъ_гюрб_бюйсслмнцн */,
      PK_GUI_NYET_SVYAZI_S_KONTS_OTKRYTIYA_ZATV_VAKUUMNOGO /* ой_цсх_мер_ябъгх_я_йнмж_нрйпшрхъ_гюрб_бюйсслмнцн */,
	  PK_GUI_YEST__SVYAZ__S_KONTS_ZAKRYTIYA_ZATV_VAKUUMNOGO /* ой_цсх_еярэ_ябъгэ_я_йнмж_гюйпшрхъ_гюрб_бюйсслмнцн */,
	  PK_GUI_NYET_SVYAZI_S_KONTS_ZAKRYTIYA_ZATV_VAKUUMNOGO /* ой_цсх_мер_ябъгх_я_йнмж_гюйпшрхъ_гюрб_бюйсслмнцн */,
      PK_GUI_YEST__SVYAZ__S_SAPUNOM /* ой_цсх_еярэ_ябъгэ_я_яюосмнл */,
	  PK_GUI_NYET_SVYAZI_S_SAPUNOM /* ой_цсх_мер_ябъгх_я_яюосмнл */,
	  PK_GUI_YEST__SVYAZ__S_PLAVNYM_PUSKOM /* ой_цсх_еярэ_ябъгэ_я_окюбмшл_осяйнл */,
	  PK_GUI_NYET_SVYAZI_S_PLAVNYM_PUSKOM /* ой_цсх_мер_ябъгх_я_окюбмшл_осяйнл */,
	  PK_GUI_YEST__SVYAZ__S_PITANIYEM_VAK_NASOSA /* ой_цсх_еярэ_ябъгэ_я_охрюмхел_бюй_мюяняю */, 
	  PK_GUI_NYET_SVYAZI_S_PITANIYEM_VAK_NASOSA /* ой_цсх_мер_ябъгх_я_охрюмхел_бюй_мюяняю */,	
	  PK_GUI_YEST__SVYAZ__S_VYENTILYATOROM /* ой_цсх_еярэ_ябъгэ_я_бемрхкърнпнл */,
	  PK_GUI_NYET_SVYAZI_S_VYENTILYATOROM /* ой_цсх_мер_ябъгх_я_бемрхкърнпнл */,
	  PK_GUI_YEST__SVYAZ__S_RYEG_TYEMPYERATURY /* ой_цсх_еярэ_ябъгэ_я_пец_релоепюрспш */,  
	  PK_GUI_NYET_SVYAZI_S_RYEG_TYEMPYERATURY /* ой_цсх_мер_ябъгх_я_пец_релоепюрспш */,
	  PK_GUI_YEST__SVYAZ__S_RYEG_UROVNYA /* ой_цсх_еярэ_ябъгэ_я_пец_спнбмъ */,
	  PK_GUI_NYET_SVYAZI_S_RYEG_UROVNYA /* ой_цсх_мер_ябъгх_я_пец_спнбмъ */,
	  PK_GUI_YEST__SVYAZ__S_NIZHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ой_цсх_еярэ_ябъгэ_я_мхфмхл_йнмжебхйнл_сп_бндш_аюйю_нук */,
	  PK_GUI_NYET_SVYAZI_S_NIZHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ой_цсх_мер_ябъгх_я_мхфмхл_йнмжебхйнл_сп_бндш_аюйю_нук */,
	  PK_GUI_YEST__SVYAZ__S_VYERKHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ой_цсх_еярэ_ябъгэ_я_бепумхл_йнмжебхйнл_сп_бндш_аюйю_нук */,
	  PK_GUI_NYET_SVYAZI_S_VYERKHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ой_цсх_мер_ябъгх_я_бепумхл_йнмжебхйнл_сп_бндш_аюйю_нук */,
	  PK_GUI_YEST__SVYAZ__S_NASOSOSOM_OKHL /* ой_цсх_еярэ_ябъгэ_я_мюянянянл_нук */,
	  PK_GUI_NYET_SVYAZI_S_NASOSOSOM_OKHL /* ой_цсх_мер_ябъгх_я_мюянянянл_нук */,
	  PK_GUI_YEST__SVYAZ__S_PITANIYEM_SHKAFA_380 /* ой_цсх_еярэ_ябъгэ_я_охрюмхел_ьйютю_380 */,   
	  PK_GUI_NYET_SVYAZI_S_PITANIYEM_SHKAFA_380 /* ой_цсх_мер_ябъгх_я_охрюмхел_ьйютю_380 */,		
		PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_BAKYE_KOMPRYESSORA /* ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_аюйе_йнлопеяянпю */,
		PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_BAKYE_KOMPRYESSORA /* ой_цсх_мер_ябъгх_я_дюбкемхел_б_аюйе_йнлопеяянпю */,
		PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_PATRUBKYE /* ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_оюрпсайе */,		
		PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_PATRUBKYE /* ой_цсх_мер_ябъгх_я_дюбкемхел_б_оюрпсайе */,		
		PK_GUI_YEST__SVYAZ__S_TYEMPYERATUROJ_V_RUBASHKYE_OKHL /* ой_цсх_еярэ_ябъгэ_я_релоепюрспни_б_псаюьйе_нук */,	
		PK_GUI_NYET_SVYAZI_S_TYEMPYERATUROJ_V_RUBASHKYE_OKHL /* ой_цсх_мер_ябъгх_я_релоепюрспни_б_псаюьйе_нук */,	
		PK_GUI_YEST__SVYAZ__S_TYEMPYERATUROJ_V_BAKYE_OKHL /* ой_цсх_еярэ_ябъгэ_я_релоепюрспни_б_аюйе_нук */,		
		PK_GUI_NYET_SVYAZI_S_TYEMPYERATUROJ_V_BAKYE_OKHL /* ой_цсх_мер_ябъгх_я_релоепюрспни_б_аюйе_нук */,		
		PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_TRUBYE_SID /* ой_цсх_еярэ_ябъгэ_я_дюбкемхел_б_рпсае_яхд */,	
		PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_TRUBYE_SID /* ой_цсх_мер_ябъгх_я_дюбкемхел_б_рпсае_яхд */,	
	  PK_GUI_VAKUUMIROVANIYE_TRUBY_VKLYUCHYENO /* ой_цсх_бюйсслхпнбюмхе_рпсаш_бйкчвемн */,
	  PK_GUI_VAKUUMIROVANIYE_TRUBY_VYKLYUCHYENO /* ой_цсх_бюйсслхпнбюмхе_рпсаш_бшйкчвемн */

};


enum EN4 {                    
      PK_GUI_FP_P_VbakyeKompryessora /* ой_цсх_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ */ = PK_GUI_VAKUUMIROVANIYE_TRUBY_VYKLYUCHYENO + 1,
      PK_GUI_FP_P_Vpatrubkye /* ой_цсх_то_P_бОЮРПСАЙЕ */,
      PK_GUI_FP_T_Vrubashkye /* ой_цсх_то_T_бПСАЮЬЙЕ */,
      PK_GUI_FP_T_Vbakye /* ой_цсх_то_T_бАЮЙЕ */,
      PK_GUI_FP_P_VtrubyeSidyer /* ой_цсх_то_P_бРПСАЕяХДЕП */
      

      
};
enum EN5 {
IZMN_NP_1 /* хглм_мо_1 */ = PK_GUI_FP_P_VtrubyeSidyer + 1,
IZMN_NP_ZD_P_VbakyeKompryessora /* хглм_мо_гд_P_бАЮЙЕйНЛОПЕЯЯНПЮ */ = IZMN_NP_1,
IZMN_NP_ZD_Patmosf /* хглм_мо_гд_PЮРЛНЯТ */,
IZMN_NP_ZD_P_VtrubyeSidyer /* хглм_мо_гд_P_бРПСАЕяХДЕП */,	
IZMN_NP_ZD_T_VrubashkyeNizhnyaya /* хглм_мо_гд_T_бПСАЮЬЙЕмХФМЪЪ */,		
IZMN_NP_ZD_T_VrubashkyeVyerkhnyaya /* хглм_мо_гд_T_бПСАЮЬЙЕбЕПУМЪЪ */,	
IZMN_NP_ZD_T_VbakyeNizhnyaya /* хглм_мо_гд_T_бАЮЙЕмХФМЪЪ */,
IZMN_NP_ZD_T_VbakyeVyerkhnyaya /* хглм_мо_гд_T_бАЮЙЕбЕПУМЪЪ */,

IZMN_NP_ZD_PyeriodaKontrP_PriOtkachkye /* хглм_мо_гд_оЕПХНДЮйНМРПP_оПХнРЙЮВЙЕ */,  
IZMN_NP_ZD_PyeriodaKontrP_PriNatyekanii /* хглм_мо_гд_оЕПХНДЮйНМРПP_оПХмЮРЕЙЮМХХ */, 

IZMN_NP_ZD_Gist_T_Vbakye /* хглм_мо_гд_цХЯР_T_бАЮЙЕ */,
IZMN_NP_ZD_Gist_T_Vrubashkye /* хглм_мо_гд_цХЯР_T_бПСАЮЬЙЕ */,
IZMN_NP_ZD_Gist_P_VbakyeKompryessora /* хглм_мо_гд_цХЯР_P_бАЮЙЕйНЛОПЕЯЯНПЮ */,
IZMN_NP_ZD_Gist_P_VtrubyeSidyerVyerkh /* хглм_мо_гд_цХЯР_P_бРПСАЕяХДЕПбЕПУ */,
IZMN_NP_ZD_Gist_P_VtrubyeSidyerNizh /* хглм_мо_гд_цХЯР_P_бРПСАЕяХДЕПмХФ */,

IZMN_NP_N /* хглм_мо_N */

};

enum EN6 {
     PK_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ой_цсх_ньхайю_йндю_йнлюмдш_нр_цсх */ = IZMN_NP_N + 1  
  
};