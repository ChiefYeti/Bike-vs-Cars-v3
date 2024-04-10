//
//  cars.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GLUT/glut.h>
#include "cars.h"
#include "collisions.h"
#include "globalVariables.h"


// Espacement entre les voitures
const float MIN_DISTANCE = 0.3f;
const float ESPACEMENT_VERTICAL = 0.3f;
const float ESPACEMENT_HORIZONTAL = 0.3f;

/*
// Structure pour hitbox
typedef struct {
    float x_min, x_max, y_min, y_max; // Coordonnées de la boîte englobante
    bool active; // État de la boîte
} Box;
 */

// Fonction pour initialiser les voitures
void initCars() {
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires

        for (int i = 0; i < MAX_CARS; i++) {
            bool positionValid;
            do {
                positionValid = true;
                cars[i].x = left_border + (float)rand()/RAND_MAX * (right_border - left_border); // Position X aléatoire entre -1.0f et 1.0f
                cars[i].y = 1.0f + (float)rand()/RAND_MAX * 2.0f; // Position Y aléatoire entre -1.0f et 1.0f

                // Vérifiez que la voiture ne touche pas les autres voitures
                for (int j = 0; j < i; j++) {
                    float dx = cars[i].x - cars[j].x;
                    float dy = cars[i].y - cars[j].y;
                    float distance = sqrt(dx * dx + dy * dy);
                    if (distance < MIN_DISTANCE) {
                        positionValid = false;
                        break;
                    }
                }
            } while (!positionValid);

            cars[i].active = true;
        }
    /*
    float positionXInitiale = -0.7f; // Position X initiale pour la première voiture
    float positionYInitiale = 1.0f; // Position Y initiale pour la première voiture
    for (int i = 0; i < MAX_CARS; i++) {
           cars[i].x = positionXInitiale + (i % 3) * ESPACEMENT_HORIZONTAL; // Position X avec espacement
           cars[i].y = positionYInitiale - (i / 3) * ESPACEMENT_VERTICAL; // Position Y avec espacement
           cars[i].active = true;
       }
     */
    
    /*
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].x = (float)rand()/(float)(RAND_MAX/1.4f) - 0.7f; // Position X aléatoire sur la route
        cars[i].y = 1.0f; // Position Y en haut de la fenêtre
        cars[i].active = true;
    }
    */
}

// Fonction pour réinitialiser une voiture
void resetCar(Car *car) {
    car->x = // nouvelle position X aléatoire dans les limites de la route;
    car->y = // nouvelle position Y au-dessus de l'écran;
    car->active = true;
}

// Fonction pour mettre à jour les voitures
void updateCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].active) {
            cars[i].y -= 0.01f; // Vitesse de la voiture

            // Vérifier la collision avec chaque projectile
            bool hitByProjectile = false;
            for (int j = 0; j < MAX_PROJECTILES; j++) {
                if (projectiles[j].active && checkCollision(projectiles[j].x, projectiles[j].y, cars[i])) {
                    hitByProjectile = true;
                    projectiles[j].active = false; // Désactiver le projectile
                    break; // Pas besoin de vérifier les autres projectiles
                }
            }

            // Si la voiture est touchée ou sort de l'écran, la réinitialiser
            if (hitByProjectile || cars[i].y < -1.0f) {
                cars[i].x = left_border + (float)rand()/RAND_MAX * (right_border - left_border);
                cars[i].y = 1.0f;
                cars[i].active = true; // Réactiver la voiture
            }
        } else {
            // Si la voiture est inactive, la réinitialiser pour qu'elle rejoigne le jeu
            cars[i].x = left_border + (float)rand()/RAND_MAX * (right_border - left_border);
            cars[i].y = 1.0f;
            cars[i].active = true; // Réactiver la voiture
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
            glVertex2f(cars[i].x, cars[i].y - 0.1f); // Bas droit
            glVertex2f(cars[i].x, cars[i].y + 0.1f);         // Haut droit
            glVertex2f(cars[i].x - 0.1f, cars[i].y + 0.1f);         // Haut gauche
            glEnd();
        }
    }
}

void timer(int value) {
 updateCars();
 glutPostRedisplay();
 glutTimerFunc(16, timer, 0); // Appelle la fonction timer toutes les 16 ms
}

