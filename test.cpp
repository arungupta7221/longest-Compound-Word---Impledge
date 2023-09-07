#include <gtest/gtest.h>
#include "Trie.h" // Include the header file for your Trie class

// Test case for Trie::insert function
TEST(TrieTest, InsertTest)
{
    Trie trie;

    // Insert a word
    trie.insert("apple");

    // Check if the word is present in the Trie
    EXPECT_TRUE(trie.contains("apple"));

    // Insert another word
    trie.insert("banana");

    // Check if both words are present in the Trie
    EXPECT_TRUE(trie.contains("apple"));
    EXPECT_TRUE(trie.contains("banana"));

    // Check a word that was not inserted
    EXPECT_FALSE(trie.contains("orange"));
}

// Test case for Trie::getSuffixesStartIndices function
TEST(TrieTest, GetSuffixesStartIndicesTest)
{
    Trie trie;

    // Insert some words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Check the suffixes of "apple"
    vector<int> suffixes = trie.getSuffixesStartIndices("apple");
    EXPECT_EQ(suffixes.size(), 2); // "apple" has two suffixes
    EXPECT_EQ(suffixes[0], 3);     // "p" is a suffix starting at index 3
    EXPECT_EQ(suffixes[1], 4);     // "le" is a suffix starting at index 4

    // Check the suffixes of "app"
    suffixes = trie.getSuffixesStartIndices("app");
    EXPECT_EQ(suffixes.size(), 1); // "app" has one suffix
    EXPECT_EQ(suffixes[0], 2);     // "p" is a suffix starting at index 2

    // Check the suffixes of "banana"
    suffixes = trie.getSuffixesStartIndices("banana");
    EXPECT_EQ(suffixes.size(), 0); // "banana" has no suffixes
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
