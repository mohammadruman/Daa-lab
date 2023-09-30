
// Menu driven
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

// Function to display the array
void displayArray(int arr[], int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform Max Heapify
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

// Function to build a Max Heap
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}

// Function to calculate time taken to sort ascending
double calculateTime(int arr[], int n)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    heapSort(arr, n);

    gettimeofday(&end, NULL);
    double elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    return elapsedTime;
}

// Function to measure time complexity for ascending sorted data
double measureTimeComplexityAscending(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = i; // Already sorted in ascending order
    }

    double timeTaken = calculateTime(arr, n);
    free(arr);
    return timeTaken;
}

// Function to measure time complexity for descending sorted data
double measureTimeComplexityDescending(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1; // Sorted in descending order
    }

    double timeTaken = calculateTime(arr, n);
    free(arr);
    return timeTaken;
}

// Function to measure time complexity for random data
double measureTimeComplexityRandom(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    double timeTaken = calculateTime(arr, n);
    free(arr);
    return timeTaken;
}

int main()
{
    int choice;
    int n;
    int *arr = NULL;
    _Bool isArrayGenerated = false;

    while (1)
    {
        printf("\nMAX-HEAP & PRIORITY QUEUE MENU\n");
        printf("0.Quit\n");
        printf("1.n Random numbers => Array\n");
        printf("2.Display the Array\n");
        printf("3.Sort the Array in Ascending Order by using Max-Heap Sort technique\n");
        printf("4.Sort the Array in Descending Order by using any algorithm\n");
        printf("5.Time Complexity to sort ascending of random data\n");
        printf("6.Time Complexity to sort ascending of data already sorted in ascending order\n");
        printf("7.Time Complexity to sort ascending of data already sorted in descending order\n");
        printf("8.Time Complexity to sort ascending all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            free(arr);
            exit(0); // Exit the program
        case 1:
            printf("Enter the number of elements (n): ");
            scanf("%d", &n);
            arr = (int *)malloc(n * sizeof(int));
            if (arr == NULL)
            {
                printf("Memory allocation failed.\n");
                exit(1);
            }
            srand(time(NULL)); // Seed the random number generator
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % 100; // Generating random numbers between 0 and 99
            }
            isArrayGenerated = true;
            break;
        case 2:
            if (!isArrayGenerated)
            {
                printf("Array not generated yet.\n");
                break;
            }
            displayArray(arr, n);
            break;
        case 3:
            if (!isArrayGenerated)
            {
                printf("Array not generated yet.\n");
                break;
            }
            heapSort(arr, n);
            printf("Array sorted in ascending order.\n");
            break;
        case 4:
            // Implement sorting in descending order using any algorithm
            break;
        case 5:
            if (!isArrayGenerated)
            {
                printf("Array not generated yet.\n");
                break;
            }
            double timeTaken = calculateTime(arr, n);
            printf("Time taken to sort ascending: %f seconds\n", timeTaken);
            break;
        case 6:
            printf("Enter the value of n (sorted in ascending order): ");
            scanf("%d", &n);
            timeTaken = measureTimeComplexityAscending(n);
            printf("Time taken to sort ascending of data already sorted in ascending order (n=%d): %f seconds\n", n, timeTaken);
            break;
        case 7:
            printf("Enter the value of n (sorted in descending order): ");
            scanf("%d", &n);
            timeTaken = measureTimeComplexityDescending(n);
            printf("Time taken to sort ascending of data already sorted in descending order (n=%d): %f seconds\n", n, timeTaken);
            break;
        case 8:
            printf("n\tRandom Data\tAscending Data\tDescending Data\n");
            for (int i = 5000; i <= 50000; i += 5000)
            {
                double randomTime = measureTimeComplexityRandom(i);
                double ascendingTime = measureTimeComplexityAscending(i);
                double descendingTime = measureTimeComplexityDescending(i);
                printf("%d\t%f\t%f\t%f\n", i, randomTime, ascendingTime, descendingTime);
            }
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
