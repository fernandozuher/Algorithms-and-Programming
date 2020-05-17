class MyIFImp implements MyIF {

	public int getNumber() {
		return 100;
	}
}

class MyIFImp2 implements MyIF {

	public int getNumber() {
		return 100;
	}

	public String getString() {
		return "This is a different string.";
	}
}

class DefaultMethodDemo {
	public static void main(String[] args) {
		MyIF myifOb;
		MyIFImp myif1 = new MyIFImp();
		MyIFImp2 myif2 = new MyIFImp2();

		myifOb = myif1;
		System.out.println(myifOb.getNumber());
		System.out.println(myifOb.getString());

		myifOb = myif2;
		System.out.println(myifOb.getNumber());
		System.out.println(myifOb.getString());
	}
}