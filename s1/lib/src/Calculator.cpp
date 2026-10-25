#include "calculator/Calculator.h"
#include <stdexcept>

namespace Calculator {
namespace {
void validateDimensions(double width, double height) {
    if (!(width > 0) || !(height > 0)) {
        throw std::invalid_argument("Rectangle dimensions must be positive");
    }
}
}

double rectangleArea(double width, double height) {
    validateDimensions(width, height);
    return width * height;
}

double rectanglePerimeter(double width, double height) {
    validateDimensions(width, height);
    return 2 * (width + height);
}
}
