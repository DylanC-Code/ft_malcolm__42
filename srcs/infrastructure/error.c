/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:43:45 by dylan             #+#    #+#             */
/*   Updated: 2025/11/05 19:52:58 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int ft_error(char *msg, int code)
{
    ft_putstr_fd("ft_malcolm: ",  STDERR_FILENO);
    ft_putstr_fd(msg,  STDERR_FILENO);
    ft_putstr_fd("\n",  STDERR_FILENO);
    return code;
}