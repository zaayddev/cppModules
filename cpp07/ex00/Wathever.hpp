#pragma once

#include <iostream>

template <typename T>
void swap(T& x, T& y)
{
   T t;
   t = x;
   x = y;
   y = t;
}

template <typename T>
T max(T x, T y)
{
   return (x >= y) ? x : y;
}

template <typename T>
T min(T x, T y)
{
   return (x <= y) ? x : y;
}