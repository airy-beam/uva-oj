#include <iostream>
#include <string.h>

using std::string;

void sort(string&);

int main(int argc, char** argv) {
    using namespace std;
    string string1, string2, common;
    while (getline(cin, string1))
    {
        getline(cin, string2);
        common = "";
        for (int i = 0; i < string1.length( ); i++)
        {
            std::string::size_type pos = string2.find(string1[i]);
            if (pos != -1)
            {
                common += string1[i];
                string2.erase(pos, 1);
            }
        }
        sort(common);
        cout << common << endl;
    }
    
    return 0;
}

void sort(string& s)
{
    char t;
    for (int i = 0; i < s.length( ); i++)
        for (int i = 0; i < s.length( ) - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                t = s[i];
                s[i] = s[i+1];
                s[i+1] = t;
            }
        }
}

