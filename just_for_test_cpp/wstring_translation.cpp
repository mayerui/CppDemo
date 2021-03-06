#include <locale>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const std::wstring s2ws(const std::string &s);
const std::string ws2s(const std::wstring &s);

int main()
{
    wstring ws = s2ws("cvt_buf");
    string s = ws2s(L"cvt_buf");
    remove(s.c_str());
    return 0;
}

const std::wstring s2ws(const std::string &s)
{
    std::ofstream ofs("cvt_buf");
    ofs << s;
    ofs.close();

    std::wifstream wifs("cvt_buf");
    wifs.imbue(std::locale(""));
    std::wstring wstr;
    wifs >> wstr;
    wifs.close();

    return wstr;
}

const std::string ws2s(const std::wstring &s)
{
    std::wofstream wofs("cvt_buf");
    wofs.imbue(std::locale(""));
    wofs << s;
    wofs.close();

    std::ifstream ifs("cvt_buf");
    std::string str;
    ifs >> str;
    ifs.close();

    return str;
}