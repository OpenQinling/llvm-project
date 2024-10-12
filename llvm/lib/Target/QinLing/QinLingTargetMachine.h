#ifndef LLVM_LIB_TARGET_QINLING_QINLINGTARGETMACHINE_H
#define LLVM_LIB_TARGET_QINLING_QINLINGTARGETMACHINE_H

#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class QinLingTargetMachine : public LLVMTargetMachine {

public:
  QinLingTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                       StringRef FS, const TargetOptions &Options,
                       std::optional<Reloc::Model> RM,
                       std::optional<CodeModel::Model> CM, CodeGenOptLevel OL);
  ~QinLingTargetMachine() override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QINLING_QINLINGTARGETMACHINE_H