#include <cassert>
#include <vector>

int main() {
    std::vector<float> test_pcm(960, 0.5f);
    assert(test_pcm.size() == 960);
    return 0;
}
