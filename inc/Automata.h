#if !defined(AUTOMATA)
#define AUTOMATA

#include <list>
#include <iterator>
#include <fstream>
#include <iostream>
#include <algorithm>

#include <Alphabet.h>
#include <State.h>
#include <Path.h>
#include <utilities.h>

using namespace std;

class Automata
{
private:
	/* Alfabeto del Automata */
	Alphabet sigma;

	/* Conjunto de estados */
	list<State> states;

	/* Estado del Automata */
	bool isComplete;

	/* Lista de caminos validos */
	list<Path> paths;
public:
	/* Constructor de un NFA a partir de un fichero */
	Automata(string);
	
	/* Destructor por defecto */
	~Automata();

	/* Setter */
	void setIsComplete();

	/* Completa el Automata */
	void completeAutomata();

	/* Impresion de quintupla del Automata */
	void print();

	/* Metodo que inicia el analisis de una cadena */
	void analizeString(string);

	/* Metodo que analiza recursivamente la cadena */
	void deepSearch(string, const int, Path);

	/* Metodo que imprime los caminos correctos */
	void printPaths();
};

#endif // AUTOMATA
