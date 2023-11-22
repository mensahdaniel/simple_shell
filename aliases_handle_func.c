#include "main.h"

/**
 * handle_alias_command - check if user input is an alias command and run
 *
 * @buffer: user input
 * @aliases: array of aliases
 * Return: 1 on success or 0 on failure (if command is not the alias command)
 */
int handle_alias_command(char *buffer, alias_t **aliases)
{
	char *alias_prefix = "alias";
	int alias_prefix_len = _strlen(alias_prefix);

	/* Check if the buffer starts with "alias"*/
	if (_strncmp(buffer, alias_prefix, alias_prefix_len) == 0)
	{
		buffer += (alias_prefix_len + 1); /* Move buffer past "alias "*/
		/* Remove trailing newline character if present*/
		char *newline = _strchr(buffer, '\n');

		if (newline != NULL)
			*newline = '\0'; /* Terminate the buffer string at the newline character */

		if (buffer[0] == '\0')
			/*If 'alias' command was entered without arguments, print all aliases*/
			return (print_all_alias(*aliases));
		else
		{
			/* Return 1 to indicate alias command handled*/
			add_get_alias(buffer, aliases);
		}
	}
	return 0; /* Return 0 for commands not related to alias */
}

/**
 * add_get_alias - add or get alias
 *
 * @buffer: alias command
 * @aliases: array of aliases (list)
 * Return: 1 on run
 */
int add_get_alias(char *buffer, alias_t **aliases)
{

	/* Tokenize the input to handle multiple aliases at once */
	char *token = _strtok(buffer, ' ');

	while (token != NULL)
	{
		/* Check if the token contains an equal sign (=) to differentiate name=value pairs */
		char *equal_sign = _strchr(token, '=');
		if (equal_sign != NULL)
		{
			*equal_sign = '\0'; /* Terminate the alias name at the equal sign */

			char *alias_name = token;
			char *alias_value = (char *)(equal_sign + 1); /* Points to the value after '=' */

			add_alias(aliases, alias_name, alias_value);
		}
		else
		{
			/*If no equal sign, print the value of the alias */
			char *alias_value = get_alias(*aliases, token);

			if (alias_value == NULL)
			{
				char msg[] = "alias: ", token_msg[] = " not found\n";
				PRINT(_strcat(msg, token));
				PRINT(token_msg);
			}
			else
				print_alias(token, alias_value);
		}
		token = _strtok(NULL, ' ');
	}
	return (1);
}
