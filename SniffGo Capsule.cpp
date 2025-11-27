#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    auto start_time = std::chrono::steady_clock::now();

    std::cout << "Welcome to SniffGo Capsule!\n";
    std::cout << "Press Ctrl+C to exit\n\n";

    while (true) {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
            current_time - start_time
        );

        long long total_seconds = elapsed.count();
        long long hours = total_seconds / 3600;
        long long minutes = (total_seconds % 3600) / 60;
        long long seconds = total_seconds % 60;

        std::cout << "\rElapsed Time: ";
        std::cout << std::setfill('0');
        std::cout << std::setw(2) << hours << ":"
                  << std::setw(2) << minutes << ":"
                  << std::setw(2) << seconds
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}