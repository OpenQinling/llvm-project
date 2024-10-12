#include "./QinLingTargetInfo.h"

using namespace llvm;

Target &llvm::getTheQinLingTarget32() {
  static Target TheQinLingTarget32;
  return TheQinLingTarget32;
}

Target &llvm::getTheQinLingTarget64() {
  static Target TheQinLingTarget64;
  return TheQinLingTarget64;
}

extern "C" void LLVMInitializeQinLingTargetInfo() {
  RegisterTarget<Triple::qinling32, false> QinLing32(
      getTheQinLingTarget32(), "qinling32", "QinLing", "QinLing");
  RegisterTarget<Triple::qinling64, false> QinLing64(
      getTheQinLingTarget64(), "qinling64", "QinLing", "QinLing");
}