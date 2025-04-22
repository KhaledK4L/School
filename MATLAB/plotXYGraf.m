% första grafen 
x1 = [1 2 3 4 5 6];
y1 = [3.5 4.8 7.1 9.1 10.5 13.2];
% andra grafen 
x2 = [1 2 5 7 10 11];
y2 = [3.0 6.7 15.5 21.2 30.6 33.0];

%funktionen 
y3 = 2 * x1 +1 
x3 = 3 * x2 + 0.5
%funktionen föratt skapa grafen 
figure; %funktinen somöppnar ett nytt figur fönster
hold on, %funktionen som håller kvar den befentliga grafen så jag kan plotta flera data på samma graf
plot(x1, y1, 'o-', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Data set 1');
plot(y3)
plot(x3)
plot(x2, y2, 's-', 'LineWidth', 2, 'MarkerSize', 8, 'DisplayName', 'Data set 2');
title('Förhållandet mellan x och y');

xlabel('x-värden');
ylabel('y-värde');

grid on;

legend show;

hold off; 