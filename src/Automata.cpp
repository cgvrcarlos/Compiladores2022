#include <Automata.h>

Automata::Automata(string fileName)
{
	ifstream text;
	string line;

	text.open(fileName, ios::in);

	while (!text.eof())
	{
		getline(text, line);

		cout << line << endl;
	}
	
}

Automata::~Automata()
{

}
