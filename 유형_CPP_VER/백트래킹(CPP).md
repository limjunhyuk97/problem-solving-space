# 백트래킹

## 언제 사용하는가?

- 대상 집합에서 조건을 만족하는 순열이나 조합을 발견해낼 때 사용할 수 있다.
- 최적화 문제, 결정 문제에서 모두 사용할 수 있다.

## 문제 해결 패턴

- DFS + pruning
    - 대상 집합으로 만들 수 있는 순열, 조합의 가능성인 state space tree를 DFS로 순회한다.
    - 이때 promising 한지 안한지를 이용하여 tree를 prune 한다.

<img width="970" alt="image" src="https://user-images.githubusercontent.com/59442344/226506462-fd0fad70-d384-4086-a921-b732cf5345ba.png">



