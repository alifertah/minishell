/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:50:31 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/18 18:09:16 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int main(int ac, char **av)
{
    (void)ac;
    int j  = 1;
    while(av[j])
    {
        if(!(strcmp(av[j], "pwd")))
            printf("%s\n", getcwd(NULL, 0));
        if(!(strcmp(av[j], "cd")))
        {
            if(av[j+1])
            {
                chdir(av[j+1]);
                printf("%s", getcwd(NULL, 0));
            }
            else
            {
                chdir(getenv("HOME"));
                printf("%s", getcwd(NULL, 0));
            }
        }
        if(!(strcmp(av[j], "echo")))
        {
            if(av[j+1])
            {
                if(!strcmp(av[j+1], "-n"))
                {
                    if(av[j + 2])
                        printf("%s", av[j+2]);
                    else
                        return 0;
                }
                else
                    printf("%s\n", av[j+1]) ;
            }
            else
                printf("\n");
        }
        j++;
    }
}
