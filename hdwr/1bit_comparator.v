//1bit comparator
module comparator (
    input wire a,b,
    output wire eq
);
wire w1,w2;
assign w1 = a & b;
assign w2 = ~a & ~b;
assign eq = w1 | w2;

endmodule