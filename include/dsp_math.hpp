#pragma once
#include <vector>

inline float calculate_energy(const std::vector<float>& samples) {
    float sum = 0.0f;
    for (float s : samples) {
        sum += s * s;
    }
    return sum / (samples.empty() ? 1.0f : (float)samples.size());
}
