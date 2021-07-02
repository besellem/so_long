/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 02:16:30 by besellem          #+#    #+#             */
/*   Updated: 2021/03/08 00:37:25 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** -- INCLUDES --
** System
*/
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

/*
** Mines
*/
# include "ft_printf.h"

/*
** -- DEFINES --
*/
/*
** Useful macros to print a message with a ft_printf or a write for example.
** Does not pass the norm unfortunately. Useful for debugging though.
**
** #define STRINGIFY(x) #x
** #define TOSTRING(x) STRINGIFY(x)
** #define ERR_MSG(s) "\033[1;31m" __FILE__ ":" TOSTRING(__LINE__) ":\033[0m " s
*/

/*
** PI constant and its variables
** Scheme:
**
**        T_PI_2
**          |   T_PI_4
**          | /
** T_PI ---- ---- T_2PI
**          |
**          |
**       T_3PI_2
*/
/*
** PI/4
*/
# define T_PI_4 0.785398163397448309615660845819875721

/*
** PI/2
*/
# define T_PI_2 1.57079632679489661923132169163975144

/*
** PI
*/
# define T_PI 3.14159265358979323846264338327950288

/*
** (3*PI)/2 or PI+(PI/2)
*/
# define T_3PI_2 4.71238898038468967399694520281627774

/*
** 2*PI
*/
# define T_2PI 6.28318530717958623199592693708837032

/*
** 1/PI
*/
# define T_1_PI 0.318309886183790671537767526745028724

/*
** 2/PI
*/
# define T_2_PI 0.636619772367581343075535053490057448

/*
** E constant
*/
# define T_E 2.71828182845904523536028747135266250

/*
** -- TYPEDEFS --
*/
/*
** INTEGER TYPES
** Signed
*/
typedef	signed char			t_int8;
typedef	short				t_int16;
typedef	int					t_int32;
typedef	long long			t_int64;
/*
** Unsigned
*/
typedef	unsigned char		t_uint8;
typedef	unsigned short		t_uint16;
typedef	unsigned int		t_uint32;
typedef	unsigned long long	t_uint64;

/*
** -- PROTOTYPES --
** Number Conversions
*/
int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);
long			ft_atol(const char *str);
long long		ft_atoll(const char *str);
double			ft_atod(const char *str);
long double		ft_atold(const char *str);
long			ft_strtol(const char *str, char **endptr, int base);
long long		ft_strtoll(const char *str, char **endptr, int base);
char			*ft_itoa(int n);
char			*ft_itoa_base(long long n, char *base);

/*
** I/O
*/
void			ft_putc(int c);
void			ft_putc_fd(int c, int fd);
void			ft_putn(int c, int bytes);
void			ft_putn_fd(int fd, int c, int bytes);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putaddr(void *addr);
void			ft_putaddr_fd(void *addr, int fd);
int				get_next_line(int fd, char **line);

/*
** String
*/
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strisall(char *str, int (*f)(int));
int				ft_strisalnum(char *str);
int				ft_strisalpha(char *str);
int				ft_strisascii(char *str);
int				ft_strisdigit(char *str);
int				ft_strisprint(char *str);
int				ft_incharset(const char *charset, int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_stridx(const char *haystack, const char *needle);
size_t			ft_stroc(const char *haystack, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char			*ft_strpbrk(const char *s, const char *charset);
char			*ft_strcasestr(const char *haystack, const char *needle);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
size_t			ft_strnlen(const char *s, size_t maxlen);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);

/*
** String Alloc
*/
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
char			**ft_strsplit(char *str, char *charset);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsjoin(size_t size, char **strs, char *sep);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/*
** Maths
*/
size_t			ft_factorial(size_t nb);
int				ft_find_next_prime(int nb);
int				ft_is_prime(long long nb);
int				ft_nblen(long long n);
int				ft_nblen_base(long long n, int base);
long long		ft_power(long long nb, int power);

/*
** List
*/
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

#endif
