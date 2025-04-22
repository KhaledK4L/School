function [k1, k2, uk1, uk2]= linjerRegression(x,y)
% funktion för att beräkna linjär regression

%Anral x
n= 30
% Riktningskoefficientenclear
k1=(n*sum(x.*y) -sum(x).*sum(y)) /(n*sum(x.^2)- sum(x)^2)
% konstant termen som mot svara m.
k2=(sum(y)-k1*sum(x))/n
% Standardavvikelse
s= sqrt(sum(y)-k1*sum(x)-k2).^2/(n-2)
% Osäkerheten för riktningskoefficient uk1 och konstanttermen uk2.
% x_i är index x dvs n*sum(x)
% x med streck på är x medelvärdet
uk1=s*sqrt(1)/sqrt(n*sum(x).^2- sum(x).^2)
%mät osäkerhet
uk2=s*sqrt(1/n)+(sum(x)^2)./ sqrt(n*sum(x).^2- sum(x).^2)
% plot för att skapa graf
plot(x,y);
% uppgift 3  x1=[45 39 31 24 18 11 4] y2[23 35 39 47 56 63 75]
end 