# 그리디(Greedy)

- 매 순간 최적인 해를 찾아나가면서 최종적인 해답에 도달하는 방법

## 그리디 조건

### 탐욕적 선택 속성 (Greedy choice property)

- 탐욕적 선택이 항상 안전하며, 최적 해의 도출을 보장할 수 있어야 한다.

### 최적 부분 문제 구조 속성 (Optimal substructure)

- 어떤 문제의 해가 최적일 때, 그 해를 구성하는 작은 문제들의 해 역시 최적이다.

## 문제 해결 패턴

- 조건을 만족할 때까지 solution set을 만든다.

1. 단계 별 최적 선택
2. 선택으로 만든 집합이 조건에 부합하는 지 확인
