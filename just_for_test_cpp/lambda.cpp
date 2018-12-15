#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> a = {"1", "2"};

    sort(a.begin(),a.end(), [](string c, string d) -> bool { return c > d; });

    for(auto i : a)
    {
        cout << i << endl;
    }

    getchar();
    return 0;
}