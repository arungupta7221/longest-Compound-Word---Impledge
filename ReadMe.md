# Code Execution Process

1. Download / Clone the repo into your machine.
2. Open the main.cpp file and scroll to the main function with the comment #Change the file name accordingly. here we can pass input file name.
3. Execute the main.cpp file.

# A brief study of the problem

1. Compounded words are the words formed using one or more of the valid words only in the selected file.
2. Since the files are already sorted alphabetically and only contain one word per line some of the the valid words that compose the compounded words are bound to come before the compounded word itself.
3. Thus the compounded word can be thought of as the combination of some of the the words that have been already read i.e. -> prefix, and a suffix.
4. If there is a situation where some character which is not the part of any valid word in the file but occours within any position of the word currently being read. Then the word can not be considered as a compounded word.

# Approach and Algorithm

While researching for this problem , many solutions and related problems were observed out of which the trie based approach was the most easily understandable , effecient and widely used one. So that particular approach has been selected and modified for solving the given problem

The algorithm for the solution :

Step-1. ## Include Necessary Libraries: Import the required C++ libraries for file handling,
data structures, and time measurement. (fstream,unordered_map,queue,vector,string,chrono)

Step-2. ## Define a Pair Class: Create a template class Pair to represent a pair of values.
This class is used to store pairs of words and their remaining suffixes.

Step-3. ## Define the Trie Data Structure: Implement a Trie data structure to efficiently  
 store and retrieve words. It consists of TrieNodes, where each node represents a character in a word.

Step-4. ## Main Function: In the main() function, the primary logic is executed:
Open the input file containing a list of words.
Initialize a Trie data structure and a queue to store word-suffix pairs.
Read each word from the file and add its suffixes to the queue while inserting the word into the Trie.
Find the longest and second-longest compound words while processing the queue.
Measure the execution time using the chrono library.

Step-5. ## Trie Operations: The insert and getSuffixesStartIndices functions in the Trie class
are responsible for inserting words into the Trie and finding suffixes, respectively. You can implement these functions based on the Trie data structure logic.

Step-6. ## Time Measurement: Use the chrono library to measure the execution time of
the algorithm. Start measuring time before processing the queue and end it afterward.

Step-7. ## Print Results: Finally, print the longest and second-longest compound words found
along with the time taken for execution.

## Unit Test

for unit testing I have used 'gtest' testing framework.
here are the steps:-

1. Install Google Test as mentioned in the previous response.
2. Create a C++ source file for your tests, test.cpp.
3. Write the test cases for the Trie class. I have write in 'test.cpp' file.
4. Compile tests and the original code together with the Google Test library. it'll
   need to link against the Google Test library, and the compiled binary will run the tests:


    `g++ -std=c++11 -o main.cpp trie.cpp test.cpp -lgtest -lgtest_main -pthread`

5. Run the compiled binary to execute the unit tests:


    `./main.cpp`
