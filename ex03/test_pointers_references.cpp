#include <iostream>
int main(void)
{
    // Section #1
    // 1. Declare a variable f as a pointer to a float
    float *f;
    // 2. Create a float variable named pi, and store the value 3.14159f
    float pi = 3.14159f;
    // 3. Make f points to pi
    f = &pi;
    // 4. Print out the content of the memory location pointed to by f
    std::cout << *f << std::endl;

    // Section #2
    short a[] = {5, 4, 3, 2, 1};
    // 5. Declare a variable ip as a pointer to a short integer
    short *ip;
    // 6. Make ip points to the beginning of the array a
    ip = a;
    // 7. Print out what ip points to and the content of a[0] (verify they are the same)
    std::cout << "*ip: " << *ip << ", a[0]: " << a[0] << std::endl;
    // 8. Increase ip by 2 and check that what it points to corresponds to a[2]
    ip += 2;
    std::cout << "*ip: " << *ip << ", a[2]: " << a[2] << std::endl;
    // 9. Make ip points to the last element of the array by increasing it by 2
    ip += 2;
    //    and check that what it points to corresponds to a[4]
    std::cout << "*ip: " << *ip << ", a[4]: " << a[4] << std::endl;

    // Section #3
    int n = 20;
    // 10. Declare a variable d as a pointer to double and make it point to an array
    // of "n" element of type "double" created on the heap
    double *d = new double[n];
    // 11. Store in each d[i] (for i=0 to n-1) the value double(i) / 5.0;
    for (int i = 0; i < n; i++)
        d[i] = double(i) / 5.0;
    // 12. Print out each element of d
    for (int i = 0; i < n; i++)
        std::cout << d[i] << ", ";
    std::cout << std::endl;
    // 13. Delete the previously allocated memory
    delete[] d;

    // Section #4
    int m = 5;
    n = 10;
    double **dd;
    // 14. Allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n).
    double **arr;
    arr = new double *[m];
    for (int i = 0; i < m; i++)
        arr[i] = new double[n];
    // Make dd points to this 2d array.
    dd = arr;
    // 15. Set the element dd[i][j] to be equal to double(i)*double(j)
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dd[i][j] = double(i) * double(j);
    // 16. Delete the memory allocated for the 2d array
    delete[] arr;

    // Section #5
    // 17. Create a reference to the variable f (1. above). Name it rf
    float &rf = *f;
    // 18. Assign the value 2.71828 to rf
    rf = 2.71828;
    // 19. Print out the value of f and rf and verify that they are equal
    std::cout << "*f: " << *f << ", rf: " << rf << std::endl;

    return 0;
}