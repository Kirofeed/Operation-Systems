#ifndef LAB_FUNCTIONS_H
#define LAB_FUNCTIONS_H

#include <vector>
#include "globals.h"

// Функция вычисления минимального и максимального элементов массива с задержками
void computeMinMax(const std::vector<int>& array, int& min, int& max);

// Функция вычисления среднего значения массива с задержками
double computeAverage(const std::vector<int>& array);

void MinMaxThread();

void AverageThread();

#endif // LAB_FUNCTIONS_H
