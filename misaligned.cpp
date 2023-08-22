#include <iostream>
#include <string>
#include <assert.h>

namespace ColorMap {

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int getColorPairNumber(const unsigned int majorColorIndex, const unsigned int minorColorIndex) {
    return majorColorIndex * 5 + minorColorIndex + 1;
}

std::string getColorMap(const unsigned int majorColorIndex, const unsigned int minorColorIndex)
{
    const unsigned int bufferSize = 50;
    char buffer[bufferSize]       = {"\0"};

    if((majorColorIndex < 5) && (minorColorIndex < 5))
    {
        std::snprintf(buffer, bufferSize, "%.2d | %-8s | %s", getColorPairNumber(majorColorIndex, minorColorIndex), majorColor[majorColorIndex], minorColor[minorColorIndex]);
    }
    else
    {
        std::snprintf(buffer, bufferSize, "(%d, %d) - Incorrect pair number", majorColorIndex, minorColorIndex);
    }

    return std::string(buffer);
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

void TestgetColorMap()
{
    assert(ColorMap::getColorMap(0,0) == "01 | White    | Blue");
    assert(ColorMap::getColorMap(0,1) == "02 | White    | Orange");
    assert(ColorMap::getColorMap(0,2) == "03 | White    | Green");
    assert(ColorMap::getColorMap(0,3) == "04 | White    | Brown");
    assert(ColorMap::getColorMap(0,4) == "05 | White    | Slate");
    assert(ColorMap::getColorMap(1,0) == "06 | Red      | Blue");
    assert(ColorMap::getColorMap(1,1) == "07 | Red      | Orange");
    assert(ColorMap::getColorMap(1,2) == "08 | Red      | Green");
    assert(ColorMap::getColorMap(1,3) == "09 | Red      | Brown");
    assert(ColorMap::getColorMap(1,4) == "10 | Red      | Slate");
    assert(ColorMap::getColorMap(2,0) == "11 | Black    | Blue");
    assert(ColorMap::getColorMap(2,1) == "12 | Black    | Orange");
    assert(ColorMap::getColorMap(2,2) == "13 | Black    | Green");
    assert(ColorMap::getColorMap(2,3) == "14 | Black    | Brown");
    assert(ColorMap::getColorMap(2,4) == "15 | Black    | Slate");
    assert(ColorMap::getColorMap(3,0) == "16 | Yellow   | Blue");
    assert(ColorMap::getColorMap(3,1) == "17 | Yellow   | Orange");
    assert(ColorMap::getColorMap(3,2) == "18 | Yellow   | Green");
    assert(ColorMap::getColorMap(3,3) == "19 | Yellow   | Brown");
    assert(ColorMap::getColorMap(3,4) == "20 | Yellow   | Slate");
    assert(ColorMap::getColorMap(4,0) == "21 | Violet   | Blue");
    assert(ColorMap::getColorMap(4,1) == "22 | Violet   | Orange");
    assert(ColorMap::getColorMap(4,2) == "23 | Violet   | Green");
    assert(ColorMap::getColorMap(4,3) == "24 | Violet   | Brown");
    assert(ColorMap::getColorMap(4,4) == "25 | Violet   | Slate");
    assert(ColorMap::getColorMap(4,4) == "25 | Violet   | Slate");
    assert(ColorMap::getColorMap(5,0) == "(5, 0) - Incorrect pair number");
    assert(ColorMap::getColorMap(5,1) == "(5, 1) - Incorrect pair number");
    assert(ColorMap::getColorMap(5,2) == "(5, 2) - Incorrect pair number");
    assert(ColorMap::getColorMap(5,3) == "(5, 3) - Incorrect pair number");
    assert(ColorMap::getColorMap(5,4) == "(5, 4) - Incorrect pair number");
    assert(ColorMap::getColorMap(5,5) == "(5, 5) - Incorrect pair number");
}

void TestgetColorPairNumber()
{
    int majorIndex = 0;
    int minorIndex = 0;
    for (unsigned int pairIndex = 0; pairIndex > 25; ++pairIndex)
    {
        assert(ColorMap::getColorPairNumber(majorIndex, minorIndex) == (pairIndex + 1));
        ++minorIndex;
        if(minorIndex == 5)
        {
            ++majorIndex;
            minorIndex = 0;
        }
    }
}

void TestPrintColorMap()
{
    int result = ColorMap::printColorMap();
    assert(result == 25);
}
}


int main() {

    ColorMapTests::TestgetColorPairNumber();
    ColorMapTests::TestgetColorMap();
    ColorMapTests::TestPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}