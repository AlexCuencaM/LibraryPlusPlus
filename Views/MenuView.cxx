#include <Views/MenuView.hpp>
using namespace std;
MenuView::MenuView(BooksController& booksController)
{
    // Initialize the booksController pointer
    this->booksController = &booksController; // Assuming booksController is a reference to an existing BooksController instance
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
            // Implement user creation functionality
            break;
        case 5:
            // Implement book lending functionality
            break;
        case 6:
            // Implement book return functionality
            break;
        case 7:
            cout << "Exiting the system." << endl;
            return false; // Exit the menu
        default:
            cout << "Invalid option. Please try again." << endl;
            return false; // Continue showing the menu
    }
    return true; // Continue showing the menu
}
