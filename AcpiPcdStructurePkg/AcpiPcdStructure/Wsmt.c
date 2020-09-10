/** @file
  Sample Driver to test ACPI PCD Structures

  Copyright (c) 2020, AMD Incorporated. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Base.h>
#include <Uefi.h>
#include <IndustryStandard/Acpi.h>
#include <IndustryStandard/WindowsSmmSecurityMitigationTable.h>
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
InstallWsmt (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_SYSTEM_TABLE             *SystemTable
  )
{

  EFI_ACPI_WSMT_TABLE  *Wsmt;
  EFI_ACPI_WSMT_TABLE  *PcdWsmt;

//  PcdWsmt = NULL;
  PcdWsmt = PcdGetPtr(PcdAcpiWsmt);

  Wsmt = AllocateZeroPool(sizeof(EFI_ACPI_WSMT_TABLE));

  CopyMem(Wsmt, PcdWsmt, sizeof(EFI_ACPI_WSMT_TABLE));
  Wsmt->Header.Length = sizeof(EFI_ACPI_WSMT_TABLE);

  return EFI_SUCCESS;
}