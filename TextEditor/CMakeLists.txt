cmake_minimum_required(VERSION 3.10)

project(TextEditor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(text_editor
    src/main.cpp
    src/TextBuffer.cpp
    src/EditorBase.cpp
    src/TextEditor.cpp
    src/AutoSaveFile.cpp
    src/SharedDocument.cpp
)

target_include_directories(text_editor PRIVATE ${CMAKE_SOURCE_DIR}/src)