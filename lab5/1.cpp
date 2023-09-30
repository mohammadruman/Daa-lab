// #include <iostream>
// #include <time.h>
// using namespace std;
// int main()
// {
//     int num, guess, nguess = 1;
//     srand(time(0));
//     num = rand() % INT_MAX + 1;
//     cout << num;

//     do
//     {
//         cout << "Guess the number between 1 and 100" << endl;
//         cin >> guess;
//         if (guess > num)
//         {
//             cout << "Try a smaller number" << endl;
//         }
//         else if (guess < num)
//         {
//             cout << "Try a bigger number" << endl;
//         }

//         else
//         {
//             cout << "You Got it" << endl;
//         }
//         nguess++;

//     } while (guess != num);

//     return 0;
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int lowerBound = 1;
    const int upperBound = 100;

    srand(time(0));
    int num = rand() % (upperBound - lowerBound + 1) + lowerBound;

    int guess, nguess = 0;
    int low = lowerBound, high = upperBound;

    cout << "Guess the number between " << lowerBound << " and " << upperBound << endl;

    do
    {
        // Use binary search to make a guess
        guess = (low + high) / 2;
        cout << "Is the number " << guess << "? (high/low/correct): ";
        string response;
        cin >> response;
        nguess++;

        if (response == "high")
        {
            high = guess - 1;
        }
        else if (response == "low")
        {
            low = guess + 1;
        }
        else if (response == "correct")
        {
            cout << "You Got it!" << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'high', 'low', or 'correct'." << endl;
        }
    } while (true);

    cout << "Number of guesses: " << nguess << endl;

    return 0;
}
