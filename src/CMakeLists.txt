
set(LIB_SOURCES
        tensor.c
        llamaConfig.c
)

set(MAIN_SOURCES
        main.c
)

set(HEADERS
        ${CONFIG_HEADER}
        tensor.h
        llamaConfig.h
)

add_library(transformers STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main transformers)

install(TARGETS transformers
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/tensor.h ${CMAKE_CURRENT_SOURCE_DIR}/llamaConfig.h DESTINATION include)