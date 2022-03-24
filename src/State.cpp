#include <State.h>

State::State(int stateID_)
{
	stateID = stateID_;
}

State::~State()
{
	stateID = -1;
	deltaTransitions.clear();
}

void State::insertTransition(char symbol_, int nextState_)
{
	Transition newTransition(symbol_, nextState_);

	deltaTransitions.insert(newTransition);
}

int State::numberOfTransitions() const
{
	return deltaTransitions.size();
}

void State::print()
{
	cout << "Las transiciones del estado " << stateID << " son" << endl;

	for (set<Transition>::iterator it = deltaTransitions.begin(); it != deltaTransitions.end(); it++)
	{
		cout << "δ(" << stateID << ", " << (*it).getSymbol() << ") = " << (*it).getNextState() << endl;
	}
	
}