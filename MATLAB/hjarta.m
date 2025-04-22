% Skapa ett intervall av vinklar
t = linspace(0, 2*pi, 1000);

% Parametriska ekvationer för en blomma
r = 5 * sin(6*t);  % Ändra antalet kronblad genom att ändra multipeln av t

% Konvertera från polära till kartesiska koordinater
x = r .* cos(t);
y = r .* sin(t);

% Rita blomman
plot(x, y, 'm', 'LineWidth', 2);  % Rita blomman med en lila färg och linjetjocklek 2

% Anpassa utseendet på grafen
axis equal  % Gör att axlarna har samma skala
title('Blomma')  % Titel till grafen
xlabel('x')  % Namnge x-axeln
ylabel('y')  % Namnge y-axeln
grid on  % Visa rutnät
