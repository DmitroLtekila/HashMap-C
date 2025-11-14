#ifndef GENERIC_TYPES_H
#define GENERIC_TYPES_H

// INT
void* copyInt(void* value);
void freeInt(void* value);
void printInt(void* value);

// DOUBLE
void* copyDouble(void* value);
void freeDouble(void* value);
void printDouble(void* value);

// FLOAT
void* copyFloat(void* value);
void freeFloat(void* value);
void printFloat(void* value);

// CHAR
void* copyChar(void* value);
void freeChar(void* value);
void printChar(void* value);

// STRING
void* copyString(void* value);
void freeString(void* value);
void printString(void* value);

#endif
