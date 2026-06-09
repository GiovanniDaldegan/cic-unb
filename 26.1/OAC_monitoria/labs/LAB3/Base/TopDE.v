/* Interface com DE1Soc
Key[0] = reset
Key[1] = mostra PC
Key[2] = mostra Instr
			mostra reg escolhido por SW[8:4]
SW[3:0] = divisor de frequência
LEDR[0] = ClockDIV
LEDR[1] = Clock
SW[9] = Clock Manual KEY[3] ou Automático 
*/

module TopDE (
	input logic CLOCK_50,
	input logic [9:0] SW,
	input logic [3:0] KEY,
	output logic [9:0] LEDR,
	output logic [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5,
	output logic [31:0] pc,instr,regout
	);
	
	
	

	fdiv FDVI1 (.clkin(CLOCK_50),.divisor(SW[3:0]),.clkout(Clock));   //Divisor de clock
	
	wire clockDIV, Clock;
	
	initial 
		clockDIV <= 1'b0;

	always @(posedge Clock) 
		begin 
			if(SW[9])
				clockDIV<=~KEY[3];		//clock manual
			else			
				clockDIV<=~clockDIV;  //clockDIV metade da frequência do clock
		end
	
	assign LEDR[0]=clockDIV;
	assign LEDR[1]=Clock;

	
	assign LEDR[7:3]=4'b1111;
	Uniciclo UNI1 (.clockCPU(clockDIV), .clockMem(Clock), .reset(~KEY[0]), 
						.PC(pc), .Instr(instr), .regin(SW[8:4]), .regout(regout)); 

					
/*	Multiciclo MULT1 (.clockCPU(clockDIV), .clockMem(Clock), .reset(~KEY[0]), 
						.PC(pc), .Instr(instr), .regin(SW[8:4]), .regout(regout), .estado(LEDR[3:0]));	*/
						
/*	assign LEDR[3:0]=4'b0000;
	Pipeline PIP1 (.clockCPU(clockDIV), .clockMem(Clock), .reset(~KEY[0]), 
						.PC(pc), .Instr(instr), .regin(SW[8:4]), .regout(regout)); */
		

	wire [31:0] hex;
		
	always @(*)
		begin
		if(~KEY[1])
			hex<=pc;		// Mostra PC
		else
			if(~KEY[2])
				hex<=instr;	// Mostra Intrução
			else
				hex<=regout;	//Mostra registrador
		end
	


	decoder7 D0 (.In(hex[3:0]),.Out(HEX0));
	decoder7 D1 (.In(hex[7:4]),.Out(HEX1));
	decoder7 D2 (.In(hex[11:8]),.Out(HEX2));
	decoder7 D3 (.In(hex[15:12]),.Out(HEX3));
	decoder7 D4 (.In(hex[19:16]),.Out(HEX4));
	decoder7 D5 (.In(hex[23:20]),.Out(HEX5));
	
endmodule
	
	