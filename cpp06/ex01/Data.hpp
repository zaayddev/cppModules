#pragma once

#include <iostream>
#include <string>

typedef struct s_data
{
	int			n;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
