/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:53:35 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/17 23:03:04 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	This function is executiond when the export command is run with a +=
	option where it adds to the existing value of the env variable.
*/
void	ft_var_add(t_env_var **head, char **new)
{
	t_env_var	*var;
	char		*name;
	char		*tmp_val;

	name = new[0];
	name[ft_strlen(name) - 1] = '\0';
	var = ft_get_env(head, name);
	if (!var)
		return ;
	tmp_val = ft_strdup(new[1]);
	free(new[1]);
	new[1] = ft_strjoin(var->value, tmp_val);
	free(tmp_val);
	free(var->value);
	free(var->name);
	free(var->both);
	var->name = name;
	var->value = new[1];
	var->both = new;
}
