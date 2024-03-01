# ASDC
### Лабараторная работа №1
В данной лабараторной работе реализован механизм сериализации/десериализации данных в текстовые файлы в формате CSV(Comma-Separated Values).
Десериализация объектов происходит в вектор объектов Human, после чего к этому вектору применяются 4 алгоритма поиска.   
Два из них реализованы для неотсортированного вектора и два для отсортированного.\
1. Linear Search\
  Простейший алгоритм поиска, работает как в сортированном так и в неотсортированном массиве. Перебирает все значения массива до тех пор, пока не будет найдено необходимое значение или не будет достигнут конец массива. Сложность такого алгоритма равна О(n), где n - количество элементов в массиве.\
2. Binary Search\
   Бинарный поиск - это эффективный алгоритм поиска элемента в отсортированном массиве, сложность такого алгоритма оценивается, как O(log n), где n - количество элементов в массиве. На каждой итерации такой алгоритм отбрасывает часть элементов массива, которые больше или меньше значения, которое мы ищем. Благодаря такому подходу поиск значения в массиве происходит с высокой скоростью
3. Interpolation Search\
   Интерполяционный поиск основан на принципе поиска в телефонной книге или, например, в словаре. Вместо сравнения каждого элемента с искомым, как при линейном поиске, данный алгоритм производит предсказание местонахождения элемента: поиск происходит подобно двоичному поиску, но вместо деления области поиска на две части, интерполирующий поиск производит оценку новой области поиска по расстоянию между ключом и текущим значением элемента. Другими словами, бинарный поиск учитывает лишь знак разности между ключом и текущим значением, а интерполирующий ещё учитывает и модуль этой разности и по данному значению производит предсказание позиции следующего элемента для проверки. В среднем интерполирующий поиск производит log(log(N)) операций, где N есть число элементов, среди которых производится поиск. Число необходимых операций зависит от равномерности распределения значений среди элементов. В плохом случае (например, когда значения элементов экспоненциально возрастают) интерполяционный поиск может потребовать до O(N) операций.
4. BinaryTree Search\
   Двоичное дерево, для которого выполняются следующие дополнительные условия (свойства дерева поиска):
     -оба поддерева — левое и правое — являются двоичными деревьями поиска;
     -у всех узлов левого поддерева произвольного узла X значения ключей данных меньше либо равны, нежели значение ключа данных самого узла X;
     -у всех узлов правого поддерева произвольного узла X значения ключей данных больше, нежели значение ключа данных самого узла X. 
