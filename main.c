#include "generic_types.h"
#include "hashmap.h" 
#include "person.h"

int main(void)
{   
    //Example of adding a Structure Person into the Hashmap
    HashMap* map = newHashMap(copyPerson, freePerson, printPerson);
    Person p;
    p.age = 20;
    p.name = "Demos";
    HashMap_put(map, "1", &p);
    HashMap_print(map);

    HashMap_free(map);
    return 0;

}