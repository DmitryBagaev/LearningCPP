#include <iostream>
#include <cstring>
#include <set>

using namespace std;

string qLetterType (char letter);

int main ()
{
    string inputString;

    cout << "Insert letter: ";
    cin  >> inputString;
    if ( inputString.length() != 1 ){
        cout << "Invalid number of symbols\n";
    } else {
        char letter = inputString[0];
        cout << qLetterType(letter);
    }
    return 0;
}

string qLetterType (char letter){

    string stringOut;

    set <char> vowels({'a','e','i','o','u','y'});
    set <char> consonants({'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'});
    set <char>::iterator it;
    it = vowels.find(letter);
    if ( it == vowels.end() ){
        it = consonants.find(letter);
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
