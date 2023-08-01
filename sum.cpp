//
//  sum.cpp
//  CSV-App
//
//  Created by Muhawenimana Janvier on 01/08/2023.
//

#include "sum.hpp"

double SUM(double num1, double num2) {
    return num1 + num2;
}

double SUM(const std::vector<double>& numbers) {
    double sum = 0.0;
    for (double num : numbers) {
        sum = SUM(sum,num);
    }
    return sum;
}

double SUM(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum = SUM(sum,arr[i]);
    }
    return sum;
}
