/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 10:35:05 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:13:14 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"

int		check_grade(char s1, char s2)
{
	int g_s1;
	int g_s2;

	g_s1 = 0;
	g_s2 = 0;
	if (s1 == '+' || s1 == '-')
		g_s1 = 1;
	else if (s1 == '*' || s1 == '/' || s1 == '%')
		g_s1 = 2;
	if (s2 == '+' || s2 == '-')
		g_s2 = 1;
	else if (s2 == '*' || s2 == '/' || s2 == '%')
		g_s2 = 2;
	return (g_s1 - g_s2);
}

void	proccess_nb(char *str, int *i, t_list **list)
{
	char	nb[12];
	int		l;

	l = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb[l] = str[*i];
		(*i)++;
		l++;
	}
	nb[l] = '\0';
	ft_list_push_back(list, nb);
}

void	tarnei(char *tmp, t_list **list, t_stack *stack)
{
	tmp[0] = stack_top(stack);
	tmp[1] = '\0';
	ft_list_push_back(list, tmp);
	stack_pop(stack);
}

void	proccess_op(char *str, int *i, t_stack *stack, t_list **list)
{
	char c;
	char tmp[2];

	c = str[*i];
	if (!stack->size || stack_top(stack) == '(')
		stack_push(stack, c);
	else if (check_grade(c, stack_top(stack)) == 1)
		stack_push(stack, c);
	else if (check_grade(c, stack_top(stack)) == 0)
	{
		tmp[0] = stack_top(stack);
		tmp[1] = '\0';
		ft_list_push_back(list, tmp);
		stack_pop(stack);
		stack_push(stack, c);
	}
	else if (check_grade(c, stack_top(stack)) == -1)
	{
		while (stack->size && stack_top(stack) != '(')
			tarnei(tmp, list, stack);
		stack_push(stack, c);
	}
	(*i)++;
}

void	proccess_paran(char *str, int *i, t_stack *stack, t_list **list)
{
	char c;
	char tmp[2];

	c = str[*i];
	if (c == '(')
	{
		stack_push(stack, c);
	}
	else if (c == ')')
	{
		while (stack_top(stack) != '(')
		{
			tmp[0] = stack_top(stack);
			tmp[1] = '\0';
			ft_list_push_back(list, tmp);
			stack_pop(stack);
		}
		stack_pop(stack);
	}
	(*i)++;
}
