#include <iostream>
#include <vector>
using namespace std;
int binarysearch(int arr[], int n, int element)
{
    int low = 0;
    int high = n - 1;
    int mid = low + high / 2;
    while (low <= high)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        if (element > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = low + high / 2;
    }
    return -1;
}
int main()
{
    cout << "Enter how many random elemnts" << endl;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the element to be searched" << endl;
    int searchelement;
    cin >> searchelement;
    vector<int> searchkey;
    int result = binarysearch(arr, n, searchelement);
    cout << "search is successfull at index" << result;

    return 0;
}