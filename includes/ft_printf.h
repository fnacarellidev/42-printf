/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:07:53 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/04 17:11:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_DIGITS_LOWCASE "0123456789abcdef"
# define HEX_DIGITS_UPPERCASE "0123456789ABCDEF"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(char *str);
int		has_repeated_chars(char *str);
int		ft_putnbr_base(long long nbr, char *base);
int		ft_puthex(long long x, char uppercase);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_percent_handler(char c, va_list ptr);
int		ft_put_address(unsigned long int nbr);

#endif
