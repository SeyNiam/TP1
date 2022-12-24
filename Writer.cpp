#include "Writer.h"

void Writer::add_book(string new_book)
{
	number_of_books++;
	string* new_books = new string[number_of_books];
	for (int i = 0; i < number_of_books - 1; i++) {
		new_books[i] = name_books[i];
	}
	new_books[number_of_books - 1] = new_book;
	name_books = new_books;
}

void Writer::delete_book()
{
	number_of_books--;
	string* new_books = new string[number_of_books];
	for (int i = 0; i < number_of_books; i++) {
		new_books[i] = name_books[i];
	}
	name_books = new_books;
}


string Writer::get_fullname()
{
	return fullname;
}

string* Writer::get_name_books()
{
	return name_books;
}

void Writer::set_fullname(string fullname)
{
	this->fullname = fullname;
}

void Writer::set_name_books(string* name_books)
{
	this->name_books = name_books;
}
int Writer::get_number_of_books()
{
	return number_of_books;
}
void Writer::set_number_of_books(int new_nob)
{
	number_of_books = new_nob;
}

void Writer::set_book(string book, int old_book_id)
{
	this->name_books[old_book_id] = book;
}
