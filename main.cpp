#include<iostream>
#include<iomanip>
#include<math.h>

#include "jacobi_seidel.h"

int main(int argc, char const *argv[])
{
    std::cout << " ## Método de Gauss-Jacobi ## " << std::endl;
    jacobiIteration(0.05);
    
    std::cout << " ## Método de Gauss-Seidel ## " << std::endl;
    seidelIteration(0.05);

    return 0;
}
