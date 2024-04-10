//
//  main.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include <stdio.h>
#include <GLUT/glut.h>
#include <stdbool.h>

#include "bike.h"
#include "display.h"
#include "projectiles.h"
#include "cars.h"
#include "globalVariables.h"
#include "collisions.h"
/*
#include "collisions.h"
 */

// Fonction pour mettre à jour le jeu
void updateGame(int value) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
            if (projectiles[i].active) {
                for (int j = 0; j < MAX_CARS; j++) {
                    if (cars[j].active && checkCollision(projectiles[i].x, projectiles[i].y, cars[j])) {
                        cars[j].active = false; // Désactiver la voiture
                        projectiles[i].active = false; // Désactiver le projectile
                        break; // Sortir de la boucle car la collision a été traitée
                    }
                }
            }
        }
    // Mettre à jour les projectiles
    updateProjectiles();
    // Mettre à jour les voitures
    updateCars();
    /*
    // Vérifier les collisions
    updateCollisions(projectiles, voitures, MAX_PROJECTILES, MAX_VOITURES);
     */
    // Redessiner l'écran
    glutPostRedisplay();
    // Régler le timer pour la mise à jour suivante
    glutTimerFunc(16, updateGame, 0);
}

// Fonction principale
int main(int argc, char **argv) {
    initGLUT(&argc, argv);
    initProjectiles();
    initCars();
    
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fond noir
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0); // Commencer la mise à jour des projectiles
    
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, updateGame, 0); // Commencer le timer immédiatement
    glutMainLoop();
    return 0;
}
