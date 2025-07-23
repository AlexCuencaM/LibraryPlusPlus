#include <Entities/LoanBook.hpp>
#include <iostream>
LoanBook::LoanBook(Book& book)
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
        os << "No book associated with this loan.";
        return os;
    }
    os << "Titulo del libro: " << loanBook.GetBook()->Title << ", Autor: " << loanBook.GetBook()->Author;
    return os;
}