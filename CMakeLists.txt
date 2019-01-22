cmake_minimum_required(VERSION 3.13)
project(ft_ls C)

set(CMAKE_C_STANDARD 11)





FILE(GLOB FT_LS_SRC ./src/*.c)
include_directories(./inc/)

#add_library(myLogicalExtLib SHARED IMPORTED)



#set_target_properties(myLogicalExtLib PROPERTIES IMPORTED_LOCATION "/Users/lreznak-/Documents/ls/libft.a")


add_executable(ft_ls ${FT_LS_SRC} src/to_list.c src/merge_sort.c src/print_mode.c)
target_link_libraries(ft_ls "/Users/lreznak-/Documents/ls/libft.a")