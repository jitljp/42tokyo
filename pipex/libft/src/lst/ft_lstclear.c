/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:53:02 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/03 11:01:29 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Deletes and frees all nodes of the list starting from '*lst',
using the function 'del' to free each node's content.
Afterwards, sets '*lst' to NULL.
'lst' is the address of the pointer to the first node.
'del' is the function used to delete the content of each node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/*
// Move before ft_lstclear to test
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del(void *content)
{
	free(content);
}


void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("%d\n", *(int *)(head->content));
		head = head->next;
	}
}

int	main(void)
{
	t_list	*head;
	int		*a;
	int		*b;
	int		*c;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	if (!a || !b || !c)
		return (1);

	*a = 100;
	*b = 200;
	*c = 300;

	head = ft_lstnew(a);
	head->next = ft_lstnew(b);
	head->next->next = ft_lstnew(c);

	printf("Before ft_lstclear:\n");
	print_list(head);

	ft_lstclear(&head, del);

	printf("After ft_lstclear:\n");
	if (head == NULL)
		printf("List is now empty.\n");

	return (0);
}
*/
