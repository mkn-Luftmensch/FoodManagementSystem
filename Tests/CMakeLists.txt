enable_testing()

# These commented out lines is the equivalense to the loop below.
# add_executable(Basics tst_basics.cpp)
# add_test(NAME Basics COMMAND Basics)
# target_link_libraries(Basics PRIVATE Qt5::Test QWAMLib)

# add_executable(Gadgets tst_gadgets.cpp)
# add_test(NAME Gadgets COMMAND Gadgets)
# target_link_libraries(Gadgets PRIVATE Qt5::Test QWAMLib)

function(SETUP_TESTS)
       foreach(_testname ${ARGN})
           add_executable(${_testname} tst_${_testname}.cpp )
           add_test(NAME ${_testname} COMMAND ${_testname})
           target_link_libraries(${_testname} Qt${QT_MAJOR_VERISION}::Test Qt${QT_MAJOR_VERSION}::Widgets Qt${QT_VERSION_MAJOR}::Sql FMS )
       endforeach()
endfunction()

SETUP_TESTS(
   ingredient
   recipe
   mealplan
   addingredient
   removeingredient
   addrecipe
   removerecipe
)
