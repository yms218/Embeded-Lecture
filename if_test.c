#include <stdio.h>
#include <stdbool.h>

#if 0
bool은 stdbool.h 헤더 파일을 포함해야만 사용할 수 있다.
또한 논리 자체를 표현할 수 있어서 아래 보이듯이 false 나 true를 return
할수 있어서 꽤 유용하게 사용된다. 최근 c문법에 추가됨
#endif


bool is_it_even(int value)
{
	if(value % 2)
		return false;
	return true;
}


int main(void)
{
	if(is_it_even(3))
		printf("이것은 짝수\n");
	else
		printf("이것은 홀수\n");
	return 0;
}

