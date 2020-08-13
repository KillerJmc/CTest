find_path(JMC_INCLUDES tools.h file.h ${PROJECT_SOURCE_DIR}/include)
find_library(JMC_LIBS _jmc ${PROJECT_SOURCE_DIR}/lib)

if (JMC_INCLUDES AND JMC_LIBS)
    set(JMC_FOUND TRUE)
endif (JMC_INCLUDES AND JMC_LIBS)