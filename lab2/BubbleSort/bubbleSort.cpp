#include <iostream>

int checkInput()
{
    int number;

    while ((!(std::cin >> number) || (std::cin.peek() != '\n'))) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Введено не число. Повторите ввод:\n  > ";
    }

    if (number <= 0) {
        std::cout << "Введено отрицательное число. Повторите ввод:\n  > ";
        number = checkInput();
    }

    return number;
}

void printArray(int array[], int size)
{
    std::cout << "  ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void bubbleSort(int array[], int size)
{
    for (int step = 0; step < size - 1; ++step) /// Внешний цикл: упорядочить N данных за N-1 раз
    {
        for (int i = 0; i < size - (step + 1); ++i) // Внутренний цикл: упорядочиваем данные, нужно сравнить N-1-i раз
                                                    // i - это количество циклов (количество данных, которые были упорядочены)
        {
            if (array[i] > array[i + 1])
            {
                //std::cout << "  ";
                //std::cout << "Перестановка " << array[i] << " и " << array[i + 1] << ":\n";

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        printArray(array, size);
    }

    std::cout << "\nОтсортированный массив пузырьковой сортировкой:\n";
    printArray(array, size);
}

int main()
{
    srand(time(0));

    std::cout << "Введите длину массива:\n  > ";
    int sizeArray = checkInput();

    int* аrray = new int[sizeArray];
    for (int i = 0; i < sizeArray; i++)
    {
        аrray[i] = rand() % 21;
    }

    std::cout << "\nПервоначальный массив:\n";
    printArray(аrray, sizeArray);

    std::cout << "\n";
    bubbleSort(аrray, sizeArray);
}
