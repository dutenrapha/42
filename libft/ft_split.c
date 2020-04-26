/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 11:37:26 by rdutenke          #+#    #+#             */
/*   Updated: 2020/03/14 12:48:42 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  **ft_split(char const *s, char c)
{
        int n;
        int i;
        int len;
	char *s1;
	char *init;
        char **split;

        if(!s || !c)
                return (NULL);

        init = &c;
	s1 = &c;
       	s1 = ft_strtrim(s, init);
        
        if(!s1 || *s1 == '\0')
        {
                split = (char **)malloc(sizeof(char *));
                *split = NULL;
                return(split);
        }
	
	n = ft_countword(s1,c);

        if(n == 0)
        {
                split = (char **)ft_calloc(2, sizeof(char *));
		*split = (char *)s;
                return(split);
        }
        else
        {
                split = (char **)ft_calloc(n + 1, sizeof(char *)); 
	}

	i = -1;
        while(++i < n)
        {
                init = ft_strchr(s1,c);
                if(init == 0)
                {
                  len = ft_strlen(s1);
                  *(split + i) = ft_substr((char const *)s1,0, len);
		  return(split);
                }
      	
		len = init - s1;

		*(split + i) = ft_substr((char const *)s1,0, len);
		
		while(*init == c)
                {
                        init++;
                }
                s1 = init;
        }
       return(split);

}
