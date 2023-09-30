#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}
void mergeSort(vector<int> &arr)
{
    int n = arr.size();

    for (int currSize = 1; currSize <= n - 1; currSize *= 2)
    {
        for (int left = 0; left < n - 1; left += 2 * currSize)
        {
            int mid = min(left + currSize - 1, n - 1);
            int right = min(left + 2 * currSize - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        }

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
