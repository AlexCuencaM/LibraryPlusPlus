#include <iostream>
#include <string>
#include <Views/BooksView.hpp>
#include <Entities/Book.hpp>
#include <Controllers/BooksController.hpp>
using namespace std;
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

    cin.ignore(); // Clear the input buffer
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
void BooksView::ShowResultsBySearch(Book* bookFiltered)
{
    if(bookFiltered == nullptr)
    {
        cout << "No hay registro de ese libro." << endl;
        return; // Exit if no book is found
    }
    cout << "Resultados de la busqueda:" << endl;
    cout << "Libro encontrado: " << *bookFiltered << endl;
}
BooksView::~BooksView()
{
}