#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to display the array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int choice, n;
    int *arr;

    while (true)
    {
        cout << "\nMAX-HEAP & PRIORITY QUEUE MENU" << endl;
        cout << "0. Quit" << endl;
        cout << "1. Generate n Random numbers => Array" << endl;
        cout << "2. Display the Array" << endl;
        cout << "3. Sort the Array in Ascending Order by using Max-Heap Sort technique" << endl;
        cout << "4. Sort the Array in Descending Order" << endl;
        cout << "5. Time Complexity to sort ascending of random data" << endl;
        cout << "6. Time Complexity to sort ascending of data already sorted in ascending order" << endl;
        cout << "7. Time Complexity to sort ascending of data already sorted in descending order" << endl;
        cout << "8. Time Complexity to sort ascending all Cases (Data Ascending, Data in Descending & Random Data)" << endl;
        cout << "9. Extract largest element" << endl;
        cout << "10. Replace value at a node with a new value" << endl;
        cout << "11. Insert a new element" << endl;
        cout << "12. Delete an element" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting the program." << endl;
            exit(0);

        case 1:
            cout << "Enter the number of elements (n): ";
            cin >> n;
            if (arr != nullptr)
            {
                delete[] arr;
            }
            arr = new int[n];
            // Generate n random numbers and store them in the array
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % 1000; // Modify the range as needed
            }
            cout << "Random numbers generated and stored in the array." << endl;
            break;

        case 2:
            cout << "Array elements: ";
            displayArray(arr, n);
            break;

        case 3:
            heapSort(arr, n);
            cout << "Array sorted in ascending order using Max-Heap Sort." << endl;
            break;

        case 8:
            // Time complexity for all cases
            cout << "n\tRandom Data\tAscending Data\tDescending Data" << endl;
            for (n = 5000; n <= 50000; n += 5000)
            {
                arr = new int[n];
                // Generate random data
                for (int i = 0; i < n; i++)
                {
                    arr[i] = rand() % 1000;
                }
                // start = high_resolution_clock::now();
                // heapSort(arr, n);
                // stop = high_resolution_clock::now();
                // duration = duration_cast<microseconds>(stop - start);
                // long long randomTime = duration.count();

                // Generate ascending data
                for (int i = 0; i < n; i++)
                {
                    arr[i] = i;
                }
                // start = high_resolution_clock::now();
                // heapSort(arr, n);
                // stop = high_resolution_clock::now();
                // duration = duration_cast<microseconds>(stop - start);
                // long long ascendingTime = duration.count();

                // Generate descending data
                for (int i = 0; i < n; i++)
                {
                    arr[i] = n - i;
                }
                // start = high_resolution_clock::now();
                // heapSort(arr, n);
                // stop = high_resolution_clock::now();
                // duration = duration_cast<microseconds>(stop - start);
                // long long descendingTime = duration.count();

                // cout << n << "\t" << randomTime << "\t\t" << ascendingTime << "\t\t" << descendingTime << endl;

                delete[] arr;
            }
            break;

            // Implement other menu options as needed

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }

    delete[] arr;
    return 0;
}
