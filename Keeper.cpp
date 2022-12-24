#include "Keeper.h"

keeper::keeper()
{
	this->size_p = 0;
	this->size_n = 0;
	this->size_f = 0;
	p = new Poet[1];
	n = new Novelist[1];
	f = new Fantast[1];
}

keeper::keeper(int size_p, int size_n, int size_f, Poet* p, Novelist* n, Fantast* f)
{
	this->size_p = size_p;
	this->size_n = size_n;
	this->size_f = size_f;
	this->p = p;
	this->n = n;
	this->f = f;
}

keeper::keeper(const keeper& ref_k)
{
	this->size_p = ref_k.size_p;
	this->size_n = ref_k.size_n;
	this->size_f = ref_k.size_f;
	this->p = ref_k.p;
	this->n = ref_k.n;
	this->f = ref_k.f;
}

keeper::~keeper()
{
	delete[] p;
	delete[] n;
	delete[] f;
	cout << "Вызван деструктор ~Novelist" << endl;
}

int keeper::get_size()
{
	return size_p + size_n + size_f;
}

void keeper::add_poet(string fullname, int year_of_birth, int year_of_death, string* books, int size_b)
{
	size_p++;
	Poet* new_poets = new Poet[size_p];
	for (int i = 0; i < size_p - 1; i++) {
		new_poets[i] = p[i];
	}
	new_poets[size_p - 1].set_fullname(fullname);
	new_poets[size_p - 1].set_years_of_birth(year_of_birth);
	new_poets[size_p - 1].set_years_of_death(year_of_death);
	new_poets[size_p - 1].set_name_books(books);
	new_poets[size_p - 1].set_number_of_books(size_b);
	p = new_poets;
}

void keeper::delete_poet(int id)
{
	if (size_p <= 0) exception;
	Poet* new_poets = new Poet[size_p - 1];
	int k = 0;
	for (int i = 0; i < size_p; i++) {
		if (i == id) continue;
		new_poets[k] = p[i];
		k++;
	}
	p = new_poets;
	size_p--;
}

void keeper::add_novelist(string fullname, int year_of_birth, int year_of_death, string* books, int size_b, string biography)
{
	size_n++;
	Novelist* new_novelists = new Novelist[size_n];
	for (int i = 0; i < size_n - 1; i++) {
		new_novelists[i] = n[i];
	}
	new_novelists[size_p - 1].set_fullname(fullname);
	new_novelists[size_p - 1].set_years_of_birth(year_of_birth);
	new_novelists[size_p - 1].set_years_of_death(year_of_death);
	new_novelists[size_p - 1].set_name_books(books);
	new_novelists[size_p - 1].set_number_of_books(size_b);
	n = new_novelists;
}

void keeper::delete_novelist(int id)
{
	if (size_n <= 0) exception;
	Novelist* new_novelists = new Novelist[size_n - 1];
	int k = 0;
	for (int i = 0; i < size_n; i++) {
		if (i == id) continue;
		new_novelists[k] = n[i];
		k++;
	}
	n = new_novelists;
	size_n--;
}

void keeper::add_fantast(string fullname, string* books, int size_b, bool IF)
{
	size_f++;
	Fantast* new_fantast = new Fantast[size_f];
	for (int i = 0; i < size_f - 1; i++) {
		new_fantast[i] = f[i];
	}
	new_fantast[size_f - 1].set_fullname(fullname);
	new_fantast[size_f - 1].set_name_books(books);
	new_fantast[size_f - 1].set_number_of_books(size_b);
	new_fantast[size_f - 1].set_isFilmed(IF);
	f = new_fantast;
}

void keeper::delete_fantast(int id)
{
	if (size_f <= 0) exception;
	Fantast* new_fantast = new Fantast[size_f - 1];
	int k = 0;
	for (int i = 0; i < size_f; i++) {
		if (i == id) continue;
		new_fantast[k] = f[i];
		k++;
	}
	//delete[] new_poets;
	f = new_fantast;
	size_f--;
}

Poet keeper::get_poet(int id)
{
	if (id >= size_p) { cout << "Исключение!" << endl; return p[0]; }
	return p[id];
}

Novelist keeper::get_novelist(int id)
{
	if (id >= size_n) { cout << "Исключение!" << endl; return n[0]; }
	return n[id];
}

Fantast keeper::get_fantast(int id)
{
	if (id >= size_f) { cout << "Исключение!" << endl; return f[0]; } 
	return f[id];
}



void keeper::Save()
{
	ofstream out;          // поток для записи
	out.open("data.txt");  // окрываем файл для записи
	bool firstIteration = true;   // проверка на первую строку в сохранение (избежание первого \n)
	if (out.is_open())
	{
		//записываем поэтов
		for (int i = 0; i < size_p; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";

			out << "Poet" << endl;
			out << p[i].get_fullname() << endl;
			out << p[i].get_years_of_birth() << endl;
			out << p[i].get_years_of_death() << endl;

			//записываем количество книг
			out << p[i].get_number_of_books();
			for (int j = 0; j < p[i].get_number_of_books(); j++) {
				out << ";" << p[i].get_name_books()[j];
			}
		}
		//записываем новелистов
		for (int i = 0; i < size_n; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			out << "Novelist" << endl;
			out << n[i].get_fullname() << endl;
			out << n[i].get_years_of_birth() << endl;
			out << n[i].get_years_of_death() << endl;

			//записываем количество книг
			out << n[i].get_number_of_books();
			for (int j = 0; j < n[i].get_number_of_books(); j++) {
				out << ";" << n[i].get_name_books()[j];
			}
			out << '\n' << n[i].get_biography();
		}
		// записываем фантастов
		for (int i = 0; i < size_f; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			out << "Fantast" << endl;
			out << f[i].get_fullname() << endl;
			//записываем количество книг
			out << f[i].get_number_of_books();
			for (int j = 0; j < f[i].get_number_of_books(); j++) {
				out << ";" << f[i].get_name_books()[j];
			}
			out << '\n' << f[i].get_isFilmed();
		}
	}
	out.close();
}

void keeper::Read()
{
	string fn;//новое ФИО
	int yob;//года
	int yod;//года
	string new_name_of_book;
	ifstream in("data.txt");
	if (in.is_open())
	{
		//обновляем keeper.h

		/*
		1 строка - получаем символ: 'p' - поэт
		2 строка - получаем ФИО
		3 строка - получаем несколько основных произведений
		4-5 строки - получаем годы жизни
		и прочее...
		*/
		while (!in.eof()) {
			string c;
			getline(in, c);
			if (c == "Poet") {
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				//присваиваем новые значения
				add_poet(fn, yob, yod, new_books, size_books);
			}
			else if (c == "Novelist") {
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				string bio; getline(in, bio);
				//присваиваем новые значения
				add_novelist(fn, yob, yod, new_books, size_books, bio);
			}
			else if (c == "Fantast") {
				getline(in, fn);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				bool isFilmed; in >> isFilmed; // \n - проверить на перенос строки

				//присваиваем новые значения
				add_fantast(fn, new_books, size_books, isFilmed);
			}
		}
	}
	in.close(); // закрываем файл
}

void keeper::print_poet()
{
	for (int i = 0; i < size_p; i++) {
		cout << "\nПоэт " << i + 1 << ": " << endl;
		print_poet(i);
	}
}

void keeper::print_poet(int id)
{
	if (id >= size_p) { return; }
	cout << "ФИО: " << p[id].get_fullname() << endl;
	cout << "Годы жизни: " << p[id].get_years_of_birth() << " - " << p[id].get_years_of_death() << endl;
	if (p[id].get_number_of_books() == 0) { cout << "Нету книг" << endl; }
	else if (!have_word(p[0].get_name_books()[0])) {
		for (int i = 1; i <= p[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << p[id].get_name_books()[i] << endl;
		}
	}
	else {
		for (int i = 0; i < p[id].get_number_of_books(); i++) {
			cout << "Книга " << i + 1 << ": ";
			cout << p[id].get_name_books()[i] << endl;
		}
	}
}


void keeper::print_novelist()
{
	for (int i = 0; i < size_n; i++) {
		cout << "\nНовелист " << i + 1 << ": " << endl;
		print_novelist(i);
	}
}

void keeper::print_novelist(int id)
{
	if (id >= size_n) { return; }
	cout << "ФИО: " << n[id].get_fullname() << endl;
	cout << "Годы жизни: " << n[id].get_years_of_birth() << " - " << n[id].get_years_of_death() << endl;
	if (n[id].get_number_of_books() == 0) { cout << "Нету книг" << endl; }
	else if (!have_word(n[0].get_name_books()[0])) {
		for (int i = 1; i <= n[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << n[id].get_name_books()[i] << endl;
		}
	}
	else {
		for (int i = 0; i < n[id].get_number_of_books(); i++) {
			cout << "Книга " << i + 1 << ": ";
			cout << n[id].get_name_books()[i] << endl;
		}
	}
	cout << "Краткая биография: " << n[id].get_biography() << endl;
}

void keeper::print_fantast()
{
	for (int i = 0; i < size_f; i++) {
		cout << "\nФантаст " << i + 1 << ": " << endl;
		print_fantast(i);
	}
}

void keeper::print_fantast(int id)
{
	if (id >= size_f) { return; }
	cout << "ФИО: " << f[id].get_fullname() << endl;
	if (f[id].get_number_of_books() == 0) { cout << "Нету книг" << endl; }
	else if (!have_word(p[0].get_name_books()[0])) {
		for (int i = 1; i <= f[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << f[id].get_name_books()[i] << endl;
		}
	}
	else {
		for (int i = 0; i < f[id].get_number_of_books(); i++) {
			cout << "Книга " << i + 1 << ": ";
			cout << f[id].get_name_books()[i] << endl;
		}
	}
	f[id].get_isFilmed() ? cout << "Снят по крайней мере 1 фильм" : cout << "Не снимались фильмы";
}

void keeper::print_all()
{
	print_poet();
	print_novelist();
	print_fantast();
}

void keeper::add_book_poet(string book, int id)
{
	p[id].add_book(book);
}

void keeper::delete_book_poet(int id)
{
	if (p[id].get_number_of_books() == 0) {
		cout << "Удалять нечего" << endl;
		return;
	}
	else p[id].delete_book();
}

void keeper::add_book_novelist(string book, int id)
{
	n[id].add_book(book);
}

void keeper::delete_book_novelist(int id)
{
	if (n[id].get_number_of_books() == 0) {
		cout << "Удалять нечего" << endl;
		return;
	}
	else n[id].delete_book();
}

void keeper::add_book_fantast(string book, int id)
{
	f[id].add_book(book);
}

void keeper::delete_book_fantast(int id)
{
	if (f[id].get_number_of_books() == 0) {
		cout << "Удалять нечего" << endl;
		return;
	}
	else f[id].delete_book();
}

string* keeper::split(string str, char ch)
{
	stringstream stream(str);
	string* s = new string();
	int size = 0;
	std::string item;
	while (getline(stream, item, ch)) {
		size++;
		string* new_s = new string[size];
		for (int i = 0; i < size - 1; i++) {
			new_s[i] = s[i];
		}
		new_s[size - 1] = item;
		s = new_s;
	}
	stream.flush();
	return s;
}

bool keeper::have_word(string s)
{
	for (int i = 0; i < s.length(); i++) { // идем по символам
		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
			return true;
	}
	return false;
}

