/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "bsvtext.inc" /* Common files for all generated c-files */
#include "bsvtxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
  
	if (P0V1)  Set_State(0, 1);
			break;
		case 1:    /*  P0S1() - СОСТОЯНИЕ: НачалоРаботы */
	

    P0V38 = 1; 
	                                   


	P0V44 = 8; 
	P0V45              = 760.00;
	P0V46 =  0.02; 




    Set_Start(9);
	Set_Start(8);
	Set_Start(10);
	Set_Start(13);
	Set_Start(14);
	Set_Start(15);
	Set_Start(16);
	Set_Start(17);

	if (!P0V12) Set_Start(40);   
	
	Set_Start(44);

	
	Set_Start(20);
	Set_Start(22);
	Set_Start(23);
	Set_Start(19);	
	Set_Start(21);	

	Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* ПРОЦЕСС: КонтрольДостоверностиОткрытияЗатвораВакуумного */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - СОСТОЯНИЕ: Начало */

    if (P0V1) {
         if (SendMsgGUICode(C_135))  Set_State(1, 1);
    } else {
         if (SendMsgGUICode(C_136))  Set_State(1, 2);
    }
    if (Timeout(1, C_15))  Set_State(1, 4);
			break;
		case 1:    /*  P1S1() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

    if (!P0V1)  Set_State(1, 3);
			break;
		case 2:    /*  P1S2() - СОСТОЯНИЕ: СменаСостоянияВЫКЛ */

    if (P0V1)  Set_State(1, 3);
			break;
		case 3:    /*  P1S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(1, P0V38))  Set_State(1, 0);
			break;
		case 4:    /*  P1S4() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(1, 0);
			break;
		default:
			break;
	}
}

void P2 (void) /* ПРОЦЕСС: КонтрольДостоверностиОткрЗатВакуумного */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - СОСТОЯНИЕ: Начало */

      if (P0V1 == C_29) Set_State(2, 1);
      else Set_State(2, 3);
			break;
		case 1:    /*  P2S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_135)) Set_State(2, 2);
     if (Timeout(2, C_15))  Set_State(2, 5);
			break;
		case 2:    /*  P2S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V1 == C_30) Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_136)) Set_State(2, 4);
     if (Timeout(2, C_15))  Set_State(2, 5);
			break;
		case 4:    /*  P2S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V1 == C_29) Set_State(2, 1);
			break;
		case 5:    /*  P2S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(2, 0);
			break;
		default:
			break;
	}
}

void P3 (void) /* ПРОЦЕСС: КонтрольДостоверностиЗакрЗатВакуумного */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - СОСТОЯНИЕ: Начало */

      if (P0V3 == C_29) Set_State(3, 1);
      else Set_State(3, 3);
			break;
		case 1:    /*  P3S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_137)) Set_State(3, 2);
     if (Timeout(3, C_15))  Set_State(3, 5);
			break;
		case 2:    /*  P3S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V3 == C_30) Set_State(3, 3);
			break;
		case 3:    /*  P3S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_138)) Set_State(3, 4);
     if (Timeout(3, C_15))  Set_State(3, 5);
			break;
		case 4:    /*  P3S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V3 == C_29) Set_State(3, 1);
			break;
		case 5:    /*  P3S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(3, 0);
			break;
		default:
			break;
	}
}

void P4 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияСапуна */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - СОСТОЯНИЕ: Начало */

      if (P0V5 == C_29) Set_State(4, 1);
      else Set_State(4, 3);
			break;
		case 1:    /*  P4S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_139)) Set_State(4, 2);
     if (Timeout(4, C_15))  Set_State(4, 5);
			break;
		case 2:    /*  P4S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V5 == C_30) Set_State(4, 3);
			break;
		case 3:    /*  P4S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_140)) Set_State(4, 4);
     if (Timeout(4, C_15))  Set_State(4, 5);
			break;
		case 4:    /*  P4S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V5 == C_29) Set_State(4, 1);
			break;
		case 5:    /*  P4S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(4, 0);
			break;
		default:
			break;
	}
}

void P5 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияУстройстваПлавПуска */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - СОСТОЯНИЕ: Начало */

      if (P0V7 == C_29) Set_State(5, 1);
      else Set_State(5, 3);
			break;
		case 1:    /*  P5S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_141)) Set_State(5, 2);
     if (Timeout(5, C_15))  Set_State(5, 5);
			break;
		case 2:    /*  P5S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V7 == C_30) Set_State(5, 3);
			break;
		case 3:    /*  P5S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_142)) Set_State(5, 4);
     if (Timeout(5, C_15))  Set_State(5, 5);
			break;
		case 4:    /*  P5S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V7 == C_29) Set_State(5, 1);
			break;
		case 5:    /*  P5S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(5, 0);
			break;
		default:
			break;
	}
}

void P6 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияВакуумногоНасоса */
{
	switch (Check_State(6)) {

		case 0:    /*  P6S0() - СОСТОЯНИЕ: Начало */

      if (P0V9 == C_29) Set_State(6, 1);
      else Set_State(6, 3);
			break;
		case 1:    /*  P6S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_143)) Set_State(6, 2);
     if (Timeout(6, C_15))  Set_State(6, 5);
			break;
		case 2:    /*  P6S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V9 == C_30) Set_State(6, 3);
			break;
		case 3:    /*  P6S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_144)) Set_State(6, 4);
     if (Timeout(6, C_15))  Set_State(6, 5);
			break;
		case 4:    /*  P6S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V9 == C_29) Set_State(6, 1);
			break;
		case 5:    /*  P6S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(6, 0);
			break;
		default:
			break;
	}
}

void P7 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияВентилятора */
{
	switch (Check_State(7)) {

		case 0:    /*  P7S0() - СОСТОЯНИЕ: Начало */

      if (P0V11 == C_29) Set_State(7, 1);
      else Set_State(7, 3);
			break;
		case 1:    /*  P7S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_145)) Set_State(7, 2);
     if (Timeout(7, C_15))  Set_State(7, 5);
			break;
		case 2:    /*  P7S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V11 == C_30) Set_State(7, 3);
			break;
		case 3:    /*  P7S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_146)) Set_State(7, 4);
     if (Timeout(7, C_15))  Set_State(7, 5);
			break;
		case 4:    /*  P7S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V11 == C_29) Set_State(7, 1);
			break;
		case 5:    /*  P7S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(7, 0);
			break;
		default:
			break;
	}
}

void P8 (void) /* ПРОЦЕСС: ЧтениеФактПараметров_с_Датчиков */
{
	switch (Check_State(8)) {

		case 0:    /*  P8S0() - СОСТОЯНИЕ: Начало */

	P0V39 	= GetFP_P_BAK_COMPRESSOR();     
	P0V40 		= GetFP_P_PATRUBKA();     			
	P0V41 		= GetFP_T_RUBACHKA();     			   
	P0V42 			= GetFP_T_BAK();     				 
	P0V43 	= GetFP_P_TRUBA();     				 
   Set_State(8, 0);
			break;
		default:
			break;
	}
}

void P9 (void) /* ПРОЦЕСС: РЕГУЛЯТОР_ТРАФИКА */
{
	switch (Check_State(9)) {

		case 0:    /*  P9S0() - СОСТОЯНИЕ: Начало */

    P0V38 = GetOutMsgNumber_GUI()/5 + 1;  
    
			break;
		default:
			break;
	}
}

void P10 (void) /* ПРОЦЕСС: ЧтениеКольцевогоБуфера */
{
	switch (Check_State(10)) {

		case 0:    /*  P10S0() - СОСТОЯНИЕ: Начало */

    
    if (GetNextMsgGUI()) {
      P0V30 = GetMsgGUICode();
            if ((P0V30 >= C_50) &&
                  (P0V30 <= C_70)) {
				Set_Start(12);
				Set_State(10, 1);
            } 
			else if ((P0V30 >= C_152) &&
                         (P0V30 <= C_156)) {
                     Set_Start(11);
                     Set_State(10, 2);
			}
			else Set_State(10, 3);
    }
			break;
		case 1:    /*  P10S1() - СОСТОЯНИЕ: КонтрольВыполненияК */

    if((Check_State(12) & MASK_OF_INACTIVITY))
    Set_State(10, 0);
			break;
		case 2:    /*  P10S2() - СОСТОЯНИЕ: КонтрольИзмененияНП */

    if((Check_State(11) & MASK_OF_INACTIVITY))
    Set_State(10, 0);
			break;
		case 3:    /*  P10S3() - СОСТОЯНИЕ: НекорректноеСобытие */

     if (SendMsgLongParamGUI(C_157, P0V30))
       Set_State(10, 0);
     if (Timeout(10, C_15))  Set_State(10, 4);
			break;
		case 4:    /*  P10S4() - СОСТОЯНИЕ: НарушениеСвязи */

	Set_State(10, 0);
     Set_Stop(10);
			break;
		default:
			break;
	}
}

void P11 (void) /* ПРОЦЕСС: ОбработкаКомандИзмененияНП_от_ГУИ */
{
	switch (Check_State(11)) {

		case 0:    /*  P11S0() - СОСТОЯНИЕ: Анализ */

    switch (P0V30) {
	    case C_154:
          P0V45  = GetFloatParamGUI();
          P0V31 = C_154;
          Set_State(11, 1);
			break;
	    case C_153:
		   P0V44  = GetFloatParamGUI();
          P0V31 = P0V44;
          Set_State(11, 1);		   
			break;
	    case C_155:
		   P0V46  = GetFloatParamGUI();
          P0V31 = P0V46;
          Set_State(11, 1);		   
			break;
		default:
          Set_State(11, 2);
          break;
    } 
	Set_Stop(11);
			break;
		case 1:    /*  P11S1() - СОСТОЯНИЕ: ПодтверждениеИзмененияНП */

    if (SendMsgLongParamGUI(P0V31, GetLongParamGUI())) Set_Stop(11);
    if (Timeout(11, C_15))  Set_State(11, 3);
			break;
		case 2:    /*  P11S2() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_157, P0V30))
         Set_Stop(11);
    if (Timeout(11, C_15))  Set_State(11, 3);
			break;
		case 3:    /*  P11S3() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_Error(11);
			break;
		default:
			break;
	}
}

void P12 (void) /* ПРОЦЕСС: ОбработкаКомандУправления_от_ГУИ */
{
	switch (Check_State(12)) {

		case 0:    /*  P12S0() - СОСТОЯНИЕ: Анализ */

    switch (P0V30) {
	
	    case C_50:
		  if (P0V6 == C_22) { 
				if ((P0V43 >= P0V40)
					|| (P0V43 >= P0V45))   
					Set_Start(28); 
				else {
					P12V13 = C_92;
					Set_State(12, 2);
				}			
		  } else {
		    P12V13 = C_91;
			Set_State(12, 2);
		  }		
		break;

	    case C_51:
		  if (P0V6 == C_22) { 
			Set_Start(29); 
		  } else {
		    P12V13 = C_91;
			Set_State(12, 2);
		  }		
			break;		  
	    case C_52:
		  if (P0V6 == C_22) { 
			Set_Start(32); 
		  } else {
		    P12V13 = C_91;
			Set_State(12, 2);
		  }
		  break;
	    case C_53:
		  if (P0V6 == C_22) { 
			Set_Start(33); 
		  } else {
		    P12V13 = C_91;
			Set_State(12, 2);
		  }
		  break;

		case C_54:
			if (P0V6 == C_22) { 
				if ((P0V32 == C_27) && (P0V10)
						&& (P0V20)&& (P0V2) && (P0V4)
						&& (P0V34 == C_27)) {   
						Set_Start(52);
				} else {
					P12V13 = C_92;
					Set_State(12, 2);
				}
			} else {
				P12V13 = C_91;
				Set_State(12, 2);
			}			
			break;
	
			
	    case C_55:   
			Set_Start(53);
			break;	
		case C_56:			
          Set_Start(36);
          break;
	    case C_57:
          Set_Start(37);
          break;


	    case C_58:
			Set_Start(24);
          break;
	    case C_59:
			Set_Start(25);	
          break;			
 
		  
	    case C_60:
		  if(P0V6 == C_22) {   
		  


				if (P0V32 == C_27) {
					if (P0V42 > 0.0) {
						Set_Start(40);
					} else {
					 P12V13 = C_94;
					 Set_State(12, 2);
					}
				P12V13 = C_93;
				Set_State(12, 2);				
				}
				
		  } else {   
		    P12V13 = C_91;
			Set_State(12, 2);
		  }
		  break;
	    case C_61:
		  if(P0V6 == C_22) {   
			Set_Start(41);
		  } else {   
		    P12V13 = C_91;
			Set_State(12, 2);
		  }
          break;
	    case C_62:
		  if(P0V6 == C_22) {   
		  	Set_Start(44);
		  } else {   
		    P12V13 = C_91;
			Set_State(12, 2);
		  } 
          break;
	    case C_63:
		  if(P0V6 == C_22) {   
		  	Set_Start(45);
		  } else {   
		    P12V13 = C_91;
			Set_State(12, 2);
		  } 
		  break;
	    case C_64:
		  if(P0V6 == C_22) {   
				if ((P0V32 = C_27) && (P0V42 > 0.0)) Set_Start(48);
		  } else {   
		    P12V13 = C_91;
			Set_State(12, 2);
		  }
		  break;
	    case C_65:
		  if(P0V6 == C_22) {   
		  	Set_Start(49);
		  } else {   
		    P12V13 = C_91;
			Set_State(12, 2);
		  } 		
		  break;
		  
	    case C_68:   
          Set_Start(56); 
          break;  
	    case C_69:  
          Set_Start(57); 
          break;  

		  case C_66:   
          Set_Start(58);
          break;
		  
		  case C_67:   
		  Set_Start(58);
          break;
		default:
          Set_State(12, 1);
          break;
    } 
	Set_Stop(12);
			break;
		case 1:    /*  P12S1() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_157, P0V30))
         Set_Stop(12);   
    if (Timeout(12, C_15))  Set_State(12, 3);
			break;
		case 2:    /*  P12S2() - СОСТОЯНИЕ: ПередачаСообщенияСПараметромГУИ */

    if (SendMsgLongParamGUI(P12V13, P0V30))
        Set_Stop(12);
    if (Timeout(12, C_15))  Set_State(12, 3);
			break;
		case 3:    /*  P12S3() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_Error(12);
			break;
		default:
			break;
	}
}

void P13 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_ВбакеКомпрессора */
{
	switch (Check_State(13)) {

		case 0:    /*  P13S0() - СОСТОЯНИЕ: Начало */

    P13V2 = (!P0V39);
    Set_State(13, 1);
			break;
		case 1:    /*  P13S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P13V2 != P0V39) {
         P13V2 = P0V39;
         Set_State(13, 2);
    }
			break;
		case 2:    /*  P13S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_147, P13V2))
         Set_State(13, 3);
     if (Timeout(13, C_15))  Set_State(13, 4);
			break;
		case 3:    /*  P13S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(13, P0V38))  Set_State(13, 1);
			break;
		case 4:    /*  P13S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(13, 1);
			break;
		default:
			break;
	}
}

void P14 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_Впатрубке */
{
	switch (Check_State(14)) {

		case 0:    /*  P14S0() - СОСТОЯНИЕ: Начало */

    P14V2 = (!P0V40);
    Set_State(14, 1);
			break;
		case 1:    /*  P14S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P14V2 != P0V40) {
         P14V2 = P0V40;
         Set_State(14, 2);
    }
			break;
		case 2:    /*  P14S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_148, P14V2))
         Set_State(14, 3);
     if (Timeout(14, C_15))  Set_State(14, 4);
			break;
		case 3:    /*  P14S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(14, P0V38))  Set_State(14, 1);
			break;
		case 4:    /*  P14S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(14, 1);
			break;
		default:
			break;
	}
}

void P15 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_T_Врубашке */
{
	switch (Check_State(15)) {

		case 0:    /*  P15S0() - СОСТОЯНИЕ: Начало */

    P15V2 = (!P0V41);
    Set_State(15, 1);
			break;
		case 1:    /*  P15S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P15V2 != P0V41) {
         P15V2 = P0V41;
         Set_State(15, 2);
    }
			break;
		case 2:    /*  P15S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_149, P15V2))
         Set_State(15, 3);
     if (Timeout(15, C_15))  Set_State(15, 4);
			break;
		case 3:    /*  P15S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(15, P0V38))  Set_State(15, 1);
			break;
		case 4:    /*  P15S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(15, 1);
			break;
		default:
			break;
	}
}

void P16 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_T_Вбаке */
{
	switch (Check_State(16)) {

		case 0:    /*  P16S0() - СОСТОЯНИЕ: Начало */

    P16V2 = (!P0V42);
    Set_State(16, 1);
			break;
		case 1:    /*  P16S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P16V2 != P0V42) {
         P16V2 = P0V42;
         Set_State(16, 2);
    }
			break;
		case 2:    /*  P16S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_150, P16V2))
         Set_State(16, 3);
     if (Timeout(16, C_15))  Set_State(16, 4);
			break;
		case 3:    /*  P16S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(16, P0V38))  Set_State(16, 1);
			break;
		case 4:    /*  P16S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(16, 1);
			break;
		default:
			break;
	}
}

void P17 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_ВтрубеСидер */
{
	switch (Check_State(17)) {

		case 0:    /*  P17S0() - СОСТОЯНИЕ: Начало */

    P17V2 = (!P0V43);
    Set_State(17, 1);
			break;
		case 1:    /*  P17S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P17V2 != P0V43) {
         P17V2 = P0V43;
         Set_State(17, 2);
    }
			break;
		case 2:    /*  P17S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_151, P17V2))
         Set_State(17, 3);
     if (Timeout(17, C_15))  Set_State(17, 4);
			break;
		case 3:    /*  P17S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(17, P0V38))  Set_State(17, 1);
			break;
		case 4:    /*  P17S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(17, 1);
			break;
		default:
			break;
	}
}

void P18 (void) /* ПРОЦЕСС: КонтрольОткачкиВауумнойТрубыСидеростата */
{
	switch (Check_State(18)) {

		case 0:    /*  P18S0() - СОСТОЯНИЕ: Начало */

	P18V2 = P0V43;
	if (Timeout(18, C_20))  Set_State(18, 1);
			break;
		case 1:    /*  P18S1() - СОСТОЯНИЕ: АнализОткачки */

	if ((P0V43 - P18V2) < -0.01) {    
        if (SendMsgGUICode(C_46)) {
					P0V36 = C_27;
					Set_State(18, 0);
		} 
    } else{
	if (SendMsgGUICode(C_47)) {
					P0V36 = C_28;
					Set_State(18, 0);
		} 
	}
			break;
		default:
			break;
	}
}

void P19 (void) /* ПРОЦЕСС: КонтрольГотовностиВакуума_в_Вакуумной_Трубе */
{
	switch (Check_State(19)) {

		case 0:    /*  P19S0() - СОСТОЯНИЕ: Начало */

   if (P0V43 <= P0V46) {
         if (SendMsgGUICode(C_44)) {
					P0V35 = C_27;
					Set_State(19, 1);
					}
    
    } else {
                if (SendMsgGUICode(C_45)) {
					P0V35 = C_28;
				   Set_State(19, 2);
				}
    }
    if (Timeout(19, C_15))  Set_State(19, 4);
			break;
		case 1:    /*  P19S1() - СОСТОЯНИЕ: ДавлениеНормальное */

       if (P0V43 > 0.025)  Set_State(19, 0);
			break;
		case 2:    /*  P19S2() - СОСТОЯНИЕ: ДавлениеВысокое */

       if (P0V43 < 0.01)  Set_State(19, 0);
			break;
		case 3:    /*  P19S3() - СОСТОЯНИЕ: Задержка */

      if (Timeout(19, C_16))  Set_State(19, 0);
			break;
		case 4:    /*  P19S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(19, 0);
			break;
		default:
			break;
	}
}

void P20 (void) /* ПРОЦЕСС: КонтрольУровняВодыБакаОхлаждения */
{
	switch (Check_State(20)) {

		case 0:    /*  P20S0() - СОСТОЯНИЕ: Начало */

     if (P0V16) {
         if (SendMsgGUICode(C_35)) {
					P0V32 = C_28;
					Set_State(20, 1);
					}
    } else if (P0V18) {
              if (SendMsgGUICode(C_36)) {
			   P0V32 = C_28;
			   Set_State(20, 2);
			   }
    } else {
                if (SendMsgGUICode(C_37)) {
					P0V32 = C_27;
				   Set_State(20, 3);
				}
         }
    if (Timeout(20, C_15))  Set_State(20, 5);
			break;
		case 1:    /*  P20S1() - СОСТОЯНИЕ: НизкийУровеньВоды */

        if (!P0V16)  Set_State(20, 4);
			break;
		case 2:    /*  P20S2() - СОСТОЯНИЕ: ВысокийУровеньВоды */

       if (!P0V18)  Set_State(20, 4);
			break;
		case 3:    /*  P20S3() - СОСТОЯНИЕ: УровеньВодыВнорме */

	   if (P0V16 && P0V18)  Set_State(20, 4);
			break;
		case 4:    /*  P20S4() - СОСТОЯНИЕ: Задержка */

      if (Timeout(20, C_16))  Set_State(20, 0);
			break;
		case 5:    /*  P20S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(20, 0);
			break;
		default:
			break;
	}
}

void P21 (void) /* ПРОЦЕСС: КонтрольТемпературыВодыБакаОхлаждения */
{
	switch (Check_State(21)) {

		case 0:    /*  P21S0() - СОСТОЯНИЕ: Начало */

    if (P0V42 < 50) {
         if (SendMsgGUICode(C_38)) {
					P0V33 = C_28;
					Set_State(21, 1);
					}
    } else if (P0V42 > 60) {
              if (SendMsgGUICode(C_39)) {
			   P0V33 = C_28;
			   Set_State(21, 2);
			   }
    } else {
                if (SendMsgGUICode(C_40)) {
					P0V33 = C_27;
				   Set_State(21, 3);
				}
         }
		 
    if (Timeout(21, C_15))  Set_State(21, 5);
			break;
		case 1:    /*  P21S1() - СОСТОЯНИЕ: НизкаяТемператураВоды */

        if (P0V42 > (50.0 + C_33))  Set_State(21, 0);
			break;
		case 2:    /*  P21S2() - СОСТОЯНИЕ: ВысокаяТемператураВоды */

       if (P0V42 < (60.0 - C_33))  Set_State(21, 0);
			break;
		case 3:    /*  P21S3() - СОСТОЯНИЕ: ТемператураВнорме */

       if ((P0V42 < (50.0 - C_33)) && 
	         (P0V42 > (60.0 + C_33)))  Set_State(21, 0);
			break;
		case 4:    /*  P21S4() - СОСТОЯНИЕ: Задержка */


      if (Timeout(21, C_16))  Set_State(21, 0);
			break;
		case 5:    /*  P21S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(21, 0);
			break;
		default:
			break;
	}
}

void P22 (void) /* ПРОЦЕСС: КонтрольТемпературыРубашкиОхлаждения */
{
	switch (Check_State(22)) {

		case 0:    /*  P22S0() - СОСТОЯНИЕ: Начало */

    if (P0V41 < 40) {
         if (SendMsgGUICode(C_41)) {
					P0V34 = C_28;
					Set_State(22, 1);
					}
    } else if (P0V41 > 85) {
              if (SendMsgGUICode(C_42)) {
			   P0V34 = C_28;
			   Set_State(22, 2);
			   }
    } else {
                if (SendMsgGUICode(C_43)) {
					P0V34 = C_27;
				   Set_State(22, 3);
				}
         }
    if (Timeout(22, C_15))  Set_State(22, 5);
			break;
		case 1:    /*  P22S1() - СОСТОЯНИЕ: НизкаяТемператураВоды */

       
		if (P0V41 > (40.0 + C_34))  Set_State(22, 0);
			break;
		case 2:    /*  P22S2() - СОСТОЯНИЕ: ВысокаяТемператураВоды */

        if (P0V41 < (85.0 - C_34))  Set_State(22, 0);
			break;
		case 3:    /*  P22S3() - СОСТОЯНИЕ: ТемператураВнорме */

        if ((P0V41 < (40.0 - C_34)) && 
	         (P0V41 > (85.0 + C_34)))  Set_State(22, 0);
			break;
		case 4:    /*  P22S4() - СОСТОЯНИЕ: Задержка */

      if (Timeout(22, C_16))  Set_State(22, 0);
			break;
		case 5:    /*  P22S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(22, 0);
			break;
		default:
			break;
	}
}

void P23 (void) /* ПРОЦЕСС: КонтрольДавленияВбакеКомпрессора */
{
	switch (Check_State(23)) {

		case 0:    /*  P23S0() - СОСТОЯНИЕ: Начало */

   if (P0V39 > P0V44) {
         if (SendMsgGUICode(C_48)) {
					P0V37 = C_27;
					Set_State(23, 1);
					}
    
    } else {
                if (SendMsgGUICode(C_49)) {
					P0V37 = C_28;
				   Set_State(23, 2);
				}
    }
    if (Timeout(23, C_15))  Set_State(23, 4);
			break;
		case 1:    /*  P23S1() - СОСТОЯНИЕ: ДавлениеНормальное */

       if (P0V39 < 9.5)  Set_State(23, 0);
			break;
		case 2:    /*  P23S2() - СОСТОЯНИЕ: ДавлениеНизкое */

       if (P0V39 < 10.5)  Set_State(23, 0);
			break;
		case 3:    /*  P23S3() - СОСТОЯНИЕ: Задержка */

      if (Timeout(23, C_16))  Set_State(23, 0);
			break;
		case 4:    /*  P23S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(23, 0);
			break;
		default:
			break;
	}
}

void P24 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_ВЕНТИЛЯТОР */
{
	switch (Check_State(24)) {

		case 0:    /*  P24S0() - СОСТОЯНИЕ: Начало */

   if ((!(Check_State(25) & MASK_OF_INACTIVITY))) Set_Error(25);
   Set_Stop(27);

	P0V22[1] = C_21;
	Set_State(24, 1);
			break;
		case 1:    /*  P24S1() - СОСТОЯНИЕ: КонтрольВключения */

	if ((P0V10 == C_21) && (P0V11)) {
		Set_Start(26);
		Set_State(24, 2);
	}
  if (Timeout(24, C_11))  Set_State(24, 3);
			break;
		case 2:    /*  P24S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_100)) Set_Stop(24);
    if (Timeout(24, C_15))  Set_State(24, 4);
			break;
		case 3:    /*  P24S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_81))	Set_Error(24);
      if (Timeout(24, C_15))  Set_State(24, 4);
			break;
		case 4:    /*  P24S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(24);
			break;
		default:
			break;
	}
}

void P25 (void) /* ПРОЦЕСС: ВЫК_ПИТ_ВЕНТИЛЯТОР */
{
	switch (Check_State(25)) {

		case 0:    /*  P25S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(24) & MASK_OF_INACTIVITY))) Set_Error(24);
	Set_Stop(26);

	P0V22[1] = C_22;
	Set_State(25, 1);
			break;
		case 1:    /*  P25S1() - СОСТОЯНИЕ: КонтрольВыключения */

	if ((P0V10 == C_22) && (P0V11)) {
		Set_Start(27);
		Set_State(25, 2);
	} 
  if (Timeout(25, C_11))  Set_State(25, 3);
			break;
		case 2:    /*  P25S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_101)) Set_Stop(25);
    if (Timeout(25, C_15))  Set_State(25, 4);
			break;
		case 3:    /*  P25S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_82))	Set_Error(25);
      if (Timeout(25, C_15))  Set_State(25, 4);
			break;
		case 4:    /*  P25S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(25);
			break;
		default:
			break;
	}
}

void P26 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияВентилятора */
{
	switch (Check_State(26)) {

		case 0:    /*  P26S0() - СОСТОЯНИЕ: Контроль */

		if (P0V10 == C_22) Set_State(26, 1);
			break;
		case 1:    /*  P26S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_102)) {
			Set_Start(59);  		
			Set_Error(26);}
		if (Timeout(26, C_15))  Set_State(26, 2);
			break;
		case 2:    /*  P26S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(26);
			break;
		default:
			break;
	}
}

void P27 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияВентилятора */
{
	switch (Check_State(27)) {

		case 0:    /*  P27S0() - СОСТОЯНИЕ: Контроль */

		if (P0V10 == C_21) Set_State(27, 1);
			break;
		case 1:    /*  P27S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_103)) Set_Error(27);
				
		if (Timeout(27, C_15))  Set_State(27, 2);
			break;
		case 2:    /*  P27S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(27);
			break;
		default:
			break;
	}
}

void P28 (void) /* ПРОЦЕСС: ОТКР_ЗАТВОР_ВАК */
{
	switch (Check_State(28)) {

		case 0:    /*  P28S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(29) & MASK_OF_INACTIVITY))) Set_Error(29);
	Set_Stop(31);

	P0V26[1] = C_23;
	Set_State(28, 1);
			break;
		case 1:    /*  P28S1() - СОСТОЯНИЕ: Контроль */
  
	if ((P0V0 == C_21) && (P0V2 = C_22)) {
		Set_Start(30);		
		Set_State(28, 2);  
	}
  if (Timeout(28, C_7))  Set_State(28, 3);
			break;
		case 2:    /*  P28S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_104)) Set_Stop(28);
    if (Timeout(28, C_15))  Set_State(28, 4);
			break;
		case 3:    /*  P28S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_77))	Set_Error(28);
      if (Timeout(28, C_15))  Set_State(28, 4);
			break;
		case 4:    /*  P28S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(28);
			break;
		default:
			break;
	}
}

void P29 (void) /* ПРОЦЕСС: ЗАКР_ЗАТВОР_ВАК */
{
	switch (Check_State(29)) {

		case 0:    /*  P29S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(28) & MASK_OF_INACTIVITY))) Set_Error(28);
	Set_Stop(30);

	P0V26[1] = C_24;
	Set_State(29, 1);
			break;
		case 1:    /*  P29S1() - СОСТОЯНИЕ: Контроль */
  
	if ((P0V0 == C_22) && (P0V2 = C_21)) {
	Set_Start(31);	
	Set_State(29, 2);
	} 
	if (Timeout(29, C_7))  Set_State(29, 3);
			break;
		case 2:    /*  P29S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_105)) Set_Stop(29);
    if (Timeout(29, C_15))  Set_State(29, 4);
			break;
		case 3:    /*  P29S3() - СОСТОЯНИЕ: Ошибка */

    if (SendMsgGUICode(C_78))	Set_Error(29);
    if (Timeout(29, C_15))  Set_State(29, 4);
			break;
		case 4:    /*  P29S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(29);
			break;
		default:
			break;
	}
}

void P30 (void) /* ПРОЦЕСС: КонтрольСпонтанногоЗакрытияЗатвораВакуумного */
{
	switch (Check_State(30)) {

		case 0:    /*  P30S0() - СОСТОЯНИЕ: КонтрольЗакрытия */

		if ((P0V0 == C_22) && (P0V2 = C_21)) Set_State(30, 1);
			break;
		case 1:    /*  P30S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_107)) {
			Set_Start(59);  		
			Set_Error(30); }
		
		if (Timeout(30, C_15))  Set_State(30, 2);
			break;
		case 2:    /*  P30S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(30);
			break;
		default:
			break;
	}
}

void P31 (void) /* ПРОЦЕСС: КонтрольСпонтанногоОткрытияЗатвораВакуумного */
{
	switch (Check_State(31)) {

		case 0:    /*  P31S0() - СОСТОЯНИЕ: Контроль */

		if ((P0V0 == C_21) && (P0V2 = C_22)) Set_State(31, 1);
			break;
		case 1:    /*  P31S1() - СОСТОЯНИЕ: Ошибка */

			
		if (SendMsgGUICode(C_106)) { Set_Error(31);}

		if (Timeout(31, C_15))  Set_State(31, 2);
			break;
		case 2:    /*  P31S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(31);
			break;
		default:
			break;
	}
}

void P32 (void) /* ПРОЦЕСС: ОТКР_САПУН */
{
	switch (Check_State(32)) {

		case 0:    /*  P32S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(33) & MASK_OF_INACTIVITY))) Set_Error(33);
	Set_Stop(35);	

	P0V27[1] = C_23;
	Set_State(32, 1);
			break;
		case 1:    /*  P32S1() - СОСТОЯНИЕ: КонтрольОткрытия */
  

    if (P0V4 == C_23) {
		Set_Start(34);	
		Set_State(32, 2);	
	
	}Set_State(32, 2);
  if (Timeout(32, C_8))  Set_State(32, 3);
			break;
		case 2:    /*  P32S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_108)) Set_Stop(32);
    if (Timeout(32, C_15))  Set_State(32, 4);
			break;
		case 3:    /*  P32S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_79))	Set_Error(32);
      if (Timeout(32, C_15))  Set_State(32, 4);
			break;
		case 4:    /*  P32S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(32);
			break;
		default:
			break;
	}
}

void P33 (void) /* ПРОЦЕСС: ЗАКР_САПУН */
{
	switch (Check_State(33)) {

		case 0:    /*  P33S0() - СОСТОЯНИЕ: Начало */

   if ((!(Check_State(32) & MASK_OF_INACTIVITY))) Set_Error(32);
	Set_Stop(34);   

	P0V27[1] = C_24;
	Set_State(33, 1);
			break;
		case 1:    /*  P33S1() - СОСТОЯНИЕ: КонтрольЗакрытия */
  
	if (P0V4 == C_24) {
		Set_Start(35);	
		Set_State(33, 2); 
	}
  if (Timeout(33, C_8))  {
  
	Set_State(33, 3);
  }
			break;
		case 2:    /*  P33S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_109)) Set_Stop(33);
    if (Timeout(33, C_15))  Set_State(33, 4);
			break;
		case 3:    /*  P33S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_80))	Set_Error(33);
      if (Timeout(33, C_15))  Set_State(33, 4);
			break;
		case 4:    /*  P33S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(33);
			break;
		default:
			break;
	}
}

void P34 (void) /* ПРОЦЕСС: КонтрольСпонтанногоЗакрытияСапуна */
{
	switch (Check_State(34)) {

		case 0:    /*  P34S0() - СОСТОЯНИЕ: КонтрольЗакрытия */

		if (P0V4 == C_22)  Set_State(34, 1);
			break;
		case 1:    /*  P34S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_111)) Set_Error(34);
		
		if (Timeout(34, C_15))  Set_State(34, 2);
			break;
		case 2:    /*  P34S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(34);
			break;
		default:
			break;
	}
}

void P35 (void) /* ПРОЦЕСС: КонтрольСпонтанногоОткрытияСапуна */
{
	switch (Check_State(35)) {

		case 0:    /*  P35S0() - СОСТОЯНИЕ: Контроль */

		if (P0V4 == C_21) Set_State(35, 1);
			break;
		case 1:    /*  P35S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_110)) Set_Error(35);
				
		if (Timeout(35, C_15))  Set_State(35, 2);
			break;
		case 2:    /*  P35S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(35);
			break;
		default:
			break;
	}
}

void P36 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_ВАК_НАСОСА */
{
	switch (Check_State(36)) {

		case 0:    /*  P36S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(37) & MASK_OF_INACTIVITY))) Set_Error(37);
	Set_Stop(39);

	P0V25[1] = C_21;
	Set_State(36, 1);
			break;
		case 1:    /*  P36S1() - СОСТОЯНИЕ: КонтрольВключения */
  
  if (P0V8 == C_21) {
		Set_Start(38);
		Set_State(36, 2);
  }
  if (Timeout(36, C_10))  	Set_State(36, 3);
			break;
		case 2:    /*  P36S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_112)) Set_Stop(36);
    if (Timeout(36, C_15))  Set_State(36, 4);
			break;
		case 3:    /*  P36S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_98))	Set_Error(36);
      if (Timeout(36, C_15))  Set_State(36, 4);
			break;
		case 4:    /*  P36S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(36);
			break;
		default:
			break;
	}
}

void P37 (void) /* ПРОЦЕСС: ВЫК_ПИТ_ВАК_НАСОСА */
{
	switch (Check_State(37)) {

		case 0:    /*  P37S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(36) & MASK_OF_INACTIVITY))) Set_Error(36);
	Set_Stop(38);

	P0V25[1] = C_22;
	Set_State(37, 1);
			break;
		case 1:    /*  P37S1() - СОСТОЯНИЕ: КонтрольВыключения */
  
  if (P0V8 == C_22) {
  		Set_Start(39);
		Set_State(37, 4);
  }
  if (Timeout(37, C_10))  	Set_State(37, 2);
			break;
		case 2:    /*  P37S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_99))	Set_Error(37);
      if (Timeout(37, C_15))  Set_State(37, 3);
			break;
		case 3:    /*  P37S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(37);
			break;
		case 4:    /*  P37S4() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_113)) Set_Stop(37);
    if (Timeout(37, C_15))  Set_State(37, 3);
			break;
		default:
			break;
	}
}

void P38 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияВакНасоса */
{
	switch (Check_State(38)) {

		case 0:    /*  P38S0() - СОСТОЯНИЕ: Контроль */

		if (P0V8 == C_22) Set_State(38, 1);
			break;
		case 1:    /*  P38S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_115)) Set_Error(38);
		
		if (Timeout(38, C_15))  Set_State(38, 2);
			break;
		case 2:    /*  P38S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(38);
			break;
		default:
			break;
	}
}

void P39 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияВакНасоса */
{
	switch (Check_State(39)) {

		case 0:    /*  P39S0() - СОСТОЯНИЕ: Контроль */

		if (P0V8 == C_21) Set_State(39, 1);
			break;
		case 1:    /*  P39S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_114)) Set_Error(39);
				
		if (Timeout(39, C_15))  Set_State(39, 2);
			break;
		case 2:    /*  P39S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(39);
			break;
		default:
			break;
	}
}

void P40 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_РЕГ_Т */
{
	switch (Check_State(40)) {

		case 0:    /*  P40S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(41) & MASK_OF_INACTIVITY))) Set_Error(41);
		Set_Stop(43);

		P0V23[1] = C_21;
		Set_State(40, 1);
			break;
		case 1:    /*  P40S1() - СОСТОЯНИЕ: КонтрольВключения */
  
	if (P0V12 == C_21) {
		Set_Start(42);
		Set_State(40, 2);
	}
	if (Timeout(40, C_12))  Set_State(40, 3);
			break;
		case 2:    /*  P40S2() - СОСТОЯНИЕ: ПередачаСообщения */

    if (SendMsgGUICode(C_116)) Set_Stop(40);
    if (Timeout(40, C_15))  Set_State(40, 4);
			break;
		case 3:    /*  P40S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_85))	Set_Error(40);
      if (Timeout(40, C_15))  Set_State(40, 4);
			break;
		case 4:    /*  P40S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(40);
			break;
		default:
			break;
	}
}

void P41 (void) /* ПРОЦЕСС: ВЫК_ПИТ_РЕГ_Т */
{
	switch (Check_State(41)) {

		case 0:    /*  P41S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(40) & MASK_OF_INACTIVITY))) Set_Error(40);
	Set_Stop(42);

	P0V23[1]  = C_22;
	Set_State(41, 1);
			break;
		case 1:    /*  P41S1() - СОСТОЯНИЕ: КонтрольВыключения */
  
	if (P0V12 == C_21) {
		Set_Start(43);  
		Set_State(41, 2);
	} 
	if (Timeout(41, C_12))  Set_State(41, 3);
			break;
		case 2:    /*  P41S2() - СОСТОЯНИЕ: ПередачаСообщения */

		if (SendMsgGUICode(C_117)) Set_Stop(41);
		if (Timeout(41, C_15))  Set_State(41, 4);
			break;
		case 3:    /*  P41S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_86))	Set_Error(41);
      if (Timeout(41, C_15))  Set_State(41, 4);
			break;
		case 4:    /*  P41S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(41);
			break;
		default:
			break;
	}
}

void P42 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияРЕГ_Т */
{
	switch (Check_State(42)) {

		case 0:    /*  P42S0() - СОСТОЯНИЕ: Контроль */

		if (P0V12 == C_22) Set_State(42, 1);
			break;
		case 1:    /*  P42S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_119)) Set_Error(42);
		
		if (Timeout(42, C_15))  Set_State(42, 2);
			break;
		case 2:    /*  P42S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(42);
			break;
		default:
			break;
	}
}

void P43 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияРЕГ_Т */
{
	switch (Check_State(43)) {

		case 0:    /*  P43S0() - СОСТОЯНИЕ: Контроль */

		if (P0V12 == C_21) Set_State(43, 1);
			break;
		case 1:    /*  P43S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_118)) Set_Error(43);
				
		if (Timeout(43, C_15))  Set_State(43, 2);
			break;
		case 2:    /*  P43S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(43);
			break;
		default:
			break;
	}
}

void P44 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_РЕГ_УР */
{
	switch (Check_State(44)) {

		case 0:    /*  P44S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(45) & MASK_OF_INACTIVITY))) Set_Error(45);
	Set_Stop(47);

	P0V29[1] = C_21;
	Set_State(44, 1);
			break;
		case 1:    /*  P44S1() - СОСТОЯНИЕ: Контроль */
  
	if (P0V14 == C_21){
		Set_Start(46);
		Set_State(44, 2);
	} 
  if (Timeout(44, C_13))  Set_State(44, 3);
			break;
		case 2:    /*  P44S2() - СОСТОЯНИЕ: ПередачаСообщения */

  if (SendMsgGUICode(C_120)) Set_Stop(44);
  if (Timeout(44, C_15))  Set_State(44, 4);
			break;
		case 3:    /*  P44S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_87))	Set_Error(44);
      if (Timeout(44, C_15))  Set_State(44, 4);
			break;
		case 4:    /*  P44S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(44);
			break;
		default:
			break;
	}
}

void P45 (void) /* ПРОЦЕСС: ВЫК_ПИТ_РЕГ_УР */
{
	switch (Check_State(45)) {

		case 0:    /*  P45S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(44) & MASK_OF_INACTIVITY))) Set_Error(44);
	Set_Stop(46);

	P0V29[1] = C_22;
	Set_State(45, 1);
			break;
		case 1:    /*  P45S1() - СОСТОЯНИЕ: Контроль */
  
	if (P0V14 == C_22) {
		Set_Start(47);  
		Set_State(45, 2);
	} 
  if (Timeout(45, C_13))  	Set_State(45, 3);
			break;
		case 2:    /*  P45S2() - СОСТОЯНИЕ: ПередачаСообщения */

  if (SendMsgGUICode(C_121)) Set_Stop(45);
  if (Timeout(45, C_15))  Set_State(45, 4);
			break;
		case 3:    /*  P45S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_88))	Set_Error(45);
      if (Timeout(45, C_15))  Set_State(45, 4);
			break;
		case 4:    /*  P45S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(45);
			break;
		default:
			break;
	}
}

void P46 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияРЕГ_УР */
{
	switch (Check_State(46)) {

		case 0:    /*  P46S0() - СОСТОЯНИЕ: Контроль */

		if (P0V14 == C_22) Set_State(46, 1);
			break;
		case 1:    /*  P46S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_123)) Set_Error(46);
		
		if (Timeout(46, C_15))  Set_State(46, 2);
			break;
		case 2:    /*  P46S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(46);
			break;
		default:
			break;
	}
}

void P47 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияРЕГ_УР */
{
	switch (Check_State(47)) {

		case 0:    /*  P47S0() - СОСТОЯНИЕ: Контроль */

		if (P0V14 == C_21) Set_State(47, 1);
			break;
		case 1:    /*  P47S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_122)) Set_Error(47);
				
		if (Timeout(47, C_15))  Set_State(47, 2);
			break;
		case 2:    /*  P47S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(47);
			break;
		default:
			break;
	}
}

void P48 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_НАС_ОХЛ */
{
	switch (Check_State(48)) {

		case 0:    /*  P48S0() - СОСТОЯНИЕ: Начало */

  if (P0V32 == C_27)  Set_State(48, 1);
  else Set_Error(48);
			break;
		case 1:    /*  P48S1() - СОСТОЯНИЕ: ВключениеПитания */

	if ((!(Check_State(49) & MASK_OF_INACTIVITY))) Set_Error(49);
	Set_Stop(51);   

	P0V24[1] = C_21;
	Set_State(48, 2);
			break;
		case 2:    /*  P48S2() - СОСТОЯНИЕ: Контроль */
  
  if (P0V20 == C_21) {
  	Set_Start(50);
	Set_State(48, 3);
  } 
  if (Timeout(48, C_14))  Set_State(48, 4);
			break;
		case 3:    /*  P48S3() - СОСТОЯНИЕ: ПередачаСообщения */

  if (SendMsgGUICode(C_124)) Set_Stop(48);
  if (Timeout(48, C_15))  Set_State(48, 5);
			break;
		case 4:    /*  P48S4() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_89))	Set_Error(48);
      if (Timeout(48, C_15))  Set_State(48, 5);
			break;
		case 5:    /*  P48S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(48);
			break;
		default:
			break;
	}
}

void P49 (void) /* ПРОЦЕСС: ВЫК_ПИТ_НАС_ОХЛ */
{
	switch (Check_State(49)) {

		case 0:    /*  P49S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(48) & MASK_OF_INACTIVITY))) Set_Error(48);
   	Set_Stop(50);

	P0V24[1] = C_22;
	Set_State(49, 1);
			break;
		case 1:    /*  P49S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V20 == C_22) {
  		Set_Start(51);
		Set_State(49, 2);
  }
  if (Timeout(49, C_14))  Set_State(49, 3);
			break;
		case 2:    /*  P49S2() - СОСТОЯНИЕ: ПередачаСообщения */

  if (SendMsgGUICode(C_125)) Set_Stop(49);
  if (Timeout(49, C_15))  Set_State(49, 4);
			break;
		case 3:    /*  P49S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_90))	Set_Error(49);
      if (Timeout(49, C_15))  Set_State(49, 4);
			break;
		case 4:    /*  P49S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(49);
			break;
		default:
			break;
	}
}

void P50 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияНасосаОхлаждения */
{
	switch (Check_State(50)) {

		case 0:    /*  P50S0() - СОСТОЯНИЕ: Контроль */

		if (P0V20 == C_22) Set_State(50, 1);
			break;
		case 1:    /*  P50S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_127)) Set_Error(50);
		
		if (Timeout(50, C_15))  Set_State(50, 2);
			break;
		case 2:    /*  P50S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(50);
			break;
		default:
			break;
	}
}

void P51 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияНасосаОхлаждения */
{
	switch (Check_State(51)) {

		case 0:    /*  P51S0() - СОСТОЯНИЕ: Контроль */

		if (P0V20 == C_21) Set_State(51, 1);
			break;
		case 1:    /*  P51S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_126)) Set_Error(51);
				
		if (Timeout(51, C_15))  Set_State(51, 2);
			break;
		case 2:    /*  P51S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(51);
			break;
		default:
			break;
	}
}

void P52 (void) /* ПРОЦЕСС: ВКЛ_УСТР_ПЛАВ_ПУСКА */
{
	switch (Check_State(52)) {

		case 0:    /*  P52S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(53) & MASK_OF_INACTIVITY))) Set_Error(53);
    Set_Stop(55);

	P0V28[1] = C_21;
	Set_State(52, 1);
			break;
		case 1:    /*  P52S1() - СОСТОЯНИЕ: Контроль */
  
	if (P0V6 == C_21) {
		Set_Start(54);  
		Set_State(52, 2);
	}
  if (Timeout(52, C_9))   	Set_State(52, 3);
			break;
		case 2:    /*  P52S2() - СОСТОЯНИЕ: ПередачаСообщения */

  if (SendMsgGUICode(C_128)) Set_Stop(52);
  if (Timeout(52, C_15))  Set_State(52, 4);
			break;
		case 3:    /*  P52S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_83))	Set_Error(52);
      if (Timeout(52, C_15))  Set_State(52, 4);
			break;
		case 4:    /*  P52S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(52);
			break;
		default:
			break;
	}
}

void P53 (void) /* ПРОЦЕСС: ВЫК_УСТР_ПЛАВ_ПУСКА */
{
	switch (Check_State(53)) {

		case 0:    /*  P53S0() - СОСТОЯНИЕ: Начало */
	
	if ((!(Check_State(52) & MASK_OF_INACTIVITY))) Set_Error(52);
	Set_Stop(54);	

	P0V28[1] = C_22;	
	Set_State(53, 1);
			break;
		case 1:    /*  P53S1() - СОСТОЯНИЕ: КонтрольВыключения */
  
	if (P0V6 == C_22) {
		Set_Start(55);
		Set_State(53, 2);
	}
	if (Timeout(53, C_9))  	Set_State(53, 3);
			break;
		case 2:    /*  P53S2() - СОСТОЯНИЕ: ПередачаСообщения */

  if (SendMsgGUICode(C_129)) Set_Stop(53);
  if (Timeout(53, C_15))  Set_State(53, 4);
			break;
		case 3:    /*  P53S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_84))	Set_Error(53);
      if (Timeout(53, C_15))  Set_State(53, 4);
			break;
		case 4:    /*  P53S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(53);
			break;
		default:
			break;
	}
}

void P54 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияПлавнПуска */
{
	switch (Check_State(54)) {

		case 0:    /*  P54S0() - СОСТОЯНИЕ: Контроль */

		if (P0V6 == C_22) Set_State(54, 1);
			break;
		case 1:    /*  P54S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_131)) Set_Error(54);
		
		if (Timeout(54, C_15))  Set_State(54, 2);
			break;
		case 2:    /*  P54S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(54);
			break;
		default:
			break;
	}
}

void P55 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияПлавнПуска */
{
	switch (Check_State(55)) {

		case 0:    /*  P55S0() - СОСТОЯНИЕ: Контроль */

		if (P0V6 == C_21) Set_State(55, 1);
			break;
		case 1:    /*  P55S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_130)) Set_Error(55);
				
		if (Timeout(55, C_15))  Set_State(55, 2);
			break;
		case 2:    /*  P55S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(55);
			break;
		default:
			break;
	}
}

void P56 (void) /* ПРОЦЕСС: ВКЛ_ВАКУУМНУЮ_ПОДСИСТЕМУ */
{
	switch (Check_State(56)) {

		case 0:    /*  P56S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(57) & MASK_OF_INACTIVITY))) Set_Error(57);
	
		if (P0V37 != C_27) Set_State(56, 20);
		else Set_State(56, 1);
			break;
		case 1:    /*  P56S1() - СОСТОЯНИЕ: КонтрольГотовностиУровняИтемпературы */

		if ((P0V42 > C_32)|| 
			(P0V32 == C_28)||
			(P0V33 == C_28 )) Set_State(56, 20);
			else 	{
				Set_Start(24);
				Set_State(56, 2);
			}
			break;
		case 2:    /*  P56S2() - СОСТОЯНИЕ: КонтрольВключенияВентилятора */

		if ( (Check_State(24) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(24) == STATE_OF_ERROR) ) Set_State(56, 20);
				else {
					Set_Start(48);
					Set_State(56, 3);
				}
		}
			break;
		case 3:    /*  P56S3() - СОСТОЯНИЕ: КонтрольВключенияПитанияНасосаОхлаждения */

		if ((Check_State(48) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(48) == STATE_OF_ERROR)) Set_State(56, 20);
				else {
					Set_Start(29);
					Set_State(56, 4);
				}
		}
			break;
		case 4:    /*  P56S4() - СОСТОЯНИЕ: КонтрольЗакрытияЗатвораВакуумного */

		if ((Check_State(29) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(29) == STATE_OF_ERROR) ) Set_State(56, 20);
			else {
				Set_Start(32);
				Set_State(56, 5);
			}
		}
			break;
		case 5:    /*  P56S5() - СОСТОЯНИЕ: КонтрольОткрытияСапуна */

		if ( (Check_State(32) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(32) == STATE_OF_ERROR) ) Set_State(56, 20);
			else Set_State(56, 6);
		}
			break;
		case 6:    /*  P56S6() - СОСТОЯНИЕ: КонтрольТемпературыРубашки */

		if (P0V34 == C_27) Set_State(56, 7);

		else Set_State(56, 20);
			break;
		case 7:    /*  P56S7() - СОСТОЯНИЕ: ПодачаПитанияНаВакуумныйНасос */

		Set_Start(36);
		Set_State(56, 8);
			break;
		case 8:    /*  P56S8() - СОСТОЯНИЕ: КонтрольПитанияВакуумногоНасоса */

		if ( (Check_State(36) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(36) == STATE_OF_ERROR)) Set_State(56, 20);
			else  Set_State(56, 9);
		}
			break;
		case 9:    /*  P56S9() - СОСТОЯНИЕ: ВключениеУстройстваПлавногоПуска */

		Set_Start(52);
		Set_State(56, 10);
			break;
		case 10:    /*  P56S10() - СОСТОЯНИЕ: КонтрольВлюченияПлавногоПуска */

		if ((Check_State(52) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(52) == STATE_OF_ERROR)) Set_State(56, 20);
			else  Set_State(56, 11);
		}
			break;
		case 11:    /*  P56S11() - СОСТОЯНИЕ: ТаймаутПередЗакрытиемСапуна */
  
		if (Timeout(56, C_16))  Set_State(56, 12);
			break;
		case 12:    /*  P56S12() - СОСТОЯНИЕ: ЗакрытиеСапуна */
  
		Set_Start(33);
		Set_State(56, 13);
			break;
		case 13:    /*  P56S13() - СОСТОЯНИЕ: КонтрольЗакрытияСапуна */

		if ( (Check_State(33) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(33) == STATE_OF_ERROR) ) Set_State(56, 20);
			else Set_State(56, 14);
		}
			break;
		case 14:    /*  P56S14() - СОСТОЯНИЕ: ЗапоминаемДавлениеВпатрубке */

			P56V9 = P0V40;
			Set_State(56, 15);
			break;
		case 15:    /*  P56S15() - СОСТОЯНИЕ: КонтрольДавления */
  
		if (P0V43 >= P0V40) {
			Set_Start(28); 
			Set_State(56, 18);
			}
		else Set_State(56, 16);
			break;
		case 16:    /*  P56S16() - СОСТОЯНИЕ: ПаузаНаОткачкуВпатрубке */
  
		if (Timeout(56, C_17))  Set_State(56, 17);
			break;
		case 17:    /*  P56S17() - СОСТОЯНИЕ: ПроверкаУменьшенияДавленияВпатрубке */
  
		if(P0V40 < P56V9) Set_State(56, 14);
        else Set_State(56, 19);
			break;
		case 18:    /*  P56S18() - СОСТОЯНИЕ: КонтрольОткрытияЗВ */

		if ( (Check_State(28) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(28) == STATE_OF_ERROR) ) Set_State(56, 20);
			else { 
				Set_Start(18);
				Set_Stop(56);
			}
		}
			break;
		case 19:    /*  P56S19() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_95))	Set_State(56, 20);
      if (Timeout(56, C_15))  Set_State(56, 22);
			break;
		case 20:    /*  P56S20() - СОСТОЯНИЕ: ВыключениеПоОшибке */

     if (!((!(Check_State(57) & MASK_OF_INACTIVITY)))) Set_Start(57);
    Set_State(56, 21);
			break;
		case 21:    /*  P56S21() - СОСТОЯНИЕ: СообщениеОбОтказеВакуумирования */

       if (SendMsgGUICode(C_133))	Set_Error(56);
      if (Timeout(56, C_15))  Set_State(56, 22);
			break;
		case 22:    /*  P56S22() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(56);
			break;
		default:
			break;
	}
}

void P57 (void) /* ПРОЦЕСС: ВЫК_ВАКУУМНУЮ_ПОДСИСТЕМУ */
{
	switch (Check_State(57)) {

		case 0:    /*  P57S0() - СОСТОЯНИЕ: Начало */

 		Set_Start(29);
		Set_Stop(18);
		Set_State(57, 1);
			break;
		case 1:    /*  P57S1() - СОСТОЯНИЕ: КонтрольЗакрытияЗатвораВакуумного */

		if ((Check_State(29) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(29) == STATE_OF_ERROR) ) Set_State(57, 9);
			else {
				Set_Start(32);
				Set_State(57, 2);
			}
		}
			break;
		case 2:    /*  P57S2() - СОСТОЯНИЕ: КонтрольОткрытияСапуна */

		if ( (Check_State(32) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(32) == STATE_OF_ERROR) ) Set_State(57, 9);
			else {
				
				Set_State(57, 3);
			}
		}
			break;
		case 3:    /*  P57S3() - СОСТОЯНИЕ: ТаймаутПередВыключениемПитанияВакуумногоНасоса */
  
		if (Timeout(57, C_6))  Set_State(57, 4);
			break;
		case 4:    /*  P57S4() - СОСТОЯНИЕ: ВыключаемУППВакуумногоНасоса */
  
		Set_Start(53); Set_State(57, 5);
			break;
		case 5:    /*  P57S5() - СОСТОЯНИЕ: КонтрольВыключенияПитанияУППВакуумногоНасоса */

		if ( (Check_State(53) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(53) == STATE_OF_ERROR)) Set_State(57, 9);
			else {
				Set_Start(37);
				Set_State(57, 6);
			}
		}
			break;
		case 6:    /*  P57S6() - СОСТОЯНИЕ: КонтрольВыключенияПитанияВакуумногоНасоса */

		if ( (Check_State(37) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(37) == STATE_OF_ERROR)) Set_State(57, 9);
			else {
				Set_Start(49);
				Set_State(57, 7);
			}
		}
			break;
		case 7:    /*  P57S7() - СОСТОЯНИЕ: КонтрольВыключенияНасосаОхлаждения */

		if ( (Check_State(49) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(49) == STATE_OF_ERROR) ) Set_State(57, 9);
				else {
					Set_Start(25);
					Set_State(57, 8);
				}
		}
			break;
		case 8:    /*  P57S8() - СОСТОЯНИЕ: КонтрольВыключенияВентилятора */

		if ( (Check_State(25) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(25) == STATE_OF_ERROR) ) Set_State(57, 9);

				else Set_Stop(57);
		}
			break;
		case 9:    /*  P57S9() - СОСТОЯНИЕ: СообщениеОбОтказеВыклВакСистемы */

      if (SendMsgGUICode(C_134))	Set_Error(57);
      if (Timeout(57, C_15))  Set_State(57, 10);
			break;
		case 10:    /*  P57S10() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(57);
			break;
		default:
			break;
	}
}

void P58 (void) /* ПРОЦЕСС: ВКЛ_ВАКУУМИРОВАНИЕ_ТРУБЫ */
{
	switch (Check_State(58)) {

		case 0:    /*  P58S0() - СОСТОЯНИЕ: Начало */

   if (P0V35 == C_27) Set_State(58, 6);
   else {  
	Set_Start(56);
	Set_State(58, 1);
	}
			break;
		case 1:    /*  P58S1() - СОСТОЯНИЕ: КонтрольВключенияВакПодсистемы */

		if ( (Check_State(56) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(56) == STATE_OF_ERROR) ) {
				Set_Error(58);  
			}
			else Set_State(58, 2);
		}
			break;
		case 2:    /*  P58S2() - СОСТОЯНИЕ: ЗапоминаемДавлениеВвакуумнойТрубе */

			P58V7 = P0V43;
			Set_State(58, 3);
			break;
		case 3:    /*  P58S3() - СОСТОЯНИЕ: КонтрольОборудования */
  
			if ( (P0V41 <= 85) && (P0V10) && (P0V20) ) Set_State(58, 4);
			else {
				Set_State(58, 10);
			}
			break;
		case 4:    /*  P58S4() - СОСТОЯНИЕ: КонтрольДавления */
  
		if (P0V43 <= P0V46) {  
			Set_Start(57); 
			Set_State(58, 5);
		}
		else Set_State(58, 7);
			break;
		case 5:    /*  P58S5() - СОСТОЯНИЕ: СообщениеОКонцеВакуумирования */

		if (SendMsgGUICode(C_97)) Set_State(58, 6); 
		if (Timeout(58, C_15))  Set_Error(58);
			break;
		case 6:    /*  P58S6() - СОСТОЯНИЕ: ПаузаНаРазвакуумированиеТрубы */

      if (Timeout(58, C_16))  Set_State(58, 0);
			break;
		case 7:    /*  P58S7() - СОСТОЯНИЕ: ПаузаНаОткачкуВвакуумнойТрубе */
  
		if (Timeout(58, C_17))  Set_State(58, 8);
			break;
		case 8:    /*  P58S8() - СОСТОЯНИЕ: ПроверкаУменьшенияДавленияВпатрубке */
  
		if(P0V43 < P58V7) Set_State(58, 2);
        else Set_State(58, 9);
			break;
		case 9:    /*  P58S9() - СОСТОЯНИЕ: ОткачкаОтсутствует */

       if (SendMsgGUICode(C_96))	Set_State(58, 10);
      if (Timeout(58, C_15))  Set_State(58, 12);
			break;
		case 10:    /*  P58S10() - СОСТОЯНИЕ: ВыключениеВакуумнойПодсистемы */

     if (!((!(Check_State(57) & MASK_OF_INACTIVITY)))) Set_Start(57);
    Set_State(58, 11);
			break;
		case 11:    /*  P58S11() - СОСТОЯНИЕ: СообщениеОбОтказеВакуумирования */

       if (SendMsgGUICode(C_132))	Set_Error(58);
      if (Timeout(58, C_15))  Set_State(58, 12);
			break;
		case 12:    /*  P58S12() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(58);
			break;
		default:
			break;
	}
}

void P59 (void) /* ПРОЦЕСС: ВЫК_ВАКУУМИРОВАНИЕ_ТРУБЫ */
{
	switch (Check_State(59)) {

		case 0:    /*  P59S0() - СОСТОЯНИЕ: Начало */

		Set_Stop(58);

	Set_Start(57); 
	Set_Stop(59);
			break;
		default:
			break;
	}
}
