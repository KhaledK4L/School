x = [1 2 3 4 5 6 7];
y = [1.6 2.7 4.5 7.4 12.2 20.1 33.1];


% linjäriserad y genom att den naturliga logaritmen av y
log_y = log(y);

%jag använder mig av polyfit för att hitta linjärreggersion, och anpassa 
%den till qrak linje
p = polyfit(x, log_y, 1);

% p(1) är lutningen (k) och p(2) är interceptet (In(A))

k = p(1);
ln_A = p(2);
A = exp(ln_A); % här vi omvandlar In (A) tillbaka till A
log_y_fit = polyval(p,x);

% vi skapar en linje baserad på den linjär modellen 
y_fit = A * exp(k * x);
plot(x, log_y, 'bo', 'MarkerFaceColor', 'b', 'DisplayName', 'originaldata');
hold on;
plot(x, log_y_fit, 'r-', 'LineWidth', 2, 'DisplayName', sprintf('Anpassad linje: y = %.2fe^{%.2fx}', A, k));

% etiketter och legen
xlabel('x');
ylabel('y');
title('linjärisering av y = A \cdot e^{kx}');
legend('show');
grid on;

% visa värdet på A och K
fprintf('värde på A: %.4f\n', A);
fprintf('värdet på K: %.4f\n', k)