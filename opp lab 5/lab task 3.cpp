#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    // Constructor
    Book(const string& _title, const string& _author, int _publicationYear) : title(_title), author(_author), publicationYear(_publicationYear) {}

    // Accessors
    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
};

class Library {
private:
    unordered_map<string, Book> books;

public:
    // Function to add a book
    void addBook(const Book& book) {
        books.emplace(book.getTitle(), book);
    }

    // Function to remove a book
    void removeBook(const string& title) {
        auto it = books.find(title);
        if (it != books.end()) {
            books.erase(it);
        }
        else {
            cout << "Book not found." << endl;
        }
    }
    // Function to list all books
    void listBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        }
        else {
            cout << "Books in the library:" << endl;
            for (const auto& pair : books) {
                const Book& book = pair.second;
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Publication Year: " << book.getPublicationYear() << endl;
            }
        }
    }
};
int main() {
    Library library;
    // Adding books
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));
    // Listing books
    library.listBooks();
    // Removing a book
    library.removeBook("To Kill a Mockingbird");
    // Listing books after removal
    library.listBooks();
    return 0;
}
