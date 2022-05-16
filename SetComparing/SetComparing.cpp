// SetComparing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> VectorToString(vector<string> text) {
	int j;
	set<string> set;
	for (j = 0; j < text.size(); ++j) {
		set.insert(text[j]);
	}
	return set;
}

int CalculateSimilarity(vector<string> first, vector<string> second) {
	int n = 0;
	set<string> firstline = VectorToString(first);
	set<string> secondline = VectorToString(second);

	//set<string> firstline(first.begin(), first.end());
	//set<string> secondline(second.begin(), second.end());

	for (string word : firstline) {
		if (secondline.count(word) > 0) {
			// есть совпадение
			n++;
		}
	}
	// верните размер пересечения множеств слов first и second
	return n;
}

// SplitIntoWords разбивает строку text на слова и возвращает их в виде вектора
// Слово - последовательность непробельных символов,
// разделённых одним или более пробелов.
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
	string query, description;

	getline(cin, query);
	getline(cin, description);

	cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;
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
