@echo off
cd ./~build
echo.
echo 请输入Release下的exe名:
set /p ren=
D:/Qt/Qt5.14.2/5.14.2/msvc2017_64/bin/windeployqt.exe --release %ren%
rem pause