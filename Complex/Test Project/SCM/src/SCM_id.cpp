#include <stdio.h>
#include "SCM_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("SCM_constants.cfg","w");
	i = VKL; /* C_0 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VryemyaNaOtklik; /* C_2 - ������������� */
	fputs( "������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_POMYESTIT__RUKI; /* ���2���_���������_���� */
	fputs( "���2���_���������_���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_UBRAT__RUKI; /* ���2���_������_���� */
	fputs( "���2���_������_���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_SLOMAT__SUSHILKU; /* ���2���_�������_������� */
	fputs( "���2���_�������_������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_SUSHILKA_RABOTAYET; /* ���2���_�������_�������� */
	fputs( "���2���_�������_�������� = " , file);
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

 	i = BUS2BV_Dlya_provyerki; /* ���2��_���_�������� */
	fputs( "���2��_���_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE; /* ���2��_�������������_������_����������_��������� */
	fputs( "���2��_�������������_������_����������_��������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE; /* ���2��_�������������_������_����������_���������� */
	fputs( "���2��_�������������_������_����������_���������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY; /* ���2��_�������������_��������������_����������_����_�������� */
	fputs( "���2��_�������������_��������������_����������_����_�������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2BV_NYEISPRAVNOST__NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RU; /* ���2��_�������������_�������������_��������������_����������_�� */
	fputs( "���2��_�������������_�������������_��������������_����������_�� = " , file);
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

 	fclose(file);
}
