#include "dolphin_tests.h"

/*
 This bonus part is all about lists!
 */

char *test1 = "hello world!";
char *test2 = "Another hello world!";
char *test3 = "A third hello world!";

// Convenience functions to free the lists used in the tests
void freeList(t_list *head) {
	if (head) 
		freeList(head->next); 
	free(head);
}

// util function to be passed to ft_lstmap
void addOne(void * p)
{
	++*(int*)p;
}

// util function to be passed to ft_lstmap
void * addOneMalloc(void * p) {
	void *r = malloc(sizeof(int));
	*(int*)r = *(int*)p + 1;
	return (r);
}

// util function to be passed to ft_lstmap
void	del(void *content)
{	
	(void)content;
}

// A pointer to this function will be passed to the lstmap
void f2(void *content)
{
	debug("=== content of node => %s\n", (char*)content);
	
}

// A pointer to this function be passed to the lstmap
// (It does not use malloc)
void *f3(void *content)
{
	debug("=== content of node => %s\n", (char*)content);
	return (content);
}

/*
 Signature of the function to test:
 t_list * ft_lstnew(void const *content, size_t content_size);
 
 Allocates (with malloc(3)) and returns a new node.
 The member variable ’content’ is initialized with
 the value of the parameter ’content’.  The variable
 ’next’ is initialized to NULL.
 */
char *test_ft_lstnew()
{
	t_list *l = ft_lstnew(test1);
	my_assert(l != NULL, "failed to create node");
	debug("==== %s \n",(char*)l->content);
	my_assert(ft_strncmp(test1, (char*)l->content, 10) == 0, "failed to get content");
	
	l->content = test2;
	debug("==== %s \n",(char*)l->content);
	my_assert(ft_strncmp(test2, (char*)l->content, 10) == 0, "failed to get content");
	l->content = test3;
	debug("==== %s \n",(char*)l->content);
	my_assert(ft_strncmp(test3, (char*)l->content, 10) == 0, "failed to get content");
	
	freeList(l); 

	return NULL;
}

/*
 Signature of the function to test:
 
 Parameters
 lst:  The address of a pointer to the first link of
 a list.
 new:  The address of a pointer to the node to be
 added to the list.
 Adds the node ’new’ at the beginning of the list.
 node->next = list->first;
 list->first->prev = node;
 list->first = node;
 */
char *test_ft_lstadd_front()
{
	t_list *l = ft_lstnew(test1);
	t_list *new = ft_lstnew(test2);
	my_assert(new != NULL, "failed to create node");

	ft_lstadd_front(&l, new);
	debug("==== %s first node value is now same as new \n",(char*)l->content);
	my_assert(ft_strncmp(test2, (char*)l->content, 10) == 0, "failed to get content");
	debug("==== next node val is old first node value %s \n",(char*)l->next->content);
	my_assert(ft_strncmp(test1, (char*)l->next->content, 10) == 0, "failed to get content");
	freeList(l); 

	l =  NULL;
	ft_lstadd_front(&l, ft_lstnew((void*)42));
	my_assert(l->content == (void*)42, "shd be 0");
	my_assert(l->next == 0, "shd be 0");

	ft_lstadd_front(&l, ft_lstnew((void*)99));
	my_assert(l->content == (void*)99, "shd be 99");
	my_assert(l->next->content == (void*)42, "shd be 42");
	my_assert(l->next->next == 0, "shd be 0");
	freeList(l); 

	return NULL;
}

/*
 Signature of the function to test:
 
 Counts the number of nodes in a list.
 Parameters
 lst:  The beginning of the list.
 Returns:
 The length of the list
 */
char *test_ft_lstsize()
{
	t_list *l = ft_lstnew(test1);
	ft_lstadd_front(&l, ft_lstnew("fish"));
	int count = ft_lstsize(l);
	debug("==== counting the list now %d =====  \n", count);
	my_assert(count == 2, "starting point of test is wrong");

	t_list *new = ft_lstnew(test3);
	my_assert(new != NULL, "failed to create node");
	debug("==== new node value %s \n",(char*)new->content);
	my_assert(ft_strncmp(test3, (char*)new->content, 10) == 0, "failed to get content");
	
	ft_lstadd_front(&l, new);
	debug("==== first node value is now same as test3 ==> %s \n",(char*)l->content);
	my_assert(ft_strncmp(test3, (char*)l->content, 10) == 0, "failed to get content");
	count = ft_lstsize(l);
	debug("==== counting the list %d =====  \n", count);
	debug("==== content first %s =====  \n", (char*)l->content);
	debug("==== content second %s =====  \n", (char*)l->next->content );
	debug("==== content third %s =====  \n", (char*)l->next->next->content);
	freeList(l); 

	return NULL;
}

/*
 Signature of the function to test:
 
 Parameters
 lst:  The beginning of the list.
 Returns 
 the last node of the list.
 */
char *test_ft_lstlast()
{
	t_list *l = ft_lstnew(test1);
	int count = ft_lstsize(l);
	debug("==== counting the list now %d =====  \n", count);
	my_assert(count == 1, "starting point of test is wrong");
	
	t_list *last = ft_lstlast(l);
	my_assert(last != NULL, "failed to get last");
	debug("==== content last %s =====  \n", (char*)last->content);
	my_assert(ft_strncmp(test1, (char*)last->content, 10) == 0, "failed to last list content");
	freeList(l); 

	return NULL;
}

/*
 Signature of the function to test:
 
 adds the node ’new’ at the end of the list.
 Parameters
 new:  The address of a pointer to the node to be
 added to the list.
 Returns:
 lst:  The address of a pointer to the first link of
 a list.
 */
char *test_ft_lstadd_back()
{
	t_list *l = ft_lstnew(test1);
	int count = ft_lstsize(l);
	debug("==== counting the list now %d =====  \n", count);
	t_list *backnode = ft_lstnew("to add on the back!");
	my_assert(l != NULL, "failed to create node");
	ft_lstadd_back(&l,backnode);
	
	t_list *last = ft_lstlast(l);
	my_assert(last != NULL, "failed to get last");
	debug("==== content last %s =====  \n", (char*)last->content);
	my_assert(ft_strncmp("to add on the back!", (char*)last->content, 10) == 0, "failed to last list content");
 	freeList(l); 
	
	l =  NULL; 
	ft_lstadd_back(&l, ft_lstnew((void*)42));
	my_assert(l->content == (void*)42, "should be 42" );
	my_assert(l->next == 0, "should be zero");

	ft_lstadd_back(&l, ft_lstnew((void*)99));
	my_assert(l->content == (void*)42, "should be 42");
	my_assert(l->next->content == (void*)99, "should be 99");
	my_assert(l->next->next == 0, "should be zero");
	t_list * l2 =  NULL;
	ft_lstadd_back(&l2, ft_lstnew((void*)3));
	ft_lstadd_back(&l2, ft_lstnew((void*)4));
	ft_lstadd_back(&l, l2);
	my_assert(l->content == (void*)42, "should be 42");
	my_assert(l->next->content == (void*)99, "should be 42");
	my_assert(l->next->next->content == (void*)3, "should be 3");
	my_assert(l->next->next->next->content == (void*)4, "should be 4");
	my_assert(l->next->next->next->next == 0, "should be 0");
	freeList(l);

	return NULL;
}

/*
 Signature of the function to test:
 
 Takes as a parameter a node and frees the memory of
 the node’s content using the function ’del’ given
 as a parameter and free the node.  The memory of
 ’next’ must not be freed.
 
 Parameters
 lst:  The node to free.
 del:  The address of the function used to delete
 the content.
 */
char *test_ft_lstdelone()
{
	t_list *new = ft_lstnew(test1);
	my_assert(new != NULL, "failed to get node");
	debug("==== content last %s =====  \n", (char*)new->content);
	ft_lstdelone(new,del);
	debug("==== freed  node =====  \n");

	t_list *l = ft_lstnew(malloc(1));
	ft_lstdelone(l, free); 
	debug("==== freed node and content =====  \n");

	return NULL;
}

/*
 Signature of the function to test:
 
 Deletes and frees the given node and every
 successor of that node, using the function ’del’
 and free(3).
 Finally, the pointer to the list must be set to
 NULL.
 
 Parameters:
 lst:  The address of a pointer to a node.
 del:  The address of the function used to delete
 the content of the node.
 */
char *test_ft_lstclear()
{
	t_list *l = NULL;
	
	l = ft_lstnew(test1);
	t_list *new = ft_lstnew(test2);
	ft_lstadd_front(&l, new);
	
	new = ft_lstnew(test3);
	ft_lstadd_front(&l, new);
	
	debug("==== %s \n",(char*)l->content);
	int count = ft_lstsize(l);
	debug("==== counting the list now %d =====  \n", count);
	ft_lstclear(&l, del);
	count = ft_lstsize(l);
	debug("==== counting the empty list now %d =====  \n", count);
	my_assert(count == 0, "list not empty");
	my_assert(l == NULL, "list pointer not freed");

	l =  ft_lstnew(malloc(1));
	for (int i = 0; i < 10; ++i)
		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
	ft_lstclear(&l, free);
	my_assert(l == 0, "shd be 0");

	return NULL;
}


/*
 Signature of the function to test:
 
 Iterates the list ’lst’ and applies the function
 ’f’ on the content of each node.
 
 Parameters:
 lst:  The address of a pointer to a node.
 f:  The address of the function used to iterate on
 the list.
 */
char *test_ft_lstiter()
{
	t_list *l = NULL;
	
	l = ft_lstnew(test1);
	t_list *new = ft_lstnew(test2);
	ft_lstadd_front(&l, new);
	
	new = ft_lstnew(test3);
	ft_lstadd_front(&l, new);
	
	int count = ft_lstsize(l);
	debug("==== counting the list now %d =====  \n", count);
	my_assert(count == 3, "starting point of test is wrong");

	ft_lstiter(l, f2);
	ft_lstclear(&l, del);

	int arr[] = {0, 1, 2, 3};
	l =  ft_lstnew(arr);
	ft_lstadd_back(&l, ft_lstnew(arr + 1));
	ft_lstadd_back(&l, ft_lstnew(arr + 2));
	ft_lstadd_back(&l, ft_lstnew(arr + 3));

	ft_lstiter(l, addOne);
	t_list *tmp = l;
	debug("==== content pos 0 is  %d =====  \n", *(int*)tmp->content);
	my_assert(*(int*)tmp->content == 1, "shd be 1");
	tmp = tmp->next;
	debug("==== content pos 0 is  %d =====  \n", *(int*)tmp->content);
	my_assert(*(int*)tmp->content == 2, "shd be 2");
	tmp = tmp->next;
	my_assert(*(int*)tmp->content == 3, "shd be 3");
	tmp = tmp->next;
	my_assert(*(int*)tmp->content == 4, "shd be 4");

	freeList(l);

	return NULL;
}

/*
 Signature of the function to test:
 
 Iterates the list ’lst’ and applies the function
 ’f’ on the content of each node. Creates a new
 list resulting of the successive applications of
 the function ’f’. The ’del’ function is used to
 delete the content of a node if needed.
 
 Parameters:
 lst: The address of a pointer to a node.
 f: The address of the function used to iterate on
 the list.
 del: The address of the function used to delete
 the content of a node if needed
 The new list.
 NULL if the allocation fails
 */
char *test_ft_lstmap()
{
	t_list *l = NULL;
	t_list *returnedlist = NULL;
	t_list *returned_pointer_to_list =  NULL;

	l = ft_lstnew(test1);
	t_list *new = ft_lstnew(test2);
	ft_lstadd_front(&l, new);
	new = ft_lstnew(test3);
	ft_lstadd_front(&l, new);
	
	int count = ft_lstsize(l);
	debug("==== counting the list now %d =====  \n", count);
	my_assert(count == 3, "starting point of test is wrong");

	returned_pointer_to_list = returnedlist = ft_lstmap(l, f3, del);
	debug("==== returnedlist content pos 0 is  %s =====  \n", (char*)returnedlist->content);
	my_assert(ft_strncmp(test3, (char*)new->content, 10) == 0, "failed to get content");
	my_assert(ft_strncmp(test3, (char*)returnedlist->content, 10) == 0, "failed to get content");
	new = new->next;
	returnedlist = returnedlist->next;
	debug("==== returnedlist content pos 1 is  %s =====  \n", (char*)returnedlist->content);
	my_assert(ft_strncmp(test2, (char*)new->content, 10) == 0, "failed to get content");
	my_assert(ft_strncmp(test2, (char*)returnedlist->content, 10) == 0, "failed to get content");
	new = new->next;
	returnedlist = returnedlist->next;
	debug("==== returnedlist content pos 2 is  %s =====  \n", (char*)returnedlist->content);
	my_assert(ft_strncmp(test1, (char*)new->content, 10) == 0, "failed to get content");
	my_assert(ft_strncmp(test1, (char*)returnedlist->content, 10) == 0, "failed to get content");

	ft_lstclear(&l, del);
	ft_lstclear(&returned_pointer_to_list, del);

	int arr[] = {0, 1, 2, 3};
	l =  ft_lstnew(arr);
	ft_lstadd_back(&l, ft_lstnew(arr + 1));
	ft_lstadd_back(&l, ft_lstnew(arr + 2));
	ft_lstadd_back(&l, ft_lstnew(arr + 3));

	// since the value of new will change I need to keep the original value 
	// of the beginning of the list otherwise I cannot free it
	returned_pointer_to_list = new = ft_lstmap(l, addOneMalloc, free );
	debug("==== content pos 0 is  %d =====  \n", *(int*)new->content);
	my_assert(*(int*)new->content == 1, "shd be 1");
	new = new->next;
	debug("==== content pos 1 is  %d =====  \n", *(int*)new->content);
	my_assert(*(int*)new->content == 2, "shd be 2");
	new = new->next;
	debug("==== content pos 2 is  %d =====  \n", *(int*)new->content);
	my_assert(*(int*)new->content == 3, "shd be 3");
	new = new->next;
	debug("==== content pos 3 is  %d =====  \n", *(int*)new->content);
	my_assert(*(int*)new->content == 4, "shd be 4");

	ft_lstclear(&l, del);
	ft_lstclear(&returned_pointer_to_list, free);

	return NULL;
}

// Feel free to deselect here some of the tests if
// you want to focus on some funtctions to test
char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_ft_lstnew);
	mu_run_test(test_ft_lstadd_front);
	mu_run_test(test_ft_lstsize);
	mu_run_test(test_ft_lstlast);
	mu_run_test(test_ft_lstadd_back);
	mu_run_test(test_ft_lstdelone);
	mu_run_test(test_ft_lstclear);
	mu_run_test(test_ft_lstiter);
	mu_run_test(test_ft_lstmap);	
	
	return NULL;
}

// Macro defined in dolphin_tests header
// works like a main for this file
RUN_TESTS(all_tests);

