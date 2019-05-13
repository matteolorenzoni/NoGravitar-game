#pragma once
#include "Mapp.h"


class Spaceship : public Mapp{
protected:
	int p1;  	//coordinate x della navicella nell'universo
	int p2;  	//coordinate y della navicella nell'universo
	int p3;     //coordinate x della navicella all'interno del pianeta
	int p4;     //coordinate x della navicella all'interno del pianeta
	int life;	//vita della navicella
	int fuel; 	//carburante della navicella
public:
	Spaceship();
	void moveSpaceshipSolarSystem(char n);
	void moveSpaceshipPlanet(char n);
	int returnParameter(int i);
	void fuelMinus();
	void lifeMinus();
	void setInitialPosition();
	void fuelPlus(int i);
	bool spaceshipIsAlive();
	void modificaCoordinateInCasoDiNuovoSistemaSolare(int i);
};

