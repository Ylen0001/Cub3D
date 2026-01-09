# Cub3D
Cub3d – Projet 42 

Un mini-moteur 3D inspiré de Wolfenstein 3D, réalisé en C avec le moteur graphique MiniLibX. Le projet utilise un algorithme de raycasting pour afficher un environnement en pseudo-3D, à partir d’une carte 2D et de textures définies dans un fichier .cub.

## 🎯 Objectifs du projet

- Découvrir les bases du **raycasting** (projection verticale de rayons pour simuler la profondeur).
- Manipuler la librairie graphique **MiniLibX** (fenêtre, images, gestion des événements).
- Implémenter un parser robuste pour un fichier de configuration `.cub`.
- Générer une scène 3D à partir :
  - d'une carte 2D fermée,
  - de textures pour chaque orientation (NO, SO, EA, WE),
  - des couleurs du plafond et du sol.
- Gérer les mouvements du joueur :
  - avancer / reculer,
  - tourner,
  - strafe gauche/droite.
- Empêcher les collisions avec les murs.

## ⌨️ Commandes

| Touche | Action |
|-------|--------|
| W     | avancer |
| S     | reculer |
| A     | strafe gauche |
| D     | strafe droite |
| ← →   | tourner vue |
| ESC   | quitter |

### Jouer

make
./cub3D maps/OK_Big_official.cub 
