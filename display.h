//
//  display.h
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#ifndef display_h
#define display_h

#include <stdio.h>

void initGLUT(int *argc, char **argv);
void drawRoad();
void drawVegetation();
void specialKeys(int key, int x, int y);
void display();

#endif /* display_h */
