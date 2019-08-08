#include <conio.h>
#include <chrono>

#include "rectangle.h"
#include "packer.h"

#include "levelh.h"

bool applyInput(Packer &pck)
{
    using Size = std::pair<int, int>;

    Size sz;

    if (scanf("%d,%d", &sz.first, &sz.second) == EOF) {
        printf("Error while reading container data!\n");
        return false;
    }
    pck.setupContainer(Geometry::Rectangle(sz.first, sz.second));

    while (scanf("%d,%d", &sz.first, &sz.second) != EOF)
    {
        pck.addBlock(sz.first, sz.second);
    }
    return true;
}

int main()
{
//    Geometry::Rectangle big(300, 100);

//    InputContainer in_cnt;
//    OutputContainer out_cnt;

//    in_cnt.push_back(Geometry::Rectangle(20, 30));
//    in_cnt.push_back(Geometry::Rectangle(10, 20));


//    {
//        LevelH L1(big, &in_cnt, &out_cnt);
//        L1.availableSpace().printBorders();

//        auto it = in_cnt.begin();
//        auto itnext = in_cnt.end();
//        if (L1.addBlock(0, it, itnext)) {
//            std::cout << "Added first block" << std::endl;
//            L1.availableSpace().printBorders();
//            L1.printBlocksAmount();
//        }

//        it = in_cnt.begin();
//        if (L1.addBlock(0, it, itnext)) {
//            std::cout << "Added second block" << std::endl;
//            L1.availableSpace().printBorders();
//            L1.printBlocksAmount();
//        }

//        std::cout << "output size = " << out_cnt.size() << std::endl;
//    }
//    bool hor = false;
//    if (b.tryToFitWithin(r)) {
//        auto n = b.fitWithinClone(r, hor);
//        std::cout << n << std::endl; //.printBorders();
//        std::cout << std::boolalpha << hor << std::endl;
//    }

//    r.printBorders();
//    r.move(Geometry::FPoint(5,5));
//    r.printBorders();
//    r.cutTop(10);
//    r.printBorders();
//    r.cutLeft(10);
//    r.printBorders();
//    r.cutBottom(5);
//    r.printBorders();

//    Geometry::FPoint pt(3,3);
//    Geometry::FPoint pt2 = pt.rotateAround(-90.0f, Geometry::FPoint(1,1));
//    std::cout << "Rotation result = (" << pt2 << ")\n";

    Packer packer;
    if (!applyInput(packer))
        return -1;   

#ifndef RAW_OUT_DATA
    auto t1 = std::chrono::steady_clock::now();
#endif

    packer.exec();

#ifndef RAW_OUT_DATA
    auto t2 = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

    printf("\nDone in %d ms\n", static_cast<int>(elapsed_ms.count()) );
#endif

    _getch();
    return 0;
}
