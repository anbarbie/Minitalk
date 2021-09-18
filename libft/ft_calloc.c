/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:22:58 by antbarbi          #+#    #+#             */
/*   Updated: 2019/11/28 16:33:07 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc2(size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!(ptr = (void*)ft_memalloc2(size * nmemb)))
		return (NULL);
	return (ptr);
}
