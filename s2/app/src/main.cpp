#include "lab/Inventory.h"
#include <iostream>
#include <utility>

int main() {
    lab::Device sensor("Temperature sensor", 3);
    sensor.addReading(21.5);
    sensor.addReading(23.5);

    lab::Device backup(sensor);
    backup.setReading(0, 99.0);
    std::cout << "Original first reading: " << sensor.reading(0)
              << "; copy first reading: " << backup.reading(0) << '\n';

    lab::Device transferred(std::move(backup));
    std::cout << "Moved device has " << transferred.size()
              << " readings; source has " << backup.size() << '\n';

    lab::Inventory inventory;
    inventory.add(sensor);
    inventory.add(std::move(transferred));
    for (std::size_t i = 0; i < inventory.size(); ++i) {
        const auto& device = inventory.at(i);
        std::cout << device.name() << " average: " << device.average() << '\n';
    }
}
