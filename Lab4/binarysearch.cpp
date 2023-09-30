#include <iostream>
using namespace std;
#include <vector>

bool binarySearch(const std::vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

bool modifiedBinarySearch(const std::vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = right - 2; // Modified formula
        if (mid < 0)
        { // Handle negative mid index
            mid = 0;
        }
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    std::vector<int> inputArray = {2, 5, 7, 7, 9, 11, 12, 12, 17, 19};
    std::vector<int> searchKeys = {3, 2, 15, 12};

    for (int key : searchKeys)
    {
        cout << "Binary search: " << (binarySearch(inputArray, key) ? "yes" : "no") << ", " << endl;
        cout << "Modified binary search: " << (modifiedBinarySearch(inputArray, key) ? "yes" : "no") << std::endl;
    }

    return 0;
}