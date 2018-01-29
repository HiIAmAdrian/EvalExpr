/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 19:43:55 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:11:43 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	char		stk[50];
	int			size;
}				t_stack;

void			stack_pop(t_stack *stack);
void			stack_push(t_stack *stack, char c);
char			stack_top(t_stack *stack);

#endif
