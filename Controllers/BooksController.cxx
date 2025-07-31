#include <Services/BookService.hpp>
#include <Views/MenuView.hpp>
#include <DataStructure/ModernLinkedList.hpp>
#include <Entities/Book.hpp>
#include <iostream>
#include <Controllers/BooksController.hpp>
#include <Views/BooksView.hpp>
using namespace std;
BooksController::BooksController(BookService& bookService, BooksView& booksView)
{
    // Initialize the book service
    this->bookService = &bookService; // Assuming bookService is a reference to an existing BookService instance
    this->booksView = &booksView; // Assuming booksView is a reference to an existing BooksView instance
}
BooksController::~BooksController()
{
}
void BooksController::AddBook()
{
    Book newBook;
    // Assuming BooksView has a method to insert a book
    if (booksView) {
        booksView->InsertBook(newBook); // Call the InsertBook method from BooksView
        bookService->AddBook(newBook); // Add the book to the service
    } else {
        cout << "BooksView is not initialized." << endl;
    }
}

void BooksController::PrintBooks()
{
    cout << "Printing all books in the list:" << endl;
    this->bookService->PrintBooks(); // Call the PrintBooks method from BooksController
    cout << "Press Enter to continue..." << endl;
    cin.ignore(); // Clear the input buffer
    cin.get(); // Wait for Enter key
}
void BooksController::SearchBook()
{
    string title, author;
    this->booksView->SearchBook(title, author); // Get search criteria from user    
    Book* bookFiltered = this->bookService->SearchBookByTreeDataStructure(title, author); // Call the SearchBook method from BookService
    this->booksView->ShowResultsBySearch(bookFiltered); // Show the results of the search
}