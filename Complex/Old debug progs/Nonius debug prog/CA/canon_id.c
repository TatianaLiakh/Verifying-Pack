#include <stdio.h>
#include "canon_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("canon_constants.cfg","w");
	i = ODNA_SYEKUNDA; /* C_0 - ����_������� */
	fputs( "����_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVYE_SYEKUNDY; /* C_1 - ���_������� */
	fputs( "���_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRI_SYEKUNDY; /* C_2 - ���_������� */
	fputs( "���_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYAT__SYEKUND; /* C_3 - ����_������ */
	fputs( "����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DYESYAT__SYEKUND; /* C_4 - ������_������ */
	fputs( "������_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVADTSAT__SYEKUND; /* C_5 - ��������_������ */
	fputs( "��������_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRIDTSAT__SYEKUND; /* C_6 - ��������_������ */
	fputs( "��������_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ODNA_MINUTA; /* C_7 - ����_������ */
	fputs( "����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DVYE_MINUTY; /* C_8 - ���_������ */
	fputs( "���_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYAT__MINUT; /* C_9 - ����_����� */
	fputs( "����_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = DYESYAT__MINUT; /* C_10 - ������_����� */
	fputs( "������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = PYATNADTSAT__MINUT; /* C_11 - ����������_����� */
	fputs( "����������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TRIDTSAT__MINUT; /* C_12 - ��������_����� */
	fputs( "��������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_VOZD_PODUSHKI; /* C_13 - �������_����_������� */
	fputs( "�������_����_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NASOSA_VAKUUMNOGO; /* C_14 - �������_������_���������� */
	fputs( "�������_������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_ZAZHIMA_DISKA; /* C_15 - �������_������_����� */
	fputs( "�������_������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_RAZZHIMA_DISKA; /* C_16 - �������_�������_����� */
	fputs( "�������_�������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_KLAPANA_KARYETKI; /* C_17 - �������_��_������������_�������_������� */
	fputs( "�������_��_������������_�������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SRABATYVANIYE_KLAPANA_SHPINDYELYA_D; /* C_18 - �������_��_������������_�������_��������_� */
	fputs( "�������_��_������������_�������_��������_� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = TAJMAUT_NA_SVYAZ__S_GIO; /* C_19 - �������_��_�����_�_��� */
	fputs( "�������_��_�����_�_��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VKL; /* C_20 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYK; /* C_21 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_22 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OTKR; /* C_23 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZAKR; /* C_24 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = YEST_; /* C_25 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NYET; /* C_26 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = NI_DA_NI_NYET; /* C_27 - ��_��_��_��� */
	fputs( "��_��_��_��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MINIMAL_NOYE_ZADANIYE_R_KARYETKI; /* C_28 - �����������_�������_R_������� */
	fputs( "�����������_�������_R_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NOYE_ZADANIYE_R_KARYETKI; /* C_29 - ������������_�������_R_������� */
	fputs( "������������_�������_R_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MINIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA; /* C_30 - �����������_�������_W_�����������_������� */
	fputs( "�����������_�������_W_�����������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = MAKSIMAL_NOYE_ZADANIYE_W_PRYEDMYETNOGO_STOLIKA; /* C_31 - ������������_�������_W_�����������_������� */
	fputs( "������������_�������_W_�����������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_INITSIALIZATSII; /* �����_������������� */
	fputs( "�����_������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_RR; /* �����_�� */
	fputs( "�����_�� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_OTMYENA; /* �����_������ */
	fputs( "�����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = RYEZHIM_KONYETS_RABOTY; /* �����_�����_������ */
	fputs( "�����_�����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KONYETS_KODOV_RYEZHIMOV; /* �����_�����_������� */
	fputs( "�����_�����_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_RYEZHIM_OTMYENA; /* ���2����_�����_������ */
	fputs( "���2����_�����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_RYEZHIM_KONYETS_RABOTY; /* ���2����_�����_�����_������ */
	fputs( "���2����_�����_�����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_ZAZHAT__DISK; /* ���2����_������_���� */
	fputs( "���2����_������_���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_RAZZHAT__DISK; /* ���2����_�������_���� */
	fputs( "���2����_�������_���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KO_ISPRAVNOST__VOZDUSHNYKH_PODUSHYEK; /* ���2����_��_�����������_���������_������� */
	fputs( "���2����_��_�����������_���������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_OTKAZ_VOZDUSHNYKH_PODUSHYEK; /* ���2����_�����_���������_������� */
	fputs( "���2����_�����_���������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KARYETKU_V_POLOZHYENIYE_USTANOVKI_DISKA; /* ���2����_�������_�_���������_���������_����� */
	fputs( "���2����_�������_�_���������_���������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KARYETKU_V_TSYENTR_VRASCHYENIYA; /* ���2����_�������_�_�����_�������� */
	fputs( "���2����_�������_�_�����_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KARYETKU_V_ZADANNYJ_RADIUS; /* ���2����_�������_�_��������_������ */
	fputs( "���2����_�������_�_��������_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_STOP_KARYETKI; /* ���2����_����_������� */
	fputs( "���2����_����_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU; /* ���2����_���_��������_����������������_��_�������� */
	fputs( "���2����_���_��������_����������������_��_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VYKL_AKTIVNOYE_POZITSIONIROVANIYE_PO_VRASCHYENIYU; /* ���2����_����_��������_����������������_��_�������� */
	fputs( "���2����_����_��������_����������������_��_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VKL_VRASCHYENIYE_PRYED_STOLIKA_V_ZD_W; /* ���2����_���_��������_����_�������_�_��_W */
	fputs( "���2����_���_��������_����_�������_�_��_W = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_STOP_VRASCHYENIYA_PRYEDMYETNOGO_STOLIKA; /* ���2����_����_��������_�����������_������� */
	fputs( "���2����_����_��������_�����������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VKL_PODSVYETKU_DISKA; /* ���2����_���_���������_����� */
	fputs( "���2����_���_���������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_VYKL_PODSVYETKU_DISKA; /* ���2����_����_���������_����� */
	fputs( "���2����_����_���������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_YEST__SVYAZ__S_MOKHA1212; /* ���2����_����_�����_�_����1212 */
	fputs( "���2����_����_�����_�_����1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_NYET_SVYAZI_S_MOKHA1212; /* ���2����_���_�����_�_����1212 */
	fputs( "���2����_���_�����_�_����1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_YEST__SVYAZ__S_MOKHA1214; /* ���2����_����_�����_�_����1214 */
	fputs( "���2����_����_�����_�_����1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = FIK2SUAB_NYET_SVYAZI_S_MOKHA1214; /* ���2����_���_�����_�_����1214 */
	fputs( "���2����_���_�����_�_����1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_IZMN_ZD_R_KARYETKI; /* ���2����_����_��_R_������� */
	fputs( "���2����_����_��_R_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA; /* ���2����_����_��_W_�����������_������� */
	fputs( "���2����_����_��_W_�����������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = GIO2SUAB_KONYETS_KODOV_FIK; /* ���2����_�����_�����_��� */
	fputs( "���2����_�����_�����_��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DAVLYENIYE_V_NORMYE; /* ����2���_��������_�_����� */
	fputs( "����2���_��������_�_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DAVLYENIYE_NIZHYE_NORMY; /* ����2���_��������_����_����� */
	fputs( "����2���_��������_����_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DAVLYENIYE_AVARIJNOYE; /* ����2���_��������_��������� */
	fputs( "����2���_��������_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_PROVYER__VOZDUSHNUYU_PODUSHKU; /* ����2���_�������_���������_������� */
	fputs( "����2���_�������_���������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_BLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA; /* ����2���_����������_������_����������� */
	fputs( "����2���_����������_������_����������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RAZBLOKIROVKA_KOMAND_PYERYEMYESCHYENIYA; /* ����2���_�������������_������_����������� */
	fputs( "����2���_�������������_������_����������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_ZD_R_KARYETKI; /* ����2���_����_��_R_������� */
	fputs( "����2���_����_��_R_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_ZD_W_PRYEDMYETNOGO_STOLIKA; /* ����2���_����_��_W_�����������_������� */
	fputs( "����2���_����_��_W_�����������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DISK_ZAZHAT; /* ����2���_����_����� */
	fputs( "����2���_����_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_DISK_RAZZHAT; /* ����2���_����_������ */
	fputs( "����2���_����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_AVARIJNOYE_RAZZHATIYE_DISKA; /* ����2���_���������_��������_����� */
	fputs( "����2���_���������_��������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OTKAZ_ZAZHIMA_DISKA; /* ����2���_�����_������_����� */
	fputs( "����2���_�����_������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OTKAZ_RAZZHIMA_DISKA; /* ����2���_�����_�������_����� */
	fputs( "����2���_�����_�������_����� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSVYESCHYENIYE_DISKA_VKLYUCHYENO; /* ����2���_���������_�����_�������� */
	fputs( "����2���_���������_�����_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSVYESCHYENIYE_DISKA_VYKLYUCHYENO; /* ����2���_���������_�����_��������� */
	fputs( "����2���_���������_�����_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__SVYAZ__S_MOKHA1212; /* ����2���_����_�����_�_����1212 */
	fputs( "����2���_����_�����_�_����1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_SVYAZI_S_MOKHA1212; /* ����2���_���_�����_�_����1212 */
	fputs( "����2���_���_�����_�_����1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__SVYAZ__S_MOKHA1214; /* ����2���_����_�����_�_����1214 */
	fputs( "����2���_����_�����_�_����1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_SVYAZI_S_MOKHA1214; /* ����2���_���_�����_�_����1214 */
	fputs( "����2���_���_�����_�_����1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1212; /* ����2���_����_�������������_����������_1212 */
	fputs( "����2���_����_�������������_����������_1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1212; /* ����2���_���_��������������_����������_1212 */
	fputs( "����2���_���_��������������_����������_1212 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_YEST__DISTANTSIONNOYE_UPRAVLYENIYE_1214; /* ����2���_����_�������������_����������_1214 */
	fputs( "����2���_����_�������������_����������_1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_NYET_DISTANTSIONNOGO_UPRAVLYENIYA_1214; /* ����2���_���_��������������_����������_1214 */
	fputs( "����2���_���_��������������_����������_1214 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_INITSIALIZATSIYA; /* ����2���_�����_������������� */
	fputs( "����2���_�����_������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_RR; /* ����2���_�����_�� */
	fputs( "����2���_�����_�� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_OTMYENA; /* ����2���_�����_������ */
	fputs( "����2���_�����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_RYEZHIM_KONYETS_RABOTY; /* ����2���_�����_�����_������ */
	fputs( "����2���_�����_�����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_USTANOVKA_GOTOVA_K_VYKLYUCHYENIYU; /* ����2���_���������_������_�_���������� */
	fputs( "����2���_���������_������_�_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_KONYETS_KODOV_SPK; /* ����2���_�����_�����_��� */
	fputs( "����2���_�����_�����_��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_FP_R_KARYETKI; /* ����2���_����_��_R_������� */
	fputs( "����2���_����_��_R_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_IZMN_FP_W_PRYEDMYETNOGO_STOLIKA; /* ����2���_����_��_W_�����������_������� */
	fputs( "����2���_����_��_W_�����������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOMANDY_IZM_FP; /* �������_���_�� */
	fputs( "�������_���_�� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_ZD_R_KARYETKI_VNYE_DIAPAZONA; /* ����2���_��_R_�������_���_��������� */
	fputs( "����2���_��_R_�������_���_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_ZD_W_PRYEDMYETNOGO_STOLIKA_VNYE_DIAPAZONA; /* ����2���_��_W_�����������_�������_���_��������� */
	fputs( "����2���_��_W_�����������_�������_���_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_VKLYUCHITYE_KOMPRYESSOR; /* ����2���_��������_���������� */
	fputs( "����2���_��������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_1; /* ����_��_1 */
	fputs( "����_��_1 = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = IZMN_NP_N; /* ����_��_N */
	fputs( "����_��_N = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSHIBKA_KODA_KOMANDY_OT_GIO; /* ����2���_������_����_�������_��_��� */
	fputs( "����2���_������_����_�������_��_��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_RR; /* ����2���_������_�����������_�������_������_�� */
	fputs( "����2���_������_�����������_�������_������_�� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = SUAB2FIK_OSHIBKA_ZAPRYESCHYENNAYA_KOMANDA_RYEZHIMA_INITSIALIZATSII; /* ����2���_������_�����������_�������_������_������������� */
	fputs( "����2���_������_�����������_�������_������_������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
