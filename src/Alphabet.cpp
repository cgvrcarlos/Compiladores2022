#include "Alphabet.h"

Alphabet::Alphabet()
{
}

Alphabet::~Alphabet()
{
        symbols.clear();
}

set<char> Alphabet::getSymbols() const
{
	return symbols;
}

void Alphabet::insert(char element)
{
        symbols.insert(element);
}

bool Alphabet::itBelongs(char s) const
{
	auto it = find(symbols.begin(), symbols.end(), s);

	return it != symbols.end();
}

int Alphabet::size() const
{
        return symbols.size();
}

void Alphabet::print()
{
    cout << "\tΣ = { ";

    set<char>::iterator it;

    for (it = symbols.begin() ; it != symbols.end() ; it++ )
    {
        cout << "[" << *it << "]";
    }
    cout << " }" << endl;
}
