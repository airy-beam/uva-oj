//---------------------------------------------------------------------------
#include <iostream>

void sort(int * studentExpenses, int size);
void swap(int& a, int& b);
int absoluteValue(int x);

int main()
{
    using namespace std;
    int n;
    while ( true )
    {
        if (!(cin >> n)) break;
        if (n<=0) break;
        int *sequence = new int[n];
        int *differences = new int[n-1];
        for (int i=0; i<n; i++) cin >> sequence[i];
        for (int i=0; i<n-1; i++) differences[i] = absoluteValue(sequence[i+1] - sequence[i]);
        sort(differences, n-1);
        bool jolly = true;
        for (int i=0; i<n-2; i++)
            if (differences[i]+1!=differences[i+1])
            {
                cout << "Not jolly" << endl;
                jolly = false;
                break;
            }
        if (jolly) cout << "Jolly" << endl;
        delete [] sequence;
        delete [] differences;
    }
    return 0;
}

void sort(int * studentExpenses, int size)
{
    for (int i=0; i<size; i++)
        for (int j=0; j<size-1; j++)
            if (studentExpenses[j]>studentExpenses[j+1])
                swap(studentExpenses[j],studentExpenses[j+1]);
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int absoluteValue(int x)
{
    if (x>0) return x; else return (-x);
}
//---------------------------------------------------------------------------
