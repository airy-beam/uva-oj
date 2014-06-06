//---------------------------------------------------------------------------
#include <iostream>
#define MAX_DAYS 3700

int main()
{
    int testsNumber;
    std::cin >> testsNumber;

    for (int tests=0; tests<testsNumber; tests++)
    {
        int i, j;
        int days;
	std::cin >> days;
        int parties;
	std::cin >> parties;
        bool hartals[MAX_DAYS];
        for (i=0; i<MAX_DAYS; i++) hartals[i] = false;

        for (i=0; i<parties; i++)
        {
            int h;
	    std::cin >> h;
            int dayNo = 0;
            while (dayNo <= days)
            {
                hartals[dayNo] = true;
                dayNo+=h;
            }
        }

        int count = 0;
        for (i=1; i<=days; i++)
            if (hartals[i] && ((i+1) % 7!=0) && (i % 7!=0) ) count+=1;
	std::cout << count << std::endl;
    }
    return 0;
}
//---------------------------------------------------------------------------
 
