/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labeuhlognaise <labeuhlognaise@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 03:04:19 by radib             #+#    #+#             */
/*   Updated: 2025/12/12 13:10:58 by labeuhlogna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int      str_equals(const char *a, const char *b)
{
        return (ft_strncmp(a, b, ft_strlen(a) + ft_strlen(b)) == 0);
}

int     is_builtin(const char *cmd)
{
        if (!cmd)
                return (0);
        return (str_equals(cmd, "echo") || str_equals(cmd, "cd")
                || str_equals(cmd, "pwd") || str_equals(cmd, "export")
                || str_equals(cmd, "unset") || str_equals(cmd, "exit"));
}

int     exec_builtin(t_command *cmd, t_env *env)
{
        if (!cmd || !cmd->argv || !cmd->argv[0])
                return (0);
        if (str_equals(cmd->argv[0], "echo"))
        {
                echobuiltin(cmd->argv + 1, env);
                return (0);
        }
        if (str_equals(cmd->argv[0], "cd"))
                return (call_cd(env, cmd->argv[1]));
        if (str_equals(cmd->argv[0], "pwd"))
                return (call_pwd(env));
        if (str_equals(cmd->argv[0], "export"))
                return (export_builtin(env, cmd->argv));
        if (str_equals(cmd->argv[0], "unset"))
                return (builtin_unset(env, cmd->argv + 1, env, 0));
        if (str_equals(cmd->argv[0], "exit"))
        {
                if (cmd->argv[1])
                        return (exit_call(ft_atoi(cmd->argv[1])));
                return (exit_call(0));
        }
        return (0);
}
