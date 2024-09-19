#include "libmx.h"

void mx_pop_front(t_list **head) {
    if(head == NULL || NULL == *head) {
        return;
    }

    t_list *temp = (*head)->next;

    free(*head);
    *head = temp;

}


