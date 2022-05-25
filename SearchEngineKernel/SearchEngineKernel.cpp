#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string ReadLine() {
	string s;
	s = "a an on the in is has been are with for from have be was"s;
	//getline(cin, s);
	return s;
}

string ReadLine1(int num) {
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

string ReadLine2() {
	string s;
	s = "cheburashka with big ears likes oranges"s;
	//getline(cin, s);
	return s;
}

int ReadLineWithNumber() {
	int result = 4;
	//int result = 0;
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
	// проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
	for (const string& word : SplitIntoWords(text)) {
		if (stop_words.count(word) == 0) {
			words.push_back(word);
		}
	}
	// вернём результат без стоп-слов
	return words;
}

void AddDocument(vector<vector<string>>& documents, const set<string>& stop_words,
	const string& document) {
	const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
	documents.push_back(words);
}

// Разбирает text на слова и возвращает только те из них, которые не входят в stop_words
set<string> ParseQuery(const string& text, const set<string>& stop_words) {
	set<string> query_words;
	// проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
	for (const string& word : SplitIntoWords(text)) {
		if (stop_words.count(word) == 0) {
			query_words.insert(word);
		}
	}
	// вернём результат без стоп-слов
	return query_words;
}

// Возвращает true, если среди слов документа (document_words)
// встречаются слова поискового запроса query_words
bool MatchDocument(const vector<string>& document_words, const set<string>& query_words) {
	for (const string& word : document_words) {
		if (query_words.count(word) > 0) {
			return true;
			break;
		}
	}
	return false;
}

// Возвращает массив id документов, подходящих под запрос query
// Стоп-слова исключаются из поиска
vector<int> FindDocuments(const vector<vector<string>>& documents, const set<string>& stop_words, const string& query) {
	vector<int> matched_documents;
	int n = 0;
	set<string> parsequery = ParseQuery(query, stop_words);
	// Парсить запрос ParseQuery(query не включая stop_words)
	// Сравнить каждое слово из query с каждым вектором из вектора векторов MatchDocument
	for (const vector<string>& document : documents) {
		if (MatchDocument(document, parsequery)) {
			matched_documents.push_back(n);
		}
		++n;
	}
	// если совпадает - извлечь id документа
	// положить id документа в вектор(int) 
	// Напишите код функции
	// Воспользуйте вспомогательными функциями ParseQuery, MatchDocument
	// В качестве id документа используйте его индекс в массиве documents

	return matched_documents;
}

int main() {
	// read stop_words
	const string stop_words_joined = ReadLine();
	const set<string> stop_words = ParseStopWords(stop_words_joined);

	// Read documents
	vector<vector<string>> documents;
	const int document_count = ReadLineWithNumber();
	for (int document_id = 0; document_id < document_count; ++document_id) {
		AddDocument(documents, stop_words, ReadLine1(document_id));
	}

	const string query = ReadLine2();
	for (const int document_id : FindDocuments(documents, stop_words, query)) {
		cout << "{ document_id = "s << document_id << " }"s << endl;
	}
}