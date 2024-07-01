#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(size_t capacity) : buffer(capacity), head(0), tail(0), is_full(false) {}

void CircularBuffer::add(const std::string& log_entry) {
    buffer[tail] = log_entry;
    if (is_full) {
        head = (head + 1) % buffer.size();
    }
    tail = (tail + 1) % buffer.size();
    is_full = tail == head;
}

std::vector<std::string> CircularBuffer::get_all() const {
    std::vector<std::string> logs;
    if (is_full) {
        for (size_t i = head; i < buffer.size(); ++i) {
            logs.push_back(buffer[i]);
        }
    }
    for (size_t i = 0; i < tail; ++i) {
        logs.push_back(buffer[i]);
    }
    return logs;
}
