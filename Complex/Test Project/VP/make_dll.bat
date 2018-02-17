cd D:\Reflex2C
ReflexToC.exe -M -P -L -N -T %1
C:\MinGW\bin\g++.exe %1_id.c -o %1_cfg_gen
%1_cfg_gen.exe
g++ -c -DBUILDING_EXAMPLE_DLL msg_queue.c r_io.c r_lib.c %10001.c %1inp.c %1main.c %1outp.c %1usr1.c dll_interface.c 
g++ -shared -o %1.dll msg_queue.o r_io.o r_lib.o %10001.o %1inp.o %1main.o %1outp.o %1usr1.o dll_interface.o -Wl,--out-implib,lib%1.a -Wl,--subsystem,windows 
chcp 1251
COPY %1.dll "C:\Nonius\LabVIEW\Reflex"
for %%f in (*.cfg) do copy %%f "C:\Nonius\LabVIEW\config"
