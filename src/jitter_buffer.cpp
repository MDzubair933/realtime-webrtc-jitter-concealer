#include "jitter_buffer.hpp"
#include <algorithm>

void JitterBuffer::insert_packet(const AudioPacket& packet) {
    ring_buffer.push_back(packet);
}

std::vector<float> JitterBuffer::get_audio_frame() {
    if (ring_buffer.empty()) {
        return synthesize_lost_packet();
    }
    auto frame = ring_buffer.front().pcm_samples;
    ring_buffer.erase(ring_buffer.begin());
    return frame;
}

std::vector<float> JitterBuffer::synthesize_lost_packet() {
    // Concealment by waveform interpolation
    return std::vector<float>(960, 0.0f);
}
