#include "monty.h"
/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _push(stack_t **head, unsigned int counter)
{
	int num, a = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			a++;
		for(; bus.arg[a] != '\0'; a++)
		{
			if (bus.arg[a] > 57 || bus.arg[a] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	if (bus.lifi == 0)
		addn(head, num);
	else
		addq(head, num);
}
