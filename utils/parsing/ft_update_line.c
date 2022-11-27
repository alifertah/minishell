	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:14:43 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/27 18:22:20 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_tokenize_dollar(char *line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			if (line[i + 1] == '?')
			{
				line[i++] = EXIT_STATUS;
				line[i] = EXIT_STATUS;
			}
			else if (line[i + 1] != '$')
				line[i] = ENV_SIGN;
			else
				i++;
		}
		i++;
	}
}

static char	*ft_get_env_name(char *line, int i)
{
	int		j;
	char	*env_name;

	j = 0;
	if (line[i + j] >= '0' && line[i + j] <= '9')
		return (ft_strdup(""));
	while (line[i + j] && (ft_isalnum(line[i + j]) || line[i + j] == '_'))
		j++;
	env_name = ft_substr(line, i, j);
	return (env_name);
}

static char	*ft_replace_env(t_state *state, char *line)
{
	t_env_var	*env;
	char		*name;
	char		*output;
	int			i;

	i = 0;
	output = NULL;
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (line[i] == ENV_SIGN)
		{
			name = ft_get_env_name(line, i + 1);
			env = ft_get_env(&state->env, name);
			if (env)
				output = ft_strjoin(output, env->value);
			else
				output = ft_strjoin(output, "");
			i += ft_strlen(name);
			free(name);
		}
		else if (line[i] == EXIT_STATUS)
		{
			name = ft_itoa(state->status);
			output = ft_strjoin(output, name);
			free(name);
			i++;
		}
		else
			output = ft_strjoin_char(output, line[i]);
		i++;
	}
	return (output);
}

char	*ft_update_line(t_state *state, char *line)
{
	char	*new_line;

	if (!line)
		return (NULL);
	new_line = ft_strdup(line);
	free(line);
	line = NULL;
	ft_tokenize_dollar(new_line);
	new_line = ft_replace_env(state, new_line);
	printf("new_line: %s\n", new_line);
	return (new_line);
}
