#include "QinLingTargetMachine.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Support/CodeGen.h"

using namespace llvm;

static StringRef computeDataLayout(const Triple &TT) {
  if (TT.isArch64Bit())
    return ("e-m:e-p:64:64-i64:64-i128:128-n32:64-S128");
  assert(TT.isArch32Bit() &&
         "only QinLing32 and QinLing64 are currently supported");
  return ("e-m:e-p:32:32-i64:64-n32-S128");
}

static Reloc::Model getEffectiveRelocModel(const Triple &TT,
                                           std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::Static);
}

static CodeModel::Model
getEffectiveQinLingCodeModel(const Triple &TT,
                             std::optional<CodeModel::Model> CM) {
  if (!CM)
    return CodeModel::Small;

  switch (*CM) {
  case CodeModel::Small:
    return *CM;
  case CodeModel::Medium:
  case CodeModel::Large:
    if (!TT.isArch64Bit())
      return CodeModel::Small;
    return *CM;
  case CodeModel::Kernel:
  case CodeModel::Tiny:
    break;
  }
  llvm_unreachable("Unsupported code model");
}

QinLingTargetMachine::QinLingTargetMachine(const Target &T, const Triple &TT,
                                           StringRef CPU, StringRef FS,
                                           const TargetOptions &Options,
                                           std::optional<Reloc::Model> RM,
                                           std::optional<CodeModel::Model> CM,
                                           CodeGenOptLevel OL)
    : LLVMTargetMachine(T, computeDataLayout(TT), TT, CPU, FS, Options,
                        getEffectiveRelocModel(TT, RM),
                        getEffectiveQinLingCodeModel(TT, CM), OL) {
  initAsmInfo();
}
