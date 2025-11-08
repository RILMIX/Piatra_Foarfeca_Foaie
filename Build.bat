@echo off
chcp 65001 > nul
set CXX=cl.exe
set CXXFLAGS=/EHsc /W4 /MD
set OUT_EXE=joc_rps.exe
set "OBJS=player.obj computer.obj engine.obj main.obj"

echo === Incepere Compilare C++ (cl.exe) ===

:: Compilare fisiere obiect
%CXX% /c player.cpp /Foplayer.obj %CXXFLAGS% || goto fail
%CXX% /c computer.cpp /Focomputer.obj %CXXFLAGS% || goto fail
%CXX% /c engine.cpp /Foengine.obj %CXXFLAGS% || goto fail
%CXX% /c main.cpp /Fomain.obj %CXXFLAGS% || goto fail

:: Legare
echo Legare...
%CXX% %OBJS% /Fe%OUT_EXE% || goto fail

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