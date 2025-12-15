cmake_minimum_required(VERSION 3.10)
project(seminar3)

# Установите стандарт C++ (C++17 для новой версии gtest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найти GoogleTest (если используется)
find_package(GTest REQUIRED)

# Добавить папку include в пути поиска заголовков
include_directories(include)

# Создать исполняемый файл
add_executable(seminar3 
    tests/test_seminar3.cpp
    main.cpp
    # Добавьте сюда другие .cpp файлы, если они есть
)

# Если используете gtest, добавить линковку
if(GTest_FOUND)
    target_link_libraries(seminar3 GTest::gtest GTest::gtest_main)
    # Для macOS может потребоваться pthread
    if(APPLE OR UNIX)
        target_link_libraries(seminar3 pthread)
    endif()
endif()