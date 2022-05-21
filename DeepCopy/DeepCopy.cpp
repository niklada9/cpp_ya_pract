// DeepCopy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// final050.cpp

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitIntoWords(string& text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = ""s;
        }
        else {
            word += text[i];
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWords(string& text) {
    set<string> stop_words;
    for (string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(string& text, set<string>& stop_words) {
    vector<string> words;
    for (string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}


int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);

    for (string word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
