/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 12:15:56 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:12:45 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROC_H
# define PROC_H

# include "stack.h"
# include "ft_list.h"
# include <stdlib.h>

void	proccess_nb(char *str, int *i, t_list **list);
void	proccess_op(char *str, int *i, t_stack *stack, t_list **list);
void	proccess_paran(char *str, int *i, t_stack *stack, t_list **list);

#endif
