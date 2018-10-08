//this is a linear congruential generator
//it calculates a sequence of pseudo-randomized numbers using concepcts of congruency
//default parameters
static unsigned long A = 40692;
static unsigned long C = 127;
static unsigned long M = 10000000;
static unsigned long x = 0;

//calculates and returns a pseudorandom value
unsigned long lcrandom(){
	x = (A*x + C) % M;
	return x;
};

//defines the initial value (seed) of the sequence
void lcrandom_seed (unsigned long s){
	x = s;
};

//returns the maximum possible random number (minimum is always 0)
unsigned long lcrandom_max(){
	return M;
};

//modifies lcrandom's parameters
void lcrandom_parms (unsigned long a, unsigned long c, unsigned long m){
	A = a;
	C = c;
	M = m;	
};

