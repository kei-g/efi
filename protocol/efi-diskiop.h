/*
 * efi-diskiop.h
 *
 * Disk I/O protocol.
 */

#ifndef __EFI_DISKIOP_H
#define __EFI_DISKIOP_H

#include <efi.h>

#define EFI_DISKIO_PROTOCOL_GUID                                                  \
  {                                                                               \
    0xce345171, 0xba0b, 0x11d2, { 0x8e, 0x4f, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \
  }

#define EFI_DISK_IO_PROTOCOL_REVISION 0x00010000
#define EFI_DISK_IO_INTERFACE_REVISION EFI_DISK_IO_PROTOCOL_REVISION

typedef struct _EFI_DISK_IO_PROTOCOL EFI_DISK_IO_PROTOCOL;

typedef EFI_STATUS (*EFIABI EFI_DISK_READ)(EFI_DISK_IO_PROTOCOL *This, UINT32 MediaId, UINT64 Offset, UINTN BufferSize, VOID *Buffer);
typedef EFI_STATUS (*EFIABI EFI_DISK_WRITE)(EFI_DISK_IO_PROTOCOL *This, UINT32 MediaId, UINT64 Offset, UINTN BufferSize, VOID *Buffer);

struct _EFI_DISK_IO_PROTOCOL {
  UINT64 Revision;
  EFI_DISK_READ ReadDisk;
  EFI_DISK_WRITE WriteDisk;
};

#endif /* __EFI_DISKIOP_H */
