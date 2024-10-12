#ifndef LLVM_LIB_TARGET_QINLING_QINLINGTARGETINFO_H
#define LLVM_LIB_TARGET_QINLING_QINLINGTARGETINFO_H

#include "llvm/MC/TargetRegistry.h"

namespace llvm {
Target &getTheQinLingTarget32();
Target &getTheQinLingTarget64();
} // namespace llvm

extern "C" void LLVMInitializeQinLingTargetInfo();

#endif