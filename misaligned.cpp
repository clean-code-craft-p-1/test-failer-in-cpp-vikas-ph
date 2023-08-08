#include <iostream>
#include <assert.h>

namespace ColorMap {
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

int getColorPairNumber(int pairNumber) {
    if ((0 < pairNumber) && (26 > pairNumber))
    {
        return pairNumber;
    }
    return 0;
}
}

namespace ColorMapTests {
void TestColorMapPairNumber()
{
    int result = ColorMap::printColorMap();
    assert(ColorMap::getColorPairNumber(result) == 25);
}
}


int main() {
    ColorMapTests::TestColorMapPairNumber();
    std::cout << "All is well (maybe!)\n";
    return 0;
}