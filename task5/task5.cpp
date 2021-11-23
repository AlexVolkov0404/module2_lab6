// task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
bool polindrom(char s[256], int k) {
    int l = strlen(s);


    k = (k - 1) / 2;
    bool b = false;
    int i = k;
    while (i < l - k && b == false) {
        int j = 1;
        b = true;
        while (j <= k && b == true) {
            if (s[i - j] != s[i + j]) {
                b = false;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return b;
}
int main()
{
    int k;
    cout << "vvedit k: ";
    cin >> k;
    ifstream text;

    ofstream text2;
    text.open("text.txt");
    text2.open("text2.txt");

    char line[256];
    char line2[256];


    while (!text.eof()) {
        text.getline(line, 256);
        /* cout << line << endl;*/
        char word[256] = {};          //Буфер для считывания строки
        stringstream x;        //Создание потоковой переменной
        x << line;


        while (x >> word) {
            if (polindrom(word, k) == false) {
                text2 << word;
                text2 << " ";
            }
        }
        text2 << endl;
    }
    text2.close();
    ifstream text22;
    text22.open("text2.txt");
    while (!text22.eof()) {
        text22.getline(line2, 256);
        cout << line2 << endl;
    }
    text.close();
    text22.close();
}

