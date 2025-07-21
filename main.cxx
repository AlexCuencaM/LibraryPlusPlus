#include <iostream>
#include <DataStructure/ModernLinkedList.hpp>
#include <Services/BookService.hpp>
#include <Services/UserService.hpp>
#include <Controllers/UserController.hpp>
#include <Controllers/BooksController.hpp>
#include <Controllers/LoanBookController.hpp>
#include <Views/BooksView.hpp>
#include <Views/UserView.hpp>
#include <MenuBuilder.hpp>
using namespace std;
int main(int argc, char* argv[]) 
{
    cout << "Welcome to the Library Management System!" << endl;
    // Initialize the linked lists for books and users
    ModernLinkedList<Book> bookList;
    ModernLinkedList<User> userList;
    ModernLinkedList<LoanBook> loanBookList;
    // Initialize the services
    BookService bookService(bookList);
    UserService userService(userList); 
    LoanBookService loanBookService(loanBookList); // Initialize LoanBookService with the loan book list
    // Initialize the views
    BooksView booksView;
    UserView userView;
    LoanBookView loanBookView; 
    // Initialize the controllers
    UserController userController(userService, userView);   
    BooksController bookController(bookService, booksView);
    LoanBookController loanBookController(loanBookService, loanBookView); // Initialize LoanBookController with the service and view
    // Initialize the MenuBuilder with the controllers
    MenuBuilder menuBuilder(bookController, userController, loanBookController);
    menuBuilder.BuildMenu();
    cout << "Exiting the program." << endl;
    return 0;
}