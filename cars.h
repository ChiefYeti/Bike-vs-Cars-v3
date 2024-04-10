//
//  cars.h
//  Bike vs Cars 2024-04-08
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

#ifndef cars_h
#define cars_h

#include <stdio.h>
#include <stdbool.h>

// Structure pour une voiture
typedef struct {
    float x, y; // Position de la voiture
    bool active; // État de la voiture (booléen indiquant si la voiture est active ou pas)
} Car;

void initCars();
void updateCars();
void drawCars();
void timer(int value);

#endif /* cars_h */
