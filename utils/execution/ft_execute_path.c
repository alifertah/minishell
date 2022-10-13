/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:26:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/12 18:57:28 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_path(t_state *state, char **paths, char **cmdarg)
{
	int		i;
	char	*forfree;

	i = 0;
	while (paths && paths[i])
	{
		forfree = ft_strjoin(paths[i++], cmdarg[0]);
		if (!access(forfree, X_OK | F_OK))
			return (forfree);
		free(forfree);
	}
	state->status = 127;
	return (NULL);
}

char	*ft_check_relative(t_state *state, char *cmd)
{
	struct stat	statbuf;

	stat(cmd, &statbuf);
	if (!access(cmd, X_OK | F_OK))
	{
		if (S_ISDIR(statbuf.st_mode) == 1)
		{
			state->status = 126;
			return (put_error(cmd, "is a directory\n"), NULL);
		}
		else
			return (cmd);
	}
	if (!access(cmd, F_OK))
	{
		state->status = 126;
		return (put_error(cmd, "Permission denied\n"), NULL);
	}
	else if (ft_strchr(cmd, '/'))
		put_error(cmd, "No such file or directory\n");
	else
		put_error(cmd, "command not found\n");
	state->status = 127;
	return (NULL);
}
