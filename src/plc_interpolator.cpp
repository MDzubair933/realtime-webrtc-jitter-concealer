#include <vector>
#include <cmath>

class PLCInterpolator {
public:
    static std::vector<float> extrapolatePitch(const std::vector<float>& history, int frame_size) {
        std::vector<float> concealed(frame_size, 0.0f);
        if (history.size() < frame_size) return concealed;
        float decay = 0.95f;
        for (int i = 0; i < frame_size; ++i) {
            concealed[i] = history[history.size() - frame_size + i] * decay;
        }
        return concealed;
    }
};
