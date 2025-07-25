#include <iostream>
#include <Services/BookService.hpp>
#include <DataStructure/LinkedList.hpp>
#include <vector>
using namespace std;
BookService::BookService(LinkedList<Book>& bookList)
{
    this->bookList = &bookList; // Initialize the book list
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
Book* BookService::SearchBook(std::string title,std::string author){
    // bookList
    if (title.empty() && author.empty()) {
        cout << "No search criteria provided." << endl;
        return nullptr; // Return nullptr if no search criteria is provided
    }
    vector<Book> allBooks = bookList->GetAll(); // Get all books from the list
    for (auto& book : allBooks) {
        if (book.Title == title || book.Author == author) {
            return new Book(book); // Return a new Book object if a match is found
        }
    }
    return nullptr; // Return nullptr if no book is found
}

bool BookService::ValidateBook(Book* book)
{
    if (book == nullptr) {
        return false; // Book not found
    } else {
        return true; // Book found
    }
}
