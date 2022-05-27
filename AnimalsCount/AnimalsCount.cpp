#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CheckAnagram(string const& s1, const string& s2) {
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

int main()
{
	cout << CheckAnagram("tea"s, "eat"s);
}

