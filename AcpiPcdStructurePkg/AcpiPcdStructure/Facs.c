/** @file
  Sample Driver to test ACPI PCD Structures

  Copyright (c) 2020, AMD Incorporated. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Base.h>
#include <Uefi.h>
#include <IndustryStandard/Acpi.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>

/**
  Main entry for this driver.

  @param ImageHandle     Image handle this driver.
  @param SystemTable     Pointer to SystemTable.

  @retval EFI_SUCESS     This function always complete successfully.

**/
EFI_STATUS
EFIAPI
InstallFacs (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_SYSTEM_TABLE             *SystemTable
  )
{

  EFI_ACPI_6_3_FIRMWARE_ACPI_CONTROL_STRUCTURE  *Facs;
  EFI_ACPI_6_3_FIRMWARE_ACPI_CONTROL_STRUCTURE  *PcdFacs;

//  PcdFacs = NULL;
  PcdFacs = PcdGetPtr(PcdAcpiFacs);

  Facs = AllocateZeroPool(sizeof(EFI_ACPI_6_3_FIRMWARE_ACPI_CONTROL_STRUCTURE));

  CopyMem(Facs, PcdFacs, sizeof(EFI_ACPI_6_3_FIRMWARE_ACPI_CONTROL_STRUCTURE));
  Facs->Length = sizeof(EFI_ACPI_6_3_FIRMWARE_ACPI_CONTROL_STRUCTURE);

  return EFI_SUCCESS;
}