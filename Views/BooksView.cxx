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
    cout << "Printing all books in the list:" << endl;
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
void BooksView::SearchBook(string& title, string& author)
{
    // This method can be implemented to search for a book by title and author
    // For now, we will just print the search criteria
    cout << "Enter title to search, press N to skip the filter: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, title);
    cout << "Enter author to search, press N to skip the filter: ";
    getline(cin, author);
    if(title == "N" || title.empty()) {
        title = ""; // Reset title if 'N' is entered
    }
    if(author == "N" || author.empty()) {
        author = ""; // Reset author if 'N' is entered
    }
}
void BooksView::ShowResultsBySearch()
{
    string title, author;
    SearchBook(title, author); // Get search criteria from user
    Book* bookFiltered = this->bookService->SearchBook(title, author); // Call the SearchBook method from BookService
    if(bookFiltered == nullptr)
    {
        cout << "No book found matching the criteria." << endl;
    } 
    cin.ignore(); // Clear the input buffer
    cin.get(); // Wait for Enter key
}
BooksView::~BooksView()
{
}