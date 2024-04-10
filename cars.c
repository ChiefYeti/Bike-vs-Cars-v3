//
//  cars.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include <stdbool.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include "cars.h"
#include "globalVariables.h"

/*
// Espacement entre les voitures
const float ESPACEMENT_VERTICAL = 0.3f;
const float ESPACEMENT_HORIZONTAL = 0.2f;


// Structure pour hitbox
typedef struct {
    float x_min, x_max, y_min, y_max; // Coordonnées de la boîte englobante
    bool active; // État de la boîte
} Box;
 */

// Fonction pour initialiser les voitures
void initCars() {
    /*
    float positionXInitiale = -0.7f; // Position X initiale pour la première voiture
    float positionYInitiale = 1.0f; // Position Y initiale pour la première voiture
    for (int i = 0; i < MAX_CARS; i++) {
           cars[i].x = positionXInitiale + (i % 3) * ESPACEMENT_HORIZONTAL; // Position X avec espacement
           cars[i].y = positionYInitiale - (i / 3) * ESPACEMENT_VERTICAL; // Position Y avec espacement
           cars[i].active = true;
       }
     */
    
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].x = (float)rand()/(float)(RAND_MAX/1.4f) - 0.7f; // Position X aléatoire sur la route
        cars[i].y = 1.0f; // Position Y en haut de la fenêtre
        cars[i].active = true;
    }
}

// Fonction pour mettre à jour les voitures
void updateCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].active) {
            cars[i].y -= 0.01f; // Vitesse de la voiture
            if (cars[i].y < -1.0f) {
                // Réinitialiser la voiture en haut avec une nouvelle position X aléatoire
                cars[i].x = (float)rand()/(float)(RAND_MAX/1.4f) - 0.7f;
                cars[i].y = 1.0f;
            }
        }
    }
}

// Fonction pour dessiner les voitures
void drawCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].active) {
            glColor3f(0.0f, 0.0f, 1.0f); // Couleur bleue pour les voitures
            glBegin(GL_QUADS);
            glVertex2f(cars[i].x - 0.1f, cars[i].y - 0.1f); // Bas gauche
            glVertex2f(cars[i].x + 0.1f, cars[i].y - 0.1f); // Bas droit
            glVertex2f(cars[i].x + 0.1f, cars[i].y);         // Haut droit
            glVertex2f(cars[i].x - 0.1f, cars[i].y);         // Haut gauche
            glEnd();
        }
    }
}

void timer(int value) {
 updateCars();
 glutPostRedisplay();
 glutTimerFunc(16, timer, 0); // Appelle la fonction timer toutes les 16 ms
}
