#ifndef PACKER_H
#define PACKER_H

#include "userdefines.h"

class Packer
{
    InputContainer _blocks;
    OutputContainer _placedBlocks;
    Rectangle _basket;

    int _basketCount;

private:

    /// Кладет блок в левый верхний угол
//    template<class Iter>
//    auto placeFirstBlock(Iter const& it, int basket, bool& horizontal) -> Iter;

    //auto findBlockMaxSquare() const -> decltype(_blocks.begin());

    void fillBasket(int& basketNum);

public:
    Packer();

    void setupContainer(Rectangle const& newCont);
    Rectangle container() const;

    void addBlock(int w, int h);

    void exec();

    void printTotalSquareToPlace() const;
    void printPlacedBlocksInfo() const;
    void printUnplacedBlocksInfo() const;

    void printBasket() const;
    void printInputBlocksInfo() const;
};

#endif // PACKER_H
