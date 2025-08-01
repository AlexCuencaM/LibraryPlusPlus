#include <Views/MenuView.hpp>
#include <iostream>
using namespace std;
MenuView::MenuView(BooksController& booksController, UserController& userController, LoanBookController& loanBookController)
{
    this->booksController = &booksController;
    this->userController = &userController;
    this->loanBookController = &loanBookController;
}

void MenuView::ShowMenu()
{
    int opc = 1;
    cout << "\n=== SISTEMA DE BIBLIOTECA ===\n";
    cout << opc++ << ". Agregar Libro\n";
    cout << opc++ << ". Modificar Libro\n";
    cout << opc++ << ". Eliminar Libro\n";
    cout << opc++ << ". Mostrar todo el catalogo de libros\n";
    cout << opc++ << ". Busqueda de libros\n";
    cout << opc++ << ". Busqueda de libros | con Arbol binario !\n";
    cout << opc++ << ". Crear Usuarios\n";
    cout << opc++ << ". Prestar Libros\n";
    cout << opc++ << ". Devolucion de Libros\n";
    cout << opc++ << ". Salir\n";
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
            loanBookController->ModifyBook();
            break;
        case 4:
            loanBookController->DeleteBook();
            break;
        case 5:
            booksController->SearchBook();
            break;
        case 6:
            booksController->SearchBookByTreeDataStructure();
            break;
        case 7:
            userController->InsertUser();
            break;
        case 8:
            loanBookController->LoanBookByCedula();
            break;
        case 9:
            loanBookController->ReturnBookByCedula();
            break;
        case 10:
            cout << "Saliendo del sistema." << endl;
            return false; // Exit the menu
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            return false; // Continue showing the menu
    }
    return true; // Continue showing the menu
}
