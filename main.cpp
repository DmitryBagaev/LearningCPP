#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    char letters_vowel[]={'a','e','w','y','u','i','o'};
    char letters_consonant[]={'q','r','t','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char c[50];
    cout << "Insert letter ";
    cin  >> c;
    int length =strlen(c);
    bool count=false;

    if (length==1){
         length =strlen(letters_vowel);
        for (int i=0;i<length;i++){
            if (c[0]==letters_vowel[i]){
                count=true;
                cout << "VOWEL\n";
                break;
            }
        }
        if (count == false){
             length =strlen(letters_consonant);
            for (int i=0;i<length;i++){
                if (c[0]==letters_consonant[i]){
                    count=true;
                    cout  <<"CONSONANT\n";
                    break;
                }
            }
            if (count==false){
                cout << "Mistake: not a letter\n";
            }
        }
    }else{
        cout <<"Mistake: not a single char\n";
    }
return 0;
}
