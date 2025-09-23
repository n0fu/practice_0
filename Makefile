# Компилятор
CXX = g++

# Флаги: C++11, все предупреждения, отладочная информация
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Имя исполняемого файла
TARGET = Tests

# Исходные файлы
SOURCES = main.cpp func.cpp

# Заголовочные файлы (для отслеживания изменений)
HEADERS = func.h

# Объектные файлы (.o)
OBJECTS = $(SOURCES:.cpp=.o)

# Цель по умолчанию: собрать программу
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Компиляция .cpp файлов в .o файлы
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f $(OBJECTS) $(TARGET)

# Пересборка с нуля
rebuild: clean all

# Установка (необязательно, но полезно)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Удаление установленной программы
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Фейковые цели (не являются файлами)
.PHONY: all clean rebuild install uninstall