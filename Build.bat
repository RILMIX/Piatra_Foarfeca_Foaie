
chcp 65001
@echo off
set CXX=cl.exe
set CXXFLAGS=/EHsc /W4 /MD
echo === Compilare joc Piatră-Hârtie-Foarfecă ===

:: Compilăm fișierele sursă
%CXX% /c player.cpp /Foplayer.obj %CXXFLAGS%
if errorlevel 1 goto fail

%CXX% /c computer.cpp /Focomputer.obj %CXXFLAGS%
if errorlevel 1 goto fail

%CXX% /c engine.cpp /Foengine.obj %CXXFLAGS%
if errorlevel 1 goto fail

%CXX% /c main.cpp /Fomain.obj %CXXFLAGS%
if errorlevel 1 goto fail

:: Legăm toate obiectele într-un executabil
%CXX% player.obj computer.obj engine.obj main.obj /Fegame.exe
if errorlevel 1 goto fail

echo -----------------------------
echo Compilare reusita!
echo Ruleaza „game.exe” pentru a incepe jocul.
goto end

:fail
echo Eroare la compilare!
echo Verifica fisierele sursa și incearca din nou.

:end
exit /b