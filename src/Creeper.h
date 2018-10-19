#ifndef CREEPER_H_
#define CREEPER_H_

#include <iostream>
#include "Animal.h"

namespace std {

	class Creeper:public Animal {
		public:
			Creeper();
			virtual ~Creeper();
			void crier();
			string exporter();
			void importer();
	};

}

#endif
