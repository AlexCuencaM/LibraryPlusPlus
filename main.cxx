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
    // Initialize the linked lists for books and users
    ModernLinkedList<Book> bookList;
    ModernLinkedList<User> userList;
    ModernLinkedList<LoanBook> loanBookList;
    ModernQueue<Node<Book>*> books;
    BinaryTreeImpl<Book> tree(books);
    // Mock data for books
    // Book book1;
    // book1.Title = "Hola";
    // book1.Author = "Author1";
    // book1.Year = 2020;
    // book1.ISBN = "ISBN001";

    // Book book2;
    // book2.Title = "Adios";
    // book2.Author = "Author2";
    // book2.Year = 2021;
    // book2.ISBN = "ISBN002";

    // Book book3;
    // book3.Title = "Bienvenido";
    // book3.Author = "Author3";
    // book3.Year = 2022;
    // book3.ISBN = "ISBN003";
    // Book book4;
    // book4.Title = "Chocolate oe";
    // book4.Author = "Author3";
    // book4.Year = 2022;
    // book4.ISBN = "ISBN003";

    // tree.insertNode(book1);
    // tree.insertNode(book2);
    // tree.insertNode(book3);
    // tree.insertNode(book4);
    // // Add mock books to the linked list and queue
    // string title = "Chocolate oe";
    // Book* bookMoment = tree.firstOrDefault([title](Book currentBook) ->
    //     bool{
    //         return currentBook.Title == title;
    //     });

    // bool isFound = tree.any([title](Book currentBook) -> 
    //     bool { 
    //         return currentBook.Title == title;
    //     });
    // if(isFound){
    //     cout << "Boook found !!" << endl;
    //     cout << *bookMoment << endl;
    // }
    // else {
    //     cout << "Boook not found :(" << endl;
    // }
    
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