#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct HuffmanNode
{
    char symbol;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char s, int f) : symbol(s), frequency(f), left(nullptr), right(nullptr) {}
};

struct CompareHuffmanNodes
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->frequency > b->frequency;
    }
};

void generateHuffmanCodes(HuffmanNode *root, string code, unordered_map<char, string> &huffmanCodes)
{
    if (root == nullptr)
        return;

    if (root->symbol != '\0')
    {
        huffmanCodes[root->symbol] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main()
{
    int numSymbols;
    cout << "Enter the number of symbols: ";
    cin >> numSymbols;

    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareHuffmanNodes> minHeap;

    for (int i = 0; i < numSymbols; i++)
    {
        char symbol;
        int frequency;
        cout << "Enter symbol and its frequency: ";
        cin >> symbol >> frequency;
        HuffmanNode *node = new HuffmanNode(symbol, frequency);
        minHeap.push(node);
    }

    while (minHeap.size() > 1)
    {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();
        HuffmanNode *merged = new HuffmanNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }

    HuffmanNode *root = minHeap.top();

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (const auto &pair : huffmanCodes)
    {
        cout << pair.first << "=" << pair.second << " ";
    }
    cout << endl;

    return 0;
}
