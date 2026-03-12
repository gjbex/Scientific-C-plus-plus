include(FetchContent)

find_package(TBB CONFIG QUIET)

if (NOT TBB_FOUND)
    FetchContent_Declare(
        onetbb
        GIT_REPOSITORY https://github.com/oneapi-src/oneTBB.git
        GIT_TAG v2021.13.0
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(onetbb)
endif()
