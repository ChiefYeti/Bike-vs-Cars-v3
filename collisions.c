//
//  collisions.c
//  Bike vs Cars v3
//
//  Created by Serge CHARLIER AZAMA on 10/04/2024.
//

#include "collisions.h"

bool checkCollision(float projectileX, float projectileY, Car car) {
    // Supposons que la voiture est un rectangle et le projectile un point pour simplifier
    float carWidth = 0.1f; // Largeur de la voiture
    float carHeight = 0.2f; // Hauteur de la voiture

    if (projectileX > car.x - carWidth / 2 && projectileX < car.x + carWidth / 2 &&
        projectileY > car.y - carHeight / 2 && projectileY < car.y + carHeight / 2) {
        return true; // Il y a collision
    }
    return false; // Pas de collision
}
