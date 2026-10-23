# Програмний проект 3, варіант 10

Багатопотокове виконання обчислення за схемою №10 (nt=4, a=7, b=9, c=4, d=8, e=7, f=5, g=7, h=9, i=8, j=5, k=4, m=4, n=3, 64 дії, мінімальний час 16 с).

## Вимоги

- Компілятор з підтримкою C++20: g++ 11+ або MSVC 2019+
- CMake 3.10+

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
- `calculator.` - клас `Calculator` (запуск потоків, дія `f`)
- `scheme.` - клас `Scheme` (розклад по потоках)
- `dependencies.*` - клас `Dependencies` (засувки залежностей)
- `action.h` - структура `Action`
- `results.txt` - вивід програми
- `diagram.png` - діаграма розподілу по потоках
