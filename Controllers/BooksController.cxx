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
    // Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 1925, 180, "9780743273565"};
    // Book book2 = {"1984", "George Orwell", "Secker & Warburg", 1949, 328, "9780451524935"};
    // cout << "Adding a new book..." << endl;
    // this->bookService->AddBook(book1);
    // this->bookService->AddBook(book2);
}

void BooksController::PrintBooks()
{
    if (booksView) {
        booksView->ShowBooks(); // Call the ShowBooks method from BooksView
    } else {
        cout << "BooksView is not initialized." << endl;
    }
}
void BooksController::SearchBook()
{
}