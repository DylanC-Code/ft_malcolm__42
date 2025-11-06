/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:35:54 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 21:40:01 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/permissions.h"

bool checking_perm()
{
    if (getuid() == 0)
        return true;
    ft_error("you must be root.", 1);
    return false;
}