cmake_minimum_required(VERSION 3.22.1)
project(server)

set(BUILD_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LINK_LIB pthread event spdlog fmt jsoncpp mysqlcppconn cryptopp)

# 包含头文件
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/libevent/include)

# 搜索源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${BUILD_PATH})

# 添加 DEBUG 宏
add_definitions(-D__DEBUG)

# 生成可执行程序
add_executable(server ${SRC_LIST})

# 链接第三方动态库
link_directories(${PROJECT_SOURCE_DIR}libevent/lib)

# 链接系统动态库
target_link_libraries(server ${LINK_LIB})
