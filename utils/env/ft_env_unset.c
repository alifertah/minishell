/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:26:20 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 22:52:24 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freenode(t_env_var *node)
{
	ft_free_matrix(node->both);
	free(node);
}

void	ft_lstdelone(t_state *state, t_env_var *var)
{
	t_env_var	*current_node;
	t_env_var	*before;

	if (!(state->env) || !var)
		return ;
	current_node = (state->env);
	before = NULL;
	while (current_node)
	{
		if (current_node == var)
		{
			if (!before)
			{
				state->env = current_node->next;
				return (ft_freenode(current_node),
					ft_setup_indexes(state->env));
			}
			before->next = current_node->next;
			return (ft_freenode(current_node), ft_setup_indexes(state->env));
		}
		before = current_node;
		current_node = current_node->next;
	}
}

static void	ft_env_del(t_state *state, char *name)
{
	t_env_var	*var;

	var = ft_get_env(&state->env, name);
	if (!var)
		return ;
	ft_lstdelone(state, var);
}

void	ft_env_unset(t_state *state, t_cmd *current_cmd)
{
	unsigned int	i;

	i = 0;
	if (current_cmd->num_of_args == 1)
		return ;
	while (current_cmd->args[++i])
	{
		if (ft_get_env(&state->env, current_cmd->args[i]))
			ft_env_del(state, current_cmd->args[i]);
	}
	state->status = 0;
}
