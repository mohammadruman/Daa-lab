#include <iostream>
using namespace std;
void check_prime(int num)
{
    int n = 0;
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            n = 0;
            break;
        }
    }
    if (n)
    {
        cout << "the number is prime " << n << endl;
    }
    else
    {
        cout << " the number is not a prime number" << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    check_prime(n);

    return 0;
}