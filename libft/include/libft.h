/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:23:36 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/18 16:04:51 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "included_ext_libs.h"
# include "macros.h"

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_list_dc
{
	void				*content;
	struct s_list_dc	*next;
	struct s_list_dc	*prev;
}						t_list_dc;

typedef struct s_base_info
{
	char				*base;
	size_t				base_len;
}						t_base_info;

/* ascci char checks n manip */

int						ft_isprint(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isalpha(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isspace(char c);

/* str search n compare */

size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
ssize_t					ft_str_chr_index(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
int						ft_str_cont_duplic(const char *str);
int						ft_str_cont_chars(const char *str, const char *set);

/* str manip */

size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strdup(const char *s);
char					*ft_str_n_dup(const char *s, int n);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_str_n_join(char const *s1, char const *s2, int n);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));

/* split */

int						malloc_error_free(char **res, size_t i_num_substr,
							size_t substr_len);
char					**ft_split(char const *s, char c);
char					**ft_split_str(char const *s, char const *split_at);

/* mem stuff */

void					*ft_memset(void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
void					*ft_bzero(void *s, size_t n);

/* linked lists */

t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstadd_back(t_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

/* double circular linked list */

t_list_dc				*dc_lst_new(void *content);
void					dc_lst_print_whole_str(t_list_dc *lst_ptr);
void					dc_lst_print_one_str(void *lst_ptr_void);
void					dc_lst_add_back(t_list_dc **lst, t_list_dc *new);
void					dc_lst_add_front(t_list_dc **lst, t_list_dc *new);
int						dc_lst_size(t_list_dc *lst);
void					dc_lst_clear(t_list_dc **lst, void (*del)(void *));
void					dc_lst_del_one(t_list_dc *lst, void (*del)(void *));
void					dc_lst_iter_node(t_list_dc *lst, void (*f)(void *));
void					dc_lst_iter_content(t_list_dc *lst, void (*f)(void *));
t_list_dc				*dc_lst_map(t_list_dc *lst, void *(*f)(void *),
							void (*del)(void *));
int						dc_lst_exactly_one(t_list_dc *lst_ptr);

/* output */

void					ft_putchar_fd(char c, int fd);
size_t					ft_putchar_fd_len(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
size_t	ft_putstr_fd_len(char *s,
						int fd);
size_t					ft_putstr_fd_len_only_print(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
size_t					ft_putnbr_base_fd_l(int fd, long nbr, const char *base);
size_t					ft_putnbr_base_fd_ul(int fd, unsigned long nbr,
							const char *base);
size_t	ft_putnbr_base_check(const char *base,
							t_base_info *base_info);

/* atoi itoa */

int						ft_atoi(const char *nptr);
ssize_t					ft_atoi_base_l(const char *nptr, const char *base);
char					*ft_itoa(int n);

/* int arr */

size_t					ft_arr_set_int(int *arr, size_t size, int num);
int						int_arr_int_index(int *arr, int search, int arr_len);
void					print_int_arr(int *arr, int num);

/* string array */
size_t					ft_arr_len_char(char **arr);
char					**ft_arr_cpy_char(char **arr, int num);
void					free_str_arr_null(char **str_arr);
void					free_str_arr(char **str_arr, int num);
void					print_str_arr_null(char **arr);
void					print_str_arr(char **arr, int num);

#endif