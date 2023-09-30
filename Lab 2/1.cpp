#include <iostream>
using namespace std;
int gcd(int m, int n)
{
    int t = (m < n) ? m : n;

    while (t > 0)
    {
        if (m % t == 0 && n % t == 0)
        {
            return t;
        }
        t--;
    }

    return 1;
}
int euclid_algorith(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        int algorithm = euclid_algorith(b, a % b);
        return algorithm;
    }
}

int main()
{
    int a, b;
    cout << "enter the two number" << endl;
    cin >> a >> b;
    int result = euclid_algorith(a, b);
    cout << "The gcd of these two number " << result << endl;
    int consecutive_integer = gcd(a, b);
    cout << "Tje gcd of two num by consecutive integer is :" << consecutive_integer;
    return 0;
}