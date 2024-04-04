/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 19:39:48 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/// @brief 			return the (the next) line of a file to the request
/// @algorithm		1)	define a static (for consectuive call) workstring array
///						for multiple different file descriptor calls in parallel
///						handling of the content read from the fd's file
///						the line string to store the actual line and the 
///						range which serves as a buffer for the following logic
///						status will represent the state of reading
///						(size EOF Error) OPEN_MAX of limits lib will parse the
///						maximum ammount of files able to be opened by system
///					2)	initialize line with NULL and the status defaults to 1
///					3)	Check BUFFER_SIZE -D Variable and the fd or return
///					4)	build workstring will retreive the content of the file
///						and represent the content in the workstring
///						status amd range are parsed for central handling
///						remains of previous calls in the beginning of 
///						workstring are noticed and will be kept for line 
///						generation
///					5)	validate worstring and status
///					6)	build the actuial line string
///					7)	validate line
///					8)	prepare workstring for the next nect line call by 
///						removing the retreived line from its start and
///						move all the remaining to the start of it
/// @param fd 		file descriptor of file to read from
/// @return line	the line as a terminated string
char	*get_next_line(int fd)
{
	static char	*workstring[OPEN_MAX];
	char		*line;
	int			status;
	char		range[BUFFER_SIZE + 1];

	line = NULL;
	status = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	workstring[fd] = build_workstring(fd, workstring[fd], &status, range);
	if (workstring[fd] == NULL || status == -1)
		return (smart_free(workstring[fd], 1));
	line = build_line(workstring[fd]);
	if (line == NULL)
	{
		free(workstring[fd]);
		workstring[fd] = NULL;
		return (NULL);
	}
	workstring[fd] = prep_next(workstring[fd]);
	return (line);
}

/// @brief				Provide the file content readeable by the size block of
///						BUFFER_SIZE and terminate it for following string 
///						handling functions
/// @algorithm			1)	make shure range is cleared memory
///						2)	check existance of workstring and initialize it 
///							as cleared memory if not initialized yet
///						3)	while reading was successfull and the range does not
///							contain a newline yet read the BUFFER_SIZE and
///							append the block till newline or EOF to the 
///							workstring by strjoin. Hadnle the EOF and Error in
///							reading from fd
///						4)	terminate range for str handling and join into tmp
///							so free'n the right pointer workstring is possible
///						5)	swap tmp and workstring and us the tmp content as
///							new worjstring to be returned. free tmp indeed. 
/// @param fd 			the file descriptor to read from
/// @param workstring 	the string to do actions on and return to the process
/// @param state 		the state of the file reading pointed by the gnl 
///						function
/// @param range 		buffer memory for temporary storage of the read file
///						content
/// @return workstring	
char	*build_workstring(int fd, char *workstring, int *state, char *range)
{
	char	*tmp;

	ft_memset(range, 0, BUFFER_SIZE + 1);
	if (workstring == NULL)
	{
		workstring = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (workstring == NULL)
			return (NULL);
		ft_memset(workstring, 0, BUFFER_SIZE + 1);
	}
	while (*state > 0 && !ft_contains(range, '\n'))
	{
		*state = read(fd, range, BUFFER_SIZE);
		if (*state == -1)
			return (smart_free(workstring, 0));
		if (*state == 0)
			break ;
		range[*state] = '\0';
		tmp = ft_strjoin(workstring, range);
		free(workstring);
		workstring = tmp;
	}
	return (workstring);
}

/// @brief 				get the "line" from the workstring
/// @algorithm			1)	define the line str and a int for its length as
///							well as a index needed
///						2)	check if the workstring is NULL or an empty string
///						3)	define len of line by measurung till newline or
///							termination (EOF)
///						4)	allocate mem according to the found situation in 
///							workstring nl and temrination or only termination
///							validate allocation successs
///						5)	copy the string and terminate either with a newline
///							and the terminator or the termintor only likewise
///							the reason of the different allocation procedure
///						6)	return the line
/// @param workstring 	the preprocessed content read from the fd as a string
/// @return line		the lin as a string
char	*build_line(char *workstring)
{
	char		*line;
	size_t		linelen;
	size_t		i;

	i = 0;
	linelen = 0;
	if (workstring == NULL || workstring[i] == '\0')
		return (NULL);
	while (workstring[linelen] != '\n' && workstring[linelen] != '\0')
		linelen++;
	if (workstring[linelen] == '\n')
		line = malloc((linelen + 2) * sizeof(char));
	else
		line = malloc((linelen + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < linelen)
	{
		line[i] = workstring[i];
		i++;
	}
	if (workstring[linelen] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/// @brief 				prepare the workstring for the next get next line call
///						to workstrings beginning
/// @algorithm			1)	define the next to be returned string as a new 
///							char pointer as well as indexes for new and old
///						2)	check if the workstring exists and measure the 
///							already processed part by imitating the 
///							while in build line if the remains of the last
///							build are only an empty string NULL shall be 
///							returned and free'd be the memory
///						3)	else the separator sign (newline) may be skipped
///							and next may be build by the subtraction of
///							the remains from whole workstring allocation and
///							a simple cpy
///						4)	mind to free the last workstring and return the
///							next to the pointer used as workstring for any
///							call to be executed from now on
/// @param workstring 	the current worstring that needs to be updated
/// @return next		updated workstring for next get next line call
char	*prep_next(char *workstring)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	if (workstring == NULL)
		return (NULL);
	while (workstring[i] != '\n' && workstring[i] != '\0')
		i++;
	if (workstring[i] == '\0')
		return (smart_free(workstring, 0));
	i++;
	next = malloc((ft_strlen(workstring) - i + 1) * sizeof(char));
	if (next == NULL)
		return (smart_free(workstring, 0));
	while (workstring[i] != '\0')
	{
		next[j] = workstring[i];
		i++;
		j++;
	}
	next[j] = '\0';
	free(workstring);
	return (next);
}
