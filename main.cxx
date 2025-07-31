// #include <iostream>
// data structure
#include <DataStructure/ModernLinkedList.hpp>
#include <DataStructure/BinaryTree.hpp>
#include <DataStructure/BinaryTreeImpl.hpp>
#include <DataStructure/ModernQueue.hpp>

#include <Services/BookService.hpp>
#include <Services/UserService.hpp>
#include <Controllers/UserController.hpp>
#include <Controllers/BooksController.hpp>
#include <Controllers/LoanBookController.hpp>
#include <Views/BooksView.hpp>
#include <Views/UserView.hpp>
#include <MenuBuilder.hpp>
// #include <string>
// using namespace std;
int main(int argc, char* argv[]) 
{
    // Initialize the data structures for books and users
    ModernLinkedList<Book> bookList;
    ModernLinkedList<User> userList;
    ModernLinkedList<LoanBook> loanBookList;
    ModernQueue<Node<Book>*> books;
    BinaryTreeImpl<Book> tree(books);
    // Initialize the services
    BookService bookService(bookList, tree);
    UserService userService(userList); 
    LoanBookService loanBookService(loanBookList); // Initialize LoanBookService with the loan book list
    // Initialize the views
    BooksView booksView;
    UserView userView;
    LoanBookView loanBookView; 
    // Initialize the controllers
    UserController userController(userService, userView);   
    BooksController bookController(bookService, booksView);
    LoanBookController loanBookController(loanBookService, loanBookView, bookService, booksView, userService, userView); // Initialize LoanBookController with the service and view
    // Initialize the MenuBuilder with the controllers
    MenuBuilder menuBuilder(bookController, userController, loanBookController);
    menuBuilder.BuildMenu();
    return 0;
}