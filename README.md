# Програмний проєкт 3, варіант 10

Багатопотокове виконання обчислення за схемою №10 (nt = 4, 64 дії, мінімальний час 16 с).

## Вимоги

- Компілятор з підтримкою C++20: g++ 11+ або MSVC 2019+
- CMake 3.10+ (для збирання через CMake)

## Збирання

CMake:

```
cmake -S . -B build
cmake --build build
```

g++:

```
g++ -std=c++20 -O2 main.cpp calculator.cpp dependencies.cpp scheme.cpp -o lab3
```

## Запуск

```
lab3.exe
```

Вивід у cmd:

```
lab3.exe > results.txt
```

## Файли

- `main.cpp` - `main`
- `calculator.*` - клас `Calculator` (запуск потоків, дія `f`)
- `scheme.*` - клас `Scheme` (розклад по потоках)
- `dependencies.*` - клас `Dependencies` (засувки залежностей)
- `action.h` - структура `Action`
- `results.txt` - вивід програми
- `diagram.png` - діаграма розподілу по потоках
