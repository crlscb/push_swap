/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:52:09 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/20 11:31:28 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	counter;
	int	is_word;

	i = 0;
	counter = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

static int	ft_findnext(char *str, char c, int *start, int *end)
{
	int	i;

	i = *end;
	while (str[i] && str[i] == c)
		i++;
	*start = i;
	while (str[i] && str[i] != c)
		i++;
	*end = i;
	return (*start < *end);
}

static void	ft_freemem(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free (result);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	int				i;
	int				start;
	int				end;

	result = malloc(sizeof(char *) * (ft_countwords((char *)s, c) + 1));
	i = 0;
	start = 0;
	end = 0;
	if (result == NULL)
		return (NULL);
	while (ft_findnext((char *)s, c, &start, &end))
	{
		result[i] = malloc (end - start + 1);
		if (result[i] == NULL)
		{
			ft_freemem(result, i);
			return (NULL);
		}
		ft_strlcpy(result[i], (s + start), (end - start + 1));
		i++;
	}
	result[i] = NULL;
	return (result);
}
