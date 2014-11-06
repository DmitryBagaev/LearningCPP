#include <iostream>
#include <cstring>
#include <set>

using namespace std;

string qLetterType (char c);

int main ()
{
    string s;

    cout << "Insert letter: ";
    cin  >> s;
    if ( s.length() != 1 ){
        cout << "Invalid number of symbols\n";
    } else {
        char c = s[0];
        cout << qLetterType(c);
    }
    return 0;
}

string qLetterType (char c){

    string stringOut;
    string lettersVowel = "aeiouy";
    string lettersConsonant = "bcdfghjklmnpqrstvwxz";
    int lengthVowel = lettersVowel.length();
    int lengthConsonant = lettersConsonant.length();

    set <char> vowels;
    set <char> consonants;
    set <char>::iterator it;
    for (int i=0; i<lengthVowel;i++){
        vowels.insert(lettersVowel[i]);
    }
    for (int i=0; i<lengthConsonant;i++){
        consonants.insert(lettersConsonant[i]);
    }
    it = vowels.find(c);
    if ( it == vowels.end() ){
        it = consonants.find(c);
        if (it == consonants.end() ){
            stringOut = "Invalid symbol: not a letter\n";
        }else{
            stringOut = "Consonant\n";
        }
    }else{
        stringOut = "Vowel\n";
    }

    return stringOut;
}
