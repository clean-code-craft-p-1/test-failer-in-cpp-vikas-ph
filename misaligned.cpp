#include <iostream>
#include <assert.h>

namespace ColorMap {

int getColorPairNumber(int majorColorIndex, int minorColorIndex) {
    return majorColorIndex * 5 + minorColorIndex;
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << getColorPairNumber(i, j) << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}
}

namespace ColorMapTests {
void TestPrintColorMap()
{
    int result = ColorMap::printColorMap();
    assert(ColorMap::getColorPairNumber(0,0) == 1);
    assert(ColorMap::getColorPairNumber(0,1) == 2);
    assert(ColorMap::getColorPairNumber(0,2) == 3);
    assert(ColorMap::getColorPairNumber(0,3) == 4);
    assert(ColorMap::getColorPairNumber(0,4) == 5);
    assert(ColorMap::getColorPairNumber(1,0) == 6);
    assert(result == 25);
}
}


int main() {
    ColorMapTests::TestPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}