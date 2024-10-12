add_llvm_component_group(QinLing)

set(LLVM_TARGET_DEFINITIONS QinLing.td)

add_public_tablegen_target(QinLingCommonTableGen)

add_llvm_target(
  QinLingCodeGen
  QinLingTargetInfo.cpp
  QinLingTargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  LoongArchDesc
  LoongArchInfo
  MC
  Scalar
  SelectionDAG
  Support
  Target
  TargetParser
  TransformUtils

  ADD_TO_COMPONENT
  QinLing
)