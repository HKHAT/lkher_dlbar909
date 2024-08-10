/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 04:25:46 by elchakir          #+#    #+#             */
/*   Updated: 2024/08/10 05:55:48 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_save	**save_add(void)
{
	static t_save	*save;

	if (save == NULL)
	{
		save = malloc(sizeof(t_save));
		if (!save)
			return (NULL);
		save->add = NULL;
		save->next = NULL;
	}
	return (&save);
}

void	*ft_malloc(size_t size)
{
	void	*add;
	t_save	*head;

	add = malloc(size);
	if (!add)
		return (0);
	head = malloc(sizeof(t_save));
	if (!head)
		return (0);
	head->add = add;
	head->next = *save_add();
	*save_add() = head;
	return (add);
}

void	ft_free_all(void)
{
	t_save	*head;
	t_save	*temp;
	int		i;

	i = 0;
	head = *save_add();
	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->add)
			free(temp->add);
		free(temp);
		printf("time loop [%i]\n", i);
		i++;
	}
}
