#include "levelh.h"


LevelH::LevelH(const Rectangle &base, InputContainer *in, OutputContainer *out) :
    _base(base), _blocks(in), _placedBlocks(out), _count(0)
{
    _available = _base;
#ifdef DEBUG
    printf("*Level constructed* \n");
#endif
}

LevelH::~LevelH()
{
#ifdef DEBUG
    printf("*Level destroyed* \n\n");
#endif
}

Rectangle LevelH::levelSpace() const
{
    return _base;
}

int LevelH::blockAmount() const
{
    return _count;
}

void LevelH::printAvailable() const
{
    printf("LevelSpace: TopLeft= (%d, %d), BotRight= (%d, %d)\n",
           _available.topLeft().x, _available.topLeft().y,
           _available.bottomRight().x, _available.bottomRight().y);
}

void LevelH::printBlocksAmount() const
{
    printf("Level contains %d blocks\n", _count);
}
