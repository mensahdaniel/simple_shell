#include "main.h"

/**
 * add_alias - Adds an alias to the alias list
 *
 * @head: Pointer to the start of the alias list
 * @name: Name of the alias
 * @value: Value of the alias
 */
void add_alias(alias_t **head, char *name, char *value)
{
	alias_t *new_alias = malloc(sizeof(alias_t));
	if (!new_alias)
	{
		/* Handle allocation failure */
		return;
	}

	new_alias->name = _strdup(name);
	new_alias->value = _strdup(value);
	new_alias->next = NULL;

	if (*head == NULL)
	{
		*head = new_alias;
		return;
	}

	alias_t *current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_alias;
}

/**
 * get_alias - Gets the value of an alias
 *
 * @head: Pointer to the start of the alias list
 * @name: Name of the alias
 */
char *get_alias(alias_t *head, char *name)
{
	alias_t *current = head;
	while (current != NULL)
	{
		if (_strcmp(current->name, name) == 0)
		{
			return current->value;
		}
		current = current->next;
	}
	return NULL;
}

/**
 * print_aliases - Prints the alias list
 *
 * @head: Pointer to the start of the alias list
 * Return: 1 always
 */
int print_all_alias(alias_t *head)
{
	char header[] = "Current aliases:\n";
	PRINT(header);

	alias_t *current = head;
	while (current != NULL)
	{
		print_alias(current->name, current->value);
		current = current->next;
	}
	return (1);
}

/**
 * free_aliases - Frees the alias list
 *
 * @head: Pointer to the start of the alias list
 */
void free_aliases(alias_t *head)
{
	while (head != NULL)
	{
		alias_t *temp = head;
		head = head->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}

/**
 * print_allias - prints an alias name and value
 *
 * @token: alias name
 * @value: alias value
 * Return: 1 always
 */
int print_alias(char *name, char *value)
{
	/*Length of the output string */
	char *output = malloc(_strlen(name) + _strlen(value) + 4);
	_strcpy(output, name);
	_strcat(output, "=");
	_strcat(output, value);
	_strcat(output, "\n");

	char *ptr = output;
	while (*ptr != '\0')
	{
		if (*ptr == '"')
		{
			*ptr = '\''; // Replace double quotes with single quotes
		}
		++ptr;
	}
	PRINT(output);

	return (1);
}
