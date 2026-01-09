/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:46:22 by ylenoel           #+#    #+#             */
/*   Updated: 2024/10/08 13:02:19 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newt)
{
	t_list	*last;

	if (!lst || !newt)
		return ;
	if (!*lst)
		*lst = newt;
	else
	{
		last = ft_lstlast(*lst);
		last->next = newt;
	}
}
