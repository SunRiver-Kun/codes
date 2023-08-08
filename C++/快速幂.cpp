int fastpow(int a, int b){
	if(b == 0) { return 1; }
	return b & 1 ? a * fastpow(a * a, (b - 1) / 2) : fastpow(a * a, b / 2);
}