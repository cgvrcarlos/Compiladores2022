#if !defined(NFA)
#define NFA

#include <set>
#include <iterator>
#include <iostream>

#include <Alphabet.h>
#include <State.h>

class NFA
{
private:
	/* Alfabeto del Automata */
	Alphabet sigma;

	/* Conjunto de estados */
	set<State> states;

	/* Estado Inicial */
	State initialState;

	/* Conjunto de Estados Finales */
	set<State> finalStates;
public:
	/* Constructor de un NFA a partir de un fichero */
	NFA(string);
	
	/* Destructor por defecto */
	~NFA();
};

#endif // NFA
