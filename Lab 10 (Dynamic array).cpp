#include <iostream>
#include <string>
using namespace std;
//������� ����� ��������� � ������������ ������
void in(string*& arr, int N, int i = 0)
{
	while (i < N) {
		cout << "������� ������: ";
		cin >> arr[i];
		i++;
		}
};
//������� ������ �������� � ������������� �������
void out(string*& arr, int N, int i = 0) {
	while (i < N) {
		cout << arr[i] << endl;
		i++;
	}
};
//������� �������� ������� �������� �������
bool Check(string row) {
	bool otvet = false;
	string check = { "��" };
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
		cout << "\n������� ���-�� �����: ";
		cin >> size;
		if (size < 1) {
			cout << "������������ ���-�� �����!";
		}
	}
	string* stroka = new string[size];
	in(stroka, size);
	cout << "\n������ �����:\n";
	out(stroka, size);
	for (i = 0; i < size; i++) {
		if (Check(stroka[i]) == true) {
			stroka[i] = "0";
			counter++;
		}
	}
	if (counter == size) {
		cout << "\n��� ������ � ������� ���������� �� '�'!\n";
	}
	else if (counter == 0) {
		cout << "\n� ������� ��� ����� ������������ �� '�'!\n";
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
		cout << "\n���-�� �������� ����� = "<< counter <<"\n������ ����� ����� ��������:\n";
		out(row, size - counter);
		delete[] row;
	}
	system("pause");
	return 0;
}