#include <Views/UserView.hpp>
#include <iostream>
using namespace std;
void UserView::InsertUser(User &newUser)
{
    cout << "Inserting a new user..." << endl;
    cout << "Enter cedula: ";
    cin >> newUser.Cedula;
    cin.ignore(); // Clear the input buffer
    cout << "Enter name: ";
    getline(cin, newUser.Name);
    cout << "User added successfully!" << endl;
    cout << "Cedula: " << newUser.Cedula << ", Name: " << newUser.Name << endl;
    cin.ignore(); // Clear the input buffer
}

void UserView::SearchCedula(std::string &cedula)
{
    cout << "Ingrese cédula del usuario a buscar: ";
    cin >> cedula;
}


bool UserView::ValidateUser(User *user)
{
    if (user == nullptr) {
        cout << "Usuario no encontrado!" << endl;
        return false; // User not found
    }
    cout << "Usuario encontrado: " << *user << endl; //<< user->Name << " with cedula: " << user->Cedula << endl;
    return true; // User found
}
