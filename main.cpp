#include<iostream>
#include<iomanip>
#include<math.h>

#include "jacobi_seidel.h"

int main(int argc, char const *argv[])
{
    jacobiIteration(0.05);
    seidelIteration(0.05);

    return 0;
}
