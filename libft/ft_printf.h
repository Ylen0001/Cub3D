/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:02:38 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:06:46 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *txt, ...);
int		ft_printf_str(va_list params, size_t *i);
int		ft_printf_int(va_list params, size_t *i, int trigger);
int		ft_printf_char(va_list params, size_t *i);
int		ft_putchar_count(char c, int fd);
int		ft_putstr_count(char *s, int fd);
int		ft_printf_hex(unsigned long long nbr, size_t *i, char c);

#endif