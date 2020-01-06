public class Example {
	public static int counter = 0;
	private int id;
	
	public Example() {
		id = counter++;
	}
	
	public void whoami() {
		System.out.println("Yo soy " + id + " object");
	}
	
	public void howManyAre() {
		System.out.println("We are " + counter + " objects");
	}
	
	public static void main(String args[]) {
		Example a = new Example();
		Example b = new Example();
		Example c = new Example();
	
		System.out.println("A:");
		a.whoami();
		a.howManyAre();
			
		System.out.println("B:");
		b.whoami();
		b.howManyAre();
		
		System.out.println("C:");
		c.whoami();
		c.howManyAre();
		
		Example.counter++;
		a.howManyAre();
		b.howManyAre();
		c.howManyAre();
		//Example.howManyAre();
	}
}
