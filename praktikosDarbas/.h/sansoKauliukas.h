#include <random>
#include <ctime>

using namespace std;

int rastiObjPoz(int sansas) {
    mt19937 gen;
    gen.seed(time(0));
    uniform_int_distribution<uint32_t> random1(5, 100);
    uniform_int_distribution<uint32_t> random2(5, 100);
    return sansas;
}