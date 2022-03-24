#include <utilities.h>

vector<string> splitString(string str, string pattern)
{
	size_t posInit = 0;
    size_t posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound != string::npos){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}
