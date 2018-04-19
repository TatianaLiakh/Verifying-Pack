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

 	i = KOM2AU_V_RUCHNOYE_UPRAVLYENIYE; /* йнл2юс_б_псвмне_сопюбкемхе */
	fputs( "йнл2юс_б_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* йнл2юс_нрйкчвхрэ_псвмне_сопюбкемхе */
	fputs( "йнл2юс_нрйкчвхрэ_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VKLYUCHIT__SUSHILKU; /* йнл2юс_бйкчвхрэ_ясьхкйс */
	fputs( "йнл2юс_бйкчвхрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = KOM2AU_VYKLYUCHIT__SUSHILKU; /* йнл2юс_бшйкчвхрэ_ясьхкйс */
	fputs( "йнл2юс_бшйкчвхрэ_ясьхкйс = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_YEST__SUSHILKA_V_RUCHNOYE_UPRAVLYENIYE; /* юс2цсх_еярэ_ясьхкйю_б_псвмне_сопюбкемхе */
	fputs( "юс2цсх_еярэ_ясьхкйю_б_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_YEST__OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE; /* юс2цсх_еярэ_нрйкчвхрэ_псвмне_сопюбкемхе */
	fputs( "юс2цсх_еярэ_нрйкчвхрэ_псвмне_сопюбкемхе = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_SUSHILKA_VYKLYUCHYENA; /* юс2цсх_ясьхкйю_бшйкчвемю */
	fputs( "юс2цсх_ясьхкйю_бшйкчвемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	i = AU2GUI_SUSHILKA_VKLYUCHYENA; /* юс2цсх_ясьхкйю_бйкчвемю */
	fputs( "юс2цсх_ясьхкйю_бйкчвемю = " , file);
	sprintf(string, "%d\n", i );
	fputs( string, file);

 	fclose(file);
}
