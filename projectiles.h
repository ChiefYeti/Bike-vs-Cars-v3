//
//  projectiles.h
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#ifndef projectiles_h
#define projectiles_h

#include <stdio.h>
#include <stdbool.h>

// Structure pour un projectile
typedef struct {
    float x, y; // Position du projectile
    bool active; // État du projectile
} Projectile;

void initProjectiles();
void fireProjectile();
void updateProjectiles();
void drawProjectiles();
void update(int value);
void keyboard(unsigned char key, int x, int y);

#endif /* projectiles_h */
