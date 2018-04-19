#include <stdio.h>
#include "VP_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("VP_constants.cfg","w");
	i = VKL; /* C_0 - бйк */
	fputs( "бйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - бшйк */
	fputs( "бшйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZadyerzhkaOb_yekta; /* C_2 - гЮДЕПФЙЮнАЗЕЙРЮ */
	fputs( "гЮДЕПФЙЮнАЗЕЙРЮ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = ZadyerzhkaDatchika; /* C_3 - гЮДЕПФЙЮдЮРВХЙЮ */
	fputs( "гЮДЕПФЙЮдЮРВХЙЮ = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_POMYESTIT__RUKI; /* ася2бнс_онлеярхрэ_псйх */
	fputs( "ася2бнс_онлеярхрэ_псйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_UBRAT__RUKI; /* ася2бнс_сапюрэ_псйх */
	fputs( "ася2бнс_сапюрэ_псйх = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_SLOMAT__SUSHILKU; /* ася2бнс_якнлюрэ_ясьхкйс */
	fputs( "ася2бнс_якнлюрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = BUS2VOU_SUSHILKA_RABOTAYET; /* ася2бнс_ясьхкйю_пюанрюер */
	fputs( "ася2бнс_ясьхкйю_пюанрюер = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
