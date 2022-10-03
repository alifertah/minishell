/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/03 23:22:09 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
int main(int ac, char **av, char **env)
{
    (void)ac;
    int y = 0;
    int x = 0;
    envp = (char **)malloc(sizeof(char *) * (count_env(env) + 100));
    while(env[x])
    {
        envp[x] = ft_strdup(env[y]);
        y++;
        x++;
    }
    envp[x] = NULL;
    if(av && av[1])
        ft_execute(av);
    return 0;
}
