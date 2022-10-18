/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:24:23 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 22:40:25 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(char *pwd)
{
	if (pwd)
	{
		free(pwd);
		pwd = NULL;
	}
	pwd = getcwd(NULL, PATH_MAX);
	return (pwd);
}

void	ft_chdir_home(t_state *state)
{
	char	*tmp;

	if (!state->home || !state->home->value)
	{
		put_error("cd", "HOME not set.\n");
		state->status = 1;
		return ;
	}
	tmp = ft_strdup(state->pwd);
	if (chdir(state->home->value) == -1)
		put_error("cd", "No such file or directory\n");
	else
		ft_chdir_update(state, tmp);
}

static void	ft_chdir(t_state *state, char *dir_name)
{
	char	*tmp;

	tmp = NULL;
	tmp = get_pwd(tmp);
	if ((ft_strcmp(dir_name, ".") || ft_strcmp(dir_name, "..") == 0)
		&& errno == ENOENT)
	{
		ft_free_puterror(state, ".", tmp);
		return ;
	}
	else if (errno == ENOENT || !tmp)
		tmp = ft_strdup(state->pwd);
	if (chdir(dir_name) == -1)
		ft_free_puterror(state, dir_name, tmp);
	else
		ft_chdir_update(state, tmp);
}

static void	ft_chdir_back(t_state *state)
{
	char	*tmp;

	if(state->oldpwd == NULL)
	{
		put_error("cd", "OLDPWD not set.\n");
		state->status = 1;
		return ;
	}
	tmp = ft_strdup(state->pwd);
	if (!tmp)
		ft_free_exit(state, OUT_OF_MEM);
	if (chdir(state->oldpwd) == -1)
		ft_free_puterror(state, state->oldpwd, tmp);
	else
		ft_chdir_update(state, tmp);
}


void	ft_cd(t_state *state, t_cmd *current_cmd)
{
	if (current_cmd->num_of_args == 1)
	{
		ft_chdir_home(state);
		return ;
	}
	if (ft_strcmp(current_cmd->args[1], "--") == 0)
		ft_chdir_home(state);
	else if (ft_strcmp(current_cmd->args[1], "-") == 0)
		{
			ft_chdir_back(state);
		}
	else
		ft_chdir(state, current_cmd->args[1]);
}
