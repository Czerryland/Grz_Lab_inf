add_executable(06.03.2025_task)

target_sources(06.03.2025_task
    PUBLIC
        ./main.cpp
)

set(THIRD_PARTY_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/task0_col_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task0_row_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task1_col_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task1_row_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task2_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task3_matrix_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task4_custom_data.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/task5_data.txt
)

foreach(fi ${THIRD_PARTY_FILES})
    add_custom_command(
        TARGET 06.03.2025_task POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${fi} ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach(fi)
