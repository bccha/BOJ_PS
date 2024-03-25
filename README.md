* 조합 0의 개수

    https://www.acmicpc.net/problem/2004
    2, 5의 개수를 찾을 때, 2^1, 2^2, 2^3 의 개수를 세는 법

* 일곱난장이
    
    https://www.acmicpc.net/problem/2309
    조합을 구할 때, 맞는 것을 찾는 것 보다 아닌 것을 찾는 방법이 빠를 때도 있다.

* N과 M 9

    https://www.acmicpc.net/problem/15663
    중복된 값의 입력이 허용될 때, 개수로 관리

* 다음 순열

    https://www.acmicpc.net/problem/10972
    https://rimkongs.tistory.com/212
    next_permutation 구현 방법 알고, 이를 응용하기

** RGB 거리 2

    https://www.acmicpc.net/problem/17404
    처음 값을 고정하는 방법

* ABCDE
    
    https://www.acmicpc.net/problem/13023
    DFS 입력을 받을 때, adjacency matrix가 편하지만, sparse일때는 Adjacency list와 성능차이가 많이 날 수 있다.
    O(n^2) vs O(n+e)

* 서울지하철2호선
    
    https://www.acmicpc.net/problem/16947
    DFS로 Cycle 및 Cycle에 속한 Node 찾는 방법


* 0-1 BFS

    deque 사용 시 push_front 써서 우선순위를 높여라.

* 합이 같은 경우에는 search space를 줄일 수 있고, visited 메모리 공간도 줄일 수 있다.


* 전구와 스위치 -> 그리디하게 생각하는 방법.
    
    처음값을 고정하는 방법. RGB거리 2와 비슷
    https://burningjeong.tistory.com/409
