//
//  display.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include <GLUT/glut.h>
#include <stdbool.h>
#include <stdlib.h>

#include "display.h"
#include "bike.h"
#include "projectiles.h"
#include "cars.h"

/*
 #include "globalVariables.h"
*/



// Fonction pour initialiser GLUT et créer la fenêtre de jeu
void initGLUT(int *argc, char **argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bike vs Cars");
}

// Fonction pour dessiner la route
void drawRoad() {
    // Dessiner la route
    glColor3f(0.5f, 0.5f, 0.5f); // Couleur grise pour la route
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(-0.8f, 1.0f);
    glEnd();

    // Dessiner la ligne discontinue au milieu
    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour la ligne
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glVertex2f(0.0f, i);
        glVertex2f(0.0f, i + 0.1f);
    }
    glEnd();
}

// Fonction pour dessiner la végétation
void drawVegetation() {
    // Végétation bordure de gauche
    glColor3f(0.0f, 0.6f, 0.0f); // Couleur verte pour la végétation
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.8f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Végétation bordure de droite
    glBegin(GL_QUADS);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.8f, 1.0f);
    glEnd();
}






// Fonction de rappel pour afficher
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawRoad();
    drawVegetation();
    drawBike();
    drawProjectiles();
    drawCars();
    
    glutSwapBuffers();
}

