#include <stdio.h>
#include "VM_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("VM_constants.cfg","w");
	i = VKL; /* C_0 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = OzhidaniyeOtvyetaOtAlgoritma; /* C_2 - ������������������������� */
	fputs( "������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZadyerzhkaOb_yekta; /* C_3 - ��������������� */
	fputs( "��������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_V_RUCHNOYE_UPRAVLYENIYE; /* ���2��_�_������_���������� */
	fputs( "���2��_�_������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* ���2��_���������_������_���������� */
	fputs( "���2��_���������_������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VKLYUCHIT__SUSHILKU; /* ���2��_��������_������� */
	fputs( "���2��_��������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VYKLYUCHIT__SUSHILKU; /* ���2��_���������_������� */
	fputs( "���2��_���������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_YEST__SUSHILKA_V_RUCHNOYE_UPRAVLYENIYE; /* ��2���_����_�������_�_������_���������� */
	fputs( "��2���_����_�������_�_������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_YEST__OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* ��2���_����_���������_������_���������� */
	fputs( "��2���_����_���������_������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_SUSHILKA_VYKLYUCHYENA; /* ��2���_�������_��������� */
	fputs( "��2���_�������_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_SUSHILKA_VKLYUCHYENA; /* ��2���_�������_�������� */
	fputs( "��2���_�������_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE; /* ���2��_������_����������_��������� */
	fputs( "���2��_������_����������_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE; /* ���2��_������_����������_���������� */
	fputs( "���2��_������_����������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY; /* ���2��_��������������_����������_����_�������� */
	fputs( "���2��_��������������_����������_����_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY; /* ���2��_��������������_����������_����_������ */
	fputs( "���2��_��������������_����������_����_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_KONYETS_SHTANOGO_RYEZHIMA; /* ���2��_�����_�������_������ */
	fputs( "���2��_�����_�������_������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2BUS_SLYEDUYUSCHIJ_STSYENARIJ; /* ��2���_���������_�������� */
	fputs( "��2���_���������_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2BUS_OSHIBKA_OSTANOV; /* ��2���_������_������� */
	fputs( "��2���_������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno; /* ��2���_��������������������������������� */
	fputs( "��2���_��������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno; /* ��2���_���������������������������������� */
	fputs( "��2���_���������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VklyuchyeniyeAvtomatichyeskoyeUspyeshno; /* ��2���_������������������������������ */
	fputs( "��2���_������������������������������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VyklyuchyeniyeAvtomatichyeskoyeUspyeshno; /* ��2���_������������������������������� */
	fputs( "��2���_������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_; /* ��2���_ */
	fputs( "��2���_ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno; /* ��2���_����������������������������������� */
	fputs( "��2���_����������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno; /* ��2���_������������������������������������ */
	fputs( "��2���_������������������������������������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_Samoproizvol_noyeOtklyuchyeniyeRyezhimaRuchnogoUpravlyeniya; /* ��2���_������������������������������������������������� */
	fputs( "��2���_������������������������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_Samoproizvol_noyeVklyuchyeniyeRyezhimaRuchnogoUpravlyeniya; /* ��2���_������������������������������������������������ */
	fputs( "��2���_������������������������������������������������ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_OSHIBKA_Samoproizvol_noyeVyklyuchyeniyeVavtomatRyezhimye; /* ��2���_������_���������������������������������������� */
	fputs( "��2���_������_���������������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BV2GOO_OSHIBKA_Samoproizvol_noyeVklyuchyeniyeVavtomatRyezhimye; /* ��2���_������_��������������������������������������� */
	fputs( "��2���_������_��������������������������������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
