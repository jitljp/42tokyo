/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:06:16 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/03 14:23:41 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates through the list 'lst' and applies the function 'f'
to the content of each node. Does not modify node pointers.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	multiply_by_two(void *content)
{
	int	*value;

	value = (int *)content;
	*value *= 2;
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		a;
	int		b;
	int		c;

	a = 1;
	b = 2;
	c = 3;
	node1 = ft_lstnew(&a);
	node2 = ft_lstnew(&b);
	node3 = ft_lstnew(&c);
	node1->next = node2;
	node2->next = node3;

	ft_lstiter(node1, multiply_by_two);
	printf("%d %d %d\n", *(int *)node1->content,
		*(int *)node2->content, *(int *)node3->content);

	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
