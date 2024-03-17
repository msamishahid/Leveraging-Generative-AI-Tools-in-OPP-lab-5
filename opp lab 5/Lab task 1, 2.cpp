#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    // Constructor
    Book(string _title, string _author, int _publicationYear) : title(_title), author(_author), publicationYear(_publicationYear) {}

    // Accessors
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
};

class BookManager {
private:
    vector<Book> books;

public:
    // Function to add a book
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Function to remove a book
    void removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Function to list all books
    void listBooks() const {
        if (books.empty()) {
            cout << "No books in the system." << endl;
        }
        else {
            cout << "List of Books:" << endl;
            for (const auto& book : books) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Publication Year: " << book.getPublicationYear() << endl;
            }
        }
    }
};

int main() {
    BookManager manager;
    // Adding books
    manager.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    manager.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    manager.addBook(Book("1984", "George Orwell", 1949));
    // Listing books
    manager.listBooks();
    // Removing a book
    manager.removeBook("To Kill a Mockingbird");
    // Listing books after removal
    manager.listBooks();

    return 0;
}
