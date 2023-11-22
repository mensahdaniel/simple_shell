#include "main.h"

/* Helper function to handle alias commands */
int handle_alias_command(char *buffer, alias_t **aliases)
{
	char *alias_prefix = "alias";
	int alias_prefix_len = _strlen(alias_prefix);

	// Check if the buffer starts with "alias "
	if (_strncmp(buffer, alias_prefix, alias_prefix_len) == 0)
	{
		buffer += (alias_prefix_len + 1); // Move buffer past "alias "

		// Remove trailing newline character if present
		char *newline = strchr(buffer, '\n');
		if (newline != NULL)
		{
			*newline = '\0'; // Terminate the buffer string at the newline character
		}

		if (buffer[0] == '\0')
		{
			// If 'alias' command was entered without arguments, print all aliases
			print_aliases(*aliases);
			return 1; // Return 1 to indicate alias command handled
		}
		else
		{
			// Tokenize the input to handle multiple aliases at once
			char *token = _strtok(buffer, ' ');
			while (token != NULL)
			{
				// Check if the token contains an equal sign (=) to differentiate name=value pairs
				char *equal_sign = strchr(token, '=');
				if (equal_sign != NULL)
				{
					*equal_sign = '\0'; // Terminate the alias name at the equal sign

					char *alias_name = token;
					char *alias_value = (char *)(equal_sign + 1); // Points to the value after '='

					add_alias(aliases, alias_name, alias_value);
				}
				else
				{
					// If no equal sign, print the value of the alias
					char *alias_value = get_alias(*aliases, token);

					if (alias_value == NULL)
					{
						char msg[] = "alias: not found\n";
						write(STDOUT_FILENO, msg, _strlen(msg));
					}
					else
					{
						char output[256];
						snprintf(output, sizeof(output), "%s='%s'\n", token, alias_value);
						write(STDOUT_FILENO, output, _strlen(output));
					}
				}
				token = _strtok(NULL, ' ');
			}
			return 1; // Return 1 to indicate alias command handled
		}
	}
	return 0; // Return 0 for commands not related to alias
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
