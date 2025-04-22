% Mätningar tagna sex gånger
D = [25.8, 25.7, 25.7, 25.9, 25.7, 25.7]* (10^-3); % Ytterdiametern på klossen
H = [38.8, 39.9, 38.8, 38.0, 38.7, 38.8] *(10^-3);   % Höjden på klossen
d = [7, 7.1, 7.1, 7.1, 7.1, 7.1]* (10^-3);  % Diameter på hålet
h1 = [10, 10.2, 10.3, 10.1, 10.1, 10.1]* (10^-3);  % Djup på hålet längs kanten
h2 = [12, 12.1, 12.1, 12.1, 12.1, 12.1] *(10^-3);  % Djup på hålet i mitten
M = 152.9 *(10^-3); % Massan på klossen i gram (endast en mätning krävs)

% Beräkna medelvärden
mD = mean(D);  % Medelvärde av ytterdiametern
mH = mean(H);  % Medelvärde av höjden
md = mean(d);  % Medelvärde av håldiametern
mh1 = mean(h1); % Medelvärde av hålets djup vid kanten
mh2 = mean(h2); % Medelvärde av hålets djup i mitten

% Beräkna volymen av klossen (stora cylindern)
Vc = pi * (mD/2)^2 * mH;  % Cylinderns volym

% Beräkna volymen av hålet
Vh = pi * (md/2)^2 * (2*mh1 + mh2)/3; % Hålets volym (cylinder + kon)

% Total volym
V = Vc - Vh;  % Total volym efter att hålet dragits ifrån

% Densitet (p = M / V)
p = M / V; % Densitet i gram per kubikmelitimeter

% Mätosäkerhet för varje mätning
uD = std(D) / sqrt(length(D));  % Mätosäkerhet för ytterdiametern
uH = std(H) / sqrt(length(H));  % Mätosäkerhet för höjden
ud = std(d) / sqrt(length(d));  % Mätosäkerhet för håldiametern
uh1 = std(h1) / sqrt(length(h1));  % Mätosäkerhet för hålets djup vid kanten
uh2 = std(h2) / sqrt(length(h2));  % Mätosäkerhet för hålets djup i mitten
uM = (M -0.99983 *M )+ (0.048 * 10^-3);  % mätosäkerhet våg                      Kombinerad mätosäkerhet för volymen av klossen
dVcdD = pi * mD * mH;  % Derivata av Vc med avseende på D
dVcdH = pi * (mD/2)^2; % Derivata av Vc med avseende på H
ucVc = sqrt((dVcdD * uD)^2 + (dVcdH * uH)^2);  % Kombinerad mätosäkerhet för Vc

% Kombinerad mätosäkerhet för volymen av hålet
dVhdd = pi * md * (2*mh1 + mh2) / 6;  % Derivata av Vh med avseende på d
dVhdh1 = pi * (md/2)^2 * 2 / 3;       % Derivata av Vh med avseende på h1
dVhdh2 = pi * (md/2)^2 / 3;           % Derivata av Vh med avseende på h2
ucVh = sqrt((dVhdd * ud)^2 + (dVhdh1 * uh1)^2 + (dVhdh2 * uh2)^2);  % Kombinerad mätosäkerhet för Vh

% Kombinerad mätosäkerhet för total volym
ucV = sqrt(ucVc^2 + ucVh^2);  % Total volyms mätosäkerhet

% Kombinerad mätosäkerhet för densiteten
ucp = sqrt((uM/M)^2 + (ucV/V)^2) * p;  % Densitetens kombinerade mätosäkerhet

% Avrunda mätosäkerheten till två värdesiffror
ucp_rounded = round(ucp, 2, 'significant');

% Avrunda densiteten till samma storlek som mätosäkerheten
p_rounded = round(p, 2, 'significant');

% Presentera resultatet
fprintf('Densiteten är p = %.3f ± %.3f kg/m^3\n', p_rounded, ucp_rounded);
