#include "shell.h"
/**
 * add_node - this function is specific to add a node to a start of a list
 * @head: An address of a pointer to a head node
 * @str: str field of the node
 * Return: size of the list
 */
int add_node(list_t **head, char *str)
{
list_t *new_head = malloc(sizeof(list_t));

if (new_head == NULL)
	return (-1);
new_head->str = strdup(str);
new_head->next = *head;
*head = new_head;
return (0);
}
/**
 * add_node_end - adds a node to the end of the list
 * @head: An address of a pointer to a head node
 * @str: str field of the node
 * Return: size of the list
 */
int add_node_end(list_t **head, char *str)
{
list_t *new_node = malloc(sizeof(list_t));
list_t *node = *head;

if (new_node == NULL)
	return (-1);
new_node->str = strdup(str);
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
return (0);
}
while (node->next != NULL)
node = node->next;
node->next = new_node;
return (0);
}
/**
 * print_list_string - prints only the str element of
 * a list_t linked list
 * @h: pointer to the first node
 * Return: size of the list
 */
size_t print_list_string(const list_t *h)
{
size_t x = 0;

while (h)
{
puts(h->str ? h->str : "(nil)");
puts("\n");
h = h->next;
x++;
}
return (x);
}
/**
 * free_list - this function is responsible for
 * freeing all nodes of a list
 * @head_ptr: An address of a pointer to a head node
 * Return: void
 */
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;

if (!head_ptr || !*head_ptr)
	return;
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}
