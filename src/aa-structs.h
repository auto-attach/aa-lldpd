/* aa-structs.h */
/* contains tlv structures for various auto attach functionality */

/* Copyright (c) 2014 Avaya
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LLDP_AA_STRUCTS_H
#define _LLDP_AA_STRUCTS_H

#include <sys/queue.h>

struct lldp_aa_element_system_id {
    u_int8_t       system_mac[6];
    unsigned short conn_type:4;
    unsigned short smlt_id:12;
    u_int8_t       mlt_id[2];
};

struct lldpd_aa_element_tlv { 
    unsigned short                      type:4;
    unsigned short                      mgmt_vlan:12;
    struct lldp_aa_element_system_id system_id;
};

struct lldpd_aa_isid_vlan_map_data {
    unsigned short status:4;
    unsigned short vlan:12;
    u_int8_t       isid[3];
};

struct lldpd_aa_isid_vlan_maps_tlv { 
	TAILQ_ENTRY(lldpd_aa_isid_vlan_maps_tlv) 	m_entries;

	struct 						lldpd_aa_isid_vlan_map_data isid_vlan_data;
};

#endif /* _LLDP_AA_STRUCTS_H */
