package br.ufc.smd;

import java.util.Vector;

public class Deposit {
	private int items;
	private int capacity;
	private static Producer p;
	private static Vector<Consumer> c;
	
	private Deposit() {
		items = 0;
		capacity = 10;
	}

	public int getNumItems() {
		return items;
	}
	
	public int getCapacity() {
		return capacity;
	}
	
	public synchronized boolean output() {
		if(items >= 1) {
			items -= 1;
			System.out.println("One out. Buffer with " + items + " items.");
			return true;
		} else {
			System.out.println("Buffer empty.");
			return false;
		}
	}
	
	public synchronized boolean input() {
		if(items < capacity) {
			items += 1;
			System.out.println("One in. Buffer with " + items + " items.");
			return true;
		} else {
			System.out.println("Buffer full.");
			return false;
		}
	}
	
	public static void main(String[] args) {
		Deposit dep = new Deposit();
		System.out.println("Buffer created with " + dep.getNumItems() + " items,"
				+ " max capacity of " + dep.getCapacity() + " items.");
		p = new Producer(dep, 50);
		c = new Vector<Consumer>(5);
		for(int i = 0; i < 5; i++) {
			if(((2*i+1) % 2) == 0)
				c.add(new Consumer(dep, 150));
			else
				c.add(new Consumer(dep, 100));
		}
		
		p.start();
		c.elementAt(0).start();
		c.elementAt(1).start();
		c.elementAt(2).start(); 
		c.elementAt(3).start(); 
		c.elementAt(4).start(); 
	}
}
