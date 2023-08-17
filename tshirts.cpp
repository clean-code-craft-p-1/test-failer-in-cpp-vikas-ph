#include <iostream>
#include <assert.h>

namespace TShirtsSize {
char size(int cms) {
    char sizeName = '\0';
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}
}

namespace TShirtsSizeTests {
void TestTShirtsSize()
{
    assert(TShirtsSize::size(37) == 'S');
    assert(TShirtsSize::size(38) == 'S');
    assert(TShirtsSize::size(40) == 'M');
    assert(TShirtsSize::size(42) == 'M');
    assert(TShirtsSize::size(43) == 'L');
}
}

int main() {
    TShirtsSizeTests::TestTShirtsSize();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
