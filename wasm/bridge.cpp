#include "jitter_buffer.hpp"
// WebAssembly Emscripten bindings
extern "C" {
    JitterBuffer* create_jitter_buffer(int delay) {
        return new JitterBuffer(delay);
    }
}
