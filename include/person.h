#ifndef PERSON_H
#define PERSON_H

typedef struct Person {
    char* name;
    int age;
} Person;

void* copyPerson(void* value);
void freePerson(void* value);
void printPerson(void* value);

#endif