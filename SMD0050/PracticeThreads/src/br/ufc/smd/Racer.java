package br.ufc.smd;

public class Racer extends Thread {
	private int index;
	
	public Racer(int i) {
		index = i;
	}
	
	public void run() {
		for(int i = 0; i < 1000; i++) {
			try {
				System.out.println("Racer " + index + " - printing");
				sleep(100);
			} catch (InterruptedException e) {
				System.out.println("Racer " + index + " - could not be printed");
			}
		}
	}
}
