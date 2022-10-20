#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "RUS");
	const int N = 100;
	int a[N];
	int x;
	int del;
	int size = 20;
	int i;
	int d;
	i = 0;
	int k = 0;
	cout << "_____Массив_____" << endl;
	while (i < size) {
		x = rand()%30+1;
		a[i] = x;
		cout << a[i] << " ";
		i++;
	}
	cout << endl << "Введите номер переменной, которую необходимо удалить: ";
	cin >> del;
	i = del-1;
	d = del-1;
	while (i<size) {
		d = d + 1;
		a[i] = a[d];
		i++;
	}
	i = 0;
	size = size - 1;
	cout << "Массив без удаленной переменной: ";
	while (i < size) {
		cout << a[i] << " ";
		i++;
	}
	cout << endl;
	i = 0;
	cout << "Массив с 0 после четных чисел: ";
	while (i < size) {
		if (a[i] % 2 == 0 && a[i]!=0) {
			k = size+1;
			while (k>i+1) {
				a[k] = a[k - 1];
				k=k-1;
			}
			size++;
			a[i + 1] = 0;
		}
		cout << a[i] << " ";
		i++;
	}	
}
