/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 11:37:26 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/28 20:32:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_aloc(char **split, int n, char const *s)
{
	split = (char **)ft_calloc(n, sizeof(char *));
	if (n == 1)
		*split = NULL;
	else if (n == 2)
		*split = (char *)s;
	return (split);
}

static	void	ft_start_struct_spt(t_spt *parms_spt, char const *s, char c)
{
	parms_spt->t = ft_strtrim(s, &c);
	parms_spt->n = ft_countword(parms_spt->t, c);
	parms_spt->i = 0;
	parms_spt->init = NULL;
	parms_spt->split = NULL;
}

static	char	**ft_aux(t_spt *parms_spt)
{
	*(parms_spt->split + parms_spt->i) =
	ft_substr((char const *)parms_spt->t, 0, ft_strlen(parms_spt->t));
	return (parms_spt->split);
}

char			**ft_split(char const *s, char c)
{
	t_spt	p;

	ft_start_struct_spt(&p, s, c);
	if (!s || !c)
		return (NULL);
	if (!p.t || *p.t == '\0')
		return (ft_aloc(p.split, 1, s));
	if (p.n == 0)
		return (ft_aloc(p.split, 2, s));
	else
		p.split = ft_aloc(p.split, p.n + 1, s);
	while (p.i < p.n)
	{
		p.init = ft_strchr(p.t, c);
		if (p.init == 0)
			return (ft_aux(&p));
		*(p.split + p.i) = ft_substr((char const *)p.t, 0, p.init - p.t);
		while (*p.init == c)
			p.init += 1;
		p.t = p.init;
		p.i += 1;
	}
	return (p.split);
}
