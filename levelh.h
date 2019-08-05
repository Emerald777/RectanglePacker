#pragma once

#include "userdefines.h"

/// Horizontal Level of blocks
/// Fills the empty space of base Rectangle with other rectangles

class LevelH
{
    Rectangle _base;
    InputContainer *_blocks;
    OutputContainer *_placedBlocks;

    int _count;
    Rectangle _available;

public:
    LevelH(Rectangle const &base, InputContainer *in, OutputContainer *out);
    ~LevelH();

    Rectangle levelSpace() const;

    int blockAmount() const;

    template<class Iter>
    auto addBlock(int num, Iter &it, bool &ok) -> Iter
    {
        ok = it->tryToFitWithin(_available);
        if (!ok) return it;

        bool horiz;
        auto rotated = it->fitWithinClone(_available, horiz);
        rotated.move(_available.topLeft());

        if (_count == 0) {
           _available.cutBottom(_available.height() - rotated.height());
           _base = _available;
        }

        ++_count;
        _available.cutLeft(rotated.width());

        _placedBlocks->insert(std::pair<int, Rectangle>(num, rotated));


#ifdef DEBUG
        printAvailable();
        printBlocksAmount();
        printf("-- end of AddBlock() -- \n");
#endif

        return _blocks->erase(it);
    }

    void printAvailable() const;
    void printBlocksAmount() const;
};

