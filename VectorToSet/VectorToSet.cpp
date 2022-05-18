// VectorToSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> VectorToSet(vector <string> line) {
    set<string> setline(line.begin(), line.end());
    return setline;
}

vector<string> SplitIntoWords(string text) {
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
    string stopword;
    //getline(cin, stopword);
    stopword = "with many very"s;
    vector<string> vectorstopword = SplitIntoWords(stopword);
    /* Считайте строку со стоп-словами */
    set<string> setstopword = VectorToSet(vectorstopword);

    // Считываем строку-запрос
    string query;
    //getline(cin, query);
    query = "very kind dog with brown fur with long long tail "s;
    vector<string> fin;
    vector<string> vectorquery = SplitIntoWords(query);
    for (string v : vectorquery) {
        if (setstopword.count(v) == 0) {
             fin.push_back(v);
        }
    }
    // Выведите только те слова, которых нет среди стоп-слов
    for (string word : fin) {
        cout << '[' << word << ']' << endl;
    }
}

