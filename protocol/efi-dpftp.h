/*
 * efi-dpftp.h
 *
 * UEFI device path from text protocol.
 */

#ifndef __EFI_DPFTP_H
#define __EFI_DPFTP_H

#include <efi.h>

typedef struct _EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL;

#define EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL_GUID                                   \
  {                                                                               \
    0x5c99a21, 0xc70f, 0x4ad2, { 0x8a, 0x5f, 0x35, 0xdf, 0x33, 0x43, 0xf5, 0x1e } \
  }

typedef EFI_DEVICE_PATH_PROTOCOL *(*EFI_CONVERT_TEXT_TO_DEVICE_NODE)(const CHAR16 *TextDeviceNode);
typedef EFI_DEVICE_PATH_PROTOCOL *(*EFI_CONVERT_TEXT_TO_DEVICE_PATH)(const CHAR16 *TextDevicePath);

struct _EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL {
  EFI_CONVERT_TEXT_TO_DEVICE_NODE ConvertTextToDeviceNode;
  EFI_CONVERT_TEXT_TO_DEVICE_PATH ConvertTextToDevicePath;
};

#endif /* __EFI_DPFTP_H */
