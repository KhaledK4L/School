--cpu
Library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.std_logic_arith.ALL;
entity cpu is
port(
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
op_in1, op_in2 : out STD_LOGIC_VECTOR(3 downto 0):="0000");
end cpu;
architecture Behave of cpu is
signal BX, CX, DX : STD_LOGIC_VECTOR(3 downto 0):="0000";
begin
A <= ax;
B <= BX;
C <= CX;
D <= DX;
clock: process(clk)
begin if rising_edge(clk)
then if update = '1'
then case opcode is
when "0000" => BX <= AX;
when "0001" => CX <= AX;
when "0010" => DX <= AX;
when "0011" => BX <= "0000";
when "0100" => CX <= "0000";
when "0101" => DX <= "0000";
when "0110" => op_in1 <= "0010";
op_in2 <= "0011";
CX <= result_add(3 downto 0);
DX <= "0101";
when "1001" => op_in1 <= "0010";
op_in2 <= "0011";
CX <= result_and(3 downto 0);
DX <= "0010";
when "1010" => op_in1 <= "0010";
op_in2 <= "0011";
CX <= result_or(3 downto 0);
DX <= "0011";
when "1011" => op_in1 <= AX;
op_in2<= BX;
CX <= result_add(3 downto 0);
DX <= "000" & result_add(4);
when "1100" => op_in1 <= AX;
op_in2 <= BX;
CX <= result_mult(7 downto 4);
DX <= result_mult(3 downto 0);
when "1101" => op_in1 <= AX;
CX <= result_not(3 downto 0);
DX <= "0000";
when "1110" => op_in1 <= AX;
op_in2 <= BX;
CX <= result_and(3 downto 0);
DX <= "0000";
when "1111" => op_in1 <= AX;
op_in2 <= BX;
CX <= result_or(3 downto 0);
DX <= "0000";
when others => NULL;
end case;
end if;
end if;
end process clock;
end;