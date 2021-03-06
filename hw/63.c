보통 DSP에서는 FIR 필터를 설계할때를 예로 window function을 설명한다.
컨볼루션이라는 연산을 DSP가 해주도록 해야하기 위해서인데, 연산의 구간이 -무한대에서
+무한대가 컨볼루션의 정의다. 하지만 시스템과 신호가 둘다 무한대라면 컨볼루션이 무한대로
계속 연산하는 것이라서 출력을 영원히 보지 못한다. 그래서 컨볼루션이라는 연산은
실제로 구현시 신호나 시스템 둘중 하나는 유한하게 만들어야한다. 그래서 시스템을
유한화 시켜야하므로 창 함수를 쓰는데 Rectangular는 주파수축으로 가져가면 Sinc함수가
되므로 무한대의 값을 가지므로 다양한 성능좋은 카이져, 해머 등 윈도우 함수들이
생겨났다.
