class Client implements Callback {
	public void callback(int p) {
		System.out.println("Callback called with " + p);
	}

	void nonIfaceMeth() {
		System.out.println("Classes that implement interfaces " +
						   "may also define other members, too.");
	}
}

class TestIface {
	public static void main(String[] args) {
		Callback c = new Client();
		c.callback(42);
	}
}

