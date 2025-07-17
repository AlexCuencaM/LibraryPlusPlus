#include <iostream>
#include <Entities/Book.h>
using namespace std;
int main(int argc, char* argv[]) 
{
    Book myBook;
    myBook.Title = "1984";
    myBook.Author = "George Orwell";
    myBook.Publisher = "Secker & Warburg";
    myBook.Year = 1949;
    myBook.Pages = 328;
    myBook.ISBN = "978-0451524935";
    cout << "Book Title: " << myBook.Title << endl;
    cout << "Author: " << myBook.Author << endl;
    cout << "Publisher: " << myBook.Publisher << endl;
    cout << "Year: " << myBook.Year << endl;
    cout << "Pages: " << myBook.Pages << endl;
    cout << "ISBN: " << myBook.ISBN << endl;
    return 0;
}