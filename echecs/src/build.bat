@echo off
echo ===============================
echo Build projet Echecs - SDL3
echo ===============================

REM Supprimer ancien executable
if exist echecs.exe del echecs.exe

REM Compilation
g++ -std=c++17 ^
main.cpp ^
Application.cpp ^
Interface.cpp ^
Core/Plateau.cpp ^
thirdparty/imgui/imgui.cpp ^
thirdparty/imgui/imgui_draw.cpp ^
thirdparty/imgui/imgui_widgets.cpp ^
thirdparty/imgui/imgui_tables.cpp ^
thirdparty/imgui/backends/imgui_impl_sdl3.cpp ^
thirdparty/imgui/backends/imgui_impl_sdlrenderer3.cpp ^
-I. ^
-Ithirdparty/imgui ^
-Ithirdparty/imgui/backends ^
-Ithirdparty/SDL3/include ^
-Lthirdparty/SDL3/lib ^
-lSDL3 ^
-o echecs.exe

if exist echecs.exe (
    echo.
    echo ✅ Compilation reussie !
    echo Lance echecs.exe
) else (
    echo.
    echo ❌ Erreur de compilation
)

pause
