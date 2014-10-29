#include <iostream>
#include <cstring>
using namespace std;

string qLetterType (string s, string letters_vowel, string letters_consonant, int length);

int main ()
{
    int length=0;
    string letters_vowel="aeiouy";
    string letters_consonant="bcdfjhjklmnpqrstvwxz";

    string s;
    cout << "Insert letter ";
    cin  >> s;
    cout << qLetterType(s,letters_vowel,letters_consonant,length);
    return 0;
}


string qLetterType (string s, string letters_vowel, string letters_consonant, int length)
{
    length=s.length();
    bool count=false;
    string StringOut=" ";

    if (length==1){
        length =letters_vowel.length();
        for (int i=0;i<length;i++){
            if (s[0]==letters_vowel[i]){
                count=true;
                StringOut= "Vowel\n";
                break;
            }
        }
        if (count == false){
            length =letters_consonant.length();
            for (int i=0;i<length;i++){
                if (s[0]==letters_consonant[i]){
                    count=true;
                    StringOut= "Consonant\n";
                    break;
                }
            }
            if (count==false){
                StringOut= "Mistake: not a letter\n";
            }
        }
    }else{
        StringOut= "Mistake: not a single char\n";
    }
    return StringOut;
}
