software interrupt : 
프로그램이 처리 중에 명령의 요청에 의해 발생하는 것으로 대표적인 형태는
운영체제 감시 프로그램을 호출하는 SVC(Super Visor Call)인터럽트가 있다.
1. 예외상황 : 프로그램이 허용되지 않은 연산을 수행하려고 할 때 자동적으로 발생
2. system call : 사용자 프로세스가 운영체제의 서비스를 요청하기 위해 커널의 함수를 호출하는 것
3. interrupt vector : 여러가지 인터럽트에 대한 해당 인터럽트 발생 시 처리해야 할 루틴의 주소를 보관하고 있는 테이블(포인터)
4. interrupt handler (=interrupt service routine) : 실제 인터럽트를 처리하기 위한 루틴.

동작 메커니즘 :
정확히 생각은 나지 않지만 마이크로프로세서 시간에서 배운것을 바탕으로 동작을 설명하면
일단 system call이 발생하면 인터럽트 vector table에서 어떤 인터럽트(여기서는 software interrupt)가 발생하였는지 확인하고 그 주소값으로 jump하여 interrupt handler(service routine)을 수행하는 것으로 알고 있다.
