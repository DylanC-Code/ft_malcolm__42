/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:57:43 by dylan             #+#    #+#             */
/*   Updated: 2025/11/06 14:03:27 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAC_PARSER_H__
#define __MAC_PARSER_H__

#include <stdint.h>
#include <stdbool.h>
#include "domain/mac.h"

typedef enum e_mac_parse_error
{
    MAC_PARSING_SUCCESS = 0,
    INVALID_MAC_LENGTH = 17,
    INVALID_MAC_FORMAT = 18,
    INVALID_MAC_CHAR = 19,
} t_mac_parse_error;

bool parse_str_mac_address(char *src, t_mac *dst);

#endif