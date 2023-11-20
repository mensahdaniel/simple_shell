#include "main.h"

/* Helper function to handle alias commands */
int handle_alias_command(char *buffer, alias_t **aliases)
{
	char *alias_prefix = "alias ";
	int alias_prefix_len = _strlen(alias_prefix);

	if (strncmp(buffer, alias_prefix, alias_prefix_len) == 0)
	{
		/* Check if the buffer starts with "alias "*/
		buffer += alias_prefix_len; /* Move buffer past "alias "*/

		char *equal_sign = strchr(buffer, '=');
		if (equal_sign != NULL)
		{
			/* Parsing the alias name and value */
			*equal_sign = '\0'; /* Terminate the name string at the '=' character */
			char *alias_name = buffer;
			char *alias_value = equal_sign + 1; /* Points to the start of the value*/

			/* Remove trailing newline character if present*/
			char *newline = strchr(alias_value, '\n');
			if (newline != NULL)
			{
				*newline = '\0'; /* Terminate the value string at the newline character */
			}

			add_alias(aliases, alias_name, alias_value);
			return (1); /* Return 1 to indicate alias command handled */
		}
	}
	else if (strcmp(buffer, "alias\n") == 0)
	{
		/* Print aliases command */
		print_aliases(*aliases);
		return (1); /* Return 1 to indicate alias command handled */
	}
	return (0); /* Return 0 for commands not related to alias */
}

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
		// Handle allocation failure
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
 */
void print_aliases(alias_t *head)
{
	printf("Current aliases:\n");
	alias_t *current = head;
	while (current != NULL)
	{
		printf("%s='%s'\n", current->name, current->value);
		current = current->next;
	}
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
