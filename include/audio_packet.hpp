#pragma once
#include <cstdint>
#include <vector>

struct RTPHeader {
    uint8_t version : 2;
    uint8_t padding : 1;
    uint8_t extension : 1;
    uint8_t csrc_count : 4;
    uint8_t marker : 1;
    uint8_t payload_type : 7;
    uint16_t sequence_number;
    uint32_t timestamp;
    uint32_t ssrc;
};

inline bool is_newer_sequence(uint16_t seq_a, uint16_t seq_b) {
    return (uint16_t)(seq_a - seq_b) < 32768;
}
