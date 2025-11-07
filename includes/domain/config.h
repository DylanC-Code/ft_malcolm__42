/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:13 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 17:11:11 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "domain/mac.h"
# include <netinet/in.h>
# include <stdbool.h>

typedef struct config
{
	struct in_addr	src_ip;
	struct in_addr	tgt_ip;
	t_mac			src_mac;
	t_mac			tgt_mac;
	bool			once;
}					t_config;

#endif
