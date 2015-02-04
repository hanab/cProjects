#ifndef READERS_H_INCLUDED
#define READERS_H_INCLUDED

#include "data.h"

int readString(char *str, int maxsize);
int readInt(int *value);
int readfloat(float *amount);
int readEntry( description*entry);

#endif
