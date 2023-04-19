/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:11:01 by egomez-a          #+#    #+#             */
/*   Updated: 2023/04/19 15:09:36 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

/* 
** Compares up to n characters of the string s1 to those of the string s2.   
** Returns an integral value indicating the relationship between the strings.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && --n && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters are
** searched.  Characters that appear after a `\0' character are not searched.
** Return Values: If needle is an empty string, haystack is returned; if needle
** occurs nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t		i;
	size_t		j;

	if (ndl[0] == '\0')
		return ((char *)hst);
	i = 0;
	while (hst[i] && i < len)
	{
		j = 0;
		if (hst[i] == ndl[j])
		{
			while (i + j < len && hst[i + j] == ndl[j])
			{
				j++;
				if (!ndl[j])
					return ((char *)&hst[i]);
			}
		}
		i++;
	}
	return (0);
}

/*
** Reserva memoria con malloc y devuelve la cadena de caracteres que es copia
** de 's1', sin los caracteres indicados en 'set' al principio y al final de la
** cadena de caracteres. NULL si falla la reserva de memoria.
** Uso la funcion ft_strchr, que busca el caracter s1[beg] en set, con un
** contador beg que se para cuando s1 termina. Por tanto retorna la posicion beg
** que es donde esta el carácter buscado.
*/

size_t	ft_begtrim(char const *s1, char const *set)
{
	int	beg;

	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	return (beg);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	beg = ft_begtrim(s1, set);
	end = ft_strlen(s1);
	if (beg == end)
	{
		str = malloc (sizeof (char *));
		str[0] = '\0';
		return (str);
	}
	while (s1[end - 1] != '\0' && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc (sizeof (char) * (end - beg + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
