Library IEEE;
use work.all;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.all;

entity add8_tb is  
end add8_tb;

architecture behave of add8_tb is

  component add8_behave
    port (
      a, b : in  std_logic_vector(7 downto 0);
	  cin  : in  std_logic;
      s  : out std_logic_vector(7 downto 0);
      cout : out std_logic);
  end component;

   component add8
    port (
      a, b : in  std_logic_vector(7 downto 0);
	  cin  : in  std_logic;
      s  : out std_logic_vector(7 downto 0);
      cout : out std_logic);
  end component;
  
  signal a_in, b_in, s_behave, s_struct : std_logic_vector(7 downto 0);
  signal c_in:STD_LOGIC:='0';
  signal cout_behave, cout_struct : std_logic;
  
begin  -- behave
add8_1 : add8_behave port map (
    a        => a_in,
    b        => b_in,
    cin      => c_in,
    s      => s_behave,
    cout     => cout_behave);

add8_0 : add8 port map (
  a        => a_in,
  b        => b_in,
  cin	   => c_in,
  s      => s_struct,
  cout     => cout_struct);
  

process

   variable a_vector, b_vector : std_logic_vector(7 downto 0):=(others=>'0'); 
begin  -- process
  
  for a_vector in 0 to 255 loop
    for b_vector in 0 to 255 loop
      a_in <= conv_std_logic_vector(a_vector,8);
      b_in <= conv_std_logic_vector(b_vector,8);
      wait for 10 ns;
        if ((conv_integer(s_behave) /= conv_integer(s_struct)) or (cout_struct /= cout_behave)) then
          assert false report "Simulation failed!" severity failure;
        end if;
    end loop;  -- b_vector
  end loop;  -- a_vector
end process;

end behave;
