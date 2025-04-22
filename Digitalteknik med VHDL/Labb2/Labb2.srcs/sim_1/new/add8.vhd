Library IEEE;
use work.all;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.all;

entity add8 is
port (
      a, b : in  std_logic_vector(7 downto 0);
	  cin  : in  std_logic;
      s  : out std_logic_vector(7 downto 0);
      cout : out std_logic);
end add8;

architecture behave of add8 is
   component fa
    port (a, b, cin : in std_logic;
    s, cout : out std_logic);
   end component;
   signal ca : std_logic_vector(6 downto 0);
begin
    add8_0: fa port map (a(0), b(0), cin, s(0), ca(0));
    add8_1: fa port map (a(1), b(1), ca(0), s(1), ca(1));
    add8_2: fa port map (a(2), b(2), ca(1), s(2), ca(2));
    add8_3: fa port map (a(3), b(3), ca(2), s(3), ca(3));
    add8_4: fa port map (a(4), b(4), ca(3), s(4), ca(4));
    add8_5: fa port map (a(5), b(5), ca(4), s(5), ca(5));
    add8_6: fa port map (a(6), b(6), ca(5), s(6), ca(6));
    add8_7: fa port map (a(7), b(7), ca(6), s(7), cout);
end behave;