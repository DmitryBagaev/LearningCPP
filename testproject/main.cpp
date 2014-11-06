#include <iostream>
#include <cstring>
#include <set>

using namespace std;

enum {NOLETTER, VOWEL, CONSONANT}; //Здесь же заглавные буквы приняты?

int qLetterType (char letter);

int main ()
{
    string inputString;

    cout << "Insert letter: ";
    cin  >> inputString;
    if ( inputString.length() != 1 ){
        cout << "Invalid number of symbols\n";
    } else {
        char letter = inputString[0];
        switch(qLetterType(letter)){
        case NOLETTER:
            cout << "Not a letter\n";
            break;
        case VOWEL:
            cout << "Vowel\n";
            break;
        case CONSONANT:
            cout << "Consonant\n";
            break;
        };

    }
    return 0;
}

int qLetterType (char letter){

    set <char> vowels({'a','e','i','o','u','y'});
    set <char> consonants({'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'});
    set <char>::iterator it;
    it = vowels.find(letter);
    if ( it == vowels.end() ){
        it = consonants.find(letter);
        if (it == consonants.end() ){
            return 0;
        }else{
            return 2;
        }
    }else{
        return 1;
    }
}
