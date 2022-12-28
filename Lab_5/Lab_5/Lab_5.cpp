#include <iostream>
using namespace std;

// Функция для сортировки слов из массива
void sort(int arr[3][60], int const z, int const c) {
	for (int i = 0; i < z; i++)
	{
		cout << "(";
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] != 0) {
				cout << arr[i][j];
			}
			else if (arr[i][j] == 0 && j != c-1) {
				cout << ",";
			}
		}
		cout << ")" << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int const z = 3;
	int const c = 60;
	int k = 0;
	int arr[z][c];
	cout << "_______Месиво из слов_______" << endl;
	//Заполнение массива 
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (j == c-1) {
				arr[i][j] = 0;
			}
			else if (k == 1 && j != c-1) {
				arr[i][j] = 1 + rand()%9;
				k = 0;
			}
			else {
				arr[i][j] = rand() % 9;
				if (arr[i][j] == 0) {
					k = 1;
				}
				else {
					k = 0;
				}
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "_______Отсортированные слова_______" << endl;
	sort(arr,z,c);
}
