#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
*/

string ReadLine_stop_words() {
    string s = "a an on the in is has been are with for from have be was"s;
    //getline(cin, s);
    return s;
}

string ReadLine(int num) {
    string s;
    vector<string> t;

    t.push_back("a small curly guinea pig with grey hair has been found"s);
    t.push_back("a young 50 year old crocodile wants to make friends"s);
    t.push_back("a strange brown creature was seen in the box of oranges"s);
    t.push_back("a strange animal with big ears is building a house for its friends"s);

    s = t[num];
    //getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 4; // должно быть 0
    //cin >> result;
    //ReadLine();
    return result;
}

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

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(vector<pair<int, vector<string>>>& documents,
    const set<string>& stop_words, int document_id, const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    
    pair<int, vector<string>> docs;
    docs.first = document_id;
    docs.second = words;
    documents.push_back(docs); 

    }
   


set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}

int MatchDocument(const pair<int, vector<string>>& content, const set<string>& query_words) {
    int result = 0;
    for (const string& word : content.second) {
        if (query_words.count(word) != 0) {
            ++result;
        }
    }
    return result;
}

// Для каждого найденного документа возвращает его id and relevance
vector<pair<int, int>> FindDocuments(const vector<pair<int, vector<string>>>& documents,
    const set<string>& stop_words, const string& query) {
    const set<string> query_words = ParseQuery(query, stop_words);
    pair <int, int> matched_documents;
    vector<pair<int, int>> id_and_relevance;
    int document_id = 0;
    int relevance = 0;
    for (const auto& document : documents) {
        //cout << document.first << endl;
        relevance = MatchDocument(document, query_words);
        if (relevance > 0) {
            //relevance = MatchDocument(document, query_words);
            matched_documents.first = document_id;
            matched_documents.second = relevance;
            id_and_relevance.push_back(matched_documents);
                    }
        ++document_id;
        //matched_documents.second = relevance;
    }
   // matched_documents.second = relevance;
    //id_and_relevance.push_back(matched_documents);
    return id_and_relevance;
}

int main() {
    const string stop_words_joined = ReadLine_stop_words(); //ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector<pair<int, vector<string>>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        //cout << document_id << endl;
        AddDocument(documents, stop_words, document_id, ReadLine(document_id));
    }

    const string query = "cheburashka with big ears likes oranges "s; //ReadLine();
    for (auto& entry : FindDocuments(documents, stop_words, query)) {
       // cout << entry.first << entry.second << endl;
        cout << "{ document_id = "s << entry.first << ", relevance = "s << entry.second << " }"s
            << endl;
    }
}