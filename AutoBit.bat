@echo off
echo [33mIntroduce el numero de serie: [0m
set /p serial=
MOVE c:\informe.htm c:\%serial%.htm
pushd Z:
MOVE c:\%serial%.htm Z:
EXIT