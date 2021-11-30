/*
 * efi-dpup.h
 *
 * UEFI device path utilities protocol.
 */

#ifndef __EFI_DPUP_H
#define __EFI_DPUP_H

#include <efi.h>

typedef struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL EFI_DEVICE_PATH_UTILITIES_PROTOCOL;

#define EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID                                   \
  {                                                                               \
    0x379be4e, 0xd706, 0x437d, { 0xb0, 0x37, 0xed, 0xb8, 0x2f, 0xb7, 0x72, 0xa4 } \
  }

typedef EFI_DEVICE_PATH_PROTOCOL *(*EFIABI EFI_APPEND_DEVICE_NODE)(const EFI_DEVICE_PATH_PROTOCOL *DevicePath, const EFI_DEVICE_PATH_PROTOCOL *DeviceNode);

struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL {
  VOID *Unknown[3];
  EFI_APPEND_DEVICE_NODE AppendDeviceNode;
};

#endif /* __EFI_DPUP_H */
