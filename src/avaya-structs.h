/* avaya-structs.h */
/* contains tlv structures for various fabric attach functionality */
#define TLV_OUT_SIZE 3

struct lldpd_avaya_element_tlv { 
       	unsigned short type:4;
       	unsigned short mgmt_vlan:12;
};

#define lldpd_avaya_ELEMENT_TLV_BASE_LEN  6

struct lldpd_avaya_isid_vlan_map_data {
       	unsigned short status:4;
       	unsigned short vlan:12;
       	u_int8_t  isid[3];
};

struct lldpd_avaya_isid_vlan_maps_tlv { 
	TAILQ_ENTRY(lldpd_avaya_isid_vlan_maps_tlv) m_entries;
	u_int8_t  msg_auth_digest[20];
	struct lldpd_avaya_isid_vlan_map_data isid_vlan_data;
};

#define AVAYA_FA_ISID_VLAN_ASGNS_TLV_COMN_LEN  4
#define AVAYA_FA_ISID_VLAN_ASGNS_TLV_COMP_LEN  5
#define AVAYA_FA_ISID_VLAN_ASGNS_TLV_BASE_LEN  36
