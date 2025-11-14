HashMap Implementation in C
This project contains a custom implementation of a hash map in C using separate chaining for collision handling.
The goal of the project is to demonstrate understanding of low-level data structures, memory management, dynamic resizing and hashing.

Features:
1)Using linked list for collisions;
2)Dynamic resizing when load factor reaches 0.75;
3)Key with type string (char* ), but value can be any type (int, double, float, char, string);
4)You also can add to HashMap your own structure if you implement all needed functions;
5)To actually add your structure, creation of both "structure".c and "structure".h is needed,
Declare all required functions in your header file, and implement them in the source file.
After that you just include your "structure".h in main.c;
6)In this version only one HashMap, created in main, can be used;

Example of usage:
HashMap* map = newHashMap(copyInt, freeInt, printInt);
int x = 67;
HashMap_put(map, "number", &x);
HashMap_print(map);
HashMap_free(map);