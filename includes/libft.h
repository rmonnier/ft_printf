/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:12:13 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/28 15:16:10 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char	t_byte;
typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, void const *src, size_t n);
void					*ft_memccpy(void *dst, void const *src,\
									int c, size_t n);
void					*ft_memmove(void *dst, void const *src, size_t len);
void					*ft_memchr(void const *s, int c, size_t n);
int						ft_memcmp(void const *s1, void const *s2, size_t n);
void					ft_print_memory(const void *addr, size_t size);
size_t					ft_strlen(char const *s);
char					*ft_strdup(char const *s1);
char					*ft_strcpy(char *dst, char const *src);
char					*ft_strncpy(char *dst, char const *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, char const *src, size_t size);
char					*ft_strchr(char const *s, int c);
char					*ft_strrchr(char const *s, int c);
char					*ft_strstr(char const *big, char const *little);
char					*ft_strnstr(char const *big, char const *little,\
									size_t len);
void					ft_strclr(char *s);
int						ft_strcmp(char const *s1, char const *s2);
int						ft_strncmp(char const *s1, char const *s2, size_t n);
int						ft_atoi(char const *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
char					*ft_itoa_base(int value, int base);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
char					*ft_strcnew(size_t size, char c);
void					ft_strdel(char **as);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,\
									char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,\
									size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int value);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_isspace(char c);
int						ft_iswhite(char c);
char					*ft_strndup(char const *s1, size_t n);
char					**ft_split_whitespaces(char *str);

#endif
