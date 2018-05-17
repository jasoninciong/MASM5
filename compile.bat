@echo off
set projectName=MASM5
\masm32\bin\ml /c /Zd /coff %projectName%.asm
\masm32\bin\Link /SUBSYSTEM:CONSOLE /ENTRY:bubbleSortASM /out:%projectName%.exe %projectName%.obj ..\..\Irvine\Kernel32.lib ..\..\Irvine\Irvine32.lib ..\..\Irvine\User32.lib

\MinGW\bin\gcc -std=c++11 -c -m32 -o main.obj masm5.cpp
\MinGW\bin\g++ -m32 -o output.exe %projectName%.obj main.obj

del %projectName%.obj
del main.obj
 
output.exe