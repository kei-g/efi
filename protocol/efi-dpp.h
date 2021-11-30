/*
 * efi-dpp.h
 *
 * UEFI device path protocol.
 */

#ifndef __EFI_DPP_H
#define __EFI_DPP_H

#include <efi.h>

#define EFI_DEVICE_PATH_PROTOCOL_GUID                                              \
  {                                                                                \
    0x09576e91, 0x6d3f, 0x11d2, { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \
  }

#define EFI_HARDWARE_DEVICE_PATH 0x01
#define EFI_HW_PCI_DP 0x01
#define EFI_HW_PCCARD_DP 0x02
#define EFI_HW_MEMMAP_DP 0x03
#define EFI_HW_VENDOR_DP 0x04
#define EFI_HW_CONTROLLER_DP 0x05
#define EFI_HW_BMC_DP 0x06

#define EFI_ACPI_DEVICE_PATH 0x02
#define EFI_ACPI_DP 0x01
#define EFI_ACPI_EXTENDED_DP 0x02
#define EFI_ACPI_ADR_DP 0x03

#define EFI_MESSAGING_DEVICE_PATH 0x03
#define EFI_MSG_ATAPI_DP 0x01
#define EFI_MSG_SCSI_DP 0x02
#define EFI_MSG_FIBRECHANNEL_DP 0x03
#define EFI_MSG_FIBRECHANNELEX_DP 0x15
#define EFI_MSG_1394_DP 0x04
#define EFI_MSG_USB_DP 0x05
#define EFI_MSG_USB_CLASS_DP 0x0f
#define EFI_MSG_USB_WWID_DP 0x10
#define EFI_MSG_DEVICE_LOGICAL_UNIT_DP 0x11
#define EFI_MSG_SATA_DP 0x12
#define EFI_MSG_I2O_DP 0x06
#define EFI_MSG_MAC_ADDR_DP 0x0b
#define EFI_MSG_IPv4_DP 0x0c
#define EFI_MSG_IPv6_DP 0x0d
#define EFI_MSG_INFINIBAND_DP 0x09
#define EFI_MSG_UART_DP 0x0e
#define EFI_MSG_VENDOR_DP 0x0a
#define EFI_MSG_SASEX_DP 0x16
#define EFI_MSG_NVME_NAMESPACE_DP 0x17
#define EFI_MSG_URI_DP 0x18
#define EFI_MSG_UFS_DP 0x19
#define EFI_MSG_SD_DP 0x1a
#define EFI_MSG_EMMC_DP 0x1d
#define EFI_MSG_ISCSI_DP 0x13
#define EFI_MSG_VLAN_DP 0x14
#define EFI_MSG_BLUETOOTH_DP 0x1b
#define EFI_MSG_WIFI_DP 0x1c

#define EFI_MEDIA_DEVICE_PATH 0x04
#define EFI_MEDIA_HARDDRIVE_DP 0x01
#define EFI_MEDIA_CDROM_DP 0x02
#define EFI_MEDIA_VENDOR_DP 0x03
#define EFI_MEDIA_FILEPATH_DP 0x04
#define EFI_MEDIA_PROTOCOL_DP 0x05

#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_PATH 0x05
#define EFI_END_OF_HARDWARE_DEVICE_PATH 0x7f
#define EFI_MEDIA_PIWG_FW_FILE_DP 0x06
#define EFI_MEDIA_PIWG_FW_VOL_DP 0x07
#define EFI_MEDIA_RELATIVE_OFFSET_RANGE_DP 0x08
#define EFI_MEDIA_RAM_DISK_DP 0x09

#define EFI_BBS_DEVICE_PATH 0x05
#define EFI_BBS_BBS_DP 0x01

typedef struct EFI_DEVICE_PATH_PROTOCOL {
  UINT8 Type;
  UINT8 SubType;
  UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

#include <efi-types.h>

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 Function;
  UINT8 Device;
} EFI_PCI_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 FunctionNumber;
} EFI_PCCARD_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 MemoryType;
  EFI_PHYSICAL_ADDRESS StartingAddress;
  EFI_PHYSICAL_ADDRESS EndingAddress;
} EFI_MEMMAP_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_GUID Guid;
} EFI_VENDOR_DEVICE_PATH;
typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 ControllerNumber;
} EFI_CONTROLLER_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 InterfaceType;
  UINT8 BaseAddress[8];
} EFI_BMC_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 HID;
  UINT32 UID;
} EFI_ACPI_HID_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 HID;
  UINT32 UID;
  UINT32 CID;
} EFI_ACPI_EXTENDED_HID_DEVICE_PATH;

#define PNP_EISA_ID_CONST 0x41d0
#define EISA_ID(_Name, _Num) ((UINT32)((_Name) | (_Num) << 16))
#define EISA_PNP_ID(_PNPId) (EISA_ID(PNP_EISA_ID_CONST, (_PNPId)))
#define EFI_PNP_ID(_PNPId) (EISA_ID(PNP_EISA_ID_CONST, (_PNPId)))

#define PNP_EISA_ID_MASK 0xffff
#define EISA_ID_TO_NUM(_Id) ((_Id) >> 16)

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 ADR;
} EFI_ACPI_ADR_DEVICE_PATH;

#define ACPI_ADR_DISPLAY_TYPE_OTHER 0
#define ACPI_ADR_DISPLAY_TYPE_VGA 1
#define ACPI_ADR_DISPLAY_TYPE_TV 2
#define ACPI_ADR_DISPLAY_TYPE_EXTERNAL_DIGITAL 3
#define ACPI_ADR_DISPLAY_TYPE_INTERNAL_DIGITAL 4

#define ACPI_DISPLAY_ADR(_DeviceIdScheme, _HeadId, _NonVgaOutput, _BiosCanDetect, _VendorInfo, _Type, _Port, _Index) \
  ((UINT32)(((UINT32)((_DeviceIdScheme)&0x1) << 31) |                                                                \
            (((_HeadId)&0x7) << 18) |                                                                                \
            (((_NonVgaOutput)&0x1) << 17) |                                                                          \
            (((_BiosCanDetect)&0x1) << 16) |                                                                         \
            (((_VendorInfo)&0xf) << 12) |                                                                            \
            (((_Type)&0xf) << 8) |                                                                                   \
            (((_Port)&0xf) << 4) |                                                                                   \
            ((_Index)&0xf)))

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 PrimarySecondary;
  UINT8 SlaveMaster;
  UINT16 Lun;
} EFI_ATAPI_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 Pun;
  UINT16 Lun;
} EFI_SCSI_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 Reserved;
  UINT64 WWN;
  UINT64 Lun;
} EFI_FIBRECHANNEL_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 Reserved;
  UINT8 WWN[8];
  UINT8 Lun[8];
} EFI_FIBRECHANNELEX_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 Reserved;
  UINT64 Guid;
} EFI_F1394_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 ParentPortNumber;
  UINT8 InterfaceNumber;
} EFI_USB_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 VendorId;
  UINT16 ProductId;
  UINT8 DeviceClass;
  UINT8 DeviceSubClass;
  UINT8 DeviceProtocol;
} EFI_USB_CLASS_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 InterfaceNumber;
  UINT16 VendorId;
  UINT16 ProductId;
} EFI_USB_WWID_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 Lun;
} EFI_DEVICE_LOGICAL_UNIT_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 HBAPortNumber;
  UINT16 PortMultiplierPortNumber;
  UINT16 Lun;
} EFI_SATA_DEVICE_PATH;

#define SATA_HBA_DIRECT_CONNECT_FLAG 0x8000

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 Tid;
} EFI_I2O_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_MAC_ADDRESS MacAddress;
  UINT8 IfType;
} EFI_MAC_ADDR_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_IPv4_ADDRESS LocalIpAddress;
  EFI_IPv4_ADDRESS RemoteIpAddress;
  UINT16 LocalPort;
  UINT16 RemotePort;
  UINT16 Protocol;
  BOOLEAN StaticIpAddress;
  EFI_IPv4_ADDRESS GatewayIpAddress;
  EFI_IPv4_ADDRESS SubnetMask;
} EFI_IPv4_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_IPv6_ADDRESS LocalIpAddress;
  EFI_IPv6_ADDRESS RemoteIpAddress;
  UINT16 LocalPort;
  UINT16 RemotePort;
  UINT16 Protocol;
  UINT8 IpAddressOrigin;
  UINT8 PrefixLength;
  EFI_IPv6_ADDRESS GatewayIpAddress;
} EFI_IPv6_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 ResourceFlags;
  UINT8 PortGid[16];
  UINT64 ServiceId;
  UINT64 TargetPortId;
  UINT64 DeviceId;
} EFI_INFINIBAND_DEVICE_PATH;

#define INFINIBAND_RESOURCE_FLAG_IOC_SERVICE 0x01
#define INFINIBAND_RESOURCE_FLAG_EXTENDED_BOOT_ENVIRONMENT 0x02
#define INFINIBAND_RESOURCE_FLAG_CONSOLE_PROTOCOL 0x04
#define INFINIBAND_RESOURCE_FLAG_STORAGE_PROTOCOL 0x08
#define INFINIBAND_RESOURCE_FLAG_NETWORK_PROTOCOL 0x10

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 Reserved;
  UINT64 BaudRate;
  UINT8 DataBits;
  UINT8 Parity;
  UINT8 StopBits;
} EFI_UART_DEVICE_PATH;

typedef EFI_VENDOR_DEVICE_PATH VENDOR_DEFINED_DEVICE_PATH;

#define DEVICE_PATH_MESSAGING_PC_ANSI EFI_PC_ANSI_GUID
#define DEVICE_PATH_MESSAGING_VT_100 EFI_VT_100_GUID
#define DEVICE_PATH_MESSAGING_VT_100_PLUS EFI_VT_100_PLUS_GUID
#define DEVICE_PATH_MESSAGING_VT_UTF8 EFI_VT_UTF8_GUID

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_GUID Guid;
  UINT32 FlowControlMap;
} EFI_UART_FLOW_CONTROL_DEVICE_PATH;

#define UART_FLOW_CONTROL_HARDWARE 0x00000001
#define UART_FLOW_CONTROL_XON_XOFF 0x00000010

#define DEVICE_PATH_MESSAGING_SAS EFI_SAS_DEVICE_PATH_GUID

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_GUID Guid;
  UINT32 Reserved;
  UINT64 SasAddress;
  UINT64 Lun;
  UINT16 DeviceTopology;
  UINT16 RelativeTargetPort;
} EFI_SAS_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 SasAddress[8];
  UINT8 Lun[8];
  UINT16 DeviceTopology;
  UINT16 RelativeTargetPort;
} EFI_SASEX_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 NamespaceId;
  UINT64 NamespaceUuid;
} EFI_NVME_NAMESPACE_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  CHAR8 Uri[];
} EFI_URI_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 Pun;
  UINT8 Lun;
} EFI_UFS_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 SlotNumber;
} EFI_SD_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 SlotNumber;
} EFI_EMMC_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 NetworkProtocol;
  UINT16 LoginOption;
  UINT64 Lun;
  UINT16 TargetPortalGroupTag;
} EFI_ISCSI_DEVICE_PATH;

#define ISCSI_LOGIN_OPTION_NO_HEADER_DIGEST 0x0000
#define ISCSI_LOGIN_OPTION_HEADER_DIGEST_USING_CRC32C 0x0002
#define ISCSI_LOGIN_OPTION_NO_DATA_DIGEST 0x0000
#define ISCSI_LOGIN_OPTION_DATA_DIGEST_USING_CRC32C 0x0008
#define ISCSI_LOGIN_OPTION_AUTHMETHOD_CHAP 0x0000
#define ISCSI_LOGIN_OPTION_AUTHMETHOD_NON 0x1000
#define ISCSI_LOGIN_OPTION_CHAP_BI 0x0000
#define ISCSI_LOGIN_OPTION_CHAP_UNI 0x2000

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 VlanId;
} EFI_VLAN_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_BLUETOOTH_ADDRESS BD_ADDR;
} EFI_BLUETOOTH_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT8 SSId[32];
} EFI_WIFI_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 PartitionNumber;
  UINT64 PartitionStart;
  UINT64 PartitionSize;
  UINT8 Signature[16];
  UINT8 MBRType;
  UINT8 SignatureType;
} EFI_HARDDRIVE_DEVICE_PATH;

#define MBR_TYPE_PCAT 0x01
#define MBR_TYPE_EFI_PARTITION_TABLE_HEADER 0x02

#define NO_DISK_SIGNATURE 0x00
#define SIGNATURE_TYPE_MBR 0x01
#define SIGNATURE_TYPE_GUID 0x02

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 BootEntry;
  UINT64 PartitionStart;
  UINT64 PartitionSize;
} EFI_CDROM_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  CHAR16 PathName[1];
} EFI_FILEPATH_DEVICE_PATH;

#define SIZE_OF_FILEPATH_DEVICE_PATH OFFSET_OF(FILEPATH_DEVICE_PATH, PathName)

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_GUID Protocol;
} EFI_MEDIA_PROTOCOL_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_GUID FvFileName;
} EFI_MEDIA_FW_VOL_FILEPATH_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  EFI_GUID FvName;
} EFI_MEDIA_FW_VOL_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 Reserved;
  UINT64 StartingOffset;
  UINT64 EndingOffset;
} EFI_MEDIA_RELATIVE_OFFSET_RANGE_DEVICE_PATH;

#define EFI_VIRTUAL_DISK_GUID EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_DISK_REGION_VOLATILE
#define EFI_VIRTUAL_CD_GUID EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_CD_REGION_VOLATILE
#define EFI_PERSISTENT_VIRTUAL_DISK_GUID EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_DISK_REGION_PERSISTENT
#define EFI_PERSISTENT_VIRTUAL_CD_GUID EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_CD_REGION_PERSISTENT

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT32 StartingAddr[2];
  UINT32 EndingAddr[2];
  EFI_GUID TypeGuid;
  UINT16 Instance;
} EFI_MEDIA_RAM_DISK_DEVICE_PATH;

typedef struct {
  EFI_DEVICE_PATH_PROTOCOL Header;
  UINT16 DeviceType;
  UINT16 StatusFlag;
  CHAR8 String[1];
} EFI_BBS_BBS_DEVICE_PATH;

#define BBS_TYPE_FLOPPY 0x01
#define BBS_TYPE_HARDDRIVE 0x02
#define BBS_TYPE_CDROM 0x03
#define BBS_TYPE_PCMCIA 0x04
#define BBS_TYPE_USB 0x05
#define BBS_TYPE_EMBEDDED_NETWORK 0x06
#define BBS_TYPE_BEV 0x80
#define BBS_TYPE_UNKNOWN 0xFF

typedef union {
  EFI_DEVICE_PATH_PROTOCOL DevPath;
  EFI_PCI_DEVICE_PATH Pci;
  EFI_PCCARD_DEVICE_PATH PcCard;
  EFI_MEMMAP_DEVICE_PATH MemMap;
  EFI_VENDOR_DEVICE_PATH Vendor;
  EFI_CONTROLLER_DEVICE_PATH Controller;
  EFI_BMC_DEVICE_PATH Bmc;
  EFI_ACPI_HID_DEVICE_PATH Acpi;
  EFI_ACPI_EXTENDED_HID_DEVICE_PATH ExtendedAcpi;
  EFI_ACPI_ADR_DEVICE_PATH AcpiAdr;
  EFI_ATAPI_DEVICE_PATH Atapi;
  EFI_SCSI_DEVICE_PATH Scsi;
  EFI_ISCSI_DEVICE_PATH Iscsi;
  EFI_FIBRECHANNEL_DEVICE_PATH FibreChannel;
  EFI_FIBRECHANNELEX_DEVICE_PATH FibreChannelEx;
  EFI_F1394_DEVICE_PATH F1394;
  EFI_USB_DEVICE_PATH Usb;
  EFI_SATA_DEVICE_PATH Sata;
  EFI_USB_CLASS_DEVICE_PATH UsbClass;
  EFI_USB_WWID_DEVICE_PATH UsbWwid;
  EFI_DEVICE_LOGICAL_UNIT_DEVICE_PATH LogicUnit;
  EFI_I2O_DEVICE_PATH I2O;
  EFI_MAC_ADDR_DEVICE_PATH MacAddr;
  EFI_IPv4_DEVICE_PATH Ipv4;
  EFI_IPv6_DEVICE_PATH Ipv6;
  EFI_VLAN_DEVICE_PATH Vlan;
  EFI_INFINIBAND_DEVICE_PATH InfiniBand;
  EFI_UART_DEVICE_PATH Uart;
  EFI_UART_FLOW_CONTROL_DEVICE_PATH UartFlowControl;
  EFI_SAS_DEVICE_PATH Sas;
  EFI_SASEX_DEVICE_PATH SasEx;
  EFI_NVME_NAMESPACE_DEVICE_PATH NvmeNamespace;
  EFI_URI_DEVICE_PATH Uri;
  EFI_BLUETOOTH_DEVICE_PATH Bluetooth;
  EFI_WIFI_DEVICE_PATH WiFi;
  EFI_UFS_DEVICE_PATH Ufs;
  EFI_SD_DEVICE_PATH Sd;
  EFI_EMMC_DEVICE_PATH Emmc;
  EFI_HARDDRIVE_DEVICE_PATH HardDrive;
  EFI_CDROM_DEVICE_PATH CD;
  EFI_FILEPATH_DEVICE_PATH FilePath;
  EFI_MEDIA_PROTOCOL_DEVICE_PATH MediaProtocol;
  EFI_MEDIA_FW_VOL_DEVICE_PATH FirmwareVolume;
  EFI_MEDIA_FW_VOL_FILEPATH_DEVICE_PATH FirmwareFile;
  EFI_MEDIA_RELATIVE_OFFSET_RANGE_DEVICE_PATH Offset;
  EFI_MEDIA_RAM_DISK_DEVICE_PATH RamDisk;
  EFI_BBS_BBS_DEVICE_PATH Bbs;
} EFI_DEV_PATH;

typedef union {
  EFI_DEVICE_PATH_PROTOCOL *DevPath;
  EFI_PCI_DEVICE_PATH *Pci;
  EFI_PCCARD_DEVICE_PATH *PcCard;
  EFI_MEMMAP_DEVICE_PATH *MemMap;
  EFI_VENDOR_DEVICE_PATH *Vendor;
  EFI_CONTROLLER_DEVICE_PATH *Controller;
  EFI_BMC_DEVICE_PATH *Bmc;
  EFI_ACPI_HID_DEVICE_PATH *Acpi;
  EFI_ACPI_EXTENDED_HID_DEVICE_PATH *ExtendedAcpi;
  EFI_ACPI_ADR_DEVICE_PATH *AcpiAdr;
  EFI_ATAPI_DEVICE_PATH *Atapi;
  EFI_SCSI_DEVICE_PATH *Scsi;
  EFI_ISCSI_DEVICE_PATH *Iscsi;
  EFI_FIBRECHANNEL_DEVICE_PATH *FibreChannel;
  EFI_FIBRECHANNELEX_DEVICE_PATH *FibreChannelEx;
  EFI_F1394_DEVICE_PATH *F1394;
  EFI_USB_DEVICE_PATH *Usb;
  EFI_SATA_DEVICE_PATH *Sata;
  EFI_USB_CLASS_DEVICE_PATH *UsbClass;
  EFI_USB_WWID_DEVICE_PATH *UsbWwid;
  EFI_DEVICE_LOGICAL_UNIT_DEVICE_PATH *LogicUnit;
  EFI_I2O_DEVICE_PATH *I2O;
  EFI_MAC_ADDR_DEVICE_PATH *MacAddr;
  EFI_IPv4_DEVICE_PATH *Ipv4;
  EFI_IPv6_DEVICE_PATH *Ipv6;
  EFI_VLAN_DEVICE_PATH *Vlan;
  EFI_INFINIBAND_DEVICE_PATH *InfiniBand;
  EFI_UART_DEVICE_PATH *Uart;
  EFI_UART_FLOW_CONTROL_DEVICE_PATH *UartFlowControl;
  EFI_SAS_DEVICE_PATH *Sas;
  EFI_SASEX_DEVICE_PATH *SasEx;
  EFI_NVME_NAMESPACE_DEVICE_PATH *NvmeNamespace;
  EFI_URI_DEVICE_PATH *Uri;
  EFI_BLUETOOTH_DEVICE_PATH *Bluetooth;
  EFI_WIFI_DEVICE_PATH *WiFi;
  EFI_UFS_DEVICE_PATH *Ufs;
  EFI_SD_DEVICE_PATH *Sd;
  EFI_EMMC_DEVICE_PATH *Emmc;
  EFI_HARDDRIVE_DEVICE_PATH *HardDrive;
  EFI_CDROM_DEVICE_PATH *CD;
  EFI_FILEPATH_DEVICE_PATH *FilePath;
  EFI_MEDIA_PROTOCOL_DEVICE_PATH *MediaProtocol;
  EFI_MEDIA_FW_VOL_DEVICE_PATH *FirmwareVolume;
  EFI_MEDIA_FW_VOL_FILEPATH_DEVICE_PATH *FirmwareFile;
  EFI_MEDIA_RELATIVE_OFFSET_RANGE_DEVICE_PATH *Offset;
  EFI_MEDIA_RAM_DISK_DEVICE_PATH *RamDisk;
  EFI_BBS_BBS_DEVICE_PATH *Bbs;
  UINT8 *Raw;
} EFI_DEV_PATH_PTR;

#pragma pack()

#define END_DEVICE_PATH_TYPE 0x7f
#define END_ENTIRE_DEVICE_PATH_SUBTYPE 0xff
#define END_INSTANCE_DEVICE_PATH_SUBTYPE 0x01

#endif /* __EFI_DPP_H */
