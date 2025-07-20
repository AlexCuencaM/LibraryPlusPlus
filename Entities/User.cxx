#include <Entities/User.hpp>
#include <iostream>
using namespace std;
ostream &operator<<(ostream &os, const User &book)
{
    // TODO: insert return statement here
    os << "Name: " << book.Name << ", Cedula: " << book.Cedula;
    return os;
}