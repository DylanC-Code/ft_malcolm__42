/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_sender.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:13:53 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:44:54 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_SENDER_H
# define ARP_SENDER_H

# include "core/arp_service.h"

bool	send_arp_frame(t_arp_context *ctx);

#endif
