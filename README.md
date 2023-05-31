# Игра 2048

Это консольная реализация популярной игры 2048, написанная на языке C++. В игре нужно комбинировать плитки с одинаковыми числами, чтобы получить как можно более высокий счет. Цель игры - создать плитку с числом 8192.

## Начало работы

### Требования
Для компиляции и запуска этого кода вам нужно иметь установленный компилятор C++ на вашей системе.

### Инструкции
1. Клонируйте этот репозиторий или загрузите файлы исходного кода.
2. Скомпилируйте код с помощью вашего компилятора C++.
3. Запустите скомпилированный исполняемый файл.

## Как играть
- Используйте клавиши-стрелки (вверх, вниз, влево, вправо) для перемещения плиток на игровом поле.
- Плитки с одинаковыми числами объединяются в одну, суммируя их значения, когда они сталкиваются.
- После каждого хода на поле появляется новая плитка со значением 2 или 4.
- Игра заканчивается, когда вы достигаете плитки со значением 8192 или больше, или когда больше нет возможных ходов.

## Управление в игре
- W или стрелка вверх: Переместить плитки вверх
- S или стрелка вниз: Переместить плитки вниз
- A или стрелка влево: Переместить плитки влево
- D или стрелка вправо: Переместить плитки вправо
- Q: Выйти из игры

## Геймплей
- Игра начинается с двух случайно сгенерированных плиток на поле.
- Счет отображается на экране и представляет сумму значений всех плиток.
- Каждый ход объединяет плитки, перемещает их и генерирует новую плитку при необходимости.
- Игра заканчивается, когда вы достигаете плитки со значением 8192 или больше, или когда больше нет возможных ходов.

## Детали реализации

### Класс `Game2048`
- Представляет состояние игры и предоставляет методы для игры.
- Инициализирует игровое поле и генерирует начальные плитки.
- Обрабатывает ввод и условия завершения игры.
- Отслеживает счет, проверяет условие победы и обрабатывает перемещение и слияние плиток.

### Запуск игры
- Игра происходит в бесконечном цикле.
- После каждой игры игроку предлагается сыграть еще раз или выйти.
- Нажмите 'q', чтобы выйти, или любую другую клавишу, чтобы начать новую игру.

## Благодарности
Эта реализация игры 2048 в консоли вдохновлена оригинальной игрой 2048, созданной Габриэле Чирулли.

Приятной игры в 2048!
