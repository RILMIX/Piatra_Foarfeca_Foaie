@echo off
REM Set codepage to UTF-8
chcp 65001 > nul

REM Set up Visual Studio environment for x64
call "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

set OUT_EXE=app.exe
set CXXFLAGS=/EHsc /std:c++20

echo === Starting Build ===

cl /c AsciiRenderer.cpp %CXXFLAGS% || goto fail
cl /c Choice.cpp %CXXFLAGS% || goto fail
cl /c Computer.cpp %CXXFLAGS% || goto fail
cl /c Engine.cpp %CXXFLAGS% || goto fail
cl /c HumanPlayer.cpp %CXXFLAGS% || goto fail
cl /c Main.cpp %CXXFLAGS% || goto fail

cl *.obj /Fe%OUT_EXE% || goto fail

:success
echo.
echo ✅ Build successful! Run "%OUT_EXE%".
goto end

:fail
echo.
echo ❌ BUILD FAILED!
:end
exit /b