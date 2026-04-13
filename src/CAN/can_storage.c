#include "can_storage.h"

void my_recive_callback(const can_msg_t *message) {
    // Process the received CAN message
    printf("Received CAN message with ID: %u\n", message->sid);
    printf("Data Length: %u\n", message->data_len);
    printf("Data: ");
}