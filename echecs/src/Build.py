#!/usr/bin/env python3
import subprocess

subprocess.run([
    "clang++",
    "-std=c++17",
    "src/main.cpp",
    "src/App.cpp",
    "src/GUI.cpp",
    "src/Core/Plateau.cpp",
    "src/Core/Regles.cpp",
    "-o",
    "echecs"
])
