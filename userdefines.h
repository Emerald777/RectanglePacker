#ifndef USERDEFINES_H
#define USERDEFINES_H

#include <map>
#include <set>
#include <list>
#include <functional>
#include <type_traits>

#include "rectangle.h"

using InputContainer = std::list<Rectangle>;
using OutputContainer = std::multimap<int, Rectangle>; /// key is the number of basket

// #define DEBUG
#define RAW_OUT_DATA

#endif // USERDEFINES_H
