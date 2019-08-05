#include "packer.h"

#include <iostream>
#include <algorithm>
#include <cassert>
#include <typeinfo>

#include "levelh.h"

Packer::Packer() : _basketCount(0)
{

}

void Packer::setupContainer(const Rectangle &newCont)
{
    _basket = newCont;
    _basketCount = 1;
}

Rectangle Packer::container() const
{
    return _basket;
}

void Packer::addBlock(int w, int h)
{
    _blocks.push_back(Rectangle(w, h, true));
}

bool cmpHeight(const Rectangle &a, const Rectangle &b)
{
    return a.height() > b.height();
}

bool cmpWidth(const Rectangle &a, const Rectangle &b)
{
    return a.width() > b.width();
}

bool cmpSquare(const Rectangle &a, const Rectangle &b)
{
    return a.square() < b.square();
}

void Packer::exec()
{
#ifdef DEBUG
    printBasket();
#endif

    printInputBlocksInfo();

    int ignoredBlocks = 0;
    int basketNum = 0;

    /// Ignore blocks that are too big for our Basket
    for (auto it = _blocks.begin(); it != _blocks.end();)
    {
        if (!(*it).tryToFitWithin(_basket)) {
            it = _blocks.erase(it);
            ++ignoredBlocks;
        }
        else
            ++it;
    }

    printTotalSquareToPlace();

    _blocks.sort(cmpHeight);

    while (!_blocks.empty())
    {
        fillBasket(basketNum);
        ++basketNum;
    }

    printf("%d blocks was ignored\n", ignoredBlocks);

    printPlacedBlocksInfo();
    printUnplacedBlocksInfo();
}

void Packer::printTotalSquareToPlace() const
{
    int totalSqr = 0;
    for (auto it = _blocks.cbegin(); it != _blocks.cend(); ++it) {
        totalSqr += it->square();
    }
    printf("total block square is %d\n\n", totalSqr);
}

void Packer::printPlacedBlocksInfo() const
{
    printf("\nAmount of placed blocks: %d\n", _placedBlocks.size());

    printf("\nPlaced blocks:\n");
    for (auto el : _placedBlocks) {
        printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n", el.first, el.second.topLeft().x, el.second.topLeft().y,
                                                      el.second.topRight().x, el.second.topRight().y,
                                                    el.second.bottomRight().x, el.second.bottomRight().y,
                                                   el.second.bottomLeft().x, el.second.bottomLeft().y);
    }
}

void Packer::printUnplacedBlocksInfo() const
{
    printf("\nAmount of unplaced blocks: %d\n", _blocks.size());

    if (!_blocks.empty()) {
        printf("\nUnplaced blocks are:\n");
        for (auto el : _blocks) {
            printf("%d,%d\n", el.width(), el.height());
        }
    }
}

void Packer::printBasket() const
{
    printf("Basket: TopLeft= (%d, %d), BotRight= (%d, %d)\n\n",
           _basket.topLeft().x, _basket.topLeft().y,
           _basket.bottomRight().x, _basket.bottomRight().y);
}

void Packer::printInputBlocksInfo() const
{
    printf("We have %d blocks to place\n", _blocks.size());
}

//template<class Iter>
//auto Packer::placeFirstBlock(Iter const& it, int basket, bool& horizontal) -> Iter
//{
//    assert(typeid(*it) == typeid(Rectangle));

//    auto block = (*it).fitWithinClone(_basket, horizontal);
//    _placedBlocks.insert(std::pair<int, Rectangle>(basket, block));
//    return _blocks.erase(it);
//}

//auto Packer::findBlockMaxSquare() const -> decltype(_blocks.begin())
//{
//    return std::max_element(_blocks.begin(), _blocks.end(), cmpSquare);
//}

void Packer::fillBasket(int &basketNum)
{
    int amount = 0;
    Rectangle space(_basket);

    do
    {
        LevelH level = LevelH(space, &_blocks, &_placedBlocks);

        for (auto it = _blocks.begin(); it != _blocks.end(); )
        {
            bool ok;
            it = level.addBlock(basketNum, it, ok);
            if (!ok)
                ++it;

        }
        space.cutTop(level.levelSpace().height());

        amount = level.blockAmount();
    }
    while (amount > 0);
}

