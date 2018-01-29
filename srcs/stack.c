/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 20:10:56 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:12:16 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_pop(t_stack *stack)
{
	if (stack->size > 0)
		stack->size--;
}

void	stack_push(t_stack *stack, char c)
{
	stack->size++;
	stack->stk[stack->size] = c;
}

char	stack_top(t_stack *stack)
{
	return (stack->stk[stack->size]);
}
