    
#define T0_1 /* C_0 - �0_1 */                       0  
#define ODNA_SYEKUNDA /* C_1 - ����_������� */               10  
#define DVYE_SYEKUNDY /* C_2 - ���_������� */             2*ODNA_SYEKUNDA
#define TRI_SYEKUNDY /* C_3 - ���_������� */             3*ODNA_SYEKUNDA
#define TAJMAUT_NA_DOSTOVYERNOST_ /* C_4 - �������_��_������������� */ DVYE_SYEKUNDY
#define PYAT__SYEKUND /* C_5 - ����_������ */             5*ODNA_SYEKUNDA
#define MAKSIMAL_NAYA_DLITYEL_NOST__OTSUTSTVIYA_DOSTOVYERNOSTI /* C_6 - ������������_������������_����������_������������� */ PYAT__SYEKUND

#define DYESYAT__SYEKUND /* C_7 - ������_������ */          10*ODNA_SYEKUNDA
#define DVADTSAT__SYEKUND /* C_8 - ��������_������ */        20*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_ZAT_VAK /* C_9 - �������_��_������������_���_��� */			PYAT__SYEKUND	
#define TAJMAUT_NA_SRABATYVANIYE_SAPUNA /* C_10 - �������_��_������������_������ */           	TRI_SYEKUNDY   
#define TAJMAUT_NA_SRABATYVANIYE_USTR_PLAV_PUSKA /* C_11 - �������_��_������������_����_����_����� */   3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VAK_NASOSA /* C_12 - �������_��_������������_���_������ */ 		3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_VYENTILYATORA /* C_13 - �������_��_������������_����������� */		PYAT__SYEKUND
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_T /* C_14 - �������_��_������������_���_� */				3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_RYEG_UR /* C_15 - �������_��_������������_���_�� */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SRABATYVANIYE_NASOS_OKHL /* C_16 - �������_��_������������_�����_��� */			3*ODNA_SYEKUNDA
#define TAJMAUT_NA_SVYAZ__S_GUI /* C_17 - �������_��_�����_�_��� */  DYESYAT__SYEKUND
#define ODNA_MINUTA /* C_18 - ����_������ */          60*ODNA_SYEKUNDA
#define DVYE_MINUTY /* C_19 - ���_������ */          2*ODNA_MINUTA
#define PYAT__MINUT /* C_20 - ����_����� */          5*60*ODNA_SYEKUNDA
#define DYESYAT__MINUT /* C_21 - ������_����� */			10*ODNA_MINUTA
#define TRIDTSAT__MINUT /* C_22 - ��������_����� */          30*ODNA_MINUTA
#define PYATNADTSAT__MINUT /* C_23 - ����������_����� */          15*ODNA_MINUTA
#define TAJMAUT_ZADYERZHKA_NA_OTKACHKU /* C_24 - �������_��������_��_������� */ DYESYAT__SYEKUND

#define VKL /* C_25 - ��� */                1
#define VYK /* C_26 - ��� */               0
#define OTKR /* C_27 - ���� */              1
#define ZAKR /* C_28 - ���� */          	0
#define YEST_ /* C_29 - ���� */               1
#define NYET /* C_30 - ��� */                0
#define NIZHYE_NORMY /* C_31 - ����_����� */		0
#define NORMA /* C_32 - ����� */              1
#define VYSHYE_NORMY /* C_33 - ����_����� */		2
#define VNYE_NORMY /* C_34 - ���_����� */			0
#define DOSTOVYERNO /* C_35 - ���������� */                1
#define NYEDOSTOVYERNO /* C_36 - ������������ */               0
#define Nye_provyeryayutsya /* C_37 - ��_����������� */       0  
#define Provyeryayutsya /* C_38 - ����������� */      1

#define TAJMAUT_NA_DIAGNOSTIKU_RAZRYVA_SVYAZI /* C_39 - �������_��_�����������_�������_����� */ 5*ODNA_SYEKUNDA

#define T_Pryedyel_nayaVrubashkyeOkhlazhdyeniya /* C_40 - �_���������������������������� */          85.0 
#define T_Pryedyel_nayaVbakyeOkhlazhdyeniya /* C_41 - �_������������������������� */          65.0 

enum EN0 {
    PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKIJ /* ��_���_�������_����_�_����_����������_������ */,
    PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKIJ /* ��_���_�������_����_�_����_����������_������� */,
	PK_GUI_UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* ��_���_�������_����_�_����_����������_�_����� */,
	PK_GUI_OTKAZ_DATCHIKOV_UROVNYA /* ��_���_�����_��������_������ */,  
	
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
	PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_VYSHYE_NORMY /* ��_���_��������_�_����_�����������_����_����� */,  
    PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY /* ��_���_��������_�_����_�����������_����_����� */,
	
	
	PK_GUI_OTKAZ_VAKUUMIROVANIYA_OTKAZ_OBORUDOVANIYA /* ��_���_�����_��������������_�����_������������ */,
	PK_GUI_START_VYKLYUCHYENIYA_VAKUUMIROVANIYA_TRUBY /* ��_���_�����_����������_��������������_����� */,
	PK_GUI_START_VYKLYUCHYENIYA_VAKUUMNOGO_NASOSA /* ��_���_�����_����������_����������_������ */
	

	
};
enum EN1 {
     KOM_GUI_OTKR_ZATVOR_VAK /* ���_���_����_������_��� */= PK_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY + 1,
     KOM_GUI_ZAKR_ZATVOR_VAK /* ���_���_����_������_��� */    	,
     KOM_GUI_OTKR_SAPUN /* ���_���_����_����� */			    ,
     KOM_GUI_ZAKR_SAPUN /* ���_���_����_����� */			    ,
     KOM_GUI_VKL_USTR_PLAV_PUSKA /* ���_���_���_����_����_����� */    ,
     KOM_GUI_VYK_USTR_PLAV_PUSKA /* ���_���_���_����_����_����� */    ,
 
 	 KOM_GUI_VKL_PIT_UPP_VAK_NASOSA /* ���_���_���_���_���_���_������ */     ,
	 KOM_GUI_VYK_PIT_UPP_VAK_NASOSA /* ���_���_���_���_���_���_������ */     ,
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
	 KOM_GUI_VKL_VAKUUMNYJ_NASOS /* ���_���_���_���������_����� */ ,
   
     KOMANDY_OT_GUI /* �������_��_��� */ = KOM_GUI_VKL_VAKUUMNYJ_NASOS 
	
 
	
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
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_PITANIYA_UPP_VAKUUMNOGO_NASOSA /* ��_���_�����_���������_�������_���_����������_������ */,   
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_UPP_VAKUUMNOGO_NASOSA /* ��_���_�����_����������_�������_���_����������_������ */,  
	  PK_GUI_NYEDOSTOVYERNYYE_DANNYYE_OBORUDOVANIYA_VAK_SISTYEMY /* ��_���_�������������_������_������������_���_������� */,
	  

		PK_GUI_AVARIYA_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_MYEN_SHYE_2kh_ATMOSFYER /* ��_���_������_��������_�_����_�����������_������_2�_�������� */, 
		PK_GUI_AVARIYA__SROCHNO_VYKLYUCHIT__VAK_SISTYEMU_V_RUCHNOM_RYEZHIMYE /* ��_���_������__������_���������_���_�������_�_������_������ */,	
		PK_GUI_AVARIYA_PYERYEGRYEV_RUBASHKI_OKHLAZHDYENIYA /* ��_���_������_��������_�������_���������� */,				
		PK_GUI_AVARIYA_PYERYEGRYEV_BAKA_OKHLAZHDYENIYA_NASOSA /* ��_���_������_��������_����_����������_������ */,					
		

	  PK_GUI_RYESTART_NYEDOSTOVYERNYYE_DANNYYE_OBORUDOVANIYA_VAK_SISTYEMY /* ��_���_�������_�������������_������_������������_���_������� */, 
	  PK_GUI_YEST__PITANIYE_SHKAFA_VS_380 /* ��_���_����_�������_�����_��_380 */,	
	  PK_GUI_NYET_PITANIYE_SHKAFA_VS_380 /* ��_���_���_�������_�����_��_380 */,	
	  PK_GUI_VYENTILYATOR_VKLYUCHYEN /* ��_���_����������_������� */,
	  PK_GUI_VYENTILYATOR_VYKLYUCHYEN /* ��_���_����������_�������� */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_VYENTILYATORA /* ��_���_����������_����������_����������� */,
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_VYENTILYATORA /* ��_���_����������_���������_����������� */,
	  PK_GUI_ZATVOR_VAKUUMNYJ_OTKRYT /* ��_���_������_���������_������ */,
	  PK_GUI_ZATVOR_VAKUUMNYJ_ZAKRYT /* ��_���_������_���������_������ */,
	  PK_GUI_SRYEDNYEYE_SOSTOYANIYE_ZATVORA_VAKUUMNOGO /* ��_���_�������_���������_�������_���������� */,
	  PK_GUI_SOSTOYANIYE_OSHIBKI_ZATVORA_VAKUUMNOGO /* ��_���_���������_������_�������_���������� */,
	  PK_GUI_SPONTANNOYE_OTKRYTIYE_ZAT_VAKUUMNOGO /* ��_���_����������_��������_���_���������� */,
	  PK_GUI_SPONTANNOYE_ZAKRYTIYE_ZAT_VAKUUMNOGO /* ��_���_����������_��������_���_���������� */,
	  PK_GUI_SAPUN_OTKRYT /* ��_���_�����_������ */,
	  PK_GUI_SAPUN_ZAKRYT /* ��_���_�����_������ */,
	  PK_GUI_SPONTANNOYE_OTKRYTIYE_SAPUNA /* ��_���_����������_��������_������ */,
	  PK_GUI_SPONTANNOYE_ZAKRYTIYE_SAPUNA /* ��_���_����������_��������_������ */,
	  PK_GUI_PITANIYE_UPP_VAKUUMNOGO_NASOSA_VKLYUCHYENO /* ��_���_�������_���_����������_������_�������� */,  
	  PK_GUI_PITANIYE_UPP_VAKUUMNOGO_NASOSA_VYKLYUCHYENO /* ��_���_�������_���_����������_������_��������� */,  
	  PK_GUI_SPONTANNOYE_VKLYUCHYENIYE_UPP_VAKUUMNOGO_NASOSA /* ��_���_����������_���������_���_����������_������ */,
	  PK_GUI_SPONTANNOYE_VYKLYUCHYENIYE_UPP_VAKUUMNOGO_NASOSA /* ��_���_����������_����������_���_����������_������ */,
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
	  PK_GUI_YEST__SVYAZ__S_KONTS_OTKRYTIYA_ZATV_VAKUUMNOGO /* ��_���_����_�����_�_����_��������_����_���������� */,
      PK_GUI_NYET_SVYAZI_S_KONTS_OTKRYTIYA_ZATV_VAKUUMNOGO /* ��_���_���_�����_�_����_��������_����_���������� */,
	  PK_GUI_YEST__SVYAZ__S_KONTS_ZAKRYTIYA_ZATV_VAKUUMNOGO /* ��_���_����_�����_�_����_��������_����_���������� */,
	  PK_GUI_NYET_SVYAZI_S_KONTS_ZAKRYTIYA_ZATV_VAKUUMNOGO /* ��_���_���_�����_�_����_��������_����_���������� */,
      PK_GUI_YEST__SVYAZ__S_SAPUNOM /* ��_���_����_�����_�_������� */,
	  PK_GUI_NYET_SVYAZI_S_SAPUNOM /* ��_���_���_�����_�_������� */,
	  PK_GUI_YEST__SVYAZ__S_PLAVNYM_PUSKOM /* ��_���_����_�����_�_�������_������ */,
	  PK_GUI_NYET_SVYAZI_S_PLAVNYM_PUSKOM /* ��_���_���_�����_�_�������_������ */,
	  PK_GUI_YEST__SVYAZ__S_PITANIYEM_VAK_NASOSA /* ��_���_����_�����_�_��������_���_������ */, 
	  PK_GUI_NYET_SVYAZI_S_PITANIYEM_VAK_NASOSA /* ��_���_���_�����_�_��������_���_������ */,	
	  PK_GUI_YEST__SVYAZ__S_VYENTILYATOROM /* ��_���_����_�����_�_������������ */,
	  PK_GUI_NYET_SVYAZI_S_VYENTILYATOROM /* ��_���_���_�����_�_������������ */,
	  PK_GUI_YEST__SVYAZ__S_RYEG_TYEMPYERATURY /* ��_���_����_�����_�_���_����������� */,  
	  PK_GUI_NYET_SVYAZI_S_RYEG_TYEMPYERATURY /* ��_���_���_�����_�_���_����������� */,
	  PK_GUI_YEST__SVYAZ__S_RYEG_UROVNYA /* ��_���_����_�����_�_���_������ */,
	  PK_GUI_NYET_SVYAZI_S_RYEG_UROVNYA /* ��_���_���_�����_�_���_������ */,
	  PK_GUI_YEST__SVYAZ__S_NIZHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ��_���_����_�����_�_������_����������_��_����_����_��� */,
	  PK_GUI_NYET_SVYAZI_S_NIZHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ��_���_���_�����_�_������_����������_��_����_����_��� */,
	  PK_GUI_YEST__SVYAZ__S_VYERKHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ��_���_����_�����_�_�������_����������_��_����_����_��� */,
	  PK_GUI_NYET_SVYAZI_S_VYERKHNIM_KONTSYEVIKOM_UR_VODY_BAKA_OKHL /* ��_���_���_�����_�_�������_����������_��_����_����_��� */,
	  PK_GUI_YEST__SVYAZ__S_NASOSOSOM_OKHL /* ��_���_����_�����_�_���������_��� */,
	  PK_GUI_NYET_SVYAZI_S_NASOSOSOM_OKHL /* ��_���_���_�����_�_���������_��� */,
	  PK_GUI_YEST__SVYAZ__S_PITANIYEM_SHKAFA_380 /* ��_���_����_�����_�_��������_�����_380 */,   
	  PK_GUI_NYET_SVYAZI_S_PITANIYEM_SHKAFA_380 /* ��_���_���_�����_�_��������_�����_380 */,		
		PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_BAKYE_KOMPRYESSORA /* ��_���_����_�����_�_���������_�_����_����������� */,
		PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_BAKYE_KOMPRYESSORA /* ��_���_���_�����_�_���������_�_����_����������� */,
		PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_PATRUBKYE /* ��_���_����_�����_�_���������_�_�������� */,		
		PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_PATRUBKYE /* ��_���_���_�����_�_���������_�_�������� */,		
		PK_GUI_YEST__SVYAZ__S_TYEMPYERATUROJ_V_RUBASHKYE_OKHL /* ��_���_����_�����_�_������������_�_�������_��� */,	
		PK_GUI_NYET_SVYAZI_S_TYEMPYERATUROJ_V_RUBASHKYE_OKHL /* ��_���_���_�����_�_������������_�_�������_��� */,	
		PK_GUI_YEST__SVYAZ__S_TYEMPYERATUROJ_V_BAKYE_OKHL /* ��_���_����_�����_�_������������_�_����_��� */,		
		PK_GUI_NYET_SVYAZI_S_TYEMPYERATUROJ_V_BAKYE_OKHL /* ��_���_���_�����_�_������������_�_����_��� */,		
		PK_GUI_YEST__SVYAZ__S_DAVLYENIYEM_V_TRUBYE_SID /* ��_���_����_�����_�_���������_�_�����_��� */,	
		PK_GUI_NYET_SVYAZI_S_DAVLYENIYEM_V_TRUBYE_SID /* ��_���_���_�����_�_���������_�_�����_��� */,	
	  PK_GUI_VAKUUMIROVANIYE_TRUBY_VKLYUCHYENO /* ��_���_��������������_�����_�������� */,
	  PK_GUI_VAKUUMIROVANIYE_TRUBY_VYKLYUCHYENO /* ��_���_��������������_�����_��������� */

};


enum EN4 {                    
      PK_GUI_FP_P_VbakyeKompryessora /* ��_���_��_P_���������������� */ = PK_GUI_VAKUUMIROVANIYE_TRUBY_VYKLYUCHYENO + 1,
      PK_GUI_FP_P_Vpatrubkye /* ��_���_��_P_��������� */,
      PK_GUI_FP_T_Vrubashkye /* ��_���_��_T_�������� */,
      PK_GUI_FP_T_Vbakye /* ��_���_��_T_����� */,
      PK_GUI_FP_P_VtrubyeSidyer /* ��_���_��_P_����������� */
      

      
};
enum EN5 {
IZMN_NP_1 /* ����_��_1 */ = PK_GUI_FP_P_VtrubyeSidyer + 1,
IZMN_NP_ZD_P_VbakyeKompryessora /* ����_��_��_P_���������������� */ = IZMN_NP_1,
IZMN_NP_ZD_Patmosf /* ����_��_��_P������ */,
IZMN_NP_ZD_P_VtrubyeSidyer /* ����_��_��_P_����������� */,	
IZMN_NP_ZD_T_VrubashkyeNizhnyaya /* ����_��_��_T_�������������� */,		
IZMN_NP_ZD_T_VrubashkyeVyerkhnyaya /* ����_��_��_T_��������������� */,	
IZMN_NP_ZD_T_VbakyeNizhnyaya /* ����_��_��_T_����������� */,
IZMN_NP_ZD_T_VbakyeVyerkhnyaya /* ����_��_��_T_������������ */,

IZMN_NP_ZD_PyeriodaKontrP_PriOtkachkye /* ����_��_��_������������P_���������� */,  
IZMN_NP_ZD_PyeriodaKontrP_PriNatyekanii /* ����_��_��_������������P_������������ */, 

IZMN_NP_ZD_Gist_T_Vbakye /* ����_��_��_����_T_����� */,
IZMN_NP_ZD_Gist_T_Vrubashkye /* ����_��_��_����_T_�������� */,
IZMN_NP_ZD_Gist_P_VbakyeKompryessora /* ����_��_��_����_P_���������������� */,
IZMN_NP_ZD_Gist_P_VtrubyeSidyerVyerkh /* ����_��_��_����_P_��������������� */,
IZMN_NP_ZD_Gist_P_VtrubyeSidyerNizh /* ����_��_��_����_P_�������������� */,

IZMN_NP_N /* ����_��_N */

};

enum EN6 {
     PK_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ��_���_������_����_�������_��_��� */ = IZMN_NP_N + 1  
  
};