//
//  globalVariables.h
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#ifndef globalVariables_h
#define globalVariables_h

#include "projectiles.h"
#include "cars.h"

extern float bikePosX;
extern float bikePosY;
extern const float cars_width;
extern const float left_border;
extern const float right_border;

#define MAX_PROJECTILES 50
#define MAX_CARS 10

extern Projectile projectiles[MAX_PROJECTILES];
extern Car cars[MAX_CARS];


#endif /* globalVariables_h */
