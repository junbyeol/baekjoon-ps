#!/bin/bash

# 문제 생성 스크립트 (문제번호/언어 구조, 다중 input/expected 파일, 언어별 디렉토리 지원)
# 사용법: ./create_problem.sh <문제번호> <언어>

if [ $# -lt 2 ]; then
    echo "사용법: ./create_problem.sh <문제번호> <언어>"
    echo "예시: ./create_problem.sh 1000 cpp"
    exit 1
fi

PROBLEM_NUMBER=$1
LANG=$2

# 문제 번호가 4-5자리 숫자인지 확인
if ! [[ $PROBLEM_NUMBER =~ ^[0-9]{4,5}$ ]]; then
    echo "오류: 문제 번호는 4-5자리 숫자여야 합니다."
    exit 1
fi

# 언어별 메인 파일명 및 템플릿
case $LANG in
    cpp)
        MAIN_FILE="main.cpp"
        ;;
    py)
        MAIN_FILE="main.py"
        ;;
    *)
        echo "지원하지 않는 언어입니다. (cpp, py만 지원)"
        exit 1
        ;;
esac

# 디렉토리 생성
PROBLEM_DIR="${PROBLEM_NUMBER}/${LANG}"
if [ -d "$PROBLEM_DIR" ]; then
    echo "오류: ${PROBLEM_DIR} 디렉토리가 이미 존재합니다."
    exit 1
fi

mkdir -p "$PROBLEM_DIR"

# 생성된 디렉토리로 이동
cd "$PROBLEM_DIR"

# 언어별 메인 파일 생성
if [ "$LANG" = "cpp" ]; then
cat > "$MAIN_FILE" << 'EOF'
#include <iostream>
using namespace std;

int main() {
    // TODO: 문제 풀이 코드 작성
    return 0;
}
EOF
elif [ "$LANG" = "py" ]; then
cat > "$MAIN_FILE" << 'EOF'
# TODO: 문제 풀이 코드 작성
if __name__ == "__main__":
    pass
EOF
fi

# Makefile (cpp만)
if [ "$LANG" = "cpp" ]; then
cat > "Makefile" << 'EOF'
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = main
SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	@for f in input*.txt; do \
	  if [ -f $$f ]; then \
	    n=$${f#input}; n=$${n%.txt}; \
	    echo "=== 테스트 $$n ==="; \
	    ./$(TARGET) < $$f > output$$n.txt; \
	    if [ -f expected$$n.txt ]; then \
	      if diff -q output$$n.txt expected$$n.txt > /dev/null; then \
	        echo "✅ 정답!"; \
	      else \
	        echo "❌ 오답! (output$$n.txt vs expected$$n.txt)"; \
	        diff output$$n.txt expected$$n.txt; \
	      fi; \
	    fi; \
	  fi; \
done

clean:
	rm -f $(TARGET) output*.txt

.PHONY: all run test clean
EOF
fi

# input1.txt, expected1.txt 기본 생성
cat > "input1.txt" << 'EOF'
EOF
cat > "expected1.txt" << 'EOF'
EOF

# README.md 생성
cat > "README.md" << EOF
# 문제 ${PROBLEM_NUMBER} (${LANG})

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
EOF

echo "✅ ${PROBLEM_DIR} 생성 완료!"
echo "- $MAIN_FILE"
echo "- input1.txt, expected1.txt (테스트케이스 확장 가능)"
echo "- README.md"
if [ "$LANG" = "cpp" ]; then
  echo "- Makefile"
fi
echo ""
echo "�� 현재 디렉토리: $(pwd)" 