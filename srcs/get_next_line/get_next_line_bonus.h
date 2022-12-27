/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:05:07 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/27 13:18:41 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <stdlib.h>
# define BUFFER_SIZE 1024


typedef struct s_file	t_file;
struct	s_file
{
	char			buffer[BUFFER_SIZE];
	int				fd;
	int				size;
	int				cnt_newline;
	t_file			*next;
};

char	*get_next_line(int fd);
void	ft_strlcpy1(char *dst, const char *src, size_t dstsize);
t_file	*ft_lstnew1(int fd);
void	ft_substr1(char *s, unsigned int start, size_t len, size_t s_len);
char	*fill_str(t_file *file_node, char *str);
void	ft_cat_str(char *result, char *buffer, size_t size);
#endif
