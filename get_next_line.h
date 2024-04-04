/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:30 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/28 11:50:27 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_contains(char *haystack, char needle);
char	*get_next_line(int fd);
char	*build_line(char *workstring);
char	*build_workstring(int fd, char *workstring, int *state, char *range);
char	*prep_next(char *workstring);
void	*ft_memset(void *start, int fill, size_t size);
char	*smart_free(char *s, int proc);
#endif