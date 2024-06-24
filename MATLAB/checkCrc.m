function bCRC = checkCrc(intVec)
% This function takes a .hex line and verifies its CRC integrity
byteSum =sum(intVec(1:end-1));
bCRC = isequal(mod((bitxor(mod(byteSum,256),255)+1),256),intVec(end));