#if !defined(AUTOMATA)
#define AUTOMATA

#include <list>
#include <iterator>
#include <fstream>
#include <iostream>
#include <algorithm>

#include <Alphabet.h>
#include <State.h>
#include <utilities.h>

using namespace std;

class Automata
{
private:
	/* Alfabeto del Automata */
	Alphabet sigma;

	/* Conjunto de estados */
	list<State> states;
public:
	/* Constructor de un NFA a partir de un fichero */
	Automata(string fileName);
	
	/* Destructor por defecto */
	~Automata();
};

#endif // AUTOMATA
