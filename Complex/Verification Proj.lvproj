<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="10008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="DLL Tests" Type="Folder">
			<Item Name="array_resize_test.vi" Type="VI" URL="../src/Dll interaction lib/array_resize_test.vi"/>
			<Item Name="InitTest.vi" Type="VI" URL="../DLL-s/MakeFullImmitationStepDLL/Release/InitTest.vi"/>
			<Item Name="libs_loader.vi" Type="VI" URL="../src/libs_loader.vi"/>
			<Item Name="NumericArrayResizeTest.vi" Type="VI" URL="../DLL-s/MakeFullImmitationStepDLL/Release/NumericArrayResizeTest.vi"/>
			<Item Name="ParserTest.vi" Type="VI" URL="../src/Parsers/ParserTest.vi"/>
			<Item Name="simple_test.vi" Type="VI" URL="../src/Dll interaction lib/simple_test.vi"/>
			<Item Name="test log.vi" Type="VI" URL="../src/Dll interaction lib/test log.vi"/>
			<Item Name="test refnum.vi" Type="VI" URL="../src/Dll interaction lib/test refnum.vi"/>
			<Item Name="Untitled 2.vi" Type="VI" URL="../src/Untitled 2.vi"/>
		</Item>
		<Item Name="Lib" Type="Folder">
			<Item Name="Ports.lvclass" Type="LVClass" URL="../src/lib/Ports.lvclass"/>
		</Item>
		<Item Name="Sandbox" Type="Folder">
			<Item Name="DllDriver.vi" Type="VI" URL="../src/lib/DllDriver.vi"/>
			<Item Name="testDLLCall.vi" Type="VI" URL="../src/Dll interaction lib/testDLLCall.vi"/>
		</Item>
		<Item Name="src" Type="Folder">
			<Item Name="CFGParser" Type="Folder">
				<Item Name="Load ALL Ports.vi" Type="VI" URL="../src/lib/Load ALL Ports.vi"/>
				<Item Name="ParceCFG.vi" Type="VI" URL="../src/ParceCFG.vi"/>
				<Item Name="ParseStates.vi" Type="VI" URL="../src/Parsers/ParseStates.vi"/>
			</Item>
			<Item Name="DLL call lib" Type="Folder">
				<Item Name="Call DLLs.vi" Type="VI" URL="../src/Dll interaction lib/Call DLLs.vi"/>
			</Item>
			<Item Name="Event Driven Agorithmic Blocks" Type="Folder">
				<Item Name="CA.vi" Type="VI" URL="../src/CA.vi"/>
				<Item Name="SCB.vi" Type="VI" URL="../src/SCB.vi"/>
				<Item Name="Template.vi" Type="VI" URL="../src/Template.vi"/>
				<Item Name="VP.vi" Type="VI" URL="../src/VP.vi"/>
			</Item>
			<Item Name="Main.vi" Type="VI" URL="../src/Main.vi"/>
		</Item>
		<Item Name="CheckCurrentStatesControl.vi" Type="VI" URL="../src/CheckCurrentStatesControl.vi"/>
		<Item Name="CheckPortsArray.vi" Type="VI" URL="../src/CheckPortsArray.vi"/>
		<Item Name="Create FOLDER.vi" Type="VI" URL="../src/lib/Create FOLDER.vi"/>
		<Item Name="Create Progect.vi" Type="VI" URL="../EDB/CA/Create Progect.vi"/>
		<Item Name="InitDLLs.vi" Type="VI" URL="../src/Dll interaction lib/InitDLLs.vi"/>
		<Item Name="LastStepMsgParser.vi" Type="VI" URL="../src/Parsers/LastStepMsgParser.vi"/>
		<Item Name="ParseAllBlocksMessages.vi" Type="VI" URL="../src/Parsers/ParseAllBlocksMessages.vi"/>
		<Item Name="ParseAllVarsFile.vi" Type="VI" URL="../src/Parsers/ParseAllVarsFile.vi"/>
		<Item Name="RunTimeMenu.rtm" Type="Document" URL="../src/RunTimeMenu.rtm"/>
		<Item Name="UdatePortsCluster.vi" Type="VI" URL="../src/Parsers/UdatePortsCluster.vi"/>
		<Item Name="Vars.vi" Type="VI" URL="../src/Parsers/Vars.vi"/>
		<Item Name="VP CA LOAD.vi" Type="VI" URL="../src/lib/VP CA LOAD.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Application Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Application Directory.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="comparison.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/comparison.ctl"/>
				<Item Name="compatCalcOffset.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatCalcOffset.vi"/>
				<Item Name="compatFileDialog.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatFileDialog.vi"/>
				<Item Name="compatOpenFileOperation.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatOpenFileOperation.vi"/>
				<Item Name="DWDT Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDTOps.llb/DWDT Error Code.vi"/>
				<Item Name="Dynamic To Waveform Array.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/Dynamic To Waveform Array.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="ex_CorrectErrorChain.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_CorrectErrorChain.vi"/>
				<Item Name="ex_Modify Signal Name.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_Modify Signal Name.vi"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="Open_Create_Replace File.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/Open_Create_Replace File.vi"/>
				<Item Name="Space Constant.vi" Type="VI" URL="/&lt;vilib&gt;/dlg_ctls.llb/Space Constant.vi"/>
				<Item Name="subComparison.vi" Type="VI" URL="/&lt;vilib&gt;/express/express arith-compare/ComparisonBlock.llb/subComparison.vi"/>
				<Item Name="subFile Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/express/express input/FileDialogBlock.llb/subFile Dialog.vi"/>
				<Item Name="System Exec.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/System Exec.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="Waveform Array To Dynamic.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/Waveform Array To Dynamic.vi"/>
				<Item Name="Waveform Scalar Limit Comparison.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/Waveform Scalar Limit Comparison.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
			<Item Name="AnalyzePortsHeader.vi" Type="VI" URL="../src/Parsers/AnalyzePortsHeader.vi"/>
			<Item Name="ConfFileParser.vi" Type="VI" URL="../src/Parsers/ConfFileParser.vi"/>
			<Item Name="FormVarValuesArray.vi" Type="VI" URL="../src/lib/FormVarValuesArray.vi"/>
			<Item Name="Loader.dll" Type="Document" URL="../src/Loader.dll"/>
			<Item Name="MakeFullImmitationStepDLL.dll" Type="Document" URL="../DLL-s/MakeFullImmitationStepDLL/Release/MakeFullImmitationStepDLL.dll"/>
			<Item Name="MsgCfgParser.vi" Type="VI" URL="../src/Parsers/MsgCfgParser.vi"/>
			<Item Name="new_bsvt_test.dll" Type="Document" URL="../DLL-s/new_bsvt_test/Debug/new_bsvt_test.dll"/>
			<Item Name="ParseVarFile.vi" Type="VI" URL="../src/Parsers/ParseVarFile.vi"/>
			<Item Name="ProcAndStates.vi" Type="VI" URL="../src/Parsers/ProcAndStates.vi"/>
			<Item Name="PSConverter.vi" Type="VI" URL="../Old debug progs/2009NewDebugProg Folder/lib/PSConverter.vi"/>
			<Item Name="ReadPortsHeader.vi" Type="VI" URL="../Old debug progs/2009NewDebugProg Folder/lib/ReadPortsHeader.vi"/>
			<Item Name="test.dll" Type="Document" URL="../DLL-s/test/Debug/test.dll"/>
			<Item Name="VB.dll" Type="Document" URL="../../../../VB.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
