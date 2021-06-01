find_package(BISON)
find_package(FLEX)

set(
    migcom_SOURCES
    error.c
    global.c
    header.c
    mig.c
    routine.c
    server.c
    statement.c
    string.c
    type.c
    user.c
    utils.c
    ${CMAKE_CURRENT_BINARY_DIR}/lexxer.c
)

set(
    migcom_INCLUDES
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

FLEX_TARGET(
    migcom
    lexxer.l
    ${CMAKE_CURRENT_BINARY_DIR}/lexxer.c
)

BISON_TARGET(
    migcom
    parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parser.c
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/y.tab.h
)

add_executable(
    migcom
    ${migcom_SOURCES}
    ${BISON_migcom_OUTPUTS}
    ${FLEX_migcom_OUTPUTS}
)

target_compile_definitions(
    migcom
    PRIVATE MIG_VERSION="${MIG_VERSION}"
)

target_include_directories(
    migcom
    PUBLIC
    ${migcom_INCLUDES}
)

install(
    PROGRAMS mig.sh DESTINATION bin RENAME mig
)

install(
    TARGETS migcom RUNTIME DESTINATION libexec
)
