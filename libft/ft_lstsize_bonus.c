/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:54 by ylenoel           #+#    #+#             */
/*   Updated: 2023/11/14 17:20:24 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*buffer;
	int		i;

	buffer = lst;
	i = 0;
	while (buffer)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}
