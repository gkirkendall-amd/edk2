/** @file
  Sample Driver to test ACPI PCD Structures

  Copyright (c) 2020, AMD Incorporated. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Base.h>
#include <Uefi.h>
#include <IndustryStandard/Acpi.h>
#include <IndustryStandard/HighPrecisionEventTimerTable.h>
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
InstallHpet (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_SYSTEM_TABLE             *SystemTable
  )
{

  EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_HEADER  *Hpet;
  EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_HEADER  *PcdHpet;

//  PcdHpet = NULL;
  PcdHpet = PcdGetPtr(PcdAcpiHpet);

  Hpet = AllocateZeroPool(sizeof(EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_HEADER));

  CopyMem(Hpet, PcdHpet, sizeof(EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_HEADER));
  Hpet->Header.Length = sizeof(EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_HEADER);

  return EFI_SUCCESS;
}