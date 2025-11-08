/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:59 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:42 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_SERVICE_H
# define ARP_SERVICE_H

# include "domain/arp/arp_frame.h"
# include "domain/config.h"
# include "infrastructure/iface.h"
# include <stdbool.h>

typedef struct s_arp_context
{
	t_config		*config;
	t_iface			*iface;
	t_arp_frame	arp_pkt;
}					t_arp_context;

bool				listen_arp_request_and_reply(t_config *config);

#endif
