    
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



#define TAJMAUT_NA_DIAGNOSTIKU_RAZRYVA_SVYAZI /* C_29 - �������_��_�����������_�������_����� */ 5*ODNA_SYEKUNDA

#define T_Pryedyel_nayaVbakyeOkhlazhdyeniya /* C_30 - �_������������������������� */          99.0 

#define ZD_P_VbakyeKompryessora /* C_31 - ��_P_���������������� */						10.0 

#define T_GISTYERYEZIS_VODY_V_BAKYE /* C_32 - �_����������_����_�_���� */  1.0
#define T_GISTYERYEZIS_VODY_V_RUBAKHYE /* C_33 - �_����������_����_�_������ */  1.0


enum EN0 {
    UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKIJ /* �������_����_�_����_����������_������ */,
    UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKIJ /* �������_����_�_����_����������_������� */,
	UROVYEN__VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* �������_����_�_����_����������_�_����� */,
	TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_NIZKAYA /* �����������_����_�_����_����������_������ */,
	TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_VYSOKAYA /* �����������_����_�_����_����������_������� */,
	TYEMPYERATURA_VODY_V_BAKYE_OKHLAZHDYENIYA_V_NORMYE /* �����������_����_�_����_����������_�_����� */,

    TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_NIZKAYA /* �����������_����_�_�������_����������_������ */,
	TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_VYSOKAYA /* �����������_����_�_�������_����������_������� */,
	TYEMPYERATURA_VODY_V_RUBASHKYE_OKHLAZHDYENIYA_V_NORMYE /* �����������_����_�_�������_����������_�_����� */,

	DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_V_NORMYE /* ��������_�_���������_�����_�_����� */,
	DAVLYENIYE_V_VAKUUMNOJ_TRUBYE_VNYE_NORMY /* ��������_�_���������_�����_���_����� */,
	
	SKOROST__OTKACHKI_V_NORMYE /* ��������_�������_�_����� */,
	SKOROST__OTKACHKI_NIZHYE_NORMY /* ��������_�������_����_����� */,
	
	DAVLYENIYE_V_BAKYE_KOMPRYESSORA_V_NORMYE /* ��������_�_����_�����������_�_����� */,
    DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY /* ��������_�_����_�����������_����_����� */


	



	
};
enum EN1 {
     OTKR_ZATVOR_VAK /* ����_������_��� */= DAVLYENIYE_V_BAKYE_KOMPRYESSORA_NIZHYE_NORMY + 1,
     ZAKR_ZATVOR_VAK /* ����_������_��� */    	,
     OTKR_SAPUN /* ����_����� */			    ,
     ZAKR_SAPUN /* ����_����� */			    ,
     VKL_USTR_PLAV_PUSKA /* ���_����_����_����� */    ,
     VYK_USTR_PLAV_PUSKA /* ���_����_����_����� */    ,
	 VKL_PIT_VAK_NASOSA /* ���_���_���_������ */     ,
	 VYK_PIT_VAK_NASOSA /* ���_���_���_������ */     ,
	 VKL_PIT_VYENTILYATOR /* ���_���_���������� */    ,
	 VYK_PIT_VYENTILYATOR /* ���_���_���������� */    ,
     VKL_PIT_RYEG_T /* ���_���_���_� */    ,
	 VYK_PIT_RYEG_T /* ���_���_���_� */    ,
     VKL_PIT_RYEG_UR /* ���_���_���_�� */     ,
	 VYK_PIT_RYEG_UR /* ���_���_���_�� */     , 
	 VKL_PIT_NAS_OKHL /* ���_���_���_��� */ ,
	 VYK_PIT_NAS_OKHL /* ���_���_���_��� */    , 
	 VKL_VAKUUMIROVANIYE_TRUBY /* ���_��������������_����� */,
	 VYK_VAKUUMIROVANIYE_TRUBY /* ���_��������������_����� */,
	 VKL_NASOS_VAKUUMNYJ /* ���_�����_��������� */ ,
	 VYK_NASOS_VAKUUMNYJ /* ���_�����_��������� */, 
     KOMANDY_OT_GUI /* �������_��_��� */ = VYK_NASOS_VAKUUMNYJ 
	
 
	
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
	  PK_GUI_OTKAZ_VKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA /* ��_���_�����_���������_�������_����������_������ */,
	  PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA /* ��_���_�����_����������_�������_����������_������ */
      
      

      
      
};
enum EN4 {                    
      PK_GUI_FP_P_VbakyeKompryessora /* ��_���_��_P_���������������� */ = PK_GUI_OTKAZ_VYKLYUCHYENIYA_PITANIYA_VAKUUMNOGO_NASOSA + 1,
      PK_GUI_FP_P_Vpatrubkye /* ��_���_��_P_��������� */,
      PK_GUI_FP_T_Vrubashkye /* ��_���_��_T_�������� */,
      PK_GUI_FP_T_Vbakye /* ��_���_��_T_����� */,
      PK_GUI_FP_P_VtrubyeSidyer /* ��_���_��_P_����������� */
      

      
};




enum EN5 {
     PK_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ��_���_������_����_�������_��_��� */ = PK_GUI_FP_P_VtrubyeSidyer + 1  
  
};