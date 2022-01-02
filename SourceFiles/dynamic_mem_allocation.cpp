#include <iostream>
// #include <stdlib.h>

void ArrayForNew(int n) {
    int *p = new int[n];
    // int *p = new int[5] {0,1,2,3,4};
    for (int i=0;i<n;i++) {
        p[i] = i;
    }
    for (int i=0;i<n;i++) {
        std::cout << i << " " << p[i] << std::endl;
    }
    // dont need to tell size while deleting p but [] is must.
    delete []p;
}

void Strings() {
    auto c = new char[4];
    strcpy(c, "C++");
    std::cout << c << std::endl;
    delete []c;
}

void TwodArray() {
    auto twod_arr = new int*[2];

    auto oned_arr_1 = new int[3]{1, 2, 3};
    auto oned_arr_2 = new int[3]{4, 5, 6};

    twod_arr[0] = oned_arr_1;
    twod_arr[1] = oned_arr_2;

    using namespace std;

    cout << twod_arr[1][2] << endl;

    delete []oned_arr_1;
    delete []oned_arr_2;
    delete []twod_arr;
}

int main() {
    // malloc returns a void * so type cast to int* in cpp code.
    int *p = (int*) malloc(sizeof(int));
    if (p==NULL) {
        std::cout << "Failed to allocate memory\n";
        return -1;
    }
    std::cout << *p << std::endl;
    *p = 5;
    printf("%d\n", *p);
    // after doing this p will be pointing to invalid address.
    // thats why point p to NULL after freeing.
    free(p);
    p = NULL;

    // calloc allocates and initializes to 0, meanwhiele malloc dont do that.
    // only to zero, not to any specific value.
    int *q = (int*) calloc(1, sizeof(int));
    if (q==NULL) {
        std::cout << "Failed to allocate memory\n";
        return -1;
    }
    std::cout << *q << std::endl;
    // if allocated memory not freed before program exit, its called memory leak.


    int *new_p = new int(4);
    std::cout << *new_p << std::endl;
    delete new_p;
    new_p = nullptr;

    // new for 1D arrays.
    ArrayForNew(5);
    Strings();


    // new for 2D arrays.
    TwodArray();
    return 0;
}