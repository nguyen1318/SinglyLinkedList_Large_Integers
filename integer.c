//Tony Nguyen
//Date Created: 9/21/16
//CSE 2421 TTh 5:20pm-7:20pm
//0x05194c41

#include "integer.h"

/*
   Creates 2 linked lists that are used to find the sum or
   the difference of.
*/
int main(void){

	struct immense_int_t* ans = NULL;
	struct immense_int_t *first = NULL;
	struct immense_int_t *second = NULL;

	//char c: first number input
	//char d: second number input
	//char e: operation input (add/subtract)
	char c, d, e;
	
	//Create list for first number.
	while(c != '\n'){
		c = getc(stdin);
		if(c != '\n'){
			add_node_front(&first, (c - '0'));
		}
	}

	//Create list for second number.
	while(d != '\n'){
		d = getc(stdin);
		if(d != '\n'){
			add_node_front(&second, (d - '0'));
		}
	}

	//Call for operation type
	scanf("%c", &e);
	if(e == '+'){
		ans = add(first, second);
	} else if(e == '-'){
		ans = subtract(first, second);
	}

	destroy_linked_list(first);
	destroy_linked_list(second);
	print_answer(ans);
	destroy_linked_list(ans);

	return 0;
}

/*
   Creates a singly-linked list in reverse order

   struct immense_int_t* list: number that is being
   				created into singly-linked list.
*/
void create_list(struct immense_int_t* list){
	char c;
	while(c != '\n'){
		c = getc(stdin);
		if(c != '\n'){
			add_node_front(&list, (c - '0'));
		}
	}
}

/*
   Destroys a singly-linked list. Frees up memory.

   struct immense_int_t* head: the list to be destroyed.
*/
void destroy_linked_list(struct immense_int_t* head){
	struct immense_int_t* temp;
	while(head!=NULL){
		temp = head;
		head = head->next_int;
		free(head);
	}
}

/*
   Function that adds two singly-linked lists.

   struct immense_int_t* a: the first number to be added.
   struct immense_int_t* b: the second number to be added.
   return ans: the sum of a + b as a singly-linked list.
*/
struct immense_int_t* add(struct immense_int_t* a, struct immense_int_t* b){

	struct immense_int_t* ans = NULL;
	int sum;
	while(a != NULL && b != NULL){
		sum = a->x + b->x;

		//Carrys the number to the next 10s place.
		if(sum >= 10){
			if(a->next_int != NULL){
				a->next_int->x++;
			} else {
				add_node_front(&a->next_int, 1);
			}
		}

		sum = sum%10;
		add_node_front(&ans, sum);

		a = a->next_int;
		b = b->next_int;
	}

	//Once done adding, if a or b was significantly longer than the other,
	//add the remaining digits left over that do not have to be changed.
	if(a != NULL){
		while(a != NULL){
			add_node_front(&ans, a->x);
			a = a->next_int;
		}
	} else {
		while(b != NULL){
			add_node_front(&ans, b->x);
			b = b->next_int;
		}
	}

	return ans;
}

/*
   Function that subtracts two singly-linked lists.

   struct immense_int_t* a: the number to be subtracted from.
   struct immense_int_t* b: the number used to subtract.
   return ans: the difference of a - b as a singly-linked list.
*/
struct immense_int_t* subtract(struct immense_int_t* a, struct immense_int_t* b){

	struct immense_int_t* ans = NULL;
	int diff;
	int same_number = 1;
	while(a != NULL && b != NULL){
		if(a->x != b->x){
			same_number = 0;
		}
		diff = a->x - b->x;

		//Borrows a 10 from the next place and adds it to current position. 
		if(diff < 0){
			if(a->next_int != NULL){
				a->next_int->x--;
			}
			diff = diff + 10;
		}
		add_node_front(&ans, diff);

		a = a->next_int;
		b = b->next_int;
	}

	if(a != NULL){
		while(a != NULL){
			if(a->x < 0){
				a->x = a->x + 10;
			}
			add_node_front(&ans, a->x);
			a = a->next_int;
		}
	}

	//If both numbers are the same, then result is a singly-linked list with
	//just a 0.
	if(same_number){
		destroy_linked_list(ans);
		ans = NULL;
		add_node_front(&ans, 0);
	}

	return ans;
}

/*
   Function that creates a new node for a singly-linked list.

   int x: the data that is being stored in the node being created.
   return node: the node with stored data.
*/
struct immense_int_t* create_node(int x){
	struct immense_int_t* node = malloc(sizeof(struct immense_int_t));
	if(node != NULL){
		node->x = x;
		node->next_int = NULL;
	}
	return node;
}

/*
   Function that adds a node to the front of a singly-linked list.

   struct immense_int_t **head: the singly-linked list that is being extended.
   int x: the data that is being added to the list.
*/
void add_node_front(struct immense_int_t **head, int x){
	struct immense_int_t* new_node = create_node(x);
	new_node->next_int = *head;
	*head = new_node;
}

/*
   Function that prints the singly_linked list

   struct immense_int_t *head: the list to be printed to the console.
*/
void print_answer(struct immense_int_t *head)
{
	struct immense_int_t* node=head;
	int first_not_zero = 0;
	
	while (node!=NULL) {

		//Protects program from printing unnecessary beginning '0'
		//Ex. 000000001 == 1
		if(node->x != 0){
			first_not_zero = 1;
		}
		if(first_not_zero){
			printf("%d", node->x);
		}

		node=node->next_int;
	}
	printf("\n");
}
