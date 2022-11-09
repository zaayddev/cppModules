#pragma once

template <typename T>
void swap(T& x, T& y)
{
   T tmp;
   tmp = x;
   x = y;
   y = tmp;
   return ;
}

template <typename T>
T const & max(T & x, T & y)
{
   if (x == y)
      return y;
	return (x >= y ? x : y);
}

template <typename T>
T const & min(T & x, T & y)
{
	return (x <= y? x : y);
}