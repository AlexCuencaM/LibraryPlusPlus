#include <Services/BookService.hpp>
#include <Views/MenuView.hpp>
#include <DataStructure/ModernLinkedList.hpp>
#include <Entities/Book.hpp>
#include <iostream>
#include <Controllers/BooksController.hpp>
using namespace std;
BooksController::BooksController(BookService& bookService)
{
    // Initialize the book service
    this->bookService = &bookService; // Assuming bookService is a reference to an existing BookService instance
}
BooksController::~BooksController()
{
}

void BooksController::AddBook()
{
    Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 1925, 180, "9780743273565"};
    Book book2 = {"1984", "George Orwell", "Secker & Warburg", 1949, 328, "9780451524935"};
    if (!this->bookService) {
        cout << "Book service is not initialized." << endl;
        return;
    }
    cout << "Adding a new book..." << endl;
    this->bookService->AddBook(book1);
    this->bookService->AddBook(book2);
}
void BooksController::PrintBooks()
{
    if (bookService) {
        bookService->PrintBooks(); // Call the PrintBooks method from BookService
    } else {
        cout << "Book service is not initialized." << endl;
    }
}
void BooksController::SearchBook()
{
}