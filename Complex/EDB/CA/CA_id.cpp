#include <stdio.h>
#include "CA_id.h"
main () {
	int i;
	FILE * file;
	char string[2 * 132];
	file = fopen("CA_constants.cfg","w");
	i = VKL; /* C_0 - бйк */
	fputs( "бйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = VYKL; /* C_1 - бшйк */
	fputs( "бшйк = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_V_RUCHNOYE_UPRAVLYENIYE; /* юс2цсх_б_псвмне_сопюбкемхе */
	fputs( "юс2цсх_б_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* юс2цсх_нрйкчвхрэ_псвмне_сопюбкемхе */
	fputs( "юс2цсх_нрйкчвхрэ_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_VKLYUCHIT__SUSHILKU; /* юс2цсх_бйкчвхрэ_ясьхкйс */
	fputs( "юс2цсх_бйкчвхрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_VYKLYUCHIT__SUSHILKU; /* юс2цсх_бшйкчвхрэ_ясьхкйс */
	fputs( "юс2цсх_бшйкчвхрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_YEST__SUSHILKA_V_RUCHNOYE_UPRAVLYENIYE; /* йнл2юс_еярэ_ясьхкйю_б_псвмне_сопюбкемхе */
	fputs( "йнл2юс_еярэ_ясьхкйю_б_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_YEST__OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* йнл2юс_еярэ_нрйкчвхрэ_псвмне_сопюбкемхе */
	fputs( "йнл2юс_еярэ_нрйкчвхрэ_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_SUSHILKA_VYKLYUCHYENA; /* йнл2юс_ясьхкйю_бшйкчвемю */
	fputs( "йнл2юс_ясьхкйю_бшйкчвемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_SUSHILKA_VKLYUCHYENA; /* йнл2юс_ясьхкйю_бйкчвемю */
	fputs( "йнл2юс_ясьхкйю_бйкчвемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
