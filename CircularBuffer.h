#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <vector>
#include <string>

class CircularBuffer {
public:
    CircularBuffer(size_t capacity);
    void add(const std::string& log_entry);
    std::vector<std::string> get_all() const;

private:
    std::vector<std::string> buffer;
    size_t head;
    size_t tail;
    bool is_full;
};

#endif // CIRCULARBUFFER_H
