#include <Entities/Book.hpp>
#include <iostream>
ostream &operator<<(ostream &os, const Book &book)
{
    os << "Title: " << book.Title << ", Author: " << book.Author
       << ", Publisher: " << book.Publisher << ", Year: " << book.Year
       << ", Pages: " << book.Pages << ", ISBN: " << book.ISBN;
    return os;
}