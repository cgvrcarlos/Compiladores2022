#if !defined(PATH)
#define PATH

#include <iostream>
#include <vector>

using namespace std;

class Path
{
private:
	vector<pair<int, char>> nodes;

	vector<pair<int, char>> errorM;
public:
	/* Constructor por defecto */
	Path();
	
	/* Constructor copia */
	Path(const Path&);

	/* Destructor por defecto */
	~Path();

	/* Getters */
	vector<pair<int, char>> getNodes();
	vector<pair<int, char>> getError();

	/* Metodo que agrega nodos */
	void insertNode(int, char);

	/* Metodo que agrega manejo de erores */
	void insertError(int, char);
};

#endif // PATH
