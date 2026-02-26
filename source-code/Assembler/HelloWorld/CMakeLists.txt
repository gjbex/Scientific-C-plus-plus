cmake_minimum_required(VERSION 3.20)
project(assembler_hello_world LANGUAGES ASM_NASM)

set(HELLO_OBJ ${CMAKE_CURRENT_BINARY_DIR}/hello.o)
set(HELLO_EXE ${CMAKE_CURRENT_BINARY_DIR}/hello.exe)

add_custom_command(
    OUTPUT ${HELLO_OBJ}
    COMMAND ${CMAKE_ASM_NASM_COMPILER} -f elf64 -o ${HELLO_OBJ}
            ${CMAKE_CURRENT_SOURCE_DIR}/hello.nsm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/hello.nsm
    VERBATIM
)

add_custom_command(
    OUTPUT ${HELLO_EXE}
    COMMAND ld -s -o ${HELLO_EXE} ${HELLO_OBJ}
    DEPENDS ${HELLO_OBJ}
    VERBATIM
)

add_custom_target(hello.exe ALL DEPENDS ${HELLO_EXE})
