#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

string reverseString(string str) {
    stack<char> charStack;
    for (char c : str) {
        charStack.push(c);
    }

    string reversedStr = "";
    while (!charStack.empty()) {
        reversedStr += charStack.top();
        charStack.pop();
    }
    return reversedStr;
}

void reverseSentence(string str) {
    stringstream ss(str);
    string word;
    string reversedSentence = "";
    int wordCount = 0;

    while (ss >> word) {
        wordCount++;
    }

    ss.clear();
    ss.str(str);

    if (wordCount < 3) {
        cout << "Kalimat harus memiliki minimal 3 kata." << endl;
        return;
    }

    while (ss >> word) {
        string reversedWord = reverseString(word);
        reversedSentence = reversedWord + " " + reversedSentence;
    }

    if (!reversedSentence.empty() && reversedSentence[reversedSentence.size() - 1] == ' ') {
        reversedSentence.pop_back();
    }

    cout << "Kalimat: " << str << endl;
    cout << "Hasil: " << reversedSentence << endl;
}

int main() {
    string input;
    cout << "Masukkan sebuah kalimat dengan minimal 3 kata: ";
    getline(cin, input);

    reverseSentence(input);

    return 0;
}
