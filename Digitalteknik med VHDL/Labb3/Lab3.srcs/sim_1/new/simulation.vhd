Library IEEE;
use work.all;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.all;

entity sim is  
end sim;

architecture behave of sim is

  component add4
    port (
      in_1, in_2 : in  std_logic_vector(3 downto 0);
      s_out : out std_logic_vector(4 downto 0));
  end component;
  
  component bit_and4
    port (
      in_1, in_2 : in  std_logic_vector(3 downto 0);
      s_out : out std_logic_vector(3 downto 0));
  end component;
  
  component bit_or4
    port (
      in_1, in_2 : in  std_logic_vector(3 downto 0);
      s_out : out std_logic_vector(3 downto 0));
  end component;
  
  component mul4
    port (
      in_1, in_2 : in  std_logic_vector(3 downto 0);
      s_out : out std_logic_vector(7 downto 0));
  end component;
  
  component invrt4
    port( in_1 : in std_logic_vector(3 downto 0);
          i_out: out std_logic_vector(3 downto 0));
  end component;
  
  signal a_in, b_in: std_logic_vector(3 downto 0);
  
  signal mul_out: std_logic_vector(7 downto 0);
  signal add_s: std_logic_vector(4 downto 0);
  signal bit_and_out: std_logic_vector(3 downto 0);
  signal bit_or_out: std_logic_vector(3 downto 0);
  signal inv_out_1: std_logic_vector(3 downto 0);
  signal inv_out_2: std_logic_vector(3 downto 0);
  
  
  
  
begin  -- behave
add4_0 : add4 port map (in_1        => a_in,in_2        => b_in,s_out       => add_s); ---Done
    
bit_and4_0 : bit_and4 port map (in_1        => a_in,in_2        => b_in,s_out       => bit_and_out);
    
bit_or4_0 : bit_or4 port map (in_1        => a_in,in_2        => b_in,s_out       => bit_or_out);

mul4_0 : mul4 port map (in_1        => a_in,in_2        => b_in,s_out       => mul_out); ---Done

invrt4_0 : invrt4 port map (in_1        => a_in,i_out        => inv_out_1);
    
invrt4_1 : invrt4 port map (in_1        => b_in,i_out        => inv_out_2);

process

   variable a_vector, b_vector : std_logic_vector(3 downto 0):=(others=>'0'); 
begin  -- process
  
  for a_vector in 0 to 15 loop
    for b_vector in 0 to 15 loop
      a_in <= conv_std_logic_vector(a_vector,4);
      b_in <= conv_std_logic_vector(b_vector,4);
      wait for 10 ns;
        
    end loop;  -- b_vector
  end loop;  -- a_vector
end process;

end behave;
