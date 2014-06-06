//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#define NCARDS 52
#define NSUITS 4

char values[] = "23456789TJQKA";
char suits[] = "CDHS";

int rank_card(char value, char suit);
char suit(int card);
char value(int card);

int main()
{
    using namespace std;
    int i, j;
    int testsNumber;
    cin >> testsNumber;

    for (int tests=0; tests<testsNumber; tests++)
    {
        vector<int> deck, newDeck;
        newDeck.resize(52);
        for (i=0; i<NSUITS; i++)
            for (j=0; j<NCARDS / NSUITS; j++)
                deck.push_back(rank_card(values[j], suits[i]));

        int tricksCount, val;
        cin >> tricksCount;
        vector<int>* tricks = new vector<int>[tricksCount];
        for (i=0; i<tricksCount; i++)
            for (j=0; j<52; j++)
            {
                cin >> val;
                tricks[i].push_back(val);
            }

        char trick[10]; cin.ignore(1);
        while ( true )
        {
            cin.getline(trick, 10);
            if (strlen(trick)==0) break;
            int trickNumber = atoi(trick);
            for (i=0; i<52; i++)
                newDeck[i] = deck[ tricks[trickNumber-1][i] - 1];
            for (i=0; i<52; i++)
                deck[i] = newDeck[i];
        }

        for (i=0; i<52; i++)
        {
            char valueL = value(deck[i]);
            if (valueL=='T') cout << "10 "; else
            if (valueL=='J') cout << "Jack "; else
            if (valueL=='Q') cout << "Queen "; else
            if (valueL=='K') cout << "King "; else
            if (valueL=='A') cout << "Ace "; else
            cout << valueL << " ";
            char suitL = suit(deck[i]);
            if (suitL=='C') cout << "of Clubs";
            if (suitL=='D') cout << "of Diamonds";
            if (suitL=='H') cout << "of Hearts";
            if (suitL=='S') cout << "of Spades";
            cout << endl;
        }
        if (tests<testsNumber-1) cout << endl;
    }
    return 0;
}

int rank_card(char value, char suit)
{
    int i, j;
    for (i=0; i<(NCARDS/NSUITS); i++)
        if (values[i]==value)
            for (j=0; j<NSUITS; j++)
                if (suits[j]==suit)
                    return ( i*NSUITS + j );
    return -1;
}

char suit(int card)
{
    return ( suits[card % NSUITS] );
}

char value(int card)
{
    return ( values[card/NSUITS] );
}
//---------------------------------------------------------------------------
 
