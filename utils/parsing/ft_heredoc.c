/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:39:52 by alfertah          #+#    #+#             */
/*   Updated: 2022/11/16 00:35:04 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define WRITE_END 1
#define READ_END  0

static void	ft_doc_child(char *eof, int hfd[2])
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	line = NULL;
	while ("zbi")
	{
		line = readline("> ");
		if (!line || !ft_strncmp(line, eof, ft_strlen(eof) + 1))
			break ;
		write(hfd[WRITE_END], line, ft_strlen(line));
		write(hfd[WRITE_END], "\n", 1);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(hfd[WRITE_END]);
	exit(0);
}

int	ft_heredoc(char *eof)
{
	int	hfd[2];
	int	status;
	int	pid;

	if (pipe(hfd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	signal(SIGINT, SIG_IGN);
	if (!pid)
		ft_doc_child(eof, hfd);
	close(hfd[1]);
	waitpid(pid, &status, 0);
	if (status == 2)
		return (-1);
	return (hfd[0]);
}
