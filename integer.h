//Tony Nguyen
//Date Created: 9/21/16
//CSE 2421 TTh 5:20pm-7:20pm
//0x05194c41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structs
struct immense_int_t{
	int x;
	struct immense_int_t* next_int;
};

//Prototypes
void create_list(struct immense_int_t* list);
void destroy_linked_list(struct immense_int_t* head);
struct immense_int_t* add(struct immense_int_t* a, struct immense_int_t* b);
struct immense_int_t* subtract(struct immense_int_t* a, struct immense_int_t* b);
struct immense_int_t* create_node(int x);
void add_node_front(struct immense_int_t** head, int x);
void print_answer(struct immense_int_t *ans);
