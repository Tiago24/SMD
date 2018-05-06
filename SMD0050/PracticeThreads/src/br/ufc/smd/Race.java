package br.ufc.smd;

import java.util.Vector;

public class Race {
	private static Vector<Racer> racers;
	
	public static void main(String[] args) {
		racers = new Vector<Racer>(10);
		for(int i = 0; i < 10; i++) {
			racers.add(new Racer(i + 1));
			racers.elementAt(i).setPriority(i+1);
		}
		for(int i = 0; i < 10; i++) racers.elementAt(i).start();
	}

}
