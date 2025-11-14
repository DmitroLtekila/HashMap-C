#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

void* copyPerson(void* value) {
    Person* original = (Person*)value;
    Person* p = malloc(sizeof(Person));
    p->age = original->age;
    p->name = strdup(original->name); //we use strdup to not mess up with memory allocation for name
    return p;
}

void freePerson(void* value) {
    Person* p = (Person*)value;
    free(p->name);
    free(p);
}

void printPerson(void* value) {
    Person* p = (Person*)value;
    printf("{ name = \"%s\", age = %d }", p->name, p->age);
}