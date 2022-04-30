#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    int c = s.size();// длина слова
    bool j = true; //true - значит палиндром;
if (c < 2){
    cout << j << endl;
} else {
    for (int i = c; i < 2 ; --i ){
        cout << s[i] << s[c-i] << endl;
        if (s[i] != s[c-i]){
            j = false;
            break;
        }
        cout << j << endl;
    }
    
}
   
}

int main() {
    IsPalindrome("arra"s);
    IsPalindrome("deer"s);
}
