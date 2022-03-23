#if !defined(STATE)
#define STATE

#include <set>
#include <iterator>
#include <iostream>

#include <Transition.h>

using namespace std;

class State
{
private:
	int stateID;
	set <Transition> deltaTransitions;
public:
	/* Constructor de State */
	State(int);

	/* Destructor por defecto */
	~State();

	/* Metodo que agrega Transiciones al Estado */
	void insertTransition(char, int);

	/* Metodo que retorna el numero de Transiciones */
	int numberOfTransitions() const;

	/* Metodo que imprime las Transiciones */
	void print();
};

#endif // STATE
