
set(LIB_SOURCES
        transformers.c
)

set(MAIN_SOURCES
        main.c
)

set(HEADERS
        ${CONFIG_HEADER}
        transformers.h
)

add_library(transformers STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main transformers)

install(TARGETS transformers
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/transformers.h DESTINATION include)