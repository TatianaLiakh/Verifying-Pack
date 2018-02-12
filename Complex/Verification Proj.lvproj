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
			<Item Name="simple_test.vi" Type="VI" URL="../src/Dll interaction lib/simple_test.vi"/>
			<Item Name="test log.vi" Type="VI" URL="../src/Dll interaction lib/test log.vi"/>
			<Item Name="test refnum.vi" Type="VI" URL="../src/Dll interaction lib/test refnum.vi"/>
			<Item Name="Untitled 2.vi" Type="VI" URL="../src/Untitled 2.vi"/>
		</Item>
		<Item Name="Lib" Type="Folder">
			<Item Name="Ports.lvclass" Type="LVClass" URL="../src/lib/Ports.lvclass"/>
		</Item>
		<Item Name="Sandbox" Type="Folder">
			<Item Name="testDLLCall.vi" Type="VI" URL="../src/Dll interaction lib/testDLLCall.vi"/>
		</Item>
		<Item Name="src" Type="Folder">
			<Item Name="DLL call lib" Type="Folder">
				<Item Name="Call DLLs.vi" Type="VI" URL="../src/Dll interaction lib/Call DLLs.vi"/>
			</Item>
			<Item Name="Event Driven Agorithmic Blocks" Type="Folder">
				<Item Name="DllDriver.vi" Type="VI" URL="../src/lib/DllDriver.vi"/>
				<Item Name="SCB.vi" Type="VI" URL="../src/SCB.vi"/>
				<Item Name="Template.vi" Type="VI" URL="../src/Template.vi"/>
				<Item Name="VP.vi" Type="VI" URL="../src/VP.vi"/>
			</Item>
			<Item Name="Main.vi" Type="VI" URL="../src/Main.vi"/>
		</Item>
		<Item Name="InitDLLs.vi" Type="VI" URL="../src/Dll interaction lib/InitDLLs.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Application Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Application Directory.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="System Exec.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/System Exec.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
			<Item Name="Loader.dll" Type="Document" URL="../src/Loader.dll"/>
			<Item Name="MakeFullImmitationStepDLL.dll" Type="Document" URL="../DLL-s/MakeFullImmitationStepDLL/Release/MakeFullImmitationStepDLL.dll"/>
			<Item Name="new_bsvt_test.dll" Type="Document" URL="../DLL-s/new_bsvt_test/Debug/new_bsvt_test.dll"/>
			<Item Name="test.dll" Type="Document" URL="../DLL-s/test/Debug/test.dll"/>
			<Item Name="VB.dll" Type="Document" URL="../../../../VB.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
