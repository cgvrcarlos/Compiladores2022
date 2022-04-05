#include <Path.h>

Path::Path()
{
}

Path::Path(const Path& obj)
{
	nodes = obj.nodes;
	errorM = obj.errorM;
}

Path::~Path()
{
	nodes.clear();
	errorM.clear();
}

void Path::insertNode(int state, char symbol)
{
	nodes.push_back(make_pair(state, symbol));
}

void Path::insertError(int state, char symbol)
{
	errorM.push_back(make_pair(state, symbol));
}

void Path::print()
{
	for(auto i : nodes)
	{
		if(i.second != '\0')
			cout << i.first << "(" << i.second << ") -> ";
		else
			cout << i.first << endl;
	}
	
	
	cout << "Manejo de errores en: {";
	for(auto i : errorM)
	{
		cout << "[" << i.first << "(" << i.second << ")" << "]";
	}
	cout << "}" << endl;
}
