#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Employee.h"

/*
 * Этот файл содержит простейшие юнит-тесты для проверки функций записи/чтения и сортировки.
 * Если вы совсем не знакомы с юнит-тестированием – не пугайтесь:
 * здесь показано, как можно организовать тесты с минимальными усилиями.
 */

// Тест записи и чтения сотрудников в/из бинарного файла
bool testWriteReadEmployees() {
    // Создаем тестовый вектор сотрудников
    std::vector<Employee> employees;
    Employee e1;
    e1.num = 2;
    std::strcpy(e1.name, "Alice");
    e1.hours = 40.0;
    Employee e2;
    e2.num = 1;
    std::strcpy(e2.name, "Bob");
    e2.hours = 35.0;
    employees.push_back(e1);
    employees.push_back(e2);

    const char* testFilename = "test_employees.bin";
    if (!writeEmployeeRecords(testFilename, employees)) {
        std::cerr << "Не удалось записать сотрудников." << std::endl;
        return false;
    }

    // Читаем данные обратно
    std::vector<Employee> readEmployees;
    if (!readEmployeeRecords(testFilename, readEmployees)) {
        std::cerr << "Не удалось прочитать сотрудников." << std::endl;
        return false;
    }

    if (readEmployees.size() != employees.size()) {
        std::cerr << "Несоответствие количества записей." << std::endl;
        return false;
    }

    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].num != readEmployees[i].num ||
            std::strcmp(employees[i].name, readEmployees[i].name) != 0 ||
            employees[i].hours != readEmployees[i].hours) {
            std::cerr << "Данные сотрудника не совпадают." << std::endl;
            return false;
        }
    }
    // Удаляем тестовый файл
    std::remove(testFilename);
    return true;
}

// Тест сортировки сотрудников по идентификационному номеру
bool testSortEmployees() {
    std::vector<Employee> employees;
    Employee e1, e2, e3;
    e1.num = 3; std::strcpy(e1.name, "Charlie"); e1.hours = 20;
    e2.num = 1; std::strcpy(e2.name, "Alice");   e2.hours = 40;
    e3.num = 2; std::strcpy(e3.name, "Bob");     e3.hours = 35;
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    
    // Выполняем сортировку
    sortEmployees(employees);
    
    if (employees[0].num != 1 || employees[1].num != 2 || employees[2].num != 3) {
        std::cerr << "Сортировка не удалась." << std::endl;
        return false;
    }
    return true;
}

int main() {
    int passed = 0, failed = 0;
    std::cout << "Запуск юнит-тестов..." << std::endl;
    
    if (testWriteReadEmployees()) {
        std::cout << "testWriteReadEmployees пройден." << std::endl;
        passed++;
    } else {
        std::cout << "testWriteReadEmployees провален." << std::endl;
        failed++;
    }
    
    if (testSortEmployees()) {
        std::cout << "testSortEmployees пройден." << std::endl;
        passed++;
    } else {
        std::cout << "testSortEmployees провален." << std::endl;
        failed++;
    }

    std::cout << "Тестов пройдено: " << passed << ", провалено: " << failed << std::endl;
    return (failed == 0) ? 0 : 1;
}