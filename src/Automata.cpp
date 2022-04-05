#include <Automata.h>

Automata::Automata(string fileName)
{
	ifstream text;
	string line;

	int numberLine = 0;

	vector<string> aux;

	text.open(fileName, ios::in);
	numberLine = 0;

	isComplete = false;

	while (!text.eof())
	{
		getline(text, line);

		aux = splitString(line, ",");

		if (numberLine == 0)
		{
			for (int i = 0; i < (int) aux.size(); i++)
			{
				states.emplace_back(stoi(aux[i]));
			}
		}else if (numberLine == 1)
		{
			for (int i = 0; i < (int) aux.size(); i++)
			{
				list<State>::iterator it = find(states.begin(), states.end(), stoi(aux[i]));

				(*it).setFinalState();
			}
		}else if (numberLine == 2)
		{
			for (int i = 0; i < (int) aux.size(); i++)
			{
				list<State>::iterator it = find(states.begin(), states.end(), stoi(aux[i]));

				(*it).setInitialState();
			}
		}else if (numberLine == 3)
		{
			for (int i = 0; i < (int) aux.size(); i++)
			{
				sigma.insert(aux[i].at(0));
			}
		}else
		{
			list<State>::iterator it = find(states.begin(), states.end(), stoi(aux[0]));

			(*it).insertTransition(aux[1].at(0), stoi(aux[2]));
		}

		numberLine++;
	}
}

Automata::~Automata()
{
}

void Automata::setIsComplete()
{
	isComplete = true;
}

void Automata::completeAutomata()
{
	/* Iteradores */
	set<Transition>::iterator itTransition;
	list<State>::iterator itState;
	set<char>::iterator itAlphabet;

	/* Variable que almacena una copia de las Transiciones de cada Estado */
	set<Transition> transitionB;

	/* Bandera que indica que tiene Transicion a un Simbolo */
	bool flag = false;

	/* Se obtiene el alfabeto */
	set<char> symbolsB = sigma.getSymbols();
	
	for (itState = states.begin(); itState != states.end(); itState++)
	{
		for (itAlphabet = symbolsB.begin(); itAlphabet != symbolsB.end(); itAlphabet++)
		{
			transitionB = (*itState).getTransitions();

			for (itTransition = transitionB.begin(); itTransition != transitionB.end(); itTransition++)
			{
				if ((*itTransition).getSymbol() == (*itAlphabet))
				{
					flag = true;
					break;
				}	
			}

			if (!flag)
				(*itState).insertTransition((*itAlphabet), -1);

			flag = false;
		}
	}

	/* Se agrega el estado Vacio y sus Transiciones */
	states.emplace_back(-1);

	list<State>::iterator search = find(states.begin(), states.end(), -1);

	for (itAlphabet = symbolsB.begin(); itAlphabet != symbolsB.end(); itAlphabet++)
		(*search).insertTransition((*itAlphabet), -1);

	setIsComplete();
}

void Automata::print()
{
	if (!isComplete)
		cout << "_/ AUTOMATA FINITO NO DETERMINISTA \\_" << endl;
	else
		cout << "_/ AUTOMATA FINITO NO DETERMINISTA COMPLETO \\_" << endl;

	cout << "\tQ = { ";
	for (list<State>::iterator it = states.begin(); it != states.end(); it++)
	{
		cout << "[" << (*it).getStateID() << "]";
	}
	cout << " }" << endl;

	cout << "\tF = { ";
	for (list<State>::iterator it = states.begin(); it != states.end(); it++)
	{
		if ((*it).getFinalState() == 1)
		{
			cout << "[" << (*it).getStateID() << "]";
		}
	}
	cout << " }" << endl;

	cout << "\tS = { ";
	for (list<State>::iterator it = states.begin(); it != states.end(); it++)
	{
		if ((*it).getInitialState() == 1)
		{
			cout << "[" << (*it).getStateID() << "]";
		}
	}
	cout << " }" << endl;

	sigma.print();

	for (list<State>::iterator it = states.begin(); it != states.end(); it++)
	{
		(*it).printTransitions();
	}
}

void Automata::analizeString(string text)
{
	Path savePath;

	cout << "Cadena a analizar -> " << text << endl << endl;

	auto it = find_if(states.begin(), states.end(), 
		[](const State& obj){return obj.getInitialState();});

	deepSearch(text, (*it).getStateID(), savePath);
}

void Automata::deepSearch(string text, int state, Path savePath)
{	
	set<Transition>::iterator itTransition;

	auto actualState = find(states.begin(), states.end(), state);

	auto transitions = (*actualState).getTransitions();

	if (text.size() >= 1)
	{
		if (sigma.itBelongs(text.at(0)))
		{
			savePath.insertNode(state, text.at(0));

			for (itTransition = transitions.begin(); itTransition != transitions.end(); itTransition++)
			{
				if ((*itTransition).getSymbol() == text.at(0))
				{
					deepSearch(text.substr(1, text.size()-1), (*itTransition).getNextState(), savePath);
				}	
			}
		}else
		{
			savePath.insertError(state, text.at(0));

			deepSearch(text.substr(1, text.size()-1), state, savePath);
		}		

	}else
	{
		if ((*actualState).getFinalState())
		{
			savePath.insertNode(state, '\0');

			paths.emplace_back(savePath);
		}
	}
}

void Automata::printPaths()
{
	if (paths.size() == 0)
	{
		cout << "La cadena no fue valida para el Automata" << endl;
	}else
	{
		for (auto it = paths.begin(); it != paths.end(); it++)
		{
			(*it).print();
		}
	}
}
