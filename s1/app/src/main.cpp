#include "calculator/Calculator.h"
#include <iostream>

int main() {
    const double width = 6.0;
    const double height = 3.0;

    std::cout << "Rectangle: " << width << " x " << height << '\n';
    std::cout << "Area: " << Calculator::rectangleArea(width, height) << '\n';
    std::cout << "Perimeter: " << Calculator::rectanglePerimeter(width, height) << '\n';
}
