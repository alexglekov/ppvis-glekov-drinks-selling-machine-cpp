# Модель аппарата по продаже напитков

#### Подготовил: Глеков А.А. 021703

Модель аппарата по продаже напитков это приложение без графического интерфейса, цель которого смоделировать поведение посетителей и работы аппарата по продаже напитков. В аппарату по продаже напитков продается несколько видов напитков. Время работы аппарата по продаже напитков задается в настройках модели. Не все напитки нужно готовить, для напитка, который нужно готовить, есть свой рецепт и для его приготовления нужен ингредиент и внутриаппаратный аппарат)). В аппарате по продаже напитков установлены следующие внутриаппаратные аппараты: капучинатор, кофемолка, дозатор сиропа, кипятильник. Ингредиенты, которые используются: зерна кофе, молоко, сироп. Кипятильник кипятит жидкости, кофемолка молет зерна, капучинатор взбивает молоко, дозатор сиропа выдает сироп. Так же в автомате существует два раздельных хранилища: хранилище ингредиентов и хранилище готовых напитков. Каждый внутриаппаратнй аппарат производит операцию со своим ингредиентом за определенное время, указаное в рецепте напитка, который готовится в данный момент. Ингредиенты заканчиваются. Аппарат обслуживает посетителей по очереди. Одновременно покупать напиток может только один человек. Посетители подходят к аппарату с определенной периодичностью, которая задается в настройках модели. Посетители подходят к аппарату и случайным образом выбирают, что они хотят купить (выбирает из того, что можно было купить и только один предмет). Если посетитель ждет больше определенного времени (задается в настройках модели), то он уходят. Все вероятности задаются в настройках модели, стартовое количество ингредиентов также задается в настройках модели.
-	Напитки, которые готовить не нужно: Кола, фанта, спрайт.
-	Напитки которые готовить нужно: Капучино, Латте, Эспрессо.
-	Из зерен кофе, можно приготовить любой сорт напитка. Капучинатор используется только для приготовления капучино

### Направления развития:
-	У аппарата, есть персональная характеристика скорость(для приготовления напитков которые нужно готовить), которая влияет на время выполнения шага рецепта. Если характеристика > 1, то аппарат делает все быстрее, иначе медленнее
-	Посетитель когда обнаруживает, что нет чего он хотел, он может один раз поменять свой выбор и если в результате это есть в кофейне, он ждет приготовление этого напитка, если нет, то уходит.
-	В любой момент приготовления напитка случайным образом определяется, что напиток испорчен и надо начать приготовление заново. Если напиток испорчен, то клиент уходит
-	В результате работы модели выдается статистика: сколько посетителей обслужили, сколько продали каждого напитка.
