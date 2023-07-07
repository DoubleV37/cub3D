/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:21:46 by jduval            #+#    #+#             */
/*   Updated: 2023/07/07 13:10:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*--------LIBFT------*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

void		ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_strcspn(char const *str, char const *reject);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_array_len(char **array);
void		ft_free_array(char **array);

void		ft_putchar_fd(int fd, char c);
void		ft_putstr_fd(int fd, char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		ft_lstadd_front(t_list **lst, t_list *node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *node);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);

int			ft_atoi(const char *nptr);
int			ft_atoi_base(char *str, int str_base);
char		*ft_itoa(int n);
char		**ft_split_char(char *s, char c);
char		**ft_split_str(const char *s, const char *delim);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

/*-------OLD_GNL-------*/

char		*ft_strjoin_gnl(char *s1, char *s2);
int			ft_flag(char *buffer);
void		ft_move(char **buffer, int len);
int			ft_read_for(char **buffer, int fd);
char		*get_next_line(int fd);

/*-------NEW_GNL-------*/

char		*ft_gnl(int fd);

/*-------PRINTF-------*/

int			ft_printf(const char *format, ...);
int			ft_putchar_printf(char c, int fd);
int			ft_putstr_printf(char *s, int fd);
int			ft_nbrlen(long unsigned int nbr, int base);
int			ft_prep(long int nbr, int fd, int len, int base);
int			ft_print_p(long unsigned nbr, int fd, int len);
int			ft_putnbr_hex(unsigned int nbr, char c, int fd, int len);

#endif
