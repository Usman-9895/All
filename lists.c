lists.c 
#include "ownshell.h"
#include <stdlib.h>

list_t *add_branch(list_t **head, const char *str, int num)
{
	if (!head)
		return NULL;

	list_t *new_branch = malloc(sizeof(list_t));
	if (!new_branch)
		return NULL;

	_memset((void *)new_branch, 0, sizeof(list_t));
	new_branch->num = num;

	if (str) {
		new_branch->str = _strdup(str);
		if (!new_branch->str) {
			free(new_branch);
			return NULL;
		}
	}

	new_branch->next = *head;
	*head = new_branch;
	return new_branch;
}

list_t *add_branch_end(list_t **head, const char *str, int num)
{
	if (!head)
		return NULL;

	list_t *new_branch = malloc(sizeof(list_t));
	if (!new_branch)
		return NULL;

	_memset((void *)new_branch, 0, sizeof(list_t));
	new_branch->num = num;

	if (str) {
		new_branch->str = _strdup(str);
		if (!new_branch->str) {
			free(new_branch);
			return NULL;
		}
	}

	if (*head) {
		list_t *branch = *head;
		while (branch->next)
			branch = branch->next;
		branch->next = new_branch;
	} else {
		*head = new_branch;
	}

	return new_branch;
}

size_t print_list_str(const list_t *h)
{
	size_t number = 0;

	while (h) {
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		number++;
	}

	return number;
}

int delete_branch_at_index(list_t **head, unsigned int index)
{
	if (!head || !*head)
		return 0;

	if (index == 0) {
		list_t *branch = *head;
		*head = (*head)->next;
		free(branch->str);
		free(branch);
		return 1;
	}

	list_t *prev_branch = NULL;
	list_t *branch = *head;
	unsigned int i = 0;

	while (branch) {
		if (i == index) {
			prev_branch->next = branch->next;
			free(branch->str);
			free(branch);
			return 1;
		}

		i++;
		prev_branch = branch;
		branch = branch->next;
	}

	return 0;
}

void free_list(list_t **head_ptr)
{
	if (!head_ptr || !*head_ptr)
		return;

	list_t *branch = *head_ptr;

	while (branch) {
		list_t *next_branch = branch->next;
		free(branch->str);
		free(branch);
		branch = next_branch;
	}

	*head_ptr = NULL;
}


