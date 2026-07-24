#include <vector>
#include <cmath>

class Crossfader {
public:
    static void applyHannCrossfade(std::vector<float>& frameA, const std::vector<float>& frameB, int window_size) {
        for (int i = 0; i < window_size && i < (int)frameA.size() && i < (int)frameB.size(); ++i) {
            float alpha = 0.5f * (1.0f - std::cos(M_PI * i / window_size));
            frameA[i] = (1.0f - alpha) * frameA[i] + alpha * frameB[i];
        }
    }
};
