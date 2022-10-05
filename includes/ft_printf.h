/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:07:53 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/05 18:32:22 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_DIGITS_LOWCASE "0123456789abcdef"
# define HEX_DIGITS_UPPERCASE "0123456789ABCDEF"
# define DECIMAL_DIGITS "0123456789"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(char *str);
int		ft_putnbr_base(long long nbr, char *base);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_puthex(unsigned long long nbr, char *base);
int		ft_percent_handler(char c, va_list ptr);
int		ft_put_address(unsigned long long nbr);
int		ft_printf(const char *str, ...);

#endif
