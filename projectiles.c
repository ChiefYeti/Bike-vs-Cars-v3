//
//  projectiles.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include <stdbool.h>
#include <GLUT/glut.h>

#include "projectiles.h"
#include "globalVariables.h"




// Variables globales pour le positionnement des projectiles
float projectileY = -1.0f;

// Fonction pour initialiser les projectiles
void initProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        projectiles[i].x = 0.0f;
        projectiles[i].y = -1.0f;
        projectiles[i].active = false;
    }
}

// Fonction pour tirer un nouveau projectile
void fireProjectile() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (!projectiles[i].active) {
            projectiles[i].y = -0.9f; // Position de départ
            projectiles[i].active = true;
            break;
        }
    }
}

// Fonction pour tirer un nouveau projectile depuis le vélo
void fireProjectileFromBike() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (!projectiles[i].active) {
            projectiles[i].x = bikePosX; // Position X du vélo
            projectiles[i].y = bikePosY + 0.1f; // Position Y juste au-dessus du vélo
            projectiles[i].active = true;
            break;
        }
    }
}

// Fonction pour mettre à jour les projectiles
void updateProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (projectiles[i].active) {
            projectiles[i].y += 0.02f; // Vitesse du projectile
            if (projectiles[i].y > 1.0f) {
                projectiles[i].active = false; // Désactiver quand il sort de l'écran
            }
        }
    }
}

// Fonction pour dessiner les projectiles
void drawProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (projectiles[i].active) {
            glPushMatrix();
            glTranslatef(projectiles[i].x, projectiles[i].y, 0.0f);
            glColor3f(1.0f, 0.0f, 0.0f); // Couleur rouge
            glutSolidSphere(0.05f, 20, 20); // Dessine un projectile sphérique
            glPopMatrix();
        }
    }
}

// Fonction de rappel pour la mise à jour
void update(int value) {
    updateProjectiles();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Fonction de rappel pour les entrées du clavier
void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        fireProjectileFromBike();
    }
}
