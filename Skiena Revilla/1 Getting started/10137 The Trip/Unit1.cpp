//---------------------------------------------------------------------------
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void sort(unsigned long * studentExpenses, unsigned long size);
void swap(unsigned long& a, unsigned long& b);
unsigned long average(unsigned long * studentExpenses, unsigned long size);
unsigned long sum(unsigned long * studentExpenses, unsigned long size);

int main()
{
    using namespace std;
    unsigned long n;
    unsigned long i;
    char expenseDecimal[10], expenseCents[10];
    for (;;)
    {
        if (!(cin >> n)) break;
        if (n == 0) break;
        unsigned long * studentExpenses = new unsigned long[n];
        for (i=0; i<n; i++)
        {
            cin >> expenseDecimal;
            unsigned long k = 0;
            for (unsigned long j=0; j<strlen(expenseDecimal); j++)
                if (expenseDecimal[j]!='.')
                {
                    expenseCents[k] = expenseDecimal[j];
                    k+=1;
                }
            expenseCents[k] = '\0';
            studentExpenses[i] = atol(expenseCents);
        }
        sort(studentExpenses, n);
        unsigned long averageExpense = average(studentExpenses, n);
        unsigned long extraCents = sum(studentExpenses, n) - averageExpense * n;
        unsigned long transfer = 0;
        signed long tryTransfer = 0;
        i = 0;
        do
        {
            if ((i+1)<=n-extraCents) tryTransfer=averageExpense-studentExpenses[i];
            else                     tryTransfer=averageExpense-studentExpenses[i]+1;
            if (tryTransfer>0) transfer+=tryTransfer;
            i+=1;
        } while ( i<n );
        cout.setf(ios::fixed, ios::floatfield);
        cout.setf(ios::showpoint);
        cout.precision(2);
        long double answer;
        answer = ( long double ) transfer / 100;
        cout << "$" << answer << endl;
        delete [] studentExpenses;
    }
    return 0;
}

void sort(unsigned long * studentExpenses, unsigned long size)
{
    for (unsigned long i=0; i<size; i++)
        for (unsigned long j=0; j<size-1; j++)
            if (studentExpenses[j]>studentExpenses[j+1])
                swap(studentExpenses[j],studentExpenses[j+1]);
}

void swap(unsigned long& a, unsigned long& b)
{
    unsigned long temp = a;
    a = b;
    b = temp;
}

unsigned long average(unsigned long * studentExpenses, unsigned long size)
{
    return sum(studentExpenses, size) / size;
}

unsigned long sum(unsigned long * studentExpenses, unsigned long size)
{
    unsigned long sum = 0;
    for (unsigned long i=0; i<size; i++)
        sum+=studentExpenses[i];
    return sum;
}
//---------------------------------------------------------------------------
