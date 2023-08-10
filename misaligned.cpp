#include <iostream>
#include <string>
#include <assert.h>

namespace ColorMap {

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int getColorPairNumber(const int majorColorIndex, const int minorColorIndex) {
    return majorColorIndex * 5 + minorColorIndex;
}

std::string getColorMap(const int majorColorIndex, const int minorColorIndex)
{
    return std::string(std::to_string(getColorPairNumber(majorColorIndex, minorColorIndex)) + " | " + majorColor[majorColorIndex] + " | " + minorColor[majorColorIndex]);
}

int printColorMap() {

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << getColorMap(i, j) << "\n";
        }
    }
    return i * j;
}
}

namespace ColorMapTests {
void TestPrintColorMap()
{
    int result = ColorMap::printColorMap();
    assert(result == 25);

    assert(ColorMap::getColorMap(0,0) == "1 | White | Blue" );
    assert(ColorMap::getColorMap(0,1) == "2 | White | Orange");
    assert(ColorMap::getColorMap(0,2) == "3 | White | Green");
    assert(ColorMap::getColorMap(0,3) == "4 | White | Brown");
    assert(ColorMap::getColorMap(0,4) == "5 | White | Slate");
    assert(ColorMap::getColorMap(1,0) == "6 | Red | Blue");

    assert(ColorMap::getColorPairNumber(0,0) == 1);
    assert(ColorMap::getColorPairNumber(0,1) == 2);
    assert(ColorMap::getColorPairNumber(0,2) == 3);
    assert(ColorMap::getColorPairNumber(0,3) == 4);
    assert(ColorMap::getColorPairNumber(0,4) == 5);
    assert(ColorMap::getColorPairNumber(1,0) == 6);
}
}


int main() {
    ColorMapTests::TestPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}