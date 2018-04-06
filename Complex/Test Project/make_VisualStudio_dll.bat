cd D:\Reflex2C
echo %1
echo %2
for %%i in (*) do if not %%i==ReflexToC.exe  del %%i

COPY %2\%1.rcs D:\Reflex2C\%1.rcs

ReflexToC.exe -M -P -G -L -N -T %1
C:\MinGW\bin\g++.exe %1_id.cpp -o %1_cfg_gen
%1_cfg_gen.exe

for %%I in (lib\*.* *.cpp *.h) do if not %%I==%1usr1.h COPY %%I %2\%1TestProject\%1TestProject
for %%I in (lib\*.* *.cpp *.h) do if not %%I==%1usr1.h COPY %%I %2\%1TestCode\%1TestCode
for %%I in (*.cfg *.dbg *.lis *.sym *.var) do COPY %%I %2\cfg

cd %2\src