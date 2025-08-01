#include <Entities/User.hpp>
#include <iostream>
using namespace std;
ostream &operator<<(ostream &os, const User &user)
{
    // TODO: insert return statement here
    os << "Nombre: " << user.Name << ", Cedula: " << user.Cedula;
    return os;
}
bool User::operator==(const User &other) const
{
    return this->Name == other.Name && this->Cedula == other.Cedula;
}