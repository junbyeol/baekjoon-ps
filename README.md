# 백준 알고리즘 문제풀이 프로젝트

이 프로젝트는 백준 온라인 저지의 알고리즘 문제를 효율적으로 풀기 위한 개발 환경을 제공합니다.

## 🚀 빠른 시작

### 1. 새 문제 생성
```bash
./create_problem.sh <문제번호>
```
예시: `./create_problem.sh 1000`

### 2. 문제 풀이
```bash
cd problem_<문제번호>
make        # 컴파일
make test   # 테스트 실행
make compare # 출력 비교
```

## 📁 프로젝트 구조

```
baekjoon-ps/
├── create_problem.sh          # 문제 생성 스크립트
├── problem_1000/             # 문제별 디렉토리
│   ├── main.cpp              # 소스 코드
│   ├── Makefile              # 빌드 스크립트
│   ├── input.txt             # 입력 테스트케이스
│   ├── expected_output.txt   # 예상 출력
│   └── README.md             # 문제 설명
└── problem_XXXX/             # 다른 문제들...
```

## 🛠️ 사용법

### 문제 생성
- 4-5자리 문제 번호로 새 문제 디렉토리를 생성합니다
- 자동으로 필요한 파일들을 생성합니다

### Makefile 명령어
- `make`: C++ 코드 컴파일
- `make run`: 프로그램 실행
- `make test`: input.txt 파일로 테스트 실행
- `make compare`: 실제 출력과 예상 출력 비교
- `make clean`: 생성된 파일들 정리

### 테스트케이스 관리
- `input.txt`: 입력 테스트케이스 작성
- `expected_output.txt`: 예상 출력 작성
- `make compare`로 자동 비교 가능

## 📝 예시

### 1000번 문제 (A+B)
```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
```

**input.txt:**
```
1 2
```

**expected_output.txt:**
```
3
```

## 🔧 요구사항

- C++ 컴파일러 (g++)
- Make
- Bash shell

## 📚 문제 목록

- [ ] 1000번: A+B
- [ ] 추가 예정...
