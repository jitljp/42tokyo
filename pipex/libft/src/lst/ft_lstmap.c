/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:29:23 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 15:31:28 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Creates a new list by applying function 'f' to each content
of the nodes in 'lst'. Uses 'del' to free content if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>

// ADD THESE FUNCTIONS TO TOP TO TEST
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*current_node;

// 	if (!lst || !new)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	current_node = *lst;
// 	while (current_node->next != NULL)
// 		current_node = current_node->next;
// 	current_node->next = new;
// }

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst != NULL)
// 	{
// 		temp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = temp;
// 	}
// }

void	*double_int(void *content)
{
	int	*value;
	int	*result;

	value = (int *)content;
	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	*result = (*value) * 2;
	return (result);
}

void	del_int(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_lst;
	int		a;
	int		b;
	int		c;

	a = 1;
	b = 2;
	c = 3;
	lst = ft_lstnew(&a);
	ft_lstadd_back(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));

	new_lst = ft_lstmap(lst, double_int, del_int);

	printf("%d %d %d\n", *(int *)new_lst->content,
		*(int *)new_lst->next->content, *(int *)new_lst->next->next->content);

	ft_lstclear(&new_lst, del_int);
	free(lst->next->next);
	free(lst->next);
	free(lst);
	return (0);
}
*/
