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
				states.insert(stoi(aux[i]));
			}
		}
	}

	for (set<State>::iterator it = states.begin(); it != states.end(); it++)
	{
		cout << (*it).getStateID() << endl;
	}
	
}

Automata::~Automata()
{

}
