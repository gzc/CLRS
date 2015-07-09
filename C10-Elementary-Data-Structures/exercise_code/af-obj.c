#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef int list_t;
typedef int obj_t;

int empty_list = -1;
int cells[MAX_SIZE * 3];
int free_list;

#define NEXT(i) cells[(i) + 1]
#define PREV(i) cells[(i) + 2]
#define KEY(i)  cells[i]

void init_storage() {
    int i;
    for (i = 0; i < (MAX_SIZE - 1) * 3; i += 3)
        NEXT(i) = i + 3;
    
    NEXT(i) = -1;
    free_list = 0;
}

list_t allocate_object() {
    if (free_list == -1) {
        fprintf(stderr, "Storage depleted\n");
        exit(1);
    }
    
    list_t new = free_list;
    free_list = NEXT(free_list);
    return new;
}

void free_object(list_t list) {
    NEXT(list) = free_list;
    free_list = list;
}

list_t cons(obj_t key, list_t list) {
    list_t new = allocate_object();
    
    NEXT(new) = list;
    PREV(new) = empty_list;
    KEY(new) = key;
    
    if (list != empty_list) {
        PREV(list) = new;
    }
    
    return new;
}

void delete(list_t list) {
    if (PREV(list) != empty_list) {
        NEXT(PREV(list)) = NEXT(list);
    }
    
    if (NEXT(list) != empty_list) {
        PREV(NEXT(list)) = PREV(list);
    }
    
    free_object(list);
}

obj_t get(list) {
    if (list == empty_list) return -1;
    return KEY(list);
}

list_t next(list) {
    if (list == empty_list) return -1;
    return NEXT(list);
}

int main()
{
    init_storage();
    list_t new_list = cons(5, empty_list);
    new_list = cons(4, new_list);
    printf("%d\n", get(new_list));
    printf("%d\n", get(next(new_list)));
    delete(new_list);
    
    return 0;
}
