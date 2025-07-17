#include <iostream>
#include <Services/BookService.h>
#include <DataStructure/LinkedList.h>
using namespace std;
BookService::BookService(LinkedList<Book> *bookList)
{
    this->bookList = bookList; // Initialize the book list
}

BookService::~BookService()
{
    delete bookList; // Clean up the book list
    bookList = nullptr; // Avoid dangling pointer
    cout << "BookService destroyed and book list cleaned up." << endl;
}

void BookService::AddBook(const Book &book)
{
    if (bookList) {
        bookList->InsertAtHead(book); // Insert the book at the head of the list
        cout << "Book added: " << book.Title << " by " << book.Author << endl;
    } else {
        cout << "Book list is not initialized." << endl;
    }
}

void BookService::PrintBooks() const
{
    if (bookList) {
        cout << "Printing all books in the list:" << endl;
        bookList->Print(); // Print all books in the list
    } else {
        cout << "Book list is not initialized." << endl;
    }
}
