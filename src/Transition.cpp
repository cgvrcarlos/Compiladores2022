#include <Transition.h>

Transition::Transition(char symbol_, int nextState_)
{
	symbol = symbol_;
	nextState = nextState_;
}

Transition::~Transition()
{
	symbol = 0;
	nextState = -1;
}

char Transition::getSymbol() const
{
	return symbol;
}

int Transition::getNextState() const
{
	return nextState;
}

bool Transition:: operator< (const Transition& rhs) const
{
        if ((this->nextState <= rhs.nextState)) return true;
        return false;
}
