
list(APPEND wombatsay_srcs
            string_operations.c
            wombat_operations.c
            drawing_operations.c
            main.c)

include_directories("${CMAKE_SOURCE_DIR}/include/")


add_executable(wombatsay ${wombatsay_srcs})
