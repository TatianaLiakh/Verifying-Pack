
#define VKL /* C_0 - ��� */ 1
#define VYKL /* C_1 - ���� */ 0
#define OzhidaniyeOtvyetaOtAlgoritma /* C_2 - ������������������������� */ 10
#define ZadyerzhkaOb_yekta /* C_3 - ��������������� */ 10

enum EN0 {
	KOM2AU_V_RUCHNOYE_UPRAVLYENIYE /* ���2��_�_������_���������� */,
	KOM2AU_OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE /* ���2��_���������_������_���������� */,
	KOM2AU_VKLYUCHIT__SUSHILKU /* ���2��_��������_������� */,
	KOM2AU_VYKLYUCHIT__SUSHILKU /* ���2��_���������_������� */

};

enum EN1 {
	AU2GUI_YEST__SUSHILKA_V_RUCHNOYE_UPRAVLYENIYE /* ��2���_����_�������_�_������_���������� */,
	AU2GUI_YEST__OTKLYUCHIT__RUCHNOYE_UPRAVLYENIYE /* ��2���_����_���������_������_���������� */,
	AU2GUI_SUSHILKA_VYKLYUCHYENA /* ��2���_�������_��������� */,
	AU2GUI_SUSHILKA_VKLYUCHYENA /* ��2���_�������_�������� */

};

 
 enum EN2 {
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VKLYUCHYENIYE /* ���2��_������_����������_��������� */,
	BUS2BV_RUCHNOYE_UPRAVLYENIYE_VYKLYUCHYENIYE /* ���2��_������_����������_���������� */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_POMYESCHYENY /* ���2��_��������������_����������_����_�������� */,
	BUS2BV_AVTOMATICHYESKOYE_UPRAVLYENIYE_RUKI_UBRANY /* ���2��_��������������_����������_����_������ */,
	BUS2BV_KONYETS_SHTANOGO_RYEZHIMA /* ���2��_�����_�������_������ */	
	
};

enum EN3 {
	BV2BUS_SLYEDUYUSCHIJ_STSYENARIJ /* ��2���_���������_�������� */,
	BV2BUS_OSHIBKA_OSTANOV /* ��2���_������_������� */

};

enum EN4 {
	BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno /* ��2���_��������������������������������� */,
	BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaUspyeshno /* ��2���_���������������������������������� */,
	BV2GOO_VklyuchyeniyeAvtomatichyeskoyeUspyeshno /* ��2���_������������������������������ */,
	BV2GOO_VyklyuchyeniyeAvtomatichyeskoyeUspyeshno /* ��2���_������������������������������� */,
	BV2GOO_ /* ��2���_ */

};

enum EN5 {
	BV2GOO_VklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno /* ��2���_����������������������������������� */ = BV2GOO_ + 1,
	BV2GOO_VyklyuchyeniyeRuchnogoUpravlyeniyaNYEUspyeshno /* ��2���_������������������������������������ */,
	BV2GOO_Samoproizvol_noyeOtklyuchyeniyeRyezhimaRuchnogoUpravlyeniya /* ��2���_������������������������������������������������� */,
	BV2GOO_Samoproizvol_noyeVklyuchyeniyeRyezhimaRuchnogoUpravlyeniya /* ��2���_������������������������������������������������ */,
	BV2GOO_OSHIBKA_Samoproizvol_noyeVyklyuchyeniyeVavtomatRyezhimye /* ��2���_������_���������������������������������������� */,
	BV2GOO_OSHIBKA_Samoproizvol_noyeVklyuchyeniyeVavtomatRyezhimye /* ��2���_������_��������������������������������������� */

};