#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> roundMatrix(const std::vector<std::vector<float>> &inputMatrix)
{
    int n = inputMatrix.size();
    std::vector<std::vector<int>> roundedMatrix(n, std::vector<int>(n, 0));

    std::vector<int> rowSums(n, 0);
    std::vector<int> colSums(n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rowSums[i] += std::floor(inputMatrix[i][j]);
            colSums[j] += std::floor(inputMatrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (rowSums[i] < std::ceil(inputMatrix[i][j]))
            {
                roundedMatrix[i][j] = std::floor(inputMatrix[i][j]);
                rowSums[i] += std::floor(inputMatrix[i][j]);
                colSums[j] += std::floor(inputMatrix[i][j]);
            }
            else
            {
                roundedMatrix[i][j] = std::ceil(inputMatrix[i][j]);
                rowSums[i] += std::ceil(inputMatrix[i][j]);
                colSums[j] += std::ceil(inputMatrix[i][j]);
            }
        }
    }

    return roundedMatrix;
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<std::vector<float>> inputMatrix(n, std::vector<float>(n));

    // Input the matrix elements
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << "Enter element at row " << i + 1 << ", column " << j + 1 << ": ";
            std::cin >> inputMatrix[i][j];
        }
    }

    // Get the rounded matrix
    std::vector<std::vector<int>> roundedMatrix = roundMatrix(inputMatrix);

    // Display the rounded matrix
    std::cout << "Rounded matrix:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << roundedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
