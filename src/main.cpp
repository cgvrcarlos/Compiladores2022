#include <Automata.h>

int main(int argc, char const *argv[])
{
	Automata a1("probe.txt");

	a1.print();

	a1.completeAutomata();

	a1.print();

	a1.analizeString("+paz.");
	
	a1.printPaths();

	return 0;
}
