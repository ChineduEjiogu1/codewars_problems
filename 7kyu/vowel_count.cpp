#include <iostream>
#include <string>
using namespace std;

int getCount(string word)
{
    char a = 'a';
    char e = 'e';
    char i_ = 'i';
    char o = 'o';
    char u = 'u';

    // size_t find (char a, size_t pos = 0);
    int vowelCounter = 0;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == a || word[i] == e || word[i] == i_ || word[i] == o || word[i] == u)
        {
            vowelCounter++;
        }
    }
    return vowelCounter;
}

int main() 
{
    // Test cases
    string test1 = "hello";
    string test2 = "world";
    string test3 = "aeiou";
    string test4 = "sky";
    string test5 = "This is a simple sentence.";

    // Output results
    cout << "Test 1: \"" << test1 << "\" has " << getCount(test1) << " vowels.\n";
    cout << "Test 2: \"" << test2 << "\" has " << getCount(test2) << " vowels.\n";
    cout << "Test 3: \"" << test3 << "\" has " << getCount(test3) << " vowels.\n";
    cout << "Test 4: \"" << test4 << "\" has " << getCount(test4) << " vowels.\n";
    cout << "Test 5: \"" << test5 << "\" has " << getCount(test5) << " vowels.\n";

    return 0;
}