class Spaceship {
public:
	int p1;  	//coordinate x della navicella nell'universo
	int p2;  	//coordinate y della navicella nell'universo
	int p3;     //coordinate x della navicella all'interno del pianeta
	int p4;     //coordinate x della navicella all'interno del pianeta
	int life;	//vita della navicella
	int fuel; 	//carburante della navicella

public:
	Spaceship();
	void moveSpaceship(char n);
	void moveSpaceshipPlanet(char m);
	int coordinate(bool scelta);
	int coordinatePlanet(bool scelta);
	void rispristinoCoordinateInCasoDiPianeta(bool b, char n);
	void rispristinoCoordinateInCasoDisuperficie(bool b, char n);
	void perditaVitaInCasosuperficie(bool b);
	void ripristinoCoordinateUscitaPianeta();
	void raggioTraente();


};
