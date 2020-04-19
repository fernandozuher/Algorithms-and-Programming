class Box {
	double width, height, depth;

	Box(Box ob) {
		width = ob.width;
		height = ob.height;
		depth = ob.depth;
	}

	Box(double w, double h, double d) {
		width = w;
		height = h;
		depth = d;
	}

	Box() {
		width = height = depth = -1;
	}

	Box(double len) {
		width = height = depth = len;
	}

	double volume() {
		return width * height * depth;
	}
}

class BoxWeight extends Box {
	double weight;

	BoxWeight(double w, double h, double d, double m) {
		width = w;
		height = h;
		depth = d;
		weight = m;
	}
}

class RefDemo {
	public static void main(String args[]) {

		BoxWeight weightbox = new BoxWeight(3, 5, 7, 8.37);
		Box plainbox = new Box();
		double vol;

		vol = weightbox.volume();
		System.out.println("Volume of weightbox is " + vol);
		System.out.println("Weight of weightbox is " + weightbox.weight);
		System.out.println();

		plainbox = weightbox;

		vol = plainbox.volume();
		System.out.println("Volume of plainbox is " + vol);

		// Error
		// System.out.println("Weight of plainbox is " + plainbox.weight);


	}
}