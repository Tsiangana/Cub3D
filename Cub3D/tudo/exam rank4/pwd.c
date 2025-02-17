/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:41:09 by pzau              #+#    #+#             */
/*   Updated: 2025/02/14 13:32:46 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	pwd(char *str)
{
	int	i = 0;
	int	on = 1;

	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			on = 0;
			i++;
		}
		if (on)
			i++;
		if (!on)
		{
			printf("%c", str[i]);
			i++;
		}
	}
	printf("\n");
}

void	export(char **env)
{
	for (int i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

void	export2(char **env, char *str2)
{
	int	add = 0;

	char **new_str = malloc(sizeof(char *) * 1000);

	for (int i = 0; env[i] != NULL; i++)
	{
		new_str[i] = strdup(env[i]);
	}
	for (int j s4% ./a ls |  dsfs
= 0; env[j] != NULL; j++)
	{
		new_str[j] = env[j];
		add = j;
	}
	new_str[add] = strcat(new_str[add], "\n");
	new_str[add] = strcat(new_str[add], str2);
	export(new_str);
}

void	unset(char **env, char *str)
{
	int i = 0;

	while (env[i] != NULL)
	{
		if (!strncmp(env[i], str, strlen(str)))
			i++;
		printf("%s\n", env[i]);
		i++;
	}
}

int	check_string(char *str)
{
	if (!strcmp(str, "|"))
		return (1);
	else
		return (0);
}

int executar(char **av, int i, char **envp)
{
	int tpipe, status, fd[2];

	if (!tpipe && !strcmp(av[i], "cd"))
		return(cd(av[i], i));
	if (!tpipe && )
}

int	main(int ac, char **av, char **env)
{
	char	*str = av[1];
	int	fd[2];
	if (ac >= 2)
	{
		if (!strncmp("pwd", str, strlen(str)))
		{
			if (av[2])
			{
				printf("pwd: too many arguments\n");
				return (1);
			}
			for (int i = 0; env[i] != NULL; i++)
			{
				if (!strncmp(env[i], "PWD", 3))
					pwd(env[i]);
			}
		}
		else if (!strncmp("export", str, strlen(str)))
		{
			if (av[2])
				export2(env, av[2]);
			else
				export(env);
		}
		else if (!strncmp("unset", str, strlen(str)))
		{
			if (ac == 2)
				return (0);
			else
				unset(env, av[2]);
		}
		else
			printf("comand %s not found\n", av[1]);
	}
	return (0);
}
