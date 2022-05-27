#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string>& input_map) {
    map<string, string> test_output;
    string output_key, output_value;
    for (const auto& map: input_map) {
        output_key = map.second;
        output_value = map.first;
        test_output.insert({ output_key, output_value });
    }
    return test_output;
}

int main() {
    map<string, string> test1_input = { {"cat"s, "felis catus"s},
                                       {"dog"s, "canis lupus"s} };
    map<string, string> test1_output = { {"felis catus"s, "cat"s},
                                        {"canis lupus"s, "dog"s} };

    // Проверяем корректность BuildReversedMap на примере 
    if (BuildReversedMap(test1_input) == test1_output) {
        cout << "BuildReversedMap returned right dictionary"s << endl;
    }

    // Добавьте ещё тесты, чтобы убедиться, что ваша функция работает верно
}