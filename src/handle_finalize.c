#include "kiln_plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;

    msg->uiType = ETH_UI_TYPE_GENERIC;

    switch (context->selectorIndex) {
        case KILN_V1_DEPOSIT:
        case KILN_V1_WITHDRAW:
        case KILN_V1_WITHDRAW_EL:
        case KILN_V1_WITHDRAW_CL:
        case KILN_V1_BATCH_WITHDRAW:
        case KILN_V1_BATCH_WITHDRAW_EL:
        case KILN_V1_BATCH_WITHDRAW_CL:
        case KILN_V1_REQUEST_EXIT:
        case KILN_V2_STAKE:
        case KILN_V2_REQUEST_EXIT:
        case KILN_V2_MULTICLAIM:
        case KILN_V2_CLAIM:
            msg->numScreens = 1;
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        case KILN_LR_DEPOSIT_INTO_STRATEGY:
            msg->numScreens = 3;
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        case KILN_LR_QUEUE_WITHDRAWAL:
            msg->numScreens = 2;
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        case KILN_LR_COMPLETE_QUEUED_WITHDRAWAL:
            msg->numScreens = 1;
            msg->result = ETH_PLUGIN_RESULT_OK;
            break;
        default:
            PRINTF("Selector Index not supported: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}
