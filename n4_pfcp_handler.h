//
// Created by ziyan on 5/29/22.
//

#ifndef PFCP_REQUEST_ANALYZER_N4_PFCP_HANDLER_H
#define PFCP_REQUEST_ANALYZER_N4_PFCP_HANDLER_H
#include "pfcp_message.h"
#include "utlt_debug.h"

int _ConvertCreateFARTlvToRule(UpfFAR *upfFar, CreateFAR *createFar);

Status _ConvertCreatePDRTlvToRule(UpfPDR *upfPdr, CreatePDR *createPdr);


#endif //PFCP_REQUEST_ANALYZER_N4_PFCP_HANDLER_H
