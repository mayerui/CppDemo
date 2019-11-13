#include <iostream>
#include <string>

using namespace std;

int main()
{
    char s[8] = {0};
    memcpy(s, "698001", 6);
    string str(s, sizeof(s));   //"698001\0\0" , size=8

    cout << ((str == string("698001")) ? "true" : "false") << endl; //string("698001"), size=6
    getchar();

    return 0;
}