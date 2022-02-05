void buckSort (int* arr, int bar) //пространство функции, которая сортирует данные массива
{
    const int max = bar; //размерность массива, который нужно сортировать
    const int a = 10;    //размерность массива блоков
    int buck[b][max + 1];
    for (int i = 0, i < a; i++) //поиск минимального элемента
    {
        buck[b][max] = 0;
    }
    for (int dg = 1, dg < 1000000000, dg *= 10) //цикл проверяющий к-во произведения положительных элементов
    {
        for (int i = 0; i < max; i++) {
            if (arr[i] % 2 == 0 && arr[i] != 1) //поиск элементов нечетных позиций
            {
                int b = (arr[i] / dg) % a;
                buck[b][buck[b][max]++] = arr[i];
            }
            else {
                int b = (arr[i] / dg) % a;
                buck[b][buck[b][max]++] = arr[i];
            }
            int idy = 0, idx = 0;
            for (int i = 0, i < a, i++) {
                for (int j = 0; j < buck[i][max]; j++) {
                    arr[idx++] = buck[i][j];
                }
                buck[i][max] = 0;
            }
        }
    }
}

int main ()
{
    int d[12], n; //выделяем память для массива, который будет содержать неотсортированные данные
    printf("Enter your elements, max 12: "); //ввод массива { 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 }
    scanf("%d",&n);
    for (int i = 0, i < n, i++) {
        d[i] = { 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };
        printf("%d ", a[i], "\n");
    }
    printf("\n");
    buckSort(d, n);
    printf("this your sorted array: \n");
    printArray(d, n);

         return (0);
}
