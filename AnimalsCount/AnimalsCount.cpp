#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CheckAnagram(const string& s1, const string& s2) {
	map<char, int> s1_chars;
	map<char, int> s2_chars;
	for (const char& c : s1) {
		++s1_chars[c];
	}
	for (const char& c : s2) {
		++s2_chars[c];
	}
	if (s1_chars == s2_chars) {
		return true;
	}
	else return false;
	{

	}
}

// напишем небольшую функцию для проверки
void CheckIsTrue(bool value) {
	if (value) {
		cout << "Test passed :)"s << endl;
	}
	else {
		cout << "Test failed :("s << endl;
	}
}

int main() {
	CheckIsTrue(CheckAnagram("tea"s, "eat"s));
	CheckIsTrue(!CheckAnagram("battle"s, "beatle"s));
	CheckIsTrue(!CheckAnagram("lift"s, "elevator"s));
	CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));

}