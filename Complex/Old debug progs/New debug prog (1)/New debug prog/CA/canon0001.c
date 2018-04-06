/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "canonext.h" /* Common files for all generated c-files */
#include "canonxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */

	P0V25 = C_27;
	P0V26 = C_27;
 
	Set_Start(9);
	Set_Start(14);
	Set_Start(11);

	Set_Start(1);
	P0V17 = C_32;
    Set_State(0, 1);
			break;
		case 1:    /*  P0S1() - СОСТОЯНИЕ: КонтрольКонцаИнициализации */
 
	if (
		((Check_State(9) & MASK_OF_INACTIVITY)) &&
		((Check_State(11) & MASK_OF_INACTIVITY)) &&
		((Check_State(14) & MASK_OF_INACTIVITY)) &&
		((Check_State(20) & MASK_OF_INACTIVITY))) {
		if (
			((Check_State(9) == STATE_OF_STOP)) &&
			((Check_State(11) == STATE_OF_STOP)) &&
			((Check_State(14) == STATE_OF_STOP)) &&
			((Check_State(20) == STATE_OF_STOP))) {
				P0V17 = C_33;
				Set_Stop(1);

				Set_Start(3);
				Set_Start(23);
				Set_Start(21);
				Set_Start(25);
				Set_Start(26);
				Set_Start(27);
				Set_Start(28);
				Set_Start(5);
				Set_Start(6);
				Set_Start(7);
				Set_Start(8);
				Set_Stop(0);
	    } else {
			Set_Error(0);		
		}
	}
			break;
		default:
			break;
	}
}

void P1 (void) /* ПРОЦЕСС: Режим_ИНИЦИАЛИЗАЦИЯ */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - СОСТОЯНИЕ: Начало */

    P0V17 = C_32;
	Set_Start(2);
    Set_State(1, 1);
			break;
		case 1:    /*  P1S1() - СОСТОЯНИЕ: ЧтениеКольцевогоБуфера */

    if (GetNextMsgGUI()) {
		P0V18 = GetMsgGUICode(); 
		switch (P0V18) {
			case C_37:
				Set_Start(31);
				break;			
			case C_38:
				Set_Start(32);
				break;
			case C_41:
				P0V24 = C_20;
				Set_Start(29);
				break;
			case C_42:
				P0V24 = C_22;
				Set_Start(30);
				break;
			default:
				if ((P0V18 >= C_39) &&
					(P0V18 <= C_59)) {
						Set_State(1, 2);
					} else	Set_State(1, 3);		
 
			break;  
		  
		} 
	}
			break;
		case 2:    /*  P1S2() - СОСТОЯНИЕ: ЗапрещеннаяКоманда */

     if (SendMsgLongParamGUI(C_99, P0V18))
       Set_State(1, 0);
     if (Timeout(1, C_19))  Set_State(1, 4);
			break;
		case 3:    /*  P1S3() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_97, P0V18))
         Set_Stop(1);   
    if (Timeout(1, C_19))  Set_State(1, 4);
			break;
		case 4:    /*  P1S4() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(1, 1);
			break;
		default:
			break;
	}
}

void P2 (void) /* ПРОЦЕСС: КонтрольРежимов */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - СОСТОЯНИЕ: Начало */

		P2V1 = (!P0V17);
		Set_State(2, 1);
			break;
		case 1:    /*  P2S1() - СОСТОЯНИЕ: КонтрольИзменения */

		if (P2V1 != P0V17) {
			P2V1 = P0V17;
			switch (P2V1) {
				case C_32:
					P2V2 = C_83;
				break;	
				case C_33:
					P2V2 = C_84;
				break;	
				case C_34:
					P2V2 = C_85;
				break;	
				case C_35:
					P2V2 = C_86;
				break;	
				default: 
				break;	
			}
			Set_State(2, 2);
		}
			break;
		case 2:    /*  P2S2() - СОСТОЯНИЕ: СообщОбИзменении_Режима */

     if (SendMsgGUICode(P2V2)) Set_State(2, 1);
     if (Timeout(2, C_19))  Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(2, 0);
			break;
		default:
			break;
	}
}

void P3 (void) /* ПРОЦЕСС: Режим_РР */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - СОСТОЯНИЕ: Начало */

    P0V17 = C_33;
    Set_State(3, 1);
			break;
		case 1:    /*  P3S1() - СОСТОЯНИЕ: ЧтениеКольцевогоБуфера */

    if (GetNextMsgGUI()) {
		P0V18 = GetMsgGUICode(); 
		switch (P0V18) {
			case C_37:
				Set_Start(31);
				break;			
			case C_38:
				Set_Start(32);
				break;
			default:
				if ((P0V18 >= C_39) &&
					(P0V18 <= C_59)) {
						Set_Start(4);
						Set_State(3, 2);
				} else 		

				Set_State(3, 4);		
				break;  
		  
		} 
	}
			break;
		case 2:    /*  P3S2() - СОСТОЯНИЕ: КонтрольВыполненияКомандОтГИО */

    if(!((!(Check_State(4) & MASK_OF_INACTIVITY))))
    Set_State(3, 1);
			break;
		case 3:    /*  P3S3() - СОСТОЯНИЕ: ЗапрещеннаяКоманда */

     if (SendMsgLongParamGUI(C_98, P0V18))
       Set_State(3, 0);
     if (Timeout(3, C_19))  Set_State(3, 5);
			break;
		case 4:    /*  P3S4() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_97, P0V18))
        Set_State(3, 0);   
    if (Timeout(3, C_19))  Set_State(3, 5);
			break;
		case 5:    /*  P3S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(3, 1);
			break;
		default:
			break;
	}
}

void P4 (void) /* ПРОЦЕСС: ОбработкаКомандОтГИО */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - СОСТОЯНИЕ: Анализ */

    Set_State(4, 1); 
    switch (P0V18) {
       case C_39:
          Set_Start(12);
          break;
       case C_40:
          Set_Start(13);
          break;
       case C_51:
          Set_Start(18);
          break;		  
       case C_52:
          Set_Start(19);
          break;		  
		case C_41:
			P0V24 = C_20;
			Set_Start(29);
			break;
		case C_42:
			P0V24 = C_22;
			Set_Start(30);
			break;
       case C_43:
          Set_Start(36);
          break;		  
       case C_44:
          Set_Start(33);
          break;
       case C_45:
         Set_Start(34);  
          break;
       case C_46:
          Set_Start(35);  
          break;
       case C_47:
          Set_Start(37);
          break;
       case C_48:
          Set_Start(38);
          break;
       case C_49:
          Set_Start(39);
          break;
       case C_50:
          Set_Start(40);
          break;
       case C_53:
          P0V25 = C_20;
          break;
       case C_54:
          P0V25 = C_22;
          break;
       case C_55:
          P0V26 = C_20;
          break;
       case C_56:
          P0V26 = C_22;
          break;
       case C_57:
          P4V7 = GetFloatParamGUI();
          if ((P4V7 < C_28)
                  || (P4V7 > C_29)) {
               P4V8 = C_92;
               Set_State(4, 3);
          } else {
               P0V20 = P4V7;

			   Set_Stop(4);
           }
        break;
		  
       case C_58:
          P4V7 = GetFloatParamGUI();
          if ((P4V7 < C_30)
                  || (P4V7 > C_31)) {
               P4V8 = C_93;
               Set_State(4, 3);
          } else {
               P0V21 = P4V7;

			   Set_Stop(4);	
          }
        break;

       default:
          Set_State(4, 2); 
        break;
    }
			break;
		case 1:    /*  P4S1() - СОСТОЯНИЕ: ОстановПоЗапускуКоманды */

    Set_Stop(4);
			break;
		case 2:    /*  P4S2() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_97, P0V18))
         Set_Stop(4);
    if (Timeout(4, C_19))  Set_State(4, 5);
			break;
		case 3:    /*  P4S3() - СОСТОЯНИЕ: ЗД_ВнеДиапазона */

    if (SendMsgGUICode(P4V8)) Set_Stop(4);
     if (Timeout(4, C_19))  Set_State(4, 5);
			break;
		case 4:    /*  P4S4() - СОСТОЯНИЕ: ПодтверждениеИзмененияЗД */

 	 if (SendMsgLongParamGUI(P0V19, GetLongParamGUI())) Set_Stop(4);
    if (Timeout(4, C_19))  Set_State(4, 5);
			break;
		case 5:    /*  P4S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_Error(4);
			break;
		default:
			break;
	}
}

void P5 (void) /* ПРОЦЕСС: КонтрольИзмененияЗаданий_ЗД_R_КАРЕТКИ */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - СОСТОЯНИЕ: Начало */

    P5V1 = (!P0V20);
    Set_State(5, 1);
			break;
		case 1:    /*  P5S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P5V1 != P0V20) {
         P5V1 = P0V20;
         Set_State(5, 2);
    }
			break;
		case 2:    /*  P5S2() - СОСТОЯНИЕ: СообщОбИзменении_ГИО */

     if (SendMsgFloatParamGUI(C_66, P5V1)) Set_State(5, 1);
     if (Timeout(5, C_19))  Set_State(5, 3);
			break;
		case 3:    /*  P5S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(5, 1);
			break;
		default:
			break;
	}
}

void P6 (void) /* ПРОЦЕСС: КонтрольИзмененияЗаданий_ЗД_W_ПРЕДМЕТНОГО_СТОЛИКА */
{
	switch (Check_State(6)) {

		case 0:    /*  P6S0() - СОСТОЯНИЕ: Начало */

    P6V1 = (!P0V21);
    Set_State(6, 1);
			break;
		case 1:    /*  P6S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P6V1 != P0V21) {
         P6V1 = P0V21;
         Set_State(6, 2);
    }
			break;
		case 2:    /*  P6S2() - СОСТОЯНИЕ: СообщОбИзменении_ГИО */

     if (SendMsgFloatParamGUI(C_67, P6V1)) Set_State(6, 1);
     if (Timeout(6, C_19))  Set_State(6, 3);
			break;
		case 3:    /*  P6S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(6, 1);
			break;
		default:
			break;
	}
}

void P7 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_R_КАРЕТКИ */
{
	switch (Check_State(7)) {

		case 0:    /*  P7S0() - СОСТОЯНИЕ: Начало */

    P7V1 = (!P0V22);
    Set_State(7, 1);
			break;
		case 1:    /*  P7S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P7V1 != P0V22) {
         P7V1 = P0V22;
         Set_State(7, 2);
    }
			break;
		case 2:    /*  P7S2() - СОСТОЯНИЕ: СообщОбИзменении_ГИО */

     if (SendMsgFloatParamGUI(C_89, P7V1)) Set_State(7, 1);
     if (Timeout(7, C_19))  Set_State(7, 3);
			break;
		case 3:    /*  P7S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(7, 1);
			break;
		default:
			break;
	}
}

void P8 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_W_ПРЕДМЕТНОГО_СТОЛИКА */
{
	switch (Check_State(8)) {

		case 0:    /*  P8S0() - СОСТОЯНИЕ: Начало */

    P8V1 = (!P0V23);
    Set_State(8, 1);
			break;
		case 1:    /*  P8S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P8V1 != P0V23) {
         P8V1 = P0V23;
         Set_State(8, 2);
    }
			break;
		case 2:    /*  P8S2() - СОСТОЯНИЕ: СообщОбИзменении_ГИО */

     if (SendMsgFloatParamGUI(C_90, P8V1)) Set_State(8, 1);
     if (Timeout(8, C_19))  Set_State(8, 3);
			break;
		case 3:    /*  P8S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(8, 1);
			break;
		default:
			break;
	}
}

void P9 (void) /* ПРОЦЕСС: ВКЛ_ВОЗД_ПОДУШКУ */
{
	switch (Check_State(9)) {

		case 0:    /*  P9S0() - СОСТОЯНИЕ: Начало */

    	if (P0V7) Set_State(9, 3);
		else Set_State(9, 1);
			break;
		case 1:    /*  P9S1() - СОСТОЯНИЕ: СообщениеВключитьКомпрессор */

		if (SendMsgGUICode(C_94))	Set_State(9, 2);
		if (Timeout(9, C_19))  Set_State(9, 10);
			break;
		case 2:    /*  P9S2() - СОСТОЯНИЕ: ОжиданиеДавления */

		if (P0V7) Set_State(9, 3);	
		if (Timeout(9, C_9))  Set_State(9, 1);
			break;
		case 3:    /*  P9S3() - СОСТОЯНИЕ: ПодачаВоздухаНаОпоруСтола */

		P0V2[1] = C_20; Set_State(9, 4);
			break;
		case 4:    /*  P9S4() - СОСТОЯНИЕ: ПаузаДляОпорыСтола */

		if (Timeout(9, C_13))  Set_State(9, 5);
			break;
		case 5:    /*  P9S5() - СОСТОЯНИЕ: ПодачаВоздухаНаКаретку */

		P0V0[1] = C_20; Set_State(9, 6);
			break;
		case 6:    /*  P9S6() - СОСТОЯНИЕ: ПаузаДляКаретки */

		if (Timeout(9, C_13))  Set_State(9, 7);
			break;
		case 7:    /*  P9S7() - СОСТОЯНИЕ: ПодачаВоздухаНаШпиндель */

		P0V1[1] = C_20; Set_State(9, 8);
			break;
		case 8:    /*  P9S8() - СОСТОЯНИЕ: ПаузаДляШпинделя */

		if (Timeout(9, C_13))  {
			Set_Start(10);
			Set_State(9, 9);
		}
			break;
		case 9:    /*  P9S9() - СОСТОЯНИЕ: АнализРезультатовПроверки */

		if ((Check_State(10) == STATE_OF_STOP)) Set_Stop(9);
		if ((Check_State(10) == STATE_OF_ERROR)) Set_Error(9);
			break;
		case 10:    /*  P9S10() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_State(9, 0);
			break;
		default:
			break;
	}
}

void P10 (void) /* ПРОЦЕСС: ПроверкаИсправностиВоздушнойПодушки */
{
	switch (Check_State(10)) {

		case 0:    /*  P10S0() - СОСТОЯНИЕ: ОператоруПроконтролируйГотовностьВоздушныхПодушек */

		P0V24 = C_27;
		if (SendMsgGUICode(C_63)) 	
			Set_State(10, 1);
		if (Timeout(10, C_19))  Set_State(10, 2);
			break;
		case 1:    /*  P10S1() - СОСТОЯНИЕ: АнализГотовностьВоздПодушек */
	
		if (P0V24 == C_20) Set_Stop(10);
		if (P0V24 == C_22) Set_Error(10);
			break;
		case 2:    /*  P10S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(10);
			break;
		default:
			break;
	}
}

void P11 (void) /* ПРОЦЕСС: ВКЛ_НАСОС */
{
	switch (Check_State(11)) {

		case 0:    /*  P11S0() - СОСТОЯНИЕ: ЗакрываемОбаКлапана */

		P0V3[1] = C_22;	
		P0V5[1] = C_22;	
		Set_State(11, 1);
			break;
		case 1:    /*  P11S1() - СОСТОЯНИЕ: ПаузаДляЗакрываемОбоихКлапанов */

		if (Timeout(11, C_1))  Set_State(11, 2);
			break;
		case 2:    /*  P11S2() - СОСТОЯНИЕ: ВключениеНасоса */

		P0V4[1] = C_20; Set_State(11, 3);
			break;
		case 3:    /*  P11S3() - СОСТОЯНИЕ: ПаузаДляВключенияНасоса */

		if (Timeout(11, C_14))  Set_Stop(11);
			break;
		default:
			break;
	}
}

void P12 (void) /* ПРОЦЕСС: ЗАЖАТЬ_ДИСК */
{
	switch (Check_State(12)) {

		case 0:    /*  P12S0() - СОСТОЯНИЕ: Начало */

		if (P0V8 == C_22) Set_Start(23); 
	    if ((!(Check_State(13) & MASK_OF_INACTIVITY)))  Set_Error(13);
		P0V5[1] = C_22;	
		Set_State(12, 1);
			break;
		case 1:    /*  P12S1() - СОСТОЯНИЕ: ЖдемЗакрытияКлапанаАтмосферы */

		if (Timeout(12, C_0))  Set_State(12, 2);
			break;
		case 2:    /*  P12S2() - СОСТОЯНИЕ: ОткрКлапанНатеканияВакуума */

		P0V3[1] = C_20;	
		Set_State(12, 3);
			break;
		case 3:    /*  P12S3() - СОСТОЯНИЕ: ЕстьЛиНормальноеДавление */
	
		if (P0V8 == C_22){
			Set_Start(24);
			Set_Stop(12);  
		}
		if (Timeout(12, C_15))  Set_State(12, 4);
			break;
		case 4:    /*  P12S4() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_71))	Set_Error(12);
		if (Timeout(12, C_19))  Set_State(12, 5);
			break;
		case 5:    /*  P12S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(12);
			break;
		default:
			break;
	}
}

void P13 (void) /* ПРОЦЕСС: РАЗЖАТЬ_ДИСК */
{
	switch (Check_State(13)) {

		case 0:    /*  P13S0() - СОСТОЯНИЕ: Начало */

		if (P0V8 == C_20) Set_Start(23); 
		if ((!(Check_State(12) & MASK_OF_INACTIVITY)))  Set_Error(12);
		Set_Start(31);   
		Set_Stop(24);
		Set_State(13, 1);
			break;
		case 1:    /*  P13S1() - СОСТОЯНИЕ: КонтрольЗавершенияОтмены */

      if ((Check_State(31) & MASK_OF_INACTIVITY)) {
         if ((Check_State(31) == STATE_OF_ERROR)) Set_Error(13);
         else Set_State(13, 2);
      }
			break;
		case 2:    /*  P13S2() - СОСТОЯНИЕ: ЗакрываемНатекание */

		P0V3[1] = C_22;		
		Set_State(13, 3);
			break;
		case 3:    /*  P13S3() - СОСТОЯНИЕ: ЖдемЗакрытияКлапанаНатекания */

		if (Timeout(13, C_0))  Set_State(13, 4);
			break;
		case 4:    /*  P13S4() - СОСТОЯНИЕ: ОткрываемКлапанАтмосферы */

		P0V5[1] = C_20;	
		Set_State(13, 5);
			break;
		case 5:    /*  P13S5() - СОСТОЯНИЕ: НетЛиДавления */
	
		if (P0V8 == C_20) 	Set_Stop(13);  
		if (Timeout(13, C_16))  Set_State(13, 6);
			break;
		case 6:    /*  P13S6() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_72))	Set_Error(13);
		if (Timeout(13, C_19))  Set_State(13, 7);
			break;
		case 7:    /*  P13S7() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(13);
			break;
		default:
			break;
	}
}

void P14 (void) /* ПРОЦЕСС: ИНИЦИАЛИЗАЦИЯ_ЛАЗЕРА */
{
	switch (Check_State(14)) {

		case 0:    /*  P14S0() - СОСТОЯНИЕ: Начало */

		if (Timeout(14, C_6))  Set_State(14, 1);
			break;
		case 1:    /*  P14S1() - СОСТОЯНИЕ: ВключаемЛазер */

		P0V10[1] = C_20;	
		Set_Start(17);
		Set_Stop(14);
			break;
		default:
			break;
	}
}

void P15 (void) /* ПРОЦЕСС: ВКЛ_ЛАЗЕРА */
{
	switch (Check_State(15)) {

		case 0:    /*  P15S0() - СОСТОЯНИЕ: Начало */

		P0V11[1] = C_20;	
		P0V12[1] = C_20;
		Set_Stop(15);
			break;
		default:
			break;
	}
}

void P16 (void) /* ПРОЦЕСС: ВЫКЛ_ЛАЗЕРА */
{
	switch (Check_State(16)) {

		case 0:    /*  P16S0() - СОСТОЯНИЕ: Начало */

		P0V11[1] = C_22;	
		P0V12[1] = C_22;
		Set_Stop(16);
			break;
		default:
			break;
	}
}

void P17 (void) /* ПРОЦЕСС: КонтрольОсвещенияДиска */
{
	switch (Check_State(17)) {

		case 0:    /*  P17S0() - СОСТОЯНИЕ: Начало */

	Set_State(17, 1); 
	if (P0V13[1] == C_20)  Set_State(17, 3);
			break;
		case 1:    /*  P17S1() - СОСТОЯНИЕ: ОсвещениеВыключено */

    if (SendMsgGUICode(C_74)) 	Set_State(17, 2);
    else Set_State(17, 0);
			break;
		case 2:    /*  P17S2() - СОСТОЯНИЕ: ОжиданиеВключения */

	if (P0V13[1] == C_20) Set_State(17, 0);
			break;
		case 3:    /*  P17S3() - СОСТОЯНИЕ: ОсвещениеВключено */

    if (SendMsgGUICode(C_73)) 	Set_State(17, 4);
    else Set_State(17, 0);
			break;
		case 4:    /*  P17S4() - СОСТОЯНИЕ: ОжиданиеВыключения */

	if (P0V13[1] == C_22) Set_State(17, 0);
			break;
		default:
			break;
	}
}

void P18 (void) /* ПРОЦЕСС: ВКЛ_ПОДСВЕТКУ_ДИСКА */
{
	switch (Check_State(18)) {

		case 0:    /*  P18S0() - СОСТОЯНИЕ: Начало */

		if (P0V13[1] == C_20) Set_Start(17);	
		P0V13[1] = C_20;	
		P0V14[1] = C_22;
		Set_Stop(18);
			break;
		default:
			break;
	}
}

void P19 (void) /* ПРОЦЕСС: ВЫКЛ_ПОДСВЕТКУ_ДИСКА */
{
	switch (Check_State(19)) {

		case 0:    /*  P19S0() - СОСТОЯНИЕ: Начало */

		if (P0V13[1] == C_22) Set_Start(17);	
		P0V13[1] = C_22;	
		P0V14[1] = C_20;
		Set_Stop(19);
			break;
		default:
			break;
	}
}

void P20 (void) /* ПРОЦЕСС: ИНИЦИАЛИЗАЦИЯ_ПРИВОДОВ */
{
	switch (Check_State(20)) {

		case 0:    /*  P20S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(20);
			break;
		default:
			break;
	}
}

void P21 (void) /* ПРОЦЕСС: КонтрольДавления */
{
	switch (Check_State(21)) {

		case 0:    /*  P21S0() - СОСТОЯНИЕ: Начало */

	Set_State(21, 1); 
	if ((P0V6 == C_20) &&
				(P0V7 != C_20)) Set_State(21, 3);	
	if (P0V6 == C_22) Set_State(21, 5);
			break;
		case 1:    /*  P21S1() - СОСТОЯНИЕ: НормальноеДавление */

    if (SendMsgGUICode(C_60)) 	Set_State(21, 2);
    else Set_State(21, 0);
			break;
		case 2:    /*  P21S2() - СОСТОЯНИЕ: ОжиданиеНеНормальногоДавления */

	if ((P0V6 == C_22) ||
				(P0V7 != C_20)) Set_State(21, 0);
			break;
		case 3:    /*  P21S3() - СОСТОЯНИЕ: НизкоеДавление */

    if (SendMsgGUICode(C_61)) 	Set_State(21, 4);
    else Set_State(21, 0);
			break;
		case 4:    /*  P21S4() - СОСТОЯНИЕ: ОжиданиеНеНизкогоДавления */

	if ((P0V6 == C_22) ||
				(P0V7 == C_20)) Set_State(21, 0);	
	if (Timeout(21, C_7))  Set_State(21, 0);
			break;
		case 5:    /*  P21S5() - СОСТОЯНИЕ: Авария */

    if (SendMsgGUICode(C_64) &&
	       SendMsgGUICode(C_62)) {	
		Set_State(21, 6);
	} else Set_State(21, 0);
			break;
		case 6:    /*  P21S6() - СОСТОЯНИЕ: ОжиданиеНеАварии */

	if (P0V6 == C_20) {
		if ((Check_State(10) & MASK_OF_INACTIVITY)) 
			Set_Start(10);
		Set_State(21, 0);	
	}
			break;
		default:
			break;
	}
}

void P22 (void) /* ПРОЦЕСС: КонтрольАварииДавления */
{
	switch (Check_State(22)) {

		case 0:    /*  P22S0() - СОСТОЯНИЕ: Начало */

	Set_State(22, 1); 
	if ((P0V6 == C_20) &&
				(P0V7 != C_20)) Set_State(22, 2);	
	if (P0V6 == C_22) Set_State(22, 3);
			break;
		case 1:    /*  P22S1() - СОСТОЯНИЕ: ОжиданиеНеНормальногоДавления */

	if ((P0V6 == C_22) ||
				(P0V7 != C_20)) Set_State(22, 0);
			break;
		case 2:    /*  P22S2() - СОСТОЯНИЕ: ОжиданиеНеНизкогоДавления */

	if ((P0V6 == C_22) ||
				(P0V7 == C_20)) Set_State(22, 0);	
	if (Timeout(22, C_7))  Set_State(22, 0);
			break;
		case 3:    /*  P22S3() - СОСТОЯНИЕ: Авария */

	if ((Check_State(31) & MASK_OF_INACTIVITY)) Set_Start(31); 
    if (SendMsgGUICode(C_62)) {	
		Set_State(22, 4);
	} else Set_State(22, 0);
			break;
		case 4:    /*  P22S4() - СОСТОЯНИЕ: ОжиданиеНеАварии */

	if (P0V6 == C_20) Set_State(22, 0);
			break;
		default:
			break;
	}
}

void P23 (void) /* ПРОЦЕСС: КонтрольВакуума */
{
	switch (Check_State(23)) {

		case 0:    /*  P23S0() - СОСТОЯНИЕ: Начало */

      if (P0V8 == C_22) Set_State(23, 1);      
      else                Set_State(23, 2);
			break;
		case 1:    /*  P23S1() - СОСТОЯНИЕ: ВакуумНорма */

      if (SendMsgGUICode(C_68)) 	Set_State(23, 3);
      if (Timeout(23, C_19))  Set_State(23, 5);
			break;
		case 2:    /*  P23S2() - СОСТОЯНИЕ: НедостаточныйВакуум */

      if (SendMsgGUICode(C_69)) 	Set_State(23, 4);
      if (Timeout(23, C_19))  Set_State(23, 5);
			break;
		case 3:    /*  P23S3() - СОСТОЯНИЕ: ОжиданиеНедостаточногоВакуума */

      if (P0V8 == C_20) Set_State(23, 2);
			break;
		case 4:    /*  P23S4() - СОСТОЯНИЕ: ОжиданиеНормальногоВакуума */

      if (P0V8 == C_22) Set_State(23, 1);
			break;
		case 5:    /*  P23S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(23, 0);
			break;
		default:
			break;
	}
}

void P24 (void) /* ПРОЦЕСС: КонтрольАварииВакуума */
{
	switch (Check_State(24)) {

		case 0:    /*  P24S0() - СОСТОЯНИЕ: Начало */

      if (P0V8 == C_22) Set_State(24, 2);    
      else Set_State(24, 1);
			break;
		case 1:    /*  P24S1() - СОСТОЯНИЕ: АварияВакуума */

      if ((Check_State(31) & MASK_OF_INACTIVITY)) Set_Start(31); 
      if (SendMsgGUICode(C_70)) 	Set_Error(24);
      if (Timeout(24, C_19))  Set_Error(24);
			break;
		case 2:    /*  P24S2() - СОСТОЯНИЕ: КонтрольАварииВакуума */

      if (P0V8 == C_20) Set_State(24, 1);
			break;
		default:
			break;
	}
}

void P25 (void) /* ПРОЦЕСС: КонтрольСвязи_сМОХА1212 */
{
	switch (Check_State(25)) {

		case 0:    /*  P25S0() - СОСТОЯНИЕ: Начало */

		if (P0V25 == C_20) Set_State(25, 1);
		if (P0V25 == C_22) Set_State(25, 2);
			break;
		case 1:    /*  P25S1() - СОСТОЯНИЕ: ЕстьСвязьМоха1212 */

      if (SendMsgGUICode(C_75)) 	Set_State(25, 3);
      if (Timeout(25, C_19))  Set_State(25, 5);
			break;
		case 2:    /*  P25S2() - СОСТОЯНИЕ: НетСвязиМоха1212 */

	  if ((Check_State(31) & MASK_OF_INACTIVITY)) Set_Start(31);      	
      if (SendMsgGUICode(C_76)) 	Set_State(25, 4);
      if (Timeout(25, C_19))  Set_State(25, 5);
			break;
		case 3:    /*  P25S3() - СОСТОЯНИЕ: ОжиданиеРазрываСвязи */

      if (P0V25 == C_22) Set_State(25, 2);
			break;
		case 4:    /*  P25S4() - СОСТОЯНИЕ: ОжиданиеВосстановленияСвязи */

      if (P0V25 == C_20) Set_State(25, 1);
			break;
		case 5:    /*  P25S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(25, 0);
			break;
		default:
			break;
	}
}

void P26 (void) /* ПРОЦЕСС: КонтрольСвязи_сМОХА1214 */
{
	switch (Check_State(26)) {

		case 0:    /*  P26S0() - СОСТОЯНИЕ: Начало */

		if (P0V26 == C_20) Set_State(26, 1);
		if (P0V26 == C_22) Set_State(26, 2);
			break;
		case 1:    /*  P26S1() - СОСТОЯНИЕ: ЕстьСвязьМоха1214 */

      if (SendMsgGUICode(C_77)) 	Set_State(26, 3);
      if (Timeout(26, C_19))  Set_State(26, 5);
			break;
		case 2:    /*  P26S2() - СОСТОЯНИЕ: НетСвязиМоха1214 */

	  if ((Check_State(31) & MASK_OF_INACTIVITY)) Set_Start(31);      	
      if (SendMsgGUICode(C_78)) 	Set_State(26, 4);
      if (Timeout(26, C_19))  Set_State(26, 5);
			break;
		case 3:    /*  P26S3() - СОСТОЯНИЕ: ОжиданиеРазрываСвязи */

      if (P0V26 == C_22) Set_State(26, 2);
			break;
		case 4:    /*  P26S4() - СОСТОЯНИЕ: ОжиданиеВосстановленияСвязи */

      if (P0V26 == C_20) Set_State(26, 1);
			break;
		case 5:    /*  P26S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(26, 0);
			break;
		default:
			break;
	}
}

void P27 (void) /* ПРОЦЕСС: КонтрольДистанционного1212 */
{
	switch (Check_State(27)) {

		case 0:    /*  P27S0() - СОСТОЯНИЕ: Начало */

		if (P0V15) Set_State(27, 1);
		else Set_State(27, 2);
			break;
		case 1:    /*  P27S1() - СОСТОЯНИЕ: ЕстьДист1212 */

      if (SendMsgGUICode(C_79)) 	Set_State(27, 3);
      if (Timeout(27, C_19))  Set_State(27, 5);
			break;
		case 2:    /*  P27S2() - СОСТОЯНИЕ: НетДист1212 */

	  if ((Check_State(31) & MASK_OF_INACTIVITY)) Set_Start(31);      	
      if (SendMsgGUICode(C_80)) 	Set_State(27, 4);
      if (Timeout(27, C_19))  Set_State(27, 5);
			break;
		case 3:    /*  P27S3() - СОСТОЯНИЕ: ОжиданиеНедистанционного */

      if (P0V15 == C_22) Set_State(27, 2);
			break;
		case 4:    /*  P27S4() - СОСТОЯНИЕ: ОжиданиеДистанционного */

      if (P0V15 == C_20) Set_State(27, 1);
			break;
		case 5:    /*  P27S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(27, 0);
			break;
		default:
			break;
	}
}

void P28 (void) /* ПРОЦЕСС: КонтрольДистанционного1214 */
{
	switch (Check_State(28)) {

		case 0:    /*  P28S0() - СОСТОЯНИЕ: Начало */

		if (P0V9) Set_State(28, 1);
		else Set_State(28, 2);
			break;
		case 1:    /*  P28S1() - СОСТОЯНИЕ: ЕстьДист1214 */

      if (SendMsgGUICode(C_81)) 	Set_State(28, 3);
      if (Timeout(28, C_19))  Set_State(28, 5);
			break;
		case 2:    /*  P28S2() - СОСТОЯНИЕ: НетДист1214 */

	  if ((Check_State(31) & MASK_OF_INACTIVITY)) Set_Start(31);      	
      if (SendMsgGUICode(C_82)) 	Set_State(28, 4);
      if (Timeout(28, C_19))  Set_State(28, 5);
			break;
		case 3:    /*  P28S3() - СОСТОЯНИЕ: ОжиданиеНедистанционного */

      if (P0V9 == C_22) Set_State(28, 2);
			break;
		case 4:    /*  P28S4() - СОСТОЯНИЕ: ОжиданиеДистанционного */

      if (P0V9 == C_20) Set_State(28, 1);
			break;
		case 5:    /*  P28S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(28, 0);
			break;
		default:
			break;
	}
}

void P29 (void) /* ПРОЦЕСС: РАЗБЛОКИРОВКА_КОМАНД_ПЕРЕМЕЩЕНИЯ */
{
	switch (Check_State(29)) {

		case 0:    /*  P29S0() - СОСТОЯНИЕ: Начало */

		Set_Start(31);
		Set_State(29, 1);
			break;
		case 1:    /*  P29S1() - СОСТОЯНИЕ: СообщениеГИО */

    if (SendMsgGUICode(C_65)) Set_State(29, 2);
     if (Timeout(29, C_19))  Set_State(29, 2);
			break;
		case 2:    /*  P29S2() - СОСТОЯНИЕ: Конец */

    Set_Stop(29);
			break;
		default:
			break;
	}
}

void P30 (void) /* ПРОЦЕСС: БЛОКИРОВКА_КОМАНД_ПЕРЕМЕЩЕНИЯ */
{
	switch (Check_State(30)) {

		case 0:    /*  P30S0() - СОСТОЯНИЕ: Начало */

		Set_Start(31);
		Set_State(30, 1);
			break;
		case 1:    /*  P30S1() - СОСТОЯНИЕ: СообщениеГИО */

    if (SendMsgGUICode(C_64)) Set_State(30, 2);
     if (Timeout(30, C_19))  Set_State(30, 2);
			break;
		case 2:    /*  P30S2() - СОСТОЯНИЕ: Конец */

    Set_Stop(30);
			break;
		default:
			break;
	}
}

void P31 (void) /* ПРОЦЕСС: ОТМЕНА */
{
	switch (Check_State(31)) {

		case 0:    /*  P31S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(31);
			break;
		default:
			break;
	}
}

void P32 (void) /* ПРОЦЕСС: КОНЕЦ_РАБОТЫ */
{
	switch (Check_State(32)) {

		case 0:    /*  P32S0() - СОСТОЯНИЕ: Начало */

		P0V17 = C_35;
		Set_Stop(3);
			
		Set_Start(16);
		Set_Start(19);
		Set_Start(36);
		Set_Start(40);


		
			
		Set_Stop(25);
		Set_Stop(26);
		Set_Stop(27);
		Set_Stop(28);
		Set_Stop(5);
		Set_Stop(6);
		Set_Stop(7);
		Set_Stop(8);
		
		Set_State(32, 1);
			break;
		case 1:    /*  P32S1() - СОСТОЯНИЕ: ПроверкаПриходаВИсходное */

    if (
	
        !( (!(Check_State(16) & MASK_OF_INACTIVITY))) &&
		!( (!(Check_State(19) & MASK_OF_INACTIVITY)))  &&
		!( (!(Check_State(36) & MASK_OF_INACTIVITY))) &&
		!( (!(Check_State(40) & MASK_OF_INACTIVITY)))  
          ) Set_State(32, 2);
			break;
		case 2:    /*  P32S2() - СОСТОЯНИЕ: СообщениеГИО */

    if (SendMsgGUICode(C_87)) Set_State(32, 3);
     if (Timeout(32, C_19))  Set_State(32, 3);
			break;
		case 3:    /*  P32S3() - СОСТОЯНИЕ: Конец */

    Set_Stop(32);
			break;
		default:
			break;
	}
}

void P33 (void) /* ПРОЦЕСС: КАРЕТКУ_В_ЦЕНТР_ВРАЩЕНИЯ */
{
	switch (Check_State(33)) {

		case 0:    /*  P33S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(33);
			break;
		default:
			break;
	}
}

void P34 (void) /* ПРОЦЕСС: КАРЕТКУ_В_ЗАДАННЫЙ_РАДИУС */
{
	switch (Check_State(34)) {

		case 0:    /*  P34S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(34);
			break;
		default:
			break;
	}
}

void P35 (void) /* ПРОЦЕСС: СТОП_КАРЕТКИ */
{
	switch (Check_State(35)) {

		case 0:    /*  P35S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(35);
			break;
		default:
			break;
	}
}

void P36 (void) /* ПРОЦЕСС: КАРЕТКУ_В_ПОЛОЖЕНИЕ_УСТАНОВКИ_ДИСКА */
{
	switch (Check_State(36)) {

		case 0:    /*  P36S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(36);
			break;
		default:
			break;
	}
}

void P37 (void) /* ПРОЦЕСС: ВКЛ_АКТИВНОЕ_ПОЗИЦИОНИРОВАНИЕ_ПО_ВРАЩЕНИЮ */
{
	switch (Check_State(37)) {

		case 0:    /*  P37S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(37);
			break;
		default:
			break;
	}
}

void P38 (void) /* ПРОЦЕСС: ВЫКЛ_АКТИВНОЕ_ПОЗИЦИОНИРОВАНИЕ_ПО_ВРАЩЕНИЮ */
{
	switch (Check_State(38)) {

		case 0:    /*  P38S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(38);
			break;
		default:
			break;
	}
}

void P39 (void) /* ПРОЦЕСС: ВКЛ_ВРАЩЕНИЕ_ПРЕД_СТОЛИКА_В_ЗД_W */
{
	switch (Check_State(39)) {

		case 0:    /*  P39S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(39);
			break;
		default:
			break;
	}
}

void P40 (void) /* ПРОЦЕСС: СТОП_ВРАЩЕНИЯ_ПРЕДМЕТНОГО_СТОЛИКА */
{
	switch (Check_State(40)) {

		case 0:    /*  P40S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(40);
			break;
		default:
			break;
	}
}
