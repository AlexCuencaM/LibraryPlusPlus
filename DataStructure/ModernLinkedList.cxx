#include <iostream>
#include <DataStructure/ModernLinkedList.h>
using namespace std;
template <typename Data>
void ModernLinkedList<Data>::InsertAtHead(Data data)
{
    dataList.push_front(data);
    cout << "Inserted at head: " << data << endl; // Assuming Data has an overloaded operator<<
}

template <typename Data>
void ModernLinkedList<Data>::Print()
{
    cout << "List contents: ";
    for (const auto& item : dataList) {
        cout << item << " "; // Assuming Data has an overloaded operator<<
    }
    cout << endl;
}
