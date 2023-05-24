#include "ownshell.h"
#include <stdlib.h>

size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h) {
		h = h->next;
		count++;
	}

	return count;
}

char **list_to_strings(list_t *head)
{
	if (!head)
		return NULL;

	size_t list_length = list_len(head);
	char **strs = malloc(sizeof(char *) * (list_length + 1));
	if (!strs)
		return NULL;

	size_t i = 0;
	list_t *node = head;

	while (node) {
		strs[i] = _strdup(node->str);
		if (!strs[i]) {
			// Free previously allocated strings
			for (size_t j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return NULL;
		}

		node = node->next;
		i++;
	}

	strs[i] = NULL;
	return strs;
}

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h) {
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}

	return count;
}

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	while (node) {
		char *p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return node;
		node = node->next;
	}

	return NULL;
}

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head) {
		if (head == node)
			return index;
		head = head->next;
		index++;
	}

	return -1;
}













