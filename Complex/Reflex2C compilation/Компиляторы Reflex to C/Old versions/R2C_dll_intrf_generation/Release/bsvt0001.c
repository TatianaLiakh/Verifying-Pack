/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "bsvtext.inc" /* Common files for all generated c-files */
#include "bsvtxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
  
    	P0V41 = 1; 
     P0V24[1] = C_22;
	P0V46 = 0.02;   
	

	Set_Start(1);
	Set_Start(2);
	Set_Start(4);
	Set_Start(5);
	Set_Start(6);
	Set_Start(7);
	Set_Start(8);

	if (!P0V6) Set_Start(23);   
	
	Set_Start(25);

	
	Set_Start(11);
	Set_Start(13);
	Set_Start(14);
	Set_Start(10);	
	Set_Start(12);	

	Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* ПРОЦЕСС: ЧтениеФактПараметров_с_Датчиков */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - СОСТОЯНИЕ: Начало */

	P0V42 	= GetFP_P_BAK_COMPRESSOR();     
	P0V43 		= GetFP_P_PATRUBKA();     			
	P0V44 		= GetFP_T_RUBACHKA();     			   
	P0V45 			= GetFP_T_BAK();     				 
	P0V47 	= GetFP_P_TRUBA();     				 
   Set_State(1, 0);
			break;
		default:
			break;
	}
}

void P2 (void) /* ПРОЦЕСС: ЧтениеКольцевогоБуфера */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - СОСТОЯНИЕ: Начало */

    
    if (GetNextMsgGUI()) {
      P0V33 = GetMsgGUICode();
            if ((P0V33 >= C_49) &&
                  (P0V33 <= C_69)) {
				Set_Start(3);
				Set_State(2, 1);
             } 
			 else Set_State(2, 2);



      
    }
			break;
		case 1:    /*  P2S1() - СОСТОЯНИЕ: КонтрольВыполненияК */

    if((Check_State(3) & MASK_OF_INACTIVITY))
    Set_State(2, 0);
			break;
		case 2:    /*  P2S2() - СОСТОЯНИЕ: НекорректноеСобытие */

     if (SendMsgLongParamGUI(C_102, P0V33))
       Set_State(2, 0);
     if (Timeout(2, C_15))  Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_Stop(2);
			break;
		default:
			break;
	}
}

void P3 (void) /* ПРОЦЕСС: ОбработкаКомандУправления_от_ГУИ */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - СОСТОЯНИЕ: Анализ */

    switch (P0V33) {
	    case C_49:
			Set_Start(17);
			break;
	    case C_50:
			Set_Start(18);
			break;		  
	    case C_51:
		  if (P0V3 == C_22) { 
			Set_Start(19); 
		  } else {
		    P3V10 = C_90;
			Set_State(3, 2);
		  }
		  break;
	    case C_52:
		  if (P0V3 == C_22) { 
			Set_Start(20); 
		  } else {
		    P3V10 = C_90;
			Set_State(3, 2);
		  }
		  break;

		case C_53:
			if (P0V3 == C_22) { 
				if ((P0V35 == C_27) && (P0V5)
						&& (P0V10)&& (P0V1) && (P0V2)
						&& (P0V37 == C_27)) {   
						Set_Start(29);
				} else {
					P3V10 = C_91;
					Set_State(3, 2);
				}
			} else {
				P3V10 = C_90;
				Set_State(3, 2);
			}			
			break;
	
			
	    case C_54:   
			Set_Start(30);
			break;	
		case C_55:			
          Set_Start(21);
          break;
	    case C_56:
          Set_Start(22);
          break;			  
	    case C_57:
		  if (P0V3 == C_22) {  
			Set_Start(15); 
		  } else {
		    P3V10 = C_90;
			Set_State(3, 2);
			}
          break;
	    case C_58:
          if (P0V3 == C_22) { 
			Set_Start(16); 
		  } else {  
		    P3V10 = C_90;
			Set_State(3, 2);
		  } 
          break;
	    case C_59:
		  if(P0V3 == C_22) {   
		  


				if (P0V35 == C_27) {
					if (P0V45 > 0.0) {
						Set_Start(23);
					} else {
					 P3V10 = C_93;
					 Set_State(3, 2);
					}
				P3V10 = C_92;
				Set_State(3, 2);				
				}
				
		  } else {   
		    P3V10 = C_90;
			Set_State(3, 2);
		  }
		  break;
	    case C_60:
		  if(P0V3 == C_22) {   
			Set_Start(24);
		  } else {   
		    P3V10 = C_90;
			Set_State(3, 2);
		  }
          break;
	    case C_61:
		  if(P0V3 == C_22) {   
		  	Set_Start(25);
		  } else {   
		    P3V10 = C_90;
			Set_State(3, 2);
		  } 
          break;
	    case C_62:
		  if(P0V3 == C_22) {   
		  	Set_Start(26);
		  } else {   
		    P3V10 = C_90;
			Set_State(3, 2);
		  } 
		  break;
	    case C_63:
		  if(P0V3 == C_22) {   
				if ((P0V35 = C_27) && (P0V45 > 0.0)) Set_Start(27);
		  } else {   
		    P3V10 = C_90;
			Set_State(3, 2);
		  }
		  break;
	    case C_64:
		  if(P0V3 == C_22) {   
		  	Set_Start(28);
		  } else {   
		    P3V10 = C_90;
			Set_State(3, 2);
		  } 		
		  break;
		  


		  case C_65:   
          Set_Start(33);
          break;
	    case C_66:
          Set_Start(34);
          break;
		default:
          Set_State(3, 1);
          break;
    }
			break;
		case 1:    /*  P3S1() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_102, P0V33))
         Set_Stop(3);   
    if (Timeout(3, C_15))  Set_State(3, 3);
			break;
		case 2:    /*  P3S2() - СОСТОЯНИЕ: ПередачаСообщенияСПараметромГУИ */

    if (SendMsgLongParamGUI(P3V10, P0V33))
        Set_Stop(3);
    if (Timeout(3, C_15))  Set_State(3, 3);
			break;
		case 3:    /*  P3S3() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_Error(3);
			break;
		default:
			break;
	}
}

void P4 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_ВбакеКомпрессора */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - СОСТОЯНИЕ: Начало */

    P4V2 = (!P0V42);
    Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P4V2 != P0V42) {
         P4V2 = P0V42;
         Set_State(4, 2);
    }
			break;
		case 2:    /*  P4S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_97, P4V2))
         Set_State(4, 3);
     if (Timeout(4, C_15))  Set_State(4, 4);
			break;
		case 3:    /*  P4S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(4, P0V41))  Set_State(4, 1);
			break;
		case 4:    /*  P4S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(4, 1);
			break;
		default:
			break;
	}
}

void P5 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_Впатрубке */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - СОСТОЯНИЕ: Начало */

    P5V2 = (!P0V43);
    Set_State(5, 1);
			break;
		case 1:    /*  P5S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P5V2 != P0V43) {
         P5V2 = P0V43;
         Set_State(5, 2);
    }
			break;
		case 2:    /*  P5S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_98, P5V2))
         Set_State(5, 3);
     if (Timeout(5, C_15))  Set_State(5, 4);
			break;
		case 3:    /*  P5S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(5, P0V41))  Set_State(5, 1);
			break;
		case 4:    /*  P5S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(5, 1);
			break;
		default:
			break;
	}
}

void P6 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_T_Врубашке */
{
	switch (Check_State(6)) {

		case 0:    /*  P6S0() - СОСТОЯНИЕ: Начало */

    P6V2 = (!P0V44);
    Set_State(6, 1);
			break;
		case 1:    /*  P6S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P6V2 != P0V44) {
         P6V2 = P0V44;
         Set_State(6, 2);
    }
			break;
		case 2:    /*  P6S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_99, P6V2))
         Set_State(6, 3);
     if (Timeout(6, C_15))  Set_State(6, 4);
			break;
		case 3:    /*  P6S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(6, P0V41))  Set_State(6, 1);
			break;
		case 4:    /*  P6S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(6, 1);
			break;
		default:
			break;
	}
}

void P7 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_T_Вбаке */
{
	switch (Check_State(7)) {

		case 0:    /*  P7S0() - СОСТОЯНИЕ: Начало */

    P7V2 = (!P0V45);
    Set_State(7, 1);
			break;
		case 1:    /*  P7S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P7V2 != P0V45) {
         P7V2 = P0V45;
         Set_State(7, 2);
    }
			break;
		case 2:    /*  P7S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_100, P7V2))
         Set_State(7, 3);
     if (Timeout(7, C_15))  Set_State(7, 4);
			break;
		case 3:    /*  P7S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(7, P0V41))  Set_State(7, 1);
			break;
		case 4:    /*  P7S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(7, 1);
			break;
		default:
			break;
	}
}

void P8 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_ВтрубеСидер */
{
	switch (Check_State(8)) {

		case 0:    /*  P8S0() - СОСТОЯНИЕ: Начало */

    P8V2 = (!P0V47);
    Set_State(8, 1);
			break;
		case 1:    /*  P8S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P8V2 != P0V47) {
         P8V2 = P0V47;
         Set_State(8, 2);
    }
			break;
		case 2:    /*  P8S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_101, P8V2))
         Set_State(8, 3);
     if (Timeout(8, C_15))  Set_State(8, 4);
			break;
		case 3:    /*  P8S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(8, P0V41))  Set_State(8, 1);
			break;
		case 4:    /*  P8S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(8, 1);
			break;
		default:
			break;
	}
}

void P9 (void) /* ПРОЦЕСС: КонтрольОткачкиВауумнойТрубыСидеростата */
{
	switch (Check_State(9)) {

		case 0:    /*  P9S0() - СОСТОЯНИЕ: Начало */

	P9V2 = P0V47;
	if (Timeout(9, C_20))  Set_State(9, 1);
			break;
		case 1:    /*  P9S1() - СОСТОЯНИЕ: АнализОткачки */

	if ((P0V47 - P9V2) < -0.05) {    
        if (SendMsgGUICode(C_45)) {
					P0V39 = C_27;
					Set_State(9, 0);
		} 
    } else{
	if (SendMsgGUICode(C_46)) {
					P0V39 = C_28;
					Set_State(9, 0);
		} 
	}
			break;
		default:
			break;
	}
}

void P10 (void) /* ПРОЦЕСС: КонтрольГотовностиВакуума_в_Вакуумной_Трубе */
{
	switch (Check_State(10)) {

		case 0:    /*  P10S0() - СОСТОЯНИЕ: Начало */

   if (P0V47 <= P0V46) {
         if (SendMsgGUICode(C_43)) {
					P0V38 = C_27;
					Set_State(10, 1);
					}
    
    } else {
                if (SendMsgGUICode(C_44)) {
					P0V38 = C_28;
				   Set_State(10, 2);
				}
    }
    if (Timeout(10, C_15))  Set_State(10, 4);
			break;
		case 1:    /*  P10S1() - СОСТОЯНИЕ: ДавлениеНормальное */

       if (P0V47 > 0.025)  Set_State(10, 0);
			break;
		case 2:    /*  P10S2() - СОСТОЯНИЕ: ДавлениеВысокое */

       if (P0V47 < 0.01)  Set_State(10, 0);
			break;
		case 3:    /*  P10S3() - СОСТОЯНИЕ: Задержка */

      if (Timeout(10, C_16))  Set_State(10, 0);
			break;
		case 4:    /*  P10S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(10, 0);
			break;
		default:
			break;
	}
}

void P11 (void) /* ПРОЦЕСС: КонтрольУровняВодыБакаОхлаждения */
{
	switch (Check_State(11)) {

		case 0:    /*  P11S0() - СОСТОЯНИЕ: Начало */

     if (P0V8) {
         if (SendMsgGUICode(C_34)) {
					P0V35 = C_28;
					Set_State(11, 1);
					}
    } else if (P0V9) {
              if (SendMsgGUICode(C_35)) {
			   P0V35 = C_28;
			   Set_State(11, 2);
			   }
    } else {
                if (SendMsgGUICode(C_36)) {
					P0V35 = C_27;
				   Set_State(11, 3);
				}
         }
    if (Timeout(11, C_15))  Set_State(11, 5);
			break;
		case 1:    /*  P11S1() - СОСТОЯНИЕ: НизкийУровеньВоды */

        if (!P0V8)  Set_State(11, 4);
			break;
		case 2:    /*  P11S2() - СОСТОЯНИЕ: ВысокийУровеньВоды */

       if (!P0V9)  Set_State(11, 4);
			break;
		case 3:    /*  P11S3() - СОСТОЯНИЕ: УровеньВодыВнорме */

	   if (P0V8 && P0V9)  Set_State(11, 4);
			break;
		case 4:    /*  P11S4() - СОСТОЯНИЕ: Задержка */

      if (Timeout(11, C_16))  Set_State(11, 0);
			break;
		case 5:    /*  P11S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(11, 0);
			break;
		default:
			break;
	}
}

void P12 (void) /* ПРОЦЕСС: КонтрольТемпературыВодыБакаОхлаждения */
{
	switch (Check_State(12)) {

		case 0:    /*  P12S0() - СОСТОЯНИЕ: Начало */

    if (P0V45 < 50) {
         if (SendMsgGUICode(C_37)) {
					P0V36 = C_28;
					Set_State(12, 1);
					}
    } else if (P0V45 > 60) {
              if (SendMsgGUICode(C_38)) {
			   P0V36 = C_28;
			   Set_State(12, 2);
			   }
    } else {
                if (SendMsgGUICode(C_39)) {
					P0V36 = C_27;
				   Set_State(12, 3);
				}
         }
    if (Timeout(12, C_15))  Set_State(12, 5);
			break;
		case 1:    /*  P12S1() - СОСТОЯНИЕ: НизкаяТемператураВоды */

        if (P0V45 > (50.0 + C_32))  Set_State(12, 0);
			break;
		case 2:    /*  P12S2() - СОСТОЯНИЕ: ВысокаяТемператураВоды */

       if (P0V45 < (60.0 - C_32))  Set_State(12, 0);
			break;
		case 3:    /*  P12S3() - СОСТОЯНИЕ: ТемператураВнорме */

       if ((P0V45 < (50.0 - C_32)) && 
	         (P0V45 > (60.0 + C_32)))  Set_State(12, 0);
			break;
		case 4:    /*  P12S4() - СОСТОЯНИЕ: Задержка */


      if (Timeout(12, C_16))  Set_State(12, 0);
			break;
		case 5:    /*  P12S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(12, 0);
			break;
		default:
			break;
	}
}

void P13 (void) /* ПРОЦЕСС: КонтрольТемпературыРубашкиОхлаждения */
{
	switch (Check_State(13)) {

		case 0:    /*  P13S0() - СОСТОЯНИЕ: Начало */

    if (P0V44 < 40) {
         if (SendMsgGUICode(C_40)) {
					P0V37 = C_28;
					Set_State(13, 1);
					}
    } else if (P0V44 > 85) {
              if (SendMsgGUICode(C_41)) {
			   P0V37 = C_28;
			   Set_State(13, 2);
			   }
    } else {
                if (SendMsgGUICode(C_42)) {
					P0V37 = C_27;
				   Set_State(13, 3);
				}
         }
    if (Timeout(13, C_15))  Set_State(13, 5);
			break;
		case 1:    /*  P13S1() - СОСТОЯНИЕ: НизкаяТемператураВоды */

       
		if (P0V44 > (40.0 + C_33))  Set_State(13, 0);
			break;
		case 2:    /*  P13S2() - СОСТОЯНИЕ: ВысокаяТемператураВоды */

        if (P0V44 < (85.0 - C_33))  Set_State(13, 0);
			break;
		case 3:    /*  P13S3() - СОСТОЯНИЕ: ТемператураВнорме */

        if ((P0V44 < (40.0 - C_33)) && 
	         (P0V44 > (85.0 + C_33)))  Set_State(13, 0);
			break;
		case 4:    /*  P13S4() - СОСТОЯНИЕ: Задержка */

      if (Timeout(13, C_16))  Set_State(13, 0);
			break;
		case 5:    /*  P13S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(13, 0);
			break;
		default:
			break;
	}
}

void P14 (void) /* ПРОЦЕСС: КонтрольДавленияВбакеКомпрессора */
{
	switch (Check_State(14)) {

		case 0:    /*  P14S0() - СОСТОЯНИЕ: Начало */

   if (P0V42 > C_31) {
         if (SendMsgGUICode(C_47)) {
					P0V40 = C_27;
					Set_State(14, 1);
					}
    
    } else {
                if (SendMsgGUICode(C_48)) {
					P0V40 = C_28;
				   Set_State(14, 2);
				}
    }
    if (Timeout(14, C_15))  Set_State(14, 4);
			break;
		case 1:    /*  P14S1() - СОСТОЯНИЕ: ДавлениеНормальное */

       if (P0V42 < 9.5)  Set_State(14, 0);
			break;
		case 2:    /*  P14S2() - СОСТОЯНИЕ: ДавлениеНизкое */

       if (P0V42 < 10.5)  Set_State(14, 0);
			break;
		case 3:    /*  P14S3() - СОСТОЯНИЕ: Задержка */

      if (Timeout(14, C_16))  Set_State(14, 0);
			break;
		case 4:    /*  P14S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(14, 0);
			break;
		default:
			break;
	}
}

void P15 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_ВЕНТИЛЯТОР */
{
	switch (Check_State(15)) {

		case 0:    /*  P15S0() - СОСТОЯНИЕ: Начало */

  P0V29 = C_26;
  P0V11[1] = C_21;
  if ((!(Check_State(16) & MASK_OF_INACTIVITY))) Set_Error(16);
  else Set_State(15, 1);
			break;
		case 1:    /*  P15S1() - СОСТОЯНИЕ: КонтрольВключения */

  if (P0V5 == C_21) Set_Stop(15);
  if (Timeout(15, C_11))  Set_State(15, 2);
			break;
		case 2:    /*  P15S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_80))	Set_Error(15);
      if (Timeout(15, C_15))  Set_State(15, 3);
			break;
		case 3:    /*  P15S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(15);
			break;
		default:
			break;
	}
}

void P16 (void) /* ПРОЦЕСС: ВЫК_ПИТ_ВЕНТИЛЯТОР */
{
	switch (Check_State(16)) {

		case 0:    /*  P16S0() - СОСТОЯНИЕ: Начало */

  P0V29 = C_26;
  P0V11[1] = C_22;
  if ((!(Check_State(15) & MASK_OF_INACTIVITY))) Set_Error(15);
  else Set_State(16, 1);
			break;
		case 1:    /*  P16S1() - СОСТОЯНИЕ: КонтрольВыключения */

  if (P0V5 == C_22) Set_Stop(16);
  if (Timeout(16, C_11))  Set_State(16, 2);
			break;
		case 2:    /*  P16S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_81))	Set_Error(16);
      if (Timeout(16, C_15))  Set_State(16, 3);
			break;
		case 3:    /*  P16S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(16);
			break;
		default:
			break;
	}
}

void P17 (void) /* ПРОЦЕСС: ОТКР_ЗАТВОР_ВАК */
{
	switch (Check_State(17)) {

		case 0:    /*  P17S0() - СОСТОЯНИЕ: Начало */

  P0V25 = C_26;
  P0V19[1] = C_23;
  if ((!(Check_State(18) & MASK_OF_INACTIVITY))) Set_Error(18);
  if ((P0V0 == C_21) && (P0V1 = C_22)) Set_Stop(17);
  else Set_State(17, 1);
			break;
		case 1:    /*  P17S1() - СОСТОЯНИЕ: Контроль */
  
  if ((P0V0 == C_21) && (P0V1 = C_22)) Set_Stop(17);
  if (Timeout(17, C_7))  Set_State(17, 2);
			break;
		case 2:    /*  P17S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_76))	Set_Error(17);
      if (Timeout(17, C_15))  Set_State(17, 3);
			break;
		case 3:    /*  P17S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(17);
			break;
		default:
			break;
	}
}

void P18 (void) /* ПРОЦЕСС: ЗАКР_ЗАТВОР_ВАК */
{
	switch (Check_State(18)) {

		case 0:    /*  P18S0() - СОСТОЯНИЕ: Начало */

  P0V25 = C_26;
  P0V19[1] = C_24;
  if ((!(Check_State(17) & MASK_OF_INACTIVITY))) Set_Error(17);
  if ((P0V0 == C_22) && (P0V1 = C_21)) Set_Stop(18);
  else Set_State(18, 1);
			break;
		case 1:    /*  P18S1() - СОСТОЯНИЕ: Контроль */
  
	if ((P0V0 == C_22) && (P0V1 = C_21)) Set_Stop(18);
	if (Timeout(18, C_7))  Set_State(18, 2);
			break;
		case 2:    /*  P18S2() - СОСТОЯНИЕ: Ошибка */

    if (SendMsgGUICode(C_77))	Set_Error(18);
    if (Timeout(18, C_15))  Set_State(18, 3);
			break;
		case 3:    /*  P18S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(18);
			break;
		default:
			break;
	}
}

void P19 (void) /* ПРОЦЕСС: ОТКР_САПУН */
{
	switch (Check_State(19)) {

		case 0:    /*  P19S0() - СОСТОЯНИЕ: Начало */

  P0V26 = C_26;
  P0V20[1] = C_23;
  if ((!(Check_State(20) & MASK_OF_INACTIVITY))) Set_Error(20);

  if (P0V2 == C_23)  Set_Stop(19);
  else Set_State(19, 1);
			break;
		case 1:    /*  P19S1() - СОСТОЯНИЕ: КонтрольКонцевика */
  

    if (P0V2 == C_23) Set_Stop(19);
  if (Timeout(19, C_8))  Set_State(19, 2);
			break;
		case 2:    /*  P19S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_78))	Set_Error(19);
      if (Timeout(19, C_15))  Set_State(19, 3);
			break;
		case 3:    /*  P19S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(19);
			break;
		default:
			break;
	}
}

void P20 (void) /* ПРОЦЕСС: ЗАКР_САПУН */
{
	switch (Check_State(20)) {

		case 0:    /*  P20S0() - СОСТОЯНИЕ: Начало */

  P0V26 = C_26;
  P0V20[1] = C_24;
  if ((!(Check_State(19) & MASK_OF_INACTIVITY))) Set_Error(19);
  if (P0V2 == C_24) Set_Stop(20);
  else Set_State(20, 1);
			break;
		case 1:    /*  P20S1() - СОСТОЯНИЕ: КонтрольКонцевика */
  
  if (P0V2 == C_24) Set_Stop(20);
  if (Timeout(20, C_8))  {
  
	Set_State(20, 2);
  }
			break;
		case 2:    /*  P20S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_79))	Set_Error(20);
      if (Timeout(20, C_15))  Set_State(20, 3);
			break;
		case 3:    /*  P20S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(20);
			break;
		default:
			break;
	}
}

void P21 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_ВАК_НАСОСА */
{
	switch (Check_State(21)) {

		case 0:    /*  P21S0() - СОСТОЯНИЕ: Начало */

  P0V28 = C_26; 
  P0V17[1] = C_21;
  if ((!(Check_State(22) & MASK_OF_INACTIVITY))) Set_Error(22);
  if (P0V4 == C_21) Set_Stop(21);
  else Set_State(21, 1);
			break;
		case 1:    /*  P21S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V4 == C_21) Set_Stop(21);
  if (Timeout(21, C_10))  	Set_State(21, 2);
			break;
		case 2:    /*  P21S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_95))	Set_Error(21);
      if (Timeout(21, C_15))  Set_State(21, 3);
			break;
		case 3:    /*  P21S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(21);
			break;
		default:
			break;
	}
}

void P22 (void) /* ПРОЦЕСС: ВЫК_ПИТ_ВАК_НАСОСА */
{
	switch (Check_State(22)) {

		case 0:    /*  P22S0() - СОСТОЯНИЕ: Начало */

  P0V28 = C_26;
  P0V17[1] = C_22;
  if ((!(Check_State(21) & MASK_OF_INACTIVITY))) Set_Error(21);
  if (P0V4 == C_22) Set_Stop(22);
  else Set_State(22, 1);
			break;
		case 1:    /*  P22S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V4 == C_22) Set_Stop(22);
  if (Timeout(22, C_10))  	Set_State(22, 2);
			break;
		case 2:    /*  P22S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_96))	Set_Error(22);
      if (Timeout(22, C_15))  Set_State(22, 3);
			break;
		case 3:    /*  P22S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(22);
			break;
		default:
			break;
	}
}

void P23 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_РЕГ_Т */
{
	switch (Check_State(23)) {

		case 0:    /*  P23S0() - СОСТОЯНИЕ: Начало */

  P0V30 = C_26;
  P0V13[1] = C_21;
  if ((!(Check_State(24) & MASK_OF_INACTIVITY))) Set_Error(24);
  if (P0V6 == C_21) Set_Stop(23);
  else Set_State(23, 1);
			break;
		case 1:    /*  P23S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V6 == C_21) Set_Stop(23);
  if (Timeout(23, C_12))  	Set_State(23, 2);
			break;
		case 2:    /*  P23S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_84))	Set_Error(23);
      if (Timeout(23, C_15))  Set_State(23, 3);
			break;
		case 3:    /*  P23S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(23);
			break;
		default:
			break;
	}
}

void P24 (void) /* ПРОЦЕСС: ВЫК_ПИТ_РЕГ_Т */
{
	switch (Check_State(24)) {

		case 0:    /*  P24S0() - СОСТОЯНИЕ: Начало */

  P0V30 = C_26;
  P0V13[1] = C_22;
  if ((!(Check_State(23) & MASK_OF_INACTIVITY))) Set_Error(23);
  if (P0V6 == C_21) Set_Stop(24);
  else Set_State(24, 1);
			break;
		case 1:    /*  P24S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V6 == C_21) Set_Stop(24);
  if (Timeout(24, C_12))  Set_State(24, 2);
			break;
		case 2:    /*  P24S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_85))	Set_Error(24);
      if (Timeout(24, C_15))  Set_State(24, 3);
			break;
		case 3:    /*  P24S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(24);
			break;
		default:
			break;
	}
}

void P25 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_РЕГ_УР */
{
	switch (Check_State(25)) {

		case 0:    /*  P25S0() - СОСТОЯНИЕ: Начало */

  P0V31 = C_26;
  P0V23[1] = C_21;
  if ((!(Check_State(26) & MASK_OF_INACTIVITY))) Set_Error(26);
  if (P0V7 == C_21) Set_Stop(25);
  else Set_State(25, 1);
			break;
		case 1:    /*  P25S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V7 == C_21) Set_Stop(25);
  if (Timeout(25, C_13))  Set_State(25, 2);
			break;
		case 2:    /*  P25S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_86))	Set_Error(25);
      if (Timeout(25, C_15))  Set_State(25, 3);
			break;
		case 3:    /*  P25S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(25);
			break;
		default:
			break;
	}
}

void P26 (void) /* ПРОЦЕСС: ВЫК_ПИТ_РЕГ_УР */
{
	switch (Check_State(26)) {

		case 0:    /*  P26S0() - СОСТОЯНИЕ: Начало */

  P0V31 = C_26;
  P0V23[1] = C_22;
  if ((!(Check_State(25) & MASK_OF_INACTIVITY))) Set_Error(25);
  if (P0V7 == C_22) Set_Stop(26);
  else Set_State(26, 1);
			break;
		case 1:    /*  P26S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V7 == C_22) Set_Stop(26);
  if (Timeout(26, C_13))  	Set_State(26, 2);
			break;
		case 2:    /*  P26S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_87))	Set_Error(26);
      if (Timeout(26, C_15))  Set_State(26, 3);
			break;
		case 3:    /*  P26S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(26);
			break;
		default:
			break;
	}
}

void P27 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_НАС_ОХЛ */
{
	switch (Check_State(27)) {

		case 0:    /*  P27S0() - СОСТОЯНИЕ: Начало */

  if ((!(Check_State(28) & MASK_OF_INACTIVITY))) Set_Error(28);
  if (P0V35 == C_27)  Set_State(27, 1);
  else Set_Error(27);
			break;
		case 1:    /*  P27S1() - СОСТОЯНИЕ: ВключениеПитания */

  P0V32 = C_26;
  P0V15[1] = C_21;
  if (P0V10 == C_21) Set_Stop(27);
  else Set_State(27, 2);
			break;
		case 2:    /*  P27S2() - СОСТОЯНИЕ: Контроль */
  
  if (P0V10 == C_21) Set_Stop(27);
  if (Timeout(27, C_14))  Set_State(27, 3);
			break;
		case 3:    /*  P27S3() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_88))	Set_Error(27);
      if (Timeout(27, C_15))  Set_State(27, 4);
			break;
		case 4:    /*  P27S4() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(27);
			break;
		default:
			break;
	}
}

void P28 (void) /* ПРОЦЕСС: ВЫК_ПИТ_НАС_ОХЛ */
{
	switch (Check_State(28)) {

		case 0:    /*  P28S0() - СОСТОЯНИЕ: Начало */

  P0V32 = C_26;
  P0V15[1] = C_22;
  if ((!(Check_State(27) & MASK_OF_INACTIVITY))) Set_Error(27);
  if (P0V10 == C_22) Set_Stop(28);
  else Set_State(28, 1);
			break;
		case 1:    /*  P28S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V10 == C_22) Set_Stop(28);
  if (Timeout(28, C_14))  Set_State(28, 2);
			break;
		case 2:    /*  P28S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_89))	Set_Error(28);
      if (Timeout(28, C_15))  Set_State(28, 3);
			break;
		case 3:    /*  P28S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(28);
			break;
		default:
			break;
	}
}

void P29 (void) /* ПРОЦЕСС: ВКЛ_УСТР_ПЛАВ_ПУСКА */
{
	switch (Check_State(29)) {

		case 0:    /*  P29S0() - СОСТОЯНИЕ: Начало */

  P0V27 = C_26;
  P0V21[1] = C_21;
  if ((!(Check_State(30) & MASK_OF_INACTIVITY))) Set_Error(30);
  if (P0V3 == C_21) Set_Stop(29);
  else Set_State(29, 1);
			break;
		case 1:    /*  P29S1() - СОСТОЯНИЕ: Контроль */
  
  if (P0V3 == C_21) Set_Stop(29);
  if (Timeout(29, C_9))   	Set_State(29, 2);
			break;
		case 2:    /*  P29S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_82))	Set_Error(29);
      if (Timeout(29, C_15))  Set_State(29, 3);
			break;
		case 3:    /*  P29S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(29);
			break;
		default:
			break;
	}
}

void P30 (void) /* ПРОЦЕСС: ВЫК_УСТР_ПЛАВ_ПУСКА */
{
	switch (Check_State(30)) {

		case 0:    /*  P30S0() - СОСТОЯНИЕ: Начало */
					
  P0V27 = C_26;                 
  P0V21[1] = C_22;
  if ((!(Check_State(29) & MASK_OF_INACTIVITY))) Set_Error(29);
  if (P0V3 == C_22) Set_Stop(30);
  else Set_State(30, 1);
			break;
		case 1:    /*  P30S1() - СОСТОЯНИЕ: КонтрольВключения */
  
  if (P0V3 == C_22) Set_Stop(30);
  if (Timeout(30, C_9))  	Set_State(30, 2);
			break;
		case 2:    /*  P30S2() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_83))	Set_Error(30);
      if (Timeout(30, C_15))  Set_State(30, 3);
			break;
		case 3:    /*  P30S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(30);
			break;
		default:
			break;
	}
}

void P31 (void) /* ПРОЦЕСС: ВКЛ_НАСОС_ВАКУУМНЫЙ */
{
	switch (Check_State(31)) {

		case 0:    /*  P31S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(32) & MASK_OF_INACTIVITY))) Set_Error(32);
	
		if (P0V40 != C_27) Set_Error(31);
		else Set_State(31, 1);
			break;
		case 1:    /*  P31S1() - СОСТОЯНИЕ: КонтрольГотовностиУровняИтемпературы */

		if ((P0V45 > C_30)|| 
			(P0V35 == C_28)||
			(P0V36 == C_28 )) Set_Error(31);
			else 	{
				Set_Start(15);
				Set_State(31, 2);
			}
			break;
		case 2:    /*  P31S2() - СОСТОЯНИЕ: КонтрольВключенияВентилятора */

		if ( (Check_State(15) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(15) == STATE_OF_ERROR) ) Set_Error(31);
				else {
					Set_Start(27);
					Set_State(31, 3);
				}
		}
			break;
		case 3:    /*  P31S3() - СОСТОЯНИЕ: КонтрольВключенияПитанияНасосаОхлаждения */

		if ((Check_State(27) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(27) == STATE_OF_ERROR) ) Set_Error(31);
				else {
					Set_Start(18);
					Set_State(31, 4);
				}
		}
			break;
		case 4:    /*  P31S4() - СОСТОЯНИЕ: КонтрольЗакрытияЗатвораВакуумного */

		if ((Check_State(18) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(18) == STATE_OF_ERROR) ) Set_Error(31);
			else {
				Set_Start(19);
				Set_State(31, 5);
			}
		}
			break;
		case 5:    /*  P31S5() - СОСТОЯНИЕ: КонтрольОткрытияСапуна */

		if ( (Check_State(19) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(19) == STATE_OF_ERROR) ) Set_Error(31);
			else Set_State(31, 6);
		}
			break;
		case 6:    /*  P31S6() - СОСТОЯНИЕ: КонтрольТемпературыРубашки */

		if (P0V37 == C_27) Set_State(31, 7);

		else Set_Error(31);
			break;
		case 7:    /*  P31S7() - СОСТОЯНИЕ: ПодачаПитанияНаВакуумныйНасос */

		Set_Start(21);
		Set_State(31, 8);
			break;
		case 8:    /*  P31S8() - СОСТОЯНИЕ: КонтрольПитанияВакуумногоНасоса */

		if ( (Check_State(21) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(21) == STATE_OF_ERROR)) Set_Error(31);
			else  Set_State(31, 9);
		}
			break;
		case 9:    /*  P31S9() - СОСТОЯНИЕ: ВключениеУстройстваПлавногоПуска */

		Set_Start(29);
		Set_State(31, 10);
			break;
		case 10:    /*  P31S10() - СОСТОЯНИЕ: КонтрольВлюченияПлавногоПуска */

		if ((Check_State(29) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(29) == STATE_OF_ERROR)) Set_Error(31);
			else  Set_State(31, 11);
		}
			break;
		case 11:    /*  P31S11() - СОСТОЯНИЕ: ТаймаутПередЗакрытиемСапуна */
  
		if (Timeout(31, C_16))  Set_State(31, 12);
			break;
		case 12:    /*  P31S12() - СОСТОЯНИЕ: ЗакрытиеСапуна */
  
		Set_Start(20);
		Set_State(31, 13);
			break;
		case 13:    /*  P31S13() - СОСТОЯНИЕ: КонтрольЗакрытияСапуна */

		if ( (Check_State(20) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(20) == STATE_OF_ERROR) ) Set_Error(31);
			else Set_State(31, 14);
		}
			break;
		case 14:    /*  P31S14() - СОСТОЯНИЕ: ЗапоминаемДавлениеВпатрубке */

			P31V9 = P0V43;
			Set_State(31, 15);
			break;
		case 15:    /*  P31S15() - СОСТОЯНИЕ: КонтрольДавления */
  
		if (P0V47 >= P0V43) {
			Set_Start(17); 
			Set_State(31, 18);
			}
		else Set_State(31, 16);
			break;
		case 16:    /*  P31S16() - СОСТОЯНИЕ: ПаузаНаОткачкуВпатрубке */
  
		if (Timeout(31, C_17))  Set_State(31, 17);
			break;
		case 17:    /*  P31S17() - СОСТОЯНИЕ: ПроверкаУменьшенияДавленияВпатрубке */
  
		if(P0V43 < P31V9) Set_State(31, 14);
        else Set_State(31, 19);
			break;
		case 18:    /*  P31S18() - СОСТОЯНИЕ: КонтрольОткрытияЗВ */

		if ( (Check_State(17) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(17) == STATE_OF_ERROR) ) Set_Error(31);
			else  Set_Stop(31);
		}
			break;
		case 19:    /*  P31S19() - СОСТОЯНИЕ: Ошибка */

       if (SendMsgGUICode(C_94))	Set_Error(31);
      if (Timeout(31, C_15))  Set_State(31, 20);
			break;
		case 20:    /*  P31S20() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(31);
			break;
		default:
			break;
	}
}

void P32 (void) /* ПРОЦЕСС: ВЫК_НАСОС_ВАКУУМНЫЙ */
{
	switch (Check_State(32)) {

		case 0:    /*  P32S0() - СОСТОЯНИЕ: Начало */

 		Set_Start(18);
		Set_State(32, 1);
			break;
		case 1:    /*  P32S1() - СОСТОЯНИЕ: КонтрольЗакрытияЗатвораВакуумного */

		if ((Check_State(18) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(18) == STATE_OF_ERROR) ) Set_Error(32);
			else {
			Set_Stop(9);
				Set_Start(19);
				Set_State(32, 2);
			}
		}
			break;
		case 2:    /*  P32S2() - СОСТОЯНИЕ: КонтрольОткрытияСапуна */

		if ( (Check_State(19) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(19) == STATE_OF_ERROR) ) Set_Error(32);
			else {
				
				Set_State(32, 3);
			}
		}
			break;
		case 3:    /*  P32S3() - СОСТОЯНИЕ: ТаймаутПередВыключениемПитанияВакуумногоНасоса */
  
		if (Timeout(32, C_6))  Set_State(32, 4);
			break;
		case 4:    /*  P32S4() - СОСТОЯНИЕ: ВыключаемУППВакуумногоНасоса */
  
		Set_Start(30); Set_State(32, 5);
			break;
		case 5:    /*  P32S5() - СОСТОЯНИЕ: КонтрольВыключенияПитанияУППВакуумногоНасоса */

		if ( (Check_State(30) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(30) == STATE_OF_ERROR)) Set_Error(32);
			else {
				Set_Start(22);
				Set_State(32, 6);
			}
		}
			break;
		case 6:    /*  P32S6() - СОСТОЯНИЕ: КонтрольВыключенияПитанияВакуумногоНасоса */

		if ( (Check_State(22) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(22) == STATE_OF_ERROR)) Set_Error(32);
			else {
				Set_Start(28);
				Set_State(32, 7);
			}
		}
			break;
		case 7:    /*  P32S7() - СОСТОЯНИЕ: КонтрольВыключенияНасосаОхлаждения */

		if ( (Check_State(28) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(28) == STATE_OF_ERROR) ) Set_Error(32);
				else {
					Set_Start(16);
					Set_State(32, 8);
				}
		}
			break;
		case 8:    /*  P32S8() - СОСТОЯНИЕ: КонтрольВыключенияВентилятора */

		if ( (Check_State(16) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(16) == STATE_OF_ERROR) ) Set_Error(32);
				else Set_Stop(32);
		}
			break;
		default:
			break;
	}
}

void P33 (void) /* ПРОЦЕСС: ВКЛ_ВАКУУМИРОВАНИЕ_ТРУБЫ */
{
	switch (Check_State(33)) {

		case 0:    /*  P33S0() - СОСТОЯНИЕ: Начало */

   if (P0V38 == C_27) Set_Stop(33);
   else {  
	Set_Start(31);
	Set_State(33, 1);
	}
			break;
		case 1:    /*  P33S1() - СОСТОЯНИЕ: КонтрольВключенияНасоса */

		if ( (Check_State(31) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(31) == STATE_OF_ERROR) ) {
				Set_Start(32); 
				Set_Error(33);
			}
			else {
				Set_Start(9);	
				Set_State(33, 2);
			}
		}
			break;
		case 2:    /*  P33S2() - СОСТОЯНИЕ: ЗапоминаемДавлениеВвакуумнойТрубе */

			P33V6 = P0V47;
			Set_State(33, 3);
			break;
		case 3:    /*  P33S3() - СОСТОЯНИЕ: КонтрольОборудования */

			if ( (P0V44 <= 85) && (P0V5) && (P0V10) ) Set_State(33, 4);
			else {
				Set_Start(32);
			Set_Error(33);
			}
			break;
		case 4:    /*  P33S4() - СОСТОЯНИЕ: КонтрольДавления */
  
		if (P0V47 <= 0.02) {
			Set_Start(32); 
			Set_Stop(33);
			}
		else Set_State(33, 5);
			break;
		case 5:    /*  P33S5() - СОСТОЯНИЕ: ПаузаНаОткачкуВвакуумнойТрубе */
  
		if (Timeout(33, C_17))  Set_State(33, 6);
			break;
		case 6:    /*  P33S6() - СОСТОЯНИЕ: ПроверкаУменьшенияДавленияВпатрубке */
  
		if(P0V47 < P33V6) Set_State(33, 2);
        else Set_Error(33);
			break;
		default:
			break;
	}
}

void P34 (void) /* ПРОЦЕСС: ВЫК_ВАКУУМИРОВАНИЕ_ТРУБЫ */
{
	switch (Check_State(34)) {

		case 0:    /*  P34S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(33) & MASK_OF_INACTIVITY))) Set_Stop(33); 
	Set_Start(32);
	Set_Stop(34);
			break;
		default:
			break;
	}
}
