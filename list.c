#include <assert.h>
#include <stdlib.h>

#include "list.h"


// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	if(head->index >= new_element-> index){
		new_element->next = head;
		head = new_element;
	}
	else {
		struct list_t* cur;
		struct list_t* curprev;
		curprev = head;
		cur = head->next;
		while(cur!=NULL){
			if(cur->index >= new_element->index) break;
			curprev = cur;
			cur = cur->next;
		}
		curprev->next = new_element;
		new_element->next = cur;
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	struct list_t *newHead = NULL;
	struct list_t *cur;
	while(head!=NULL){
		cur = head;
		head = head->next;
		cur->next = newHead;
		newHead = cur;
	}
	head = newHead;
	return head;
}


