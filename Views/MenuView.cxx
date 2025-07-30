#include <Views/MenuView.hpp>
#include <iostream>
using namespace std;
MenuView::MenuView(BooksController& booksController, UserController& userController, LoanBookController& loanBookController)
{
    // Initialize the booksController pointer
    this->booksController = &booksController;
    // Initialize the userController pointer
    this->userController = &userController;
    // Initialize the loanBookController pointer
    this->loanBookController = &loanBookController;
}

void MenuView::ShowMenu()
{
    cout << "\n=== SISTEMA DE BIBLIOTECA ===\n";
    cout << "1. Agregar Libro\n";
    cout << "2. Mostrar todo el catalogo de libros\n";
    cout << "3. Busqueda de libros\n";
    cout << "4. Crear Usuarios\n";
    cout << "5. Prestar Libros\n";
    cout << "6. Devolucion de Libros\n";
    cout << "7. Salir\n";
}

MenuView::~MenuView()
{
}

int MenuView::ChooseOption()
{
    int option;
    cout << "Seleccione una opcion: ";
    cin >> option;
    return option;
}

bool MenuView::SelectView(int option)
{
    switch (option)
    {
        case 1:
            booksController->AddBook();
            break;
        case 2:
            booksController->PrintBooks();
            break;
        case 3:
            booksController->SearchBook();
            break;
        case 4:
            userController->InsertUser();
            break;
        case 5:
            loanBookController->LoanBookByCedula();
            // Implement book lending functionality
            break;
        case 6:
            // Implement book return functionality
            loanBookController->ReturnBookByCedula();
            break;
        case 7:
            cout << "Saliendo del sistema." << endl;
            return false; // Exit the menu
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            return false; // Continue showing the menu
    }
    return true; // Continue showing the menu
}
