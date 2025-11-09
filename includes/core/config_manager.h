/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:13 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:33:54 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_MANAGER_H
# define CONFIG_MANAGER_H

# include "domain/config.h"

bool	load_and_validate_config(int argc, char **restrict argv,
			t_config *restrict cfg) __attribute__((nonnull));

#endif
