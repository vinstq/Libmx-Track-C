#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *temp = NULL;
    t_list *list2 = mx_create_node(data);

    if(list == NULL || *list == NULL) {
        *list = list2;
    }
    else{
        temp = *list;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = list2;
    }
}



