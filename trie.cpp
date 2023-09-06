#include <iostream>
#include <unordered_map>
#include <vector>

class Trie
{
private:
    struct TrieNode
    {
        char val;
        std::unordered_map<char, TrieNode *> children;
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

    void insert(std::string s)
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

    std::vector<int> getSuffixesStartIndices(std::string s)
    {
        std::vector<int> indices;
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
