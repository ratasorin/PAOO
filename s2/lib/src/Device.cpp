#include "lab/Device.h"
#include <iostream>
#include <stdexcept>
#include <utility>

namespace lab {
Device::Device(std::string name, std::size_t capacity)
    : name_(std::move(name)), capacity_(capacity), size_(0),
      readings_(capacity ? new double[capacity]{} : nullptr) {
    std::cout << "Constructed device: " << name_ << '\n';
}
Device::~Device() {
    std::cout << "Destroyed device: " << name_ << '\n';
    delete[] readings_;
}
void Device::addReading(double value) {
    if (size_ == capacity_) throw std::out_of_range("Device capacity reached");
    readings_[size_++] = value;
}
void Device::setReading(std::size_t index, double value) {
    if (index >= size_) throw std::out_of_range("Reading index out of range");
    readings_[index] = value;
}
double Device::reading(std::size_t index) const {
    if (index >= size_) throw std::out_of_range("Reading index out of range");
    return readings_[index];
}
double Device::average() const {
    if (size_ == 0) throw std::logic_error("No readings available");
    double sum = 0;
    for (std::size_t i = 0; i < size_; ++i) sum += readings_[i];
    return sum / size_;
}
}
