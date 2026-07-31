#include "jitter_buffer.hpp"
#include <cassert>

int main() {
    JitterBuffer buffer(20);
    auto frame = buffer.get_audio_frame();
    assert(frame.size() == 960);
    return 0;
}
