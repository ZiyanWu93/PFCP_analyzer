//
// Created by ziyan on 5/29/22.
//

#ifndef PFCP_REQUEST_ANALYZER_DPDK_H
#define PFCP_REQUEST_ANALYZER_DPDK_H

#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "string.h"


#define __rte_packed __attribute__((__packed__))
#define RTE_ETHER_ADDR_LEN  6 /**< Length of Ethernet address. */
#define PFCP_HEADER_LEN     16
#define PFCP_SEID_LEN       8

#define __rte_aligned(a) __attribute__((__aligned__(a)))

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef uint16_t rte_be16_t; /**< 16-bit big-endian value. */
typedef uint32_t rte_be32_t; /**< 32-bit big-endian value. */
typedef uint64_t rte_be64_t; /**< 64-bit big-endian value. */
typedef uint16_t rte_le16_t; /**< 16-bit little-endian value. */
typedef uint32_t rte_le32_t; /**< 32-bit little-endian value. */
typedef uint64_t rte_le64_t; /**< 64-bit little-endian value. */


struct rte_ether_addr {
    uint8_t addr_bytes[RTE_ETHER_ADDR_LEN]; /**< Addr bytes in tx order */
} __rte_aligned(2);


struct rte_ether_hdr {
    struct rte_ether_addr dst_addr; /**< Destination address. */
    struct rte_ether_addr src_addr; /**< Source address. */
    rte_be16_t ether_type; /**< Frame type. */
} __rte_aligned(2);


struct rte_ipv4_hdr {
    __extension__
    union {
        uint8_t version_ihl;    /**< version and header length */
        struct {
#if RTE_BYTE_ORDER == RTE_LITTLE_ENDIAN
            uint8_t ihl: 4;     /**< header length */
            uint8_t version: 4; /**< version */
#elif RTE_BYTE_ORDER == RTE_BIG_ENDIAN
            uint8_t version:4; /**< version */
            uint8_t ihl:4;     /**< header length */
#endif
        };
    };
    uint8_t type_of_service;    /**< type of service */
    rte_be16_t total_length;    /**< length of packet */
    rte_be16_t packet_id;        /**< packet ID */
    rte_be16_t fragment_offset;    /**< fragmentation offset */
    uint8_t time_to_live;        /**< time to live */
    uint8_t next_proto_id;        /**< protocol ID */
    rte_be16_t hdr_checksum;    /**< header checksum */
    rte_be32_t src_addr;        /**< source address */
    rte_be32_t dst_addr;        /**< destination address */
} __rte_packed;

struct rte_udp_hdr {
    rte_be16_t src_port;    /**< UDP source port. */
    rte_be16_t dst_port;    /**< UDP destination port. */
    rte_be16_t dgram_len;   /**< UDP datagram length */
    rte_be16_t dgram_cksum; /**< UDP datagram checksum */
} __rte_packed;

#endif //PFCP_REQUEST_ANALYZER_DPDK_H
