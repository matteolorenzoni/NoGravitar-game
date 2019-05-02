#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include "Infinito.h"
#include "Spaceship.h"
#include "windows.h"
#include "Planet.h"
using namespace std;



Infinito::Infinito()
{
	puntatoreOggettoUniverso = NULL;
}

void Infinito::aggiungereUniverso() {
	if (puntatoreOggettoUniverso == NULL) {
		puntatoreOggettoUniverso = new Universo();
		puntatoreOggettoUniverso->PP = NULL;
		puntatoreOggettoUniverso->next = NULL;
		puntatoreOggettoUniverso->prev = NULL;
	}
	else if (puntatoreOggettoUniverso->next == NULL) {
		puntatoreOggettoUniverso->next->next = new Universo();
		puntatoreOggettoUniverso->next->PP = NULL;
		puntatoreOggettoUniverso->next->next = NULL;
		puntatoreOggettoUniverso->next->prev = puntatoreOggettoUniverso;
	}
	else {
		ptr_Universo tmp, tmpOld;
		tmpOld = puntatoreOggettoUniverso;
		tmp = puntatoreOggettoUniverso->next;
		while (tmpOld->next->next != NULL) {
			tmp = tmp->next;
			tmpOld = tmpOld->next;
		}
		tmp->next = new Universo();
		tmp->next->PP = NULL;
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
}

void Infinito::crezioneUniverso(int numeroPianeti) {
	for (int i = 1; i <= numeroPianeti; i++) {
		if (puntatoreOggettoUniverso->PP == NULL) {
			puntatoreOggettoUniverso->PP = new Pianeta();
			puntatoreOggettoUniverso->PP->numeroMondo = i;
			puntatoreOggettoUniverso->PP->pianetaDistrutto = false;
			puntatoreOggettoUniverso->PP->xCoordinataMondo = ((rand() % 8) + 5);
			puntatoreOggettoUniverso->PP->yCoordinataMondo = ((rand() % 12) + 2);
			puntatoreOggettoUniverso->PP->pianetaCorrente = new Planet();
			puntatoreOggettoUniverso->PP->next = NULL;
			puntatoreOggettoUniverso->PP->prev = NULL;
		}
		else if (puntatoreOggettoUniverso->PP->next == NULL) {
			puntatoreOggettoUniverso->PP->next = new Pianeta();
			puntatoreOggettoUniverso->PP->next->numeroMondo = i;
			puntatoreOggettoUniverso->PP->next->pianetaDistrutto = false;
			puntatoreOggettoUniverso->PP->next->xCoordinataMondo = ((rand() % 8) + 5);
			puntatoreOggettoUniverso->PP->next->yCoordinataMondo = ((rand() % 12) + 2);
			puntatoreOggettoUniverso->PP->next->pianetaCorrente = new Planet();
			puntatoreOggettoUniverso->PP->next->next = NULL;
			puntatoreOggettoUniverso->PP->next->prev = puntatoreOggettoUniverso->PP->next;
		}
		else {
			ptr_Pianeta tmp, tmpOld;
			tmpOld = puntatoreOggettoUniverso->PP;
			tmp = puntatoreOggettoUniverso->PP->next;
			while (tmpOld->next->next != NULL) {
				tmp = tmp->next;
				tmpOld = tmpOld->next;
			}
			tmp->next = new Pianeta();
			tmp->next->numeroMondo = i;
			tmp->next->pianetaDistrutto = false;
			tmp->next->xCoordinataMondo = ((rand() % 8) + 5);
			tmp->next->yCoordinataMondo = ((rand() % 12) + 2);
			tmp->next->pianetaCorrente = new Planet();
			tmp->next->next = NULL;
			tmp->next->prev = tmp;
		}
	}
}

void Infinito::aggiungiPlanet() {
	ptr_Pianeta tmp = puntatoreOggettoUniverso->PP;
	while (tmp!=NULL) {
		tmp->xCoordinataMondo = 3;
		tmp = tmp->next;
	}
}

void Infinito::stampaCoordinate() {
	ptr_Pianeta tmp = puntatoreOggettoUniverso->PP;
	while (tmp != NULL) {
		cout << "Numero mondo: " << tmp->numeroMondo << "          Coordinata x: " << tmp->xCoordinataMondo << "          Coordinata y: " << tmp->yCoordinataMondo << endl;
		tmp = tmp->next;
	}
}

void Infinito::setMappaUniverso(int xSpaceship, int ySpaceship) {
	//setta la cornice
	for (int z = 0; z < x; z++) {
		for (int j = 0; j < y; j++) {
			matrice[z][j] = ' ';
		}
	}
	int i;
	matrice[0][0] = 201;
	matrice[19][0] = 200;
	matrice[0][79] = 187;
	matrice[19][79] = 188;
	for (i = 1; i < x - 1; i++)  matrice[i][0] = 186;
	for (i = 1; i < x - 1; i++)  matrice[i][y - 1] = 186;
	for (i = 1; i < y - 1; i++)  matrice[0][i] = 205;
	for (i = 1; i < y - 1; i++)  matrice[x - 1][i] = 205;

	//setta la posizione della navicella
	matrice[xSpaceship][ySpaceship] = 'Y';

	ptr_Pianeta tmp = puntatoreOggettoUniverso->PP;

	//setta 'O' per rappresentare i Pianeti in base alle loro coordinate
	while (tmp != NULL) {
		matrice[tmp->xCoordinataMondo][tmp->yCoordinataMondo] = 'O';
		tmp = tmp->next;
	}
}

//setta da carattere nullo a carattere "Y" la nuova posizione della navicella�
//setta anche le quattro posizioni adiacenti in carattere nullo (cancellando la vecchia posizione)
//prima di settare fa un controllo per vedere se � vicino ad un bordo della mappa, in tal caso non modifica il carattere in prossimita del relativo margine
bool Infinito::setMatrice(int x, int y, char direzione) {
	bool guardia = false;

	if (direzione == 75 && y > 0) {       //left
		if (matrice[x][y] != 'O') {
			matrice[x][y + 1] = ' ';
			matrice[x][y] = 'Y';
		}
		else guardia = true;
	}

	else if (direzione == 77 && y < 79) { //righ
		if (matrice[x][y] != 'O') {
			matrice[x][y - 1] = ' ';
			matrice[x][y] = 'Y';
		}
		else guardia = true;
	}

	else if (direzione == 72 && x > 0) {    //up
		if (matrice[x][y] != 'O') {
			matrice[x][y] = 'Y';
			matrice[x + 1][y] = ' ';
		}
		else guardia = true;
	}

	else if (direzione == 80 && x < 20) {    //down
		if (matrice[x][y] != 'O') {
			matrice[x - 1][y] = ' ';
			matrice[x][y] = 'Y';
		}
		else guardia = true;
	}

	return guardia;
}



//stampa la mappa
void Infinito::printMappUniverso() {
	system("cls");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matrice[i][j];
		}
		cout << "\n";
	}
}

ptr_planet Infinito::pianetaCor(int x, int y) {
	ptr_Pianeta tmp = puntatoreOggettoUniverso->PP;
	while ((tmp->xCoordinataMondo != x) || (tmp->yCoordinataMondo != y)) {
		tmp = tmp->next;
	}
 	return tmp->pianetaCorrente;
}