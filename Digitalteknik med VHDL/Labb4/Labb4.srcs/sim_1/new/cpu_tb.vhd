Library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.all;
entity cpu_tb is end cpu_tb;
architecture Behavioral of cpu_tb is
component add4
Port (
in_1 : in STD_LOGIC_VECTOR (3 downto 0);
in_2 : in STD_LOGIC_VECTOR (3 downto 0);
s_out : out STD_LOGIC_VECTOR (4 downto 0));
end component;
component mul4
Port (
in_1 : in STD_LOGIC_VECTOR (3 downto 0);
in_2 : in STD_LOGIC_VECTOR (3 downto 0);
m_out : out STD_LOGIC_VECTOR (7 downto 0));
end component;
component invrt4
Port (
in_1 : in STD_LOGIC_VECTOR (3 downto 0);
i_out : out STD_LOGIC_VECTOR (3 downto 0));
end component;
component bit_or4
Port (
in_1 : in STD_LOGIC_VECTOR (3 downto 0);
in_2 : in STD_LOGIC_VECTOR (3 downto 0);
o_out : out STD_LOGIC_VECTOR (3 downto 0));
end component;
component bit_add4
Port (
in_1 : in STD_LOGIC_VECTOR (3 downto 0);
in_2 : in STD_LOGIC_VECTOR (3 downto 0);
a_out : out STD_LOGIC_VECTOR (3 downto 0));
end component;
component cpu
Port (
clk : in STD_LOGIC;
update : in STD_LOGIC;
ax : in STD_LOGIC_VECTOR(3 downto 0);
opcode : in STD_LOGIC_VECTOR(3 downto 0);
result_add : in STD_LOGIC_VECTOR(4 downto 0);
result_mult : in STD_LOGIC_VECTOR(7 downto 0);
result_not : in STD_LOGIC_VECTOR(3 downto 0);
result_and : in STD_LOGIC_VECTOR(3 downto 0);
result_or : in STD_LOGIC_VECTOR(3 downto 0);
A : out STD_LOGIC_VECTOR(3 downto 0);
B : out STD_LOGIC_VECTOR(3 downto 0);
C : out STD_LOGIC_VECTOR(3 downto 0);
D : out STD_LOGIC_VECTOR(3 downto 0);
op_in1 : out STD_LOGIC_VECTOR(3 downto 0);
op_in2 : out STD_LOGIC_VECTOR(3 downto 0) );
end component;
signal clk_in : STD_LOGIC;
signal update_in : STD_LOGIC;
signal ax_in : STD_LOGIC_VECTOR (3 downto 0);
signal opcode_in : STD_LOGIC_VECTOR (3 downto 0);
signal add_1: STD_LOGIC_VECTOR (4 downto 0);
signal mul_1: STD_LOGIC_VECTOR (7 downto 0);
signal inv_1: STD_LOGIC_VECTOR (3 downto 0);
signal and_1: STD_LOGIC_VECTOR (3 downto 0);
signal or_1: STD_LOGIC_VECTOR (3 downto 0);
signal input1 : STD_LOGIC_VECTOR (3 downto 0);
signal input2 : STD_LOGIC_VECTOR (3 downto 0);
signal ax_temp: STD_LOGIC_VECTOR (3 downto 0):="0000";
signal BX, CX, DX : std_logic_vector(3 downto 0):="0000";
begin
cpu_tb : cpu Port Map(
clk => clk_in,
update => update_in, ax => ax_in, opcode => opcode_in, result_add => add_1, result_mult => mul_1,
result_not => inv_1, result_and => and_1, result_or => or_1, A => ax_temp, B => BX, C => CX, D =>
DX, op_in1 => input1, op_in2 => input2 );
u1 : add4 port map ( in_1 => input1, in_2 => input2, s_out => add_1 );
u2 : mul4 port map ( in_1 => input1, in_2 => input2, m_out => mul_1 );
u3 : invrt4 port map ( in_1 => input1, i_out => inv_1 );
u4 : bit_add4 port map ( in_1 => input1, in_2 => input2, a_out => and_1 );
u5 : bit_or4 port map (in_1 => input1, in_2 => input2, o_out => or_1 );
process variable a_vector : std_logic_vector(3 downto 0):=(others=>'0');
begin
update_in <= '1';
ax_in <= "0000";
for a_vector in 0 to 15 loop opcode_in <= conv_std_logic_vector(a_vector, 4);
clk_in <= '1';
wait for 10 ns;
clk_in <= '0';
wait for 10 ns;
end loop;
end process;
end;