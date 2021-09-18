/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:33:37 by antbarbi          #+#    #+#             */
/*   Updated: 2019/11/18 18:00:04 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*beg;
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		if (!(beg = ft_lstnew(f(tmp->content))))
			return (NULL);
		tmp = tmp->next;
		while (tmp->next)
		{
			if (!(new = ft_lstnew(f(tmp->content))))
			{
				ft_lstclear(&beg, del);
				return (NULL);
			}
			ft_lstadd_back(&beg, new);
			tmp = tmp->next;
		}
		return (beg);
	}
	return (NULL);
}
