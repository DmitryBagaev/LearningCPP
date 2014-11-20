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

int main()
{
    string strText[n];

    ifstream fileInput;
    fileInput.open("/home/administrator/Desktop/C++Learning/stringsandstreams/text.dat", ios::in);

    if (!fileInput){
        cout << "File opening failed";
        return 0;
    }

    int i = 0;
    while (!fileInput.eof()){
        getline(fileInput,strText[i]);
        i++;
    }
    //--------------------Вывод текста на экран-----------------------
    i = 0;
    while (strText[i] != "")
    {
        cout << strText[i] << endl;
        i++;
    }

    //------------------Подсчёт количества слов в тексте--------------

    int wordCount = 0;

    for (i = 0; i < n; i++){

        if (strText[0][0] != ' ')
            wordCount += 1;

        int pos1=0;
        int pos2=0;
        while ((pos2 != strText[i].find_last_of(' ')) && (pos1 != strText[i].find_last_of(' ')) )
        {
            pos1 = strText[i].find_first_of(' ', pos2);
            pos2 = strText[i].find_first_of(' ', pos1 + 1);
            if ((pos1 +1) != pos2)
                wordCount += 1;
        }
    }
    cout << "Words = " << wordCount << endl;



    return 1;
}
