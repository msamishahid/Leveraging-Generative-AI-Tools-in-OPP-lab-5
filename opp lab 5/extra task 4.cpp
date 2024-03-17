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
            cout << "Book removed successfully." << endl;
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

void userInterface(Library& lib) {
    string command;
    while (true) {
        cout << "Enter command (add, remove, list, exit): ";
        getline(cin, command);

        if (command == "add") {
            string title, author;
            int publicationYear;
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter publication year: ";
            cin >> publicationYear;
            cin.ignore(); // Ignore newline character left in the buffer
            lib.addBook(Book(title, author, publicationYear));
        }
        else if (command == "remove") {
            string title;
            cout << "Enter title of the book to remove: ";
            getline(cin, title);
            lib.removeBook(title);
        }
        else if (command == "list") {
            lib.listBooks();
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
}

int main() {
    Library myLibrary;
    userInterface(myLibrary);
    return 0;
}
