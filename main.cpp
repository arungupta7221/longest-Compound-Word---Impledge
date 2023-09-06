#include <chrono> // Include chrono for time measurement
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

// Pair class definition
template <typename T>
class Pair
{
public:
    T first;
    T second;

    Pair(T f, T s) : first(f), second(s) {}
};

// Trie class definition
class Trie
{
private:
    struct TrieNode
    {
        char val;
        unordered_map<char, TrieNode *> children;
        bool isWord;

        TrieNode(char c) : val(c), isWord(false) {}
    };

    TrieNode *root;
    TrieNode *curr;

public:
    Trie()
    {
        root = new TrieNode(' ');
        curr = root;
    }

    void insert(string s)
    {
        char letter;
        curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            letter = s[i];

            if (curr->children.find(letter) == curr->children.end())
            {
                curr->children[letter] = new TrieNode(letter);
            }

            curr = curr->children[letter];
        }

        curr->isWord = true;
    }

    vector<int> getSuffixesStartIndices(string s)
    {
        vector<int> indices;
        char letter;
        curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            letter = s[i];

            if (curr->children.find(letter) == curr->children.end())
            {
                return indices;
            }

            curr = curr->children[letter];

            if (curr->isWord)
            {
                indices.push_back(i + 1);
            }
        }

        return indices;
    }
};

int main()
{
    // Change the file name accordingly
    ifstream file("input01.txt");

    Trie trie;
    queue<Pair<string>> wordQueue;

    string word;
    vector<int> sufIndices;

    while (file >> word)
    {
        sufIndices = trie.getSuffixesStartIndices(word);

        for (int i : sufIndices)
        {
            if (i >= word.length())
            {
                break;
            }
            wordQueue.push(Pair<string>(word, word.substr(i)));
        }

        trie.insert(word);
    }

    string longest = "";
    string secondLongest = "";
    int maxLength = 0;

    // Measure time taken (start)
    auto start = high_resolution_clock::now();

    while (!wordQueue.empty())
    {
        Pair<string> p = wordQueue.front();
        wordQueue.pop();
        string currentWord = p.second;
        sufIndices = trie.getSuffixesStartIndices(currentWord);

        if (sufIndices.empty())
        {
            continue;
        }

        for (int i : sufIndices)
        {
            if (i > currentWord.length())
            {
                break;
            }

            if (i == currentWord.length())
            {
                if (p.first.length() > maxLength)
                {
                    secondLongest = longest;
                    maxLength = p.first.length();
                    longest = p.first;
                }
            }
            else
            {
                wordQueue.push(Pair<string>(p.first, currentWord.substr(i)));
            }
        }
    }

    // Measure time taken (end)
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Print out the results
    cout << "Longest Compound Word: " << longest << endl;
    cout << "Second Longest Compound Word: " << secondLongest << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
