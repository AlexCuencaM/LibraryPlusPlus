#include <Views/BooksView.hpp>
#include <iostream>
#include <Entities/Book.hpp>
#include <string>
#include <Controllers/BooksController.hpp>
#include <limits>
using namespace std;
BooksView::BooksView(BookService& bookService)
{
    // Initialize the book service
    this->bookService = &bookService; // Assuming bookService is a reference to an existing BookService instance
}

void BooksView::ShowBooks()
{
    this->bookService->PrintBooks(); // Call the PrintBooks method from BooksController
    cout << "Press Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    cin.get(); // Wait for Enter key
}

void BooksView::InsertBook(Book &newBook)
{
    cout << "Inserting a new book..." << endl;
    cout << "Enter author: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newBook.Author);
    cout << "Enter title: ";
    getline(cin, newBook.Title);
    cout << "Enter publisher: ";
    getline(cin, newBook.Publisher);
    cout << "Enter year: ";
    cin >> newBook.Year;
    cout << "Enter number of pages: ";
    cin >> newBook.Pages;
    cout << "Enter ISBN: ";
    cin >> newBook.ISBN;
    cout << "Book added successfully!" << endl;
    // Wait for user input before proceeding
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    cin.get(); // Wait for Enter key
}

BooksView::~BooksView()
{
}