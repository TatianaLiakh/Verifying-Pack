//bvz #include "IO_arrays.h"
#include "r_io.h"
#include "R_CNST.h" 

/*
*    ���� ������������ ���������� ��������� �������������
*    � ���������������� ������������� (�������������) ��������
*    �� ������ ������� �����/������.
*    ��������� ����� ���������� � ������ �������� �� ������ ������������
*    ������
*    ��������, ��� ����� ������� ����� � �������� � ISA �� PCI, ��� c
*    Multibus �� VME.
*    ���� ������������� ��������� ����� ���������� ��� �����
*    ������������ �������
*/


/*
*    ���������� ��� ����, ��� ����� ����������� ����� ������� Input � Output (int)
     SignalType (��� �������: 0 -- ����, 1 -- �����), 
     SignalAddress -- ����� �������� � �������,
     _DO -- �������� ����� ��� ������        
*/

unsigned char INBYTE(unsigned int SignalType, unsigned int SignalAddress)
{
	if (SignalType == 0)     // ������ ������ ?  
                return (aInput[SignalAddress]);
    else return (aOutput[SignalAddress]);
}

unsigned int OUTBYTE(unsigned int SignalType, unsigned int SignalAddress, unsigned char _DO)
{
	if (SignalType == 1)
	{
        aOutput[SignalAddress] = ~_DO; //
		return 1;
	}
	else return 0;
}
