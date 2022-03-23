#if !defined(ALPHABET)
#define ALPHABET

#include <set>
#include <iterator>

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

	/* Insertar elemento al Alfabeto */
	void insert(char);

	/* Tamanio del Alfabeto */
	int size() const;

    /* Impresion de Alfabeto*/
    void print();
};

#endif // ALPHABET
