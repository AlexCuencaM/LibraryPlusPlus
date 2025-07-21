#include <Views/UserView.hpp>
#include <iostream>
using namespace std;
void UserView::InsertUser(User &newUser)
{
    cout << "Inserting a new user..." << endl;
    cout << "Enter cedula: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newUser.Cedula);
    cout << "Enter name: ";
    getline(cin, newUser.Name);
    cout << "User added successfully!" << endl;
    cin.ignore(); // Clear the input buffer
}