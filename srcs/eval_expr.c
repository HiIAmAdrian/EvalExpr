/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:09:56 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:54:35 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stack.h"
#include "ft_func.h"
#include "eval_expr.h"
#include <stdio.h>
#include "proc.h"

#include <string.h>

void	ss(int *result, t_list *tmp1, t_list *tmp2, t_list *tmp3)
{
	if (tmp3->data[0] == '+')
		*result = (ft_atoi(tmp1->data) + ft_atoi(tmp2->data));
	else if (tmp3->data[0] == '-')
		*result = (ft_atoi(tmp1->data) - ft_atoi(tmp2->data));
	else if (tmp3->data[0] == '*')
		*result = (ft_atoi(tmp1->data) * ft_atoi(tmp2->data));
	else if (tmp3->data[0] == '/')
		*result = (ft_atoi(tmp1->data) / ft_atoi(tmp2->data));
	else if (tmp3->data[0] == '%')
		*result = (ft_atoi(tmp1->data) % ft_atoi(tmp2->data));
}

int		operator(t_list *list, t_list *tmp1, t_list *tmp2, t_list *tmp3)
{
	int result;

	result = 0;
	while (tmp1->next)
	{
		tmp3 = tmp1->next->next;
		if (tmp3->next == 0)
			tmp2 = tmp1->next;
		if ((tmp3->data[0] < '0' || tmp3->data[0] > '9') || (tmp3->data
					[0] == '-' && tmp3->data[1] >= '0' && tmp3->data[1] <= '9'))
			tmp2 = tmp1->next;
		while ((tmp3->data[0] >= '0' && tmp3->data[0] <= '9') || (tmp3->data
					[0] == '-' && tmp3->data[1] >= '0' && tmp3->data[1] <= '9'))
		{
			tmp1 = tmp1->next;
			tmp2 = tmp1->next;
			tmp3 = tmp2->next;
		}
		ss(&result, tmp1, tmp2, tmp3);
		ft_strcpy(tmp1->data, ft_itoa(result));
		tmp1->next = tmp3->next;
		tmp1 = list;
	}
	return (ft_atoi(tmp1->data));
}

int		calculate(t_list *list)
{
	t_list *tmp1;
	t_list *tmp2;
	t_list *tmp3;

	tmp1 = list;
	tmp2 = tmp1->next;
	tmp3 = 0;
	if (tmp1->next == 0)
	{
		return (ft_atoi(tmp1->data));
	}
	else
	{
		return (operator(list, tmp1, tmp2, tmp3));
	}
}

void	empty_stack(t_stack *stack, t_list **list)
{
	char	tmp[2];

	while (stack->size > 0)
	{
		tmp[0] = stack_top(stack);
		tmp[1] = '\0';
		ft_list_push_back(list, tmp);
		stack_pop(stack);
	}
}

int		eval_expr(char *str)
{
	int		i;
	t_list	*list;
	t_stack	stack;

	list = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			proccess_nb(str, &i, &list);
		else if (str[i] == '*' || str[i] == '/' || str[i] == '%' ||
				str[i] == '+' || str[i] == '-')
			proccess_op(str, &i, &stack, &list);
		else if (str[i] == '(' || str[i] == ')')
			proccess_paran(str, &i, &stack, &list);
		else
			i++;
	}
	empty_stack(&stack, &list);
	return (calculate(list));
}
