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
#include <vector>
#include <SFML/Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::RectangleShape shapeRectangle(sf::Vector2f(800, 600));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Texture texture;
		texture.setRepeated(true);

		if (!texture.loadFromFile("./data/background.png"))
		{
			cout << "File not successfully loaded" << endl;
		}

		shapeRectangle.setTexture(&texture);
		shapeRectangle.setTextureRect(sf::IntRect(0, 0, 600, 600));

		window.clear();
		//window.draw(shapeCircle);
		//window.draw(shapeRectangle);
		window.display();
	}


	vector<Personnage*> listePersonnage;
	vector<Animal*> listeAnimal;

	int position = 0;



	Animal* referenceCorbeau = new Corbeau();
	listeAnimal.push_back(referenceCorbeau);

	Animal* referenceChaton = new Chaton();
	listeAnimal.push_back(referenceChaton);

	Animal* referenceCreeper = new Creeper();
	listeAnimal.push_back(referenceCreeper);





	Personnage* referenceGuerrier = new Guerrier();
	listePersonnage.push_back(referenceGuerrier);

	Personnage* referenceKamikaze = new Kamikaze();
	listePersonnage.push_back(referenceKamikaze);

	Personnage* referenceMage = new Mage();
	referenceMage->ajouterAnimal(*referenceChaton);
	listePersonnage.push_back(referenceMage);

	// listeAnimal.at(0)->crier(); TEST METHODE SUR UN ELEMENT

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
			switch (touche)
			{
			case 27:
				gameIsRunning = false;
				break;

			case 'w':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->avancer();
				cout << endl;
				break;

			case 'a':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->direNom();
				cout << " se decale sur la gauche !" << endl;
				break;

			case 's':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->direNom();
				cout << " recule !" << endl;
				break;
			case 'd':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->direNom();
				cout << " se decale sur la droite !" << endl;
				break;

			case 'e':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->direNom();
				cout << endl;
				break;

			case 'r':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->direAnimal();
				cout << "est mon fidele partenaire !" << endl;
				break;

			case 'q':
				//cout << tour << endl;
				cout << endl;
				cout << "L\'echauffement est fini !" << endl;
				listePersonnage.at(position)->direNom();
				cout << " se recharge en energie !" << endl;
				++(*(listePersonnage.at(position)));
				break;

			case 't':
				cout << endl;
				cout << "tour numero " << tour << endl;
				break;

			case 'f':
				//cout << tour << endl;
				cout << endl;
				listePersonnage.at(position)->direNom();
				cout << " a " << listePersonnage.at(position)->pv << " pv !" << endl;
				break;

			case 32: // Space
				cout << endl;
				//cout << tour << endl;
				cout << "Changement de personnage !" << endl;
				position++;
				if (position > 2) {
					position = 0;
				}
				listePersonnage.at(position)->direNom();
				cout << " entre en scene !" << endl;
				break;

			default:
				cout << "" << endl;
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
	fichierMonde << listeAnimal.at(0)->exporter() << endl;
	fichierMonde << listeAnimal.at(1)->exporter() << endl;
	fichierMonde << listeAnimal.at(2)->exporter() << endl;
	fichierMonde << referenceCreeper->exporter() << endl;
	fichierMonde << "</Animaux>" << endl;
	fichierMonde << "<Personnages>" << endl;
	fichierMonde << listePersonnage.at(0)->exporter() << endl;
	fichierMonde << listePersonnage.at(1)->exporter() << endl;
	fichierMonde << listePersonnage.at(2)->exporter() << endl;
	fichierMonde << "</Personnages>" << endl;
	fichierMonde << "</Monde>" << endl;

	fichierMonde.close();

	listeAnimal.clear();
	listePersonnage.clear();

	delete referenceGuerrier;
	delete referenceKamikaze;
	delete referenceMage;

	delete referenceCorbeau;
	delete referenceChaton;
	delete referenceCreeper;


	return 0;
}