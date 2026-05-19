#include <iostream>

#include <string>

using namespace std;

bool isAccepted(string str)
{
    int state = 0;

    for(char ch : str)
    {
        switch(state)
        {
            case 0:

                if(ch == 'a')
                    state = 1;
                else
                    state = 3;
                break;


            case 1:
                if(ch == 'a')
                    state = 1;
                else if(ch == 'b')
                    state = 2;

                else
                    state = 3;
                break;

            case 2:
                if(ch == 'b')
                    state = 2;
                else if(ch == 'a')
                    state = 1;

                else
                    state = 3;
                break;

            case 3:
                state = 3;
                break;
        }
    }
    return (state == 1 || state == 2);
}



int main()
{
    string testCases[5] = {
        "a",
        "abbb",
        "aaabbb",
        "ba",
        "bbb"


    };

    for(string str : testCases)
    {
        cout << "Input....: " << str << " --> ";

        if(isAccepted(str))
            cout << "Accepted...." << endl;
        else
            cout << "Rejected....." << endl;
    }

    return 0;
}
