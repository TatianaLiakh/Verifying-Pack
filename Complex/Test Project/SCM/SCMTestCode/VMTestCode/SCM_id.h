
#define VKL /* C_0 - ��� */                1
#define VYKL /* C_1 - ���� */               0
#define VryemyaNaOtklik /* C_2 - ������������� */		1000

 

 enum EN0 {
	BUS2VOU_POMYESTIT__RUKI /* ���2���_���������_���� */,
	BUS2VOU_UBRAT__RUKI /* ���2���_������_���� */,
	BUS2VOU_SLOMAT__SUSHILKU /* ���2���_�������_������� */,
	BUS2VOU_SUSHILKA_RABOTAYET /* ���2���_�������_�������� */
 
 };
 
 
 enum EN1 {
	BUS2AU_V_RUCHNOYE_UPRAVLYENIYE /* ���2��_�_������_���������� */,
	BUS2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE /* ���2��_���������_������_���������� */,
	BUS2AU_VKLYUCHIT__SUSHILKU /* ���2��_��������_������� */,
	BUS2AU_VYKLYUCHIT__SUSHILKU /* ���2��_���������_������� */

};

 
  enum EN2 {
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE /* ���2��_������_����������_��������� */,
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE /* ���2��_������_����������_���������� */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY /* ���2��_��������������_����������_����_�������� */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY /* ���2��_��������������_����������_����_������ */,
	BUS2BV_KONYETS_SHTANOGO_RYEZHIMA /* ���2��_�����_�������_������ */	
	
};

enum EN3 {
	BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE /* ���2��_�������������_������_����������_��������� */ = BUS2BV_KONYETS_SHTANOGO_RYEZHIMA + 1,
	BUS2BV_NYEISPRAVNOST__RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE /* ���2��_�������������_������_����������_���������� */,
	BUS2BV_NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY /* ���2��_�������������_��������������_����������_����_�������� */,
	BUS2BV_NYEISPRAVNOST__NYEISPRAVNOST__AVTOMATICHYESKOYE_UPRAVLYENIYE_RU /* ���2��_�������������_�������������_��������������_����������_�� */

};