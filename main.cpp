#include "Logger.h"

int main() {
    Logger logger("logfile.txt", 10);

    for (int i = 1; i <= 20; ++i) {
        logger.log("Log entry " + std::to_string(i));
    }

    return 0;
}
