#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int num, guess, nguess = 1;
    srand(time(0));
    num = rand() % 100 + 1;
    int low = 1;
    int high = 100;

    while (true)
    {
        guess = (low + high) / 2;
        cout << "Is the number " << guess << "?" << endl;
        char response;
        cout << "Enter 's' for smaller, 'b' for bigger, or 'c' for correct: ";
        cin >> response;

        if (response == 's')
        {
            high = guess - 1;
        }
        else if (response == 'b')
        {
            low = guess + 1;
        }
        else if (response == 'c')
        {
            cout << "You Got it" << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 's', 'b', or 'c'." << endl;
        }
        nguess++;
    }

    return 0;
}
