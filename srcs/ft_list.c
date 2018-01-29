/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 23:39:10 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:22:14 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_func.h"
#include <stdio.h>

t_list	*ft_create_elem(char *data)
{
	t_list *new_elem;

	new_elem = NULL;
	new_elem = malloc(sizeof(t_list));
	new_elem->data = malloc(sizeof(char) * 10);
	if (new_elem)
	{
		ft_strcpy(new_elem->data, data);
		new_elem->next = NULL;
	}
	return (new_elem);
}

void	ft_list_push_back(t_list **begin_list, char *data)
{
	t_list *tmp;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		tmp = *begin_list;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_create_elem(data);
	}
}

void	ft_list_display(t_list *begin_list)
{
	if (!begin_list)
		return ;
	else
		while (begin_list)
		{
			printf("list: %s\n", begin_list->data);
			begin_list = begin_list->next;
		}
}

void	ft_list_remove_node(t_list *node)
{
	free(node);
}
