#include "evaluate.h"

int main(void)
{
    std::cout << "( ( 1 + 2 ) * 3 ) = " << evaluate("( ( 1 + 2 ) * 3 )") << std::endl;
    std::cout << "( ( ( 5.5 - 2 ) * 4 ) / 3.5 + 8.4 ) = " << evaluate("( ( ( 5.5 - 2 ) * 4 ) / 3.5 + 8.4 )") << std::endl;  

    return 0;
}