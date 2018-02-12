#include <stdio.h>
#include "lp07_id.c"
main () {
	int i;
	FILE * file;
	char string[2 * 1024];
	file = fopen("lp07_cnfg.cnfg","w");
	i = VKL; /* C_0 - ÂÊË */
	fputs( "ÂÊË = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - ÂÛÊË */
	fputs( "ÂÛÊË = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
