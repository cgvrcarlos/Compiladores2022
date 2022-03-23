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