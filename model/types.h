﻿#ifndef TYPES_H
#define TYPES_H

#include <array>
#include <functional>

class GPoint;
class GWindow;
class GObject;
class GViewport;
class OperationBuilder;
using Operation = std::function<GPoint (const GPoint)>;
using Vector = std::array<double, 3>;
using Matrix = std::array<std::array<double, 3>, 3>;

#endif // TYPES_H
