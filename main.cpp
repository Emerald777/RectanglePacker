#include <conio.h>
#include <chrono>

#include "rectangle.h"
#include "packer.h"


using Size = std::pair<int, int>;

int main()
{
    Packer packer;
    Size sz;

    if (scanf("%d, %d", &sz.first, &sz.second) == EOF) {
        printf("Error while reading container data!\n");
        return -1;
    }
    packer.setupContainer(Rectangle(sz.first, sz.second));

    const auto& cont = packer.container();
    printf("Container square %d - (%d, %d)\n\n",
                    cont.square(), cont.width(), cont.height());

    while (scanf("%d, %d", &sz.first, &sz.second) != EOF)
    {
        packer.addBlock(sz.first, sz.second);
    }

    auto t1 = std::chrono::steady_clock::now();

    packer.exec();

    auto t2 = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    printf("\nDone in %d ms\n", static_cast<int>(elapsed_ms.count()) );

    _getch();
    return 0;
}
