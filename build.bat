@echo off
setlocal enabledelayedexpansion

if not exist build2 mkdir build2

echo Compiling source files...
for /r src %%f in (*.cpp) do (
  echo %%f | findstr /i /c:"build2" >nul
  if errorlevel 1 (
    echo Compiling: %%f
    g++ -std=c++17 -g -c "%%f" -o "build2\%%~nf.o" -I libs\SFML\include -I libs\ImGui -I libs\ImGui-SFML -I src
  )
)

echo Compiling ImGui...
for /r libs\ImGui %%f in (*.cpp) do (
  echo Compiling: %%f
  g++ -std=c++17 -g -c "%%f" -o "build2\%%~nf.o" -I libs\SFML\include -I libs\ImGui -I libs\ImGui-SFML
)

echo Compiling ImGui-SFML...
for /r libs\ImGui-SFML %%f in (*.cpp) do (
  echo Compiling: %%f
  g++ -std=c++17 -g -c "%%f" -o "build2\%%~nf.o" -I libs\SFML\include -I libs\ImGui -I libs\ImGui-SFML
)

echo Compiling main.cpp...
g++ -std=c++17 -g -c main.cpp -o build2\main.o -I libs\SFML\include -I libs\ImGui -I libs\ImGui-SFML -I src

echo Linking...

set OBJFILES=
for %%f in (build2\*.o) do set OBJFILES=!OBJFILES! "%%f"

g++ !OBJFILES! -L libs\SFML\lib -o AlgoViewer.exe -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -mwindows

echo Build complete.
endlocal
exit /b 0