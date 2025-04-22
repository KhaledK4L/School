% data
x = [45 39 31 24 18 11 4]';
y = [23 35 39 47 56 63 75]';

% Anropa funktionen
[k1, k2, u_k1, u_k2] = linjar_regression(x, y);
% Visa resultaten
fprintf('Riktningskoefficien (k1): %.4f\n', k1);
fprintf('Konstantterna (k2): %.4f\n', k2);
fprintf('Standardosäkerhet för k1: %.4f\n', u_k1);
fprintf('Standardosäkerhet för k2: %.4f\n', u_k2);

