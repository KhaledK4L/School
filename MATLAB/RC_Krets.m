%här lägger man mätvärden för tiden i sekunder
t = 10:10:300;
%Stömmen i(f) ampereq 
f = (10^-8)* [75 74.5 74 73.5 73 72.5 72 72 71.5 71.5 71 70.5 70 69.5 69.5 69 68.5 68 68 67.5 67.5 67 66.5 66 65.5 65.5 65 64.5 64.5 64];

y = log(f);
x = t;
[k1, k2, uk1, uk2]=linjerRegression(x,f);
fprintf('Riktningskoefficient (k1): %.4f\n', k1);
fprintf('Konstantterm (k2): %.4f\n', k2);
fprintf('Standardosäkerhet för k1: %.4f\n', uk1);
fprintf('Standardosäkerhet för k2: %.4f\n', uk2);
figure;
plot(x, k1*x+k2);
scatter(x, y, 'filled');
xlabel('Tid(s)');
ylabel('ln(i)');
title('Linjärisering av ström i RC-krets')
grid on;
p = polyfit(x, y, 1);
y_fit = polyval(p, x);
hold on;
plot(x, y_fit, '-r');
hold off;
tau = -1/p(1)

% e är spänningen i volt i kretsen 
E = 30;

% BERÄKNING AV RESETANSEN AV R

R = E/ exp(p(2)) 

% beräkningen av kondencentaren 

C = tau /R


fprintf('Tidskonstantenn(tau): %.2f\n', tau);
fprintf('resestansen (R): %.2f Ohm\n',R );
fprintf('Kapicistans för k1: %.2e f\n', C);




