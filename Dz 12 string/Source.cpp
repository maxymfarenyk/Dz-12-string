#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string text, word;
    fstream fin("data.txt");
    getline(fin, text);
    cout << text << endl;
    vector<string> words;
   stringstream ss(text);
   while (getline(ss, word, ' ')) {
       if (word != ".") {
           words.push_back(word);
       }
    }

    for (int i = 1;i < words.size(); i++)
    {
        string temp = words[i];
        int j = i - 1;
        while (j >= 0 && temp.length() > words[j].length())
        {
            words[j + 1] = words[j];
            j--;
           
        }
        words[j + 1] = temp;
    }

    for (auto itr : words) {
        cout << itr << ' ';
    }
    cout << '.';
    return 0;
}