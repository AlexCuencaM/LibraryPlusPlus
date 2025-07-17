cmake_minimum_required(VERSION 3.10)
project(LibrarylusPlus)
# add_executable(LibrarylusPlus hello_world.cxx Bye.cxx Hello.cxx)
add_executable(LibrarylusPlus main.cxx)
target_include_directories(LibrarylusPlus PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
configure_file(./Entities/Book.h.in ./Entities/Book.h)
# configure_file(Bye.h.in Bye.h)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)