    

#define VKL /* C_0 - ��� */                1
#define VYKL /* C_1 - ���� */               0
#define MINIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_2 - �����������_�������_R_������� */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI /* C_3 - ������������_�������_R_������� */        200.0    

#define MINIMAL_NOYE_ZADANIYE_W_UglovojSkorosti /* C_4 - �����������_�������_W_��������������� */            0.0    
#define MAKSIMAL_NOYE_ZADANIYE_W_UglovojSkorosti /* C_5 - ������������_�������_W_��������������� */        200.0     


#define R_PO_UMOLCHANIYU /* C_6 - R_��_��������� */ 0.0
#define W_PO_UMOLCHANIYU /* C_7 - W_��_��������� */ 0.0
#define R_FP_PO_UMOLCHANIYU /* C_8 - R_��_��_��������� */ 0.0
#define FP_W_PO_UMOLCHANIYU /* C_9 - ��_W_��_��������� */ 0.0

#define TAJMAUT_VOZD_PODUSHKI /* C_10 - �������_����_������� */ 10
#define TAJMAUT_KLAPANOV /* C_11 - �������_�������� */ 10


enum EN0 {
KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_NORMU /* ���_�������_����_��������_�_����� */,
KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_NIZKOYE /* ���_�������_����_��������_�_������ */,
KOM_VKHODNAYA_TYEST_DAVLYENIYE_V_AVARINOYE /* ���_�������_����_��������_�_�������� */,
KOM_VKHODNAYA_TYEST_OPORA_ISPRAVNA /* ���_�������_����_�����_�������� */,
KOM_VKHODNAYA_TYEST_OPORA_OTKAZ_VKLYUCHYENIYA /* ���_�������_����_�����_�����_��������� */,
KOM_VKHODNAYA_TYEST_OPORA_OTKAZ_VYKLYUCHYENIYA /* ���_�������_����_�����_�����_���������� */,
KOM_VKHODNAYA_TYEST_KARYETKA_ISPRAVNA /* ���_�������_����_�������_�������� */,
KOM_VKHODNAYA_TYEST_KARYETKA_OTKAZ_VKLYUCHYENIYA /* ���_�������_����_�������_�����_��������� */,
KOM_VKHODNAYA_TYEST_KARYETKA_OTKAZ_VYKLYUCHYENIYA /* ���_�������_����_�������_�����_���������� */,
KOM_VKHODNAYA_TYEST_SHPINDYEL__ISPRAVYEN /* ���_�������_����_��������_�������� */,
KOM_VKHODNAYA_TYEST_SHPINDYEL__OTKAZ_VKLYUCHYENIYA /* ���_�������_����_��������_�����_��������� */,
KOM_VKHODNAYA_TYEST_SHPINDYEL__OTKAZ_VYKLYUCHYENIYA /* ���_�������_����_��������_�����_���������� */,
KOM_VKHODNAYA_TYEST_SVYETODIOD_ISPRAVYEN /* ���_�������_����_���������_�������� */,
KOM_VKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VKLYUCHYENIYA /* ���_�������_����_���������_�����_��������� */,
KOM_VKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VYKLYUCHYENIYA /* ���_�������_����_���������_�����_���������� */,
KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_ISPRAVYEN /* ���_�������_����_������_���������_�������� */,
KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKAZ_VKLYUCHYENIYA /* ���_�������_����_������_���������_�����_��������� */,
KOM_VKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKAZ_VYKLYUCHYENIYA /* ���_�������_����_������_���������_�����_���������� */,
KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_ISPRAVYEN /* ���_�������_����_������_�������_�������� */,
KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKAZ_VKLYUCHYENIYA /* ���_�������_����_������_�������_�����_��������� */,
KOM_VKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKAZ_VYKLYUCHYENIYA /* ���_�������_����_������_�������_�����_���������� */,

KOM_VKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE /* ���_�������_����_�����������_��������� */

};

enum EN1 {
	KOM_VYKHODNAYA_TYEST_IZMN_R_KARYETKI /* ���_��������_����_����_R_������� */ = KOM_VKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE + 1, 
	KOM_VYKHODNAYA_TYEST_IZMN_W_KARYETKI /* ���_��������_����_����_W_������� */,  		
	KOM_VYKHODNAYA_TYEST_IZMN_R_FP_KARYETKI /* ���_��������_����_����_R_��_������� */,
	KOM_VYKHODNAYA_TYEST_IZMN_W_FP_KARYETKI /* ���_��������_����_����_W_��_������� */,
	KOM_VYKHODNAYA_TYEST_DAVLYENIYE_V_NORMYE /* ���_��������_����_��������_�_����� */,
	KOM_VYKHODNAYA_TYEST_DAVLYENIYE_NIZKOYE /* ���_��������_����_��������_������ */,
	KOM_VYKHODNAYA_TYEST_DAVYELYENIYE_AVARIJNOYE /* ���_��������_����_���������_��������� */,
	KOM_VYKHODNAYA_OSHIBKA_KODA_KOMANDY_OT_GUI /* ���_��������_������_����_�������_��_��� */,
	KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_OPORU /* ���_��������_����_������_�����_��_����� */,
	KOM_VYKHODNAYA_TYEST_NA_OPORYE_STOLA_AVARIJNOYE_DAVLYENIYE /* ���_��������_����_��_�����_�����_���������_�������� */,
	KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_OPORU /* ���_��������_����_���������_������_�������_��_����� */,
	KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_KARYETKU /* ���_��������_����_������_�����_��_������� */,
	KOM_VYKHODNAYA_TYEST_NA_KARYETKYE_AVARIJNOYE_DAVLYENIYE /* ���_��������_����_��_�������_���������_�������� */,
	KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_KARYETKU /* ���_��������_����_���������_������_�������_��_������� */,
	KOM_VYKHODNAYA_TYEST_VOZDUKH_PODAN_NA_SHPINDYEL_ /* ���_��������_����_������_�����_��_�������� */,
	KOM_VYKHODNAYA_TYEST_PRYEDUPRYEZHDYENIYE_VOZDUKH_PODAN_NA_SHPINDYEL__NA_KA /* ���_��������_����_��������������_������_�����_��_��������_��_�� */,
	KOM_VYKHODNAYA_TYEST_PRYEDUPRYEZHDYENIYE_VOZDUKH_PODAN_NA_SHPINDYEL__NA_OP /* ���_��������_����_��������������_������_�����_��_��������_��_�� */,
	KOM_VYKHODNAYA_TYEST_NA_SHPINDYELYE_AVARIJNOYE_DAVLYENIYE /* ���_��������_����_��_��������_���������_�������� */,
	KOM_VYKHODNAYA_TYEST_VYKLYUCHYENA_PODACHA_VOZDUKHA_NA_SHPINDYEL_ /* ���_��������_����_���������_������_�������_��_�������� */,
	KOM_VYKHODNAYA_TYEST_PITANIYE_PODANO_NA_LAZYER /* ���_��������_����_�������_������_��_����� */,
	KOM_VYKHODNAYA_TYEST_PITANIYE_NA_LAZYERYE_NYET /* ���_��������_����_�������_��_������_��� */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_VKLYUCHYEN /* ���_��������_����_���������_������� */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_VYKLYUCHYEN /* ���_��������_����_���������_�������� */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VKLYUCHYENIYA /* ���_��������_����_���������_�����_��������� */,
	KOM_VYKHODNAYA_TYEST_SVYETODIOD_OTKAZ_VYKLYUCHYENIYA /* ���_��������_����_���������_�����_���������� */,
	KOM_VYKHODNAYA_TYEST_NASOS_VYKLYUCHYEN /* ���_��������_����_�����_�������� */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_NASOS_VKLYUCHYEN /* ���_��������_����_������_�����_������� */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_OTKRYT /* ���_��������_����_������_���������_������ */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_ATMOSFYERY_ZAKRYT /* ���_��������_����_������_���������_������ */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_VAKUUMA_OTKRYT /* ���_��������_����_������_�������_������ */,
	KOM_VYKHODNAYA_TYEST_KLAPAN_VAKUUMA_ZAKRYT /* ���_��������_����_������_�������_������ */,
	KOM_VYKHODNAYA_TYEST_OBA_KLAPANA_OTKRYTY_DISK_RAZAZHAT /* ���_��������_����_���_�������_�������_����_������� */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_OTKRYT_ATMOSFYERA_ZAKRYT_DISK_ZAZHAT /* ���_��������_����_������_������_���������_������_����_����� */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_OTKRYT_ATMOSFYERA_ZAKRYT_DISK_RAZZHAT /* ���_��������_����_������_������_���������_������_����_������ */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_OTKRYT_DISK_RAZAZHAT /* ���_��������_����_������_������_���������_������_����_������� */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_ZAKRYT_DISK_ZAZHAT /* ���_��������_����_������_������_���������_������_����_����� */,
	KOM_VYKHODNAYA_TYEST_VAKUUM_ZAKRYT_ATMOSFYERA_ZAKRYT_DISK_RAZZHAT /* ���_��������_����_������_������_���������_������_����_������ */,
	KOM_VYKHODNAYA_TYEST_KONTROL_NOYE_SOOBSCHYENIYE /* ���_��������_����_�����������_��������� */ 
  
 };
 
 
 
 enum EN2 {
	DAVLYENIYE_AVARIJNOYE /* ��������_��������� */,
	DAVLYENIYE_NIZKOYE /* ��������_������ */,
	DAVLYENIYE_V_NORMYE /* ��������_�_����� */
 
 };
 
 enum EN3 {
	ISPRAVNOST_ /* ����������� */,
	OTKAZ_VKLYUCHYENIYA /* �����_��������� */,
	OTKAZ_VYKLYUCHYENIYA /* �����_���������� */

};