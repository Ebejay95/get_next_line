/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:29:55 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 18:44:39 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief 			set a range of memory to a value by poointer and size 
///	@algorithm		set a working buffer to not loose the pointer to memory
///					iterate trough the range by size, move the pointer and
///					set values pointed at
/// @param start 	pointer to memory range
/// @param fill 	value the memory range shall be filled with
/// @param size 	size of the desired range
/// @return start	pointer to start
void	*ft_memset(void *start, int fill, size_t size)
{
	unsigned char	*work;

	work = start;
	while (size > 0)
	{
		*work = fill;
		work++;
		size--;
	}
	return (start);
}

/// @brief		get the length of a string
///	@algorithm	decplare an int counter and iterate to the termination of the
///				string str while counting each iteration. return the counter
/// @param str 	string that length shall be returned
/// @return len	length of string
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/// @brief 			join a string to the end of another string and return as new
///	@algorithm		1)	define size_ts for the lengths of both strings as well
///						as a char pointer for the result and a char pointer to
///						keep the pointer to the start of the result
///					2)	get the lengths of bothe strings ans allocate their sum
///						of bytes for the join + 1 for termination
///					3)	check allocation success or return NULL
///					4)	store the join start pointer for return
///					5)	iterate trough s1 and s2 after another to fill the 
///						allocated result
///					6)	terminate the result and return the keept pointer to its
///						start
/// @param s1 		string to join to
/// @param s2 		string to be joined
/// @return join	pointer to the joined result	
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*join_work;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join_work = join;
	while (*s1 != '\0')
	{
		*join_work = *s1;
		join_work++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*join_work = *s2;
		join_work++;
		s2++;
	}
	*join_work = '\0';
	return (join);
}

/// @brief 				tell if a str contains a char or not
///	@algorithm			1)	terminate with negative if str is NULL
///						2)	walk trough haystack till char needle is found and
///							return 1 on  occurance else return 0 by default
/// @param haystack 	str to search char needle in
/// @param needle 		char to search for in haystack
/// @return 1|0			depenend on detection of the needle char
int	ft_contains(char *haystack, char needle)
{
	long long	i;

	i = 0;
	if (haystack == NULL)
		return (0);
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (1);
		i++;
	}
	return (0);
}

/// @brief 				free workstring and terminate function 
///	@algorithm			1)	free if s is  not NULL and return NULL
/// @param s 			string to free
/// @param proc 		select process to be run
/// @return 			NULL
char	*smart_free(char *s, int proc)
{
	if (proc)
	{
		if (s != NULL)
		{
			free(s);
			s = NULL;
		}
	}
	else
	{
		free(s);
		s = NULL;
	}
	return (NULL);
}
