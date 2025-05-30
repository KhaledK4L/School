x = [45 39 31 24 18 11 4]';
y = [23 35 39 47 56 63 75]';

[k1, k2, u_k1, u_k2] = linjar_regression(x, y);

figure;
plot(x, y, 'bo','MarkerFaceColor',  'b', 'Displayname', 'mätpunkterna');
hold on;

%beräkningen av linjär regressionslinje
x_fit = linspace (min(x), max(x), 100); % det skapar en linär sekvens av x_bärden för att passa linjen
y_fit = k1 * x_fit + k2; % detta beräknar motsvarande y_värden med en reggriosons linje

plot(x_fit, y_fit, 'r-', 'LineWidth', 2, 'DisplayName', 'linjär regresionslinje');

xlabel('X-värden');
ylabel('Y_värden');
title('graf för linär regression');
legend('show');
grid on;