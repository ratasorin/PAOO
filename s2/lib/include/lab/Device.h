#pragma once

#include <cstddef>
#include <string>

namespace lab {
class Device {
public:
    Device(std::string name, std::size_t capacity);
    ~Device();
    Device(const Device& other);
    Device(Device&& other) noexcept;
    Device& operator=(const Device& other);
    Device& operator=(Device&& other) noexcept;

    void addReading(double value);
    void setReading(std::size_t index, double value);
    double reading(std::size_t index) const;
    double average() const;
    const std::string& name() const noexcept { return name_; }
    std::size_t size() const noexcept { return size_; }
    std::size_t capacity() const noexcept { return capacity_; }

private:
    std::string name_;
    std::size_t capacity_;
    std::size_t size_;
    double* readings_;
};
}
