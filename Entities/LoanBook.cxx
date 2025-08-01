#include <Entities/LoanBook.hpp>
#include <iostream>
LoanBook::~LoanBook()
{
    this->userQueue->ClearAll();
}
LoanBook::LoanBook(Book &book)
{
    // this->userQueue = &userQueue; // Initialize the user queue
    this->book = &book; // Initially, no book is associated with the loan
}
Book* LoanBook::GetBook() const
{
    return this->book; // Return the book associated with the loan
}

ostream &operator<<(ostream &os, const LoanBook &loanBook)
{
    // TODO: insert return statement here
    if (loanBook.GetBook() == nullptr) {
        os << "No hay un libro asociado al prestamos.";
        return os;
    }
    os << "Titulo del libro: " << loanBook.GetBook()->Title << ", Autor: " << loanBook.GetBook()->Author;
    return os;
}
bool LoanBook::operator==(const LoanBook& other) const {
        return this->book != nullptr && other.book != nullptr && this->book == other.book;
};