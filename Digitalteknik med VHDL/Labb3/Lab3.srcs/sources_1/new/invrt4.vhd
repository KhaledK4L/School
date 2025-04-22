Library IEEE;
use work.all;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity invrt4 is -- i_out <= NOT ( in_1 )
Port ( in_1 : in STD_LOGIC_VECTOR (3 downto 0);
i_out : out STD_LOGIC_VECTOR (3 downto 0));
end invrt4;

architecture behave of invrt4 is
begin
    i_out <= not(in_1);
end behave;
