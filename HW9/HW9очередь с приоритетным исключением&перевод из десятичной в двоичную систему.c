// Реализация очередей с приоритетом в  C

#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Функция сортирует дерево
void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("В куче один элемент");
  } else {
    // Находим самое большое значение среди
   // корневого, правого и левого дочернего элемента
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;

    // Меняем местами и продолжаем сортировку, 
   // если значение корневого элемента не самое большое
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

// Функция вставляет элемент
void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}

// Функция удаляет элемент
void deleteRoot(int array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}

// Выводим массив в консоль
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

// Функция main
int main() {
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);

  printf("Массив max-heap: ");
  printArray(array, size);

  deleteRoot(array, 4);

  printf("После удаления элемента: ");

  printArray(array, size);
  
  //Перевод из десятичной в двоичную систему
  printf("Enter number: ");
  
  int n, new_n = 0;
  scanf("%d", &n);
  fflush(stdin);
  while(n)
    {
    new_n *= 10;
    new_n += n % 10;
    n /= 10;
    }
   printf("Result: %d", new_n);
   getchar();
}
