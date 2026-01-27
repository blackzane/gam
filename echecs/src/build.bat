@echo off
echo ===============================
echo Compilation du projet Echecs
echo ===============================

REM Nettoyage ancien executable
if exist echecs.exe del echecs.exe

REM Compilation
g++ -std=c++17 ^
src/main.cpp ^
src/Application.cpp ^
src/Interface.cpp ^
src/Core/Plateau.cpp ^
src/thirdparty/imgui/imgui.cpp ^
src/thirdparty/imgui/imgui_draw.cpp ^
src/thirdparty/imgui/imgui_widgets.cpp ^
src/thirdparty/imgui/imgui_tables.cpp ^
src/thirdparty/imgui/backends/imgui_impl_sdl3.cpp ^
src/thirdparty/imgui/backends/imgui_impl_sdlrenderer3.cpp ^
-Isrc/thirdparty/SDL3/include ^
-Isrc/thirdparty/imgui ^
-Isrc/thirdparty/imgui/backends ^
-Lsrc/thirdparty/SDL3/lib ^
-lSDL3 ^
-o echecs.exe

if exist echecs.exe (
    echo.
    echo ✅ Compilation reussie !
) else (
    echo.
    echo ❌ Erreur de compilation
)

pause
