#include <State.h>

State::State()
{
}

State::State(int stateID_)
{
	stateID = stateID_;
}

State::~State()
{
	stateID = -1;
	deltaTransitions.clear();
}

int State::getStateID() const
{
	return stateID;
}

bool State::getInitialState() const
{
	return initialState;
}

bool State::getFinalState() const
{
	return finalState;
}

void State::setInitialState()
{
	initialState = true;
}

void State::setFinalState()
{
	finalState = true;
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

void State::printTransitions()
{
	cout << "\tq" << stateID << " Transiciones" << endl;

	for (set<Transition>::iterator it = deltaTransitions.begin(); it != deltaTransitions.end(); it++)
	{
		cout << "\t\tδ(" << stateID << ", " << (*it).getSymbol() << ") = " << (*it).getNextState() << endl;
	}
}

bool State:: operator< (const State& rhs) const
{
	if (this->stateID < rhs.stateID) return true;
	return false;
}

bool State:: operator==(const State& rhs) const
{
	if (this->stateID == rhs.stateID)
	{
		return true;
	}else
	{
		return false;
	}
}
