#include <Entities/Book.hpp>
#include <iostream>
ostream &operator<<(ostream &os, const Book &book)
{
    os << "Titulo: " << book.Title << ", Autor: " << book.Author
       << ", Publisher: " << book.Publisher << ", Anios: " << book.Year
       << ", Paginas: " << book.Pages << ", ISBN: " << book.ISBN;
    return os;
}
bool Book::operator==(const Book& other) const {
        return Title == other.Title &&
               Author == other.Author; 
};