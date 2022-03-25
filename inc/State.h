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

	bool initialState;
	bool finalState;
public:
	/* Constructor por defecto */
	State();

	/* Constructor de State */
	State(int);

	/* Destructor por defecto */
	~State();

	/* Getters */
	int getStateID() const;
	bool getInitialState() const;
	bool getFinalState() const;

	/* Setters */
	void setInitialState();
	void setFinalState();

	/* Metodo que agrega Transiciones al Estado */
	void insertTransition(char, int);

	/* Metodo que retorna el numero de Transiciones */
	int numberOfTransitions() const;

	/* Metodo que imprime las Transiciones */
	void print();

	/* Sobrecarga del operador < */
	bool operator<(const State&) const;
};

#endif // STATE
