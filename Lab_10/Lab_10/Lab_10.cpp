#include <iostream>
using namespace std;


void del_array(int *&arr, int &size)
{
	int del;
	cout << "Удалить элемент:";
	cin >> del;
	int *nArr = new int[size - 1];
	for (int i = 0; i < del-1; i++) {
		nArr[i] = arr[i];
	}
	for (int i = del-1; i < size - 1; i++) {
		nArr[i] = arr[i+1];
	}

	for (int i = 0; i < (size - 1); i++)
	{
		cout << nArr[i] << " ";
	}
	delete[] arr;
	arr = nArr;
}

void add_array(int*& arr, int& size) {
	int add;
	cout << "Добавить элемент:";
	cin >> add;
	int* dArr = new int[size];
	for (int i = 0; i < add-1; i++) {
		dArr[i] = arr[i];
	}
	for (int i = add; i < size; i++) {
		dArr[i] = arr[i-1];
	}
	dArr[add - 1] = rand();
	for (int i = 0; i < size; i++)
	{
		cout << dArr[i] << " ";
	}
	delete[]arr;
	arr = dArr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите длину массива:";
	cin >> size;
	int *arr = new int[size];
	
	for (int i = 0; i < size; i++) 
	{
		arr[i] = i+1;
		cout << arr[i] << " ";
	}
	cout << endl;
	del_array(arr, size);
	cout << endl;
	add_array(arr, size);
}
