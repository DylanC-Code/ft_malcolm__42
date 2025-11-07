/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:35:54 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 16:42:33 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/permissions.h"

/// @brief Checks if the program is running with root permissions
/// @param void
/// @return true if root, false otherwise
bool	checking_perm(void)
{
	if (getuid() == 0)
		return (true);
	ft_error("you must be root.");
	return (false);
}
