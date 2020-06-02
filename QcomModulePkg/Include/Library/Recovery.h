/* Copyright (c) 2016,2019 The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided
 *  with the distribution.
 *   * Neither the name of The Linux Foundation nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _BOOTLOADER_RECOVERY_H
#define _BOOTLOADER_RECOVERY_H

#include "LinuxLoaderLib.h"

#define FFBM_MODE_BUF_SIZE 8

#define READ_OEM_BUF_SIZE 512
#define READ_OEM_BUF_LEN  24

#define RECOVERY_BOOT_RECOVERY "boot-recovery"
#define RECOVERY_BOOT_FASTBOOT "boot-fastboot"

/* Recovery Message */
struct RecoveryMessage {
  CHAR8 command[32];
  CHAR8 status[32];
  CHAR8 recovery[1024];
};

EFI_STATUS
RecoveryInit (BOOLEAN *BootIntoRecovery);
EFI_STATUS
GetFfbmCommand (CHAR8 *FfbmMode, UINT32 Sz);
EFI_STATUS
WriteRecoveryMessage (CHAR8 *Command);

EFI_STATUS
GetOemHardwareRevision (CHAR8 *nv_hwrevision);
EFI_STATUS
GetOemSerialNum (CHAR8 *nv_serialnum);

#endif
