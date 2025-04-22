Library IEEE;
use work.all;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity bit_or4 is -- s_out <= ( '0 ' & in_1 ) + ( '0 ' & in_2 )
Port ( in_1, in_2 : in STD_LOGIC_VECTOR (3 downto 0);
o_out : out STD_LOGIC_VECTOR (3 downto 0));
end bit_or4;

architecture behave of bit_or4 is
begin
    o_out <= (in_1 or in_2);
end behave;
