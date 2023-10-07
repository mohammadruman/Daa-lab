#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compareItems(const Item &a, const Item &b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

void fractionalKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    vector<int> selectedWeights(items.size(), 0);

    for (int i = 0; i < items.size(); i++)
    {
        if (capacity >= items[i].weight)
        {
            selectedWeights[i] = items[i].weight;
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            selectedWeights[i] = capacity;
            totalValue += (double)capacity / items[i].weight * items[i].value;
            break;
        }
    }

    cout << "Selected weights: [ ";
    for (int i = 0; i < selectedWeights.size(); i++)
    {
        cout << selectedWeights[i] << " ";
    }
    cout << "] Total value: " << totalValue << endl;
}

int main()
{
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);

    for (int i = 0; i < numItems; i++)
    {
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> items[i].weight;
        cout << "Enter value for item " << i + 1 << ": ";
        cin >> items[i].value;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    fractionalKnapsack(items, capacity);

    return 0;
}
