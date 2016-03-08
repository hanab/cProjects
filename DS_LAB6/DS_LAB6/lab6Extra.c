# include"intstack.h"
# include <string.h>
# include<ctype.h>
# include<stdlib.h>
# include <stdio.h>
# define MAXE 80
Tintstack stack;
int precedence(char ope);
void infixTopostfix(char *infix, char *postfix);
int evaluatepostfix(char *postfix);
int main(void)
{
	int i;
	char infix[80];
	char postfix[80];
	printf("Infix to postfix converter\n");
	printf("Give an infix equation at one line\n");
	gets(infix);
	infixTopostfix(infix, postfix);
	printf("Equivivalent postfix equation is: ");
	for (i = 0; i<strlen(postfix); i++)
	{

		printf("%c ", postfix[i]);

	}
	printf("\n");
	printf("And it's value is %d\n", evaluatepostfix(postfix));


}
int precedence(char ope)
{

	if (ope == '#' || ope == '(' || ope == ')')
		return 1;
	else if (ope == '+' || ope == '-')
		return 2;
	else if (ope == '*' || ope == '/')
		return 3;
	else return 0;
}
void infixTopostfix(char *infix, char *postfix)
{
	int i, j = 0;
	int temp;

	initialize_int_stack(&stack);
	push_int(&stack, '#');

	for (i = 0; i<strlen(infix); i++)

	{
		if (isdigit(infix[i]))
			postfix[j++] = infix[i];
		else 
			{if (infix[i] == '(')
				push_int(&stack, infix[i]);
			else if (infix[i] == ')') 
			{
				if(!is_empty_int_stack(&stack))
				{pop_int(&stack, &temp);
				push_int(&stack, temp);}
				while ((char)temp != '(' && !is_empty_int_stack(&stack))
				{

					pop_int(&stack, &temp);
					if (temp != '(')
					{
						postfix[j++] = (char)temp;
					}
					
				} 
				if(!is_empty_int_stack(&stack))
				{pop_int(&stack, &temp);}
			}
			else{
				if(!is_empty_int_stack(&stack))
				{pop_int(&stack, &temp);
				push_int(&stack, temp);}
				if (precedence(infix[i])>precedence((char)temp))
				{
					push_int(&stack, infix[i]);
				}
				else{
					if(!is_empty_int_stack(&stack))
					{pop_int(&stack, &temp);
					push_int(&stack, temp);}
					while (precedence(infix[i]) <= precedence((char)temp))
					{
						if (precedence(infix[i]) <= precedence((char)temp))
						{
							pop_int(&stack, &temp);
							if (temp != '#'&& !is_empty_int_stack(&stack))
							{
								postfix[j++] = (char)temp;
							}
						}
					}
					push_int(&stack, infix[i]);

				}

			}


		}




	}
	if(!is_empty_int_stack(&stack))
	{pop_int(&stack, &temp);
	push_int(&stack, temp);}
	while (temp != '#'&& !is_empty_int_stack(&stack))
	{
		pop_int(&stack, &temp);
		if ((char)temp != '#')
		{

			postfix[j++] = (char)temp;
		}
	}
	postfix[j] = '\0';

}
int evaluatepostfix(char *postfix)
{
	Tintstack stack;
	int i, operand, op1, op2,temp;
	initialize_int_stack(&stack);
	for (i = 0; i<strlen(postfix); i++)
	{

		if (isdigit(postfix[i]))
		{
			operand = postfix[i] - 48;
			push_int(&stack, operand);
		}
		else if (postfix[i] == '+')
		{
			if (!is_empty_int_stack(&stack) && pop_int(&stack, &op1) && pop_int(&stack, &op2))
			{
				operand = op1 + op2;
				push_int(&stack, operand);
			}
		}
		else if (postfix[i] == '-')
		{
			if (!is_empty_int_stack(&stack) && pop_int(&stack, &op1) && pop_int(&stack, &op2))
			{
				operand = op2 - op1;
				push_int(&stack, operand);
			}
		}
		else if (postfix[i] == '*')
		{
			if (!is_empty_int_stack(&stack) && pop_int(&stack, &op1) && pop_int(&stack, &op2))
			{
				operand = op1*op2;
				push_int(&stack, operand);
			}
		}
		else if (postfix[i] == '/')
		{
			if (!is_empty_int_stack(&stack) && pop_int(&stack, &op1) && pop_int(&stack, &op2))
			{
				operand = op2 / op1;
				push_int(&stack, operand);
			}
		}
	}
	print_int_stack(&stack);
	pop_int(&stack, &temp);
	push_int(&stack, temp);
	return temp;



}