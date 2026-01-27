@echo off
echo ==============================
echo Compilation du projet ECHECS
echo ==============================

g++ -std=c++20 ^
main.cpp Application.cpp Interface.cpp Core/Plateau.cpp ^
-I. ^
-ICore ^
-Ithirdparty/imgui ^
-Ithirdparty/imgui/backends ^
-Ithirdparty/SDL3/include ^
-Lthirdparty/SDL3/lib ^
thirdparty/imgui/imgui.cpp ^
thirdparty/imgui/imgui_draw.cpp ^
thirdparty/imgui/imgui_tables.cpp ^
thirdparty/imgui/imgui_widgets.cpp ^
thirdparty/imgui/backends/imgui_impl_sdl3.cpp ^
thirdparty/imgui/backends/imgui_impl_sdlrenderer3.cpp ^
-lSDL3 ^
-o echecs.exe

if %ERRORLEVEL% neq 0 (
    echo ERREUR DE COMPILATION
    pause
    exit /b
)

copy thirdparty\SDL3\bin\SDL3.dll .
echecs.exe
pause
