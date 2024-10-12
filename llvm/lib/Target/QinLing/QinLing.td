include "llvm/Target/Target.td";

// 定义支持的指令集扩展和 CPU 特性
def Feature32Bit : SubtargetFeature<"32bit", "Supports32Bit", "true", "支持32位指令集">;
def Feature64Bit : SubtargetFeature<"64bit", "Supports64Bit", "true", "支持64位指令集">;

// 定义目标 CPU
def QinLing32 : ProcessorModel<"qinling32", [Feature32Bit]>;
def QinLing64 : ProcessorModel<"qinling64", [Feature64Bit]>;