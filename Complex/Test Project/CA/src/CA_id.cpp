#include <stdio.h>
#include "CA_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("CA_constants.cfg","w");
	i = VKL; /* C_0 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - ���� */
	fputs( "���� = " , file);
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

 	fclose(file);
}
