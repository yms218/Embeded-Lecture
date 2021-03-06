윈도우나 리눅스같은 멀티 프로세스 운영체제에서는 여러개의 프로세스들이 CPU 실행시간을 나누는 방식
으로 동시에 실행되는 효과를 얻는다. 그런데 실행중인(RUNNING상태에 있는) 프로세스의 변경은 시스템에 많은
부하를 일으킨다.
CPU 내에 존재하는 레지스터들이 현재 실행중에 있는 프로세스 관련 데이터들로 채워지는데, 실행중인 프로세스가
변경되면 CPU내에 존재하는 레지스터들의 값이 변경되기 때문이다.
이 경우 다른 프로세스가 실행되고 나서 이전의 프로세스를 재 실행시키기 위해 레지스터 값들은 어딘가에 저장해야하며, 다른 프로세스의 작업이 완료되면 이전 프로세스의 데이터(레지스터 값)를 복원시켜야한다.
여기서 프로세스의 데이터(CPU의 레지스터 값)을 컨텍스트(Context)라고 하며 실행할 프로세스가 바뀔때마다
레지스터값들도 바뀌게 되는데 이를 Context swiching이라고 한다.
