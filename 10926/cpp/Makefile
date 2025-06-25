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
