#include <iostream>
#include <string>
#include <Views/BooksView.hpp>
#include <Entities/Book.hpp>
#include <Controllers/BooksController.hpp>
using namespace std;
void BooksView::InsertBook(Book &newBook)
{
    cout << "Agregando un nuevo libro..." << endl;
    cout << "Ingrese autor: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newBook.Author);
    cout << "Ingrese titulo del libro: ";
    getline(cin, newBook.Title);
    cout << "Enter publisher: ";
    getline(cin, newBook.Publisher);
    cout << "Ingrese anio: ";
    cin >> newBook.Year;
    cout << "Ingrese numero de paginas: ";
    cin >> newBook.Pages;
    cout << "Ingrese ISBN: ";
    cin >> newBook.ISBN;
    cout << "Libro agregado !" << endl;
    // Wait for user input before proceeding
    cout << "Presione enter para continuar...";

    cin.ignore(); // Clear the input buffer
    cin.get(); // Wait for Enter key
}
void BooksView::SearchBook(string& title, string& author)
{
    // This method can be implemented to search for a book by title and author
    // For now, we will just print the search criteria
    cout << "Ingrese el titulo para buscar, presione N para omitir el filtro: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, title);
    cout << "Ingrese el titulo para buscar, presione N para omitir el filtro: ";
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