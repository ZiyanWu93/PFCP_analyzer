#include <stdio.h>
#include <bits/types.h>
#include <string.h>

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

#define RTE_BE_TO_CPU_16(be_16_v) \
        (uint16_t) ((((be_16_v) & 0xFF) << 8) | ((be_16_v) >> 8))
#define RTE_CPU_TO_BE_16(cpu_16_v) \
        (uint16_t) ((((cpu_16_v) & 0xFF) << 8) | ((cpu_16_v) >> 8))
// #define RTE_CPU_TO_BE_32(cpu_32_v) \
//         (uint32_t) ((((cpu_32_v) & 0xFFFF) << 24) |
//             ((cpu_32_v) & 0xFFFF) << 24) |
//             ((cpu_32_v) & 0xFFFF) << 24) |
//                       ((cpu_32_v) >> 8))

void hexDump (
        const char * desc,
        const void * addr,
        const int len,
        int perLine
) {
    // Silently ignore silly per-line values.

    if (perLine < 4 || perLine > 64) perLine = 16;

    int i;
    unsigned char buff[perLine+1];
    const unsigned char * pc = (const unsigned char *)addr;

    // Output description if given.

    if (desc != NULL) printf ("%s:\n", desc);

    // Length checks.

    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %d\n", len);
        return;
    }

    // Process every byte in the data.

    for (i = 0; i < len; i++) {
        // Multiple of perLine means new or first line (with line offset).

        if ((i % perLine) == 0) {
            // Only print previous-line ASCII buffer for lines beyond first.

            if (i != 0) printf ("  %s\n", buff);

            // Output the offset of current line.

            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.

        printf (" %02x", pc[i]);

        // And buffer a printable ASCII character for later.

        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) // isprint() may be better.
            buff[i % perLine] = '.';
        else
            buff[i % perLine] = pc[i];
        buff[(i % perLine) + 1] = '\0';
    }

    // Pad out last line if not exactly perLine characters.

    while ((i % perLine) != 0) {
        printf ("   ");
        i++;
    }

    // And print the final ASCII buffer.

    printf ("  %s\n", buff);
}


struct NodeID{
    rte_be16_t type;
    rte_be16_t length;
    rte_be16_t spare:8;
    rte_be16_t address_type:8;
    rte_be32_t ip_address;
} __attribute__ ((packed));

struct Cause{
    rte_be16_t type;
    rte_be16_t length;
    uint8_t cause;
} __attribute__ ((packed));

struct Recovery{
    rte_be16_t type;
    rte_be16_t length;
    rte_be32_t timestamp;
} __attribute__ ((packed));

struct UserPlaneInformation{
    rte_be16_t type;
    rte_be16_t length;

    uint8_t v4:1;
    uint8_t v6:1;
    uint8_t teidri:3;
    uint8_t assoni:1;
    uint8_t assosi:1;
    uint8_t spare:1;

    uint8_t teid;
    uint32_t ipaddress;
    char dnn_name[8];
} __attribute__ ((packed));

struct PFCPAssociationSetupResponse {
    struct NodeID nodeID;
    struct Cause cause;
    struct Recovery recovery;
    struct UserPlaneInformation userplaninformation;
} __attribute__((packed));


// int main(void) {
//   struct PFCPAssociationSetupResponse pfcpassociationsetupresponse;
//   memset(&pfcpassociationsetupresponse, 0, sizeof(struct PFCPAssociationSetupResponse));
//   pfcpassociationsetupresponse.nodeID.type = RTE_CPU_TO_BE_16(60);
//   pfcpassociationsetupresponse.nodeID.length = RTE_CPU_TO_BE_16(5);
//   pfcpassociationsetupresponse.nodeID.spare = 0;
//   pfcpassociationsetupresponse.nodeID.address_type = 0;
//   pfcpassociationsetupresponse.nodeID.ip_address = (0x0800007f);

//   pfcpassociationsetupresponse.cause.type = RTE_CPU_TO_BE_16(19);
//   pfcpassociationsetupresponse.cause.length = RTE_CPU_TO_BE_16(1);
//   pfcpassociationsetupresponse.cause.cause = 1;

//   pfcpassociationsetupresponse.recovery.type = RTE_CPU_TO_BE_16(96);
//   pfcpassociationsetupresponse.recovery.length = RTE_CPU_TO_BE_16(4);
//   pfcpassociationsetupresponse.recovery.timestamp = 0x1b338762;

//   pfcpassociationsetupresponse.userplaninformation.type = RTE_CPU_TO_BE_16(116);
//   pfcpassociationsetupresponse.userplaninformation.length = RTE_CPU_TO_BE_16(15);

//   pfcpassociationsetupresponse.userplaninformation.assoni = 1;
//   pfcpassociationsetupresponse.userplaninformation.teidri = 0x1;
//   pfcpassociationsetupresponse.userplaninformation.v4 =1;

//   pfcpassociationsetupresponse.userplaninformation.teid = 0;
//   pfcpassociationsetupresponse.userplaninformation.ipaddress = (0x6502a8c0);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[0] = (0x08);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[1] = (0x69);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[2] = (0x6e);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[3] = (0x74);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[4] = (0x65);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[5] = (0x72);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[6] = (0x65);
//   pfcpassociationsetupresponse.userplaninformation.dnn_name[7] = (0x74);

//   hexDump("pfcpassociationsetupresponse",&pfcpassociationsetupresponse, sizeof(struct PFCPAssociationSetupResponse),16);
//   return 0;
// }