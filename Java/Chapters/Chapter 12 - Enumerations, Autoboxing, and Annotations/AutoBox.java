class AutoBox {
	public static void main(String[] args) {
		
		Integer iOb = 100; // autobox as int

		int i = iOb; // auto-unbox

		System.out.println(i + " " + iOb); // displays 100 100
	}
}