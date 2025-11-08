/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:35:54 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 23:17:39 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/log/logger.h"
#include "infrastructure/permissions.h"

/// @brief Checks if the program is running with root permissions
/// @param void
/// @return true if root, false otherwise
bool	checking_perm(void)
{
	if (getuid() == 0)
		return (true);
	log_error("You must be root.");
	return (false);
}
