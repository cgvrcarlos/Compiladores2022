#if !defined(TRANSITION)
#define TRANSITION

#include <iostream>

using namespace std;

class Transition
{
private:
	char symbol;
	int nextState;
public:
	/* Constructor de Transition */
	Transition(char, int);
	
	/* Destructor por defecto */
	~Transition();

	/* Getters */
	char getSymbol() const;
	int getNextState() const;
};

#endif // TRANSITION
