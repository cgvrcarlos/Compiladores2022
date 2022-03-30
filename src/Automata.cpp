#include <Automata.h>

Automata::Automata(string fileName)
{
	ifstream text;
	string line;

	int numberLine = 0;

	vector<string> aux;

	text.open(fileName, ios::in);
	numberLine = 0;

	while (!text.eof())
	{
		getline(text, line);

		aux = splitString(line, ",");

		if (numberLine == 0)
		{
			for (int i = 0; i < aux.size(); i++)
			{
				states.push_back(stoi(aux[i]));
			}
		}else if (numberLine == 1)
		{
			for (int i = 0; i < aux.size(); i++)
			{
				list<State>::iterator it = find(states.begin(), states.end(), stoi(aux[i]));

				(*it).setFinalState();
			}
		}else if (numberLine == 2)
		{
			for (int i = 0; i < aux.size(); i++)
			{
				list<State>::iterator it = find(states.begin(), states.end(), stoi(aux[i]));

				(*it).setInitialState();
			}
		}else if (numberLine == 3)
		{
			for (int i = 0; i < aux.size(); i++)
			{
				sigma.insert(aux[i].at(0));
			}
		}	

		numberLine++;
	}
}

Automata::~Automata()
{
}
