#pragma once

#include <stdint.h>
#include "mach/boolean.h"

enum _MACH_MSG_TYPE {
    MACH_MSG_TYPE_COPY_SEND = 19,
    MACH_MSG_TYPE_PORT_NAME = 15,
    MACH_MSG_TYPE_PORT_RECEIVE = 16,
    MACH_MSG_TYPE_PORT_SEND = 17,
    MACH_MSG_TYPE_PORT_SEND_ONCE = 18,
    MACH_MSG_TYPE_MAKE_SEND = 20,
    MACH_MSG_TYPE_MAKE_SEND_ONCE = 21,
    MACH_MSG_TYPE_MOVE_RECEIVE = MACH_MSG_TYPE_PORT_RECEIVE,
    MACH_MSG_TYPE_MOVE_SEND = MACH_MSG_TYPE_PORT_SEND,
    MACH_MSG_TYPE_MOVE_SEND_ONCE = MACH_MSG_TYPE_PORT_SEND_ONCE,
    MACH_MSG_TYPE_POLYMORPHIC = -1,
};

enum {
    MACH_MSG_PORT_DESCRIPTOR = 0,
    MACH_MSG_OOL_DESCRIPTOR = 1,
    MACH_MSG_OOL_PORTS_DESCRIPTOR = 2,
    MACH_MSG_OOL_VOLATILE_DESCRIPTOR = 3,
};

typedef uint32_t mach_msg_bits_t;
typedef uint32_t mach_msg_descriptor_type_t;
typedef integer_t mach_msg_id_t;
typedef	natural_t mach_msg_size_t;
typedef natural_t mach_msg_type_number_t;

typedef struct mach_msg_body_t {
    mach_msg_size_t msgh_descriptor_count;
} mach_msg_body_t;

typedef	struct mach_msg_header_t {
    mach_msg_bits_t msgh_bits;
    mach_msg_size_t msgh_size;
    mach_port_t msgh_remote_port;
    mach_port_t msgh_local_port;
    mach_port_name_t msgh_voucher_port;
    mach_msg_id_t msgh_id;
} mach_msg_header_t;

static boolean_t
MACH_MSG_TYPE_PORT_ANY(mach_msg_type_number_t msg) {
   return (msg >= MACH_MSG_TYPE_MOVE_RECEIVE) &&
          (msg <= MACH_MSG_TYPE_MAKE_SEND_ONCE);
}
