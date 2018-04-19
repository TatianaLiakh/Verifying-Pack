cd D:\Reflex2C
echo %1
echo %2
for %%i in (*) do if not %%i==ReflexToC.exe  del %%i

COPY %2\%1.rcs D:\Reflex2C\%1.rcs
chcp 1251

ReflexToC.exe -M -P -L -N -T -G %1
C:\MinGW\bin\g++.exe %1_id.cpp -o %1_cfg_gen
%1_cfg_gen.exe

for %%I in (lib\*.* *.cpp *.h) do if not %%I==%1usr1.h COPY %%I %2\src
for %%I in (*.cfg *.dbg *.lis *.sym *.var) do COPY %%I %2\cfg

cd %2\src

set cintools="C:\Program Files (x86)\National Instruments\LabVIEW 2010\cintools"
x86_64-w64-mingw32-g++ -c -DBUILDING_EXAMPLE_DLL msg_queue.cpp r_io.cpp r_lib.cpp %10001.cpp %1inp.cpp %1main.cpp %1outp.cpp %1usr1.cpp custom_dll_interface.cpp lib.cpp -I%cintools% -m32 -L%cintools% -llabviewv -fpermissive
::dlltool -d import.def -l %1.dll
x86_64-w64-mingw32-g++ -shared -o %1.dll msg_queue.o r_io.o r_lib.o %10001.o %1inp.o %1main.o %1outp.o %1usr1.o custom_dll_interface.o lib.o -m32 -Wl,--subsystem,windows,--output-def,add.def,--out-implib,libadd.a -L%cintools% -llabviewv 

COPY %1.dll %2

:: for %%f in (*.cfg) do copy %%f "C:\Nonius\LabVIEW\config"

:: 1 - file name; 2 - progect path 