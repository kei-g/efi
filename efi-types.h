#ifndef __EFI_TYPES_H
#define __EFI_TYPES_H

#pragma pack(1)

typedef struct {
  UINT8 Addr[32];
} EFI_MAC_ADDRESS;

typedef struct {
  UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct {
  UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

typedef union {
  UINT32 Addr[4];
  EFI_IPv4_ADDRESS v4;
  EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;

typedef struct {
  UINT8 Address[6];
} EFI_BLUETOOTH_ADDRESS;

typedef struct {
  UINT8 FormatType : 2;
  UINT8 MinorDeviceClass : 6;
  UINT16 MajorDeviceClass : 5;
  UINT16 MajorServiceClass : 11;
} EFI_BLUETOOTH_CLASS_OF_DEVICE;

#pragma pack()

#define BLUETOOTH_HCI_COMMAND_LOCAL_READABLE_NAME_MAX_SIZE 248
#define BLUETOOTH_HCI_LINK_KEY_SIZE 16

#endif /* __EFI_TYPES_H */
