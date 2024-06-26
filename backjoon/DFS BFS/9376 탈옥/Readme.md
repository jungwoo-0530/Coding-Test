# [탈옥](https://rebas.kr/770)

- 일반적인 탐색문제와는 다르다.
- 수감되어있는 범죄자는 2명
- 이동횟수에 제한(depth)이 없으면 BFS로 품





## <u>실수한 점</u>

- 처음에 문제를 인식을 이상하게 하였다. 상근이만 문을 열 수가 있고 **상근이가 두명의 죄수가 있는 위치로 이동할때의 문의 갯수만 인식을 하였다**. 그러기에 잘못된 결과가 계속 도출되었다.(죄수도 상근이의 도움을 받아 문을 열면서 나갈 수 있다.)

- 5시간 고민을하고 도저히 안되서 결국 https://rebas.kr/770여기서 도움을 받았다. 때로는 도움을 받고 그것을 내것으로 만드는 것이 더 중요하다고 생각한다.

  



## 문제 해결 방식

- 각 죄수는 문을 공유한다는 것

- 밖에서 문을 열어 주는 상근이는 감옥 밖을 자유롭게 돌아다니면서 문을 열 수 있으므로

  기존 맵을 ('.') 1칸씩 확장한다.

- 총 3가지의 경우의 수를 더해야 한다.

- 1. **<u>첫 번째 죄수부터 출발하여 문을 여는 경우</u>**
  2. **<u>두 번째 죄수부터 출발하여 문을 여는 경우</u>**
  3. **<u>바깥쪽에서 출발하여 문을 여는 경우</u>**

- 저 총 3가지로 3번의 bfs를 돌린다.

  1. **<u>감옥 밖 (0,0)에서 출발한다. BFS탐색을 하면서 각 좌표에 문을 여는 횟수를 저장.</u>**

     **<u>이 경우에는 이 문제는 최단거리를 구하는 문제가 아니므로 밖 아무 곳에서 출발해도 상관이 없다.</u>**

  2. **<u>첫 번째 죄수('$')에서 출발하여, 문을 여는 횟수를 저장.</u>**

  3. **<u>두 번째 죄수에서 출발하여, 문을 여는 횟수를 저장.</u>**

- 위에서 3번의 bfs를 돌린 후에 각 단계에서 저장한 3개의 배열을 모두 더하고 그 중 최솟값을 출력한다.

- 해당 좌표가 문('#')일 경우, 2를 뺀다(그 이유는 첫번째 죄수와 두 번째 죄수가 문을 중복으로 열기 때문이다. 문은 한번 열면 계속 열려 있기 때문이다)



## 위에 해결방식 후에 배운점.

- 이 문제에서의 최소비용은 문을 최소한으로 여는 것.
- 저는 큐를 사용하였기에 FIFO로 인해 나중에 최소비용의 길을 찾아도 업데이트가 되지 않음.
- 해결하는 방법은 덱 자료구조를 사용하여 bfs에서 . 와 #을 때로 나눠지는데 .로 가는 방향으로 먼저 맨 앞에 넣어서 먼저 실행해야한다.