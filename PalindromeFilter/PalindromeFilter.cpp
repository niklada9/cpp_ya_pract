// PalindromeFilter.cpp : returns all palindrome strings from the vector words with length at least min_length.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// determines if the string s is a palindrome
bool IsPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromeFilter(vector<string> words, int min_length) {
    string word;// This function should call the IsPalindrome function written above.
    vector<string> nwords;
    int i;
    for (i = 0; i < words.size(); ++i) {
        word = words[i];
            if (IsPalindrome(word) && (word.size() >= min_length)) {
            nwords.push_back(word);
            cout << word << endl;
                    }
            }// Returns from words all palindrome strings with length at least min_length
    return nwords;   
}



int main()
{
    int min_length = 5;
    int i;
    vector <string> words = {"rotor"s, "anna"s, "kayak"s};
    string word;
    PalindromeFilter(words, min_length);
}

