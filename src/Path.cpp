#include <Path.h>

Path::Path()
{
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


