#ifndef PFCP_MESSAGE_H
#define PFCP_MESSAGE_H
#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "string.h"
#include "updk/rule_far.h"
#include "updk/rule_pdr.h"
#include "pfcp_types.h"
//#include "utlt_debug.h"
#include "utlt_buff.h"

typedef struct _TlvOctet {
    unsigned long presence;
    uint16_t type;
    uint16_t len;
    void *value;
} __attribute__((packed)) TlvOctet;

typedef struct _IeDescription {
    uint16_t msgType;
    uint16_t msgLen; // msg struct size
    _Bool isTlvObj;
    int numToParse;
    int next[80];
} __attribute__((packed)) IeDescription;


typedef TlvOctet Reserved;
typedef TlvOctet Cause;
typedef TlvOctet SourceInterface;
typedef TlvOctet FTEID;
typedef TlvOctet NetworkInstance;
typedef TlvOctet SDFFilter;
typedef TlvOctet ApplicationID;
typedef TlvOctet GateStatus;
typedef TlvOctet MBR;
typedef TlvOctet GBR;
typedef TlvOctet QERCorrelationID;
typedef TlvOctet Precedence;
typedef TlvOctet TransportLevelMarking;
typedef TlvOctet VolumeThreshold;
typedef TlvOctet TimeThreshold;
typedef TlvOctet MonitoringTime;
typedef TlvOctet SubsequentVolumeThreshold;
typedef TlvOctet SubsequentTimeThreshold;
typedef TlvOctet InactivityDetectionTime;
typedef TlvOctet ReportingTriggers;
typedef TlvOctet RedirectInformation;
typedef TlvOctet ReportType;
typedef TlvOctet OffendingIE;
typedef TlvOctet ForwardingPolicy;
typedef TlvOctet DestinationInterface;
typedef TlvOctet UPFunctionFeatures;
typedef TlvOctet ApplyAction;
typedef TlvOctet DownlinkDataServiceInformation;
typedef TlvOctet DownlinkDataNotificationDelay;
typedef TlvOctet DLBufferingDuration;
typedef TlvOctet DLBufferingSuggestedPacketCount;
typedef TlvOctet PFCPSMReqFlags;
typedef TlvOctet PFCPSRRspFlags;
typedef TlvOctet SequenceNumber;
typedef TlvOctet Metric;
typedef TlvOctet Timer;
typedef TlvOctet PacketDetectionRuleID;
typedef TlvOctet FSEID;
//typedef TlvOctet PFDContext;
typedef TlvOctet NodeID;
typedef TlvOctet PFDContents;
typedef TlvOctet MeasurementMethod;
typedef TlvOctet UsageReportTrigger;
typedef TlvOctet MeasurementPeriod;
typedef TlvOctet FQCSID;
typedef TlvOctet VolumeMeasurement;
typedef TlvOctet DurationMeasurement;
typedef TlvOctet TimeOfFirstPacket;
typedef TlvOctet TimeOfLastPacket;
typedef TlvOctet QuotaHoldingTime;
typedef TlvOctet DroppedDLTrafficThreshold;
typedef TlvOctet VolumeQuota;
typedef TlvOctet TimeQuota;
typedef TlvOctet StartTime;
typedef TlvOctet EndTime;
typedef TlvOctet URRID;
typedef TlvOctet LinkedURRID;
typedef TlvOctet OuterHeaderCreation;
typedef TlvOctet BARID;
typedef TlvOctet CPFunctionFeatures;
typedef TlvOctet UsageInformation;
typedef TlvOctet ApplicationInstanceID;
typedef TlvOctet FlowInformation;
typedef TlvOctet UEIPAddress;
typedef TlvOctet PacketRate;
typedef TlvOctet OuterHeaderRemoval;
typedef TlvOctet RecoveryTimeStamp;
typedef TlvOctet DLFlowLevelMarking;
typedef TlvOctet HeaderEnrichment;
typedef TlvOctet MeasurementInformation;
typedef TlvOctet NodeReportType;
//typedef TlvOctet UserPlanePathFailureReport;
typedef TlvOctet RemoteGTPUPeer;
typedef TlvOctet URSEQN;
typedef TlvOctet ActivatePredefinedRules;
typedef TlvOctet DeactivatePredefinedRules;
typedef TlvOctet FARID;
typedef TlvOctet QERID;
typedef TlvOctet OCIFlags;
typedef TlvOctet GracefulReleasePeriod;
typedef TlvOctet PDNType;
typedef TlvOctet FailedRuleID;
typedef TlvOctet TimeQuotaMechanism;
typedef TlvOctet UserPlaneIPResourceInformation;
typedef TlvOctet UserPlaneInactivityTimer;
typedef TlvOctet Multiplier;
typedef TlvOctet AggregatedURRID;
typedef TlvOctet SubsequentVolumeQuota;
typedef TlvOctet SubsequentTimeQuota;
typedef TlvOctet RQI;
typedef TlvOctet QFI;
typedef TlvOctet QueryURRReference;
typedef TlvOctet AdditionalUsageReportsInformation;
typedef TlvOctet TrafficEndpointID;
typedef TlvOctet MACAddress;
typedef TlvOctet CTAG;
typedef TlvOctet STAG;
typedef TlvOctet Ethertype;
typedef TlvOctet Proxying;
typedef TlvOctet EthernetFilterID;
typedef TlvOctet EthernetFilterProperties;
typedef TlvOctet SuggestedBufferingPacketsCount;
typedef TlvOctet UserID;
typedef TlvOctet EthernetPDUSessionInformation;
typedef TlvOctet MACAddressesDetected;
typedef TlvOctet MACAddressesRemoved;
typedef TlvOctet EthernetInactivityTimer;
typedef TlvOctet EventID;
typedef TlvOctet EventThreshold;
typedef TlvOctet TraceInformation;
typedef TlvOctet FramedRoute;
typedef TlvOctet FramedRouting;
typedef TlvOctet FramedIPv6Route;



typedef struct _HeartbeatRequest {
    unsigned long presence;
    RecoveryTimeStamp recoveryTimeStamp;
} __attribute__((packed)) HeartbeatRequest;

typedef struct _HeartbeatResponse {
    unsigned long presence;
    RecoveryTimeStamp recoveryTimeStamp;
} __attribute__((packed)) HeartbeatResponse;

typedef struct _PFDContext {
    unsigned long presence;
    PFDContents pFDContents;
} __attribute__((packed)) PFDContext;

typedef struct _PFCPPFDManagementResponse {
    unsigned long presence;
    Cause cause;
    OffendingIE offendingIE;
} __attribute__((packed)) PFCPPFDManagementResponse;

typedef struct _PFCPAssociationSetupRequest {
    unsigned long presence;
    NodeID nodeID;
    RecoveryTimeStamp recoveryTimeStamp;
    UPFunctionFeatures uPFunctionFeatures;
    CPFunctionFeatures cPFunctionFeatures;
    UserPlaneIPResourceInformation userPlaneIPResourceInformation;
} __attribute__((packed)) PFCPAssociationSetupRequest;

typedef struct _PFCPAssociationSetupResponse {
    unsigned long presence;
    NodeID nodeID;
    Cause cause;
    RecoveryTimeStamp recoveryTimeStamp;
    UPFunctionFeatures uPFunctionFeatures;
    CPFunctionFeatures cPFunctionFeatures;
    UserPlaneIPResourceInformation userPlaneIPResourceInformation;
} __attribute__((packed)) PFCPAssociationSetupResponse;

typedef struct _PFCPAssociationUpdateResponse {
    unsigned long presence;
    NodeID nodeID;
    Cause cause;
    UPFunctionFeatures uPFunctionFeatures;
    CPFunctionFeatures cPFunctionFeatures;
} __attribute__((packed)) PFCPAssociationUpdateResponse;

typedef struct _PFCPAssociationReleaseRequest {
    unsigned long presence;
    NodeID nodeID;
} __attribute__((packed)) PFCPAssociationReleaseRequest;

typedef struct _PFCPAssociationReleaseResponse {
    unsigned long presence;
    NodeID nodeID;
    Cause cause;
} __attribute__((packed)) PFCPAssociationReleaseResponse;

typedef struct _UserPlanePathFailureReport {
    unsigned long presence;
    RemoteGTPUPeer remoteGTPUPeer;
} __attribute__((packed)) UserPlanePathFailureReport;

typedef struct _PFCPNodeReportRequest {
    unsigned long presence;
    NodeID nodeID;
    NodeReportType nodeReportType;
    UserPlanePathFailureReport userPlanePathFailureReport;
} __attribute__((packed)) PFCPNodeReportRequest;

typedef struct _PFCPNodeReportResponse {
    unsigned long presence;
    NodeID nodeID;
    Cause cause;
    OffendingIE offendingIE;
} __attribute__((packed)) PFCPNodeReportResponse;

typedef struct _PFCPSessionSetDeletionRequest {
    unsigned long presence;
    NodeID nodeID;
    FQCSID sGWCFQCSID;
    FQCSID pGWCFQCSID;
    FQCSID sGWUFQCSID;
    FQCSID pGWUFQCSID;
    FQCSID tWANFQCSID;
    FQCSID ePDGFQCSID;
    FQCSID mMEFQCSID;
} __attribute__((packed)) PFCPSessionSetDeletionRequest;

typedef struct _PFCPSessionSetDeletionResponse {
    unsigned long presence;
    NodeID nodeID;
    Cause cause;
    OffendingIE offendingIE;
} __attribute__((packed)) PFCPSessionSetDeletionResponse;

typedef struct _EthernetPacketFilter {
    unsigned long presence;
    EthernetFilterID ethernetFilterID;
    EthernetFilterProperties ethernetFilterProperties;
    MACAddress mACAddress;
    Ethertype ethertype;
    CTAG cTAG;
    STAG sTAG;
    SDFFilter sDFFilter;
} __attribute__((packed)) EthernetPacketFilter;

typedef struct _ForwardingParameters {
    unsigned long presence;
    DestinationInterface destinationInterface;
    NetworkInstance networkInstance;
    RedirectInformation redirectInformation;
    OuterHeaderCreation outerHeaderCreation;
    TransportLevelMarking transportLevelMarking;
    ForwardingPolicy forwardingPolicy;
    HeaderEnrichment headerEnrichment;
    TrafficEndpointID linkedTrafficEndpointID;
    Proxying proxying;
} __attribute__((packed)) ForwardingParameters;

typedef struct _DuplicatingParameters {
    unsigned long presence;
    DestinationInterface destinationInterface;
    OuterHeaderCreation outerHeaderCreation;
    TransportLevelMarking transportLevelMarking;
    ForwardingPolicy forwardingPolicy;
} __attribute__((packed)) DuplicatingParameters;

typedef struct _AggregatedURRs {
    unsigned long presence;
    AggregatedURRID aggregatedURRID;
    Multiplier multiplier;
} __attribute__((packed)) AggregatedURRs;

typedef struct _AdditionalMonitoringTime {
    unsigned long presence;
    MonitoringTime monitoringTime;
    SubsequentVolumeThreshold subsequentVolumeThreshold;
    SubsequentTimeThreshold subsequentTimeThreshold;
    SubsequentVolumeQuota subsequentVolumeQuota;
    SubsequentTimeQuota subsequentTimeQuota;
} __attribute__((packed)) AdditionalMonitoringTime;

typedef struct _EventInformation {
    unsigned long presence;
    EventID eventID;
    EventThreshold eventThreshold;
} __attribute__((packed)) EventInformation;

typedef struct _CreateQER {
    unsigned long presence;
    QERID qERID;
    QERCorrelationID qERCorrelationID;
    GateStatus gateStatus;
    MBR maximumBitrate;
    GBR guaranteedBitrate;
    PacketRate packetRate;
    DLFlowLevelMarking dLFlowLevelMarking;
    QFI qoSFlowIdentifier;
    RQI reflectiveQoS;
} __attribute__((packed)) CreateQER;

typedef struct _CreateBAR {
    unsigned long presence;
    BARID bARID;
    DownlinkDataNotificationDelay downlinkDataNotificationDelay;
    SuggestedBufferingPacketsCount suggestedBufferingPacketsCount;
} __attribute__((packed)) CreateBAR;

typedef struct _CreateTrafficEndpoint {
    unsigned long presence;
    TrafficEndpointID trafficEndpointID;
    FTEID localFTEID;
    NetworkInstance networkInstance;
    UEIPAddress uEIPAddress;
    EthernetPDUSessionInformation ethernetPDUSessionInformation;
    FramedRoute framedRoute;
    FramedRouting framedRouting;
    FramedIPv6Route framedIPv6Route;
} __attribute__((packed)) CreateTrafficEndpoint;

typedef struct _LoadControlInformation {
    unsigned long presence;
    SequenceNumber loadControlSequenceNumber;
    Metric loadMetric;
} __attribute__((packed)) LoadControlInformation;

typedef struct _OverloadControlInformation {
    unsigned long presence;
    SequenceNumber overloadControlSequenceNumber;
    Metric overloadReductionMetric;
    Timer periodOfValidity;
    OCIFlags overloadControlInformationFlags;
} __attribute__((packed)) OverloadControlInformation;

typedef struct _CreatedTrafficEndpoint {
    unsigned long presence;
    TrafficEndpointID trafficEndpointID;
    FTEID localFTEID;
} __attribute__((packed)) CreatedTrafficEndpoint;

typedef struct _UpdateForwardingParameters {
    unsigned long presence;
    DestinationInterface destinationInterface;
    NetworkInstance networkInstance;
    RedirectInformation redirectInformation;
    OuterHeaderCreation outerHeaderCreation;
    TransportLevelMarking transportLevelMarking;
    ForwardingPolicy forwardingPolicy;
    HeaderEnrichment headerEnrichment;
    PFCPSMReqFlags pFCPSMReqFlags;
    TrafficEndpointID linkedTrafficEndpointID;
} __attribute__((packed)) UpdateForwardingParameters;

typedef struct _UpdateDuplicatingParameters {
    unsigned long presence;
    DestinationInterface destinationInterface;
    OuterHeaderCreation outerHeaderCreation;
    TransportLevelMarking transportLevelMarking;
    ForwardingPolicy forwardingPolicy;
} __attribute__((packed)) UpdateDuplicatingParameters;

typedef struct _UpdateURR {
    unsigned long presence;
    URRID uRRID;
    MeasurementMethod measurementMethod;
    ReportingTriggers reportingTriggers;
    MeasurementPeriod measurementPeriod;
    VolumeThreshold volumeThreshold;
    VolumeQuota volumeQuota;
    TimeThreshold timeThreshold;
    TimeQuota timeQuota;
    QuotaHoldingTime quotaHoldingTime;
    DroppedDLTrafficThreshold droppedDLTrafficThreshold;
    MonitoringTime monitoringTime;
    EventInformation eventInformation;
    SubsequentVolumeThreshold subsequentVolumeThreshold;
    SubsequentTimeThreshold subsequentTimeThreshold;
    SubsequentVolumeQuota subsequentVolumeQuota;
    SubsequentTimeQuota subsequentTimeQuota;
    InactivityDetectionTime inactivityDetectionTime;
    LinkedURRID linkedURRID;
    MeasurementInformation measurementInformation;
    TimeQuotaMechanism timeQuotaMechanism;
    AggregatedURRs aggregatedURRs;
    FARID fARIDForQuotaAction;
    EthernetInactivityTimer ethernetInactivityTimer;
    AdditionalMonitoringTime additionalMonitoringTime;
} __attribute__((packed)) UpdateURR;

typedef struct _UpdateQER {
    unsigned long presence;
    QERID qERID;
    QERCorrelationID qERCorrelationID;
    GateStatus gateStatus;
    MBR maximumBitrate;
    GBR guaranteedBitrate;
    PacketRate packetRate;
    DLFlowLevelMarking dLFlowLevelMarking;
    QFI qoSFlowIdentifier;
    RQI reflectiveQoS;
} __attribute__((packed)) UpdateQER;

typedef struct _RemoveFAR {
    unsigned long presence;
    FARID fARID;
} __attribute__((packed)) RemoveFAR;

typedef struct _RemoveURR {
    unsigned long presence;
    URRID uRRID;
} __attribute__((packed)) RemoveURR;

typedef struct _RemoveQER {
    unsigned long presence;
    QERID qERID;
} __attribute__((packed)) RemoveQER;

typedef struct _QueryURR {
    unsigned long presence;
    URRID uRRID;
} __attribute__((packed)) QueryURR;

typedef struct _UpdateBARPFCPSessionModificationRequest {
    unsigned long presence;
    BARID bARID;
    DownlinkDataNotificationDelay downlinkDataNotificationDelay;
    SuggestedBufferingPacketsCount suggestedBufferingPacketsCount;
} __attribute__((packed)) UpdateBARPFCPSessionModificationRequest;

typedef struct _RemoveBAR {
    unsigned long presence;
    BARID bARID;
} __attribute__((packed)) RemoveBAR;

typedef struct _UpdateTrafficEndpoint {
    unsigned long presence;
    TrafficEndpointID trafficEndpointID;
    FTEID localFTEID;
    NetworkInstance networkInstance;
    UEIPAddress uEIPAddress;
    FramedRoute framedRoute;
    FramedRouting framedRouting;
    FramedIPv6Route framedIPv6Route;
} __attribute__((packed)) UpdateTrafficEndpoint;

typedef struct _RemoveTrafficEndpoint {
    unsigned long presence;
    TrafficEndpointID trafficEndpointID;
} __attribute__((packed)) RemoveTrafficEndpoint;

typedef struct _ApplicationDetectionInformation {
    unsigned long presence;
    ApplicationID applicationID;
    ApplicationInstanceID applicationInstanceID;
    FlowInformation flowInformation;
} __attribute__((packed)) ApplicationDetectionInformation;

typedef struct _EventReporting {
    unsigned long presence;
    EventID eventID;
} __attribute__((packed)) EventReporting;

typedef struct _EthernetTrafficInformation {
    unsigned long presence;
    MACAddressesDetected mACAddressesDetected;
    MACAddressesRemoved mACAddressesRemoved;
} __attribute__((packed)) EthernetTrafficInformation;

typedef struct _ErrorIndicationReport {
    unsigned long presence;
    FTEID remoteFTEID;
} __attribute__((packed)) ErrorIndicationReport;

typedef struct _UpdateBARPFCPSessionReportResponse {
    unsigned long presence;
    BARID bARID;
    DownlinkDataNotificationDelay downlinkDataNotificationDelay;
    DLBufferingDuration dLBufferingDuration;
    DLBufferingSuggestedPacketCount dLBufferingSuggestedPacketCount;
    SuggestedBufferingPacketsCount suggestedBufferingPacketsCount;
} __attribute__((packed)) UpdateBARPFCPSessionReportResponse;

typedef struct _ApplicationIDsPFDs {
    unsigned long presence;
    ApplicationID applicationID;
    PFDContext pFD;
} __attribute__((packed)) ApplicationIDsPFDs;

typedef struct _PFCPAssociationUpdateRequest {
    unsigned long presence;
    NodeID nodeID;
    UPFunctionFeatures uPFunctionFeatures;
    CPFunctionFeatures cPFunctionFeatures;
    PFCPAssociationReleaseRequest pFCPAssociationReleaseRequest;
    GracefulReleasePeriod gracefulReleasePeriod;
    UserPlaneIPResourceInformation userPlaneIPResourceInformation;
} __attribute__((packed)) PFCPAssociationUpdateRequest;

typedef struct _PDI {
    unsigned long presence;
    SourceInterface sourceInterface;
    FTEID localFTEID;
    NetworkInstance networkInstance;
    UEIPAddress uEIPAddress;
    TrafficEndpointID trafficEndpointID;
    SDFFilter sDFFilter;
    ApplicationID applicationID;
    EthernetPDUSessionInformation ethernetPDUSessionInformation;
    EthernetPacketFilter ethernetPacketFilter;
    QFI qFI;
    FramedRoute framedRoute;
    FramedRouting framedRouting;
    FramedIPv6Route framedIPv6Route;
} __attribute__((packed)) PDI;

typedef struct _CreateFAR {
    unsigned long presence;
    FARID fARID;
    ApplyAction applyAction;
    ForwardingParameters forwardingParameters;
    DuplicatingParameters duplicatingParameters;
    BARID bARID;
} __attribute__((packed)) CreateFAR;

typedef struct _CreateURR {
    unsigned long presence;
    URRID uRRID;
    MeasurementMethod measurementMethod;
    ReportingTriggers reportingTriggers;
    MeasurementPeriod measurementPeriod;
    VolumeThreshold volumeThreshold;
    VolumeQuota volumeQuota;
    TimeThreshold timeThreshold;
    TimeQuota timeQuota;
    QuotaHoldingTime quotaHoldingTime;
    DroppedDLTrafficThreshold droppedDLTrafficThreshold;
    MonitoringTime monitoringTime;
    EventInformation eventInformation;
    SubsequentVolumeThreshold subsequentVolumeThreshold;
    SubsequentTimeThreshold subsequentTimeThreshold;
    SubsequentVolumeQuota subsequentVolumeQuota;
    SubsequentTimeQuota subsequentTimeQuota;
    InactivityDetectionTime inactivityDetectionTime;
    LinkedURRID linkedURRID;
    MeasurementInformation measurementInformation;
    TimeQuotaMechanism timeQuotaMechanism;
    AggregatedURRs aggregatedURRs;
    FARID fARIDForQuotaAction;
    EthernetInactivityTimer ethernetInactivityTimer;
    AdditionalMonitoringTime additionalMonitoringTime;
} __attribute__((packed)) CreateURR;

typedef struct _CreatedPDR {
    unsigned long presence;
    PacketDetectionRuleID pDRID;
    FTEID localFTEID;
} __attribute__((packed)) CreatedPDR;

typedef struct _UpdatePDR {
    unsigned long presence;
    PacketDetectionRuleID pDRID;
    OuterHeaderRemoval outerHeaderRemoval;
    Precedence precedence;
    PDI pDI;
    FARID fARID;
    URRID uRRID;
    QERID qERID[4];
    ActivatePredefinedRules activatePredefinedRules;
    DeactivatePredefinedRules deactivatePredefinedRules;
} __attribute__((packed)) UpdatePDR;

typedef struct _UpdateFAR {
    unsigned long presence;
    FARID fARID;
    ApplyAction applyAction;
    UpdateForwardingParameters updateForwardingParameters;
    UpdateDuplicatingParameters updateDuplicatingParameters;
    BARID bARID;
} __attribute__((packed)) UpdateFAR;

typedef struct _RemovePDR {
    unsigned long presence;
    PacketDetectionRuleID pDRID;
} __attribute__((packed)) RemovePDR;

typedef struct _UsageReportPFCPSessionModificationResponse {
    unsigned long presence;
    URRID uRRID;
    URSEQN uRSEQN;
    UsageReportTrigger usageReportTrigger;
    StartTime startTime;
    EndTime endTime;
    VolumeMeasurement volumeMeasurement;
    DurationMeasurement durationMeasurement;
    TimeOfFirstPacket timeOfFirstPacket;
    TimeOfLastPacket timeOfLastPacket;
    UsageInformation usageInformation;
    QueryURRReference queryURRReference;
    EthernetTrafficInformation ethernetTrafficInformation;
} __attribute__((packed)) UsageReportPFCPSessionModificationResponse;

typedef struct _PFCPSessionDeletionRequest {
    unsigned long presence;
} __attribute__((packed)) PFCPSessionDeletionRequest;

typedef struct _UsageReportPFCPSessionDeletionResponse {
    unsigned long presence;
    URRID uRRID;
    URSEQN uRSEQN;
    UsageReportTrigger usageReportTrigger;
    StartTime startTime;
    EndTime endTime;
    VolumeMeasurement volumeMeasurement;
    DurationMeasurement durationMeasurement;
    TimeOfFirstPacket timeOfFirstPacket;
    TimeOfLastPacket timeOfLastPacket;
    UsageInformation usageInformation;
    EthernetTrafficInformation ethernetTrafficInformation;
} __attribute__((packed)) UsageReportPFCPSessionDeletionResponse;

typedef struct _DownlinkDataReport {
    unsigned long presence;
    PacketDetectionRuleID pDRID;
    DownlinkDataServiceInformation downlinkDataServiceInformation;
} __attribute__((packed)) DownlinkDataReport;

typedef struct _UsageReportPFCPSessionReportRequest {
    unsigned long presence;
    URRID uRRID;
    URSEQN uRSEQN;
    UsageReportTrigger usageReportTrigger;
    StartTime startTime;
    EndTime endTime;
    VolumeMeasurement volumeMeasurement;
    DurationMeasurement durationMeasurement;
    ApplicationDetectionInformation applicationDetectionInformation;
    UEIPAddress uEIPAddress;
    NetworkInstance networkInstance;
    TimeOfFirstPacket timeOfFirstPacket;
    TimeOfLastPacket timeOfLastPacket;
    UsageInformation usageInformation;
    QueryURRReference queryURRReference;
    EventReporting eventReporting;
    EthernetTrafficInformation ethernetTrafficInformation;
} __attribute__((packed)) UsageReportPFCPSessionReportRequest;

typedef struct _PFCPSessionReportResponse {
    unsigned long presence;
    Cause cause;
    OffendingIE offendingIE;
    UpdateBARPFCPSessionReportResponse updateBAR;
    PFCPSRRspFlags sxSRRspFlags;
} __attribute__((packed)) PFCPSessionReportResponse;

typedef struct _PFCPPFDManagementRequest {
    unsigned long presence;
    ApplicationIDsPFDs applicationIDsPFDs;
} __attribute__((packed)) PFCPPFDManagementRequest;

typedef struct _CreatePDR {
    unsigned long presence;
    PacketDetectionRuleID pDRID;
    Precedence precedence;
    PDI pDI;
    OuterHeaderRemoval outerHeaderRemoval;
    FARID fARID;
    URRID uRRID;
    QERID qERID[4];
    ActivatePredefinedRules activatePredefinedRules;
} __attribute__((packed)) CreatePDR;

typedef struct _PFCPSessionEstablishmentResponse {
    unsigned long presence;
    NodeID nodeID;
    Cause cause;
    OffendingIE offendingIE;
    FSEID uPFSEID;
    CreatedPDR createdPDR;
    LoadControlInformation loadControlInformation;
    OverloadControlInformation overloadControlInformation;
    FQCSID sGWUFQCSID;
    FQCSID pGWUFQCSID;
    FailedRuleID failedRuleID;
    CreatedTrafficEndpoint createdTrafficEndpoint;
} __attribute__((packed)) PFCPSessionEstablishmentResponse;

typedef struct _PFCPSessionModificationRequest {
    unsigned long presence;
    FSEID cPFSEID;
    RemovePDR removePDR[4];
    RemoveFAR removeFAR[4];
    RemoveURR removeURR;
    RemoveQER removeQER[4];
    RemoveBAR removeBAR;
    RemoveTrafficEndpoint removeTrafficEndpoint;
    CreatePDR createPDR[4];
    CreateFAR createFAR[4];
    CreateURR createURR;
    CreateQER createQER[4];
    CreateBAR createBAR;
    CreateTrafficEndpoint createTrafficEndpoint;
    UpdatePDR updatePDR[4];
    UpdateFAR updateFAR[4];
    UpdateURR updateURR;
    UpdateQER updateQER[4];
    UpdateBARPFCPSessionModificationRequest updateBAR;
    UpdateTrafficEndpoint updateTrafficEndpoint;
    PFCPSMReqFlags pFCPSMReqFlags;
    QueryURR queryURR;
    FQCSID pGWCFQCSID;
    FQCSID sGWCFQCSID;
    FQCSID mMEFQCSID;
    FQCSID ePDGFQCSID;
    FQCSID tWANFQCSID;
    UserPlaneInactivityTimer userPlaneInactivityTimer;
    QueryURRReference queryURRReference;
    TraceInformation traceInformation;
} __attribute__((packed)) PFCPSessionModificationRequest;

typedef struct _PFCPSessionModificationResponse {
    unsigned long presence;
    Cause cause;
    OffendingIE offendingIE;
    CreatedPDR createdPDR;
    LoadControlInformation loadControlInformation;
    OverloadControlInformation overloadControlInformation;
    UsageReportPFCPSessionModificationResponse usageReport;
    FailedRuleID failedRuleID;
    AdditionalUsageReportsInformation additionalUsageReportsInformation;
    CreatedTrafficEndpoint createdUpdatedTrafficEndpoint;
} __attribute__((packed)) PFCPSessionModificationResponse;

typedef struct _PFCPSessionDeletionResponse {
    unsigned long presence;
    Cause cause;
    OffendingIE offendingIE;
    LoadControlInformation loadControlInformation;
    OverloadControlInformation overloadControlInformation;
    UsageReportPFCPSessionDeletionResponse usageReport;
} __attribute__((packed)) PFCPSessionDeletionResponse;

typedef struct _PFCPSessionReportRequest {
    unsigned long presence;
    ReportType reportType;
    DownlinkDataReport downlinkDataReport;
    UsageReportPFCPSessionReportRequest usageReport;
    ErrorIndicationReport errorIndicationReport;
    LoadControlInformation loadControlInformation;
    OverloadControlInformation overloadControlInformation;
    AdditionalUsageReportsInformation additionalUsageReportsInformation;
} __attribute__((packed)) PFCPSessionReportRequest;

typedef struct _PFCPSessionEstablishmentRequest {
    unsigned long presence;
    NodeID nodeID;
    FSEID cPFSEID;
    CreatePDR createPDR[4];
    CreateFAR createFAR[4];
    CreateURR createURR;
    CreateQER createQER[4];
    CreateBAR createBAR;
    CreateTrafficEndpoint createTrafficEndpoint;
    PDNType pDNType;
    FQCSID sGWCFQCSID;
    FQCSID mMEFQCSID;
    FQCSID pGWCFQCSID;
    FQCSID ePDGFQCSID;
    FQCSID tWANFQCSID;
    UserPlaneInactivityTimer userPlaneInactivityTimer;
    UserID userID;
    TraceInformation traceInformation;
} __attribute__((packed)) PFCPSessionEstablishmentRequest;

int _TlvParseMessage(void * msg, IeDescription * msgDes, void * buff, int buffLen);
void _PfcpBuildBody(Bufblk **bufBlkPtr, void *msg, IeDescription *ieDescription);
int _TlvBuildMessage(Bufblk **bufBlkPtr, void *msg, IeDescription *ieDescription);

#define ENDIAN2(x1, x2) x2 x1
#define ENDIAN3(x1, x2, x3) x3 x2 x1
#define ENDIAN4(x1, x2, x3, x4) x4 x3 x2 x1
#define ENDIAN5(x1, x2, x3, x4, x5) x5 x4 x3 x2 x1
#define ENDIAN6(x1, x2, x3, x4, x5, x6) x6 x5 x4 x3 x2 x1
#define ENDIAN7(x1, x2, x3, x4, x5, x6, x7) x7 x6 x5 x4 x3 x2 x1
#define ENDIAN8(x1, x2, x3, x4, x5, x6, x7, x8) x8 x7 x6 x5 x4 x3 x2 x1

#define PFCP_HEARTBEAT_REQUEST 1
#define PFCP_HEARTBEAT_RESPONSE 2
#define PFCPPFD_MANAGEMENT_REQUEST 3
#define PFCPPFD_MANAGEMENT_RESPONSE 4
#define PFCP_ASSOCIATION_SETUP_REQUEST 5
#define PFCP_ASSOCIATION_SETUP_RESPONSE 6
#define PFCP_ASSOCIATION_UPDATE_REQUEST 7
#define PFCP_ASSOCIATION_UPDATE_RESPONSE 8
#define PFCP_ASSOCIATION_RELEASE_REQUEST 9
#define PFCP_ASSOCIATION_RELEASE_RESPONSE 10
#define PFCP_VERSION_NOT_SUPPORTED_RESPONSE 11
#define PFCP_NODE_REPORT_REQUEST 12
#define PFCP_NODE_REPORT_RESPONSE 13
#define PFCP_SESSION_SET_DELETION_REQUEST 14
#define PFCP_SESSION_SET_DELETION_RESPONSE 15
#define PFCP_SESSION_ESTABLISHMENT_REQUEST 50
#define PFCP_SESSION_ESTABLISHMENT_RESPONSE 51
#define PFCP_SESSION_MODIFICATION_REQUEST 52
#define PFCP_SESSION_MODIFICATION_RESPONSE 53
#define PFCP_SESSION_DELETION_REQUEST 54
#define PFCP_SESSION_DELETION_RESPONSE 55
#define PFCP_SESSION_REPORT_REQUEST 56
#define PFCP_SESSION_REPORT_RESPONSE 57

typedef struct _PfcpHeader {
    union {
        struct {
            ENDIAN4(uint8_t version:3;,
                    uint8_t spare0:3;,
                    uint8_t mp:1;,
                    uint8_t seidP:1;)
        };
        uint8_t flags;
    };
    uint8_t type;
    uint16_t length;
    union {
        struct {
            uint64_t seid;
#define PfcpTransactionId2Sqn(__transactionId) htonl(((__transactionId) << 8))
#define PfcpSqn2TransactionId(__sqn) (ntohl(__sqn) >> 8)
            uint32_t sqn;
        };
        uint32_t sqn_only;
    };
} __attribute__ ((packed)) PfcpHeader;


typedef struct _PfcpMessage {
    PfcpHeader header;
    union {
//        HeartbeatRequest heartbeatRequest;
//        HeartbeatResponse heartbeatResponse;
//        PFCPPFDManagementRequest pFCPPFDManagementRequest;
//        PFCPPFDManagementResponse pFCPPFDManagementResponse;
//        PFCPAssociationSetupRequest pFCPAssociationSetupRequest;
        PFCPAssociationSetupResponse pFCPAssociationSetupResponse;
//        PFCPAssociationUpdateRequest pFCPAssociationUpdateRequest;
//        PFCPAssociationUpdateResponse pFCPAssociationUpdateResponse;
//        PFCPAssociationReleaseRequest pFCPAssociationReleaseRequest;
//        PFCPAssociationReleaseResponse pFCPAssociationReleaseResponse;
//        PFCPNodeReportRequest pFCPNodeReportRequest;
//        PFCPNodeReportResponse pFCPNodeReportResponse;
//        PFCPSessionSetDeletionRequest pFCPSessionSetDeletionRequest;
//        PFCPSessionSetDeletionResponse pFCPSessionSetDeletionResponse;
        PFCPSessionEstablishmentRequest pFCPSessionEstablishmentRequest;

        PFCPSessionEstablishmentResponse pFCPSessionEstablishmentResponse;
        PFCPSessionModificationRequest pFCPSessionModificationRequest;
        PFCPSessionModificationResponse pFCPSessionModificationResponse;
//        PFCPSessionDeletionRequest pFCPSessionDeletionRequest;
//        PFCPSessionDeletionResponse pFCPSessionDeletionResponse;
//        PFCPSessionReportRequest pFCPSessionReportRequest;
//        PFCPSessionReportResponse pFCPSessionReportResponse;
    };
} PfcpMessage;

//$ CAUSE
#define PFCP_CAUSE_REQUEST_ACCEPTED                     1
#define PFCP_CAUSE_REQUEST_REJECTED                     64
#define PFCP_CAUSE_SESSION_CONTEXT_NOT_FOUND            65
#define PFCP_CAUSE_MANDATORY_IE_MISSING                 66
#define PFCP_CAUSE_CONDITIONAL_IE_MISSING               67
#define PFCP_CAUSE_INVALID_LENGTH                       68
#define PFCP_CAUSE_MANDATORY_IE_INCORRECT               69
#define PFCP_CAUSE_INVALID_FORWARDING_POLICY            70
#define PFCP_CAUSE_INVALID_F_TEID_ALLOCATION_OPTION     71
#define PFCP_CAUSE_NO_ESTABLISHED_PFCP_ASSOCIATION      72
#define PFCP_CAUSE_RULE_CREATION_MODIFICATION_FAILURE   73
#define PFCP_CAUSE_PFCP_ENTITY_IN_CONGESTION            74
#define PFCP_CAUSE_NO_RESOURCES_AVAILABLE               75
#define PFCP_CAUSE_SERVICE_NOT_SUPPORTED                76
#define PFCP_CAUSE_SYSTEM_FAILURE                       77

//
//typedef struct _PfcpFSeid {
//    ENDIAN3(uint8_t         spare:6;,
//            uint8_t         v4:1;,
//            uint8_t         v6:1;)
//    uint64_t      seid;
//    union {
//        /* PFCP_F_TEID_IPV4 */
//        struct in_addr      addr4;
//        /* PFCP_F_TEID_IPV6 */
//        struct in6_addr     addr6;
//        /* PFCP_F_TEID_BOTH */
//        struct {
//            struct in_addr  addr4;
//            struct in6_addr addr6;
//        } dualStack;
//    };
//} __attribute__ ((packed)) PfcpFSeid;
//
//typedef struct _PfcpNodeId {
//    ENDIAN2(uint8_t spare:4;,
//            uint8_t type:4;)
//#define PFCP_NODE_ID_IPV4   0
//#define PFCP_NODE_ID_IPV6   1
//#define PFCP_NODE_ID_FQDN   2
//#define PFPC_NODE_ID_LEN(__nid) 1 + (__nid.type & 2) ? \
//            -1 : ((__nid.type & 1) ? IPV6_LEN : IPV4_LEN)
//    union {
//        /* IPV4 */
//        struct in_addr      addr4;
//        /* IPV6 */
//        struct in6_addr     addr6;
//    };
//} __attribute__ ((packed)) PfcpNodeId;

void dump_pfcp_message(PfcpMessage);

typedef struct _UpfUeIp      UpfUeIp;
typedef struct _UpfDev       UpfDev;
typedef struct gtp5g_pdr     UpfPdr;
typedef struct gtp5g_far     UpfFar;
typedef struct _UpfBufPacket UpfBufPacket;

// Rule structure dependent on UPDK
typedef UPDK_PDR UpfPDR;
typedef UPDK_FAR UpfFAR;
//typedef UPDK_QER UpfQER;
Status PfcpBuildMessage(Bufblk **bufBlkPtr, PfcpMessage *pfcpMessage);

#endif