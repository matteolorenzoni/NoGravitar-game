#pragma once
class Mapp {
protected:
	int xMatrice = 100;
	int yMatrice = 20;
	char matrice[101][21]; //mappa
public:
	Mapp();
	void printMapp();
	void setMapp();
	void setInitialMapp();
	void setFinalMapp();
	void setGeneralParameters(int fuel, int life);
	void setPlanetSurfaceParameters(int fuel, int life);
	void setSolarSystemParameters(int fuel, int life, int universo);
};


