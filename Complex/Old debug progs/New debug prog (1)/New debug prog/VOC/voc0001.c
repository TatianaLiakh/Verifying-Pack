/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "vocext.h" /* Common files for all generated c-files */
#include "vocxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
	 

		P0V24 = C_75;
		P0V25 = C_75;
		P0V26 = C_75;		
		P0V27 = C_75;
		P0V28 = C_75;
		P0V29 = C_75;
		
		P0V23 = C_74;
		
		P0V19 = C_6;
		P0V20 = C_7;		
		P0V21	= C_8; 
		P0V22 = 	C_9;
		
		SendMsgFloatParamGUI(C_34, P0V19);
		SendMsgFloatParamGUI(C_35, P0V20);
		SendMsgFloatParamGUI(C_36, P0V21);
		SendMsgFloatParamGUI(C_37, P0V22);
		Set_Start(1);
		Set_Start(2); 
		Set_Start(3); 
		Set_Start(6); 
		Set_Start(9); 
		Set_Start(15); 
		Set_Start(18); 
		Set_Start(19);
		
		
		Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* ПРОЦЕСС: ЧтениеКольцевогоБуфера */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - СОСТОЯНИЕ: Начало */

		
		if (GetNextMsgGUI()) 
		{
			P1V10 = GetMsgGUICode(); 
			switch (P1V10) {
				case C_12:
					P0V23 = C_74;
					break;
				case C_13:
					P0V23 = C_73;
					break;
				case C_14:
					P0V23 = C_72;
					break;
				
				case C_15:
					P0V24  = C_75;
					break;
				case C_16:
					P0V24  = C_76;
					break;
				case C_17:
					P0V24  = C_77;
					break;
				
				case C_18:
					P0V25  = C_75;
					break;
				case C_19:
					P0V25  = C_76;
					break;
				case C_20:
					P0V25  = C_77;
					break;
					
				case C_21:
					P0V26   = C_75;
					break;
				case C_22:
					P0V26   = C_76;
					break;
				case C_23:
					P0V26   = C_77;
					break;	
					
				case C_24:
					P0V27    = C_75;
					break;
				case C_25:
					P0V27    = C_76;
					break;
				case C_26:
					P0V27    = C_77;
					break;	
					
				case C_27:
					P0V28     = C_75;
					break;
				case C_28:
					P0V28     = C_76;
					break;
				case C_29:
					P0V28     = C_77;
					break;	
					
				case C_30:
					P0V29      = C_75;
					break;
				case C_31:
					P0V29      = C_76;
					break;
				case C_32:
					P0V29      = C_77;
					break;	
									
				default:
					Set_State(1, 1);
				break;
				}
		}
			break;
		case 1:    /*  P1S1() - СОСТОЯНИЕ: НекорректноеСобытие */

		SendMsgLongParamGUI(C_41, P0V17);
		Set_State(1, 0);
			break;
		default:
			break;
	}
}

void P2 (void) /* ПРОЦЕСС: КОНТРОЛЬ_ДАВЛЕНИЯ_ВОЗД_ПОДУШКИ */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - СОСТОЯНИЕ: Начало */
 
		if (P0V23 == C_74)
		{
			SendMsgGUICode(C_38);
			Set_State(2, 1);
		}
		else if (P0V23 == C_73)
		{
			Set_State(2, 2);	
			SendMsgGUICode(C_39);
		}
		else if (P0V23 == C_72)
		{
			Set_State(2, 3);
			SendMsgGUICode(C_40);
		}
			break;
		case 1:    /*  P2S1() - СОСТОЯНИЕ: ДавлениеВНорме */

		if (P0V23 == C_74) 
		{
			P0V7[1] = C_0;
			P0V6[1] = C_0;			
		}
		else Set_State(2, 0);
			break;
		case 2:    /*  P2S2() - СОСТОЯНИЕ: ДавлениеНизкое */

		if (P0V23 == C_73)
		{
			P0V7[1] = C_1;
			P0V6[1] = C_0;
		}
		else Set_State(2, 0);
			break;
		case 3:    /*  P2S3() - СОСТОЯНИЕ: ДавлениеАварийное */

		if (P0V23 == C_72)
		{
			P0V7[1] = C_1;
			P0V6[1] = C_1;			
		}
		else Set_State(2, 0);
			break;
		default:
			break;
	}
}

void P3 (void) /* ПРОЦЕСС: КонтрольПодачиВоздухаНаОпору */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - СОСТОЯНИЕ: Начало */

		Set_Stop(4);
		Set_Stop(5);
		if (P0V24 == C_75) Set_State(3, 1);
		else Set_State(3, 3);
			break;
		case 1:    /*  P3S1() - СОСТОЯНИЕ: ЗапускИсправногоОборудования */

		if (P0V2 == C_0) Set_Start(4);
		else if (P0V2 == C_1) Set_Start(5);
		Set_State(3, 2);
			break;
		case 2:    /*  P3S2() - СОСТОЯНИЕ: ИсправностьРаботы */

		if (P0V24 != C_75) Set_State(3, 0);
			break;
		case 3:    /*  P3S3() - СОСТОЯНИЕ: ИмитацияНеисправностиОборудования */

		if (P0V24 == C_76)  Set_Start(5);
		else if (P0V24 == C_77) Set_Start(4);
		Set_State(3, 4);
			break;
		case 4:    /*  P3S4() - СОСТОЯНИЕ: Неисправность */

		if (P0V24 != C_76
			&& P0V24 != C_77) Set_State(3, 0);
			break;
		default:
			break;
	}
}

void P4 (void) /* ПРОЦЕСС: ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ОПОРУ */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(4, C_10))  Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_42);
		Set_State(4, 2);
			break;
		case 2:    /*  P4S2() - СОСТОЯНИЕ: РаботаВоздушнойПодушкиНаОпоре */

		if ( (Check_State(2) == 3))
		{
			SendMsgGUICode(C_43);
			Set_State(4, 3);
		}
		else 
			break;
		case 3:    /*  P4S3() - СОСТОЯНИЕ: ОжиданиеНормльногоДавления */

	if ( !((Check_State(2) == 3)))
		Set_State(4, 0);
			break;
		default:
			break;
	}
}

void P5 (void) /* ПРОЦЕСС: ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ОПОРУ */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(5, C_10))  Set_State(5, 1);
			break;
		case 1:    /*  P5S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_44);
		Set_State(5, 2);
			break;
		case 2:    /*  P5S2() - СОСТОЯНИЕ: ВоздушнойПодушкиНаОпореНет */
 
			break;
		default:
			break;
	}
}

void P6 (void) /* ПРОЦЕСС: КонтрольПодачиВоздухаНаКаретку */
{
	switch (Check_State(6)) {

		case 0:    /*  P6S0() - СОСТОЯНИЕ: Начало */

		Set_Stop(7);
		Set_Stop(8);
		if (P0V25== C_75) Set_State(6, 1);
		else Set_State(6, 3);
			break;
		case 1:    /*  P6S1() - СОСТОЯНИЕ: ЗапускИсправногоОборудования */

		if (P0V0 == C_0) Set_Start(7);
		else if (P0V0 == C_1) Set_Start(8);
		Set_State(6, 2);
			break;
		case 2:    /*  P6S2() - СОСТОЯНИЕ: ИсправностьРаботы */

		if (P0V25 != C_75) Set_State(6, 0);
			break;
		case 3:    /*  P6S3() - СОСТОЯНИЕ: ИмитацияНеисправностиОборудования */

		if (P0V25 == C_76)  Set_Start(8);
		else if (P0V25 == C_77) Set_Start(7);
		Set_State(6, 4);
			break;
		case 4:    /*  P6S4() - СОСТОЯНИЕ: Неисправность */

		if (P0V25 != C_76 
			&& P0V25 != C_77) Set_State(6, 0);
			break;
		default:
			break;
	}
}

void P7 (void) /* ПРОЦЕСС: ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_КАРЕТКУ */
{
	switch (Check_State(7)) {

		case 0:    /*  P7S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(7, C_10))  Set_State(7, 1);
			break;
		case 1:    /*  P7S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_45);
		Set_State(7, 2);
			break;
		case 2:    /*  P7S2() - СОСТОЯНИЕ: РаботаВоздушнойПодушкиНаКаретке */

		if ( (Check_State(2) == 3))
		{
			SendMsgGUICode(C_46);
			Set_State(7, 3);
		}
		else 
			break;
		case 3:    /*  P7S3() - СОСТОЯНИЕ: ОжиданиеНормльногоДавления */

	if ( !((Check_State(2) == 3)))
		Set_State(7, 0);
			break;
		default:
			break;
	}
}

void P8 (void) /* ПРОЦЕСС: ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_КАРЕТКУ */
{
	switch (Check_State(8)) {

		case 0:    /*  P8S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(8, C_10))  Set_State(8, 1);
			break;
		case 1:    /*  P8S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_47);
		Set_State(8, 2);
			break;
		case 2:    /*  P8S2() - СОСТОЯНИЕ: ВоздушнойПодушкиНаКареткеНет */
 
			break;
		default:
			break;
	}
}

void P9 (void) /* ПРОЦЕСС: КонтрольПодачиВоздухаНаШпиндель */
{
	switch (Check_State(9)) {

		case 0:    /*  P9S0() - СОСТОЯНИЕ: Начало */

		Set_Stop(10);
		Set_Stop(11);
		if (P0V26== C_75) Set_State(9, 1);
		else Set_State(9, 3);
			break;
		case 1:    /*  P9S1() - СОСТОЯНИЕ: ЗапускИсправногоОборудования */

		if (P0V0 == C_0) Set_Start(10);
		else if (P0V0 == C_1) Set_Start(11);
		Set_State(9, 2);
			break;
		case 2:    /*  P9S2() - СОСТОЯНИЕ: ИсправностьРаботы */

		if (P0V26 != C_75) Set_State(9, 0);
			break;
		case 3:    /*  P9S3() - СОСТОЯНИЕ: ИмитацияНеисправностиОборудования */

		if (P0V26 == C_76)  Set_Start(11);
		else if (P0V26 == C_77) Set_Start(10);
		Set_State(9, 4);
			break;
		case 4:    /*  P9S4() - СОСТОЯНИЕ: Неисправность */

		if (P0V26 != C_76 
			&& P0V26 != C_77) Set_State(9, 0);
			break;
		default:
			break;
	}
}

void P10 (void) /* ПРОЦЕСС: ВКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ШПИНДЕЛЬ */
{
	switch (Check_State(10)) {

		case 0:    /*  P10S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(10, C_10))  Set_State(10, 1);
			break;
		case 1:    /*  P10S1() - СОСТОЯНИЕ: ОтправкаСообщений */

		SendMsgGUICode(C_48);
		if ((Check_State(7) == 2))
			SendMsgGUICode(C_49);
		if ((Check_State(4) == 2))
			SendMsgGUICode(C_50);
		Set_State(10, 2);
			break;
		case 2:    /*  P10S2() - СОСТОЯНИЕ: РаботаВоздушнойПодушкиНаШпнделе */

		if ( (Check_State(2) == 3))
		{
			SendMsgGUICode(C_51);
			Set_State(10, 3);
		}
		else 
			break;
		case 3:    /*  P10S3() - СОСТОЯНИЕ: ОжиданиеНормльногоДавления */

	if ( !((Check_State(2) == 3)))
		Set_State(10, 0);
			break;
		default:
			break;
	}
}

void P11 (void) /* ПРОЦЕСС: ВЫКЛЮЧЕНИЕ_ПОДАЧИ_ВОЗДУХА_НА_ШПИНДЕЛЬ */
{
	switch (Check_State(11)) {

		case 0:    /*  P11S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(11, C_10))  Set_State(11, 1);
			break;
		case 1:    /*  P11S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_52);
		Set_State(11, 2);
			break;
		case 2:    /*  P11S2() - СОСТОЯНИЕ: ВоздушнойПодушкиНаШпинделеНет */
 
			break;
		default:
			break;
	}
}

void P12 (void) /* ПРОЦЕСС: УправлениеПитаниемЛазера */
{
	switch (Check_State(12)) {

		case 0:    /*  P12S0() - СОСТОЯНИЕ: Начало */

		if (P0V10 == C_0)
			{ 
				SendMsgGUICode(C_53);
				Set_State(12, 1);
			}
		else 
		{
			SendMsgGUICode(C_54);
			Set_State(12, 2);
		}
			break;
		case 1:    /*  P12S1() - СОСТОЯНИЕ: ПитаниеПоданоНаЛазер */

		if (P0V10 != C_0) Set_State(12, 0);
			break;
		case 2:    /*  P12S2() - СОСТОЯНИЕ: ПитанияНаЛазереНет */

		if (P0V10 != C_1) Set_State(12, 0);
			break;
		default:
			break;
	}
}

void P13 (void) /* ПРОЦЕСС: УПРАВЛЕНИЕ_СВЕТОДИОДОМ */
{
	switch (Check_State(13)) {

		case 0:    /*  P13S0() - СОСТОЯНИЕ: Начало */

		if (P0V27 == C_75 )
			if (P0V13 == C_0) 
			{
				SendMsgGUICode(C_55);
				Set_State(13, 1);
			}
			else  
			{	
				SendMsgGUICode(C_56);
				Set_State(13, 2);
			}
		else if (P0V27 == C_76 ) 
			{
				SendMsgGUICode(C_57);
				Set_State(13, 3);
			}
		else if (P0V27 == C_77)
		{
			SendMsgGUICode(C_58);
			Set_State(13, 4);
		}
			break;
		case 1:    /*  P13S1() - СОСТОЯНИЕ: СветодиодИсправенИВключен */

		if (P0V27 != C_75 ||  P0V13 != C_0) Set_State(13, 0);
			break;
		case 2:    /*  P13S2() - СОСТОЯНИЕ: СветодиодИсправенИВыключен */

		if (P0V27 != C_75 ||  P0V13 != C_1) Set_State(13, 0);
			break;
		case 3:    /*  P13S3() - СОСТОЯНИЕ: СветодиодНЕИсправенИВыключен */

		if (P0V27 != C_76 ) Set_State(13, 0);
			break;
		case 4:    /*  P13S4() - СОСТОЯНИЕ: СветодиодНЕИсправенИВключен */

		if (P0V27 != C_77 ) Set_State(13, 0);
			break;
		default:
			break;
	}
}

void P14 (void) /* ПРОЦЕСС: УПРАВЛЕНИЕ_НАСОСОМ */
{
	switch (Check_State(14)) {

		case 0:    /*  P14S0() - СОСТОЯНИЕ: Начало */

		if (P0V4 == C_1)
		{
			SendMsgGUICode(C_59);
			Set_State(14, 1);
		}
		else if (P0V4 == C_0)
		{
			SendMsgGUICode(C_60);
			Set_State(14, 2);
		}
			break;
		case 1:    /*  P14S1() - СОСТОЯНИЕ: НасосВыключен */

		if (P0V4 != C_1) Set_State(14, 0);
			break;
		case 2:    /*  P14S2() - СОСТОЯНИЕ: НасосВключен */

		if (P0V4 != C_0) Set_State(14, 0);
			break;
		default:
			break;
	}
}

void P15 (void) /* ПРОЦЕСС: КонтрольКлапанаАтмосферы */
{
	switch (Check_State(15)) {

		case 0:    /*  P15S0() - СОСТОЯНИЕ: Начало */

		Set_Stop(16);
		Set_Stop(17);
		if (P0V28 == C_75) Set_State(15, 1);
		else Set_State(15, 3);
			break;
		case 1:    /*  P15S1() - СОСТОЯНИЕ: ЗапускИсправногоОборудования */

		if (P0V5 == C_0) Set_Start(16);
		else if (P0V5 == C_1) Set_Start(17);
		Set_State(15, 2);
			break;
		case 2:    /*  P15S2() - СОСТОЯНИЕ: ИсправностьРаботы */

		if (P0V28 != C_75) Set_State(15, 0);
			break;
		case 3:    /*  P15S3() - СОСТОЯНИЕ: ИмитацияНеисправностиОборудования */

		if (P0V28 == C_76)  Set_Start(17);
		else if (P0V28 == C_77) Set_Start(16);
		Set_State(15, 4);
			break;
		case 4:    /*  P15S4() - СОСТОЯНИЕ: Неисправность */

		if (P0V28 != C_76 
			&& P0V28 != C_77) Set_State(15, 0);
			break;
		default:
			break;
	}
}

void P16 (void) /* ПРОЦЕСС: ОТКРЫТИЕ_КЛАПАНА_АТМОСФЕРЫ */
{
	switch (Check_State(16)) {

		case 0:    /*  P16S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(16, C_11))  Set_State(16, 1);
			break;
		case 1:    /*  P16S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_61);
		Set_State(16, 2);
			break;
		case 2:    /*  P16S2() - СОСТОЯНИЕ: КлапанАтмосферыОткрыт */

		
			break;
		default:
			break;
	}
}

void P17 (void) /* ПРОЦЕСС: ЗАКРЫТИЕ_КЛАПАНА_АТМОСФЕРЫ */
{
	switch (Check_State(17)) {

		case 0:    /*  P17S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(17, C_11))  Set_State(17, 1);
			break;
		case 1:    /*  P17S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_62);
		Set_State(17, 2);
			break;
		case 2:    /*  P17S2() - СОСТОЯНИЕ: КлапанЗакрыт */
 
		
			break;
		default:
			break;
	}
}

void P18 (void) /* ПРОЦЕСС: КонтрольРазжатияЗажатияДиска */
{
	switch (Check_State(18)) {

		case 0:    /*  P18S0() - СОСТОЯНИЕ: Начало */

		if ((Check_State(20) == 2)
			&& (Check_State(16) == 2))
		{
			P0V8[1] = C_0;
			SendMsgGUICode(C_65);
			Set_State(18, 1);
		}
		else if ((Check_State(20) == 2) 
					&& (Check_State(17) == 2))
		{
			if (! ((Check_State(2) == 3))
					&& (Check_State(10) == 2))
					{
						P0V8[1] = C_1;
						SendMsgGUICode(C_66);
						Set_State(18, 3);
					}
			else if ((Check_State(2) == 3)
						|| (Check_State(11) == 2))
			{
				P0V8[1] = C_0;
				SendMsgGUICode(C_67);
				Set_State(18, 4);
			}			
		}
		else if ((Check_State(21) == 2) 
					&& (Check_State(16) == 2))
		{
			P0V8[1] = C_0;
			SendMsgGUICode(C_68);
			Set_State(18, 2);
		}
		else if ( (Check_State(17) == 2) 
					&& (Check_State(21) == 2))
		{
			if (! ((Check_State(2) == 3))
					&& (Check_State(10) == 2))
			{
						P0V8[1] = C_1;
						SendMsgGUICode(C_69);
						Set_State(18, 5);
			}
			else if ((Check_State(2) == 3)
						|| (Check_State(11) == 2))
			{
				P0V8[1] = C_0;
				SendMsgGUICode(C_70);
				Set_State(18, 6);
			}		
		}
			break;
		case 1:    /*  P18S1() - СОСТОЯНИЕ: ДискРазжатКлапанаОткрыты */

		if ( !( (Check_State(20) == 2))
		||	 !((Check_State(16) == 2)))
		Set_State(18, 0);
			break;
		case 2:    /*  P18S2() - СОСТОЯНИЕ: ДискРазжатАтмосфераОткрытВакуумЗакрыт */

		if ( !((Check_State(21) == 2))
		||	 !((Check_State(16) == 2)))
		Set_State(18, 0);
			break;
		case 3:    /*  P18S3() - СОСТОЯНИЕ: ДискЗажатВакуумОткрытАтмсфераЗакрыт */

		if ( !( (Check_State(20) == 2)) 
				|| ! ((Check_State(17) == 2))
				|| ((Check_State(2) == 3))
				|| (Check_State(10) == 2))
				Set_State(18, 0);
			break;
		case 4:    /*  P18S4() - СОСТОЯНИЕ: ДискРазажатВакуумОткрытАтмсфераЗакрыт */

		if ( !( (Check_State(20) == 2)) 
				|| ! ((Check_State(17) == 2))
				|| !((Check_State(2) == 3))
				|| !((Check_State(10) == 2)))
				Set_State(18, 0);
			break;
		case 5:    /*  P18S5() - СОСТОЯНИЕ: ДискЗажатВакуумЗакрытАтмсфераЗакрыт */

		if (!((Check_State(17) == 2)) 
				|| !( (Check_State(21) == 2))
				|| !((Check_State(10) == 2)))
				Set_State(18, 0);
			break;
		case 6:    /*  P18S6() - СОСТОЯНИЕ: ДискРазажатВакуумЗакрытАтмсфераЗакрыт */

			if (!((Check_State(17) == 2)) 
				|| !( (Check_State(21) == 2))
				|| ((Check_State(10) == 2)))
				Set_State(18, 0);
			break;
		default:
			break;
	}
}

void P19 (void) /* ПРОЦЕСС: КонтрольКлапанаВакуума */
{
	switch (Check_State(19)) {

		case 0:    /*  P19S0() - СОСТОЯНИЕ: Начало */

		Set_Stop(20);
		Set_Stop(21);
		if (P0V29 == C_75) Set_State(19, 1);
		else Set_State(19, 3);
			break;
		case 1:    /*  P19S1() - СОСТОЯНИЕ: ЗапускИсправногоОборудования */

		if (P0V5 == C_0) Set_Start(20);
		else if (P0V5 == C_1) Set_Start(21);
		Set_State(19, 2);
			break;
		case 2:    /*  P19S2() - СОСТОЯНИЕ: ИсправностьРаботы */

		if (P0V29 != C_75) Set_State(19, 0);
			break;
		case 3:    /*  P19S3() - СОСТОЯНИЕ: ИмитацияНеисправностиОборудования */

		if (P0V29 == C_76)  Set_Start(21);
		else if (P0V29 == C_77) Set_Start(20);
		Set_State(19, 4);
			break;
		case 4:    /*  P19S4() - СОСТОЯНИЕ: Неисправность */

		if (P0V29 != C_76 
			&& P0V29 != C_77) Set_State(19, 0);
			break;
		default:
			break;
	}
}

void P20 (void) /* ПРОЦЕСС: ОТКРЫТИЕ_КЛАПАНА_ВАКУУМА */
{
	switch (Check_State(20)) {

		case 0:    /*  P20S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(20, C_11))  Set_State(20, 1);
			break;
		case 1:    /*  P20S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_63);
		Set_State(20, 2);
			break;
		case 2:    /*  P20S2() - СОСТОЯНИЕ: КлапанВакуумаОткрыт */

		P0V8[1] = C_0;
		
			break;
		default:
			break;
	}
}

void P21 (void) /* ПРОЦЕСС: ЗАКРЫТИЕ_КЛАПАНА_ВАКУУМА */
{
	switch (Check_State(21)) {

		case 0:    /*  P21S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(21, C_11))  Set_State(21, 1);
			break;
		case 1:    /*  P21S1() - СОСТОЯНИЕ: ОтправкаСообщения */

		SendMsgGUICode(C_64);
		Set_State(21, 2);
			break;
		case 2:    /*  P21S2() - СОСТОЯНИЕ: КлапанЗакрыт */
 
		P0V8[1] = C_0;
		
			break;
		default:
			break;
	}
}
