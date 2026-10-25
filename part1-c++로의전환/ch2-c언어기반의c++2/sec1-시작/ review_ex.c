#include <stdio.h>

int main()
{
    const int num = 1; //num의 값 수정 불가
    
    int val1 = 111;
    const int* ptr1 = &val1; //ptr1을 통해 val1 값 수정 불가(read_only), prt1 수정 가능
    
    int val2 = 222;
    int* const ptr2 = &val2; //ptr2 수정 불가
    
    int val3 = 333;
    const int* const ptr3 = &val3; //ptr3을 통해 val3 값 수정 불가(read_only), prt3 수정 불가
    
	// num = 2;
    // *ptr1 = 1111;
    // ptr2 = &val3;
    // *ptr3 = 3333;
    // ptr3 = &val1;
    printf("%d %d %d", *ptr1, *ptr2, *ptr3);
    return 0;
}