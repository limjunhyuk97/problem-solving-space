## 풀이 과정

### 1.막무가내로 돌입하기 전에, 가설을 세워보자
  - n까지 제일 큰 수의 누적수를 기준으로 잡고, n+1과 비교를 하려할 때 타당한가? 반례는 없는가?
  - 반례가 있다면 무엇을 기준으로 잡아야 하는가?

### 2. DP로 푸는데..
  - arr[N + a]로 각 숫자에 대한 누적수를 유지해준다.
  