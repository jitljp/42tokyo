/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:24:16 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 14:31:51 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates a new t_list node using malloc. The content field is set to the
given pointer, and the next pointer is initialized to NULL.
Returns a pointer to the new node, or NULL if allocation fails.
*/
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

/*
#include <stdio.h>

int	main(void)
{
	t_list	*node;
	int		num;

	num = 42;
	node = ft_lstnew(&num);
	if (!node)
	{
		printf("Allocation failed\n");
		return (1);
	}
	printf("Content: %d\n", *(int *)(node->content));
	printf("Next: %p\n", (void *)node->next);

	free(node);
	return (0);
}
*/
