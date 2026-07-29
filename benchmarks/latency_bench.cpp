#include "jitter_buffer.hpp"
#include <chrono>
#include <iostream>

int main() {
    JitterBuffer buffer(40);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        AudioPacket pkt{ (uint32_t)i, (uint32_t)(i * 960), std::vector<float>(960, 0.1f) };
        buffer.insert_packet(pkt);
        buffer.get_audio_frame();
    }
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "10k frames processed in " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " us\n";
    return 0;
}
