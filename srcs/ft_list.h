/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 14:32:03 by adstan            #+#    #+#             */
/*   Updated: 2017/09/03 20:22:24 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

t_list				*ft_create_elem(char *data);
void				ft_list_push_back(t_list **begin_list, char *data);
void				ft_list_display(t_list *begin_list);
void				ft_list_remove_node(t_list *node);

#endif
