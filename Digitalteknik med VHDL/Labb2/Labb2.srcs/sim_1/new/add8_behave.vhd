Library IEEE;
use work.all;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.all;

entity add8_behave is
port (
      a, b : in  std_logic_vector(7 downto 0);
	  cin  : in  std_logic;
      s  : out std_logic_vector(7 downto 0);
      cout : out std_logic);
end add8_behave;

architecture behavioral of add8_behave is
   signal tmp: std_logic_vector(8 downto 0);
begin  
    tmp <= conv_std_logic_vector((conv_integer(a)+conv_integer(b) + conv_integer(cin)),9);
    s <= tmp(7 downto 0);
    cout  <= tmp(8);
end behavioral;