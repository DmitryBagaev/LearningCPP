//-------------------------------------------------------------
/*
 * C помощью текстового редактора создать файл, содержащий текст, длина
 * кото­рого не превышает 1000 символов (длина строки текста не должна
 * превышать 70 символов).
 * Имя файла должно иметь расширение dat.
 * Написать программу, которая:
 * • выводит текст на экран дисплея;
 * • определяет количество слов в тексте;
 * • определяет количество слов в тексте, у которых первый и последний
 * символы совпадают.
 * Вывод осуществить с помощью стандартных потоков, манип. и форм. методов.
*/
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int n = 20;

void fileOutput(string strText[]);

int main()
{
    string strText[n];

    ifstream fileInput;
    fileInput.open("/home/administrator/Desktop/C++Learning/stringsandstreams/text.dat", ios::in);

    if (!fileInput){
        cout << "File opening failed" << endl;
        return 0;
    }

    int i = 0;
    while (!fileInput.eof()){
        getline(fileInput,strText[i]);
        i++;
    }
    fileOutput(strText);
    //--------------------Вывод текста на экран-----------------------
    /*
    i = 0;
    while (strText[i] != "")
    {
        cout << strText[i] << endl;
        i++;
    }
*/
    //------------------Подсчёт количества слов в тексте--------------

    int wordCount = 0;

    for (i = 0; i < n; i++){
        if (!strText[i].empty()){
            if (strText[i][0] != ' ')
                wordCount += 1;
            unsigned int pos1 = 0;
            unsigned int pos2 = 0;
            while ((pos2 != strText[i].find_last_of(' ')) && (pos1 != strText[i].find_last_of(' ')) )
            {
                pos1 = strText[i].find_first_of(' ', pos2);
                pos2 = strText[i].find_first_of(' ', pos1 + 1);
                if (((pos1 + 1) != pos2) && ((pos2 + 1) != pos1))
                    wordCount += 1;
            }
            if (strText[i][strText[i].length() - 1] != ' ')
                wordCount += 1;
        }
    }
    cout << "Words in the text file = " << wordCount << endl;

    //------------------Подсчёт количества слов с одинаковыми буквами на концах--------------
    int wordEqualSidesCount = 0;

    for (i = 0; i < n; i++){
        if (!strText[i].empty()){

            if (strText[i][0] != ' ')
                if (strText[i][0] == strText[i][strText[i].find_first_of(' ')-1])
                    wordEqualSidesCount += 1;

            unsigned int pos1 = 0;
            unsigned int pos2 = 0;

            while ( (pos2 != strText[i].find_last_of(' ')) && (pos1 != strText[i].find_last_of(' ')) )
            {
                pos1 = strText[i].find_first_of(' ', pos2);

                if ((pos2 + 1) == pos1)
                    if (strText[i][pos2+1] == strText[i][pos1-1])
                        wordEqualSidesCount += 1;
                pos2 = strText[i].find_first_of(' ', pos1 + 1);

                if ((pos1 + 1) != pos2)
                    if (strText[i][pos1+1] == strText[i][pos2-1])
                        wordEqualSidesCount += 1;
            }
            if (strText[i][strText[i].length()-1] != ' ')
                if ( strText[i][strText[i].find_last_of(' ') + 1] == strText[i][strText[i].length()-1])
                    wordEqualSidesCount += 1;
        }
    }

    cout << "Words with equal sides in the text file = " << wordEqualSidesCount << endl;

    fileInput.close();

    return 1;
}

void fileOutput(string strText[])
{
    int i = 0;
    while (strText[i] != "")
    {
        cout << strText[i] << endl;
        i++;
    }
}
