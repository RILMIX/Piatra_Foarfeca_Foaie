@echo off
REM Setează codepage-ul la UTF-8 pentru mesaje în limba română
chcp 65001 > nul

REM === PASUL 1: Configurarea Mediului Visual Studio ===
REM Setează variabilele de mediu necesare (cl.exe, lib.exe etc.) pentru x64.
call "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

set OUT_EXE=joc_rps.exe
set CXXFLAGS=/EHsc

echo === Incepere Compilare si Creare .lib ===

REM Compilare si creare player.lib
cl /c player.cpp %CXXFLAGS% || goto fail
lib /OUT:player.lib player.obj || goto fail

REM Compilare si creare computer.lib
cl /c computer.cpp %CXXFLAGS% || goto fail
lib /OUT:computer.lib computer.obj || goto fail

REM Compilare si creare engine.lib
cl /c engine.cpp %CXXFLAGS% || goto fail
lib /OUT:engine.lib engine.obj || goto fail

REM === PASUL 2: Compilarea Modulului Principal ===
echo Compilare main.cpp...
cl /c main.cpp %CXXFLAGS% /Fomain.obj || goto fail

REM === PASUL 3: Legarea Executabilului (Folosind cl.exe pentru link) ===
echo Legare finala...
REM cl.exe leagă obiectul principal cu bibliotecile statice
cl main.obj player.lib computer.lib engine.lib /Fe%OUT_EXE% || goto fail

:success
echo.
echo ✅ Compilare reușită! Rulează "%OUT_EXE%".
goto end

:fail
echo.
echo ❌ EROARE: Eșec la Construcție!
echo Verificati log-ul compilatorului de mai sus.

:end
exit /b