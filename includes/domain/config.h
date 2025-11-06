/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:13 by dylan             #+#    #+#             */
/*   Updated: 2025/11/05 19:52:11 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <netinet/in.h>

typedef struct config
{
    struct in_addr src_ip;
    struct in_addr tgt_ip;
    uint8_t src_mac[8];
    uint8_t tgt_mac[8];
} t_config;

#endif