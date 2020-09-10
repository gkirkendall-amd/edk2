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
InstallFadt (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_SYSTEM_TABLE             *SystemTable
  )
{

  EFI_ACPI_6_3_FIXED_ACPI_DESCRIPTION_TABLE  *Fadt;
  EFI_ACPI_6_3_FIXED_ACPI_DESCRIPTION_TABLE  *PcdFadt;

//  PcdFadt = NULL;
  PcdFadt = PcdGetPtr(PcdAcpiFadt);

  Fadt = AllocateZeroPool(sizeof(EFI_ACPI_6_3_FIXED_ACPI_DESCRIPTION_TABLE));

  CopyMem(Fadt, PcdFadt, sizeof(EFI_ACPI_6_3_FIXED_ACPI_DESCRIPTION_TABLE));
  Fadt->Header.Length = sizeof(EFI_ACPI_6_3_FIXED_ACPI_DESCRIPTION_TABLE);

  return EFI_SUCCESS;
}