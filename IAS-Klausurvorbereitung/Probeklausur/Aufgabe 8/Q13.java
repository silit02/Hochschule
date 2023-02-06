class Q13{
	public static void main(String[] args) {
		int x = 10;
		int y = new Q13().change(x);
		System.out.println(x+y);
	}
	
	int change(int x) {
		x = 12;
		return x;
	}
}