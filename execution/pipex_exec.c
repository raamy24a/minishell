/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:12:00 by acollon           #+#    #+#             */
/*   Updated: 2025/12/15 12:11:15 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int      exec_error(char **args, char *msg, int code)
{
        if (msg)
                ft_putendl_fd(msg, STDERR_FILENO);
        free_split(args);
        return (code);
}

static char     **build_args(char *cmd)
{
        if (!cmd)
                return (NULL);
        return (ft_split(cmd, " "));
}

int     px_exec(char *cmd, char **envp)
{
        char    *path;
        char    **args;

        args = build_args(cmd);
        if (!args || !args[0])
                return (exec_error(args, "Error: empty command", EXIT_FAILURE));
        path = px_find_path(args[0], envp);
        if (!path)
        {
                ft_putstr_fd("Command not found: ", STDERR_FILENO);
                ft_putendl_fd(args[0], STDERR_FILENO);
                free_split(args);
                return (127);
        }
        execve(path, args, envp);
        perror("execve");
        free(path);
        free_split(args);
        return (EXIT_FAILURE);
}
