#include <iostream>
#include <DataStructure/ModernLinkedList.hpp>
#include <Services/BookService.hpp>
#include <MenuBuilder.hpp>
using namespace std;
int main(int argc, char* argv[]) 
{
    ModernLinkedList<Book> bookList;
    BookService bookService(bookList);
    BooksView booksView;
    BooksController bookController(bookService, booksView);
    MenuBuilder menuBuilder(bookController);
    menuBuilder.BuildMenu();
    cout << "Exiting the program." << endl;
    return 0;
}