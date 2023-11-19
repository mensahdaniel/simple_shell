#include "main.h"

/**
 * free_buff_and_env - Frees the buffer and an environ variable
 * @str: Buffer to free
 */
void free_buff_and_env(char *str)
{
	free(str);
}
/**
 * waitAndFree - Waits and frees things
 * @status: Status of the process
 * @argv: Array to free
 * @dup: Duplicated array to free
 *
 * Return: Returns the status of isatty
 */
void waitAndFree(int status, char **argv, char *dup)
{
	wait(&status);
	free_array_dup(argv, dup);
}
/**
 * free_and_exit - Frees a buffer and exits the function
 * @buffer: Buffer to free
 */
void free_and_exit(char *buffer)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}
/**
 * free_array_dup - Frees an array and the duplicated string
 * @array: Array to free
 * @dup: Duplicated string to free
 */
void free_array_dup(char **array, char *dup)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
	free(dup);
}
/**
 * free_environ - frees all the environ[i] used in the function _setenv
 * @var_name: the name of the variable
 *
 * Return: asd
 */
void free_environ(char *var_name)
{
	size_t len = 0;
	int i = 0;

	len = strlen(var_name);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], var_name, len) == 0)
		{
			free(environ[i]);
		}
		i++;
	}
}

/**
 * _realloc -  Reallocates A Memory Block Using Malloc And Free
 *@ptr: Pointer
 *@old_size: Previous Size Of The Pointer
 *@new_size: New Size Of The Pointer
 *Return: Void Pointer Rellocated Memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * _memcpy - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Much You Will Copy)
 *Return: Void Pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * fill_an_array - Fill An Array By Constant Byte
 * @a:Void Pointer
 * @el: Int
 * @len:Length Int
 *Return: Void Pointer
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc -  Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: Void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
