#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <random>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

double measureCPUTime(int arr[], int n)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    return duration.count();
}

void generateSortedArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }
}

void generateReversedArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = n - i;
    }
}

void generateRandomArray(int arr[], int n)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 10000);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = distribution(generator);
    }
}

int main()
{
    int input_sizes[] = {100, 500, 1000, 2000, 3000};
    int max_size = 3000;

    std::cout << "Input Size\tBest Case\tWorst Case\tAverage Case\n";

    for (int i = 0; i < sizeof(input_sizes) / sizeof(input_sizes[0]); ++i)
    {
        int size = input_sizes[i];
        int *sorted_array = new int[size];
        int *reversed_array = new int[size];
        int *random_array = new int[size];

        generateSortedArray(sorted_array, size);
        generateReversedArray(reversed_array, size);
        generateRandomArray(random_array, size);

        double best_case_time = measureCPUTime(sorted_array, size);
        double worst_case_time = measureCPUTime(reversed_array, size);
        double average_case_time = measureCPUTime(random_array, size);

        std::cout << size << "\t\t" << best_case_time << "\t\t" << worst_case_time << "\t\t" << average_case_time << "\n";

        delete[] sorted_array;
        delete[] reversed_array;
        delete[] random_array;
    }

    return 0;
}