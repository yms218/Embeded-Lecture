OoO(Out of Order)인 비순차 실행이란
CPU의 실행 속도를 빠르게 하는 기술중 하나이다. 
간단한 예로
A=5
B=3
C=A+B
D=4

C=A+B를 계산하는 순서를 볼 수 있다. 첫번째 변수 지정 명령들이 먼저 완성되고 파이프라인을 떠나야4힌디. 두 개의 변수 지정 명령어들이 완성되기 위해 2개의 사이클이 필요하다고 가정하면 그림 1과 같은 과정을 거치게 된다.
<명령 실행>
A=5      empty
B=3      A=5
empty	 B=3
C=A+B	 empty
D=4	 C=A+B
empty	 D=4	

C=A+B 명령이 한 사이클을 기다려야 함을 볼 수 있다. 이것을 D=4 계산을 C=A+B 이전에 하면
피할 수가 있을 것이다. 대부분의 CPU들은 D=4를 C=A+B 이전에 실행시킬 것이다.
A=5	 empty
B=3	 A=5
D=4	 B=3
C=A+B	 D=4
empty	 C=A+B

결론적으로 이렇게 함으로써 귀중한 한 개의 사이클을 절약한 것이다. 이것은 매우 단순화 시킨 예에 
불과하지만 이런식으로 동작을 한다.	
