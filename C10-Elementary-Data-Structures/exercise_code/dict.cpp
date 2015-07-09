/*************************************************************************
	> File Name: dict.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Tue Jul  7 21:43:43 2015
 ************************************************************************/
#include<iostream>
using namespace std;


struct node_t {
    int key;
    struct node_t *next;
};

struct list_t{
    struct node_t nil;
};

void init_list(list_t *list) {
    list->nil.key = 0;
    list->nil.next = &(list->nil);
}

void destroy_list(list_t *list) {
    node_t *node = list->nil.next;
    node_t *next;
    
    while (node != &(list->nil)) {
        next = node->next;
        free(node);
        node = next;
    }
}

void insert(list_t *list, int key) {
    node_t *newnode = (node_t *) malloc(sizeof(node_t));
    newnode->key = key;
    newnode->next = list->nil.next;
    list->nil.next = newnode;
}

node_t *search(list_t *list, int key) {
    node_t *node = list->nil.next;
    list->nil.key = key;
    
    while (node->key != key) {
        node = node->next;
    }
    
    if (node == &(list->nil)) {
        return NULL;
    } else {
        return node;
    }
}

void del(list_t *list, int key) {
    node_t *node = &(list->nil);
    
    while (node->next != &(list->nil)) {
        if (node->next->key == key) {
            node_t *to_be_deleted = node->next;
            node->next = node->next->next;
            free(to_be_deleted);
        } else {
            node = node->next;
        }
    }
}

int main()
{
    list_t *mydict = new list_t;
    init_list(mydict);
    insert(mydict, 2);
    insert(mydict, 3);
    insert(mydict, 4);
    node_t *tmp = search(mydict, 3);
    cout << tmp->key;
    
    return 0;
}
