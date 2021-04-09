#pragma once
#include "Book.h"
#include "BooksContainer.h"
#include "utills.h"


bool compById(Book &left, Book &right) {
	return left.getId() < right.getId();
}

bool compByAuthor(Book& left, Book& right) {
	return left.getAuthor() < right.getAuthor();
}

bool compByPublisher(Book& left, Book& right) {
	return left.getPublisher() < right.getPublisher();
}

class BooksContainer {
private:
	vector<Book> container;

public:
	void add(Book &book) {
		container.push_back(book);
	}

	void edit(Book &book, Book &newBook) {
		int editIndex = 0;
		for (int i = 0; i < container.size(); i++)
		{
			if (container[i] == book) {
				editIndex = i;
				break;
			}
		}

		container.at(editIndex) = newBook;
	}


	void remove(Book &book) {
		int deleteIndex = 0;
		for (int i = 0; i < container.size(); i++)
		{
			if (container[i] == book) {
				deleteIndex = i;
				break;
			}
		}

		container.erase(container.begin() + deleteIndex);
	}

	void printToTheConsole() {
		ostream_iterator<Book> cout_it(cout, " ");
		copy(container.begin(), container.end(), cout_it);
	}

	static void printToTheConsole(typename vector <Book> ::iterator begin, typename vector <Book> ::iterator end) {
		ostream_iterator<Book> cout_it(cout, " ");

		copy(begin, end, cout_it);
	}

	void printToTheFile() {

	}

	void readFromConsole() {
		istream_iterator<Book> cin_it(cin), eos;

		copy(cin_it, eos, back_inserter(container));
	}

	vector<Book> findById(int id) {

		vector<Book> result;

		copy_if(container.begin(), container.end(), result.begin(), [&id](Book& b) {return b.getId() == id; });
	}

	vector<Book> findByClientSecondName(string secondName) {
		vector<Book> result;
		
		copy_if(container.begin(), container.end(), result.begin(), [&secondName](Book& b) {return b.getClientSecondName() == secondName; });

		return result;
	}

	vector<Book> findByAuthor(string author) {
		vector<Book> result;
		
		copy_if(container.begin(), container.end(), result.begin(), [&author](Book& b) {return b.getAuthor() == author; });

		return result;
	}

	vector<Book> findByPublisher(string publisher) {
		vector<Book> result;
		
		copy_if(container.begin(), container.end(), result.begin(), [&publisher](Book& b) {return b.getPublisher() == publisher; });

		return result;
	}

	

	vector<Book> findByIdWithBinarySearch(int id) {
		//сортировать
		sort(container.begin(), container.end(), compById);

		vector<Book> result;
		//тут должен быть бинарный поиск
		int m, l = 0, r = container.size();
		while (l < r) {
			m = (l + r) / 2;
			if (container[m].getId() < id) l = m + 1;
			else r = m;
		}

		//если r-ый элемент подходит, то ищем в его окрестносятях такие же
		if (container[r].getId() == id) {
			result.push_back(container[r]);

			bool search = true;
			int idx = r - 1;
			while (search && r >= 0) {
				if (container[idx].getId() == id) {
					result.push_back(container[idx]);
					idx--;
				}
				else {
					search = false;
				}
			}

			idx = r + 1;
			search = true;
			while (search && r < container.size()) {
				if (container[idx].getId() == id) {
					result.push_back(container[idx]);
					idx++;
				}
				else {
					search = false;
				}
			}
		}
		

		return result;
	}

	vector<Book> findByAuthorWithBinarySearch(string author) {
		//сортировать
		sort(container.begin(), container.end(), compByAuthor);
			
		vector<Book> result;
		//тут должен быть бинарный поиск
		int m, l = 0, r = container.size();
		while (l < r) {
			m = (l + r) / 2;
			if (container[m].getAuthor() < author) l = m + 1;
			else r = m;
		}

		//если r-ый элемент подходит, то ищем в его окрестносятях такие же
		if (container[r].getAuthor() == author) {
			result.push_back(container[r]);

			bool search = true;
			int idx = r - 1;
			while (search && r >= 0) {
				if (container[idx].getAuthor() == author) {
					result.push_back(container[idx]);
					idx--;
				}
				else {
					search = false;
				}
			}

			idx = r + 1;
			search = true;
			while (search && r < container.size()) {
				if (container[idx].getAuthor() == author) {
					result.push_back(container[idx]);
					idx++;
				}
				else {
					search = false;
				}
			}
		}



		return result;
	}

	vector<Book> findByPublisherWithBinarySearch(string publisher) {
		//сортировать
		sort(container.begin(), container.end(), compByPublisher);

		vector<Book> result;
		//тут должен быть бинарный поиск
		int m, l = 0, r = container.size();
		while (l < r) {
			m = (l + r) / 2;
			if (container[m].getPublisher() < publisher) l = m + 1;
			else r = m;
		}

		//если r-ый элемент подходит, то ищем в его окрестносятях такие же
		if (container[r].getPublisher() == publisher) {
			result.push_back(container[r]);

			bool search = true;
			int idx = r - 1;
			while (search && r >= 0) {
				if (container[idx].getPublisher() == publisher) {
					result.push_back(container[idx]);
					idx--;
				}
				else {
					search = false;
				}
			}

			idx = r + 1;
			search = true;
			while (search && r < container.size()) {
				if (container[idx].getPublisher() == publisher) {
					result.push_back(container[idx]);
					idx++;
				}
				else {
					search = false;
				}
			}
		}

		return result;
	}
};






	/*	for (const Book& b : container)
			cout << b << "\n";*/
