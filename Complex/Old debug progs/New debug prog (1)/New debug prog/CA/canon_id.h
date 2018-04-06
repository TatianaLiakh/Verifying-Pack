    
#define ODNA_SYEKUNDA /* C_0 - ����_������� */               10  
#define DVYE_SYEKUNDY /* C_1 - ���_������� */             2*ODNA_SYEKUNDA
#define TRI_SYEKUNDY /* C_2 - ���_������� */             3*ODNA_SYEKUNDA
#define PYAT__SYEKUND /* C_3 - ����_������ */             5*ODNA_SYEKUNDA
#define DYESYAT__SYEKUND /* C_4 - ������_������ */          10*ODNA_SYEKUNDA
#define DVADTSAT__SYEKUND /* C_5 - ��������_������ */        20*ODNA_SYEKUNDA
#define TRIDTSAT__SYEKUND /* C_6 - ��������_������ */        30*ODNA_SYEKUNDA
#define ODNA_MINUTA /* C_7 - ����_������ */            60*ODNA_SYEKUNDA
#define DVYE_MINUTY /* C_8 - ���_������ */             2*ODNA_MINUTA
#define PYAT__MINUT /* C_9 - ����_����� */             5*60*ODNA_SYEKUNDA
#define DYESYAT__MINUT /* C_10 - ������_����� */			 10*ODNA_MINUTA
#define PYATNADTSAT__MINUT /* C_11 - ����������_����� */       15*ODNA_MINUTA
#define TRIDTSAT__MINUT /* C_12 - ��������_����� */         30*ODNA_MINUTA

#define TAJMAUT_VOZD_PODUSHKI /* C_13 - �������_����_������� */		TRI_SYEKUNDY
#define TAJMAUT_NASOSA_VAKUUMNOGO /* C_14 - �������_������_���������� */	DVADTSAT__SYEKUND
#define TAJMAUT_ZAZHIMA_DISKA /* C_15 - �������_������_����� */		DVADTSAT__SYEKUND
#define TAJMAUT_RAZZHIMA_DISKA /* C_16 - �������_�������_����� */		DVADTSAT__SYEKUND

#define TAJMAUT_NA_SRABATYVANIYE_KLAPANA_KARYETKI /* C_17 - �������_��_������������_�������_������� */          	TRI_SYEKUNDY   
#define TAJMAUT_NA_SRABATYVANIYE_KLAPANA_SHPINDYELYA_D /* C_18 - �������_��_������������_�������_��������_� */       	TRI_SYEKUNDY   

#define TAJMAUT_NA_SVYAZ__S_GIO /* C_19 - �������_��_�����_�_��� */  DYESYAT__SYEKUND

#define VKL /* C_20 - ��� */                1
#define VYK /* C_21 - ��� */               0
#define VYKL /* C_22 - ���� */               0
#define OTKR /* C_23 - ���� */              1
#define ZAKR /* C_24 - ���� */          	0
#define YEST_ /* C_25 - ���� */               1
#define NYET /* C_26 - ��� */                0
#define NI_DA_NI_NYET /* C_27 - ��_��_��_��� */       2


#define MINIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_28 - �����������_�������_R_������� */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_29 - ������������_�������_R_������� */        200.0    

#define MINIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA /* C_30 - �����������_�������_W_�����������_������� */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA /* C_31 - ������������_�������_W_�����������_������� */        200.0     

enum EN0 {
    RYEZHIM_INITSIALIZATSII /* �����_������������� */ = 1,
    RYEZHIM_RR /* �����_�� */,
    RYEZHIM_OTMYENA /* �����_������ */        ,
    RYEZHIM_KONYETS_RABOTY /* �����_�����_������ */,  
	KONYETS_KODOV_RYEZHIMOV /* �����_�����_������� */       
       
};

enum EN1 {
    GIO2SUAB_RYEZHIM_OTMYENA /* ���2����_�����_������ */ = KONYETS_KODOV_RYEZHIMOV,
    GIO2SUAB_RYEZHIM_KONYETS_RABOTY /* ���2����_�����_�����_������ */,  
	GIO2SUAB_ZAZHAT__DISK /* ���2����_������_���� */ , 
	GIO2SUAB_RAZZHAT__DISK /* ���2����_�������_���� */,
	GIO2SUAB_KO_ISPRAVNOST__VOZDUSHNYKH_PODUSHYEK /* ���2����_��_�����������_���������_������� */,
	GIO2SUAB_OTKAZ_VOZDUSHNYKH_PODUSHYEK /* ���2����_�����_���������_������� */,
	GIO2SUAB_KARYETKU_V_POLOZHYENIYE_USTANOVKI_DISKA /* ���2����_�������_�_���������_���������_����� */,
   	GIO2SUAB_KARYETKU_V_TSYENTR_VRASCHYENIYA /* ���2����_�������_�_�����_�������� */,
	GIO2SUAB_KARYETKU_V_ZADANNYJ_RADIUS /* ���2����_�������_�_��������_������ */,
	GIO2SUAB_STOP_KARYETKI /* ���2����_����_������� */,
	GIO2SUAB_VKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU /* ���2����_���_��������_����������������_��_�������� */,
	GIO2SUAB_VYKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU /* ���2����_����_��������_����������������_��_�������� */,
	GIO2SUAB_VKL_VRASCHYENIYE_PRYED_STOLIKA_V_ZD_W /* ���2����_���_��������_����_�������_�_��_W */,  
	GIO2SUAB_STOP_VRASCHYENIYA_PRYEDMYETNOGO_STOLIKA /* ���2����_����_��������_�����������_������� */,
	GIO2SUAB_VKL_PODSVYETKU_DISKA /* ���2����_���_���������_����� */,  
	GIO2SUAB_VYKL_PODSVYETKU_DISKA /* ���2����_����_���������_����� */,
	
	FIK2SUAB_YEST__SVYAZ__S_MOKHA1212 /* ���2����_����_�����_�_����1212 */,
	FIK2SUAB_NYET_SVYAZI_S_MOKHA1212 /* ���2����_���_�����_�_����1212 */,
	FIK2SUAB_YEST__SVYAZ__S_MOKHA1214 /* ���2����_����_�����_�_����1214 */,
	FIK2SUAB_NYET_SVYAZI_S_MOKHA1214 /* ���2����_���_�����_�_����1214 */,


	GIO2SUAB_IZMN_ZD_R_KARYETKI /* ���2����_����_��_R_������� */,
    GIO2SUAB_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA /* ���2����_����_��_W_�����������_������� */,	
	GIO2SUAB_KONYETS_KODOV_FIK /* ���2����_�����_�����_��� */	
	
	
	
};

enum EN2 {
	
	SUAB2FIK_DAVLYENIYE_V_NORMYE /* ����2���_��������_�_����� */ = 0,
	SUAB2FIK_DAVLYENIYE_NIZHYE_NORMY /* ����2���_��������_����_����� */,
	SUAB2FIK_DAVLYENIYE_AVARIJNOYE /* ����2���_��������_��������� */,
	
	SUAB2FIK_PROVYER__VOZDUSHNUYU_PODUSHKU /* ����2���_�������_���������_������� */,
	SUAB2FIK_BLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA /* ����2���_����������_������_����������� */,
	SUAB2FIK_RAZBLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA /* ����2���_�������������_������_����������� */,
	SUAB2FIK_IZMN_ZD_R_KARYETKI /* ����2���_����_��_R_������� */,
	SUAB2FIK_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA /* ����2���_����_��_W_�����������_������� */,

	
	SUAB2FIK_DISK_ZAZHAT /* ����2���_����_����� */,
	SUAB2FIK_DISK_RAZZHAT /* ����2���_����_������ */,
	SUAB2FIK_AVARIJNOYE_RAZZHATIYE_DISKA /* ����2���_���������_��������_����� */,
	SUAB2FIK_OTKAZ_ZAZHIMA_DISKA /* ����2���_�����_������_����� */,
	SUAB2FIK_OTKAZ_RAZZHIMA_DISKA /* ����2���_�����_�������_����� */,
	SUAB2FIK_OSVYESCHYENIYE_DISKA_VKLYUCHYENO /* ����2���_���������_�����_�������� */,
	SUAB2FIK_OSVYESCHYENIYE_DISKA_VYKLYUCHYENO /* ����2���_���������_�����_��������� */,
	
	
	SUAB2FIK_YEST__SVYAZ__S_MOKHA1212 /* ����2���_����_�����_�_����1212 */,
	SUAB2FIK_NYET_SVYAZI_S_MOKHA1212 /* ����2���_���_�����_�_����1212 */,
	SUAB2FIK_YEST__SVYAZ__S_MOKHA1214 /* ����2���_����_�����_�_����1214 */,
	SUAB2FIK_NYET_SVYAZI_S_MOKHA1214 /* ����2���_���_�����_�_����1214 */,
	
	SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1212 /* ����2���_����_�������������_����������_1212 */,
	SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1212 /* ����2���_���_��������������_����������_1212 */,
	SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1214 /* ����2���_����_�������������_����������_1214 */,
	SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1214 /* ����2���_���_��������������_����������_1214 */,
	SUAB2FIK_RYEZHIM_INITSIALIZATSIYA /* ����2���_�����_������������� */,
	SUAB2FIK_RYEZHIM_RR /* ����2���_�����_�� */,
	SUAB2FIK_RYEZHIM_OTMYENA /* ����2���_�����_������ */,
	SUAB2FIK_RYEZHIM_KONYETS_RABOTY /* ����2���_�����_�����_������ */,
	SUAB2FIK_USTANOVKA_GOTOVA_K_VYKLYUCHYENIYU /* ����2���_���������_������_�_���������� */,
	SUAB2FIK_KONYETS_KODOV_SPK /* ����2���_�����_�����_��� */ 
 
};	


enum EN3 {
	SUAB2FIK_IZMN_FP_R_KARYETKI /* ����2���_����_��_R_������� */ = SUAB2FIK_KONYETS_KODOV_SPK + 1,
	SUAB2FIK_IZMN_FP_W_PRYEDMYETNOGO_STOLIKA /* ����2���_����_��_W_�����������_������� */,
	KOMANDY_IZM_FP /* �������_���_�� */ = SUAB2FIK_IZMN_FP_W_PRYEDMYETNOGO_STOLIKA 	
 	
};

enum EN4 {
	SUAB2FIK_ZD_R_KARYETKI_VNYE_DIAPAZONA /* ����2���_��_R_�������_���_��������� */ = KOMANDY_IZM_FP + 1,
	SUAB2FIK_ZD_W_PRYEDMYETNOGO_STOLIKA_VNYE_DIAPAZONA /* ����2���_��_W_�����������_�������_���_��������� */

};

enum EN5 {                    
   
	
	SUAB2FIK_VKLYUCHITYE_KOMPRYESSOR /* ����2���_��������_���������� */ = SUAB2FIK_ZD_W_PRYEDMYETNOGO_STOLIKA_VNYE_DIAPAZONA +1



};	


enum EN6 { 
	IZMN_NP_1 /* ����_��_1 */ = SUAB2FIK_VKLYUCHITYE_KOMPRYESSOR + 1,
	IZMN_NP_N /* ����_��_N */

};
enum EN7 {
    SUAB2FIK_OSHIBKA_KODA_KOMANDY_OT_GIO /* ����2���_������_����_�������_��_��� */ = IZMN_NP_N + 1,
	SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_RR /* ����2���_������_�����������_�������_������_�� */,
	SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_INITSIALIZATSII /* ����2���_������_�����������_�������_������_������������� */	 
	 
	 
	 
};