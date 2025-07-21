#include <Entities/User.hpp>
#include <iostream>
using namespace std;
ostream &operator<<(ostream &os, const User &user)
{
    // TODO: insert return statement here
    os << "Name: " << user.Name << ", Cedula: " << user.Cedula;
    return os;
}