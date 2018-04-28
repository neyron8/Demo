#include "func.h"
#include "ctest.h"

CTEST(arithmetic_suite, sum)
{
    // Given
    const int a = 1;
    const int b = 2;

    // When
    const int result = sum(a, b);

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, raz)
{
    // Given
    const int a = 5;
    const int b = 2;

    // When
    const int result = raz(a, b);

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}

