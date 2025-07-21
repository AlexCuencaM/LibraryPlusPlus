#include <iostream>
#include <Entities/Book.hpp>
#include <Entities/User.hpp>
#include <DataStructure/ModernLinkedList.hpp>
#include <Services/BookService.hpp>
#include <Services/UserService.hpp>
#include <Controllers/UserController.hpp>
#include <Controllers/BooksController.hpp>
#include <Views/BooksView.hpp>
#include <Views/UserView.hpp>
#include <MenuBuilder.hpp>
using namespace std;
int main(int argc, char* argv[]) 
{
    ModernLinkedList<Book> bookList;
    ModernLinkedList<User> userList; // Assuming User is a class defined in Entities/User.hpp
    BookService bookService(bookList);
    UserService userService(userList); // Assuming UserService uses the same book list for demonstration
    BooksView booksView;
    UserView userView;
    UserController userController(userService, userView);   
    BooksController bookController(bookService, booksView);
    // Initialize the MenuBuilder with the controllers
    MenuBuilder menuBuilder(bookController, userController);
    menuBuilder.BuildMenu();
    cout << "Exiting the program." << endl;
    return 0;
}