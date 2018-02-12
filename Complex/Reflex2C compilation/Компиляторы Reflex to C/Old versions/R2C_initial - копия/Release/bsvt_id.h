    
#define T0_1 /* C_0 - �0_1 */                       0  
#define ODNA_SYEKUNDA /* C_1 - ����_������� */               2  
#define DVYE_SYEKUNDY /* C_2 - ���_������� */             2*ODNA_SYEKUNDA
#define TRI_SYEKUNDY /* C_3 - ���_������� */             3*ODNA_SYEKUNDA
#define PYAT__SYEKUND /* C_4 - ����_������ */             5*ODNA_SYEKUNDA
#define DYESYAT__SYEKUND /* C_5 - ������_������ */          10*ODNA_SYEKUNDA
#define DVADTSAT__SYEKUND /* C_6 - ��������_������ */        20*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_ZAT_VAK /* C_7 - �������_��_������������_���_��� */			10*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_SAPUNA /* C_8 - �������_��_������������_������ */           	DYESYAT__SYEKUND
#define TAJMAUT_NA_SRABATYVANIYE_USTR_PLAV_PUSKA /* C_9 - �������_��_������������_����_����_����� */   3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VAK_NASOSA /* C_10 - �������_��_������������_���_������ */ 		3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VYENTILYATORA /* C_11 - �������_��_������������_����������� */		PYAT__SYEKUND
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_T /* C_12 - �������_��_������������_���_� */				3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_UR /* C_13 - �������_��_������������_���_�� */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_NASOS_OKHL /* C_14 - �������_��_������������_�����_��� */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SVYAZ__S_GUI /* C_15 - �������_��_�����_�_��� */  DYESYAT__SYEKUND
#define ODNA_MINUTA /* C_16 - ����_������ */          60*ODNA_SYEKUNDA
#define DVYE_MINUTY /* C_17 - ���_������ */          2*ODNA_MINUTA
#define PYAT__MINUT /* C_18 - ����_����� */          5*60*ODNA_SYEKUNDA
#define TRIDTSAT__MINUT /* C_19 - ��������_����� */          30*ODNA_MINUTA
#define TAJMAUT_ZADYERZHKA_NA_OTKACHKU /* C_20 - �������_��������_��_������� */ PYAT__SYEKUND

#define VKL /* C_21 - ��� */                1
#define VYK /* C_22 - ��� */               0
#define OTKR /* C_23 - ���� */              1
#define ZAKR /* C_24 - ���� */          	0
#define YEST_ /* C_25 - ���� */               1
#define NYET /* C_26 - ��� */                0
#define NORMA /* C_27 - ����� */              1
#define VNYE_NORMY /* C_28 - ���_����� */          0
#define DOSTOVYERNO /* C_29 - ���������� */                1
#define NYEDOSTOVYERNO /* C_30 - ������������ */               0


#define TAJMAUT_NA_DIAGNOSTIKU_RAZRYVA_SVYAZI /* C_31 - �������_��_�����������_�������_����� */ 5*ODNA_SYEKUNDA

#define T_Pryedyel_nayaVbakyeOkhlazhdyeniya /* C_32 - �_������������������������� */          99.0 

  

#define T_GISTYERYEZIS_VODY_V_BAKYE /* C_33 - �_����������_����_�_���� */  1.0
#define T_GISTYERYEZIS_VODY_V_RUBAKHYE /* C_34 - �_����������_����_�_������ */  1.0


enum EN0 {
    PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKIJ /* ��_���_�������_����_�_����_����������_������ */,
    PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKIJ /* ��_���_�������_����_�_����_����������_������� */,
	PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* ��_���_�������_����_�_����_����������_�_����� */,
	PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKAYA /* ��_���_�����������_����_�_����_����������_������ */,
	PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKAYA /* ��_���_�����������_����_�_����_����������_������� */,
	PK_GUI_TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* ��_���_�����������_����_�_����_����������_�_����� */,

    PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_NIZKAYA /* ��_���_�����������_����_�_�������_����������_������ */,
	PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_VYSOKAYA /* ��_���_�����������_����_�_�������_����������_������� */,
	PK_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_V_NORMYE /* ��_���_�����������_����_�_�������_����������_�_����� */,

	PK_GUI_DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_V_NORMYE /* ��_���_��������_�_���������_�����_�_����� */,
	PK_GUI_DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_VNYE_NORMY /* ��_���_��������_�_���������_�����_���_����� */,
	
	PK_GUI_SKOROST__OTKACHKI_V_NORMYE /* ��_���_��������_�������_�_����� */,
	PK_GUI_SKOROST__OTKACHKI_NIZHYE_NORMY /* ��_���_��������_�������_����_����� */,
	
	PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_V_NORMYE /* ��_���_��������_�_����_�����������_�_����� */,
    PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY /* ��_���_��������_�_����_�����������_����_����� */
	

	
};
enum EN1 {
     KOM_GUI_OTKR_ZATVOR_VAK /* ���_���_����_������_��� */= PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY + 1,
     KOM_GUI_ZAKR_ZATVOR_VAK /* ���_���_����_������_��� */    	,
     KOM_GUI_OTKR_SAPUN /* ���_���_����_����� */			    ,
     KOM_GUI_ZAKR_SAPUN /* ���_���_����_����� */			    ,
     KOM_GUI_VKL_USTR_PLAV_PUSKA /* ���_���_���_����_����_����� */    ,
     KOM_GUI_VYK_USTR_PLAV_PUSKA /* ���_���_���_����_����_����� */    ,
	 KOM_GUI_VKL_PIT_VAK_NASOSA /* ���_���_���_���_���_������ */     ,
	 KOM_GUI_VYK_PIT_VAK_NASOSA /* ���_���_���_���_���_������ */     ,
	 KOM_GUI_VKL_PIT_VYENTILYATOR /* ���_���_���_���_���������� */    ,
	 KOM_GUI_VYK_PIT_VYENTILYATOR /* ���_���_���_���_���������� */    ,
     KOM_GUI_VKL_PIT_RYEG_T /* ���_���_���_���_���_� */    ,
	 KOM_GUI_VYK_PIT_RYEG_T /* ���_���_���_���_���_� */    ,
     KOM_GUI_VKL_PIT_RYEG_UR /* ���_���_���_���_���_�� */     ,
	 KOM_GUI_VYK_PIT_RYEG_UR /* ���_���_���_���_���_�� */     , 
	 KOM_GUI_VKL_PIT_NAS_OKHL /* ���_���_���_���_���_��� */ ,
	 KOM_GUI_VYK_PIT_NAS_OKHL /* ���_���_���_���_���_��� */    , 
	 KOM_GUI_VKL_VAKUUMIROVANIYE_TRUBY /* ���_���_���_��������������_����� */,
	 KOM_GUI_VYK_VAKUUMIROVANIYE_TRUBY /* ���_���_���_��������������_����� */,
	 KOM_GUI_VKL_VAKUUMNUYU_PODSISTYEMU /* ���_���_���_���������_���������� */ ,
	 KOM_GUI_VYK_VAKUUMNUYU_PODSISTYEMU /* ���_���_���_���������_���������� */,   
     KOMANDY_OT_GUI /* �������_��_��� */ = KOM_GUI_VYK_VAKUUMNUYU_PODSISTYEMU 
	
 
	
};


enum EN2 {
	IZMN_FP_P_VbakyeKompryessora /* ����_��_P_���������������� */ = KOMANDY_OT_GUI + 1,
	IZMN_FP_P_Vpatrubkye /* ����_��_P_��������� */,
	IZMN_FP_T_Vrubashkye /* ����_��_T_�������� */,	
	IZMN_FP_T_Vbakye /* ����_��_T_����� */,	
    IZMN_FP_P_VtrubyeSidyer /* ����_��_P_����������� */,
    KOMANDY_IZM_FP /* �������_���_�� */ = IZMN_FP_P_VtrubyeSidyer  
  
};

enum EN3 {                    
      PK_GUI_OTKAZ_OTKRYTIYA_ZATVORA_VAKUUMNOGO /* ��_���_�����_��������_�������_���������� */ = KOMANDY_IZM_FP + 1,
      PK_GUI_OTKAZ_ZAKRYTIYA_ZATVORA_VAKUUMNOGO /* ��_���_�����_��������_�������_���������� */,
      PK_GUI_OTKAZ_OTKRYTIYA_SAPUNA /* ��_���_�����_��������_������ */,
      PK_GUI_OTKAZ_ZAKRYTIYA_SAPUNA /* ��_���_�����_��������_������ */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_VYENTILYATORA /* ��_���_�����_���������_����������� */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_VYENTILYATORA /* ��_���_�����_����������_����������� */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_USTR_PLAV_PUSKA /* ��_���_�����_���������_����_����_����� */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_USTR_PLAV_PUSKA /* ��_���_�����_����������_����_����_����� */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_RYEGULYATORA_TYEMPYERATURY /* ��_���_�����_���������_����������_����������� */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_RYEGULYATORA_TYEMPYERATURY /* ��_���_�����_����������_����������_����������� */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_RYEGULYATORA_UROVNYA /* ��_���_�����_���������_����������_������ */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_RYEGULYATORA_UROVNYA /* ��_���_�����_����������_����������_������ */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_NASOSA_OKHLAZHDYENIYA /* ��_���_�����_���������_������_���������� */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_NASOSA_OKHLAZHDYENIYA /* ��_���_�����_����������_������_���������� */,
	  PK_GUI_IDYET_VAKUUMIROVANIYE_OTKAZ_VYPOLNYENIYA_KOMANDY /* ��_���_����_��������������_�����_����������_������� */,
	  PK_GUI_NYET_USLOVIJ_DLYA_VYPOLNYENIYA_KOMANDY /* ��_���_���_�������_���_����������_������� */,
	  PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VNYE_NORMY_OTKAZ_VYPOLNYENI /* ��_���_�������_����_�_����_����������_���_�����_�����_��������� */, 				
	  PK_GUI_OTRITSATYEL_NAYA_TYEMPYERATURA_VODY_OTKAZ_VYPOLNYENIYA_KOMANDY /* ��_���_�������������_�����������_����_�����_����������_������� */,
	  PK_GUI_DAVLYENIYE_V_PATRUBKYE_NYE_UMYEN_SHAYETSYA /* ��_���_��������_�_��������_��_����������� */,
	  PK_GUI_DAVLYENIYE_V_VAK_TRUBYE_NYE_UMYEN_SHAYETSYA /* ��_���_��������_�_���_�����_��_����������� */,
	  PK_GUI_VAKUUMIROVANIYE_USPYESHNO_ZAVYERSHYENO /* ��_���_��������������_�������_��������� */,	  
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA /* ��_���_�����_���������_�������_����������_������ */,   
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA /* ��_���_�����_����������_�������_����������_������ */,
	  PK_GUI_VYENTILYATOR_VKLYUCHYEN /* ��_���_����������_������� */,
	  PK_GUI_VYENTILYATOR_VYKLYUCHYEN /* ��_���_����������_�������� */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_VYENTILYATORA /* ��_���_����������_����������_����������� */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_VYENTILYATORA /* ��_���_����������_���������_����������� */,
	  PK_GUI_ZATVOR_VAKUUMNYJ_OTKRYT /* ��_���_������_���������_������ */,
	  PK_GUI_ZATVOR_VAKUUMNYJ_ZAKRYT /* ��_���_������_���������_������ */,
	  PK_GUI_SPONTANNOYE_OTKRYTIYE_ZAT_VAKUUMNOGO /* ��_���_����������_��������_���_���������� */,
	  PK_GUI_SPONTANNOYE_ZAKRYTIYE_ZAT_VAKUUMNOGO /* ��_���_����������_��������_���_���������� */,
	  PK_GUI_SAPUN_OTKRYT /* ��_���_�����_������ */,
	  PK_GUI_SAPUN_ZAKRYT /* ��_���_�����_������ */,
	  PK_GUI_SPONTANNOYE_OTKRYTIYE_SAPUNA /* ��_���_����������_��������_������ */,
	  PK_GUI_SPONTANNOYE_ZAKRYTIYE_SAPUNA /* ��_���_����������_��������_������ */,
	  PK_GUI_PITANIYE_VAKUUMNOGO_NASOSA_VKLYUCHYENO /* ��_���_�������_����������_������_�������� */,
	  PK_GUI_PITANIYE_VAKUUMNOGO_NASOSA_VYKLYUCHYENO /* ��_���_�������_����������_������_��������� */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_VAKUUMNOGO_NASOSA /* ��_���_����������_���������_����������_������ */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_VAKUUMNOGO_NASOSA /* ��_���_����������_����������_����������_������ */,
	  PK_GUI_PITANIYE_RYEGULYATORA_TYEMPYERATURY_VKLYUCHYENO /* ��_���_�������_����������_�����������_�������� */,
	  PK_GUI_PITANIYE_RYEGULYATORA_TYEMPYERATURY_VYKLYUCHYENO /* ��_���_�������_����������_�����������_��������� */,
  	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_RYEGULYATORA_TYEMPYERATURY /* ��_���_����������_���������_����������_����������� */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_RYEGULYATORA_TYEMPYERATURY /* ��_���_����������_����������_����������_����������� */,
	  PK_GUI_PITANIYE_RYEGULYATORA_UROVNYA_VKLYUCHYENO /* ��_���_�������_����������_������_�������� */,
	  PK_GUI_PITANIYE_RYEGULYATORA_UROVNYA_VYKLYUCHYENO /* ��_���_�������_����������_������_��������� */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_RYEGULYATORA_UROVNYA /* ��_���_����������_���������_����������_������ */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_RYEGULYATORA_UROVNYA /* ��_���_����������_����������_����������_������ */,
	  PK_GUI_PITANIYE_NASOSA_OKHLAZHDYENIYA_VKLYUCHYENO /* ��_���_�������_������_����������_�������� */,
	  PK_GUI_PITANIYE_NASOSA_OKHLAZHDYENIYA_VYKLYUCHYENO /* ��_���_�������_������_����������_��������� */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_NASOSA_OKHLAZHDYENIYA /* ��_���_����������_���������_������_���������� */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_NASOSA_OKHLAZHDYENIYA /* ��_���_����������_����������_������_���������� */,
	  PK_GUI_USTROJSTVO_PLAVNOGO_PUSKA_VKLYUCHYENO /* ��_���_����������_��������_�����_�������� */,
	  PK_GUI_USTROJSTVO_PLAVNOGO_PUSKA_VYKLYUCHYENO /* ��_���_����������_��������_�����_��������� */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_USTROJSTVA_PLAVNOGO_PUSKA /* ��_���_����������_���������_����������_��������_����� */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_USTROJSTVA_PLAVNOGO_PUSKA /* ��_���_����������_����������_����������_��������_����� */,
	  PK_GUI_OTKAZ_VAKUUMIROVANIYA /* ��_���_�����_�������������� */,
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_VAKUUMNOJ_PODSISTYEMY /* ��_���_�����_���������_���������_���������� */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_VAKUUMNOJ_PODSISTYEMY /* ��_���_�����_����������_���������_���������� */,
	  PK_GUI_YEST__DOSTOVYERNOST__KONTROLYA_OTKRYTIYA_ZATVORA_VAKUUMNOGO /* ��_���_����_�������������_��������_��������_�������_���������� */,
      PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_OTKRYTIYA_ZATVORA_VAKUUMNOGO /* ��_���_���_�������������_��������_��������_�������_���������� */,
	  PK_GUI_YEST__DOSTOVYERNOST__KONTROLYA_ZAKRYTIYA_ZATVORA_VAKUUMNOGO /* ��_���_����_�������������_��������_��������_�������_���������� */,
	  PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_ZAKRYTIYA_ZATVORA_VAKUUMNOGO /* ��_���_���_�������������_��������_��������_�������_���������� */,
      PK_GUI_YEST__DOSTOVYERNOST__KONTROLYA_SAPUNA /* ��_���_����_�������������_��������_������ */,
	  PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_SAPUNA /* ��_���_���_�������������_��������_������ */,
	  PK_GUI_YEST__DOSTOVYERNOST__KONTROLYA_USTR_PLAV_PUSKA /* ��_���_����_�������������_��������_����_����_����� */,
	  PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_USTR_PLAV_PUSKA /* ��_���_���_�������������_��������_����_����_����� */,
	  PK_GUI_YEST__DOSTOVYERNOST__KONTROLYA_PIT_VAK_NASOSA /* ��_���_����_�������������_��������_���_���_������ */,
	  PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_PIT_VAK_NASOSA /* ��_���_���_�������������_��������_���_���_������ */,
	  PK_GUI_YEST__DOSTOVYERNOST__KONTROLYA_PIT_VYENTILYATORA /* ��_���_����_�������������_��������_���_����������� */,
	  PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_PIT_VYENTILYATORA /* ��_���_���_�������������_��������_���_����������� */

};


enum EN4 {                    
      PK_GUI_FP_P_VbakyeKompryessora /* ��_���_��_P_���������������� */ = PK_GUI_NYET_DOSTOVYERNOSTI_KONTROLYA_PIT_VYENTILYATORA + 1,
      PK_GUI_FP_P_Vpatrubkye /* ��_���_��_P_��������� */,
      PK_GUI_FP_T_Vrubashkye /* ��_���_��_T_�������� */,
      PK_GUI_FP_T_Vbakye /* ��_���_��_T_����� */,
      PK_GUI_FP_P_VtrubyeSidyer /* ��_���_��_P_����������� */
      

      
};
enum EN5 {
IZMN_NP_1 /* ����_��_1 */ = PK_GUI_FP_P_VtrubyeSidyer + 1,
IZMN_NP_P_VbakyeKompryessora /* ����_��_P_���������������� */ = IZMN_NP_1,
IZMN_NP_Patmosf /* ����_��_P������ */,
IZMN_NP_GlubokijVakuumTruby /* ����_��_������������������� */,

IZMN_NP_N /* ����_��_N */

};



enum EN6 {
     PK_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ��_���_������_����_�������_��_��� */ = IZMN_NP_N + 1  
  
};