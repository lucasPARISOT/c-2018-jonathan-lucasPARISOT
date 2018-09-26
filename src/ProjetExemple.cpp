//============================================================================
// Name        : ProjetExemple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

using namespace std;
#include "Personnage.h"
#include "Guerrier.h"
#include "Kamikaze.h"
#include "Mage.h"
#include "Corbeau.h"
#include "Chaton.h"
#include "Creeper.h"
#include <iostream>

int main() {
	
	Animal* referenceCorbeau = new Corbeau();
	referenceCorbeau->crier();

	Animal* referenceChaton = new Chaton();
	referenceChaton->crier();

	Animal* referenceCreeper = new Creeper();
	referenceCreeper->crier();

	Personnage* referencePersonnageGuerrier = new Guerrier();
	referencePersonnageGuerrier->avancer();
	referencePersonnageGuerrier->attaquer();

	Personnage* referencePersonnageKamikaze = new Kamikaze();
	referencePersonnageKamikaze->avancer();
	referencePersonnageKamikaze->attaquer();

	Personnage* referencePersonnageMage = new Mage();
	referencePersonnageMage->avancer();
	referencePersonnageMage->attaquer();

	referencePersonnageMage->rotationDroite();


	delete referencePersonnageGuerrier;
	delete referencePersonnageKamikaze;
	delete referencePersonnageMage;
	return 0;
}
