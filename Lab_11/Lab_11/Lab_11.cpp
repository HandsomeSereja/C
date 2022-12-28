#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int val;
	string data;
	Node* next;
};

struct list {
	ofstream fout;
	ifstream fin;
	Node* first;
	Node* p;
	Node* z;
	
	bool empty() {
		return first == NULL;
	}
	void make_list(int n) {
		first = NULL;
		for (int i = n; i > 0; i--) {
			p = new(Node);
			p->val = i;
			if (i%2 == 0) {
				p->data = "Саша";
			}
			else {
				p->data = "Маша";
			}
			p->next = first;
			first = p;
		}
	}
	void sort_list() {
		int i = 1;
		Node* p = first;
		while (p != NULL) {
			p->val = i;
			p = p->next;
			i++;
		}
	}
	void print_list() {
		if (empty()) {
			cout << "Empty"; 
			return;
		}
		Node* p = first;
		while (p) {
			cout << p->val << ":" << p->data << endl;
			p = p->next;
		}
	}
	void del_Node(int n) {
		if (empty()) {
			return;
		}
		Node* p = first;
		Node* q = first->next;
		if (p->val == n) {
			first = first->next;
			cout << "Первый элемент удалён" << endl;
			delete p;
			sort_list();
			return;
		}
		while (q && q->val !=n) {				
			p = p->next;
			q = q->next;
		}
		if (!q) {
			cout << "Такого элемента нет в списке";
			return;
		};
		if (q->next == NULL) {
			p->next = NULL;
			cout << "Последний элемент удалён" << endl;
			delete q;
			sort_list();
			return;
		}
		cout << "Элемент под номером " << n <<" удалён" << endl;
		p->next = q->next;
		delete q;
		sort_list();
	}
	void add_Node(int n) {
		Node* p = first;
		Node* q = first->next;
		Node* a;
		string s;
		if (p->val == n) {
			a = new(Node);
			a->next = p;
			cout << "Данные: ";
			cin >> s;
			a->data = s;
			first = a;
			sort_list();
			return;
		}
		while (p->next != NULL)
		{
			if (q->val == n) {
				a = new(Node);
				a->val = n;
				cout << "Данные: ";
				cin >> s;
				a->data = s;
				p->next = a;
				a->next = q;
				sort_list();
				return;
			}
			p = p->next;
			q = q->next;
		}
		a = new(Node);
		a->val = p->val;
		cout << "Данные: ";
		cin >> s;
		a->data = s;
		p->next = a;
		a->next = NULL;
		sort_list();
		return;
	}
	void change_Node(int n) {
		string s;
		Node* p = first;
		while (p != NULL) {
			if (p->val == n) {
				cout << "Данные: ";
				cin >> s;
				p->data = s;
				print_list();
				return;
			}
			p = p->next;
		}
		if (p == NULL) {
			cout << "Такого элемента нет" << endl;
			return;
		}
	}
	void save_list(string path) {
		Node* p = first;
		fout.open(path);
		if (!fout.is_open()) {
			cout << "Ошибка открытия файла" << endl;
		}
		else {
			cout << "Файл сохранен" << endl;
			while (p) {
				fout << p->val << p->data << endl;
				p = p->next;
			}
		}
		fout.close();
	}
	void load_list(string path) {
		fin.open(path);
		Node* p = first;
		char ch;
		string str;
		if (!fin.is_open()) {
			cout << "Ошибка открытия файла";
		}
		else {
			cout << "Файл загружен" << endl;
			while (!p->next == NULL) {
				if (p->val < 10) {
					fin.get(ch);
					fin >> str;
					p->data = str;
					fin.get(ch);
					p = p->next;
				}
				if (p->val >= 10) {
					fin.get(ch);
					fin.get(ch);
					fin >> str;
					p->data = str;
					fin.get(ch);
					p = p->next;
				}
			}
		}
	}
	void del_list() {
		if (empty()) {
			cout << "Empty";
			return;
		}
		Node* p = first;
		Node* q = first->next;
		while (!q == NULL) {
			first = first->next;
			delete p;
			p = first;
			q = first->next;
		}
		delete p;
		first = NULL;
		cout << "Список удален" << endl;
	}
};

int main()
{
	int k = 1;
	setlocale(LC_ALL, "Russian");
	list l;
	int n;
	string path = "List.txt";
	cout << "Количество элементов в списке: ";
	cin >> n;
	l.make_list(n);
	l.print_list();
	while (true) {
		if (k!=1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8) {
		cout << "Ты блять до 8 считать не умеешь?";
		}
		cout << endl;
		cout << "1.Удалить элемент 2.Добавить элемент 3.Показать список 4.Изменить элемент 5.Сохранить 6.Загрузить 7.Удалить список 8. Создать список" << endl;
		cin >> k;
		if (k == 1) {
			cout << "Номер элемента: ";
			cin >> n;
			l.del_Node(n);
			l.print_list();
		}
		if (k == 2) {
			cout << "Номер элемента: ";
			cin >> n;
			l.add_Node(n);
			l.print_list();
		}
		if (k == 3) {
			cout << endl;
			l.print_list();
		}
		if (k == 4) {
			cout << "Номер элемента: ";
			cin >> n;
			l.change_Node(n);
		}
		if (k == 5) {
			l.save_list(path);
		}
		if (k == 6) {
			l.load_list(path);
		}
		if (k == 7) {
			l.del_list();
		}
		if (k == 8) {
			cout << "Количество элементов в списке: ";
			cin >> n;
			l.make_list(n);
			l.print_list();
		}
		
	}
}

