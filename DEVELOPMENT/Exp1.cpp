#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    string line;
    int lineCount = 0, wordCount = 0, charCount = 0;

    while (getline(file, line)) {
        cout<<line<<endl;
        lineCount++;
        charCount += line.length() + 1; // +1 for newline character
        stringstream ss(line);
        string word;
        while (ss >> word) wordCount++;
    }
    file.close();

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    return 0;
}
