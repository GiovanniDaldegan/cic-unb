/*
 * fdiv3
 *
 * divide o clkin por divisor qualquer resultando em clkout
 */


module fdiv (
	input wire clkin,
	input wire [3:0] divisor,
	output wire clkout
	);
	
reg[3:0] counter=4'd0;

wire [3:0] div;
assign div=divisor-4'd1;


always @(posedge clkin)
	begin
		counter <= counter + 4'd1;
		if(counter>= div)
			counter <= 4'd0;	
	end
	
	assign clkout = (divisor==4'd1) ? clkin : ( (counter < divisor>>1) ? 1'b1 : 1'b0 );
	
endmodule