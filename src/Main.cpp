using namespace std;


#include "Guerrier.h"
#include "Kamikaze.h"
#include "Mage.h"
#include "Corbeau.h"
#include "Chaton.h"
#include "Creeper.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <thread>


int main() {

	cout << "WORK" << endl;

	Animal* referenceCorbeau = new Corbeau();

	Animal* referenceChaton = new Chaton();

	Animal* referenceCreeper = new Creeper();

	Personnage* referenceGuerrier = new Guerrier();

	Personnage* referenceKamikaze = new Kamikaze();

	Personnage* referenceMage = new Mage();
	referenceMage->ajouterAnimal(*referenceChaton);

	int tour = 0;
	int touche; // Ou int
	bool gameIsRunning = true;
	while (gameIsRunning)
	{

		// premier probleme-solution : dormir sans occuper les ressources
		this_thread::sleep_for(chrono::milliseconds(1000 / 60)); // 60 fps
		// second probleme-solution : lire les entrées sans bloquer la boucle
		if (_kbhit())
		{
			touche = _getch(); // touche 1, défile de la liste
			cout << "touche " << touche << " " << tour << endl;
			switch (touche)
			{
			case 27:
				gameIsRunning = false;
				break;
			case 'w':
				cout << "up" << endl;
				break;
			case 'a':
				cout << "left" << endl;
				break;
			case 's':
				cout << "down" << endl;
				break;
			case 'd':
				cout << "right" << endl;
				break;
			case 32:
				cout << "Changement personnage" << endl;
				break;
			}
		}
		//cout << "tour " << tour << endl;

		while (_kbhit()) {
			_getch();
		}
		tour++;
	}

	ofstream fichierMonde;
	fichierMonde.open("data/monde.xml");
	fichierMonde << "<Monde>" << endl;
	fichierMonde << "<Animaux>" << endl;
	fichierMonde << referenceCorbeau->exporter() << endl;
	fichierMonde << referenceChaton->exporter() << endl;
	fichierMonde << referenceCreeper->exporter() << endl;
	fichierMonde << "</Animaux>" << endl;
	fichierMonde << "<Personnages>" << endl;
	fichierMonde << referenceGuerrier->exporter() << endl;
	fichierMonde << referenceKamikaze->exporter() << endl;
	fichierMonde << referenceMage->exporter() << endl;
	fichierMonde << "</Personnages>" << endl;
	fichierMonde << "</Monde>" << endl;

	fichierMonde.close();

	delete referenceGuerrier;
	delete referenceKamikaze;
	delete referenceMage;

	delete referenceCorbeau;
	delete referenceChaton;
	delete referenceCreeper;


	return 0;
}
