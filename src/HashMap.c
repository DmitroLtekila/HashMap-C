#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_types.h"

#define INITIAL_CAPACITY 16

//ALL generics 
typedef void* (*CopyFunction)(void* value);
typedef void (*FreeFunction)(void* value);
typedef void (*PrintFunction)(void* value);

typedef struct Node {
    char* key;
    void* value;
    struct Node* next;
} Node;

typedef struct HashMap {
    int CAPACITY;
    Node** buckets;
    int numElements;

    CopyFunction copyValue;
    FreeFunction freeValue;
    PrintFunction printValue;
} HashMap;

HashMap* newHashMap(CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue);
int hashCode(const char* key);
void HashMap_resize(HashMap* HashMap);
void HashMap_print(HashMap* HashMap);
void HashMap_remove(HashMap* HashMap, char* key);
void* HashMap_get(HashMap *HashMap, char* key);
void HashMap_put(HashMap *HashMap, char* key, void* value);
void HashMap_free(HashMap* map);

int hashCode(const char* key)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

HashMap* newHashMap(CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue)
{
    HashMap* map = malloc(sizeof(HashMap));
    map->CAPACITY = INITIAL_CAPACITY;
    map->numElements = 0;
    map->buckets = calloc(map->CAPACITY, sizeof(Node*));
    map->copyValue = copyValue;
    map->freeValue = freeValue;
    map->printValue = printValue;
    return map;
}

void HashMap_resize(HashMap* HashMap)
{
    int old_CAPACITY = HashMap->CAPACITY;
    Node** old_buckets = HashMap->buckets;

    HashMap->CAPACITY *= 2;
    HashMap->buckets = calloc(HashMap->CAPACITY, sizeof(Node*));

    for (int i = 0; i < old_CAPACITY; i++)
    {
        Node* node = old_buckets[i];
        while(node != NULL)
        {
            Node* next = node->next;
            int index = hashCode(node->key) % HashMap->CAPACITY;
            node->next = HashMap->buckets[index];
            HashMap->buckets[index] = node;
            node = next;
        }
    }
    free(old_buckets);
}

void HashMap_print(HashMap* HashMap)
{
    for(int i = 0; i < HashMap->CAPACITY; i++)
    {
        Node* node = HashMap->buckets[i];
        while(node != NULL)
        {
            printf("key = \"%s\", value = ", node->key);
            HashMap->printValue(node->value);
            printf("\n");
            node = node->next;
        }
    }
}

void HashMap_remove(HashMap* HashMap, char* key)
{
    int index = hashCode(key) % HashMap->CAPACITY;
    Node* current = HashMap->buckets[index];
    Node* prev = NULL;
    while(current != NULL)
    {
        if(strcmp(current->key,key) == 0)
        {
            if(prev == NULL)
                HashMap->buckets[index] = current->next;
            else
                prev->next = current->next;

            HashMap->freeValue(current->value);
            free(current->key); 
            free(current);
            HashMap->numElements--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void HashMap_free(HashMap* map) {
    for (int i = 0; i < map->CAPACITY; i++) {
        Node* node = map->buckets[i];
        while (node) {
            Node* next = node->next;
            map->freeValue(node->value);
            free(node->key);
            free(node);
            node = next;
        }
    }
    free(map->buckets);
    free(map);
}

void* HashMap_get(HashMap *HashMap, char* key)
{
    int index = hashCode(key) % HashMap->CAPACITY;
    Node* node = HashMap->buckets[index];
    while(node != NULL)
    {
        if(strcmp(node->key,key) == 0)
        {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void HashMap_put(HashMap *HashMap, char* key, void* value)
{
    int index = hashCode(key) % HashMap->CAPACITY;
    Node* newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = HashMap->copyValue(value);
    newNode->next = NULL;

    if(HashMap->buckets[index] == NULL)
    {
        HashMap->buckets[index] = newNode;
        HashMap->numElements++;
        if(HashMap->numElements >= HashMap->CAPACITY * 0.75)
        {
            HashMap_resize(HashMap);
        }
        return;
    }

    Node* current = HashMap->buckets[index];
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    HashMap->numElements++;
}