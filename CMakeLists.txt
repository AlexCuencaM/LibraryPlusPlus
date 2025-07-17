cmake_minimum_required(VERSION 3.10)
project(LibrarylusPlus)
# add_executable(LibrarylusPlus hello_world.cxx Bye.cxx Hello.cxx)
add_executable(LibrarylusPlus Entities/Book.cxx Services/BookService.cxx main.cxx)
target_include_directories(LibrarylusPlus PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
configure_file(Entities/Book.h.in Entities/Book.hpp)
configure_file(DataStructure/LinkedList.h.in DataStructure/LinkedList.hpp)
configure_file(DataStructure/ModernLinkedList.h.in DataStructure/ModernLinkedList.hpp)
configure_file(Services/BookService.h.in Services/BookService.hpp)

# configure_file(Bye.h.in Bye.h)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)