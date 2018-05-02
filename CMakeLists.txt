cmake_minimum_required(VERSION 3.1)

project(chat_test_app LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(include)
add_executable(${PROJECT_NAME} "src/main.cpp" "qml.qrc" "src/chatCore.cpp" "include/chatCore.h" "include/userInput.h" "src/UserInput.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
