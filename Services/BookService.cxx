#include <iostream>
#include <Services/BookService.hpp>
#include <DataStructure/LinkedList.hpp>
using namespace std;
BookService::BookService(LinkedList<Book>& bookList)
{
    this->bookList = &bookList; // Initialize the book list
}

BookService::~BookService()
{    
    cout << "BookService destroyed and book list cleaned up." << endl;
}

void BookService::AddBook(const Book &book)
{
    cout << "Book added: " << book.Title << " by " << book.Author << endl;
    bookList->InsertAtHead(book); // Insert the book at the head of the list
}

void BookService::PrintBooks()
{
    cout << "Printing all books in the list:" << endl;
    bookList->Print(); // Print all books in the list
}
