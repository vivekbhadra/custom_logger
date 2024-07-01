#ifndef LOGGER_H
#define LOGGER_H

#include "CircularBuffer.h"
#include <string>

class Logger {
public:
    Logger(const std::string& filename, size_t max_entries);
    void log(const std::string& message);

private:
    void write_to_file();

    std::string log_file;
    CircularBuffer buffer;
};

#endif // LOGGER_H

