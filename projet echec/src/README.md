# ♟️ Chess Game (SDL3 + C++)

Un jeu d’échecs développé en **C++** avec **SDL3** pour le rendu graphique et **Dear ImGui** pour l’interface utilisateur.
Ce projet a pour objectif de poser les bases d’un **vrai moteur de jeu d’échecs**, évolutif vers des règles complètes, une interface moderne et une IA.

---

## ✨ Fonctionnalités actuelles

* Plateau d’échecs 8×8
* Affichage graphique avec SDL3
* Interface utilisateur avec ImGui
* Gestion des tours (Blancs / Noirs)
* Sélection et déplacement des pièces à la souris
* Règles de déplacement de base :

  * Pion
  * Tour
  * Cavalier
  * Fou
  * Dame
  * Roi
* Bouton **Reset** pour réinitialiser la partie

---

## 🧱 Architecture du projet

```text
chess_game/
├─ src/
│  ├─ Board.h / Board.cpp     # Logique du plateau et règles
│  ├─ Piece.h / Piece.cpp     # Définition des pièces (types, couleurs)
│  ├─ Renderer.h / Renderer.cpp # Rendu graphique du plateau et des pièces
│  ├─ main.cpp                # Boucle de jeu et événements
│  └─ README.md
│
├─ assets/
│  ├─ Fonts/                 # Polices (TTF)
│  ├─ Sounds/                # Sons (à venir)
│  └─ Themes/                # Thèmes UI (à venir)
│
├─ extern/
│  └─ imgui/                 # Dear ImGui + backends SDL3
│
├─ build/                    # Fichiers de build (CMake)
└─ chess_game.exe
```

---

## 🛠️ Technologies utilisées

* **C++17**
* **SDL3** (rendu, fenêtre, événements)
* **SDL3_ttf** (polices)
* **Dear ImGui** (interface graphique)
* **CMake / Makefile** (build)

---

## ▶️ Compilation et exécution

### Prérequis

* Un compilateur C++ compatible C++17 (GCC, Clang, MSVC)
* SDL3 et SDL3_ttf installés
* CMake (optionnel si Makefile utilisé)

### Compilation (exemple)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Exécution

```bash
./chess_game
```

Sous Windows, assurez-vous que les DLL SDL3 sont accessibles (dans le même dossier que l’exécutable ou dans le PATH).

---

## 🎮 Contrôles

* **Clic gauche** :

  * Sélectionner une pièce
  * Cliquer sur une case valide pour la déplacer
* **Bouton Reset (ImGui)** : réinitialiser la partie

---

## 🚧 Limitations actuelles

* Pas de gestion de l’échec / échec et mat
* Pas de roque
* Pas de prise en passant
* Pas de promotion du pion
* Pas de collision sur les trajets (tour, fou, dame)
* Pas encore de textures (formes simples)

Ces points sont prévus dans les prochaines versions.

---

## 🚀 Évolutions prévues

* Ajout des règles complètes des échecs
* Textures PNG pour les pièces
* Surbrillance des coups possibles
* Drag & drop
* IA simple (Minimax)
* Sauvegarde / chargement de partie
* Amélioration de l’UI et des thèmes

---

## 👤 Auteur

** Black Zane**
Développeur passionné par le C++, le game programming et les moteurs de jeu.

---

## 📜 Licence

Projet open-source à but éducatif. Libre d’utilisation et de modification pour l’apprentissage.

