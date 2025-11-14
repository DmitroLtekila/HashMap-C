#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generic_types.h"

// ----INT----
void* copyInt(void* value) {
    int* p = malloc(sizeof(int));
    *p = *(int*)value;
    return p;
}
void freeInt(void* value) {
    free(value);
}
void printInt(void* value) {
    printf("%d", *(int*)value);
}
// ----DOUBLE----
void* copyDouble(void* value) {
    double* p = malloc(sizeof(double));
    *p = *(double*)value;
    return p;
}
void freeDouble(void* value) {
    free(value);
}
void printDouble(void* value) {
    printf("%lf", *(double*)value);
}
// ----FLOAT----
void* copyFloat(void* value) {
    float* p = malloc(sizeof(float));   
    *p = *(float*)value;
    return p;
}
void freeFloat(void* value) {
    free(value);
}
void printFloat(void* value) {
    printf("%f", *(float*)value);
}
// ----CHAR----
void* copyChar(void* value) {
    char* p = malloc(sizeof(char));
    *p = *(char*)value;
    return p;
}
void freeChar(void* value) {
    free(value);
}
void printChar(void* value) {
    printf("%c", *(char*)value);
}
// ----STRING----
void* copyString(void* value) {
    return strdup((char*)value);
}
void freeString(void* value) {
    free(value);
}
void printString(void* value) {
    printf("%s", (char*)value);
}