//
// Created by ziyan on 5/29/22.
//

#include "n4_pfcp_handler.h"
#include "pfcp_message.h"
#include "pfcp_types.h"
#include "updk/rule_far.h"


int _ConvertCreateFARTlvToRule(UpfFAR *upfFar, CreateFAR *createFar) {
//    UTLT_Assert(upfFar && createFar, return STATUS_ERROR,
//            "UpfFAR or CreateFAR pointer should not be NULL");

    char ipStr[INET6_ADDRSTRLEN];

    if (createFar->fARID.presence) {
        upfFar->flags.farId = 1;
        upfFar->farId = ntohl(*((uint32_t *) createFar->fARID.value));
        printf("FAR ID: %u\n", upfFar->farId);
    }

    if (createFar->applyAction.presence) {
        upfFar->flags.applyAction = 1;
        upfFar->applyAction = *((uint8_t *) (createFar->applyAction.value));
//        UTLT_Debug("FAR Apply Action: %u", upfFar->applyAction);
        printf("FAR Apply Action: %u\n", upfFar->applyAction);
    }

    if (createFar->forwardingParameters.presence) {
        upfFar->flags.forwardingParameters = 1;
        ForwardingParameters *forwardingParameters = &createFar->forwardingParameters;
        UPDK_ForwardingParameters *updkForwardingParameters = &upfFar->forwardingParameters;

        if (forwardingParameters->destinationInterface.presence) {
            updkForwardingParameters->flags.destinationInterface = 1;
            updkForwardingParameters->destinationInterface = *((uint8_t *) (createFar->forwardingParameters.destinationInterface.value));
            printf("Forwarding Parameters Destination Interface: %u\n", updkForwardingParameters->destinationInterface);
        }

        if (forwardingParameters->networkInstance.presence) {
            updkForwardingParameters->flags.networkInstance = 1;
//            UTLT_Assert(forwardingParameters->networkInstance.len < sizeof(updkForwardingParameters->networkInstance),return STATUS_ERROR, "Need more space to store Network Instance in FAR");
            strncpy(updkForwardingParameters->networkInstance, forwardingParameters->networkInstance.value,
                    forwardingParameters->networkInstance.len);
            printf("Forwarding Parameters Network Instance: %u\n", updkForwardingParameters->destinationInterface);
        }

        if (forwardingParameters->outerHeaderCreation.presence) {
            updkForwardingParameters->flags.outerHeaderCreation = 1;
            PfcpOuterHdr *outerHdr = (PfcpOuterHdr *) (forwardingParameters->outerHeaderCreation.value);
            UPDK_OuterHeaderCreation *updkOuterHeaderCreation = &updkForwardingParameters->outerHeaderCreation;

            updkOuterHeaderCreation->description = *((uint8_t *) outerHdr);
            printf("Outer Header Creation Description: %u\n", updkOuterHeaderCreation->description);

            if (outerHdr->gtpuIpv4 || outerHdr->gtpuIpv6) {
                updkOuterHeaderCreation->teid = ntohl(outerHdr->teid);
                printf("Outer Header Creation TEID: %u\n", updkOuterHeaderCreation->teid);
            }

            if (outerHdr->udpIpv4 || outerHdr->gtpuIpv4) {
                updkOuterHeaderCreation->ipv4 = outerHdr->addr4;
                inet_ntop(AF_INET, &updkOuterHeaderCreation->ipv4, ipStr, INET_ADDRSTRLEN);
                printf("Outer Header Creation IPv4: %s\n", ipStr);

                if (!outerHdr->gtpuIpv4) {
                    updkOuterHeaderCreation->port = ntohs(outerHdr->port);
//                    UTLT_Debug("Outer Header Creation Port: %u", updkOuterHeaderCreation->port);
                }
            }

            if (outerHdr->udpIpv6 || outerHdr->gtpuIpv6) {
                updkOuterHeaderCreation->ipv6 = outerHdr->addr6;
                inet_ntop(AF_INET6, &updkOuterHeaderCreation->ipv6, ipStr, INET6_ADDRSTRLEN);
                printf("Outer Header Creation IPv6: %s\n", ipStr);

                if (!outerHdr->gtpuIpv6) {
                    updkOuterHeaderCreation->port = ntohs(outerHdr->port);
                    printf("Outer Header Creation Port: %u\n", updkOuterHeaderCreation->port);
                }
            }
        }

        if (forwardingParameters->forwardingPolicy.presence) {
            updkForwardingParameters->flags.forwardingPolicy = 1;
            uint8_t *forwardingPolicy = forwardingParameters->forwardingPolicy.value;
            UPDK_ForwardingPolicy *updkForwardingPolicy = &updkForwardingParameters->forwardingPolicy;

            updkForwardingPolicy->forwardingPolicyIdentifierLength = forwardingPolicy[0];
//            UTLT_Assert(forwardingPolicy[0] < sizeof(updkForwardingPolicy->forwardingPolicyIdentifier), return STATUS_ERROR, "Forwarding Policy Identifier is too long");
            memcpy(updkForwardingPolicy->forwardingPolicyIdentifier, &forwardingPolicy[1], forwardingPolicy[0]);
            updkForwardingPolicy->forwardingPolicyIdentifier[forwardingPolicy[0]] = 0;
        }
    }

    return STATUS_OK;
}



Status _ConvertCreatePDRTlvToRule(UpfPDR *upfPdr, CreatePDR *createPdr) {
//    UTLT_Assert(upfPdr && createPdr, return STATUS_ERROR,
//                "UpfPDR or CreatePDR pointer should not be NULL");

    char ipStr[INET6_ADDRSTRLEN];
    struct in_addr *ipv4Ptr;
    struct in6_addr *ipv6Ptr;

    if (createPdr->pDRID.presence) {
        upfPdr->flags.pdrId = 1;
        upfPdr->pdrId = ntohs(*((uint16_t *)createPdr->pDRID.value));
        UTLT_Debug("PDR ID: %u", upfPdr->pdrId);
    }

    if (createPdr->precedence.presence) {
        upfPdr->flags.precedence = 1;
        upfPdr->precedence = ntohl(*((uint32_t *)createPdr->precedence.value));
        UTLT_Debug("PDR ID: %u", upfPdr->precedence);
    }

    if (createPdr->pDI.presence) {
        upfPdr->flags.pdi = 1;
        PDI *pdi = &createPdr->pDI;
        UPDK_PDI *updkPdi = &upfPdr->pdi;

        if (pdi->sourceInterface.presence) {
            updkPdi->flags.sourceInterface = 1;
            updkPdi->sourceInterface = *((uint8_t *)(pdi->sourceInterface.value));
            UTLT_Debug("PDI Source Interface: %u", updkPdi->sourceInterface);
        }

        if (pdi->localFTEID.presence) {
            updkPdi->flags.fTeid = 1;
            UPDK_FTEID *updkFTeid = &updkPdi->fTeid;
            PfcpFTeid *fTeid = (PfcpFTeid *)createPdr->pDI.localFTEID.value;

            // Copy flags in F-TEID
            memcpy(updkFTeid, fTeid, sizeof(uint8_t));

            updkFTeid->teid = ntohl(fTeid->teid);
            UTLT_Debug("F-TEID TEID: %u", updkFTeid->teid);

            if (fTeid->v4 && fTeid->v6) {
                ipv4Ptr = &fTeid->dualStack.addr4;
                ipv6Ptr = &fTeid->dualStack.addr6;
            } else {
                ipv4Ptr = &fTeid->addr4;
                ipv6Ptr = &fTeid->addr6;
            }

            if (fTeid->v4) {
                updkFTeid->ipv4 = *ipv4Ptr;
                inet_ntop(AF_INET, &updkFTeid->ipv4, ipStr, INET_ADDRSTRLEN);
                UTLT_Debug("F-TEID IPv4: %s", ipStr);
            }

            if (fTeid->v6) {
                updkFTeid->ipv6 = *ipv6Ptr;
                inet_ntop(AF_INET6, &updkFTeid->ipv6, ipStr, INET6_ADDRSTRLEN);
                UTLT_Debug("F-TEID IPv6: %s", ipStr);
            }

            if (fTeid->chid) {
                updkFTeid->chooseId = fTeid->chooseId;
                UTLT_Debug("F-TEID Choose ID: %u", updkFTeid->chooseId);
            }
        }

        if (pdi->uEIPAddress.presence) {
            updkPdi->flags.ueIpAddress = 1;
            UPDK_UEIPAddress *updkUeIpAddresss = &updkPdi->ueIpAddress;
            PfcpUeIpAddr *ueIp = (PfcpUeIpAddr*)createPdr->pDI.uEIPAddress.value;

            // Copy flags in UE IP Address
            memcpy(updkUeIpAddresss, ueIp, sizeof(uint8_t));

            if (ueIp->v4 && ueIp->v6) {
                ipv4Ptr = &ueIp->dualStack.addr4;
                ipv6Ptr = &ueIp->dualStack.addr6;
            } else {
                ipv4Ptr = &ueIp->addr4;
                ipv6Ptr = &ueIp->addr6;
            }

            if (ueIp->v4) {
                updkUeIpAddresss->ipv4 = *ipv4Ptr;
                inet_ntop(AF_INET, &updkUeIpAddresss->ipv4, ipStr, INET_ADDRSTRLEN);
                UTLT_Debug("UE IP Address IPv4: %s", ipStr);
            }

            if (ueIp->v6) {
                updkUeIpAddresss->ipv6 = *ipv6Ptr;
                inet_ntop(AF_INET6, &updkUeIpAddresss->ipv6, ipStr, INET6_ADDRSTRLEN);
                UTLT_Debug("UE IP Address IPv6: %s", ipStr);
            }

            if (ueIp->ipv6d) {
                updkUeIpAddresss->ipv6PrefixDelegationBit = ueIp->ipv6PrefixDelegationBit;
                UTLT_Debug("UE IP Address IPv6 Prefix Delegation Bit: %u", ipStr);
            }
        }

        if (pdi->sDFFilter.presence) {
            updkPdi->flags.sdfFilter = 1;
            UPDK_SDFFilter *updkSdfFilter = &updkPdi->sdfFilter;
            PfcpSDFFilterDescription *des = (PfcpSDFFilterDescription*) pdi->sDFFilter.value;

            // Copy flags in UE IP Address
            memcpy(updkSdfFilter, des, sizeof(uint8_t));

            for (size_t idx = 2; idx < createPdr->pDI.sDFFilter.len; /* Do nothing here */) {
                if (des->fd) {
                    // TODO: Need to Check if it is correct
                    updkSdfFilter->lenOfFlowDescription = ntohs(*(uint16_t *) ((uint8_t *) pdi->sDFFilter.value + idx));

                    // TODO: dynamic alloc?
//                    UTLT_Assert(sizeof(updkSdfFilter->flowDescription) > updkSdfFilter->lenOfFlowDescription,
//                                continue, "Need more space to store Flow Description");

                    strncpy(updkSdfFilter->flowDescription, pdi->sDFFilter.value+idx+2,
                            updkSdfFilter->lenOfFlowDescription);

                    idx += 2 + updkSdfFilter->lenOfFlowDescription;

                    UTLT_Debug("SDF Filter Flow Description: %s", updkSdfFilter->flowDescription);
                } else if (des->ttc) {
                    updkSdfFilter->tosTrafficClass = ntohs(*(uint16_t *)((uint8_t *) pdi->sDFFilter.value+idx));
                    idx += 2;

                    UTLT_Debug("SDF Filter ToS Traffic Class: %u", updkSdfFilter->tosTrafficClass);
                } else if (des->spi) {
                    updkSdfFilter->securityParameterIndex = ntohl(*(uint32_t *)((uint8_t *) pdi->sDFFilter.value+idx));
                    idx += 4;

                    UTLT_Debug("SDF Filter Security Parameter Index: %u", updkSdfFilter->securityParameterIndex);
                } else if (des->fl) {
                    memcpy(updkSdfFilter->flowLabel, (uint8_t *) pdi->sDFFilter.value+idx, sizeof(char) * 3);
                    idx += 3;

                    UTLT_Debug("SDF Filter Flow Label: %c%c%c",
                               updkSdfFilter->flowLabel[0], updkSdfFilter->flowLabel[1], updkSdfFilter->flowLabel[2]);
                } else if (des->bid) {
                    updkSdfFilter->sdfFilterId = ntohl(*(uint32_t*)((uint8_t*)createPdr->pDI.sDFFilter.value+idx));
                    UTLT_Debug("SDF Filter SDF Filter Id: %u", updkSdfFilter->sdfFilterId);
                    idx += 4;
                } else {
                    UTLT_Warning("Other tag not implements");
                    idx++;
                }
            }
        }
    }

    if (createPdr->outerHeaderRemoval.presence) {
        upfPdr->flags.outerHeaderRemoval = 1;
        upfPdr->outerHeaderRemoval = *((uint8_t *)(createPdr->outerHeaderRemoval.value));
        UTLT_Debug("PDR Outer Header Removal: %u", upfPdr->outerHeaderRemoval);
    }

    if (createPdr->fARID.presence) {
        upfPdr->flags.farId = 1;
        upfPdr->farId = ntohl(*((uint32_t *)createPdr->fARID.value));
        UTLT_Debug("PDR FAR ID: %u", upfPdr->farId);
    }

    if (createPdr->uRRID.presence) {
        // TODO: Need to handle multiple URR
        /*
        upfPdr->flags.urrId = 1;
        upfPdr->urrId = ntohl(*((uint32_t *)createPdr->uRRID.value));
        UTLT_Debug("PDR URR ID: %u", upfPdr->farId);
        */
        UTLT_Warning("UPF do NOT support URR yet");
    }

    for (int i = 0; i < sizeof(createPdr->qERID) / sizeof(QERID); i++) {
        if (createPdr->qERID[i].presence) {
            upfPdr->flags.qerId = 1;
            upfPdr->qerId[i] = ntohl(*((uint32_t *)createPdr->qERID[i].value));
            UTLT_Debug("PDR QER ID: %u", upfPdr->qerId[i]);
        }
    }

    if (createPdr->activatePredefinedRules.presence) {
        // TODO: Need to support
        UTLT_Warning("UPF do NOT support Activate Predefined Rules yet");
    }

    return STATUS_OK;
}