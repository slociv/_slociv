//编译 预处理cpp 语法分析 词法分析  ast抽象语法树 生成机器语言


// 源代码（.cpp） -> 预处理后的文件（.i） -> 词法分析生成的记号序列 -> 语法分析生成的抽象语法树（AST） -> 语义分析 -> 优化后的中间表示文件（.ir） -> 最终的机器语言文件


//预处理成i 文件会将所有include 中的复制,就是一个简单的文本复制
// # define 1
// #if
//#endif
