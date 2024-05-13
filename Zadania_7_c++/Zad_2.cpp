#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int wordToNumeral(const string& word) {
    if (word == "zero") return 0;
    if (word == "one") return 1;
    if (word == "two") return 2;
    if (word == "three") return 3;
    if (word == "four") return 4;
    if (word == "five") return 5;
    if (word == "six") return 6;
    if (word == "seven") return 7;
    if (word == "eight") return 8;
    if (word == "nine") return 9;
    return -1; // Invalid word
}

int sumEnergy(const string& filename, int option) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> words = {"zero","one", "two", "three" ,"four", "five" ,"six" ,"seven", "eight", "nine"};

    int sum = 0;
    string line;

    while (getline(file, line)) {
        int number_first = -1;
        int number_last = -1;
        int line_length = line.length();

        if (option == 1) {
            for (int i = 0; i < line_length; i++) {
                if (isdigit(line[i])) {
                    number_first = line[i] - '0';
                    break;
                }
            }
            for (int i = line_length - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_last = line[i] - '0';
                    break;
                }
            }
        } else if (option == 2) {
            for (int i = 0; i < line_length; i++) {
                if (isdigit(line[i])) {
                    number_first = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (line.substr(i, words[j].length()) == words[j]) {
                            number_first = wordToNumeral(words[j]);
                            break;
                        }
                    }
                    if (number_first != -1) {
                        break;
                    }
                }
            }
            for (int i = line_length - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_last = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (line.substr(i, words[j].length()) == words[j]) {
                            number_last = wordToNumeral(words[j]);
                            break;
                        }
                    }
                    if (number_last != -1) {
                        break;
                    }
                }
            }
        }

        sum += (number_first * 10) + number_last;
    }

    file.close();
    return sum;
}

int main() {
    const string filename = "../input1.txt";
    int energySum1 = sumEnergy(filename, 1);
    cout << "Suma energii 1: " << energySum1 << endl;

    int energySum2 = sumEnergy(filename, 2);
    cout << "Suma energii 2: " << energySum2 << endl;

    string keepopen;
    cin >> keepopen; // to keep the console open
    return 0;
}

