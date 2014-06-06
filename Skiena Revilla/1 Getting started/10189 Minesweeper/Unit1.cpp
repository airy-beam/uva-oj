//---------------------------------------------------------------------------
#include <iostream>

int CountMines(int, int);

bool field[1002][1002];

int main()
{
    using namespace std;
    int n, m;
    char line[1000];
    int fieldNo = 1;
    for (;;)
    {
        if (!(cin >> n >> m)) break;
        if (n == 0 && m == 0) break;
        if (fieldNo>1)
            cout << endl;
        for (int row=0; row<=n+1; row++)
            for (int column=0; column<=m+1; column++)
                field[row][column] = false;
        for (int row=1; row<=n; row++)
        {
            cin >> line;
            for (int column=1; column<=m; column++)
                if (line[column-1]=='*') field[row][column]=true; else
                                       field[row][column]=false;
        }
        cout << "Field #" << fieldNo << ":" << endl;
        for (int row=1; row<=n; row++)
        {
            for (int column=1; column<=m; column++)
                if (field[row][column]) cout << "*"; else cout << CountMines(row, column);
            cout << endl;
        }

        fieldNo+=1;
    }
    return 0;
}

int CountMines(int row, int column)
{
    int count = 0;
    count = field[row-1][column-1] +
            field[row][column-1] +
            field[row+1][column-1] +
            field[row-1][column] +
            field[row+1][column] +
            field[row-1][column+1] +
            field[row][column+1] +
            field[row+1][column+1];
    return count;
}
//---------------------------------------------------------------------------
 
