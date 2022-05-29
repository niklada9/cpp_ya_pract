#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string FindWidespreadBird(const vector<string>& types) {
	map<string, int> birds;
	int ans_num = 0;
	string answer;
	for (const string& c : types) {
		++birds[c];
	}
	for (auto& bird : birds) {
		if (bird.second > ans_num) {
			ans_num = bird.second;
			answer = bird.first;
		}
	}
	return answer;
}

int main() {
	vector<string> bird_types1 = { "zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s };
	if (FindWidespreadBird(bird_types1) == "sinica"s) {
		cout << "Correct"s << endl;
	}
	else {
		cout << "Not correct"s << endl;
	}

	vector<string> bird_types2 = { "ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s };
	if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s) {
		cout << "Correct"s << endl;
	}
	else {
		cout << "Not correct"s << endl;
	}
}