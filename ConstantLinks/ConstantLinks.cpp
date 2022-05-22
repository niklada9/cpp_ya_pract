#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

int main() {
    string line = "test search query"s;
    vector<string> lines = SplitIntoWords(line);
    for (const string& s : lines) {
        cout << "["s << s << "] "s;
    }
}