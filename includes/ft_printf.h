/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:07:53 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/05 19:31:40 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOWCASE "0123456789abcdef"
# define HEX_UPCASE "0123456789ABCDEF"
# define DEC_DIGITS "0123456789"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_putchar(char c);
int				ft_putstr(char *str);
size_t			ft_strlen(char *str);
int				ft_printf(const char *str, ...);
int				ft_put_address(unsigned long long nbr);
static int		ft_percent_handler(char c, va_list ptr);
int				ft_putnbr_base(long long nbr, char *base);
int				ft_puthex(unsigned long long nbr, int use_uppercase);

#endif
