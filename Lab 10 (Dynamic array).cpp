#include <iostream>
#include <string>
using namespace std;
//Функция ввода элементов в динамический массив
void in(string*& arr, int N, int i = 0)
{
	while (i < N) {
		cout << "Введиет строку: ";
		cin >> arr[i];
		i++;
		}
};
//Функция вывода элемнтов в динамического массива
void out(string*& arr, int N, int i = 0) {
	while (i < N) {
		cout << arr[i] << endl;
		i++;
	}
};
//Функция проверки первого элемента массива
bool Check(string row) {
	bool otvet = false;
	string check = { "Аа" };
	string stroka = row;
	for (int i = 0; i < size(check); i++) {
		if (stroka[0] == check[i]) {
			otvet = true;
		}
	}
	return otvet;
};
int main()
{
	system("chcp 1251");
	int size=-1,counter=0, i, j=0;
	while (size < 1) {
		cout << "\nВведите кол-во строк: ";
		cin >> size;
		if (size < 1) {
			cout << "Недопустимое кол-во строк!";
		}
	}
	string* stroka = new string[size];
	in(stroka, size);
	cout << "\nМассив строк:\n";
	out(stroka, size);
	for (i = 0; i < size; i++) {
		if (Check(stroka[i]) == true) {
			stroka[i] = "0";
			counter++;
		}
	}
	if (counter == size) {
		cout << "\nВсе строки в массиве начинаются на 'а'!\n";
	}
	else if (counter == 0) {
		cout << "\nВ массиве нет строк начинающихся на 'а'!\n";
	}
	else { 
		string* row = new string[size - counter];
		for (i = 0; i < size; i++) {
			if (stroka[i] != "0") {
				row[j] = stroka[i];
				j++;
			}
		}
		delete[] stroka;
		cout << "\nКол-во удалённых строк = "<< counter <<"\nМассив строк после удаления:\n";
		out(row, size - counter);
		delete[] row;
	}
	system("pause");
	return 0;
}