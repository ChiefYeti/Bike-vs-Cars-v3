//
//  bike.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include <GLUT/glut.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bike.h"
#include "globalVariables.h"
/*

*/

// Fonction pour dessiner le vélo (représenté, pour l'instant, par un triangle rouge)
void drawBike() {
    glColor3f(1.0f, 0.0f, 0.0f); // Couleur rouge pour le vélo
    glBegin(GL_TRIANGLES);
    glVertex2f(bikePosX - 0.1f, bikePosY); // Sommet inférieur gauche du triangle
    glVertex2f(bikePosX, bikePosY + 0.1f);        // Sommet supérieur du triangle
    glVertex2f(bikePosX + 0.1f, bikePosY); // Sommet inférieur droit du triangle
    glEnd();
}

// Fonction de rappel pour les entrées du clavier spécial (touches fléchées)
void specialKeys(int key, int x, int y) {
    const float speed = 0.05f; // Vitesse de déplacement du vélo
    switch (key) {
        case GLUT_KEY_LEFT:
            bikePosX -= speed;
            break;
        case GLUT_KEY_RIGHT:
            bikePosX += speed;
            break;
        case GLUT_KEY_UP:
            bikePosY += speed;
            break;
        case GLUT_KEY_DOWN:
            bikePosY -= speed;
            break;
    }
    // Limiter le déplacement du vélo aux frontières de la fenêtre de jeu
    if (bikePosX < -0.7f) bikePosX = -0.7f;
    if (bikePosX > 0.7f) bikePosX = 0.7f;
    if (bikePosY < -0.9f) bikePosY = -0.9f;
    if (bikePosY > 0.9f) bikePosY = 0.9f;
}
