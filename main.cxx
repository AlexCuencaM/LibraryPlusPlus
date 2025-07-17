#include <iostream>
#include <DataStructure/ModernLinkedList.hpp>
#include <Services/BookService.hpp>
#include <Entities/Book.hpp>
using namespace std;
int main(int argc, char* argv[]) 
{
    ModernLinkedList<Book> bookList;
    BookService bookService(bookList);
    Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 1925, 180, "9780743273565"};
    Book book2 = {"1984", "George Orwell", "Secker & Warburg", 1949, 328, "9780451524935"};
    bookService.AddBook(book1);
    bookService.AddBook(book2);
    bookService.PrintBooks();
    // The destructor will be called automatically when bookService goes out of scope
    cout << "Program finished." << endl;
    return 0;
}