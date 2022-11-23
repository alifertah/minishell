/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cd_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:20:35 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/10 22:25:40 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_cd_err(t_state *state, char *dir_name)
{
	if (!dir_name)
		return ;
	state->status = 1;
	if (!ft_strncmp(dir_name, ".", 2))
	{
		put_error("cd", "error retrieving current directory\n");
		put_error("getcwd", "cannot access parent directories\n");
		put_error(dir_name, "No such file or directory\n");
	}
	else if (errno == ENOENT)
		put_error(dir_name, "No such file or directory\n");
	else if (errno == EACCES)
		put_error(dir_name, "Permission denied\n");
	else if (errno == ENOTDIR)
		put_error(dir_name, "Not a directory");
	else
		put_error(NULL, "Error!");
}

void	ft_free_puterror(t_state *state, char *dir_name,
			char *pwd)
{
	ft_put_cd_err(state, dir_name);
	free(pwd);
}

void	ft_chdir_update(t_state *state, char *new)
{
	free(state->oldpwd);
	state->oldpwd = new;
	state->pwd = get_pwd(state->pwd);
	state->status = 0;
	ft_update_env(state);
}

