#if !defined(ALPHABET)
#define ALPHABET

#include <set>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

class Alphabet
{
private:
	set <char> symbols;
public:
	/* Constructor por defecto */
	Alphabet();

	/* Destructor por defecto */
	~Alphabet();

	/* Getter */
	set<char> getSymbols() const;

	/* Insertar elemento al Alfabeto */
	void insert(char);

	/* Metodo que valida si el caracter existe en el alfabeto */
	bool itBelongs(char) const;

	/* Tamanio del Alfabeto */
	int size() const;

    /* Impresion de Alfabeto*/
    void print();
};

#endif // ALPHABET
