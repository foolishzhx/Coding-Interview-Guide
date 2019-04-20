cmake_minimum_required(VERSION 3.12)
project(mianshitimu)

set(CMAKE_CXX_STANDARD 14)
include_directories(
    include
)
add_library(support
    src/BiTree.cpp
)
#add_executable(main chapter3-binarytree/7subBST.cpp)
#add_executable(main chapter2-linklist/1linklistsamepart.cpp)
add_executable(main chapter1-stackandqueue/8maxTree.cpp)
target_link_libraries(main support)
#未完成的题目
#第一章
#6、用栈来求解汉诺塔问题
#第二章
#15、将二叉树转换成双向链表
#第三章
#8、找到二叉树中符合搜索二叉树条件的最大拓扑结构
