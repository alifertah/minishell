/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:25:48 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 19:09:24 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var	*ft_get_env(t_env_var **head, char *name)
{
	t_env_var	*current_node;
	int			add;

	current_node = *head;
	if (!head || !(*head))
		return (NULL);
	add = 0;
	if (name[ft_strlen(name) - 1] == '+')
	{
		add = 1;
		name[ft_strlen(name) - 1] = '\0';
	}
	while (current_node)
	{
		if (ft_strcmp(current_node->name, name) == 0)
		{
			if (add)
				name[ft_strlen(name)] = '+';
			return (current_node);
		}
		current_node = current_node->next;
	}
	return (NULL);
}

static void	print_env(t_state *state)
{
	t_env_var	*current_node;

	current_node = state->env;
	while (current_node)
	{
		// if (current_node->value == NULL || ft_strlen(current_node->value) == 0)
		// {
		// 	current_node = current_node->next;
		// 	continue ;
		// }
		printf("%s=%s\n", current_node->name, current_node->value);
		current_node = current_node->next;
	}
}

void	ft_env(t_state *state, t_cmd *current_cmd)
{
	if (current_cmd->num_of_args == 1)
	{
		print_env(state);
		state->status = 0;
	}
}
