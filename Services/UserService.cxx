#include <Services/UserService.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
UserService::UserService(LinkedList<User> &userList)
{
    this->userList = &userList; // Initialize the user list
}
void UserService::AddUser(const User &user)
{
    userList->InsertAtHead(user); // Insert the user at the head of the list
}
User *UserService::GetUser(string &cedula)
{
    return userList->firstOrDefault([cedula](User user){
        return user.Cedula == cedula;
    }); // Return nullptr if user not found
}
UserService::~UserService()
{
}
