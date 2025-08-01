#include <iostream>
#include <Services/BookService.hpp>
#include <DataStructure/LinkedList.hpp>
#include <DataStructure/BinaryTree.hpp>
#include <vector>
using namespace std;
BookService::BookService(LinkedList<Book>& bookList, BinaryTree<Book>& treeOfBooks)
{
    this->bookList = &bookList; // Initialize the book list
    this->treeOfBooks = &treeOfBooks;
}

BookService::~BookService()
{    
    cout << "BookService destroyed and book list cleaned up." << endl;
}
void BookService::AddBook(const Book &book)
{
    cout << "Book added: " << book.Title << " by " << book.Author << endl;
    bookList->InsertAtHead(book); // Insert the book at the head of the list
}
void BookService::PrintBooks()
{   
    bookList->Print(); // Print all books in the list
}
//linear search
Book* BookService::SearchBook(std::string title, std::string author){
    // bookList
    if (title.empty() && author.empty()) {
        cout << "No search criteria provided." << endl;
        return nullptr; // Return nullptr if no search criteria is provided
    }
    return bookList->firstOrDefault([title, author](Book book){
        return book.Title == title || book.Author == author;
    });
}
//Tree searching
Book* BookService::SearchBookByTreeDataStructure(std::string title, std::string author)
{
    if (title.empty() && author.empty()) {
        cout << "No search criteria provided." << endl;
        return nullptr; // Return nullptr if no search criteria is provided
    }
    for (auto& book : bookList->GetAll()) {
        treeOfBooks->insertNode(book);
    }
    Book* bookFiltered = treeOfBooks->firstOrDefault([title, author](Book book){
        return book.Title == title || book.Author == author;
    });
    return bookFiltered;
}
void BookService::ModifyBook(Book bookModified)
{
    bookList->ForEach([bookModified](Book& data){
        if(bookModified.ISBN == data.ISBN){
            data.Title = bookModified.Title;
            data.Author = bookModified.Author;
            data.Publisher = bookModified.Publisher;
            data.Year = bookModified.Year;
            data.Pages = bookModified.Pages;
            return;
        }
    });
}
bool BookService::ValidateBook(Book *book)
{
    if (book == nullptr) {
        return false; // Book not found
    } else {
        return true; // Book found
    }
}
