#include <stdio.h>
#include "VP_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("VP_constants.cfg","w");
	i = VKL; /* C_0 - ��� */
	fputs( "��� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - ���� */
	fputs( "���� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZadyerzhkaOb_yekta; /* C_2 - ��������������� */
	fputs( "��������������� = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZadyerzhkaDatchika; /* C_3 - ��������������� */
	fputs( "��������������� = " , file);
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

 	fclose(file);
}
