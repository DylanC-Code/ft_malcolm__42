/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_receiver.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:06:28 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 11:07:54 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_RECEIVER_H
# define ARP_RECEIVER_H

# include "core/arp_service.h"
# include <stdbool.h>

bool	receive_arp_packet(t_arp_context *ctx);

#endif
