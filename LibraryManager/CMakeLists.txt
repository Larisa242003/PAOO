cmake_minimum_required(VERSION 3.10)
project(LibraryManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(library_lib
    src/Book.cpp
    src/Library.cpp
)

target_include_directories(library_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(library_app src/main.cpp)
target_link_libraries(library_app PRIVATE library_lib)

if (MSVC)
  target_compile_options(library_app PRIVATE /W4)
else()
  target_compile_options(library_app PRIVATE -Wall -Wextra -Wpedantic)
endif()
