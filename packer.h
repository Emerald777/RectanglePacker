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
