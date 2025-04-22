LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

entity fa is
port (a, b, cin : in std_logic;
s, cout : out std_logic);
end fa;

architecture behavioral of fa is
begin
    s <= a xor b xor cin;
    cout <= (a and b) or (b and cin) or (a and cin);
end behavioral;