/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:59 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 17:16:52 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_SERVICE_H
# define ARP_SERVICE_H

# include "domain/config.h"
# include "infrastructure/iface.h"
# include <stdbool.h>

bool	listen_arp_request_and_reply(t_config *config);

#endif
