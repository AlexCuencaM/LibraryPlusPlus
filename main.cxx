#include <iostream>
#include <DataStructure/ModernLinkedList.hpp>
#include <Services/BookService.hpp>
#include <MenuBuilder.hpp>
using namespace std;
int main(int argc, char* argv[]) 
{
    ModernLinkedList<Book> bookList;
    LinkedList<Book>* linkedList = &bookList;
    BookService bookService(bookList);
    BooksController  bookController(bookService);
    MenuBuilder menuBuilder(bookController);
    menuBuilder.BuildMenu();
    cout << "Exiting the program." << endl;
    return 0;
}