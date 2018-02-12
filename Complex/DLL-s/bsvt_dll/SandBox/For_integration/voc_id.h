enum EN0 {
	KOM_TYEST_GUI_NACHAL_NOYE_DAVLYENIYE_V_TRUBYE_SIDYEROSTATA /* ���_����_���_���������_��������_�_�����_����������� */,
	KOM_TYEST_GUI_NACHAL_NOYE_DAVLYENIYE_V_PATRUBKYE /* ���_����_���_���������_��������_�_�������� */,
	KOM_TYEST_GUI_NACHAL_NAYA_TYEMPYERATURA_V_BAKYE /* ���_����_���_���������_�����������_�_���� */, 
	KOM_TYEST_GUI_TYEMPYERATURA_OKRUZHAYUSCHYEJ_SRYEDY /* ���_����_���_�����������_����������_����� */,
	KOM_TYEST_GUI_UROVYEN__VODY_MIN /* ���_����_���_�������_����_MIN */,
	KOM_TYEST_GUI_UROVYEN__VODY_MAX /* ���_����_���_�������_����_MAX */,
	KOM_TYEST_GUI_UROVYEN__VODY_NORM /* ���_����_���_�������_����_���� */

};

enum EN1 {
     PK_TYEST_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ��_����_���_������_����_�������_��_��� */ = KOM_TYEST_GUI_TYEMPYERATURA_OKRUZHAYUSCHYEJ_SRYEDY + 1,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_IZMYENILAS_ /* ��_����_���_�����������_����_�_����_���������� */,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_IZMYENILAS_ /* ��_����_���_�����������_����_�_�������_���������� */,
	 PK_TYEST_GUI_TYEMPYERATURA_NASOSA_IZMYENILAS_ /* ��_����_���_�����������_������_���������� */,
	 PK_TYEST_GUI_VODA_V_BAKYE_ZAKIPYELA /* ��_����_���_����_�_����_�������� */,
	 PK_TYEST_GUI_VODA_V_BAKYE_ZAMYERZLA /* ��_����_���_����_�_����_�������� */,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_SLISHKOM_VYSOKAYA /* ��_����_���_�����������_����_�_����_�������_������� */,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_SLISHKOM_NIZKAYA /* ��_����_���_�����������_����_�_����_�������_������ */,
	 PK_TYEST_GUI_TYEMPYERATURA_OKUZHAYUSCHYEJ_SRYEDY_IZMYENILAS_ /* ��_����_���_�����������_���������_�����_���������� */,
	 PK_TYEST_GUI_TYEMPYERATURA_OKUZHAYUSCHYEJ_SRYEDY_SLISHKOM_VYSOKAYA /* ��_����_���_�����������_���������_�����_�������_������� */,
	 PK_TYEST_GUI_TYEMPYERATURA_OKUZHAYUSCHYEJ_SRYEDY_SLISHKOM_NIZKAYA /* ��_����_���_�����������_���������_�����_�������_������ */,
	 PK_TYEST_GUI_UROVYEN__VODY_NORM /* ��_����_���_�������_����_���� */,
	 PK_TYEST_GUI_UROVYEN__VODY_MAX /* ��_����_���_�������_����_MAX */,
	 PK_TYEST_GUI_UROVYEN__VODY_MIN /* ��_����_���_�������_����_MIN */,
	 
	 PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SIDYEROSTATA_IZMYENILOS_ /* ��_����_���_��������_�_�����_�����������_���������� */, 
	 PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SLISHKOM_VYSOKOYE /* ��_����_���_��������_�_�����_�������_������� */,
	 PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SLISHKOM_NIZKOYE /* ��_����_���_��������_�_�����_�������_������ */,
	 
	 PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_IZMYENILOS_ /* ��_����_���_��������_�_��������_���������� */, 
	 PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_SLISHKOM_VYSOKOYE /* ��_����_���_��������_�_��������_�������_������� */,
	 PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_SLISHKOM_NIZKOYE /* ��_����_���_��������_�_��������_�������_������ */,
	 
	 PK_TYEST_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_IZMYENILOS_ /* ��_����_���_��������_�_����_�����������_���������� */,
	 PK_TYEST_GUI_DAVLYENIYE_V_KOMPRYESSORYE_SLISHKOM_NIZKOYE /* ��_����_���_��������_�_�����������_�������_������ */,
	 
	 PK_TYEST_GUI_OSHIBKA_POPYTKA_OTKRYT__SAPUN_PRI_OTKRYTOM_ZATVORYE /* ��_����_���_������_�������_�������_�����_���_��������_������� */,
	 PK_TYEST_GUI_OSHIBKA_POPYTKA_OTKRYT__ZATVOR_PRI_OTKRYTOM_SAPUNYE /* ��_����_���_������_�������_�������_������_���_��������_������ */,
	 PK_TYEST_GUI_OSHIBKA_DAVLYENIYE_PATRUBKA_VYSHYE_DAVLYENIYA_TRUBY /* ��_����_���_������_��������_��������_����_��������_����� */,
	 PK_TYEST_GUI_OSHIBKA_VKLYUCHYENIYE_NAGRYEVA_PRI_NIZKOM_UROVNYE_VODY /* ��_����_���_������_���������_�������_���_������_������_���� */,
	 PK_TYEST_GUI_POPYTKA_ZAPUSKA_USTR_PLAV_PUSKA_BYEZ_PITANIYA /* ��_����_���_�������_�������_����_����_�����_���_������� */,
	 PK_TYEST_GUI_OSHIBKA_VKLYUCHYENIYE_NASOSA_OKHL_PRI_NIZKOM_UROVNYE_VODY /* ��_����_���_������_���������_������_���_���_������_������_���� */,
	 PK_TYEST_GUI_OSHIBKA_PYERYEGRYEV_VAK_NASOSA /* ��_����_���_������_��������_���_������ */

}; 