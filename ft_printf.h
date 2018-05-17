/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:37:34 by amnishen          #+#    #+#             */
/*   Updated: 2018/02/09 08:37:38 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef	struct	s_printf
{
	long		width;
	long		precision;
	char		*flag_str;
	int			minus_flag;
	int			plus_flag;
	int			space_flag;
	int			sharp_flag;
	int			zero_flag;
	char		size_spec;
	char		type;
	va_list		arg;
	char		*width_str;
	char		prefix;
	int			bytes_printed;
	int			prefix_size;
	char		*prefix_line;
}				t_printf;

void			make_string_to_print(t_printf *pf, char *arg_line);
int				is_printf_spec(char c);
int				is_printf_flag(char c);
int				is_size_spec(char c);
void			make_flag_str(char *format, int *a, t_printf *pf);
int				make_arg(char *format, va_list *ap, int *a);
int				i_hate_this_project(char *format, va_list *ap);
void			manage_flags(t_printf *pf);
void			make_struct_great_again(t_printf *pf);
void			go_for_spec(t_printf *pf);
void			make_width_line(t_printf *pf, char *arg_line);
void			spec_i_d(t_printf *pf);
void			spec_percent(t_printf *pf);
void			spec_c(t_printf *pf);
void			spec_c_lc(t_printf *pf);
int				wchar_size(int uni);
void			make_width_string(t_printf *pf, int	wchar_size);
void			spec_o(t_printf *pf);
void			spec_p(t_printf *pf);
void			spec_s(t_printf *pf);
void			spec_s_ls(t_printf *pf);
void			spec_u(t_printf *pf);
void			spec_x(t_printf *pf);
void			do_some_unicode_pls(int uni);
int				ft_printf(char *format, ...);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
void			ft_strdel(char **as);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
char			*ft_itoa_base(unsigned long n, int base);
int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
char			*ft_toupper_str(char *str);
int				ft_toupper(int c);
void			make_prefix_line(t_printf *pf);
void			make_width_line(t_printf *pf, char *arg_line);
void			go_to_print(t_printf *pf, char *arg_line);
void			manege_prefix_d(t_printf *pf, long x);
char			*dz_size_arg_line(t_printf *pf, size_t x);
char			*oz_size_arg_line(t_printf *pf);
char			*uz_size_arg_line(t_printf *pf);
char			*xz_size_arg_line(t_printf *pf);
void			unicode_write(int *tab, int size);
int				gimme_some_int(char *bits_line, int *y);
int				atoi_binary(char *str);

#endif
