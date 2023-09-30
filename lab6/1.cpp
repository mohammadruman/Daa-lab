#include <iostream>
#include <vector>

using namespace std;
void maxHeapify(vector<int> &arr, int n, int root, int &comparisons)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
        comparisons++;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
        comparisons++;
    }

    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        comparisons++;
        maxHeapify(arr, n, largest, comparisons);
    }
}

void heapSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i, comparisons);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        comparisons++;
        maxHeapify(arr, i, 0, comparisons);
    }
}

int main()
{
    vector<int> arr = {7, 9, 2, 11, 19, 17, 12, 5, 7, 12};
    vector<int> copy = arr;
    int comparisons = 0;

    cout << "Copy: ";
    for (int num : copy)
    {
        cout << num << " ";
    }
    cout << endl;

    heapSort(arr, comparisons);

    cout << "Heap: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Heapsort: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << comparisons << " comparisons" << endl;

    return 0;
}
