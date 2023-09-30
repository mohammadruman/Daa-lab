#include <iostream>
#include <vector>

using namespace std;

// Merge function for Merge Sort
void merge(vector<int> &arr, int left, int mid, int right, int &comparisons)
{
    int leftlength = mid - left + 1;
    int rightlength = right - mid;

    vector<int> L(leftlength);
    vector<int> R(rightlength);

    for (int i = 0; i < leftlength; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < rightlength; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftlength && j < rightlength)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < leftlength)
        arr[k++] = L[i++];
    while (j < rightlength)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSort(vector<int> &arr, int left, int right, int &comparisons)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}

// 3-way Merge Sort
void merge3way(vector<int> &arr, int left, int mid1, int mid2, int right, int &comparisons)
{
    int n1 = mid1 - left + 1;
    int n2 = mid2 - mid1;
    int n3 = right - mid2;

    vector<int> L(n1);
    vector<int> M(n2);
    vector<int> R(n3);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[mid1 + 1 + j];
    for (int k = 0; k < n3; k++)
        R[k] = arr[mid2 + 1 + k];

    int i = 0, j = 0, k = 0, l = left;
    while (i < n1 && j < n2 && k < n3)
    {
        comparisons += 2;
        int min_val = min(L[i], min(M[j], R[k]));
        arr[l++] = min_val;

        if (min_val == L[i])
            i++;
        else if (min_val == M[j])
            j++;
        else
            k++;
    }

    while (i < n1)
        arr[l++] = L[i++];
    while (j < n2)
        arr[l++] = M[j++];
    while (k < n3)
        arr[l++] = R[k++];
}

// 3-way Merge Sort
void mergeSort3way(vector<int> &arr, int left, int right, int &comparisons)
{
    if (left < right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2 * (right - left) / 3;

        mergeSort3way(arr, left, mid1, comparisons);
        mergeSort3way(arr, mid1 + 1, mid2, comparisons);
        mergeSort3way(arr, mid2 + 1, right, comparisons);

        merge3way(arr, left, mid1, mid2, right, comparisons);
    }
}

int main()
{
    vector<int> arr = {79, 2, 11, 19, 17, 12, 5, 7, 12};
    int comparisons_merge = 0;
    int comparisons_merge3way = 0;

    mergeSort(arr, 0, arr.size() - 1, comparisons_merge);
    cout << "Merge Sort: [ ";
    for (int num : arr)
        cout << num << " ";
    cout << "] " << comparisons_merge << " comparisons" << endl;

    arr = {79, 2, 11, 19, 17, 12, 5, 7, 12}; // Reset the array
    mergeSort3way(arr, 0, arr.size() - 1, comparisons_merge3way);
    cout << "3-way Merge Sort: [ ";
    for (int num : arr)
        cout << num << " ";
    cout << "] " << comparisons_merge3way << " comparisons" << endl;

    return 0;
}
