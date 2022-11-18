/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:35:29 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/12 22:23:04 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	


ft_handle_status(t_state *state)
{
	if (state->status == 3)
	{
		write(2, "Quit: 3\n", 8);
		state->status = 131;
	}
	else if (state->status == 2)
	{
		write(2, "\n", 1);
		state->status = 130;
	}
	else if (state->status == 127 || state->status == 126)
		return ;
	else
		state->status = WEXITSTATUS(state->status);
}

static void	ft_cmd_exec(t_state *state, char **paths, char **cmdarg)
{
	char	*path;

	path = ft_check_path(state, paths, cmdarg);
	if (!path)
	{
		state->status = 127;
		return (put_error(cmdarg[0], "command not found\n"));
	}
	state->pid = fork();
	if (state->pid == -1)
		ft_free_exit(state, 1);
	if (state->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(path, cmdarg, state->envtab);
	}
	waitpid(state->pid, &state->status, 0);
	free(path);
}

static void	ft_exe_path(t_state *state, t_cmd *current_cmd)
{
	int	pid;

	if (!ft_check_file(state, current_cmd->name))
		return ;
	pid = fork();
	if (pid == -1)
		ft_free_exit(state, errno);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(current_cmd->name, current_cmd->args, state->envtab);
	}
	waitpid(pid, &state->status, 0);
}

static void	ft_execve(t_state *state, t_cmd *current_cmd)
{
	char	**paths;
	char	**carg;
	char	*tmp;
	int		i;

	i = -1;
	if (!current_cmd->name[0])
		return (put_error(current_cmd->name, "command not found\n"));
	if (current_cmd->args[0][0] == '.' ||
		ft_strchr(current_cmd->args[0], '/'))
		return (ft_exe_path(state, current_cmd));
	carg = current_cmd->args;
	state->path = ft_get_env(&state->env, "PATH");
	paths = NULL;
	if (state->path)
		paths = ft_split(state->path->value, ':');
	while (paths && paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
	}
	ft_cmd_exec(state, paths, carg);
	ft_free_temp(paths);
}

void	execution(t_state *state, t_cmd *current_cmd)
{
	if (ft_strncmp(current_cmd->name, "echo", 5) == 0)
		ft_echo(state, current_cmd);
	else if (ft_strncmp(current_cmd->name, "cd", 3) == 0)
		ft_cd(state, current_cmd);
	else if (ft_strncmp(current_cmd->name, "pwd", 4) == 0)
		ft_pwd(state);
	else if (ft_strncmp(current_cmd->name, "env", 4) == 0)
		ft_env(state, current_cmd);
	else if (ft_strncmp(current_cmd->name, "unset", 6) == 0)
		ft_env_unset(state, current_cmd);
	else if (ft_strncmp(current_cmd->name, "export", 7) == 0)
		ft_export(state, current_cmd);
	else if (ft_strncmp(current_cmd->name, "exit", 5) == 0)
		ft_exit(state, current_cmd);
	else
		ft_execve(state, current_cmd);
}
