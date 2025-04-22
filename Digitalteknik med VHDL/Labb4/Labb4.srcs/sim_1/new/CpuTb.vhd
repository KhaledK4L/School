entity cpu is
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
end cpu;
