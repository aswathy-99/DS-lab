#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>     
#include<string.h>

#define SIZE 40

char stack[SIZE];
int top = -1;

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		stack[++top] = item;
	}
}

char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();		
		exit(1);
	}
	else
	{
		item = stack[top--];
		return(item);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')         
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               
	strcat(infix_exp,")");                  

	i=0;
	j=0;
	item=infix_exp[i];         

	while(item != '\0')        
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              
			j++;
		}
		else if(is_operator(item) == 1)      
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop();                     
			}
			push(x);
			push(item);                
		}
		else if(item == ')')        
		{
			x = pop();                
			while(x != '(')          
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	} 
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0'; 

}

void EvalPostfix(char postfix[])
 {

	int i ;
	char ch;
	int val;
	int A, B ;

	for (i = 0 ; postfix[i] != ')'; i++)
	{
		ch = postfix[i];
		if (isdigit(ch))
		{
			push(ch - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			A = pop();
			B = pop();

			switch (ch) 
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}
			push(val);
		}
	}
	printf( " \n Result of expression evaluation : %d \n", pop()) ;
}

int main(void)
{
	int c,x=0;
	char ch;
	while(1)
	{
	printf("Enter yout choice 1)Infix to postfix expression 2)Postfix evaluation 3)Exit\n");
	scanf("%d",&c);

	switch(c)	
	{
		case 1:
		{
			char infix[SIZE], postfix[SIZE];         
			printf("\nEnter Infix expression : ");
			scanf("%s",&infix);
			InfixToPostfix(infix,postfix);                 
			
			printf("Postfix Expression: ");
			for(int y=0;postfix[y]!='\0';y++)
			printf("%c ",postfix[y]);
			printf("\n");
			break;
		}
		case 2:
		{
			int i ;
			char postfix[SIZE];
			printf("There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");
			printf( " \nEnter postfix expression,\npress right parenthesis ')' for end expression : ");

			for (i = 0 ; i <= SIZE - 1 ; i++)
			{
			scanf("%c", &postfix[i]);
			if ( postfix[i] == ')' ) 
				break; 
			}

			EvalPostfix(postfix);
			break;
        	}
        case 3:exit(0);
		default:printf("Invalid choice\n");
	}
	}
	return 0;
}
