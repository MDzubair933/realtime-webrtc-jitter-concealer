#pragma once
#include <vector>
#include <cstdint>

struct AudioPacket {
    uint32_t sequence_number;
    uint32_t timestamp;
    std::vector<float> pcm_samples;
};

class JitterBuffer {
private:
    uint32_t target_delay_ms;
    std::vector<AudioPacket> ring_buffer;

public:
    JitterBuffer(uint32_t delay_ms = 40) : target_delay_ms(delay_ms) {}
    void insert_packet(const AudioPacket& packet);
    std::vector<float> get_audio_frame();
    std::vector<float> synthesize_lost_packet(); // PLC
};
