#include "Alphabet.h"

Alphabet::Alphabet()
{
}

Alphabet::~Alphabet()
{
        symbols.clear();
}

void Alphabet::insert(char element)
{
        symbols.insert(element);
}

int Alphabet::size() const
{
        return symbols.size();
}

void Alphabet::print()
{
    cout << "El Alphabeto es => {";

    set<char>::iterator it;

    for (it = symbols.begin() ; it != symbols.end() ; it++ )
    {
        cout << *it << ",";
    }
    cout << "}" << endl;
}
