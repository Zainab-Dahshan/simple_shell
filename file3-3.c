#include "shell.h"
/**
 * delete_node_at_index - a function that deletes a node at
 * a specified index from a linked list.
 * @head: A pointer to a pointer to a head of a linked list.
 * @index: An index of a node to be deleted.
 * Return: 0 on if it is successful, -1 if a linked list is empty
 * or an index is out of range.
 */
int delete_node_at_index(list_t **head, int index)
{
int z;
list_t *current = *head;
list_t *next_node;

if (*head == NULL)
	return (-1);
if (index == 0)
{
list_t *temp = *head;
*head = (*head)->next;
free(temp);
return (0);
}
for (z = 0; z < index - 1; z++)
{
if (current->next == NULL)
	return (-1);
current = current->next;
}
next_node = current->next;
current->next = next_node->next;
free(next_node);
return (0);
}
/**
 * get_node_index - a function gets an index of a node
 * in a linked list.
 * @head: A pointer to a head of a linked list.
 * @node: A pointer to a node whose index needs to be found.
 * Return: An index of a node if found, -1 otherwise.
 */
int get_node_index(list_t *head, list_t *node)
{
int index = 0;
list_t *current = head;

while (current != NULL)
{
if (current == node)
	return (index);
current = current->next;
index++;
}
return (-1);
}
