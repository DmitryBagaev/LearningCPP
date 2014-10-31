#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string qLetterType (string s);

int main ()
{
    string s;
    string vowel = "vowel";
    string consonant = "consonant";

    cout << "Insert letter ";
    cin  >> s;
    cout << qLetterType(s);

    return 0;
}

string qLetterType (string s){
    string lettersVowel = "aeiouy";
    string lettersConsonant = "bcdfghjklmnpqrstvwxz";
    int lengthVowel = lettersVowel.length();
    int lengthConsonant = lettersConsonant.length();

    vector <char> letters;
    string stringOut;

    for (int i=0; i<lengthVowel; i++){
        letters.push_back(lettersVowel[i]);
    }

    for (int i=0; i<lengthConsonant; i++){
        letters.push_back(lettersConsonant[i]);
    }

    int lengthVector = letters.size();
    int par = 1;

    if (s.length()==1){
        for (int i=0; i<lengthVector; i++){
            if (s[0]==letters[i]){
                par = 0;
                if ( i < lengthVowel-1 ){
                    stringOut = "Vowel\n";
                } else {
                    stringOut = "Consonant\n";
                }
            }
        }
        if ( par == 1){
         stringOut = "Error: not a letter\n";
        }
    } else {
        stringOut = "Error: not a single char\n";

    }
    return stringOut;
}
