/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:31:23 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/04 17:13:56 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char				*ft_strdup(char *src);
size_t				ft_strlen(const char *str);
size_t				ft_strnlen(char const *str, char c);
int					ft_dgt_quntt_i(unsigned int n);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *str, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *str, const char *source, size_t num);
char				*ft_strcat(char *str, const char *source);
char				*ft_strnew(size_t size);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
int					get_next_line(const int fd, char **line);
char				*ft_del_whitespaces(char *str);
size_t				ft_grap_to_whitespaces(char *str);
size_t				ft_grap_to_whitespaces_or_ch(char *str, int ch);
int					ft_isdigit(int c);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *argv);
size_t				ft_atoi_and_qntt_dgt(char *argv, int *ptr_num);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, unsigned int base);
char				*ft_uitoa_base(unsigned int n, unsigned int base);
char				*ft_ulltoa(size_t n);
int					ft_atoi_base(char *str, int base);
void				ft_swap(int *a, int *b);
long long int		ft_degree(int val, int cnt);
void				ft_putstr_error(char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_str_del_newline(char *dest);
void				ft_putchar(char c);
char				*ft_to_upper_c(char *data);
char				*ft_to_lowercase(char *data);
#endif
