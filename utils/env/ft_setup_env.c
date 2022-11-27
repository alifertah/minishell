/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:14:14 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/27 19:29:14 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	ft_count_smaller(t_env_var *head, t_env_var *node)
{
	t_env_var		*current_node;
	unsigned int	smaller;

	smaller = 0;
	current_node = head;
	while (current_node)
	{
		if (current_node == node)
		{
			current_node = current_node->next;
			continue ;
		}
		if (ft_strcmp(current_node->name, node->name) < 0)
			smaller++;
		current_node = current_node->next;
	}
	return (smaller);
}

void	ft_setup_indexes(t_env_var *head)
{
	t_env_var	*current_node;

	current_node = head;
	while (current_node)
	{
		current_node->sort_index = ft_count_smaller(head, current_node);
		current_node = current_node->next;
	}
}

void	ft_add_shlvl(t_env_var **env_lst, unsigned int *i)
{
	t_env_var		*new_var;
	char			*env_str;
	char			**new_env;

	env_str = ft_strdup("SHLVL=0");
	if (!env_str)
		return ;
	new_env = ft_split_env(env_str, '=');
	new_var = ft_lstnew(new_env);
	new_var->index = (*i)++;
	free(env_str);
	ft_lstadd_back(env_lst, new_var);
}

t_env_var	*ft_setup_env(char **env)
{
	t_env_var		*env_lst;
	t_env_var		*new_var;
	char			**new_env;
	unsigned int	i;

	i = 0;
	if (!env || !env[i])
		return (ft_default_env(NULL));
	new_env = ft_split_env(env[i], '=');
	if (!new_env)
		return (NULL);
	env_lst = ft_lstnew(new_env);
	env_lst->index = i++;
	while (env[i])
	{
		new_env = ft_split_env(env[i], '=');
		if (ft_strncmp(new_env[0], "OLDPWD", 7) != 0)
		{
			new_var = ft_lstnew(new_env);
			ft_lstadd_back(&env_lst, new_var);
		}
		else
			ft_free_matrix(new_env);
		new_var->index = i++;
	}
	env_lst = ft_default_env(env_lst);
	ft_setup_indexes(env_lst);
	return (env_lst);
}
