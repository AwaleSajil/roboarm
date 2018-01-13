#include <iostream>
using namespace std;

void sequence(bool* seq, bool direction)
{
    bool Tp = (seq[0] ^ seq[1] ^ direction);
    //toggle
    if(Tp)
    {
        seq[1] = !(seq[1]);
    }
    else
    {
        seq[0] = !(seq[0]);
    }
}

int main()
{
    bool seq[2];
    seq[0] = 0;
    seq[1] = 0;
    cout << "clockwise"<< endl;
    for(int i = 0; i< 8; i++)
    {
        cout << seq[1] << "  " << seq[0] <<endl;
        sequence(seq,0);
    }

    cout << "anti clockwise"<< endl;
    for(int i = 0; i< 8; i++)
    {
        cout << seq[1] << "  " << seq[0] <<endl;
        sequence(seq,1);
    }
    return 0;
}
