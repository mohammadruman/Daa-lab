#include <iostream>
using namespace std;

int comparison = 0;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            count++;
        comparison++;
    }

    int pivotindex = s + count;

    swap(arr[pivotindex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotindex && j > pivotindex)
    {

        while (arr[i] <= pivot)
        {
            i++;
            comparison++;
        }

        while (arr[j] > pivot)
        {
            j--;
            comparison++;
        }

        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotindex;
}

void quicksort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int piindex = partition(arr, s, e);

    // left call
    quicksort(arr, s, piindex - 1);

    // right call
    quicksort(arr, piindex + 1, e);
}

int main()
{
    int arr[] = {7, 9, 2, 11, 19, 17, 12, 5, 7, 12};
    int size = 10;
    quicksort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparison << endl;

    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// int main(){
//     int number, guess, nguesses=1;
//     srand(time(0));
//     number = rand()%100 + 1; // Generates a random number between 1 and 100
//     // printf("The number is %d\n", number);
//     // Keep running the loop until the number is guessed
//     do{
//         printf("Guess the number between 1 to 100\n");
//         scanf("%d", &guess);
//         if(guess>number){
//             printf("Lower number please!\n");
//         }
//         else if(guess<number){
//             printf("Higher number please!\n");
//         }
//         else{
//             printf("You guessed it in %d attempts\n", nguesses);
//         }
//         nguesses++;
//     }while(guess!=number);

//     return 0;
// }