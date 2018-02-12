    
#define T0_1 /* C_0 - р0_1 */                       0  
#define ODNA_SYEKUNDA /* C_1 - ндмю_яейсмдю */               2  
#define DVYE_SYEKUNDY /* C_2 - дбе_яейсмдш */             2*ODNA_SYEKUNDA
#define TRI_SYEKUNDY /* C_3 - рпх_яейсмдш */             3*ODNA_SYEKUNDA
#define PYAT__SYEKUND /* C_4 - оърэ_яейсмд */             5*ODNA_SYEKUNDA
#define DYESYAT__SYEKUND /* C_5 - деяърэ_яейсмд */          10*ODNA_SYEKUNDA
#define DVADTSAT__SYEKUND /* C_6 - дбюджюрэ_яейсмд */        20*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_ZAT_VAK /* C_7 - рюилюср_мю_япюаюршбюмхе_гюр_бюй */			10*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_SAPUNA /* C_8 - рюилюср_мю_япюаюршбюмхе_яюосмю */           	DYESYAT__SYEKUND
#define TAJMAUT_NA_SRABATYVANIYE_USTR_PLAV_PUSKA /* C_9 - рюилюср_мю_япюаюршбюмхе_сярп_окюб_осяйю */   3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VAK_NASOSA /* C_10 - рюилюср_мю_япюаюршбюмхе_бюй_мюяняю */ 		3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VYENTILYATORA /* C_11 - рюилюср_мю_япюаюршбюмхе_бемрхкърнпю */		PYAT__SYEKUND
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_T /* C_12 - рюилюср_мю_япюаюршбюмхе_пец_р */				3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_UR /* C_13 - рюилюср_мю_япюаюршбюмхе_пец_сп */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_NASOS_OKHL /* C_14 - рюилюср_мю_япюаюршбюмхе_мюяня_нук */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SVYAZ__S_GUI /* C_15 - рюилюср_мю_ябъгэ_я_цсх */  DYESYAT__SYEKUND
#define ODNA_MINUTA /* C_16 - ндмю_лхмсрю */          60*ODNA_SYEKUNDA
#define DVYE_MINUTY /* C_17 - дбе_лхмсрш */          2*ODNA_MINUTA
#define PYAT__MINUT /* C_18 - оърэ_лхмср */          5*60*ODNA_SYEKUNDA
#define TRIDTSAT__MINUT /* C_19 - рпхджюрэ_лхмср */          30*ODNA_MINUTA
#define TAJMAUT_ZADYERZHKA_NA_OTKACHKU /* C_20 - рюилюср_гюдепфйю_мю_нрйювйс */ PYAT__SYEKUND

#define VKL /* C_21 - бйк */                1
#define VYK /* C_22 - бшй */               0
#define OTKR /* C_23 - нрйп */              1
#define ZAKR /* C_24 - гюйп */          	0
#define YEST_ /* C_25 - еярэ */               1
#define NYET /* C_26 - мер */                0
#define NORMA /* C_27 - мнплю */              1
#define VNYE_NORMY /* C_28 - бме_мнплш */          0



#define TAJMAUT_NA_DIAGNOSTIKU_RAZRYVA_SVYAZI /* C_29 - рюилюср_мю_дхюцмнярхйс_пюгпшбю_ябъгх */ 5*ODNA_SYEKUNDA

#define T_Pryedyel_nayaVbakyeOkhlazhdyeniya /* C_30 - р_оПЕДЕКЭМЮЪбАЮЙЕнУКЮФДЕМХЪ */          99.0 

#define ZD_P_VbakyeKompryessora /* C_31 - гд_P_бАЮЙЕйНЛОПЕЯЯНПЮ */						10.0 

#define T_GISTYERYEZIS_VODY_V_BAKYE /* C_32 - р_цхярепегхя_бндш_б_аюйе */  1.0
#define T_GISTYERYEZIS_VODY_V_RUBAKHYE /* C_33 - р_цхярепегхя_бндш_б_псаюуе */  1.0


enum EN0 {
    UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKIJ /* спнбемэ_бндш_б_аюйе_нукюфдемхъ_мхгйхи */,
    UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKIJ /* спнбемэ_бндш_б_аюйе_нукюфдемхъ_бшянйхи */,
	UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* спнбемэ_бндш_б_аюйе_нукюфдемхъ_б_мнпле */,
	TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKAYA /* релоепюрспю_бндш_б_аюйе_нукюфдемхъ_мхгйюъ */,
	TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKAYA /* релоепюрспю_бндш_б_аюйе_нукюфдемхъ_бшянйюъ */,
	TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* релоепюрспю_бндш_б_аюйе_нукюфдемхъ_б_мнпле */,

    TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_NIZKAYA /* релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_мхгйюъ */,
	TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_VYSOKAYA /* релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_бшянйюъ */,
	TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_V_NORMYE /* релоепюрспю_бндш_б_псаюьйе_нукюфдемхъ_б_мнпле */,

	DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_V_NORMYE /* дюбкемхе_б_бюйсслмни_рпсае_б_мнпле */,
	DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_VNYE_NORMY /* дюбкемхе_б_бюйсслмни_рпсае_бме_мнплш */,
	
	SKOROST__OTKACHKI_V_NORMYE /* яйнпнярэ_нрйювйх_б_мнпле */,
	SKOROST__OTKACHKI_NIZHYE_NORMY /* яйнпнярэ_нрйювйх_мхфе_мнплш */,
	
	DAVLYENIYE_V_BAKYE_KOMPRYESSORA_V_NORMYE /* дюбкемхе_б_аюйе_йнлопеяянпю_б_мнпле */,
    DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY /* дюбкемхе_б_аюйе_йнлопеяянпю_мхфе_мнплш */


	



	
};
enum EN1 {
     OTKR_ZATVOR_VAK /* нрйп_гюрбнп_бюй */= DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY + 1,
     ZAKR_ZATVOR_VAK /* гюйп_гюрбнп_бюй */    	,
     OTKR_SAPUN /* нрйп_яюосм */			    ,
     ZAKR_SAPUN /* гюйп_яюосм */			    ,
     VKL_USTR_PLAV_PUSKA /* бйк_сярп_окюб_осяйю */    ,
     VYK_USTR_PLAV_PUSKA /* бшй_сярп_окюб_осяйю */    ,
	 VKL_PIT_VAK_NASOSA /* бйк_охр_бюй_мюяняю */     ,
	 VYK_PIT_VAK_NASOSA /* бшй_охр_бюй_мюяняю */     ,
	 VKL_PIT_VYENTILYATOR /* бйк_охр_бемрхкърнп */    ,
	 VYK_PIT_VYENTILYATOR /* бшй_охр_бемрхкърнп */    ,
     VKL_PIT_RYEG_T /* бйк_охр_пец_р */    ,
	 VYK_PIT_RYEG_T /* бшй_охр_пец_р */    ,
     VKL_PIT_RYEG_UR /* бйк_охр_пец_сп */     ,
	 VYK_PIT_RYEG_UR /* бшй_охр_пец_сп */     , 
	 VKL_PIT_NAS_OKHL /* бйк_охр_мюя_нук */ ,
	 VYK_PIT_NAS_OKHL /* бшй_охр_мюя_нук */    , 
	 VKL_VAKUUMIROVANIYE_TRUBY /* бйк_бюйсслхпнбюмхе_рпсаш */,
	 VYK_VAKUUMIROVANIYE_TRUBY /* бшй_бюйсслхпнбюмхе_рпсаш */,
	 VKL_NASOS_VAKUUMNYJ /* бйк_мюяня_бюйсслмши */ ,
	 VYK_NASOS_VAKUUMNYJ /* бшй_мюяня_бюйсслмши */, 
     KOMANDY_OT_GUI /* йнлюмдш_нр_цсх */ = VYK_NASOS_VAKUUMNYJ 
	
 
	
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
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA /* ой_цсх_нрйюг_бйкчвемхъ_охрюмхъ_бюйсслмнцн_мюяняю */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA /* ой_цсх_нрйюг_бшйкчвемхъ_охрюмхъ_бюйсслмнцн_мюяняю */
      
      

      
      
};
enum EN4 {                    
      PK_GUI_FP_P_VbakyeKompryessora /* ой_цсх_то_P_бАЮЙЕйНЛОПЕЯЯНПЮ */ = PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA + 1,
      PK_GUI_FP_P_Vpatrubkye /* ой_цсх_то_P_бОЮРПСАЙЕ */,
      PK_GUI_FP_T_Vrubashkye /* ой_цсх_то_T_бПСАЮЬЙЕ */,
      PK_GUI_FP_T_Vbakye /* ой_цсх_то_T_бАЮЙЕ */,
      PK_GUI_FP_P_VtrubyeSidyer /* ой_цсх_то_P_бРПСАЕяХДЕП */
      

      
};




enum EN5 {
     PK_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ой_цсх_ньхайю_йндю_йнлюмдш_нр_цсх */ = PK_GUI_FP_P_VtrubyeSidyer + 1  
  
};