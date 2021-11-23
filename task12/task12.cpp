// task12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
bool perevirka(char s[256]) {
	int l = strlen(s);
	bool b = true;
	int i = 0;
	while (i < l && b == true) {
		if (s[i] < '0' || s[i]>'9') {
			b = false;
		}
		i = i + 1;
	}
	return b;
}
int main()
{
	ifstream text;
	ofstream text2;

	char line[256];

	text.open("text.txt");
	text2.open("text2.txt", ios::binary);
	while (!text.eof()) {
		text.getline(line, 256);
		char word[256] = {};          //Буфер для считывания строки
		stringstream x;        //Создание потоковой переменной
		x << line;


		while (x >> word) {
			if (perevirka(word) == true) {

				text2.write((char*)&word, sizeof(int));


				/*text2 << " ";*/
			}
		}
		/*text2 << endl;*/
	}
	text2.close();
	ifstream text22;
	char line22[256];
	text22.open("text2.txt", ios::binary);
	while (text22.read((char*)&line22, sizeof(int))) {

		cout << line22 << " ";
	}
	text.close();
	text22.close();
}

