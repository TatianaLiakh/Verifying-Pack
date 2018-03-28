/* MAIN FILE OF THE PROJECT */
#include "CAext.h" /* Common files for all generated c-files */
#include "CAproc.h"  /* Process-functions desription */
#include "CAgvar.h"  /* Project variables images */
#include "CAio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* ”правл€ющий алгоритм */
{
	Input();
	P0();  /* Process »нициализаци€ */
	P1();  /* Process „тение ольцевогоЅуфера */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}