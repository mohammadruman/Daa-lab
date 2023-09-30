#include <iostream>
#include <math.h>
using namespace std;
void rowsum(int arr[4][4], int row, int col)
{
    // for each row we have to traversed column
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        // traversing each column for calculating sum
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << " " << endl;
    }
    cout << endl;
}
void colsum(int arr[4][4], int row, int col)
{
    // for each col we have to traversed row
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        // traversing each row for calculating sum
        for (int j = 0; j < row; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << " " << endl;
    }
    cout << endl;
}
void printmatrix(int arr[4][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 8, 9}, {4, 5, 7, 9}};
    printmatrix(arr, 4, 4);
    cout << "Row sum is " << endl;
    rowsum(arr, 4, 4);
    cout << "Col sum is " << endl;
    colsum(arr, 4, 4);

    return 0;
}