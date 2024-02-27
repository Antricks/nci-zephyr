#pragma once
#include "dep.hpp"

// I feel like these defines are not really necessary for the most part but whatevs...
#define APDU_INS_DEACTIVATE_FILE 0x04
#define APDU_INS_DEACTIVATE_RECORD 0x06
#define APDU_INS_ACTIVATE_RECORD 0x08
#define APDU_INS_ERASE_RECORD 0x0c
#define APDU_INS_ERASE_BINARY_0e 0x0e
#define APDU_INS_ERASE_BINARY_0f 0x0f
#define APDU_INS_SCQL_OPERATIOIN 0x10
#define APDU_INS_TRANSACTION_OPERATION 0x12
#define APDU_INS_USER_OPERATION 0x14
#define APDU_INS_ADDITIONAL_DEVICE_MGMT_16 0x16
#define APDU_INS_ADDITIONAL_DEVICE_MGMT_17 0x17
#define APDU_INS_VERIFY_20 0x20
#define APDU_INS_VERIFY_21 0x21
#define APDU_INS_MANAGE_SECURITY_ENV 0x22
#define APDU_INS_CHANGE_REFERENCE_DATA_24 0x24
#define APDU_INS_CHANGE_REFERENCE_DATA_25 0x25
#define APDU_INS_DISABLE_VERIFICATION_REQUIREMENT 0x26
#define APDU_INS_ENABLE_VERIFICATION_REQUIREMENT 0x28
#define APDU_INS_SECURITY_OPERATION_2a 0x2a
#define APDU_INS_SECURITY_OPERATION_2b 0x2b
#define APDU_INS_RESET_RETRY_COUNTER_2c 0x2c
#define APDU_INS_RESET_RETRY_COUNTER_2d 0x2d
#define APDU_INS_BIOMETRIC_OPERATION_2e 0x2e
// biometric? whaat? TODO: read ISO/IEC 7816-11 about that
#define APDU_INS_BIOMETRIC_OPERATION_2f 0x2f
#define APDU_INS_COMPARE 0x33
#define APDU_INS_GET_ATTRIBUTE_34 0x34
#define APDU_INS_GET_ATTRIBUTE_35 0x35
#define APDU_INS_APPLICATION_MGMT_REQUEST_40 0x40
#define APDU_INS_APPLICATION_MGMT_REQUEST_41 0x41
#define APDU_INS_ACTIVATE_FILE 0x44
#define APDU_INS_GEN_ASYMMETRIC_KEY_PAIR_46 0x46
#define APDU_INS_GEN_ASYMMETRIC_KEY_PAIR_47 0x47
#define APDU_INS_IMPORT_CARD_SECRET 0x48
#define APDU_INS_MANAGE_CHANNEL 0x70
#define APDU_INS_EXT_AUTHENTICATE 0x82
#define APDU_INS_GET_CHALLENGE 0x84
#define APDU_INS_GENERAL_AUTH_86 0x86
#define APDU_INS_GENERAL_AUTH_87 0x87
#define APDU_INS_INTERNAL_AUTH 0x88
#define APDU_INS_SEARCH_BINARY_a0 0xa0
#define APDU_INS_SEARCH_BINARY_a1 0xa1
#define APDU_INS_SEARCH_RECORD 0xa2
#define APDU_INS_SELECT 0xa4
#define APDU_INS_SELECT_DATA 0xa5
#define APDU_INS_READ_BINARY_b0 0xb0
#define APDU_INS_READ_BINARY_b1 0xb1
#define APDU_INS_READ_RECORD_b2 0xb2
#define APDU_INS_READ_RECORD_b3 0xb3
#define APDU_INS_GET_RESPONSE 0xc0
#define APDU_INS_ENVELOPE_c2 0xc2
#define APDU_INS_ENVELOPE_c3 0xc3
#define APDU_INS_GET_DATA_ca 0xca
#define APDU_INS_GET_DATA_cb 0xcb
#define APDU_INS_GET_NEXT_DATA_cc 0xcc
#define APDU_INS_GET_NEXT_DATA_cd 0xcd
#define APDU_INS_MANAGE_DATA 0xcf
#define APDU_INS_WRITE_BINARY_d0 0xd0
#define APDU_INS_WRITE_BINARY_d1 0xd1
#define APDU_INS_WRITE_RECORD 0xd2
#define APDU_INS_UPDATE_BINARY_d6 0xd6
#define APDU_INS_UPDATE_BINARY_d7 0xd7
#define APDU_INS_PUT_NEXT_DATA_d8 0xd8
#define APDU_INS_PUT_NEXT_DATA_d9 0xd9
#define APDU_INS_PUT_DATA_da 0xda
#define APDU_INS_PUT_DATA_db 0xdb
#define APDU_INS_UPDATE_RECORD_dc 0xdc
#define APDU_INS_UPDATE_RECORD_dd 0xdd
#define APDU_INS_UPDATE_DATA_de 0xde
#define APDU_INS_UPDATE_DATA_df 0xdf
#define APDU_INS_CREATE_FILE 0xe0
#define APDU_INS_CREATE 0xe1
#define APDU_INS_APPEND_RECORD 0xe2
#define APDU_INS_DELETE_FILE 0xe4
#define APDU_INS_TERMINATE_DF 0xe6
#define APDU_INS_TERMINATE_EF 0xe8
#define APDU_INS_LOAD_APPLICATION_ea 0xea
#define APDU_INS_LOAD_APPLICATION_eb 0xeb
#define APDU_INS_DELETE_DATA 0xee
#define APDU_INS_REMOVE_APPLICATION_ec 0xec
#define APDU_INS_REMOVE_APPLICATION_ed 0xed
#define APDU_INS_TERMINATE_CARD_USAGE 0xfe

// Theoretically it could be nice to also abstract away transport here
// but honestly I don't know if that's maybe a bit too much...
class IsoDep : public Dep {
  public:
    IsoDep(Nci *nci);
    ~IsoDep();

    int handle_apdu(const uint8_t *buf, size_t buf_len);

    uint8_t selected_application[32];
    uint8_t selected_ef[8];

    uint8_t selected_application_len = 0;
    uint8_t selected_ef_len = 0;
};
