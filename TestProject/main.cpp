#include <iostream>
#include <cstring>
using namespace std;

string qLetterType (string s);

int main ()
{
    string s;
    cout << "Insert letter ";
    cin  >> s;
    cout << qLetterType(s);
    return 0;
}


string qLetterType (string s)
{
    string lettersVowel="aeiouy";
    string lettersConsonant="bcdfghjklmnpqrstvwxz";
    bool count = false;
    string StringOut = " ";

    if (s.length()==1){
      int length = lettersVowel.length();
        for (int i=0; i<length; i++){
            if (s[0]==lettersVowel[i]){
                count=true;
                StringOut = "Vowel\n";
                break;
            }
        }
        if (count == false){
            length = lettersConsonant.length();
            for (int i=0; i<length; i++){
                if (s[0]==lettersConsonant[i]){
                    count=true;
                    StringOut = "Consonant\n";
                    break;
                }
            }
            if (count==false){
                StringOut = "Mistake: not a letter\n";
            }
        }
    }else{
        StringOut = "Mistake: not a single char\n";
    }
    return StringOut;
}
