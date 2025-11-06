/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_service.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:59 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 21:56:04 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARP_SERVICE_H__
#define __ARP_SERVICE_H__

#include <stdbool.h>

#include "domain/config.h"
#include "infrastructure/iface.h"

bool listen_arp_request_and_reply(t_config *config);

#endif