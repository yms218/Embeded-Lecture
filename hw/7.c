void (*signal (int signum, void (*handler)(int)))(int) 라는 signal 함수의 프로토타입
// void (*)(int) signal (int signum, void(*)(int))
즉 리턴 값은 void (*)(int) 의 함수
인자는 int signum과 void (*)(int)의 함수를 갖게 된다
