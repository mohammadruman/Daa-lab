#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <map>

using namespace std;

int insertionSort(vector<int> &arr)
{
    int steps = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
            ++steps;
        }
        arr[j + 1] = key;
        ++steps;
    }
    return steps;
}

vector<int> generateRandomArray(int n)
{
    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(rand() % 1000 + 1);
    }
    return arr;
}

pair<double, int> timeInsertionSort(vector<int> &arr)
{
    auto start_time = chrono::high_resolution_clock::now();
    int steps = insertionSort(arr);
    auto end_time = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() / 1e9;
    return make_pair(time_taken, steps);
}

int main()
{
    map<int, string> data_types = {
        {1, "Random Data"},
        {2, "Sorted in Ascending Order"},
        {3, "Sorted in Descending Order"}};

    vector<int> array;

    while (true)
    {
        cout << "\nINSERTION SORT MENU" << endl;
        cout << "0. Quit" << endl;
        cout << "1. Generate n Random numbers and create an Array" << endl;
        cout << "2. Display the Array" << endl;
        cout << "3. Sort the Array in Ascending Order using Insertion Sort" << endl;
        cout << "4. Sort the Array in Descending Order" << endl;
        cout << "5. Time Complexity to sort ascending of Random Data" << endl;
        cout << "6. Time Complexity to sort ascending of Sorted Data" << endl;
        cout << "7. Time Complexity to sort ascending of Reversely Sorted Data" << endl;
        cout << "8. Time Complexities in tabular form" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            array = generateRandomArray(n);
            cout << "Array created." << endl;
        }
        else if (choice == 2)
        {
            for (int num : array)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        else if (choice == 3)
        {
            int steps = insertionSort(array);
            cout << "Array sorted in ascending order using Insertion Sort." << endl;
            cout << "Number of steps: " << steps << endl;
        }
        else if (choice == 4)
        {
            sort(array.rbegin(), array.rend());
            cout << "Array sorted in descending order." << endl;
        }
        else if (choice == 5)
        {
            pair<double, int> result = timeInsertionSort(array);
            cout << "Time taken to sort random data: " << result.first << " seconds" << endl;
            cout << "Number of steps: " << result.second << endl;
        }
        else if (choice == 6)
        {
            vector<int> sorted_array = array;
            sort(sorted_array.begin(), sorted_array.end());
            pair<double, int> result = timeInsertionSort(sorted_array);
            cout << "Time taken to sort ascending sorted data: " << result.first << " seconds" << endl;
            cout << "Number of steps: " << result.second << endl;
        }
        else if (choice == 7)
        {
            vector<int> reversed_array = array;
            sort(reversed_array.rbegin(), reversed_array.rend());
            pair<double, int> result = timeInsertionSort(reversed_array);
            cout << "Time taken to sort ascending reversed data: " << result.first << " seconds" << endl;
            cout << "Number of steps: " << result.second << endl;
        }
        else if (choice == 8)
        {
            cout << "n\tRandom Data\tAscending Data\tDescending Data" << endl;
            for (int n = 5000; n <= 50000; n += 5000)
            {
                vector<int> random_data = generateRandomArray(n);
                vector<int> ascending_data = generateRandomArray(n);
                sort(ascending_data.begin(), ascending_data.end());
                vector<int> descending_data = generateRandomArray(n);
                sort(descending_data.rbegin(), descending_data.rend());

                pair<double, int> random_time = timeInsertionSort(random_data);
                pair<double, int> ascending_time = timeInsertionSort(ascending_data);
                pair<double, int> descending_time = timeInsertionSort(descending_data);

                cout << n << "\t" << random_time.first << "s (" << random_time.second << " steps)\t"
                     << ascending_time.first << "s (" << ascending_time.second << " steps)\t"
                     << descending_time.first << "s (" << descending_time.second << " steps)" << endl;
            }
        }
    }
    cout << "Program terminated." << endl;
    return 0;
}