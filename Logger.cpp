#include "Logger.h"
#include <iostream>
#include <fstream>

Logger::Logger(const std::string& filename, size_t max_entries)
    : log_file(filename), buffer(max_entries) {}

void Logger::log(const std::string& message) {
    buffer.add(message);
    write_to_file();
}

void Logger::write_to_file() {
    std::ofstream file(log_file, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Unable to open log file: " << log_file << std::endl;
        return;
    }

    for (const auto& entry : buffer.get_all()) {
        file << entry << std::endl;
    }

    file.close();
}
