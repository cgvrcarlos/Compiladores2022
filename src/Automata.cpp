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
				states.push_back(stoi(aux[i]));
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
