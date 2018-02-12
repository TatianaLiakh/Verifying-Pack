enum EN0 {
	KOM_TYEST_GUI_NACHAL_NOYE_DAVLYENIYE_V_TRUBYE_SIDYEROSTATA /* йнл_реяр_цсх_мювюкэмне_дюбкемхе_б_рпсае_яхдепнярюрю */,
	KOM_TYEST_GUI_NACHAL_NOYE_DAVLYENIYE_V_PATRUBKYE /* йнл_реяр_цсх_мювюкэмне_дюбкемхе_б_оюрпсайе */,
	KOM_TYEST_GUI_NACHAL_NAYA_TYEMPYERATURA_V_BAKYE /* йнл_реяр_цсх_мювюкэмюъ_релоепюрспю_б_аюйе */, 
	KOM_TYEST_GUI_TYEMPYERATURA_OKRUZHAYUSCHYEJ_SRYEDY /* йнл_реяр_цсх_релоепюрспю_нйпсфючыеи_япедш */,
	KOM_TYEST_GUI_UROVYEN__VODY_MIN /* йнл_реяр_цсх_спнбемэ_бндш_MIN */,
	KOM_TYEST_GUI_UROVYEN__VODY_MAX /* йнл_реяр_цсх_спнбемэ_бндш_MAX */,
	KOM_TYEST_GUI_UROVYEN__VODY_NORM /* йнл_реяр_цсх_спнбемэ_бндш_мнпл */

};

enum EN1 {
     PK_TYEST_GUI_OSHIBKA_KODA_KOMANDY_OT_GUI /* ой_реяр_цсх_ньхайю_йндю_йнлюмдш_нр_цсх */ = KOM_TYEST_GUI_TYEMPYERATURA_OKRUZHAYUSCHYEJ_SRYEDY + 1,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_IZMYENILAS_ /* ой_реяр_цсх_релоепюрспю_бндш_б_аюйе_хглемхкюяэ */,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_IZMYENILAS_ /* ой_реяр_цсх_релоепюрспю_бндш_б_псаюьйе_хглемхкюяэ */,
	 PK_TYEST_GUI_TYEMPYERATURA_NASOSA_IZMYENILAS_ /* ой_реяр_цсх_релоепюрспю_мюяняю_хглемхкюяэ */,
	 PK_TYEST_GUI_VODA_V_BAKYE_ZAKIPYELA /* ой_реяр_цсх_бндю_б_аюйе_гюйхоекю */,
	 PK_TYEST_GUI_VODA_V_BAKYE_ZAMYERZLA /* ой_реяр_цсх_бндю_б_аюйе_гюлепгкю */,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_SLISHKOM_VYSOKAYA /* ой_реяр_цсх_релоепюрспю_бндш_б_аюйе_якхьйнл_бшянйюъ */,
	 PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_SLISHKOM_NIZKAYA /* ой_реяр_цсх_релоепюрспю_бндш_б_аюйе_якхьйнл_мхгйюъ */,
	 PK_TYEST_GUI_TYEMPYERATURA_OKUZHAYUSCHYEJ_SRYEDY_IZMYENILAS_ /* ой_реяр_цсх_релоепюрспю_нйсфючыеи_япедш_хглемхкюяэ */,
	 PK_TYEST_GUI_TYEMPYERATURA_OKUZHAYUSCHYEJ_SRYEDY_SLISHKOM_VYSOKAYA /* ой_реяр_цсх_релоепюрспю_нйсфючыеи_япедш_якхьйнл_бшянйюъ */,
	 PK_TYEST_GUI_TYEMPYERATURA_OKUZHAYUSCHYEJ_SRYEDY_SLISHKOM_NIZKAYA /* ой_реяр_цсх_релоепюрспю_нйсфючыеи_япедш_якхьйнл_мхгйюъ */,
	 PK_TYEST_GUI_UROVYEN__VODY_NORM /* ой_реяр_цсх_спнбемэ_бндш_мнпл */,
	 PK_TYEST_GUI_UROVYEN__VODY_MAX /* ой_реяр_цсх_спнбемэ_бндш_MAX */,
	 PK_TYEST_GUI_UROVYEN__VODY_MIN /* ой_реяр_цсх_спнбемэ_бндш_MIN */,
	 
	 PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SIDYEROSTATA_IZMYENILOS_ /* ой_реяр_цсх_дюбкемхе_б_рпсае_яхдепнярюрю_хглемхкняэ */, 
	 PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SLISHKOM_VYSOKOYE /* ой_реяр_цсх_дюбкемхе_б_рпсае_якхьйнл_бшянйне */,
	 PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SLISHKOM_NIZKOYE /* ой_реяр_цсх_дюбкемхе_б_рпсае_якхьйнл_мхгйне */,
	 
	 PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_IZMYENILOS_ /* ой_реяр_цсх_дюбкемхе_б_оюрпсайе_хглемхкняэ */, 
	 PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_SLISHKOM_VYSOKOYE /* ой_реяр_цсх_дюбкемхе_б_оюрпсайе_якхьйнл_бшянйне */,
	 PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_SLISHKOM_NIZKOYE /* ой_реяр_цсх_дюбкемхе_б_оюрпсайе_якхьйнл_мхгйне */,
	 
	 PK_TYEST_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_IZMYENILOS_ /* ой_реяр_цсх_дюбкемхе_б_аюйе_йнлопеяянпю_хглемхкняэ */,
	 PK_TYEST_GUI_DAVLYENIYE_V_KOMPRYESSORYE_SLISHKOM_NIZKOYE /* ой_реяр_цсх_дюбкемхе_б_йнлопеяянпе_якхьйнл_мхгйне */,
	 
	 PK_TYEST_GUI_OSHIBKA_POPYTKA_OTKRYT__SAPUN_PRI_OTKRYTOM_ZATVORYE /* ой_реяр_цсх_ньхайю_оношрйю_нрйпшрэ_яюосм_опх_нрйпшрнл_гюрбнпе */,
	 PK_TYEST_GUI_OSHIBKA_POPYTKA_OTKRYT__ZATVOR_PRI_OTKRYTOM_SAPUNYE /* ой_реяр_цсх_ньхайю_оношрйю_нрйпшрэ_гюрбнп_опх_нрйпшрнл_яюосме */,
	 PK_TYEST_GUI_OSHIBKA_DAVLYENIYE_PATRUBKA_VYSHYE_DAVLYENIYA_TRUBY /* ой_реяр_цсх_ньхайю_дюбкемхе_оюрпсайю_бшье_дюбкемхъ_рпсаш */,
	 PK_TYEST_GUI_OSHIBKA_VKLYUCHYENIYE_NAGRYEVA_PRI_NIZKOM_UROVNYE_VODY /* ой_реяр_цсх_ньхайю_бйкчвемхе_мюцпебю_опх_мхгйнл_спнбме_бндш */,
	 PK_TYEST_GUI_POPYTKA_ZAPUSKA_USTR_PLAV_PUSKA_BYEZ_PITANIYA /* ой_реяр_цсх_оношрйю_гюосяйю_сярп_окюб_осяйю_аег_охрюмхъ */,
	 PK_TYEST_GUI_OSHIBKA_VKLYUCHYENIYE_NASOSA_OKHL_PRI_NIZKOM_UROVNYE_VODY /* ой_реяр_цсх_ньхайю_бйкчвемхе_мюяняю_нук_опх_мхгйнл_спнбме_бндш */,
	 PK_TYEST_GUI_OSHIBKA_PYERYEGRYEV_VAK_NASOSA /* ой_реяр_цсх_ньхайю_оепецпеб_бюй_мюяняю */

}; 