#include <iostream>
#include <cstring>
#include <set>

using namespace std;

enum LetterResult{NoLetter, Vowel, Consonant};

LetterResult qLetterType (char letter);

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
        case NoLetter:
            cout << "Not a letter: " << letter << "\n";
            break;
        case Vowel:
            cout << "Vowel: " << letter << "\n";
            break;
        case Consonant:
            cout << "Consonant: " << letter << "\n";
            break;
        };

    }
    return 0;
}

LetterResult qLetterType (char letter){

    set <char> vowels({'a','e','i','o','u','y'});
    set <char> consonants({'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'});
    set <char>::iterator it;
    it = vowels.find(letter);
    if ( it == vowels.end() ){
        it = consonants.find(letter);
        if (it == consonants.end() )
            return NoLetter;
        else
            return Consonant;
    } else {
        return Vowel;
    }
}
