# 문제 5430 (cpp)

## 사용법

test: 여러 input/expected 파일 지원

	test: input1.txt, expected1.txt
	추가 테스트케이스는 input2.txt, expected2.txt ...


e.g.
make        # 컴파일 (cpp)
make run    # 실행 (cpp)
make test   # 모든 테스트케이스 실행 (cpp)
make clean  # 정리 (cpp)

python main.py < input1.txt (py)
