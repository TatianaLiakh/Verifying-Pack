/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "bsvtext.inc" /* Common files for all generated c-files */
#include "bsvtxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
 		
	P0V44 = C_34;
	P0V45 = C_34;
	P0V46 = C_34;
	P0V47 = C_34;
	P0V48 = C_34;
	P0V49 = C_34;
			
	P0V82 = C_38;		

	
		
	
		
	Set_Start(8);
	Set_Start(9);
	Set_Start(10);
	Set_Start(11);
	Set_Start(12);
	Set_Start(13);
	Set_Start(14);
	Set_Start(15);
	Set_Start(16);
	Set_Start(17);
	Set_Start(18);
	Set_Start(7);   
	Set_Start(2);
	Set_Start(3);
	Set_Start(4);
	Set_Start(5);
	Set_Start(6);
	Set_State(0, 1);
			break;
		case 1:    /*  P0S1() - СОСТОЯНИЕ: КонтрольИдетЛиВакуумированиеВакуумирования */

		if (((Check_State(94) & MASK_OF_INACTIVITY)) &&
			((Check_State(96) & MASK_OF_INACTIVITY))) {
				if (SendMsgGUICode(C_191)) Set_State(0, 2);
		}
		if (Timeout(0, C_17))  Set_State(0, 6);
			break;
		case 2:    /*  P0S2() - СОСТОЯНИЕ: ВыборРаботыСдостоверностями */


	if (P0V82 == C_37) Set_State(0, 3);
	else Set_State(0, 4);
			break;
		case 3:    /*  P0S3() - СОСТОЯНИЕ: НеПроверяемДостоверностьКонтроля */
  
	
	if (P0V4) 				P0V39[1] = C_25;
	if (P0V6) 	P0V40[1] = C_25;
	if (P0V8) 	P0V37[1] = C_25;   
	if (P0V10) 	P0V34[1] = C_25;
	if (P0V12) 			P0V35[1] = C_25;
	if (P0V14) 		P0V41[1] = C_25;
	if (P0V20) 		P0V36[1] = C_25;	
	if  ((P0V0) && (!P0V2)) 	P0V38[1] = C_27; 
	if ((!P0V0) && (P0V2)) 		P0V38[1] = C_28;
	
	Set_State(0, 7);
			break;
		case 4:    /*  P0S4() - СОСТОЯНИЕ: ПроверяемДостоверностьКонтроля */
   
										
							
										
	if ( 	
			(P0V25) &&		
			(P0V27) &&
			(P0V29) &&
			(P0V31) &&
			(P0V33) &&
			
			(P0V1) &&				
			(P0V3) &&
			(P0V5) &&
			(P0V7) &&
			(P0V9) &&     
			(P0V11) &&
			(P0V13) &&
			(P0V15) &&
			(P0V17) &&
			(P0V19) &&
			(P0V21) && 
			(P0V23)  
			) {
				if (P0V4) 				P0V39[1] = C_25;
				if (P0V6)	P0V40[1] = C_25;
				if (P0V8)  	P0V37[1] = C_25;   
				if (P0V10)  	P0V34[1] = C_25;
				if (P0V12)			P0V35[1] = C_25;
				if (P0V14) 		P0V41[1] = C_25;
				if (P0V20)   	P0V36[1] = C_25;
				if  ((P0V0) && (!P0V2)) P0V38[1] = C_27; 
				if ((!P0V0) && (P0V2)) 	P0V38[1] = C_28; 
				Set_State(0, 7);
	}
	if (Timeout(0, C_6))  Set_State(0, 5);
			break;
		case 5:    /*  P0S5() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

		if (SendMsgGUICode(C_111)) Set_State(0, 2);
		if (Timeout(0, C_17))  Set_State(0, 6);
			break;
		case 6:    /*  P0S6() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_State(0, 2);
			break;
		case 7:    /*  P0S7() - СОСТОЯНИЕ: НачалоРаботы */
	

    P0V83 = 1; 
	                                   



	P0V89 = 4;   
	P0V90            = 0.05; 
	P0V91 =  0.05; 	
	P0V92  	= 		15.0;		
	P0V93  = 	70.0;		
	P0V94 =  	10.0;
	P0V95 =  	60.0;

	P0V96  = 2.0;         
	P0V97 = 15.0;      	
	
	P0V98 = 2;  				
	P0V99 = 2;  			
	P0V100 = 0.5;	
	P0V101 = 0.005;	
	P0V102 = 0.0025;	
	
	Set_Start(35);	
    Set_Start(34);
	
	
	
	
	
	Set_Start(19);			
	Set_Start(21);					
	Set_Start(22);  	
	Set_Start(23);		
	Set_Start(24);			
   	Set_Start(25); 		
	Set_Start(26); 	
	Set_Start(27);	
	Set_Start(28);  
	Set_Start(29);  
	Set_Start(30);  
	Set_Start(31);  
	Set_Start(32);  
	Set_Start(33);  		
		
	
	Set_Start(38);
	Set_Start(39);
	Set_Start(40);
	Set_Start(41);
	Set_Start(42);
	
	Set_Start(47);
	Set_Start(48);    
	Set_Start(49);	
	Set_Start(50);
	Set_Start(51);
	Set_Start(45);  
	Set_Start(46);
	
	
		
	
	Set_Start(56); 
	Set_Start(66);
	Set_Start(71);
	Set_Start(76);
	Set_Start(81);
	Set_Start(86);
	Set_Start(91);
	Set_Start(52); 
	Set_Start(59);
		
	Set_Start(44);
	
	Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* ПРОЦЕСС: ОстановВсехПроцессовИстартПроцИнициализация */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - СОСТОЯНИЕ: Начало */


		Set_Stop(36);
		Set_Stop(37); 
		
		Set_Stop(19);
		Set_Stop(21);
		Set_Stop(22);  
		Set_Stop(23);
		Set_Stop(24);
	
		Set_Stop(25); 
		Set_Stop(26); 
		Set_Stop(27);	
		Set_Stop(28);  
		Set_Stop(29);  
		Set_Stop(30);  	
		Set_Stop(31);  	
		Set_Stop(32);  
		Set_Stop(33);  			
		
	
		

		
		Set_Stop(38); 
		Set_Stop(39); 
		Set_Stop(40);	
		Set_Stop(41);	
		Set_Stop(42); 

		Set_Stop(43);
		Set_Stop(44);
		Set_Stop(45);  
		Set_Stop(46); 
		Set_Stop(47);
		Set_Stop(48);
		
		Set_Stop(49);
		Set_Stop(50);
		Set_Stop(51);
		
		Set_Stop(54);
		Set_Stop(55);
		Set_Stop(56); 
		Set_Stop(57);
		Set_Stop(58);
		Set_Stop(60);
		Set_Stop(61);
		Set_Stop(59);  
		Set_Stop(62);
		Set_Stop(63);
		Set_Stop(64);
		Set_Stop(65);
		Set_Stop(67);
		Set_Stop(68);
		Set_Stop(69);  
		Set_Stop(70);  
		Set_Stop(72);  
		Set_Stop(73);	

		Set_Stop(77);
		Set_Stop(78);

		Set_Stop(82);
		Set_Stop(83);
		Set_Stop(84);
		Set_Stop(85);
		Set_Stop(87);
		Set_Stop(88);
		Set_Stop(89);
		Set_Stop(90);
		Set_Stop(92);
		Set_Stop(93);
		Set_Stop(96);
		
		Set_Stop(53);
		Set_Stop(97); 
		Set_Stop(94);
		Set_Stop(95);  
		Set_Stop(52);

		

		Set_Start(0);
		Set_Stop(1);
			break;
		default:
			break;
	}
}

void P2 (void) /* ПРОЦЕСС: КонтрольДостоверностиДавленияВбакеКомпрессора */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - СОСТОЯНИЕ: Начало */

      if (P0V25 == C_35) Set_State(2, 1);
      else Set_State(2, 3);
			break;
		case 1:    /*  P2S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_180)) Set_State(2, 2);
     if (Timeout(2, C_17))  Set_State(2, 5);
			break;
		case 2:    /*  P2S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V25 == C_36) Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_181)) Set_State(2, 4);
     if (Timeout(2, C_17))  Set_State(2, 5);
			break;
		case 4:    /*  P2S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V25 == C_35) Set_State(2, 1);
			break;
		case 5:    /*  P2S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(2, 0);
			break;
		default:
			break;
	}
}

void P3 (void) /* ПРОЦЕСС: КонтрольДостоверностиДавленияВпатрубке */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - СОСТОЯНИЕ: Начало */

      if (P0V27 == C_35) Set_State(3, 1);
      else Set_State(3, 3);
			break;
		case 1:    /*  P3S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_182)) Set_State(3, 2);
     if (Timeout(3, C_17))  Set_State(3, 5);
			break;
		case 2:    /*  P3S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V27 == C_36) Set_State(3, 3);
			break;
		case 3:    /*  P3S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_183)) Set_State(3, 4);
     if (Timeout(3, C_17))  Set_State(3, 5);
			break;
		case 4:    /*  P3S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V27 == C_35) Set_State(3, 1);
			break;
		case 5:    /*  P3S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(3, 0);
			break;
		default:
			break;
	}
}

void P4 (void) /* ПРОЦЕСС: КонтрольДостоверностиТемпературыВрубашкеОхлаждения */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - СОСТОЯНИЕ: Начало */

      if (P0V29 == C_35) Set_State(4, 1);
      else Set_State(4, 3);
			break;
		case 1:    /*  P4S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_184)) Set_State(4, 2);
     if (Timeout(4, C_17))  Set_State(4, 5);
			break;
		case 2:    /*  P4S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V29 == C_36) Set_State(4, 3);
			break;
		case 3:    /*  P4S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_185)) Set_State(4, 4);
     if (Timeout(4, C_17))  Set_State(4, 5);
			break;
		case 4:    /*  P4S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V29 == C_35) Set_State(4, 1);
			break;
		case 5:    /*  P4S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(4, 0);
			break;
		default:
			break;
	}
}

void P5 (void) /* ПРОЦЕСС: КонтрольДостоверностиТемпературыВбакеОхлаждения */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - СОСТОЯНИЕ: Начало */

      if (P0V31 == C_35) Set_State(5, 1);
      else Set_State(5, 3);
			break;
		case 1:    /*  P5S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_186)) Set_State(5, 2);
     if (Timeout(5, C_17))  Set_State(5, 5);
			break;
		case 2:    /*  P5S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V31 == C_36) Set_State(5, 3);
			break;
		case 3:    /*  P5S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_187)) Set_State(5, 4);
     if (Timeout(5, C_17))  Set_State(5, 5);
			break;
		case 4:    /*  P5S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V31 == C_35) Set_State(5, 1);
			break;
		case 5:    /*  P5S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(5, 0);
			break;
		default:
			break;
	}
}

void P6 (void) /* ПРОЦЕСС: КонтрольДостоверностиДавленияВтрубеСидеростата */
{
	switch (Check_State(6)) {

		case 0:    /*  P6S0() - СОСТОЯНИЕ: Начало */

      if (P0V33 == C_35) Set_State(6, 1);
      else Set_State(6, 3);
			break;
		case 1:    /*  P6S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_188)) Set_State(6, 2);
     if (Timeout(6, C_17))  Set_State(6, 5);
			break;
		case 2:    /*  P6S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V33 == C_36) Set_State(6, 3);
			break;
		case 3:    /*  P6S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_189)) Set_State(6, 4);
     if (Timeout(6, C_17))  Set_State(6, 5);
			break;
		case 4:    /*  P6S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V33 == C_35) Set_State(6, 1);
			break;
		case 5:    /*  P6S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(6, 0);
			break;
		default:
			break;
	}
}

void P7 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияШКАФА_ВС */
{
	switch (Check_State(7)) {

		case 0:    /*  P7S0() - СОСТОЯНИЕ: Начало */

      if (P0V23 == C_35) Set_State(7, 1);
      else Set_State(7, 3);
			break;
		case 1:    /*  P7S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_178)) Set_State(7, 2);
     if (Timeout(7, C_17))  Set_State(7, 5);
			break;
		case 2:    /*  P7S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V23 == C_36) Set_State(7, 3);
			break;
		case 3:    /*  P7S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_179)) Set_State(7, 4);
     if (Timeout(7, C_17))  Set_State(7, 5);
			break;
		case 4:    /*  P7S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V23 == C_35) Set_State(7, 1);
			break;
		case 5:    /*  P7S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(7, 0);
			break;
		default:
			break;
	}
}

void P8 (void) /* ПРОЦЕСС: КонтрольДостоверностиОткрЗатВакуумного */
{
	switch (Check_State(8)) {

		case 0:    /*  P8S0() - СОСТОЯНИЕ: Начало */

      if (P0V1 == C_35) Set_State(8, 1);
      else Set_State(8, 3);
			break;
		case 1:    /*  P8S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_156)) Set_State(8, 2);
     if (Timeout(8, C_17))  Set_State(8, 5);
			break;
		case 2:    /*  P8S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V1 == C_36) Set_State(8, 3);
			break;
		case 3:    /*  P8S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_157)) Set_State(8, 4);
     if (Timeout(8, C_17))  Set_State(8, 5);
			break;
		case 4:    /*  P8S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V1 == C_35) Set_State(8, 1);
			break;
		case 5:    /*  P8S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(8, 0);
			break;
		default:
			break;
	}
}

void P9 (void) /* ПРОЦЕСС: КонтрольДостоверностиЗакрЗатВакуумного */
{
	switch (Check_State(9)) {

		case 0:    /*  P9S0() - СОСТОЯНИЕ: Начало */

      if (P0V3 == C_35) Set_State(9, 1);
      else Set_State(9, 3);
			break;
		case 1:    /*  P9S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_158)) Set_State(9, 2);
     if (Timeout(9, C_17))  Set_State(9, 5);
			break;
		case 2:    /*  P9S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V3 == C_36) Set_State(9, 3);
			break;
		case 3:    /*  P9S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_159)) Set_State(9, 4);
     if (Timeout(9, C_17))  Set_State(9, 5);
			break;
		case 4:    /*  P9S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V3 == C_35) Set_State(9, 1);
			break;
		case 5:    /*  P9S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(9, 0);
			break;
		default:
			break;
	}
}

void P10 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияСапуна */
{
	switch (Check_State(10)) {

		case 0:    /*  P10S0() - СОСТОЯНИЕ: Начало */

      if (P0V5 == C_35) Set_State(10, 1);
      else Set_State(10, 3);
			break;
		case 1:    /*  P10S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_160)) Set_State(10, 2);
     if (Timeout(10, C_17))  Set_State(10, 5);
			break;
		case 2:    /*  P10S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V5 == C_36) Set_State(10, 3);
			break;
		case 3:    /*  P10S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_161)) Set_State(10, 4);
     if (Timeout(10, C_17))  Set_State(10, 5);
			break;
		case 4:    /*  P10S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V5 == C_35) Set_State(10, 1);
			break;
		case 5:    /*  P10S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(10, 0);
			break;
		default:
			break;
	}
}

void P11 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияУстройстваПлавПуска */
{
	switch (Check_State(11)) {

		case 0:    /*  P11S0() - СОСТОЯНИЕ: Начало */

      if (P0V7 == C_35) Set_State(11, 1);
      else Set_State(11, 3);
			break;
		case 1:    /*  P11S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_162)) Set_State(11, 2);
     if (Timeout(11, C_17))  Set_State(11, 5);
			break;
		case 2:    /*  P11S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V7 == C_36) Set_State(11, 3);
			break;
		case 3:    /*  P11S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_163)) Set_State(11, 4);
     if (Timeout(11, C_17))  Set_State(11, 5);
			break;
		case 4:    /*  P11S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V7 == C_35) Set_State(11, 1);
			break;
		case 5:    /*  P11S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(11, 0);
			break;
		default:
			break;
	}
}

void P12 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостПитанияУППВакНасоса */
{
	switch (Check_State(12)) {

		case 0:    /*  P12S0() - СОСТОЯНИЕ: Начало */

      if (P0V9 == C_35) Set_State(12, 1);   
      else Set_State(12, 3);
			break;
		case 1:    /*  P12S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_164)) Set_State(12, 2);  
     if (Timeout(12, C_17))  Set_State(12, 5);
			break;
		case 2:    /*  P12S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V9 == C_36) Set_State(12, 3);
			break;
		case 3:    /*  P12S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_165)) Set_State(12, 4);   
     if (Timeout(12, C_17))  Set_State(12, 5);
			break;
		case 4:    /*  P12S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V9 == C_35) Set_State(12, 1);
			break;
		case 5:    /*  P12S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(12, 0);
			break;
		default:
			break;
	}
}

void P13 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияВентилятора */
{
	switch (Check_State(13)) {

		case 0:    /*  P13S0() - СОСТОЯНИЕ: Начало */

      if (P0V11 == C_35) Set_State(13, 1);
      else Set_State(13, 3);
			break;
		case 1:    /*  P13S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_166)) Set_State(13, 2);
     if (Timeout(13, C_17))  Set_State(13, 5);
			break;
		case 2:    /*  P13S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V11 == C_36) Set_State(13, 3);
			break;
		case 3:    /*  P13S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_167)) Set_State(13, 4);
     if (Timeout(13, C_17))  Set_State(13, 5);
			break;
		case 4:    /*  P13S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V11 == C_35) Set_State(13, 1);
			break;
		case 5:    /*  P13S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(13, 0);
			break;
		default:
			break;
	}
}

void P14 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияРегТемпературы */
{
	switch (Check_State(14)) {

		case 0:    /*  P14S0() - СОСТОЯНИЕ: Начало */

      if (P0V13 == C_35) Set_State(14, 1);
      else Set_State(14, 3);
			break;
		case 1:    /*  P14S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_168)) Set_State(14, 2);
     if (Timeout(14, C_17))  Set_State(14, 5);
			break;
		case 2:    /*  P14S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V13 == C_36) Set_State(14, 3);
			break;
		case 3:    /*  P14S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_169)) Set_State(14, 4);
     if (Timeout(14, C_17))  Set_State(14, 5);
			break;
		case 4:    /*  P14S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V13 == C_35) Set_State(14, 1);
			break;
		case 5:    /*  P14S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(14, 0);
			break;
		default:
			break;
	}
}

void P15 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияРегУровня */
{
	switch (Check_State(15)) {

		case 0:    /*  P15S0() - СОСТОЯНИЕ: Начало */

      if (P0V15 == C_35) Set_State(15, 1);
      else Set_State(15, 3);
			break;
		case 1:    /*  P15S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_170)) Set_State(15, 2);
     if (Timeout(15, C_17))  Set_State(15, 5);
			break;
		case 2:    /*  P15S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V15 == C_36) Set_State(15, 3);
			break;
		case 3:    /*  P15S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_171)) Set_State(15, 4);
     if (Timeout(15, C_17))  Set_State(15, 5);
			break;
		case 4:    /*  P15S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V15 == C_35) Set_State(15, 1);
			break;
		case 5:    /*  P15S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(15, 0);
			break;
		default:
			break;
	}
}

void P16 (void) /* ПРОЦЕСС: КонтрольДостоверностиУровняВодыМинимум */
{
	switch (Check_State(16)) {

		case 0:    /*  P16S0() - СОСТОЯНИЕ: Начало */

      if (P0V17 == C_35) Set_State(16, 1);
      else Set_State(16, 3);
			break;
		case 1:    /*  P16S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_172)) Set_State(16, 2);
     if (Timeout(16, C_17))  Set_State(16, 5);
			break;
		case 2:    /*  P16S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V17 == C_36) Set_State(16, 3);
			break;
		case 3:    /*  P16S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_173)) Set_State(16, 4);
     if (Timeout(16, C_17))  Set_State(16, 5);
			break;
		case 4:    /*  P16S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V17 == C_35) Set_State(16, 1);
			break;
		case 5:    /*  P16S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(16, 0);
			break;
		default:
			break;
	}
}

void P17 (void) /* ПРОЦЕСС: КонтрольДостоверностиУровняВодыМаксимум */
{
	switch (Check_State(17)) {

		case 0:    /*  P17S0() - СОСТОЯНИЕ: Начало */

      if (P0V19 == C_35) Set_State(17, 1);
      else Set_State(17, 3);
			break;
		case 1:    /*  P17S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_174)) Set_State(17, 2);
     if (Timeout(17, C_17))  Set_State(17, 5);
			break;
		case 2:    /*  P17S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V19 == C_36) Set_State(17, 3);
			break;
		case 3:    /*  P17S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_175)) Set_State(17, 4);
     if (Timeout(17, C_17))  Set_State(17, 5);
			break;
		case 4:    /*  P17S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V19 == C_35) Set_State(17, 1);
			break;
		case 5:    /*  P17S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(17, 0);
			break;
		default:
			break;
	}
}

void P18 (void) /* ПРОЦЕСС: КонтрольДостоверностиСостоянияПитанияНасОхлаждения */
{
	switch (Check_State(18)) {

		case 0:    /*  P18S0() - СОСТОЯНИЕ: Начало */

      if (P0V21 == C_35) Set_State(18, 1);
      else Set_State(18, 3);
			break;
		case 1:    /*  P18S1() - СОСТОЯНИЕ: СообК_ГУИ_ЕСТЬ_ДОСТОВЕРНОСТЬ */

     if (SendMsgGUICode(C_176)) Set_State(18, 2);
     if (Timeout(18, C_17))  Set_State(18, 5);
			break;
		case 2:    /*  P18S2() - СОСТОЯНИЕ: ОжиданиеНедостоверности */

      if (P0V21 == C_36) Set_State(18, 3);
			break;
		case 3:    /*  P18S3() - СОСТОЯНИЕ: СообК_ГУИ_НЕТ_ДОСТОВЕРНОСТИ */

     if (SendMsgGUICode(C_177)) Set_State(18, 4);
     if (Timeout(18, C_17))  Set_State(18, 5);
			break;
		case 4:    /*  P18S4() - СОСТОЯНИЕ: ОжиданиеЕстьДостоверность */

      if (P0V21 == C_35) Set_State(18, 1);
			break;
		case 5:    /*  P18S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(18, 0);
			break;
		default:
			break;
	}
}

void P19 (void) /* ПРОЦЕСС: ЧтениеДавленияВбакеКомпрессора */
{
	switch (Check_State(19)) {

		case 0:    /*  P19S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V25 = C_25;   
	if (P0V25) {
		P0V68 = C_29;  
		P0V84 	= GetFP_P_BAK_COMPRESSOR();
		Set_State(19, 0);
	}
	if (Timeout(19, C_6))  Set_State(19, 1);
			break;
		case 1:    /*  P19S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V68 = C_30;
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(19, 0);
		else 	Set_Start(95); Set_State(19, 2);
			break;
		case 2:    /*  P19S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(19);  
				}
				else  Set_State(19, 0);  
		}
			break;
		case 3:    /*  P19S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(19);
			break;
		default:
			break;
	}
}

void P20 (void) /* ПРОЦЕСС: ОтлючитьВакуумированиеВручную */
{
	switch (Check_State(20)) {

		case 0:    /*  P20S0() - СОСТОЯНИЕ: ПереходВручноеОтключение */

		if (SendMsgGUICode(C_113))Set_State(20, 1);
		if (Timeout(20, C_17))  Set_State(20, 2);
			break;
		case 1:    /*  P20S1() - СОСТОЯНИЕ: ОстановПроцессов */

		if (!((!(Check_State(1) & MASK_OF_INACTIVITY))))
			Set_Start(1);   
		Set_Stop(20);
			break;
		case 2:    /*  P20S2() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(20);
			break;
		default:
			break;
	}
}

void P21 (void) /* ПРОЦЕСС: ЧтениеДавленияВпатрубке */
{
	switch (Check_State(21)) {

		case 0:    /*  P21S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V27 = C_25;   
	if (P0V27) {
		P0V69 = C_29;    
		P0V85 		= GetFP_P_PATRUBKA();
		Set_State(21, 0);
	}
	if (Timeout(21, C_6))  Set_State(21, 1);
			break;
		case 1:    /*  P21S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V69 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(21, 0);
		else 	Set_Start(95); Set_State(21, 2);
			break;
		case 2:    /*  P21S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(21);  
				}
				else  Set_State(21, 0);  
		}
			break;
		case 3:    /*  P21S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(21);
			break;
		default:
			break;
	}
}

void P22 (void) /* ПРОЦЕСС: ЧтениеТемпературыВрубашкеОхлаждения */
{
	switch (Check_State(22)) {

		case 0:    /*  P22S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V29 = C_25;   
	if (P0V29) {
		P0V70 = C_29;   
		P0V86 		= GetFP_T_RUBACHKA();
		Set_State(22, 0);
	}
	if (Timeout(22, C_6))  Set_State(22, 1);
			break;
		case 1:    /*  P22S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V70 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(22, 0);
		else 	Set_Start(95); Set_State(22, 2);
			break;
		case 2:    /*  P22S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(22);  
				}
				else  Set_State(22, 0);  
		}
			break;
		case 3:    /*  P22S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(22);
			break;
		default:
			break;
	}
}

void P23 (void) /* ПРОЦЕСС: ЧтениеТемпературыВбакеОхлаждения */
{
	switch (Check_State(23)) {

		case 0:    /*  P23S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V31 = C_25;   
	if (P0V31) {
		P0V71 = C_29;	
		P0V87 			= GetFP_T_BAK();
		Set_State(23, 0);
	}
	if (Timeout(23, C_6))  Set_State(23, 1);
			break;
		case 1:    /*  P23S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V71 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(23, 0);
		else 	Set_Start(95); Set_State(23, 2);
			break;
		case 2:    /*  P23S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(23);  
				}
				else  Set_State(23, 0);  
		}
			break;
		case 3:    /*  P23S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(23);
			break;
		default:
			break;
	}
}

void P24 (void) /* ПРОЦЕСС: ЧтениеДавленияВтрубеСидеростата */
{
	switch (Check_State(24)) {

		case 0:    /*  P24S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V33 = C_25;   
	if (P0V33) {
		P0V72 = C_29;
		P0V88 	= GetFP_P_TRUBA();
		Set_State(24, 0);
	}
	if (Timeout(24, C_6))  Set_State(24, 1);
			break;
		case 1:    /*  P24S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V72 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(24, 0);
		else Set_Start(95); Set_State(24, 2);
			break;
		case 2:    /*  P24S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(24);  
				}
				else  Set_State(24, 0);  
		}
			break;
		case 3:    /*  P24S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(24);
			break;
		default:
			break;
	}
}

void P25 (void) /* ПРОЦЕСС: ПроверкаСвязиС_РегуляторомУровня */
{
	switch (Check_State(25)) {

		case 0:    /*  P25S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V15;   
	if (P0V15) {
		P0V73 = C_29;		
		Set_State(25, 0);
	}
	if (Timeout(25, C_6))  Set_State(25, 1);
			break;
		case 1:    /*  P25S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */
	
		P0V73 = C_30;
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(25, 0);
		else 	Set_Start(95); Set_State(25, 2);
			break;
		case 2:    /*  P25S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(25);  
				}
				else  Set_State(25, 0);  
		}
			break;
		default:
			break;
	}
}

void P26 (void) /* ПРОЦЕСС: ПроверкаСвязиС_РегуляторомТемпературы */
{
	switch (Check_State(26)) {

		case 0:    /*  P26S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V13;   
	if (P0V13) {
		P0V74 = C_29;		
		Set_State(26, 0);
	}
	if (Timeout(26, C_6))  Set_State(26, 1);
			break;
		case 1:    /*  P26S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V74 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(26, 0);
		else 	Set_Start(95); Set_State(26, 2);
			break;
		case 2:    /*  P26S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(26);  
				}
				else  Set_State(26, 0);  
		}
			break;
		default:
			break;
	}
}

void P27 (void) /* ПРОЦЕСС: ПроверкаСвязиС_Вентилятором */
{
	switch (Check_State(27)) {

		case 0:    /*  P27S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V11;   
	if (P0V11) {
		P0V75 = C_29;		
		Set_State(27, 0);
	}
	if (Timeout(27, C_6))  Set_State(27, 1);
			break;
		case 1:    /*  P27S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V75 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(27, 0);
		else Set_Start(95); Set_State(27, 2);
			break;
		case 2:    /*  P27S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(27);  
				}
				else  Set_State(27, 0);  
		}
			break;
		default:
			break;
	}
}

void P28 (void) /* ПРОЦЕСС: ПроверкаСвязиС_НасососомОхлажденияДвигателя */
{
	switch (Check_State(28)) {

		case 0:    /*  P28S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V21;   
	if (P0V21) {
		P0V76 = C_29;		
		Set_State(28, 0);
	}
	if (Timeout(28, C_6))  Set_State(28, 1);
			break;
		case 1:    /*  P28S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V76 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(28, 0);
		else Set_Start(95); Set_State(28, 2);
			break;
		case 2:    /*  P28S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(28);  
				}
				else  Set_State(28, 0);  
		}
			break;
		default:
			break;
	}
}

void P29 (void) /* ПРОЦЕСС: ПроверкаСвязиС_КонцевикомОткрытияЗатвораВакуумного */
{
	switch (Check_State(29)) {

		case 0:    /*  P29S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V1;   
	if (P0V1) {
		P0V77 = C_29;		
		Set_State(29, 0);
	}
	if (Timeout(29, C_6))  Set_State(29, 1);
			break;
		case 1:    /*  P29S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V77 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(29, 0);
		else 	Set_Start(95); Set_State(29, 2);
			break;
		case 2:    /*  P29S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(29);  
				}
				else  Set_State(29, 0);  
		}
			break;
		default:
			break;
	}
}

void P30 (void) /* ПРОЦЕСС: ПроверкаСвязиС_КонцевикомЗакрытияЗатвораВакуумного */
{
	switch (Check_State(30)) {

		case 0:    /*  P30S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V3;   
	if (P0V3) {
		P0V78 = C_29;		
		Set_State(30, 0);
	}
	if (Timeout(30, C_6))  Set_State(30, 1);
			break;
		case 1:    /*  P30S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V78 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(30, 0);
		else 	Set_Start(95); Set_State(30, 2);
			break;
		case 2:    /*  P30S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(30);  
				}
				else  Set_State(30, 0);  
		}
			break;
		default:
			break;
	}
}

void P31 (void) /* ПРОЦЕСС: ПроверкаСвязиС_КонцевикомСапуна */
{
	switch (Check_State(31)) {

		case 0:    /*  P31S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V5;   
	if (P0V5) {
		P0V79 = C_29;		
		Set_State(31, 0);
	}
	if (Timeout(31, C_6))  Set_State(31, 1);
			break;
		case 1:    /*  P31S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V79 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(31, 0);
		else 	Set_Start(95); Set_State(31, 2);
			break;
		case 2:    /*  P31S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(31);  
				}
				else  Set_State(31, 0);  
		}
			break;
		case 3:    /*  P31S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(31);
			break;
		default:
			break;
	}
}

void P32 (void) /* ПРОЦЕСС: ПроверкаСвязиС_ПитаниемПлавногоПуска */
{
	switch (Check_State(32)) {

		case 0:    /*  P32S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V9;   
	if (P0V9) {
		P0V80 = C_29;		
		Set_State(32, 0);
	}
	if (Timeout(32, C_6))  Set_State(32, 1);
			break;
		case 1:    /*  P32S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V80 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(32, 0);
		else 	Set_Start(95); Set_State(32, 2);
			break;
		case 2:    /*  P32S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(32);  
				}
				else  Set_State(32, 0);  
		}
			break;
		case 3:    /*  P32S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(32);
			break;
		default:
			break;
	}
}

void P33 (void) /* ПРОЦЕСС: ПроверкаСвязиС_ПлавнымПуском */
{
	switch (Check_State(33)) {

		case 0:    /*  P33S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) P0V7;   
	if (P0V7) {
		P0V81 = C_29;		
		Set_State(33, 0);
	}
	if (Timeout(33, C_6))  Set_State(33, 1);
			break;
		case 1:    /*  P33S1() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */

		P0V81 = C_30;	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(33, 0);
		else 	Set_Start(95); Set_State(33, 2);
			break;
		case 2:    /*  P33S2() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Stop(33);  
				}
				else  Set_State(33, 0);  
		}
			break;
		case 3:    /*  P33S3() - СОСТОЯНИЕ: НарушениеСвязи */

			Set_Error(33);
			break;
		default:
			break;
	}
}

void P34 (void) /* ПРОЦЕСС: РЕГУЛЯТОР_ТРАФИКА */
{
	switch (Check_State(34)) {

		case 0:    /*  P34S0() - СОСТОЯНИЕ: Начало */

    P0V83 = GetOutMsgNumber_GUI()/5 + 1;  
    
			break;
		default:
			break;
	}
}

void P35 (void) /* ПРОЦЕСС: ЧтениеКольцевогоБуфера */
{
	switch (Check_State(35)) {

		case 0:    /*  P35S0() - СОСТОЯНИЕ: Начало */

    
    if (GetNextMsgGUI()) {
      P0V42 = GetMsgGUICode();
            if ((P0V42 >= C_62) &&
                  (P0V42 <= C_81)) {
				Set_Start(37);
				Set_State(35, 1);
            } 
			else if ((P0V42 >= C_197) &&
                         (P0V42 <= C_212)) {
                     Set_Start(36);
                     Set_State(35, 2);
			}
			else Set_State(35, 3);
    }
			break;
		case 1:    /*  P35S1() - СОСТОЯНИЕ: КонтрольВыполненияК */

    if((Check_State(37) & MASK_OF_INACTIVITY))
    Set_State(35, 0);
			break;
		case 2:    /*  P35S2() - СОСТОЯНИЕ: КонтрольИзмененияНП */

    if((Check_State(36) & MASK_OF_INACTIVITY))
    Set_State(35, 0);
			break;
		case 3:    /*  P35S3() - СОСТОЯНИЕ: НекорректноеСобытие */

     if (SendMsgLongParamGUI(C_213, P0V42))
       Set_State(35, 0);
     if (Timeout(35, C_17))  Set_State(35, 4);
			break;
		case 4:    /*  P35S4() - СОСТОЯНИЕ: НарушениеСвязи */

	Set_State(35, 0);
     Set_Stop(35);
			break;
		default:
			break;
	}
}

void P36 (void) /* ПРОЦЕСС: ОбработкаКомандИзмененияНП_от_ГУИ */
{
	switch (Check_State(36)) {

		case 0:    /*  P36S0() - СОСТОЯНИЕ: Анализ */

    switch (P0V42) {
	    case C_199:
          P0V90  = GetFloatParamGUI();
          P0V43 = C_199;
          Set_State(36, 1);
			break;
	    case C_198:
		   P0V89  = GetFloatParamGUI();
          P0V43 = P0V89;
          Set_State(36, 1);		   
			break;
	    case C_200:
		   P0V91  = GetFloatParamGUI();
          P0V43 = P0V91;
          Set_State(36, 1);		   
			break;
	    case C_201:		
		   P0V92  = GetFloatParamGUI();
          P0V43 = P0V92;
          Set_State(36, 1);		   
			break;
	    case C_202:		
		   P0V93  = GetFloatParamGUI();
          P0V43 = P0V93;
          Set_State(36, 1);		   
			break;			
	    case C_203:	
		   P0V94  = GetFloatParamGUI();
          P0V43 = P0V94;
          Set_State(36, 1);		   
			break;			
	    case C_204:	
		   P0V95  = GetFloatParamGUI();
          P0V43 = P0V95;
          Set_State(36, 1);		   
			break;

	    case C_207:	
		   P0V98  = GetFloatParamGUI();
          P0V43 = P0V98;
          Set_State(36, 1);		   
			break;	
	    case C_208:	
		   P0V99  = GetFloatParamGUI();
          P0V43 = P0V99;
          Set_State(36, 1);		   
			break;	
	    case C_209:	
		   P0V100  = GetFloatParamGUI();
          P0V43 = P0V100;
          Set_State(36, 1);		   
			break;			
	    case C_210:	
		   P0V101  = GetFloatParamGUI();
          P0V43 = P0V101;
          Set_State(36, 1);		   
			break;				
	    case C_211:	
		   P0V102  = GetFloatParamGUI();
          P0V43 = P0V102;
          Set_State(36, 1);		   
			break;

       case C_205:
          P0V96 = GetLongParamGUI();
          P0V43 = C_205;
          Set_State(36, 1);
          break;

       case C_206:
          P0V97 = GetLongParamGUI();
          P0V43 = C_206;
          Set_State(36, 1);
          break;
			
		default:
          Set_State(36, 2);
          break;
    } 
	Set_Stop(36);
			break;
		case 1:    /*  P36S1() - СОСТОЯНИЕ: ПодтверждениеИзмененияНП */

    if (SendMsgLongParamGUI(P0V43, GetLongParamGUI())) Set_Stop(36);
    if (Timeout(36, C_17))  Set_State(36, 3);
			break;
		case 2:    /*  P36S2() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_213, P0V42))
         Set_Stop(36);
    if (Timeout(36, C_17))  Set_State(36, 3);
			break;
		case 3:    /*  P36S3() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_Error(36);
			break;
		default:
			break;
	}
}

void P37 (void) /* ПРОЦЕСС: ОбработкаКомандУправления_от_ГУИ */
{
	switch (Check_State(37)) {

		case 0:    /*  P37S0() - СОСТОЯНИЕ: Анализ */

    switch (P0V42) {


	    case C_62:
			Set_Start(60);		
		break;		
			
  		
																				
	    case C_63:
			Set_Start(61); 		
			break;		
 			

	    case C_64:
			Set_Start(64);		
		break;		
 		   

	    case C_65:
			Set_Start(65);
		break; 																			
 		   

		case C_66:
			Set_Start(89);
		break;
 		   
	
	    case C_67: 
			Set_Start(90);
         break;			
 		   
		  
		case C_68:   
			Set_Start(69);   
          break;
 		   
		  
	    case C_69:  
			Set_Start(70);  
          break;
 		   

	    case C_70:
			Set_Start(54);		
          break;
 		   
  
	    case C_71:
			Set_Start(55);	
          break;
		      	  
 											      
	  
		case C_72:
			Set_Start(74);
          break;
					 
 												
	 
	    case C_73:
			Set_Start(75);
        break;			
 		
  										

	    case C_74:
		  	Set_Start(79);
        break;
  	
  									

	    case C_75:
		  	Set_Start(80);
        break;		
  		
							 

	    case C_76:
			Set_Start(84);
		  break;
					 
 												

	    case C_77:		  
		  	Set_Start(85);		  
		break;		  
  		
							 


		  
	    case C_80:   
          Set_Start(96); 
          break;  
	    case C_79:  
			P0V82 = C_38; 			
			Set_Start(95);  
          break;  

		  case C_78:   
			P0V82 = C_38; 			         
			Set_Start(94);
          break;
		  
		default:
          Set_State(37, 1);
          break;
    } 
	Set_Stop(37);
			break;
		case 1:    /*  P37S1() - СОСТОЯНИЕ: НекорректноеСобытие */

    if (SendMsgLongParamGUI(C_213, P0V42))
         Set_Stop(37);   
    if (Timeout(37, C_17))  Set_State(37, 3);
			break;
		case 2:    /*  P37S2() - СОСТОЯНИЕ: ПередачаСообщенияСПараметромГУИ */

    if (SendMsgLongParamGUI(P37V15, P0V42))
        Set_Stop(37);
    if (Timeout(37, C_17))  Set_State(37, 3);
			break;
		case 3:    /*  P37S3() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_Error(37);
			break;
		default:
			break;
	}
}

void P38 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_ВбакеКомпрессора */
{
	switch (Check_State(38)) {

		case 0:    /*  P38S0() - СОСТОЯНИЕ: Начало */

    P38V2 = (!P0V84);
    Set_State(38, 1);
			break;
		case 1:    /*  P38S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P38V2 != P0V84) {
         P38V2 = P0V84;
         Set_State(38, 2);
    }
			break;
		case 2:    /*  P38S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_192, P38V2))
         Set_State(38, 3);
     if (Timeout(38, C_17))  Set_State(38, 4);
			break;
		case 3:    /*  P38S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(38, P0V83))  Set_State(38, 1);
			break;
		case 4:    /*  P38S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(38, 1);
			break;
		default:
			break;
	}
}

void P39 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_Впатрубке */
{
	switch (Check_State(39)) {

		case 0:    /*  P39S0() - СОСТОЯНИЕ: Начало */

    P39V2 = (!P0V85);
    Set_State(39, 1);
			break;
		case 1:    /*  P39S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P39V2 != P0V85) {
         P39V2 = P0V85;
         Set_State(39, 2);
    }
			break;
		case 2:    /*  P39S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_193, P39V2))
         Set_State(39, 3);
     if (Timeout(39, C_17))  Set_State(39, 4);
			break;
		case 3:    /*  P39S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(39, P0V83))  Set_State(39, 1);
			break;
		case 4:    /*  P39S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(39, 1);
			break;
		default:
			break;
	}
}

void P40 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_T_Врубашке */
{
	switch (Check_State(40)) {

		case 0:    /*  P40S0() - СОСТОЯНИЕ: Начало */

    P40V2 = (!P0V86);
    Set_State(40, 1);
			break;
		case 1:    /*  P40S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P40V2 != P0V86) {
         P40V2 = P0V86;
         Set_State(40, 2);
    }
			break;
		case 2:    /*  P40S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_194, P40V2))
         Set_State(40, 3);
     if (Timeout(40, C_17))  Set_State(40, 4);
			break;
		case 3:    /*  P40S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(40, P0V83))  Set_State(40, 1);
			break;
		case 4:    /*  P40S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(40, 1);
			break;
		default:
			break;
	}
}

void P41 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_T_Вбаке */
{
	switch (Check_State(41)) {

		case 0:    /*  P41S0() - СОСТОЯНИЕ: Начало */

    P41V2 = (!P0V87);
    Set_State(41, 1);
			break;
		case 1:    /*  P41S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P41V2 != P0V87) {
         P41V2 = P0V87;
         Set_State(41, 2);
    }
			break;
		case 2:    /*  P41S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_195, P41V2))
         Set_State(41, 3);
     if (Timeout(41, C_17))  Set_State(41, 4);
			break;
		case 3:    /*  P41S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(41, P0V83))  Set_State(41, 1);
			break;
		case 4:    /*  P41S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(41, 1);
			break;
		default:
			break;
	}
}

void P42 (void) /* ПРОЦЕСС: КонтрольИзменения_ФП_P_ВтрубеСидер */
{
	switch (Check_State(42)) {

		case 0:    /*  P42S0() - СОСТОЯНИЕ: Начало */

    P42V2 = (!P0V88);
    Set_State(42, 1);
			break;
		case 1:    /*  P42S1() - СОСТОЯНИЕ: КонтрольИзменения */

    if (P42V2 != P0V88) {
         P42V2 = P0V88;
         Set_State(42, 2);
    }
			break;
		case 2:    /*  P42S2() - СОСТОЯНИЕ: СообщОбИзменении */

     if (SendMsgFloatParamGUI(C_196, P42V2))
         Set_State(42, 3);
     if (Timeout(42, C_17))  Set_State(42, 4);
			break;
		case 3:    /*  P42S3() - СОСТОЯНИЕ: ТрафикПауза */

    if (Timeout(42, P0V83))  Set_State(42, 1);
			break;
		case 4:    /*  P42S4() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(42, 1);
			break;
		default:
			break;
	}
}

void P43 (void) /* ПРОЦЕСС: КонтрольВеличиныОткачкиВауумнойТрубыСидеростата */
{
	switch (Check_State(43)) {

		case 0:    /*  P43S0() - СОСТОЯНИЕ: Начало */

	P43V2 = P0V88;
	if (Timeout(43, C_24))  Set_State(43, 1);
			break;
		case 1:    /*  P43S1() - СОСТОЯНИЕ: АнализОткачки */

	if ((P43V2 - P0V88) > 0.00) {    
        if (SendMsgGUICode(C_54)) {
					P0V48 = C_32;
					Set_State(43, 0);
		} 
    } else{
	if (SendMsgGUICode(C_55)) {
					P0V48 = C_34;
					Set_State(43, 0);
		} 
	}
			break;
		default:
			break;
	}
}

void P44 (void) /* ПРОЦЕСС: КонтрольГотовностиВакуума_в_Вакуумной_Трубе */
{
	switch (Check_State(44)) {

		case 0:    /*  P44S0() - СОСТОЯНИЕ: Начало */

   if (P0V88 <= P0V91) {  
         if (SendMsgGUICode(C_52)) {
					P0V47 = C_32;
					Set_State(44, 1);
					}
    } else {
                if (SendMsgGUICode(C_53)) {
					P0V47 = C_34;
				   Set_State(44, 2);
				}
    }
    if (Timeout(44, C_17))  Set_State(44, 3);
			break;
		case 1:    /*  P44S1() - СОСТОЯНИЕ: ДавлениеНормальное */
  
       if (P0V88 > (P0V91 + P0V101))  Set_State(44, 0);
			break;
		case 2:    /*  P44S2() - СОСТОЯНИЕ: ДавлениеВысокое */
  
       if (P0V88 < (P0V91 - P0V102))  Set_State(44, 0);
			break;
		case 3:    /*  P44S3() - СОСТОЯНИЕ: НарушениеСвязи */

     Set_State(44, 0);
			break;
		default:
			break;
	}
}

void P45 (void) /* ПРОЦЕСС: КонтрольУровняВодыБакаОхлаждения */
{
	switch (Check_State(45)) {

		case 0:    /*  P45S0() - СОСТОЯНИЕ: Начало */

	if (P0V82 == C_37) {P0V17 = C_25; P0V19 = C_25; } 
	if ((P0V17) && (P0V19)) { 
	
		if ((!P0V16) && (!P0V18)) {		
						P0V44 = C_34;
						Set_State(45, 1);
		} else { 
			if ((P0V16) && (P0V18)) { 
						P0V44 = C_34;
						Set_State(45, 2);
			} else {
				if ((!P0V16) && (P0V18)) {  
						P0V44 = C_34;
						Set_State(45, 3);
				} else  {   
						P0V44 = C_32;
						Set_State(45, 4);
					
				}
			}	 
		}	 
	}
			break;
		case 1:    /*  P45S1() - СОСТОЯНИЕ: СообщениеНизкийУровеньВоды */

		if (SendMsgGUICode(C_42))Set_State(45, 5);
		if (Timeout(45, C_17))  Set_State(45, 9);
			break;
		case 2:    /*  P45S2() - СОСТОЯНИЕ: СообщениеВысокийУровеньВоды */

		if (SendMsgGUICode(C_43))Set_State(45, 6);
		if (Timeout(45, C_17))  Set_State(45, 9);
			break;
		case 3:    /*  P45S3() - СОСТОЯНИЕ: СообщениеОтказДатчиков */

		if (SendMsgGUICode(C_45))Set_State(45, 8);
		if (Timeout(45, C_17))  Set_State(45, 9);
			break;
		case 4:    /*  P45S4() - СОСТОЯНИЕ: СообщениеУровеньВодыВнорме */

		if (SendMsgGUICode(C_44))Set_State(45, 7);
		if (Timeout(45, C_17))  Set_State(45, 9);
			break;
		case 5:    /*  P45S5() - СОСТОЯНИЕ: НизкийУровеньВоды */

		if (P0V82 == C_37) {P0V17 = C_25; P0V19 = C_25; }  
		if (((P0V16) || (P0V18)) && (P0V17) && (P0V19))  Set_State(45, 0);
			break;
		case 6:    /*  P45S6() - СОСТОЯНИЕ: ВысокийУровеньВоды */

 		if (P0V82 == C_37) {P0V17 = C_25; P0V19 = C_25; } 
       if (((!P0V16) || (!P0V18)) && (P0V17) && (P0V19)) Set_State(45, 0);
			break;
		case 7:    /*  P45S7() - СОСТОЯНИЕ: УровеньВодыВнорме */

  		if (P0V82 == C_37) {P0V17 = C_25; P0V19 = C_25; } 
		if (((!P0V16) || (P0V18)) && (P0V17) && (P0V19)){ 
			Set_State(45, 0);
		}
			break;
		case 8:    /*  P45S8() - СОСТОЯНИЕ: ОтказДатчиков */

		if (P0V82 == C_37) {P0V17 = C_25; P0V19 = C_25; }  
		if (((P0V16) || (!P0V18)) && (P0V17) && (P0V19))Set_State(45, 0);
			break;
		case 9:    /*  P45S9() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_State(45, 0);
			break;
		default:
			break;
	}
}

void P46 (void) /* ПРОЦЕСС: КонтрольТемпературыВодыБакаОхлаждения */
{
	switch (Check_State(46)) {

		case 0:    /*  P46S0() - СОСТОЯНИЕ: Начало */

    if (P0V87 < P0V94) { 
         if (SendMsgGUICode(C_46)) {
					P0V45 = C_34;
					Set_State(46, 1);
					}
    } else if (P0V87 > P0V95) {		
              if (SendMsgGUICode(C_47)) {
			   P0V45 = C_34;
			   Set_State(46, 2);
			   }
    } else {
                if (SendMsgGUICode(C_48)) {
					P0V45 = C_32;
				   Set_State(46, 3);
				}
    }
		 
    if (Timeout(46, C_17))  Set_State(46, 4);
			break;
		case 1:    /*  P46S1() - СОСТОЯНИЕ: НизкаяТемператураВоды */
					
	if (P0V87 > (P0V94 + P0V98))  Set_State(46, 0);
	if (Timeout(46, C_18))  Set_State(46, 0);
			break;
		case 2:    /*  P46S2() - СОСТОЯНИЕ: ВысокаяТемператураВоды */

	if (P0V87 < (P0V95 - P0V98))  Set_State(46, 0);
	if (Timeout(46, C_18))  Set_State(46, 0);
			break;
		case 3:    /*  P46S3() - СОСТОЯНИЕ: ТемператураВнорме */

       if ((P0V87 < (P0V94 - P0V98)) || 
	         (P0V87 > (P0V95 + P0V98)))  Set_State(46, 0);
			break;
		case 4:    /*  P46S4() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(46, 0);
			break;
		default:
			break;
	}
}

void P47 (void) /* ПРОЦЕСС: КонтрольТемпературыРубашкиОхлаждения */
{
	switch (Check_State(47)) {

		case 0:    /*  P47S0() - СОСТОЯНИЕ: Начало */

    if (P0V86 < P0V92) {  
         if (SendMsgGUICode(C_49)) {
					P0V46 = C_31;
					Set_State(47, 1);
					}
    } else if (P0V86 > P0V93) {		
              if (SendMsgGUICode(C_50)) {
			   P0V46 = C_33;
			   Set_State(47, 2);
			   }
    } else {
                if (SendMsgGUICode(C_51)) {
					P0V46 = C_32;
				   Set_State(47, 3);
				}
         }
    if (Timeout(47, C_17))  Set_State(47, 5);
			break;
		case 1:    /*  P47S1() - СОСТОЯНИЕ: НизкаяТемператураВоды */

       
		if (P0V86 > (P0V92 + P0V99))  Set_State(47, 0);
		if (Timeout(47, C_18))  Set_State(47, 0);
			break;
		case 2:    /*  P47S2() - СОСТОЯНИЕ: ВысокаяТемператураВоды */

        if (P0V86 < (P0V93 - P0V99))  Set_State(47, 0);
		if (Timeout(47, C_18))  Set_State(47, 0);
			break;
		case 3:    /*  P47S3() - СОСТОЯНИЕ: ТемператураВнорме */

        if ((P0V86 < (P0V92 - P0V99)) || 
	         (P0V86 > (P0V93 + P0V99)))  Set_State(47, 0);
			break;
		case 4:    /*  P47S4() - СОСТОЯНИЕ: Задержка */

      if (Timeout(47, C_18))  Set_State(47, 0);
			break;
		case 5:    /*  P47S5() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(47, 0);
			break;
		default:
			break;
	}
}

void P48 (void) /* ПРОЦЕСС: КонтрольДавленияВбакеКомпрессора */
{
	switch (Check_State(48)) {

		case 0:    /*  P48S0() - СОСТОЯНИЕ: Начало */
    						
    if (P0V84 < P0V89) {
        if (SendMsgGUICode(C_58)) {
					P0V49 = C_34;
					Set_State(48, 1);
		}
    } else if (P0V84 >= (P0V89)) {
				if (SendMsgGUICode(C_56)) {
					P0V49 = C_32;
					Set_State(48, 2);
				}
			}
    if (Timeout(48, C_17))  Set_State(48, 4);
			break;
		case 1:    /*  P48S1() - СОСТОЯНИЕ: НизкоеДавление */
														
		if (P0V84 > ((P0V89 ) + P0V100))
																				Set_State(48, 0);
			break;
		case 2:    /*  P48S2() - СОСТОЯНИЕ: ДавлениеВнорме */
														
        if (P0V84 < (P0V89 - P0V100))  Set_State(48, 0);
			break;
		case 3:    /*  P48S3() - СОСТОЯНИЕ: Задержка */

      if (Timeout(48, C_2))  Set_State(48, 0);
			break;
		case 4:    /*  P48S4() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(48, 0);
			break;
		default:
			break;
	}
}

void P49 (void) /* ПРОЦЕСС: КонтрольАварийногоДавленияВбакеКомпрессора */
{
	switch (Check_State(49)) {

		case 0:    /*  P49S0() - СОСТОЯНИЕ: Начало */

		if (P0V84 <= 2.0) Set_State(49, 1);
			break;
		case 1:    /*  P49S1() - СОСТОЯНИЕ: АварийноеДавлениеВбакеКомпрессора */

 		if (SendMsgGUICode(C_112)) Set_State(49, 2);
		if (Timeout(49, C_17))  Set_State(49, 6);
			break;
		case 2:    /*  P49S2() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */
	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(49, 5);
		else Set_Start(95); Set_State(49, 3);
			break;
		case 3:    /*  P49S3() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) Set_Start(20);
				else  Set_State(49, 4);  
		}
			break;
		case 4:    /*  P49S4() - СОСТОЯНИЕ: ОжиданиеПовышенияДавления */
 
		if (P0V84 > 2.0) Set_State(49, 0);
			break;
		case 5:    /*  P49S5() - СОСТОЯНИЕ: Пауза */

     if (Timeout(49, C_5))  Set_State(49, 0);
			break;
		case 6:    /*  P49S6() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(49, 0);
			break;
		default:
			break;
	}
}

void P50 (void) /* ПРОЦЕСС: КонтрольАварийнойТемпературыВрубашкеОхлаждения */
{
	switch (Check_State(50)) {

		case 0:    /*  P50S0() - СОСТОЯНИЕ: Начало */

		if (P0V86 >  C_40) Set_State(50, 1);
			break;
		case 1:    /*  P50S1() - СОСТОЯНИЕ: АварийнаяТемператураВрубахеОхлаждения */

 		if (SendMsgGUICode(C_114)) Set_State(50, 2);
		if (Timeout(50, C_17))  Set_State(50, 6);
			break;
		case 2:    /*  P50S2() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */
	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(50, 5);
		else Set_Start(95); Set_State(50, 3);
			break;
		case 3:    /*  P50S3() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) Set_Start(20);
				else  Set_State(50, 4);  
		}
			break;
		case 4:    /*  P50S4() - СОСТОЯНИЕ: ОжиданиеСниженияТемпературы */
 
		if (P0V86 < P0V93) Set_State(50, 0);
			break;
		case 5:    /*  P50S5() - СОСТОЯНИЕ: Пауза */

     if (Timeout(50, C_5))  Set_State(50, 0);
			break;
		case 6:    /*  P50S6() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(50, 0);
			break;
		default:
			break;
	}
}

void P51 (void) /* ПРОЦЕСС: КонтрольАварийнойТемпературыВбакеОхлаждения */
{
	switch (Check_State(51)) {

		case 0:    /*  P51S0() - СОСТОЯНИЕ: Начало */

		if (P0V87 >  C_41) Set_State(51, 1);
			break;
		case 1:    /*  P51S1() - СОСТОЯНИЕ: АварийнаяТемператураВБакеОхлаждения */

		if (SendMsgGUICode(C_115)) Set_State(51, 2);
		if (Timeout(51, C_17))  Set_State(51, 6);
			break;
		case 2:    /*  P51S2() - СОСТОЯНИЕ: ПроверкаИдетЛиВакуумирование */
	
		if ((Check_State(94) & MASK_OF_INACTIVITY)) Set_State(51, 5);
		else 	Set_Start(95); Set_State(51, 3);
			break;
		case 3:    /*  P51S3() - СОСТОЯНИЕ: КонтрольВыключения */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(95) == STATE_OF_ERROR) ) Set_Start(20);
				else  Set_State(51, 4);  
		}
			break;
		case 4:    /*  P51S4() - СОСТОЯНИЕ: ОжиданиеСниженияТемпературы */
 
		if (P0V87 < P0V95) Set_State(51, 0);
			break;
		case 5:    /*  P51S5() - СОСТОЯНИЕ: Пауза */

     if (Timeout(51, C_5))  Set_State(51, 0);
			break;
		case 6:    /*  P51S6() - СОСТОЯНИЕ: НарушениеСвязи */

    Set_State(51, 0);
			break;
		default:
			break;
	}
}

void P52 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияШКАФА_ВС */
{
	switch (Check_State(52)) {

		case 0:    /*  P52S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V23 = C_25;  
	    if (P0V23){
			if (P0V22){
				P0V64 = C_25; Set_State(52, 1);
			}
			else{
				P0V64 = C_26; 	Set_State(52, 2);
			}		
		}
			break;
		case 1:    /*  P52S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_117))  Set_State(52, 3);
		if (Timeout(52, C_17))  Set_State(52, 5);
			break;
		case 2:    /*  P52S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_118))  Set_State(52, 4);
		if (Timeout(52, C_17))  Set_State(52, 5);
			break;
		case 3:    /*  P52S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V23 = C_25;  
		if ((!P0V22)&&(P0V23))  Set_State(52, 0);
			break;
		case 4:    /*  P52S4() - СОСТОЯНИЕ: СменаСостоянияВЫКЛ */

		if (P0V82 == C_37) P0V23 = C_25;  
		if ((P0V22) && (P0V23))  Set_State(52, 0);
			break;
		case 5:    /*  P52S5() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_State(52, 0);
			break;
		default:
			break;
	}
}

void P53 (void) /* ПРОЦЕСС: КонтрольСостоянияОборудования */
{
	switch (Check_State(53)) {

		case 0:    /*  P53S0() - СОСТОЯНИЕ: КонтрольОборудования */

			if ((P0V0 == C_25) && 
				(P0V2 == C_26) &&
				(P0V22 == C_25) &&    
				(P0V4 == C_28) &&    
				(P0V6 == C_25) &&    
				(P0V8 == C_25) &&   
				(P0V10 == C_25) &&    
				(P0V12 == C_25) &&      
				(P0V14 == C_25) && 
				(P0V20 == C_25)  &&    
				(P0V49 == C_32)   
			) 
		{ 			
			Set_State(53, 0);
		}
		if (Timeout(53, C_2))  Set_State(53, 1);
			break;
		case 1:    /*  P53S1() - СОСТОЯНИЕ: СообщениеОбОтказеВакуумирования */

       if (SendMsgGUICode(C_59))	Set_State(53, 2);
      if (Timeout(53, C_17))  Set_State(53, 5);
			break;
		case 2:    /*  P53S2() - СОСТОЯНИЕ: ВыключенияВакНасоса */

		Set_Start(95);
		Set_State(53, 3);
			break;
		case 3:    /*  P53S3() - СОСТОЯНИЕ: КонтрольВыключенияВакНасоса */

		if ( (Check_State(95) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(95) == STATE_OF_ERROR) ) {
				Set_State(53, 4);  
			}
			else Set_Stop(53);   
		}
			break;
		case 4:    /*  P53S4() - СОСТОЯНИЕ: ВыключениеНаЩиткеКнопарями */

    Set_Start(20);
    Set_Error(53);
			break;
		case 5:    /*  P53S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(53);
			break;
		default:
			break;
	}
}

void P54 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_ВЕНТИЛЯТОР */
{
	switch (Check_State(54)) {

		case 0:    /*  P54S0() - СОСТОЯНИЕ: Начало */

		P54V4 = P0V34[1];
		if ((!(Check_State(55) & MASK_OF_INACTIVITY))) Set_Error(55);
		Set_Stop(58);
		P0V34[1] = C_25;
		Set_State(54, 1);
			break;
		case 1:    /*  P54S1() - СОСТОЯНИЕ: КонтрольВключения */

		if (P0V82 == C_37) P0V11 = C_25;   
		if ((P0V10 == C_25) && (P0V11))  {
			Set_Start(57);
			Set_Stop(54);  
		}
		if (Timeout(54, C_13))  Set_State(54, 2);
			break;
		case 2:    /*  P54S2() - СОСТОЯНИЕ: Ошибка */

		P0V34[1] = P54V4;
		if (SendMsgGUICode(C_92))	Set_Error(54);
		if (Timeout(54, C_17))  Set_State(54, 3);
			break;
		case 3:    /*  P54S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(54);
			break;
		default:
			break;
	}
}

void P55 (void) /* ПРОЦЕСС: ВЫК_ПИТ_ВЕНТИЛЯТОР */
{
	switch (Check_State(55)) {

		case 0:    /*  P55S0() - СОСТОЯНИЕ: Начало */

		if ((!(Check_State(54) & MASK_OF_INACTIVITY))) Set_Error(54);
		Set_Stop(57);
		P0V34[1] = C_26;
		Set_State(55, 1);
			break;
		case 1:    /*  P55S1() - СОСТОЯНИЕ: КонтрольВыключения */

		if (P0V82 == C_37) P0V11 = C_25;  
		if ((P0V10 == C_26) && (P0V11)) {
			Set_Start(58);
			Set_Stop(55);	
		} 
		if (Timeout(55, C_13))  Set_State(55, 2);
			break;
		case 2:    /*  P55S2() - СОСТОЯНИЕ: Ошибка */

		P0V34[1] = P55V4;
		if (SendMsgGUICode(C_93))	Set_Error(55);
		if (Timeout(55, C_17))  Set_State(55, 3);
			break;
		case 3:    /*  P55S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(55);
			break;
		default:
			break;
	}
}

void P56 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияВентилятора */
{
	switch (Check_State(56)) {

		case 0:    /*  P56S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V11 = C_25;  
	   

	   if (P0V11){
			 if (P0V10) 
			   { 
					P0V63 = C_25;
					Set_State(56, 1); 
			   }
			   else      
			   { 
					P0V63 = C_26;
					Set_State(56, 2);
			   }
		}
			break;
		case 1:    /*  P56S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_119))  Set_State(56, 3);
		if (Timeout(56, C_17))  Set_State(56, 5);
			break;
		case 2:    /*  P56S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_120))  Set_State(56, 4);
		if (Timeout(56, C_17))  Set_State(56, 5);
			break;
		case 3:    /*  P56S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V11 = C_25;  
		if ((!P0V10)&&(P0V11))  Set_State(56, 0);
			break;
		case 4:    /*  P56S4() - СОСТОЯНИЕ: СменаСостоянияВЫКЛ */

		if (P0V82 == C_37) P0V11 = C_25;  
		if ((P0V10) && (P0V11))  Set_State(56, 0);
			break;
		case 5:    /*  P56S5() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_State(56, 0);
			break;
		default:
			break;
	}
}

void P57 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияВентилятора */
{
	switch (Check_State(57)) {

		case 0:    /*  P57S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V11 = C_25;   
		if ((P0V10 == C_26) && (P0V11))
		{
			Set_Start(58);
			P0V34[1] = C_26;
			Set_State(57, 1);
		}
			break;
		case 1:    /*  P57S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_121)) Set_Error(57);
		if (Timeout(57, C_17))  Set_State(57, 2);
			break;
		case 2:    /*  P57S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(57);
			break;
		default:
			break;
	}
}

void P58 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияВентилятора */
{
	switch (Check_State(58)) {

		case 0:    /*  P58S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V11 = C_25;   
		if ((P0V10 == C_25) && (P0V11)) 
		{	
			Set_Start(57);
			P0V34[1] = C_25;
			Set_State(58, 1); 
		}
			break;
		case 1:    /*  P58S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_122)) Set_Error(58);
		if (Timeout(58, C_17))  Set_State(58, 2);
			break;
		case 2:    /*  P58S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(58);
			break;
		default:
			break;
	}
}

void P59 (void) /* ПРОЦЕСС: КонтрольСостоянияЗатвораВакуумного */
{
	switch (Check_State(59)) {

		case 0:    /*  P59S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25; } 
		if ((P0V1) && (P0V3)) { 
			if ((!P0V0) && (!P0V2) ) {  
				P0V58 = C_26;
				P0V59 = C_26;
				Set_State(59, 1);
			} else {
				if ((!P0V0)&&(P0V2)) {  
					P0V58 = C_26;
					P0V59 = C_25;
					Set_State(59, 2);
				} else {
					if ((P0V0)&&(!P0V2) ) {  
						P0V58 = C_25;
						P0V59 = C_26;
						Set_State(59, 3);
					} else { 										 
						P0V58 = C_25;  
						P0V59 = C_25;
						Set_State(59, 4);
					}
				}
			}
		}
			break;
		case 1:    /*  P59S1() - СОСТОЯНИЕ: СообщениеСменаСостоянияСреднего */

		if (SendMsgGUICode(C_125))Set_State(59, 5);
		if (Timeout(59, C_17))  Set_State(59, 9);
			break;
		case 2:    /*  P59S2() - СОСТОЯНИЕ: СообщениеСменаСостоянияЗакрытия */

		if (SendMsgGUICode(C_124))Set_State(59, 6);
		if (Timeout(59, C_17))  Set_State(59, 9);
			break;
		case 3:    /*  P59S3() - СОСТОЯНИЕ: СообщениеСменаСостоянияОткрытия */

		if (SendMsgGUICode(C_123))Set_State(59, 7);
		if (Timeout(59, C_17))  Set_State(59, 9);
			break;
		case 4:    /*  P59S4() - СОСТОЯНИЕ: СообщениеСменаСостоянияОшибки */

		if (SendMsgGUICode(C_126))Set_State(59, 8);
		if (Timeout(59, C_17))  Set_State(59, 9);
			break;
		case 5:    /*  P59S5() - СОСТОЯНИЕ: СменаСостоянияСреднего */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25; } 
        if (((P0V0) || (P0V2)) && (P0V1) && (P0V3))  Set_State(59, 0);
			break;
		case 6:    /*  P59S6() - СОСТОЯНИЕ: СменаСостоянияЗакрытия */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25; } 
		if ((P0V0 || (!P0V2))  && (P0V1) && (P0V3)) Set_State(59, 0);
			break;
		case 7:    /*  P59S7() - СОСТОЯНИЕ: СменаСостоянияОткрытия */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25; } 
		if (((!P0V0) || P0V2)  && (P0V1) && (P0V3)) Set_State(59, 0);
			break;
		case 8:    /*  P59S8() - СОСТОЯНИЕ: СменаСостоянияОшибки */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25; } 
		if (((!P0V0) || (!P0V2))  && (P0V1) && (P0V3))  Set_State(59, 0);
			break;
		case 9:    /*  P59S9() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_State(59, 0);
			break;
		default:
			break;
	}
}

void P60 (void) /* ПРОЦЕСС: ОТКР_ЗАТВОР_ВАК */
{
	switch (Check_State(60)) {

		case 0:    /*  P60S0() - СОСТОЯНИЕ: Начало */

		P60V6 = P0V38[1];
		if ((!(Check_State(61) & MASK_OF_INACTIVITY))) Set_Error(61);
		Set_Stop(63);
		P0V38[1] = C_27;
		Set_State(60, 1);
			break;
		case 1:    /*  P60S1() - СОСТОЯНИЕ: Контроль */
 
		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25;}   
		if ((P0V0 == C_25) && (P0V1) &&
				(P0V2 == C_26) && (P0V3)) {
			Set_Start(62);		
			Set_Stop(60);
		}
		if (Timeout(60, C_9))  Set_State(60, 2);
			break;
		case 2:    /*  P60S2() - СОСТОЯНИЕ: Ошибка */

		P0V38[1] = P60V6;
		if (SendMsgGUICode(C_88))	Set_Error(60);
		if (Timeout(60, C_17))  Set_State(60, 3);
			break;
		case 3:    /*  P60S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(60);
			break;
		default:
			break;
	}
}

void P61 (void) /* ПРОЦЕСС: ЗАКР_ЗАТВОР_ВАК */
{
	switch (Check_State(61)) {

		case 0:    /*  P61S0() - СОСТОЯНИЕ: Начало */

		P61V6 = P0V38[1];
		if ((!(Check_State(60) & MASK_OF_INACTIVITY))) Set_Error(60);
		Set_Stop(62);
		P0V38[1] = C_28;
		Set_State(61, 1);
			break;
		case 1:    /*  P61S1() - СОСТОЯНИЕ: Контроль */
 
		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25;}   
		if ((P0V0 == C_26) && (P0V1) &&
				(P0V2 == C_25) && (P0V3) ) {
			Set_Start(63);	
			Set_Stop(61);
		} 
		if (Timeout(61, C_9))  Set_State(61, 2);
			break;
		case 2:    /*  P61S2() - СОСТОЯНИЕ: Ошибка */

		P0V38[1] = P61V6;
		if (SendMsgGUICode(C_89))	Set_Error(61);
		if (Timeout(61, C_17))  Set_State(61, 3);
			break;
		case 3:    /*  P61S3() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(61);
			break;
		default:
			break;
	}
}

void P62 (void) /* ПРОЦЕСС: КонтрольСпонтанногоЗакрытияЗатвораВакуумного */
{
	switch (Check_State(62)) {

		case 0:    /*  P62S0() - СОСТОЯНИЕ: КонтрольЗакрытия */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25;}   
		if ((P0V0 == C_26) && (P0V1) &&
				(P0V2 == C_25) && (P0V3) )

		{
			Set_Start(63);
			P0V38[1] = C_28;
			Set_State(62, 1);
		}
			break;
		case 1:    /*  P62S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_128)) {
			Set_Error(62); }
		if (Timeout(62, C_17))  Set_State(62, 2);
			break;
		case 2:    /*  P62S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(62);
			break;
		default:
			break;
	}
}

void P63 (void) /* ПРОЦЕСС: КонтрольСпонтанногоОткрытияЗатвораВакуумного */
{
	switch (Check_State(63)) {

		case 0:    /*  P63S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) {P0V1 = C_25; P0V3 = C_25;}   
		if ((P0V0 == C_25) && (P0V1) &&
				(P0V2 == C_26) && (P0V3) )
			{
				Set_Start(62);
				P0V38[1] = C_27;
				Set_State(63, 1);
			}
			break;
		case 1:    /*  P63S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_127))  Set_Error(63);
		if (Timeout(63, C_17))  Set_State(63, 2);
			break;
		case 2:    /*  P63S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(63);
			break;
		default:
			break;
	}
}

void P64 (void) /* ПРОЦЕСС: ОТКР_САПУН */
{
	switch (Check_State(64)) {

		case 0:    /*  P64S0() - СОСТОЯНИЕ: Начало */

		P64V4 = P0V39[1];
		if ((!(Check_State(65) & MASK_OF_INACTIVITY))) Set_Error(65);
		Set_Stop(68);	
		P0V39[1] = C_27;
		Set_State(64, 1);
			break;
		case 1:    /*  P64S1() - СОСТОЯНИЕ: КонтрольОткрытия */

		if (P0V82 == C_37) P0V5 = C_25;    
		if ((P0V4 == C_27) && (P0V5)){
			Set_Start(67);	
			Set_Stop(64);	
		}
		if (Timeout(64, C_10))  Set_State(64, 2);
			break;
		case 2:    /*  P64S2() - СОСТОЯНИЕ: Ошибка */

		P0V39[1] = P64V4;
		if (SendMsgGUICode(C_90))	Set_Error(64);
		if (Timeout(64, C_17))  Set_State(64, 3);
			break;
		case 3:    /*  P64S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(64);
			break;
		default:
			break;
	}
}

void P65 (void) /* ПРОЦЕСС: ЗАКР_САПУН */
{
	switch (Check_State(65)) {

		case 0:    /*  P65S0() - СОСТОЯНИЕ: Начало */

	P65V4 = P0V39[1];
	if ((!(Check_State(64) & MASK_OF_INACTIVITY))) Set_Error(64);
		Set_Stop(67);   
		P0V39[1] = C_28;
		Set_State(65, 1);
			break;
		case 1:    /*  P65S1() - СОСТОЯНИЕ: КонтрольЗакрытия */
 
		if (P0V82 == C_37) P0V5 = C_25;    
		if ((P0V4 == C_28) && (P0V5)){
			Set_Start(68);	
			Set_Stop(65);	
		}
		if (Timeout(65, C_10))  	Set_State(65, 2);
			break;
		case 2:    /*  P65S2() - СОСТОЯНИЕ: Ошибка */

		P0V39[1] = P65V4;
		if (SendMsgGUICode(C_91))	Set_Error(65);
		if (Timeout(65, C_17))  Set_State(65, 3);
			break;
		case 3:    /*  P65S3() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(65);
			break;
		default:
			break;
	}
}

void P66 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияСапуна */
{
	switch (Check_State(66)) {

		case 0:    /*  P66S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V5 = C_25;  
	    if (P0V5){
			if (P0V4){
				P0V60 = C_27; Set_State(66, 1);
			}
			else{
				P0V60 = C_28; 	Set_State(66, 2);
			}		
		}
			break;
		case 1:    /*  P66S1() - СОСТОЯНИЕ: ОткрытСообщаем */
 
		if (SendMsgGUICode(C_129))  Set_State(66, 3);
		if (Timeout(66, C_17))  Set_State(66, 5);
			break;
		case 2:    /*  P66S2() - СОСТОЯНИЕ: ЗакрытСообщаем */
 
		if (SendMsgGUICode(C_130))  Set_State(66, 4);
		if (Timeout(66, C_17))  Set_State(66, 5);
			break;
		case 3:    /*  P66S3() - СОСТОЯНИЕ: СменаСостоянияОткрыт */

		if (P0V82 == C_37) P0V5 = C_25;  
		if ((!P0V4)&&(P0V5))  Set_State(66, 0);
			break;
		case 4:    /*  P66S4() - СОСТОЯНИЕ: СменаСостоянияЗакрыт */

		if (P0V82 == C_37) P0V5 = C_25;  
		if ((P0V4) && (P0V5))  Set_State(66, 0);
			break;
		case 5:    /*  P66S5() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(66, 0);
			break;
		default:
			break;
	}
}

void P67 (void) /* ПРОЦЕСС: КонтрольСпонтанногоЗакрытияСапуна */
{
	switch (Check_State(67)) {

		case 0:    /*  P67S0() - СОСТОЯНИЕ: КонтрольЗакрытия */

		if (P0V82 == C_37) P0V5 = C_25;    
		if ((P0V4 == C_26) && (P0V5)) 
			{	
				Set_Start(68);
				P0V39[1] = C_28;
				Set_State(67, 1);
			}
			break;
		case 1:    /*  P67S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_132)) Set_Error(67);
		if (Timeout(67, C_17))  Set_State(67, 2);
			break;
		case 2:    /*  P67S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(67);
			break;
		default:
			break;
	}
}

void P68 (void) /* ПРОЦЕСС: КонтрольСпонтанногоОткрытияСапуна */
{
	switch (Check_State(68)) {

		case 0:    /*  P68S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V5 = C_25;   
		if ((P0V4 == C_25) && (P0V5))
		{
			Set_Start(67);
			P0V39[1] = C_27;
			Set_State(68, 1);
		}
			break;
		case 1:    /*  P68S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_131)) Set_Error(68);
				
		if (Timeout(68, C_17))  Set_State(68, 2);
			break;
		case 2:    /*  P68S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(68);
			break;
		default:
			break;
	}
}

void P69 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_УПП_ВАК_НАСОСА */
{
	switch (Check_State(69)) {

		case 0:    /*  P69S0() - СОСТОЯНИЕ: Начало */

		P69V4 = P0V37[1];
		if ((!(Check_State(70) & MASK_OF_INACTIVITY))) Set_Error(70);  
		Set_Stop(73);
		P0V37[1] = C_25;   
		Set_State(69, 1);
			break;
		case 1:    /*  P69S1() - СОСТОЯНИЕ: КонтрольВключения */
 
		if (P0V82 == C_37) P0V9 = C_25;     
		if ((P0V8 == C_25) && (P0V9)){        
			Set_Start(72);
			Set_Stop(69);	
		}
		if (Timeout(69, C_12))  	Set_State(69, 2);
			break;
		case 2:    /*  P69S2() - СОСТОЯНИЕ: Ошибка */

		P0V37[1] = P69V4;
		if (SendMsgGUICode(C_109))	Set_Error(69);
		if (Timeout(69, C_17))  Set_State(69, 3);
			break;
		case 3:    /*  P69S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(69);
			break;
		default:
			break;
	}
}

void P70 (void) /* ПРОЦЕСС: ВЫК_ПИТ_УПП_ВАК_НАСОСА */
{
	switch (Check_State(70)) {

		case 0:    /*  P70S0() - СОСТОЯНИЕ: Начало */

		P70V4 = P0V37[1];
		if ((!(Check_State(69) & MASK_OF_INACTIVITY))) Set_Error(69); 
		Set_Stop(72);
		P0V37[1] = C_26;   
		Set_State(70, 1);
			break;
		case 1:    /*  P70S1() - СОСТОЯНИЕ: КонтрольВыключения */

		if (P0V82 == C_37) P0V9 = C_25;   
		if ((P0V8 == C_26) && (P0V9)) {  
			Set_Start(73);
			Set_Stop(70);	
		}
		if (Timeout(70, C_12))  	Set_State(70, 2);
			break;
		case 2:    /*  P70S2() - СОСТОЯНИЕ: Ошибка */

		P0V37[1] = P70V4;
		if (SendMsgGUICode(C_110))	Set_Error(70);
		if (Timeout(70, C_17))  Set_State(70, 3);
			break;
		case 3:    /*  P70S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(70);
			break;
		default:
			break;
	}
}

void P71 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияУППВакНасоса */
{
	switch (Check_State(71)) {

		case 0:    /*  P71S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V9 = C_25;  
	    if (P0V9){
			if (P0V8){
				P0V62 = C_25; Set_State(71, 1);
			}
			else{
				P0V62 = C_26; 	Set_State(71, 2);
			}		
		}
			break;
		case 1:    /*  P71S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_133))  Set_State(71, 3);
		if (Timeout(71, C_17))  Set_State(71, 5);
			break;
		case 2:    /*  P71S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_134))  Set_State(71, 4);
		if (Timeout(71, C_17))  Set_State(71, 5);
			break;
		case 3:    /*  P71S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V9 = C_25;  
		if ((!P0V8)&&(P0V9))  Set_State(71, 0);
			break;
		case 4:    /*  P71S4() - СОСТОЯНИЕ: СменаСостоянияВЫК */

		if (P0V82 == C_37) P0V9 = C_25;  
		if ((P0V8) && (P0V9))  Set_State(71, 0);
			break;
		case 5:    /*  P71S5() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(71, 0);
			break;
		default:
			break;
	}
}

void P72 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияУППВакНасоса */
{
	switch (Check_State(72)) {

		case 0:    /*  P72S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V9 = C_25;  	
		if ((P0V8 == C_26) && (P0V9))
			{ 
				Set_Start(73);
				P0V37[1] = C_26;
				Set_State(72, 1);
			}
			break;
		case 1:    /*  P72S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_136)) Set_Error(72);  
		if (Timeout(72, C_17))  Set_State(72, 2);
			break;
		case 2:    /*  P72S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(72);
			break;
		default:
			break;
	}
}

void P73 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияУППВакНасоса */
{
	switch (Check_State(73)) {

		case 0:    /*  P73S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V9 = C_25;  
		if ((P0V8 == C_25) && (P0V9))
			{	
				Set_Start(72);
				P0V37[1] = C_25;
				Set_State(73, 1);
			}
			break;
		case 1:    /*  P73S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_135)) Set_Error(73);
		if (Timeout(73, C_17))  Set_State(73, 2);
			break;
		case 2:    /*  P73S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(73);
			break;
		default:
			break;
	}
}

void P74 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_РЕГ_Т */
{
	switch (Check_State(74)) {

		case 0:    /*  P74S0() - СОСТОЯНИЕ: Начало */

	
	
		P74V5 = P0V35[1];
		if ((!(Check_State(75) & MASK_OF_INACTIVITY))) Set_Error(75);
		Set_Stop(78);
		P0V35[1] = C_25;
		Set_State(74, 1);
			break;
		case 1:    /*  P74S1() - СОСТОЯНИЕ: КонтрольВключения */

		if (P0V82 == C_37) P0V13 = C_25;   
		if ((P0V12 == C_25) && (P0V13)) {
			Set_Start(77);
		Set_Stop(74);	
		}
		if (Timeout(74, C_14))  Set_State(74, 2);
			break;
		case 2:    /*  P74S2() - СОСТОЯНИЕ: Ошибка */

		P0V35[1] = P74V5;
		if (SendMsgGUICode(C_96))	Set_Error(74);
		if (Timeout(74, C_17))  Set_State(74, 3);
			break;
		case 3:    /*  P74S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(74);
			break;
		default:
			break;
	}
}

void P75 (void) /* ПРОЦЕСС: ВЫК_ПИТ_РЕГ_Т */
{
	switch (Check_State(75)) {

		case 0:    /*  P75S0() - СОСТОЯНИЕ: Начало */

		P75V4 = P0V35[1];
		if ((!(Check_State(74) & MASK_OF_INACTIVITY))) Set_Error(74);
		Set_Stop(77);
		P0V35[1]  = C_26;
		Set_State(75, 1);
			break;
		case 1:    /*  P75S1() - СОСТОЯНИЕ: КонтрольВыключения */
 
		if (P0V82 == C_37) P0V13 = C_25;    
		if ((P0V12 == C_26) && (P0V13)) {	
			Set_Start(78);  
			Set_Stop(75);	
		} 
		if (Timeout(75, C_14))  Set_State(75, 2);
			break;
		case 2:    /*  P75S2() - СОСТОЯНИЕ: Ошибка */

		P0V35[1] = P75V4;
		if (SendMsgGUICode(C_97))	Set_Error(75);
		if (Timeout(75, C_17))  Set_State(75, 3);
			break;
		case 3:    /*  P75S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(75);
			break;
		default:
			break;
	}
}

void P76 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияРЕГ_Т */
{
	switch (Check_State(76)) {

		case 0:    /*  P76S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V13 = C_25;  
	    if (P0V13){
			if (P0V12){
				P0V65 = C_25;  Set_State(76, 1);
			}
			else{
				P0V65 = C_26;  	Set_State(76, 2);
			}		
		}
			break;
		case 1:    /*  P76S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_137))  Set_State(76, 3);
		if (Timeout(76, C_17))  Set_State(76, 5);
			break;
		case 2:    /*  P76S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_138))  Set_State(76, 4);
		if (Timeout(76, C_17))  Set_State(76, 5);
			break;
		case 3:    /*  P76S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V13 = C_25;  
		if ((!P0V12)&&(P0V13))  Set_State(76, 0);
			break;
		case 4:    /*  P76S4() - СОСТОЯНИЕ: СменаСостоянияВЫК */

		if (P0V82 == C_37) P0V13 = C_25;  
		if ((P0V12) && (P0V13))  Set_State(76, 0);
			break;
		case 5:    /*  P76S5() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(76, 0);
			break;
		default:
			break;
	}
}

void P77 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияРЕГ_Т */
{
	switch (Check_State(77)) {

		case 0:    /*  P77S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V13 = C_25;  
		if ((P0V12 == C_26) && (P0V13)) 
		{
			Set_Start(78);
			P0V35[1] = C_26;
			Set_State(77, 1);
		}
			break;
		case 1:    /*  P77S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_140)) Set_Error(77);
		if (Timeout(77, C_17))  Set_State(77, 2);
			break;
		case 2:    /*  P77S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(77);
			break;
		default:
			break;
	}
}

void P78 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияРЕГ_Т */
{
	switch (Check_State(78)) {

		case 0:    /*  P78S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V13 = C_25;  
		if ((P0V12 == C_25) && (P0V13)) 
		{
			Set_Start(77);
			P0V35[1] = C_25;
			Set_State(78, 1);
		}
			break;
		case 1:    /*  P78S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_139)) Set_Error(78);
		if (Timeout(78, C_17))  Set_State(78, 2);
			break;
		case 2:    /*  P78S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(78);
			break;
		default:
			break;
	}
}

void P79 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_РЕГ_УР */
{
	switch (Check_State(79)) {

		case 0:    /*  P79S0() - СОСТОЯНИЕ: Начало */

		P79V4 = P0V41[1];
		if ((!(Check_State(80) & MASK_OF_INACTIVITY))) Set_Error(80);
		Set_Stop(83);
		P0V41[1] = C_25;
		Set_State(79, 1);
			break;
		case 1:    /*  P79S1() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V15 = C_25;   
		if ((P0V14 == C_25) && (P0V15)){
			Set_Start(82);
		Set_Stop(79);	
		} 
		if (Timeout(79, C_15))  Set_State(79, 2);
			break;
		case 2:    /*  P79S2() - СОСТОЯНИЕ: Ошибка */

		P0V41[1] = P79V4;
		if (SendMsgGUICode(C_98))	Set_Error(79);
		if (Timeout(79, C_17))  Set_State(79, 3);
			break;
		case 3:    /*  P79S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(79);
			break;
		default:
			break;
	}
}

void P80 (void) /* ПРОЦЕСС: ВЫК_ПИТ_РЕГ_УР */
{
	switch (Check_State(80)) {

		case 0:    /*  P80S0() - СОСТОЯНИЕ: Начало */

		P80V4 = P0V41[1];
		if ((!(Check_State(79) & MASK_OF_INACTIVITY))) Set_Error(79);
		Set_Stop(82);
		P0V41[1] = C_26;
		Set_State(80, 1);
			break;
		case 1:    /*  P80S1() - СОСТОЯНИЕ: Контроль */
 
		if (P0V82 == C_37) P0V15 = C_25;    
		if ((P0V14 == C_26) && (P0V15)){
			Set_Start(83);
			Set_Stop(80);	
		} 
		if (Timeout(80, C_15))  	Set_State(80, 2);
			break;
		case 2:    /*  P80S2() - СОСТОЯНИЕ: Ошибка */

		P0V41[1] = P80V4;
		if (SendMsgGUICode(C_99))	Set_Error(80);
		if (Timeout(80, C_17))  Set_State(80, 3);
			break;
		case 3:    /*  P80S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(80);
			break;
		default:
			break;
	}
}

void P81 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияРЕГ_УР */
{
	switch (Check_State(81)) {

		case 0:    /*  P81S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V15 = C_25;  
	    if (P0V15){
			if (P0V14){
				P0V66 = C_25;  Set_State(81, 1);
			}
			else{
				P0V66 = C_26;  	Set_State(81, 2);
			}		
		}
			break;
		case 1:    /*  P81S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_141))  Set_State(81, 3);
		if (Timeout(81, C_17))  Set_State(81, 5);
			break;
		case 2:    /*  P81S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_142))  Set_State(81, 4);
		if (Timeout(81, C_17))  Set_State(81, 5);
			break;
		case 3:    /*  P81S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V15 = C_25;  
		if ((!P0V14)&&(P0V15))  Set_State(81, 0);
			break;
		case 4:    /*  P81S4() - СОСТОЯНИЕ: СменаСостоянияВЫК */

		if (P0V82 == C_37) P0V15 = C_25;  
		if ((P0V14) && (P0V15))  Set_State(81, 0);
			break;
		case 5:    /*  P81S5() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(81, 0);
			break;
		default:
			break;
	}
}

void P82 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияРЕГ_УР */
{
	switch (Check_State(82)) {

		case 0:    /*  P82S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V15 = C_25;  	
		if ((P0V14 == C_26) && (P0V15))
		{
			Set_Start(83);
			P0V41[1] = C_26;
			Set_State(82, 1);
		}
			break;
		case 1:    /*  P82S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_144)) Set_Error(82);
		if (Timeout(82, C_17))  Set_State(82, 2);
			break;
		case 2:    /*  P82S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(82);
			break;
		default:
			break;
	}
}

void P83 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияРЕГ_УР */
{
	switch (Check_State(83)) {

		case 0:    /*  P83S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V15 = C_25;  	
		if ((P0V14 == C_25) && (P0V15))
		{
			Set_Start(82);
			P0V41[1] = C_25;
			Set_State(83, 1);
		}
			break;
		case 1:    /*  P83S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_143)) Set_Error(83);
		if (Timeout(83, C_17))  Set_State(83, 2);
			break;
		case 2:    /*  P83S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(83);
			break;
		default:
			break;
	}
}

void P84 (void) /* ПРОЦЕСС: ВКЛ_ПИТ_НАС_ОХЛ */
{
	switch (Check_State(84)) {

		case 0:    /*  P84S0() - СОСТОЯНИЕ: Начало */

		P84V6 = P0V36[1];
		if ((!(Check_State(85) & MASK_OF_INACTIVITY))) Set_Error(85);
		Set_Stop(88);   
		P0V36[1] = C_25;
		Set_State(84, 1);
			break;
		case 1:    /*  P84S1() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V21 = C_25;  	 
		if ((P0V20 == C_25) && (P0V21)) {
			Set_Start(87);
			Set_Stop(84);	
		} 
	if (Timeout(84, C_16))  Set_State(84, 2);
			break;
		case 2:    /*  P84S2() - СОСТОЯНИЕ: Ошибка */

		P0V36[1] = P84V6;
		if (SendMsgGUICode(C_100))	Set_Error(84);
		if (Timeout(84, C_17))  Set_State(84, 3);
			break;
		case 3:    /*  P84S3() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(84);
			break;
		default:
			break;
	}
}

void P85 (void) /* ПРОЦЕСС: ВЫК_ПИТ_НАС_ОХЛ */
{
	switch (Check_State(85)) {

		case 0:    /*  P85S0() - СОСТОЯНИЕ: Начало */

		P85V4 = P0V36[1];	
		if ((!(Check_State(84) & MASK_OF_INACTIVITY))) Set_Error(84);
		Set_Stop(87);
		P0V36[1] = C_26;
		Set_State(85, 1);
			break;
		case 1:    /*  P85S1() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V21 = C_25;   
		if ((P0V20 == C_26) && (P0V21)) {
			Set_Start(88);
			Set_Stop(85);	
		}
		if (Timeout(85, C_16))  Set_State(85, 2);
			break;
		case 2:    /*  P85S2() - СОСТОЯНИЕ: Ошибка */

		P0V36[1] = P85V4;
		if (SendMsgGUICode(C_101))	Set_Error(85);
		if (Timeout(85, C_17))  Set_State(85, 3);
			break;
		case 3:    /*  P85S3() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(85);
			break;
		default:
			break;
	}
}

void P86 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияНАС_ОХЛ */
{
	switch (Check_State(86)) {

		case 0:    /*  P86S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V21 = C_25;  
	    if (P0V21){
			if (P0V20){
				P0V67 = C_25;  Set_State(86, 1);
			}
			else{
				P0V67 = C_26;  Set_State(86, 2);
			}		
		}
			break;
		case 1:    /*  P86S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_145))  Set_State(86, 3);
		if (Timeout(86, C_17))  Set_State(86, 5);
			break;
		case 2:    /*  P86S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_146))  Set_State(86, 4);
		if (Timeout(86, C_17))  Set_State(86, 5);
			break;
		case 3:    /*  P86S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V21 = C_25;  
		if ((!P0V20)&&(P0V21))  Set_State(86, 0);
			break;
		case 4:    /*  P86S4() - СОСТОЯНИЕ: СменаСостоянияВЫК */

		if (P0V82 == C_37) P0V21 = C_25;  
		if ((P0V20) && (P0V21))  Set_State(86, 0);
			break;
		case 5:    /*  P86S5() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(86, 0);
			break;
		default:
			break;
	}
}

void P87 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияНасосаОхлаждения */
{
	switch (Check_State(87)) {

		case 0:    /*  P87S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V21 = C_25;  
		if ((P0V20 == C_26) && (P0V21))
			{
				Set_Start(88);
				P0V36[1] = C_26;
				Set_State(87, 1);
			}
			break;
		case 1:    /*  P87S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_148)) Set_Error(87);
		if (Timeout(87, C_17))  Set_State(87, 2);
			break;
		case 2:    /*  P87S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(87);
			break;
		default:
			break;
	}
}

void P88 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияНасосаОхлаждения */
{
	switch (Check_State(88)) {

		case 0:    /*  P88S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V21 = C_25;  
		if ((P0V20 == C_25) && (P0V21)) 
		{ 
			Set_Start(87);
			P0V36[1] = C_25;
			Set_State(88, 1);
		}
			break;
		case 1:    /*  P88S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_147)) Set_Error(88);
		if (Timeout(88, C_17))  Set_State(88, 2);
			break;
		case 2:    /*  P88S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(88);
			break;
		default:
			break;
	}
}

void P89 (void) /* ПРОЦЕСС: ВКЛ_УСТР_ПЛАВ_ПУСКА */
{
	switch (Check_State(89)) {

		case 0:    /*  P89S0() - СОСТОЯНИЕ: Начало */

		P89V4 = P0V40[1];
		if ((!(Check_State(90) & MASK_OF_INACTIVITY))) Set_Error(90);
		Set_Stop(93);
		P0V40[1] = C_25;
		Set_State(89, 1);
			break;
		case 1:    /*  P89S1() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V7 = C_25;  	
		if ((P0V6 == C_25) && (P0V7)) {
			Set_Start(92);  
			Set_Stop(89);	
		}
		if (Timeout(89, C_11))   	Set_State(89, 2);
			break;
		case 2:    /*  P89S2() - СОСТОЯНИЕ: Ошибка */

		P0V40[1] = P89V4;
		if (SendMsgGUICode(C_94))	Set_Error(89);
		if (Timeout(89, C_17))  Set_State(89, 3);
			break;
		case 3:    /*  P89S3() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(89);
			break;
		default:
			break;
	}
}

void P90 (void) /* ПРОЦЕСС: ВЫК_УСТР_ПЛАВ_ПУСКА */
{
	switch (Check_State(90)) {

		case 0:    /*  P90S0() - СОСТОЯНИЕ: Начало */

		P90V4 = P0V40[1];	
		if ((!(Check_State(89) & MASK_OF_INACTIVITY))) Set_Error(89);
		Set_Stop(92);	
		P0V40[1] = C_26;	
		Set_State(90, 1);
			break;
		case 1:    /*  P90S1() - СОСТОЯНИЕ: КонтрольВыключения */

		if (P0V82 == C_37) P0V7 = C_25;  	
		if ((P0V6 == C_26) && (P0V7)) {
			Set_Start(93);
			Set_Stop(90);	
		}
		if (Timeout(90, C_11))  	Set_State(90, 2);
			break;
		case 2:    /*  P90S2() - СОСТОЯНИЕ: Ошибка */

		P0V40[1] = P90V4;
		if (SendMsgGUICode(C_95))	Set_Error(90);
		if (Timeout(90, C_17))  Set_State(90, 3);
			break;
		case 3:    /*  P90S3() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(90);
			break;
		default:
			break;
	}
}

void P91 (void) /* ПРОЦЕСС: КонтрольСостоянияПитанияПЛАВ_ПУСКА */
{
	switch (Check_State(91)) {

		case 0:    /*  P91S0() - СОСТОЯНИЕ: Начало */

		if (P0V82 == C_37) P0V7 = C_25;  
	    if (P0V7){
			if (P0V6){
				P0V61 = C_25;  Set_State(91, 1);
			}
			else{
				P0V61 = C_26;  Set_State(91, 2);
			}		
		}
			break;
		case 1:    /*  P91S1() - СОСТОЯНИЕ: ВключенСообщаем */
 
		if (SendMsgGUICode(C_149))  Set_State(91, 3);
		if (Timeout(91, C_17))  Set_State(91, 5);
			break;
		case 2:    /*  P91S2() - СОСТОЯНИЕ: ВыключенСообщаем */
 
		if (SendMsgGUICode(C_150))  Set_State(91, 4);
		if (Timeout(91, C_17))  Set_State(91, 5);
			break;
		case 3:    /*  P91S3() - СОСТОЯНИЕ: СменаСостоянияВКЛ */

		if (P0V82 == C_37) P0V7 = C_25;  
		if ((!P0V6)&&(P0V7))  Set_State(91, 0);
			break;
		case 4:    /*  P91S4() - СОСТОЯНИЕ: СменаСостоянияВЫК */

		if (P0V82 == C_37) P0V7 = C_25;  
		if ((P0V6) && (P0V7))  Set_State(91, 0);
			break;
		case 5:    /*  P91S5() - СОСТОЯНИЕ: НарушениеСвязи */

      Set_State(91, 0);
			break;
		default:
			break;
	}
}

void P92 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВыключенияПлавнПуска */
{
	switch (Check_State(92)) {

		case 0:    /*  P92S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V7 = C_25;  
		if ((P0V6 == C_26) && (P0V7)) 
		{	
			Set_Start(93);
			P0V40[1] = C_26;
			Set_State(92, 1);
		}
			break;
		case 1:    /*  P92S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_152)) Set_Error(92);
		if (Timeout(92, C_17))  Set_State(92, 2);
			break;
		case 2:    /*  P92S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(92);
			break;
		default:
			break;
	}
}

void P93 (void) /* ПРОЦЕСС: КонтрольСпонтанногоВключенияПлавнПуска */
{
	switch (Check_State(93)) {

		case 0:    /*  P93S0() - СОСТОЯНИЕ: Контроль */

		if (P0V82 == C_37) P0V7 = C_25;  
		if ((P0V6 == C_25) && (P0V7)) {
			Set_Start(92);
			P0V40[1] = C_25;
			Set_State(93, 1);
		}
			break;
		case 1:    /*  P93S1() - СОСТОЯНИЕ: Ошибка */

		if (SendMsgGUICode(C_151)) Set_Error(93);
		if (Timeout(93, C_17))  Set_State(93, 2);
			break;
		case 2:    /*  P93S2() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(93);
			break;
		default:
			break;
	}
}

void P94 (void) /* ПРОЦЕСС: ВКЛ_ВАКУУМИРОВАНИЕ_ТРУБЫ */
{
	switch (Check_State(94)) {

		case 0:    /*  P94S0() - СОСТОЯНИЕ: Начало */

	if ((!(Check_State(95) & MASK_OF_INACTIVITY))) Set_Error(95);
	if ((!(Check_State(97) & MASK_OF_INACTIVITY))) Set_Error(97);
	Set_State(94, 1);
			break;
		case 1:    /*  P94S1() - СОСТОЯНИЕ: ПроверкаНеобходимостиВакуумирования */

   if (P0V47 == C_32) Set_Stop(94);  
   
   else {  
	Set_Start(96);    
	Set_State(94, 2);
	}
			break;
		case 2:    /*  P94S2() - СОСТОЯНИЕ: ПередачаСообщения */
 
	if (SendMsgGUICode(C_190)) Set_State(94, 3);
	if (Timeout(94, C_17))  Set_State(94, 16);
			break;
		case 3:    /*  P94S3() - СОСТОЯНИЕ: КонтрольВключенияВакПодсистемы */

		if ( (Check_State(96) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(96) == STATE_OF_ERROR) ) {
				Set_State(94, 11);  
			}
			else
			{
				Set_Start(53);
				Set_State(94, 4);
			}				
		}
			break;
		case 4:    /*  P94S4() - СОСТОЯНИЕ: ЗапоминаемДавлениеВвакуумнойТрубе */

			P94V19 = P0V88;
			Set_State(94, 5);
			break;
		case 5:    /*  P94S5() - СОСТОЯНИЕ: КонтрольДавления */
  
		if (P0V88 < (P0V91 - P0V102) )  {  
 
			Set_Stop(53);
			Set_Start(97);    
			Set_State(94, 6);
		}
		else Set_State(94, 8);
			break;
		case 6:    /*  P94S6() - СОСТОЯНИЕ: КонтрольВыключенияВакПодсистемы */

		if ( (Check_State(97) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(97) == STATE_OF_ERROR) ) {
				Set_State(94, 14);  
			}
			else Set_State(94, 7);
		}
			break;
		case 7:    /*  P94S7() - СОСТОЯНИЕ: СообщениеОКонцеВакуумирования */

		if (SendMsgGUICode(C_108)) Set_Stop(94);  
		if (Timeout(94, C_17))  Set_Error(94);
			break;
		case 8:    /*  P94S8() - СОСТОЯНИЕ: ПаузаНаОткачкуВвакуумнойТрубе */
  

	if (Timeout(94, C_20))  Set_State(94, 9);
			break;
		case 9:    /*  P94S9() - СОСТОЯНИЕ: ПроверкаУменьшенияДавленияВпатрубке */
  
		if(P0V88 < P94V19) Set_State(94, 4);
        else Set_State(94, 10);
			break;
		case 10:    /*  P94S10() - СОСТОЯНИЕ: ОткачкаОтсутствует */

       if (SendMsgGUICode(C_107))	Set_State(94, 11);
      if (Timeout(94, C_17))  Set_State(94, 16);
			break;
		case 11:    /*  P94S11() - СОСТОЯНИЕ: СообщениеОбОтказеВакуумирования */

       if (SendMsgGUICode(C_153))	Set_State(94, 12);
      if (Timeout(94, C_17))  Set_State(94, 16);
			break;
		case 12:    /*  P94S12() - СОСТОЯНИЕ: ВыключенияВакНасоса */

		Set_Start(97);
		Set_State(94, 13);
			break;
		case 13:    /*  P94S13() - СОСТОЯНИЕ: КонтрольВыключенияВакНасоса */

		if ( (Check_State(97) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(97) == STATE_OF_ERROR) ) {
				Set_State(94, 15);  
			}
			else Set_Stop(94);   
		}
			break;
		case 14:    /*  P94S14() - СОСТОЯНИЕ: СообщениеПриНеудачномВыкВакНасоса */

		if (SendMsgGUICode(C_153))	Set_State(94, 15);
		if (Timeout(94, C_17))  Set_State(94, 16);
			break;
		case 15:    /*  P94S15() - СОСТОЯНИЕ: ВыключениеНаЩиткеКнопарями */

    Set_Start(20);
    Set_Error(94);
			break;
		case 16:    /*  P94S16() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(94);
			break;
		default:
			break;
	}
}

void P95 (void) /* ПРОЦЕСС: ВЫК_ВАКУУМИРОВАНИЕ_ТРУБЫ */
{
	switch (Check_State(95)) {

		case 0:    /*  P95S0() - СОСТОЯНИЕ: Начало */

		if ((!(Check_State(94) & MASK_OF_INACTIVITY))) Set_Error(94);  
		if ((!(Check_State(96) & MASK_OF_INACTIVITY)))	Set_Error(96);
		Set_State(95, 1);
			break;
		case 1:    /*  P95S1() - СОСТОЯНИЕ: ПередачаОтладочногоСообщения */
 
	if (SendMsgGUICode(C_60)) Set_State(95, 2);
	if (Timeout(95, C_17))  Set_State(95, 5);
			break;
		case 2:    /*  P95S2() - СОСТОЯНИЕ: АктивенЛиПроцВыключенияВакНасоса */

		if ((Check_State(97) & MASK_OF_INACTIVITY)) {
			Set_Start(97);
			Set_State(95, 3);
		}
		else Set_State(95, 3);
			break;
		case 3:    /*  P95S3() - СОСТОЯНИЕ: ПроверкаВыключенияВакНасоса */

 		if ( (Check_State(97) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(97) == STATE_OF_ERROR) ) {
					if (!((!(Check_State(20) & MASK_OF_INACTIVITY))))	Set_Start(20);
					Set_Error(95);  
				}
				else  Set_State(95, 4);  
		}
			break;
		case 4:    /*  P95S4() - СОСТОЯНИЕ: ПередачаСообщения */
 
		if (SendMsgGUICode(C_191)) Set_Stop(95);
		if (Timeout(95, C_17))  Set_State(95, 5);
			break;
		case 5:    /*  P95S5() - СОСТОЯНИЕ: НарушениеСвязи */
			
	   Set_Error(95);
			break;
		default:
			break;
	}
}

void P96 (void) /* ПРОЦЕСС: ВКЛ_ВАКУУМНЫЙ_НАСОС */
{
	switch (Check_State(96)) {

		case 0:    /*  P96S0() - СОСТОЯНИЕ: Начало */

	
		if ((!(Check_State(97) & MASK_OF_INACTIVITY))) Set_Error(97);  
		
		if (P0V49 != C_32) Set_State(96, 26);
		else Set_State(96, 1);
			break;
		case 1:    /*  P96S1() - СОСТОЯНИЕ: ВключениеПитанияРегУровня */
	  
		Set_Start(79);
		Set_State(96, 2);
			break;
		case 2:    /*  P96S2() - СОСТОЯНИЕ: КонтрольВключенияПитРегУр */
	
		if ( (Check_State(79) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(79) == STATE_OF_ERROR) ) Set_State(96, 26);
				else Set_State(96, 3);
		}
			break;
		case 3:    /*  P96S3() - СОСТОЯНИЕ: КонтрольГотовностиУровняВодыБО */
	
		if (P0V44 == C_32) Set_State(96, 4);
		else Set_State(96, 26);
			break;
		case 4:    /*  P96S4() - СОСТОЯНИЕ: ВключениеРегТ */
 	
		Set_Start(74);   
		Set_State(96, 5);
			break;
		case 5:    /*  P96S5() - СОСТОЯНИЕ: КонтрольВключенияРегТ */
	
		if ( (Check_State(74) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(74) == STATE_OF_ERROR) ) Set_State(96, 26);
				else Set_State(96, 6);
		}
			break;
		case 6:    /*  P96S6() - СОСТОЯНИЕ: КонтрольГотовностиТемпературыВодыБО */

		if (P0V45 == C_32) Set_State(96, 7);
		else Set_State(96, 26);
			break;
		case 7:    /*  P96S7() - СОСТОЯНИЕ: ВключаемВентилятор */

		Set_Start(54);
		Set_State(96, 8);
			break;
		case 8:    /*  P96S8() - СОСТОЯНИЕ: КонтрольВключенияВентилятора */

		if ( (Check_State(54) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(54) == STATE_OF_ERROR) ) Set_State(96, 26);
				else {
					Set_Start(84);   
					Set_State(96, 9);
				}
		}
			break;
		case 9:    /*  P96S9() - СОСТОЯНИЕ: КонтрольВключенияПитанияНасосаОхлаждения */

		if ((Check_State(84) & MASK_OF_INACTIVITY)){ 
				if ((Check_State(84) == STATE_OF_ERROR)) Set_State(96, 26);
				else {
					Set_Start(61);
					Set_State(96, 10);
				}
		}
			break;
		case 10:    /*  P96S10() - СОСТОЯНИЕ: КонтрольЗакрытияЗатвораВакуумного */

		if ((Check_State(61) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(61) == STATE_OF_ERROR) ) Set_State(96, 26);
			else {
				Set_Start(64);
				Set_State(96, 11);
			}
		}
			break;
		case 11:    /*  P96S11() - СОСТОЯНИЕ: КонтрольОткрытияСапуна */

		if ( (Check_State(64) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(64) == STATE_OF_ERROR) ) Set_State(96, 26);
			else Set_State(96, 12);
		}
			break;
		case 12:    /*  P96S12() - СОСТОЯНИЕ: КонтрольТемпературыРубашки */

		if (P0V46 == C_32) Set_State(96, 13);  
		else if (P0V46 == C_33) Set_State(96, 26);
		if (Timeout(96, C_21))  Set_State(96, 26);
			break;
		case 13:    /*  P96S13() - СОСТОЯНИЕ: ПодачаПитанияНаУППвакНасоса */

		Set_Start(69);  
		Set_State(96, 14);
			break;
		case 14:    /*  P96S14() - СОСТОЯНИЕ: КонтрольПодачиПитанияНаУППвакНасоса */

		if ( (Check_State(69) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(69) == STATE_OF_ERROR)) Set_State(96, 26);
			else  Set_State(96, 15);
		}
			break;
		case 15:    /*  P96S15() - СОСТОЯНИЕ: ВключениеУстройстваПлавногоПуска */

		Set_Start(89);
		Set_State(96, 16);
			break;
		case 16:    /*  P96S16() - СОСТОЯНИЕ: КонтрольВключенияПлавногоПуска */

		if ((Check_State(89) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(89) == STATE_OF_ERROR)) Set_State(96, 26);
			else  Set_State(96, 17);
		}
			break;
		case 17:    /*  P96S17() - СОСТОЯНИЕ: ТаймаутПередЗакрытиемСапуна */
  
 		if (Timeout(96, C_18))   Set_State(96, 18);
			break;
		case 18:    /*  P96S18() - СОСТОЯНИЕ: ЗакрытиеСапуна */
  
		Set_Start(65);
		Set_State(96, 19);
			break;
		case 19:    /*  P96S19() - СОСТОЯНИЕ: КонтрольЗакрытияСапуна */

		if ( (Check_State(65) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(65) == STATE_OF_ERROR) ) Set_State(96, 26);
			else Set_State(96, 20);
		}
			break;
		case 20:    /*  P96S20() - СОСТОЯНИЕ: ЗапоминаемДавлениеВпатрубке */

			P96V8 = P0V85;
			Set_State(96, 21);
			break;
		case 21:    /*  P96S21() - СОСТОЯНИЕ: КонтрольДавления */
  
		if (P0V85 <= P0V88) {
			Set_Start(60); 
			Set_State(96, 24);
		}
		else Set_State(96, 22);
			break;
		case 22:    /*  P96S22() - СОСТОЯНИЕ: ПаузаНаОткачкуВпатрубке */
  
 
		if (Timeout(96, C_3))  Set_State(96, 23);
			break;
		case 23:    /*  P96S23() - СОСТОЯНИЕ: ПроверкаУменьшенияДавленияВпатрубке */
  
		if(P0V85 < P96V8) Set_State(96, 20);
        else Set_State(96, 25);
			break;
		case 24:    /*  P96S24() - СОСТОЯНИЕ: КонтрольОткрытияЗВ */

		if ( (Check_State(60) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(60) == STATE_OF_ERROR) ) Set_State(96, 26);
			else { 
					
				
				Set_Stop(96);
			}
		}
			break;
		case 25:    /*  P96S25() - СОСТОЯНИЕ: НетОткачки */

       if (SendMsgGUICode(C_106))	Set_State(96, 26);
      if (Timeout(96, C_17))  Set_State(96, 27);
			break;
		case 26:    /*  P96S26() - СОСТОЯНИЕ: СообщениеОбОтказеВакуумирования */

       if (SendMsgGUICode(C_154))	Set_Error(96);
      if (Timeout(96, C_17))  Set_State(96, 27);
			break;
		case 27:    /*  P96S27() - СОСТОЯНИЕ: НарушениеСвязи */

	   Set_Error(96);
			break;
		default:
			break;
	}
}

void P97 (void) /* ПРОЦЕСС: ВЫК_ВАКУУМНЫЙ_НАСОС */
{
	switch (Check_State(97)) {

		case 0:    /*  P97S0() - СОСТОЯНИЕ: Начало */

		P97V0 = 0;   

		if ((!(Check_State(96) & MASK_OF_INACTIVITY))) Set_Error(96);
		 
 		Set_Start(61);
		Set_Stop(43);
		Set_State(97, 1);
			break;
		case 1:    /*  P97S1() - СОСТОЯНИЕ: ПередачаОтладочногоСообщения */
 
		if (SendMsgGUICode(C_61)) Set_State(97, 2);
		if (Timeout(97, C_17))  Set_State(97, 16);
			break;
		case 2:    /*  P97S2() - СОСТОЯНИЕ: КонтрольЗакрытияЗатвораВакуумного */

		if ((Check_State(61) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(61) == STATE_OF_ERROR) ) {
			
				Set_State(97, 15);
			}
			else Set_State(97, 3);
		}
			break;
		case 3:    /*  P97S3() - СОСТОЯНИЕ: ОткрытьСапун */

		Set_Start(64);
		Set_State(97, 4);
			break;
		case 4:    /*  P97S4() - СОСТОЯНИЕ: КонтрольОткрытияСапуна */

		if ((Check_State(64) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(64) == STATE_OF_ERROR) ) {
				P97V0 = 1;
				Set_State(97, 6);
			}
			else Set_State(97, 5);
		}
			break;
		case 5:    /*  P97S5() - СОСТОЯНИЕ: ТаймаутПередВыключениемПитанияВакуумногоНасоса */
  
		if (Timeout(97, C_8))  Set_State(97, 6);
			break;
		case 6:    /*  P97S6() - СОСТОЯНИЕ: ВыключаемУстройствоПлавногоПуска */
  
		Set_Start(90); Set_State(97, 7);
			break;
		case 7:    /*  P97S7() - СОСТОЯНИЕ: КонтрольВыключенияПлавногоПуска */
  
		if ((Check_State(90) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(90) == STATE_OF_ERROR) ) 	P97V0 = 1;
			Set_State(97, 8);
		}
			break;
		case 8:    /*  P97S8() - СОСТОЯНИЕ: ВыключаемПитаниеПлавногоПуска */
  
		Set_Start(70); Set_State(97, 9);
			break;
		case 9:    /*  P97S9() - СОСТОЯНИЕ: КонтрольВыключенияПитанияПлавногоПуска */
  
		if ((Check_State(70) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(70) == STATE_OF_ERROR) ) 	P97V0 = 1;
			Set_State(97, 10);
		}
			break;
		case 10:    /*  P97S10() - СОСТОЯНИЕ: ВыключаемПитаниеНасосаОхлаждения */
  
		Set_Start(85); Set_State(97, 11);
			break;
		case 11:    /*  P97S11() - СОСТОЯНИЕ: КонтрольВыключенияНасосаОхлаждения */
  
		if ((Check_State(85) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(85) == STATE_OF_ERROR) ) 	P97V0 = 1;
			Set_State(97, 12);
		}
			break;
		case 12:    /*  P97S12() - СОСТОЯНИЕ: ВыключаемВентилятор */
  
		Set_Start(55); Set_State(97, 13);
			break;
		case 13:    /*  P97S13() - СОСТОЯНИЕ: КонтрольВыключенияВентилятора */
  
		if ((Check_State(55) & MASK_OF_INACTIVITY)){ 
			if ((Check_State(55) == STATE_OF_ERROR) ) 	P97V0 = 1;
			Set_State(97, 14);
		}
			break;
		case 14:    /*  P97S14() - СОСТОЯНИЕ: АнализПризнакаОшибки */
 
		if (P97V0 == 1) Set_State(97, 15);  
		else Set_Stop(97);
			break;
		case 15:    /*  P97S15() - СОСТОЯНИЕ: СообщениеОбОтказеВыклВакСистемы */

		if (SendMsgGUICode(C_155))	Set_Error(97);
		if (Timeout(97, C_17))  Set_State(97, 16);
			break;
		case 16:    /*  P97S16() - СОСТОЯНИЕ: НарушениеСвязи */

		Set_Error(97);
			break;
		default:
			break;
	}
}
