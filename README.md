# 41_tree_toys

## Условие: 
Наташа занимается изготовлением ёлочных игрушек и любит дарить их своим друзьям перед Новым годом. Самым близким друзьям она дарит коробки с наборами игрушек,
на которые она потратила больше всего времени. Каждый набор состоит из di игрушек, связанных определённой темой, поэтому Наташа не хочет дарить игрушки из одного набора разным людям.
Для каждого набора известно время ti, потраченное на его создание. Сейчас перед Наташей стоит проблема собрать коробку игрушек для самого близкого ей человека.
Коробка для хранения игрушек состоит из n×m ячеек, по одной игрушке в каждой. Часть ячеек могут остаться пустыми, если не удалось найти подходящий набор. 
Игрушки из одного набора можно разместить в произвольных ячейках коробки Помогите Наташе выбрать k наборов игрушек для упаковки в одну коробку так, чтобы общее время их изготовления было наибольшим  

## Формат входных данных:
Первая строка содержит три целых положительных числа: s — количество наборов, n и m — размеры коробки. Гарантируется, что s не превосходит 10^5, а произведение s×n×m не превосходит 10^7.
Каждая из следующих s строк содержит по два целых числа di и ti (1≤di≤10^9, 1≤ti≤10^9) — число игрушек в наборе и время его изготовления.

## Формат выходных данных:
В первой строке выведите одно число k (0≤k≤s) — количество наборов, которые нужно упаковать в коробку.
Во второй строке выведите k различных целых чисел от 1 до s — номера выбранных наборов. Наборы пронумерованы в порядке следования во входных данных.

- Так как оптимальных решений может быть несколько, можете вывести любое из них.
