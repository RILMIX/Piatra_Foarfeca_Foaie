@echo off
echo === Compilare joc Piatră-Hârtie-Foarfecă ===

:: Compilăm fișierele sursă
g++ -c player.cpp -o player.o
if errorlevel 1 goto fail

g++ -c computer.cpp -o computer.o
if errorlevel 1 goto fail

g++ -c engine.cpp -o engine.o
if errorlevel 1 goto fail

g++ -c main.cpp -o main.o
if errorlevel 1 goto fail

:: Legăm toate obiectele într-un executabil
g++ player.o computer.o engine.o main.o -o game.exe
if errorlevel 1 goto fail

echo -----------------------------
echo Compilare reușită!
echo Rulează „game.exe” pentru a începe jocul.
goto end

:fail
echo Eroare la compilare!
echo Verifică fișierele sursă și încearcă din nou.

:end
exit /b
