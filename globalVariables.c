//
//  globalVariables.c
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#include "globalVariables.h"

float bikePosX = 0.0f;
float bikePosY = -0.9f;
const float cars_width = 0.1f;
const float left_border = -0.8f + cars_width / 2;
const float right_border = 0.8f - cars_width / 2;

Projectile projectiles[MAX_PROJECTILES];
Car cars[MAX_CARS];
