#include <iostream>
#include <string.h>
#define MAX_LENGTH 30

using namespace std;

int char2int(char);

int main() 
{
    int i, j;
    
    for (;;)
    {
        char line[MAX_LENGTH];
        int first[MAX_LENGTH], second[MAX_LENGTH];
        cin.getline(line, MAX_LENGTH);
        string s = line;
        if (s == "0 0") break;
        int spacePos = 0;
        while (line[spacePos]!=' ') spacePos++;
        int firstLength = spacePos;
        for (i=0; i<spacePos; i++) 
            first[i] = char2int(line[i]);
        int secondLength = strlen(line) - spacePos - 1;
        for (i=spacePos+1; i<strlen(line); i++) 
            second[i-spacePos-1] = char2int(line[i]);
        
        int l = max( firstLength, secondLength ) + 1;
        int n1[l], n2[l], result[l];
        for (i=0; i<l; i++)
        {
            n1[i] = 0;
            n2[i] = 0;
            result[i] = 0;
        }
        for (i = firstLength - 1, j=l - 1; i>=0; i--, j--)
            n1[j] = first[i];
        for (i = secondLength - 1, j=l - 1; i>=0; i--, j--)
            n2[j] = second[i];

        int carry = 0;
        int carryCount = 0;
        for (i=l - 1; i>=0; i--)
        {
            result[i] = n1[i] + n2[i] + carry;
            carry = 0;
            if (result[i]>=10)
            {
                result[i] = result[i] % 10;
                carry = 1;
                carryCount ++ ;
            }
        }

        if (carryCount==0)
            cout << "No carry operation." << endl;
        else if (carryCount==1)
            cout << "1 carry operation." << endl;
        else
            cout << carryCount << " carry operations." << endl;
    }
    
    return 0;
}

int char2int(char a)
{
    switch (a)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
    }
}
