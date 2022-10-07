/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/07 05:20:47 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
int main(int ac, char **av, char **env)
{
    (void)av;
    (void)ac;
    int y = 0;
    int x = 0;
    char *rdl;
    char **cmd;
    envp = (char **)malloc(sizeof(char *) * (count_env(env) + 100));
    while(env[x])
    {
        envp[x] = strdup(env[y]);
        y++;
        x++;
    }
    envp[x] = NULL;
    while(1)
    {
        rdl = readline("\033[0;32mSHILIMENN : ");
        cmd = ft_split(rdl,' ');
        ft_execute(cmd, envp);
        free(rdl);
    }
    return 0;
}
